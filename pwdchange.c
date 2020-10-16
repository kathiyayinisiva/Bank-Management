void pwdchange(struct details *u)
{
  FILE *fp1, *fp2;
  char old[20],new1[20],new2[20];
  fp1=fopen("details.dat", "rb+");
  fp2=fopen("temp.dat","wb");
  while(fread(&u, 1, sizeof(u),fp1))
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
        else{
          printf("Password mismatch! Try again.\n");
          pwdchange(&u);
        }


      }
      else{
        printf("Incorrect password! Try again.\n");
        pwdchange(&u);
      }
  fclose(fp1);
  fclose(fp2);
  remove("details.dat");
  rename("temp.dat","details.dat");
}
