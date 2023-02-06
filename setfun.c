#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
#define PASSWORD "lovetocode"
struct details
{
    char account_no[15];
    char branch_code[15],product_code[15];
    char name[20],sex[7],aadhar[13];
    int date,month,year,key;
    char password[20];
    float balance;

};
void bank()
{
    printf("\t\t==============================\n");
    printf("\t\t\xb2\xb2\xb2\xb2\xb2 BANK OF COIMBATORE \xb2\xb2\xb2\xb2\xb2");
    printf("\n\t\t==============================");
}

void account_creation()
{
    FILE *p1;
    struct details d,t;
    int i,temp,temp1,n,pass_length=0,pass_upper=0,pass_symbol=0,pass_lower=0,aadhar_key=0;
    int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    long int temp_account;
    char tempaccount_no[20],temp_zero[8],temp_pass[20];
    char product[][4]={" ","201","202","203","204","205","206","207","208"};
    char zero[][20]={" ","000000","00000","0000","000","00","0"};
    printf("Name:");
    scanf(" %[^\n]s",d.name);
    while(1)
        {
            printf("\nEnter your Aadhar no:");
            scanf("%s",d.aadhar);
            if(strlen(d.aadhar)==12)
                {
                    for(i=0;i<12;i++)
                       if(!isdigit(d.aadhar[i]) && d.aadhar[0]!='0' && d.aadhar[1]!='1')

                           aadhar_key=1;                     /*aadhar nummber should not start from 0 or 1 and it
                                                                should be 12 digit in length*/
                           if(aadhar_key)
                              printf("Enter a valid no...\n");
                           else
                              break;
                }
            else
            printf("Enter a vaild no...");
    }
    while(1)
        {
            printf("press\n 1 for female\n 2 for male:");
            scanf("%d",&temp);
            if(temp==1 || temp==2)
                break;
                printf("Enter a valid number");
        }
    if(temp==1)
        {
            strcpy(d.sex,"Female");
        }
     else
        strcpy(d.sex,"Male");

     printf("Date Of Birth:\n");
     while(1)
        {
            printf("Year:");
            scanf("%d",&d.year);
            if(d.year>1900 && d.year<2023)               //assuming that the falls between 1901-2023
                break;
                printf("Enter a valid year...\n");
        }
     if((d.year%4)==0)                              //In the above mentioned range if the year is divisible by 4 then it is a leap year
        month[2]=29;
     else
        month[2]=28;
    while(1)
        {
            printf("Month:");
            scanf("%d",&d.month);
            if(d.month>0 && d.month<13)
                break;
                printf("Enter a valid month...\n");
        }
     while(1)
        {
            printf("Date:");
            scanf("%d",&d.date);
            if(d.date>0 && d.date<=month[d.month])
            break;
            printf("Enter a valid date...\n");
        }

     printf("Enter the branch where the account to be opened\n1.Peelamedu\n2.Gandhipuram\n3.Perianaicken Palayam\n");
     scanf("%d",&temp);
     while(1)
        {
            if(temp==1 || temp==2 || temp==3)
            break;
            printf("Enter a valid number...\n");
        }
     if(temp==1)
        strcpy(d.branch_code,"7612");
           else if(temp==2)                             //These are the respective branch codes
              strcpy(d.branch_code,"9217");
                 else
                    strcpy(d.branch_code,"3517");

     while(1)
        {
            printf("press...\n 1 for Savings account\n 2 for Current account:\n\n");
            scanf("%d",&temp1);
            if(temp1==1 || temp1==2)                         //savings or current
                break;
                printf("Enter a valid number\n");
        }
     while(1)
        {
            printf("press...\n1 for Rural\n2 for Semi Urban\n3 for Urban\n4 for Metropolitan\n\n");
            scanf("%d",&temp);
            if(temp==1 || temp==2 || temp==3 || temp==4)
                break;
                printf("Enter a valid number...\n");
        }
    if(temp1==1)
    {
        strcpy(d.product_code,product[temp]);               /*         rural semiurban urban metropolitan
                                                              savings   201      202     203     204
                                                              current   205      206     207     208 */

                                                            //char product[][4]={" ","201","202","203","204","205","206","207","208"};
    }
           else if(temp1==2)
           {
              strcpy(d.product_code,product[4+temp]);
           }

    p1=fopen("details.txt","rb");
    if(p1==NULL)
        {
            printf("Cannot open file...\n");
            exit(1);
        }
    fseek(p1,0,2);
    n=ftell(p1);                                        // lenfth of key        0     1        2       3     4     5   6
    n=n/sizeof(d);                                      //char zero[][20]=    {" ","000000","00000","0000","000","00","0"};
    fseek(p1,(n-1)*sizeof(d),0);
    fread(&t,sizeof(d),1,p1);
    d.key=t.key+1;                                       //value of key is read from the last record new key=key+1
    sprintf(temp_zero,"%d",d.key);                       //key is converted to character of array and the length is found by
    strcat(zero[strlen(temp_zero)],temp_zero);           //strlen function which tells the zeros to be added before the key
    strcpy(tempaccount_no,zero[strlen(temp_zero)]);      //    1->000000+1->201+000000+1->7612+201+000000+1
    strcat(d.branch_code,strcat(d.product_code,tempaccount_no));
    strcpy(d.account_no,d.branch_code);
    fclose(p1);
    printf("1 file closed...\n\n");
    printf("\nNOTE:Your password should contain...\n1.Atleast 8 characters\n2.Mixture of  uppercase and lowercase letters\n3.Atleast 1 special character\n\n");
    while(1)
        {
            printf("\nEnter your password:");
            scanf(" %[^\n]s",d.password);
            if(strlen(d.password)>=8)
            pass_length=1;
            for(i=0;i<strlen(d.password);i++)
                {
                    if(isupper(d.password[i]))
                        pass_upper=1;
                    if(ispunct(d.password[i]))
                        pass_symbol=1;
                    if(islower(d.password[i]))
                        pass_lower=1;
                }
            if(pass_length*pass_upper*pass_lower*pass_symbol)
                break;
            if(!pass_upper)
                printf("\n**your password should contain a upper case alphabet**\n");
            if(!pass_lower)
                printf("\n**your password should contain a lower case alphabet**\n");
            if(!pass_length)
                printf("\n**your password should be atleast 8 characters of length**\n");
            if(!pass_symbol)
                printf("\n**your password should contain a special character**\n");

      }
        while(1)
            {
                printf("\n\nRenter the passsword:");
                scanf(" %[^\n]s",temp_pass);
                if(strcmp(d.password,temp_pass)==0)
                    break;
                printf("Your password didn't match\n");
            }
        p1=fopen("details.txt","ab");
        if(p1==NULL)
        {
            printf("cannot open file...\n");
            exit(1);
        }
    fwrite(&d,sizeof(d),1,p1);
    fclose(p1);
    system("color 0B");
    system("cls");
    bank();
    printf("\n\n\t\tAccount created successfully...\n\n");
    printf("\t\tAccount no:%s\n",d.account_no);
    printf("\t\tName:%s\n",d.name);
    printf("\t\tSex:%s\n",d.sex);
    printf("\t\tDOB:%d/%d/%d\n",d.date,d.month,d.year);
    printf("\t\tPassword:%s\n\n",d.password);
    printf("press any key to home page...");
    getch();
return ;
}

