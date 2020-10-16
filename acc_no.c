#define N 10
void acc_no(struct u_details u)
{
    char acc_no[N]='\0';
    int k=0;
    for(int i=0;i<10;i++)
    {
        if((i==0)||(i==1))
            u.acc_no[i]=u.addr.pincode[i];
        else if((i>1)&&(i<=5))
            u.acc_no[i]=u.uname.fname[k++];
        else if((i>5)&&(i<=9))
            u.acc_no[i]=u.ph.mobile[i];
    }
    printf("Your username is %s", u.acc_no);
    printf("\nEnter the password: (password should be a maximum of 10 characters) ");
    scanf(" %[^\n]", u.pwd);
    printf("\nYour login ID and and password have been saved successfully!");
}
