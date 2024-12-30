#include<stdio.h>
#include<string.h>
void main()
{
    FILE *fp;
    int n,n1;
    char file_name[15],username[15];
    char password[5],pin[5];
    double balance,deposit,withdraw;

    printf("Enter 1 -->  to Make New Account\nEnter 2 -->  to view your Account :  ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("Enter Your ID in capital letters :");
        scanf("%s",file_name);
        printf("\n");
        fp=fopen(file_name,"w");
        printf("Enter Password of your choice (4 digit only) : ");
        scanf("%s",&password);
        printf("\n");
        printf("Enter User Name Of Your Account : ");
        scanf("%s",username);
        printf("\n");
        printf("Enter Balance you want to Deposit : ");
        scanf("%lf",&balance);
        fprintf(fp,"%s",password);
        fprintf(fp,"\n");
        fprintf(fp,"%s",username);
        fprintf(fp,"\n");
        fprintf(fp,"%.2lf",balance);
        fprintf(fp,"\n");
        fclose(fp);


    }else if(n==2)
    {
     printf("Enter Your ID in capital letters :");
      scanf("%s",file_name);
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        printf("Account doesnt exits :");

    }else
    {
       fgets(password,5,fp);
       printf("Enter Password : ");
       x:
       scanf("%s",pin);
       if(strcmp(password,pin)==0)
       {
         fscanf(fp,"%s",username);
         fscanf(fp,"%lf",&balance);
         fprintf(stdout,"Name :- %s\n",username);
         fprintf(stdout,"Balance :- %.2lf",balance);
         fclose(fp);
         printf("\nEnter 1 -->  to deposit money in Account\nEnter 2 -->  to withdraw money from your Account\nEnter 0 -->  to Exit : ");
         scanf("%d",&n1);
          if(n1==1)
          {
        printf("Enter The Amount You Want to deposit : ");
        scanf("%lf",&deposit);
        printf("\n");
        balance=balance+deposit;
        printf("Amount successfully deposited\n");
        printf("Your current balance == %.2lf ",balance);
        fp=fopen(file_name,"w");
        fprintf(fp,"%s",password);
        fprintf(fp,"\n");
        fprintf(fp,"%s",username);
        fprintf(fp,"\n");
        fprintf(fp,"%.2lf",balance);
        fprintf(fp,"\n");
        fclose(fp);



          }else if(n1==2)
           {
               s:
               printf("Enter The Amount You Want to withdraw : ");
        scanf("%lf",&withdraw);
        printf("\n");
        if(balance>withdraw)
        {
             balance=balance-withdraw;
        printf("Amount successfully withdrawn\n");
        printf("Your current balance == %.2lf ",balance);
        fp=fopen(file_name,"w");
        fprintf(fp,"%s",password);
        fprintf(fp,"\n");
        fprintf(fp,"%s",username);
        fprintf(fp,"\n");
        fprintf(fp,"%.2lf",balance);
        fprintf(fp,"\n");
        fclose(fp);
        }else
        {
            printf("\n\tInsufficient Balance\n");
            goto s;
        }





             }else if(n1==0)
             {
                 printf("\n\tThank you");
             }
       }else
       {
           printf("\tInvalid Password\n\tEnter correct Password :");
           goto x;
       }


    }



    }
    else
    {

        printf("Enter Correct Inputs \n");
    }

}
