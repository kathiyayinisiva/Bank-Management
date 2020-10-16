void view(char x[])
{
  FILE *fp1, *fp2;
	struct u_details u;
  char old[20],new1[20],new2[20];
  while(fread(&u, 1, sizeof(u),fp1))
  {
    if(strcmp(x,u.acc_no)==0)
    {
		  if(u.gender=='f')
		  {
			  printf("welcome Ms..%s %s\n",u.uname.fname,u.uname.lname);
		  }
		  else if(u.gender=='m')
		  {
			  printf("Welcome Mr.%s %s\n",u.uname.fname,u.uname.lname);
		  }
		  printf("Your acccount number is %s\n",u.acc_no);
      printf("Adress:\n%d, %s, %s,\n%s, %s,\n %s,\n %s",u.addr.dno,u.addr.building,u.addr.street,u.addr.area,u.addr.city,u.addr.state,u.addr.pincode);
      printf("Mobile number: %s\nTelephone number: %s",u.ph.mobile,u.ph.landline);
      printf("\nYour current balance: %f",u.balance);
    }
  }
}