void delay(int j)
{
    int i=0,k;                   //gets the j value,runs the loop for j times and the control is returned.
    for(i=0;i<j;i++)
        k=i;
    return;
}

void edit(int key)
{
    FILE *p;
    char temp_pass[20];
    int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int i,n,pass_length=0,pass_upper=0,pass_symbol=0,pass_lower=0,temp_sex;
    struct details d;
    p=fopen("details.txt","rb+");
    printf("\nvalue of n??\n1.Name\n2.DOB\n3.Sex\n4.Password\n5.Exit");
    scanf("%d",&n);
    if(p==NULL)
    {
        printf("cannot open file...\n");
        exit(1);
    }
    else
        fseek(p,sizeof(d)*key,0);
        fread(&d,sizeof(d),1,p);
        system("cls");
        bank();
        printf("---------------------------------------------------------------------\n");
        printf("ACCOUNT NO\tNAME\tAADHAR NO\tDOB\t\tSEX\n");
        printf("---------------------------------------------------------------------\n\n");
        printf("%s\t",d.account_no);
        printf("%-1s\t",d.name);
        printf("%s\t",d.aadhar);
        printf("%d/%d/%d\t",d.date,d.month,d.year);
        printf("%s\t",d.sex);
        printf("\n");
    if(n==1)
      {
         printf("Enter the name:");
         scanf("%s",d.name);
      }
    else if(n==2)
      {
        printf("Date Of Birth:\n");
        while(1)
            {
                printf("Year:");
                scanf("%d",&d.year);
                if(d.year>1900 && d.year<2023)
                    break;
                printf("Enter a valid year...");
            }
    if((d.year%4)==0)
        month[1]=29;
    else
        month[1]=28;

    while(1)
        {
            printf("Month:");
            scanf("%d",&d.month);
            if(d.month>0 && d.month<13)
                break;
            printf("Enter a valid month...");
        }
     while(1)
        {
        printf("Date:");
        scanf("%d",&d.date);
        if(d.date>0 && d.date<=month[d.month])
            break;
        printf("Enter a valid date...");
        }

    }
    else if(n==3)
    {
        while(1)
        {
            printf("press...\n1.Female\n2.Male");
            scanf("%d",&temp_sex);
                if(temp_sex==1)
                    {
                        strcpy(d.sex,"Female");
                            break;
                    }
                else if(temp_sex==2)
                        {
                            strcpy(d.sex,"Male");
                            break;
                        }
                else
                    printf("Enter a valid number...");
        }
    }
    else if(n==4)
        {
            while(1)
                {
                    printf("\nEnter your password:");
                    scanf(" %[^\n]s",d.password);
                    if(strlen(d.password)>=8)
                    pass_length=1;
                    for(i=0;i<strlen(d.password);i++)
                        {
                            if(isupper (d.password[i]))
                                pass_upper=1;
                            if(ispunct(d.password[i]))
                                pass_symbol=1;
                            if(islower(d.password[i]))
                                pass_lower=1;
                        }
                    if(pass_length * pass_upper * pass_lower * pass_symbol)
                        break;
                    if(!pass_upper)
                        printf("\n**your password should contain a upper case alphabet**\n");
                    if(!pass_lower)
                        printf("\n**your password should contain a lower case alphabet**\n");
                    if(!pass_length)
                        printf("\n**your password should be atleast 8 characters of length**\n");
                    if(!pass_symbol)
                        printf("\n**your password should contain a special character**\n");

    }
        while(1)
            {
                printf("\n\nRenter the passsword:");
                scanf(" %[^\n]s",temp_pass);
                if(strcmp(d.password,temp_pass)==0)
                break;
                printf("Your password didn't match\n");

            }
    }
    if(n==5)
        {
            fclose(p);
            return ;
        }
        system("cls");
        bank();
        printf("------------------------------------------------------------------------------\n");
        printf("ACCOUNT NO\tNAME\tAADHAR NO\tDOB\t\tSEX\n");
        printf("----------------------------------------------------------------------------\n\n");
        printf("%s\t",d.account_no);
        printf("%-1s\t",d.name);
        printf("%s\t",d.aadhar);
        printf("%d/%d/%d\t",d.date,d.month,d.year);
        printf("%s\t",d.sex);
        printf("\n");
        fseek(p,sizeof(d)*key,0);
        fwrite(&d,sizeof(d),1,p);
        printf("success...");
        fclose(p);
        return ;
}


