#include<stdio.h>
#include<string.h>
struct name
{
	char fname[50],lname[50];
};

struct date
{
	int dd,mm,yy;
};

struct address
{
	int dno;
	char building[50], street[50], area[50], city[50], state[50];
	char pincode[50];
};

struct contact
{
	char mobile[50], landline[50];
};

struct details
{
	struct name uname;
	struct date dob;
	struct address addr;
	struct contact ph;
	char gender;
	int age;
	char acc_no[50], pwd[10];
	char type[20];
	float balance;
};

void menu(struct details u);
void login();

void acc_no(struct details *u)
{
    int k=0,i=0,j=4;
    for(i=0;i<10;i++)
    {
        if((i==0)||(i==1))
            u->acc_no[i]=u->addr.pincode[j++];
        else if((i>1)&&(i<=5))
            u->acc_no[i]=u->uname.fname[k++];
        else if((i>5)&&(i<=9))
            u->acc_no[i]=u->ph.mobile[i];
    }
    u->acc_no[i]='\0';
    printf("Your username is %s", u->acc_no);
    printf("\nEnter the password: (password can be a maximum of 10 characters) ");
    scanf(" %[^\n]", u->pwd);
    printf("\nYour login ID and and password have been saved successfully!");
}


void create(struct details *u)
{
	FILE *fp;
	printf("Enter details:\n");
	printf("First Name: ");
	scanf("%s",u->uname.fname);
	printf("Last Name: ");

	scanf("%s",u->uname.lname);
	printf("DOB(dd/mm/yy): ");

	scanf("%d %d %d",&u->dob.dd,&u->dob.mm,&u->dob.yy);
	printf("House no. : ");
	scanf(" %d",&u->addr.dno);
	printf("Building: ");
	scanf(" %[^\n]",u->addr.building);
	printf("Street: ");
	scanf(" %[^\n]",u->addr.street);
	printf("Area: ");
	scanf(" %[^\n]",u->addr.area);
	printf("City: ");
	scanf(" %[^\n]",u->addr.city);
	printf("State: ");
	scanf(" %[^\n]",u->addr.state);
	printf("Pincode: ");
	scanf(" %s",u->addr.pincode);

	printf("Mobile: ");
	scanf(" %s",u->ph.mobile);
	printf("Landline: ");
	scanf(" %s",u->ph.landline);

	printf("Gender: ");
	scanf(" %c",&u->gender);

	printf("Age: ");
	scanf("%d",&u->age);

	acc_no(u);

	int option;
	printf("\nEnter account type:\n1.Savings\n2.Current\n3.Joint\n4.Minor\n");
	scanf("%d",&option);
	switch(option)
	{
    case 1:
        strcpy(u->type,"Savings");
        break;
    case 2:
        strcpy(u->type,"Current");
        break;
    case 3:
        strcpy(u->type,"Joint");
        break;
    case 4:
        strcpy(u->type,"Minor");
        break;
    }

    u->balance=0;
	printf("Enter amount of money to deposit: ");
	scanf("%f",&u->balance);

	fp=fopen("details.dat", "ab");
	fwrite(u, 1, sizeof(struct details),fp);
	fclose(fp);
}


void modify(struct details *u)
{
    FILE *fp1,*fp2;
    struct details obj1;
    fp1=fopen("details.dat","rb");
    fp2=fopen("temp.dat","wb");
    while(fread(&obj1,sizeof(obj1),1,fp1))
    {
        if(strcmp(obj1.acc_no,u->acc_no)==0)
        {
            printf("Enter new details:\n");
            printf("House no. : ");
            scanf("%d",&u->addr.dno);
            printf("Building: ");
            scanf(" %[^\n]",u->addr.building);
            printf("Street: ");
            scanf(" %[^\n]",u->addr.street);
            printf("Area: ");
            scanf(" %[^\n]",u->addr.area);
            printf("City: ");
            scanf(" %[^\n]",u->addr.city);
            printf("State: ");
            scanf(" %[^\n]",u->addr.state);
            printf("Pincode: ");
            scanf(" %[^\n]",u->addr.pincode);

            printf("Mobile: ");
            scanf("%s",u->ph.mobile);
            printf("Landline: ");
            scanf("%s",u->ph.landline);

            fwrite(u,1,sizeof(struct details),fp2);
        }
        else
            fwrite(&obj1,1,sizeof(obj1),fp2);


    }
fclose(fp1);
fclose(fp2);
remove("details.dat");
rename("temp.dat","details.dat");
printf("Details modified\n");
}


