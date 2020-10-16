void trans()
{
  FILE *fp1, *fp2;
	struct u_details u;
	struct a_details a;
  int choice;
  char t1[20],t2[20];
  printf("Enter the choice:\n1.withdraw \n2.deposit\n3.transfer\n");
  scanf("%d",&choice);
  if(choice==1)
  {
    printf("Enter your id: ");
    scanf("%s",t1);
    withdraw(t1);
  }
  else if(choice==2)
  {
    printf("Enter your id: ");
    scanf("%s",t1);
    deposit(t1);
  }
  
}


void withdraw(char s[])
{
  FILE *fp1, *fp2;
	struct u_details u;
	struct a_details a;
  float temp;
  char c,t[20];
  fp1=fopen("udetails.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&u, 1, sizeof(u),fp1))
  {
    if(strcmp(s,u.id)==0)
    {
      printf("Please enter your password:");
      scanf("%s",t);
      if(strcmp(t,u.pwd)==0)
      {
        printf("Enter the amount of money you want to withdraw: ");
        scanf("%f",&temp);
        if(a.balance<10000 && temp>5000)
        {
          printf("Your balance is less than 10000. Are you sure u want to withdraw(y/n) : ");
          scanf(" %c",&c);
          if(c=='y')
          {
            a.balance-=temp;
            printf("\nYour current balance is %f",a.balance);
            break;
          }
          else if(c=='n')
           break;
        }
      }
    }
  fwrite(&u, 1, sizeof(u),fp2);
  fclose(fp1);
  fclose(fp2);
  remove("udetails.dat");
  rename("temp.dat","udetails.dat");

  }


}



void deposit(char s[])
{
  FILE *fp1, *fp2;
	struct u_details u;
	struct a_details a;
  float temp;
  char c,t[20];
  fp1=fopen("udetails.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&u, 1, sizeof(u),fp1))
  {
    if(strcmp(s,u.id)==0)
    {
      printf("Please enter your password:");
      scanf("%s",t);
      if(strcmp(t,u.pwd)==0)
      {
        printf("Enter the amount of money you want to deposit: ");
        scanf("%f",&temp);
        
        a.balance+=temp;
        printf("\nYour current balance is %f",a.balance);
        break;
        
      }
      
    }
  }
  fwrite(&u, 1, sizeof(u),fp2);
  fclose(fp1);
  fclose(fp2);
  remove("udetails.dat");
  rename("temp.dat","udetails.dat");
}