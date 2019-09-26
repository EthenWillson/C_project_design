#include"account_j.h"
#include"struct_c.h"
#include"common_c.h"

void change_account_j(setuser person)//把用户的余额写入文档ACCOUNT中
{
    FILE *faccount;
    if((faccount=fopen("data_c\\user\\account.txt","rt"))==NULL)
    {
        faccount=fopen("data_c\\user\\account.txt","wt+");
    }
    faccount=fopen("data_c\\user\\account.txt","at+");
    //@用户$余额
    fputc('@',faccount);//@标志一个用户的开头
    fputs(person.accounts,faccount);
   
    fputc('$',faccount);//$标志用户余额
    fputs(person.money,faccount);
    
    fclose(faccount);
}