void viewall(struct u_details u)
{
    FILE *fp;
    fp=fopen("details.dat", "rb");
    printf("\nDETAILS OF CUSTOMERS: ");
    while(fread(&u, sizeof(u), 1, fp))
    {
        printf("Account Number: %s\n",u.acc_no);
        printf("Name of Customer: %s %s\n", u.uname.fname, u.uname.lname);
        printf("Address:\n%d, %s, %s,\n%s, %s,\n %s,\n %s",u.addr.dno,u.addr.building,u.addr.street,u.addr.area,u.addr.city,u.addr.state,u.addr.pincode);
        printf("Mobile Number: %s\nTelephone Number: %s",u.ph.mobile,u.ph.landline);
        printf("Date of Birth: %d / %d / %d\n", u.dob.dd, u.dob.mm, u.dob.yy);
        printf("Age: %d\n", u.age);
        printf("Gender: %c\n", u.gender);
        printf("Account Type: %s", u.type);
        printf("\nCurrent Balance: %f",u.balance););
        printf("\n");
    }
    fclose(fp);
}
