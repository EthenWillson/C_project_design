/**********************************************************
此文件专门存放改变用户信息相关的函数
作者：江明轩
**********************************************************/
#include "customer_j.h"
#include "common_c.h"
void changemoney_j(int n, setuser *person, int radix, setuser *head);
void changescore_j(int n, setuser *person, setuser *head);
void changerecord_j(setuser *person, setuser *head, int start_name, int end_name, int price);
/**********************************************************
Function:  changemoney
Description：	改变文件中用户余额
Attention:  字符串与int之间的转换
**********************************************************/
void changemoney_j(int n, setuser *person, int radix, setuser *head) //文件操作
{
    int number;
    FILE *fp = NULL; //打开文件的指针
    setuser *ph = head->next;

    number = atoi(person->money);
    itoa(n + number, person->money, radix); //用于修改person->money的值，字符串与整型之间的转换

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            strcpy(ph->money, person->money); //修改链表中person->money值
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //以写的方式新建一个文件
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@标志一个用户的开头
        fputs(ph->accounts, fp);
        fputc('*', fp); //*标志用户密码的开头
        fputs(ph->code, fp);
        fputc('#', fp); //#标志用户的权限码
        fputs(ph->class, fp);
        fputc('$', fp); //$标志用户余额
        fputs(ph->money, fp);
        fputc('(', fp); //(标志用户积分
        fputs(ph->score, fp);
        fputc('^', fp); //出行记录
        fputs(ph->record, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
    return 0;
}
/**********************************************************
Function:  changescore
Description：	改变文件中用户积分
Attention:  无
**********************************************************/
void changescore_j(int n, setuser *person, setuser *head)
{
    int number;
    FILE *fp = NULL; //打开文件的指针
    setuser *ph = head->next;

    number = atoi(person->score);
    itoa(n + number, person->score, 10); //用于修改person->score的值，字符串与整型之间的转换

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            strcpy(ph->score, person->score); //修改链表中person->score值
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //以写的方式新建一个文件
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@标志一个用户的开头
        fputs(ph->accounts, fp);
        fputc('*', fp); //*标志用户密码的开头
        fputs(ph->code, fp);
        fputc('#', fp); //#标志用户的权限码
        fputs(ph->class, fp);
        fputc('$', fp); //$标志用户余额
        fputs(ph->money, fp);
        fputc('(', fp); //(标志用户积分
        fputs(ph->score, fp);
        fputc('^', fp); //出行记录
        fputs(ph->record, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
    return 0;
}
/**********************************************************
Function:  changerecord
Description：	改变文件中用户历史记录
Attention:  无
**********************************************************/
void changerecord_j(setuser *person, setuser *head, int start_name, int end_name, int price) //文件操作
{
    int number;
    FILE *fp = NULL; //打开文件的指针
    setuser *ph = head->next;
    char start_str[3];
    char end_str[3];
    char price_str[2];
    itoa(start_name, start_str, 10);
    itoa(end_name, end_str, 10);
    itoa(price, price_str, 10);

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            strcat(ph->record, start_str);
            strcat(ph->record, "!");
            strcat(ph->record, end_str);
            strcat(ph->record, "!");
            strcat(ph->record, price_str);
            strcat(ph->record, "!");
            strcpy(person->record,ph->record);//要写在里面，不然会不太正常
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //以写的方式新建一个文件
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@标志一个用户的开头
        fputs(ph->accounts, fp);
        fputc('*', fp); //*标志用户密码的开头
        fputs(ph->code, fp);
        fputc('#', fp); //#标志用户的权限码
        fputs(ph->class, fp);
        fputc('$', fp); //$标志用户余额
        fputs(ph->money, fp);
        fputc('(', fp); //(标志用户积分
        fputs(ph->score, fp);
        fputc('^', fp); //出行记录
        fputs(ph->record, fp);
    }
    
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
    return 0;
}