void delete(int key,FILE *p)                //*p catches the address of the file pointer
{
    FILE *p1;
    int n,j=0,i;
    struct details d;
    p1=fopen("temp_details.txt","wb+");     //opening a binaryfile of both redding and writing type
    if(p1==NULL)
        {
            printf("cannot open file...");
            exit(0);
        }
    if(p==NULL)
        {
            printf("cannot open file...");
            exit(0);
        }
        fseek(p,0,2);                 //moving to crusor to the end of the file now it is currently pointing to the null character
        n=ftell(p);                   //this tells how many bytes are before it
        n=n/sizeof(d);                //this gives the no.of records
        struct details t[n];
        for(i=0;i<n;i++)
            {
                if(i!=key)            //if i=key ,then the single record is not copied to the temp_details file
                    {
                        fseek(p,(sizeof(d)*i),0);
                        fread(&d,sizeof(d),1,p);
                        d.key=j++;
                        fwrite(&d,sizeof(d),1,p1);
                    }

       }
       fclose(p);
       fclose(p1);
       p1=fopen("temp_details.txt","rb");
       p=fopen("details.txt","wb");
       fread(t,sizeof(d),n-1,p1);      //the no.of.elemets is n-1 as one record is removed
       fwrite(t,sizeof(d),n-1,p);
       fclose(p);
       fclose(p1);
       printf("\nAccount deleted successfully...");
       printf("\npress any key to continue...");
       getch();
return;
}

void check()
{
    struct details d;
    int i,n;
    FILE *p;
    p=fopen("details.txt","rb");
    if(p==NULL)
    {
        printf("cannot open file...\n");
        exit(1);
    }
    else
        printf("file opened...\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("S.NO\tACCOUNT NO\tNAME\tAADHAR NO\tDOB\t\tSEX\tBALANCE\t\n");
        printf("--------------------------------------------------------------------------------\n");
        fseek(p,0,2);
        n=ftell(p);
        n=n/sizeof(d);
        for(i=0;i<n;i++)
            {
                fseek(p,(sizeof(d)*i),0);
                fread(&d,sizeof(d),1,p);
                printf("%d\t",i+1);
                printf("%s\t",d.account_no);
                printf("%-1s\t",d.name);
                printf("%s\t",d.aadhar);
                printf("%d/%d/%d\t",d.date,d.month,d.year);
                printf("%s\t",d.sex);
                printf("%.2f",d.balance);
                printf("\n");
            }
    return;

}

