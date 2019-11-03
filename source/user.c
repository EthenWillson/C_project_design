/**********************************************************
此文件专门存放改变用户信息相关的函数
作者：江明轩
**********************************************************/
#include "user.h"
#include "common_c.h"
void changemoney_j(int n, setuser *person, int radix, setuser *head);
void changescore_j(int n, setuser *person, setuser *head);
void changerecord_j(setuser *person, setuser *head, int start_name, int end_name, int price);
void change_class_j(setuser *person, setuser *head, int sign1, int sign2);
void delete_user_j(setuser *p, setuser *head);
void DrawrecordScreen_j(setuser *person, int *judge, all_lines_stations *all);
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
        fputc('&', fp); //商品兑换记录
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
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
        fputc('&', fp); //商品兑换记录
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
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
            strcpy(person->record, ph->record); //要写在里面，不然会不太正常
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
        fputc('&', fp); //商品兑换记录
        fputs(ph->goods, fp);
    }

    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  change_class
Description：	改变用户的权限码，将普通用户提升权限
Attention:  无
**********************************************************/
void change_class_j(setuser *person, setuser *head, int sign1, int sign2)
{
    FILE *fp = NULL; //打开文件的指针
    setuser *ph = head->next;

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            if (sign1 == 0) //改为运营管理员
            {
                strcpy(ph->class, "jmxzs");
            }
            else if (sign2 == 0) //改为调度管理员
            {
                strcpy(ph->class, "cjwzs");
            }
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
        fputc('&', fp); //商品兑换记录
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  delete_user
Description：	删除用户或者调度管理员的账号
Attention:  无
**********************************************************/
void delete_user_j(setuser *person, setuser *head)
{
    FILE *fp = NULL; //打开文件的指针
    setuser *ph = head;

    for (ph = head; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->next->accounts, person->accounts) == 0)
        {
            ph->next = ph->next->next;
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
        fputc('&', fp); //商品兑换记录
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  DrawrecordScreen
Description：显示出历史记录
Attention:  无
**********************************************************/
void DrawrecordScreen_j(setuser *person, int *judge, all_lines_stations *all)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    char name[20];
    char temporary[4];
    char price[2];
    int i;
    int m;
    int station_name;
    m = 0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN); //返回按钮

    puthz(90, 28, "您好！尊敬的：", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 25, person->accounts);
    puthz(90, 60, "您的购票记录如下：", 16, 16, CYAN);
    puthz(170, 100, "起点", 16, 16, GREEN);
    puthz(290, 100, "终点", 16, 16, GREEN);
    puthz(400, 100, "票价", 16, 16, GREEN);

    for (i = 0; person->record[i]; i++) //读到结束符为止
    {
        if (!(person->record[i] >= '0' && person->record[i] <= '9' || person->record[i] == '!'))
        {
            continue;
        }
        /*
        closegraph();
        printf("%d\n",i);
        printf("%s",person->record);
        getch();
        */
        m++;
        if (m % 8 == 3 || m % 8 == 6)
        {
            station_name = atoi(temporary);
            judgestation_j(50 + 40 * (m % 8), 140 + 30 * (m / 8), station_name);
            temporary[0] = '0';
            temporary[1] = '0';
        }
        else if (m % 8 == 1 || m % 8 == 4)
        {
            temporary[0] = person->record[i];
        }
        else if (m % 8 == 2 || m % 8 == 5)
        {
            temporary[1] = person->record[i];
        }
        else if (m % 8 == 7)
        {
            itoa(person->record[i] - 48, price, 10);
            puthz(400, 140 + 30 * (m / 8), price, 16, 16, LIGHTMAGENTA);
            puthz(420, 140 + 30 * (m / 8), "元", 16, 16, LIGHTMAGENTA);
            outtextxy(250, 130 + 30 * (m / 8), "->");
        }
    }

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, 6);
                return;
            }
        }
    }
}