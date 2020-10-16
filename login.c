void login(struct u_details u)
{
    FILE *fp;
    char u_name[10], u_pwd[10];
    fp=fopen("udetails.dat", "rb");
    printf("\nEnter your username: ");
    scanf(" %[^\n]", u_name);
    printf("\nEnter your password: ");
    scanf(" %[^\n]", u_pwd);
    fread(&u, sizeof(u), 1, fp);
    if((strcmp(u.acc_no,u_name))&&(strcmp(u.pwd, u_pwd)))
    {
        printf("Welcome, %s", u.uname.fname);
        menu();
    }
    else
    {
        printf("\nIncorrect username or password. Please try again.");
        login(u);
    }
    fclose(fp);
}
