#include"setfun.c"
int main()
{
    FILE *p1;
    while(1)
       {
            int i,n,choice,num=1,pass,stem=0,choice1,logout,count=3,key;
            float amount;
            struct details d;
            char password[20],account_no[15];
            system("cls");
            system("color 0F");
            printf("\t\t=======================================\n");
            printf("\t\t\xb2\xb2\xb2\xb2\xb2WELCOME TO BANK OF COIMBATROE\xb2\xb2\xb2\xb2\xb2");
            printf("\n\t\t=======================================");
            printf("\n\t\t1.Customer login");
            printf("\n\t\t2.Admin login");
            printf("\n\t\t3.New account opening");
            printf("\n\t\t4.exit\n");
            scanf(" %d",&choice);
            printf("\a");
      if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
         {
             printf("\n\nNot valid try again later...\n\n");
             printf("press any key...");
             getch();
             break;
         }

      if(choice==2)
         {
             while(count--)
                {
                    system ("cls");
                    bank();
                    printf("\n\nEnter the password:");
                    scanf("%s",password);
                    if(strcmp(password,PASSWORD)==0)
                        {
                            system ("color 09");
                            printf("password match!\nLOADING");
                            for(i=0;i<6;i++)
                                {
                                    delay(100000000);
                                    printf(".");
                                }
                                    printf("\n1.All customer details");
                                    scanf("%d",&key);
                                    switch(key)
                                        {
                                            case 1:check ();
                                                    break;
                                        }
                                    printf("\npress any key to logout...");
                                    getch();
                                    break;
                             }
                    else
                       {
                            if(count!=0)
                                {
                                    printf("\n %d tries left...\n",count);
                                    printf("press any key...");
                                    getch();
                                }
                            else
                               {
                                     printf("\a\a\a\a");
                                     system("color 0C");
                                     printf("\nActivity reported...");
                                     getch();
                                     break;
                               }

                      }

             }

     }
    if(choice==1)
        {
            printf("Enter the account number:");
            scanf("%s",account_no);
            p1=fopen("details.txt","rb+");
            if(p1==NULL)
                {
                    printf("cannot open file...");
                    exit(1);
                }
    while(1)
        {
            fseek(p1,sizeof(d)*i++,0);
            fread(&d,sizeof(d),1,p1);
            if(strcmp(d.account_no,account_no)==0)
                {
                    stem=1;
                    break;
                }
                if(feof(p1))
                break;
       }
    if(stem==1)
        {
            system("color 0B");
            printf("Account found...\n");
            printf("\nWelcome... %s\n",d.name);
            printf("press any key");
            getch();
       }
    else
        {
            printf("Account not found...\n\n");
            printf("\a\a\a\a");
            system("color 0C");
            printf("Try after some time...");
            break;
       }
    while(1)
    {
         system("cls");
         bank();
         printf("\nEnter your password:");
         scanf("%s",password);
         if(strcmp(password,d.password)==0)
            {
                system ("cls");
                bank();
                system ("color 0A");
                printf("\npassword match!\nLOADING");
                for(i=0;i<6;i++)
                    {
                        delay(100000000);
                        printf(".");
                    }
                break;
         }
         else
            {
                printf("Wrong password...\n\n");
                printf("\a\a\a\a");
                system("color 0C");
                printf("press 1 to re-try\npress 2 to exit\n");
                scanf("%d",&pass);
                if(pass==2)
                    {
                        printf("Thankyou for using our service...\n");
                        exit(0);
                    }
                else
                   printf("%d attempts left\n",(3-num++));
                   printf("\npress any key...");
                   getch();
                   if(num==4)
                   {
                       printf("\nExceeded the limit...\nTry again later");
                       printf("\a\a\a\a");
                       exit(0);
                   }
          }
    }
    while(1)
    {
       system("cls");
       bank();
       printf("\n1.Deposit\n");
       printf("2.Withdraw\n");
       printf("3.Edit details\n");
       printf("4.Balance check\n");
       printf("5.Delete account\n");
       printf("6.Logout");
       scanf("%d",&choice1);
       printf("\a");

          switch(choice1)
          {
              case 1:system("cls");
                     bank();
                     printf("\n\nDEPOSIT\n");
                     while(1)
                     {
                         printf("balance=%.2f\n",d.balance);
                         printf("Enter the amount to deposit:");
                         scanf("%f",&amount);
                         if(amount>0)
                            {
                                d.balance+=amount;
                                printf("New balance=%.2f",d.balance);
                                fseek(p1,sizeof(d)*d.key,0);
                                fwrite(&d,sizeof(d),1,p1);
                                break;
                            }
                         else
                            {
                                printf("Not valid...");
                            }

                     }
                      printf("\npress any key to continue...");
                      getch();
                      break;
              case 2: system("cls");
                      bank();
                      printf("\n\nWITHDRAW\n");
                      while(1)
                        {
                            printf("balance=%.2f\n",d.balance);
                            printf("Enter the amount to withdraw:");
                            scanf("%f",&amount);
                            if(amount>0 && amount<=d.balance )
                                {
                                    d.balance-=amount;
                                    printf("New balance=%.2f\n",d.balance);
                                    fseek(p1,sizeof(d)*d.key,0);
                                    fwrite(&d,sizeof(d),1,p1);
                                    break;
                                }
                            else
                                {
                                    printf("Insufficient balance...");
                                }
                        }
                        printf("\npress any key to continue");
                        getch();
                        break;
               case 3:system("cls");
                      bank();
                      printf("\n\nEDIT");
                      edit(d.key);
                      printf("press any key...\n");
                      getch();
                      break;
               case 4:system("cls");
                      bank();
                      printf("\n\nBALANCE CHECK");
                      printf("\nbalance=%.2f\n\n",d.balance);
                      getch();
                      break;
               case 5:system("cls");
                      bank();
                      printf("\n\nDELETE ACCOUNT");
                      delete(d.key,p1);
                      choice1=6;
                      break;
          }//switch
    if(choice1==6)
       break;

    }//while
    fclose(p1);

    }//if

if(choice==3)
    account_creation();
if(choice==4)
     break;
    }
    return 0;
}