void withdraw(struct details *u)
{
  FILE *fp1, *fp2;
  struct details obj;
  float temp;
  char c;
  fp1=fopen("details.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&obj, 1, sizeof(obj),fp1))
  {
        if(strcmp(obj.acc_no,u->acc_no)==0)
        {
            printf("Enter the amount of money you want to withdraw: ");
            scanf("%f",&temp);
            if(u->balance<10000 && temp>5000)
            {
              printf("Your balance is less than 10000. Are you sure you want to withdraw(y/n) : ");
              scanf(" %c",&c);
              if(c=='y')
              {
                 u->balance=u->balance-temp;
                 printf("\nYour current balance is %f\n",u->balance);
                 fwrite(u, 1, sizeof(struct details),fp2);
              }
              else if(c=='n')
                 fwrite(u,1,sizeof(struct details),fp2);
            }
            else
            {
                 u->balance=u->balance-temp;
                 printf("\nYour current balance is %f\n",u->balance);
                 fwrite(u, 1, sizeof(struct details),fp2);
            }

        }
        else
            fwrite(u, 1, sizeof(struct details),fp2);

    }
  fclose(fp1);
  fclose(fp2);
  remove("details.dat");
  rename("temp.dat","details.dat");
}



void deposit(struct details *u)
{
  FILE *fp1, *fp2;
  struct details obj;
  float temp;
  fp1=fopen("details.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&obj, 1, sizeof(obj),fp1))
  {
      if(strcmp(obj.acc_no,u->acc_no)==0)
      {
        printf("Enter the amount of money you want to deposit: ");
        scanf("%f",&temp);
        u->balance=u->balance+temp;
        printf("\nYour current balance is %f\n",u->balance);
        fwrite(u, 1, sizeof(struct details),fp2);
      }
      else
         fwrite(u, 1, sizeof(struct details),fp2);

  }
  fclose(fp1);
  fclose(fp2);
  remove("details.dat");
  rename("temp.dat","details.dat");
}



void view(struct details u)
{

  FILE *fp;
  fp=fopen("details.dat","rb");
  struct details obj;
  while(fread(&obj, 1, sizeof(obj),fp))
  {
    if(strcmp(obj.acc_no,u.acc_no)==0)
    {
		  if(u.gender=='f'||u.gender=='F')
		  {
			  printf("Welcome Ms.%s %s\n",u.uname.fname,u.uname.lname);
		  }
		  else if(u.gender=='m'||u.gender=='M')
		  {
			  printf("Welcome Mr.%s %s\n",u.uname.fname,u.uname.lname);
		  }
      printf("Account Number: %s\n",u.acc_no);
      printf("Address:\n%d, %s\n%s, %s\n%s\n%s\n%s\n",u.addr.dno,u.addr.building,u.addr.street,u.addr.area,u.addr.city,u.addr.state,u.addr.pincode);
      printf("\nMobile Number: %s\nTelephone Number: %s\n",u.ph.mobile,u.ph.landline);
      printf("Date of Birth: %d / %d / %d\n", u.dob.dd, u.dob.mm, u.dob.yy);
      printf("Age: %d\n", u.age);
      printf("Gender: %c\n", u.gender);
      printf("Account Type: %s\n", u.type);
      printf("Current balance: Rs.%f\n",u.balance);
    }
  }
  fclose(fp);

}


void viewall()
{
    struct details u;
    FILE *fp;
    int c=1;
    fp=fopen("details.dat", "rb");
    printf("\nDETAILS OF CUSTOMERS: \n\n");
    while(fread(&u,1,sizeof(u),fp))
    {
        printf("Customer %d:\n",c++);
        printf("Account Number: %s\n",u.acc_no);
        printf("Name: %s %s\n", u.uname.fname, u.uname.lname);
        printf("Address:\n%d, %s, %s,\n%s, %s,\n%s,\n%s\n",u.addr.dno,u.addr.building,u.addr.street,u.addr.area,u.addr.city,u.addr.state,u.addr.pincode);
        printf("Mobile Number: %s\nTelephone Number: %s\n",u.ph.mobile,u.ph.landline);
        printf("Date of Birth: %d / %d / %d\n", u.dob.dd, u.dob.mm, u.dob.yy);
        printf("Age: %d\n", u.age);
        printf("Gender: %c\n", u.gender);
        printf("Account Type: %s\n", u.type);
        printf("Current Balance: Rs.%f\n",u.balance);
        printf("\n");
        printf("========================================================================================================================\n");
    }
    fclose(fp);
}

void pwdchange(struct details *u)
{
  FILE *fp1, *fp2;
  struct details obj;
  char old[20],new1[20],new2[20];
  fp1=fopen("details.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&obj, 1, sizeof(obj),fp1))
  {
      if(strcmp(obj.acc_no,u->acc_no)==0)
      {
          printf("\nEnter your current password: ");
          scanf(" %[^\n]",old);
          if(strcmp(old,u->pwd)==0)
          {
              printf("Enter the new password: ");
              scanf(" %[^\n]",new1);
              printf("Confirm password: ");
              scanf(" %[^\n]",new2);
              if(strcmp(new1,new2)==0)
              {
                   strcpy(u->pwd,new1);
                   printf("\nPassword is set!\n");
                   fwrite(u, 1, sizeof(struct details),fp2);
              }
              else
              {
                   printf("Password mismatch! Try again.\n");
                   pwdchange(u);
              }
          }
          else
          {
              printf("Incorrect password! Try again.\n");
              pwdchange(u);
          }
      }
      else
      {
          fwrite(&obj, 1, sizeof(struct details),fp2);
      }
  }
  fclose(fp1);
  fclose(fp2);
  remove("details.dat");
  rename("temp.dat","details.dat");
}

void login()
{
    struct details u;
    FILE *fp;
    char u_name[20], u_pwd[10];
    fp=fopen("details.dat", "rb");
    printf("\nEnter your username (account no.): ");
    scanf(" %[^\n]", u_name);
    while(fread(&u, 1,sizeof(struct details), fp))
    {
        if(strcmp(u.acc_no,u_name)==0)
        {
            printf("\nEnter your password: ");
            scanf(" %[^\n]", u_pwd);
            if(strcmp(u_pwd,u.pwd)==0)
            {
                 printf("Welcome, %s", u.uname.fname);
                 fclose(fp);
                 menu(u);
                 break;
            }
            else
            {

                 printf("\nIncorrect username or password. Please try again.");
                 login();
            }
        }

    }


}

void menu(struct details u)
{
		int c2;
		char ch1;
		do
		{
		printf("\nEnter choice:\n1.Modify account\n2.Withdraw\n3.Deposit\n4.View account\n5.Change password\n");
		scanf("%d",&c2);
		switch(c2)
		{

			case 1:
                modify(&u);
                break;
			case 2:
                withdraw(&u);
                break;
			case 3:
                deposit(&u);
                break;
            case 4:
                view(u);
                break;
            case 5:
                pwdchange(&u);
        }
		printf("Return to user menu? (y/n)");
		scanf(" %c",&ch1);
		}while(ch1=='y');
}


int main()
{
    int c1, c3;
	char ch2,x[10];
	struct details u;
	printf("=======================================================================================================================\n");
	printf("\t\t\t\t\t\tBANK MANAGEMENT\n");
	printf("=======================================================================================================================\n");
	do
	{
	printf("Enter choice:\n");
	printf("1.User\n2.Admin\n");
	scanf("%d",&c1);
	if(c1==1)
	{
		printf("1.New User\n2.Existing User\n");
		scanf("%d",&c3);
		if(c3==1)
		{
			create(&u);
			menu(u);
		}
		else
			login();

	}
	else if(c1==2)
    {
       printf("Welcome admin\n");
       viewall();
    }

	else
    {
        printf("Invalid choice. Enter again: ");
        continue;
    }

	printf("Return to main menu? (y/n)");
	scanf(" %c",&ch2);
	}while(ch2=='y');
	return 0;
}


