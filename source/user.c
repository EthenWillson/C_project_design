/**********************************************************
���ļ�ר�Ŵ�Ÿı��û���Ϣ��صĺ���
���ߣ�������
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
Description��	�ı��ļ����û����
Attention:  �ַ�����int֮���ת��
**********************************************************/
void changemoney_j(int n, setuser *person, int radix, setuser *head) //�ļ�����
{
    int number;
    FILE *fp = NULL; //���ļ���ָ��
    setuser *ph = head->next;

    number = atoi(person->money);
    itoa(n + number, person->money, radix); //�����޸�person->money��ֵ���ַ���������֮���ת��

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            strcpy(ph->money, person->money); //�޸�������person->moneyֵ
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts, fp);
        fputc('*', fp); //*��־�û�����Ŀ�ͷ
        fputs(ph->code, fp);
        fputc('#', fp); //#��־�û���Ȩ����
        fputs(ph->class, fp);
        fputc('$', fp); //$��־�û����
        fputs(ph->money, fp);
        fputc('(', fp); //(��־�û�����
        fputs(ph->score, fp);
        fputc('^', fp); //���м�¼
        fputs(ph->record, fp);
        fputc('&', fp); //��Ʒ�һ���¼
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  changescore
Description��	�ı��ļ����û�����
Attention:  ��
**********************************************************/
void changescore_j(int n, setuser *person, setuser *head)
{
    int number;
    FILE *fp = NULL; //���ļ���ָ��
    setuser *ph = head->next;

    number = atoi(person->score);
    itoa(n + number, person->score, 10); //�����޸�person->score��ֵ���ַ���������֮���ת��

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            strcpy(ph->score, person->score); //�޸�������person->scoreֵ
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts, fp);
        fputc('*', fp); //*��־�û�����Ŀ�ͷ
        fputs(ph->code, fp);
        fputc('#', fp); //#��־�û���Ȩ����
        fputs(ph->class, fp);
        fputc('$', fp); //$��־�û����
        fputs(ph->money, fp);
        fputc('(', fp); //(��־�û�����
        fputs(ph->score, fp);
        fputc('^', fp); //���м�¼
        fputs(ph->record, fp);
        fputc('&', fp); //��Ʒ�һ���¼
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  changerecord
Description��	�ı��ļ����û���ʷ��¼
Attention:  ��
**********************************************************/
void changerecord_j(setuser *person, setuser *head, int start_name, int end_name, int price) //�ļ�����
{
    int number;
    FILE *fp = NULL; //���ļ���ָ��
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
            strcpy(person->record, ph->record); //Ҫд�����棬��Ȼ�᲻̫����
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts, fp);
        fputc('*', fp); //*��־�û�����Ŀ�ͷ
        fputs(ph->code, fp);
        fputc('#', fp); //#��־�û���Ȩ����
        fputs(ph->class, fp);
        fputc('$', fp); //$��־�û����
        fputs(ph->money, fp);
        fputc('(', fp); //(��־�û�����
        fputs(ph->score, fp);
        fputc('^', fp); //���м�¼
        fputs(ph->record, fp);
        fputc('&', fp); //��Ʒ�һ���¼
        fputs(ph->goods, fp);
    }

    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  change_class
Description��	�ı��û���Ȩ���룬����ͨ�û�����Ȩ��
Attention:  ��
**********************************************************/
void change_class_j(setuser *person, setuser *head, int sign1, int sign2)
{
    FILE *fp = NULL; //���ļ���ָ��
    setuser *ph = head->next;

    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->accounts, person->accounts) == 0)
        {
            if (sign1 == 0) //��Ϊ��Ӫ����Ա
            {
                strcpy(ph->class, "jmxzs");
            }
            else if (sign2 == 0) //��Ϊ���ȹ���Ա
            {
                strcpy(ph->class, "cjwzs");
            }
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts, fp);
        fputc('*', fp); //*��־�û�����Ŀ�ͷ
        fputs(ph->code, fp);
        fputc('#', fp); //#��־�û���Ȩ����
        fputs(ph->class, fp);
        fputc('$', fp); //$��־�û����
        fputs(ph->money, fp);
        fputc('(', fp); //(��־�û�����
        fputs(ph->score, fp);
        fputc('^', fp); //���м�¼
        fputs(ph->record, fp);
        fputc('&', fp); //��Ʒ�һ���¼
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  delete_user
Description��	ɾ���û����ߵ��ȹ���Ա���˺�
Attention:  ��
**********************************************************/
void delete_user_j(setuser *person, setuser *head)
{
    FILE *fp = NULL; //���ļ���ָ��
    setuser *ph = head;

    for (ph = head; ph != NULL; ph = ph->next)
    {
        if (strcmp(ph->next->accounts, person->accounts) == 0)
        {
            ph->next = ph->next->next;
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL) //��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for (ph = head->next; ph != NULL; ph = ph->next)
    {
        fputc('@', fp); //@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts, fp);
        fputc('*', fp); //*��־�û�����Ŀ�ͷ
        fputs(ph->code, fp);
        fputc('#', fp); //#��־�û���Ȩ����
        fputs(ph->class, fp);
        fputc('$', fp); //$��־�û����
        fputs(ph->money, fp);
        fputc('(', fp); //(��־�û�����
        fputs(ph->score, fp);
        fputc('^', fp); //���м�¼
        fputs(ph->record, fp);
        fputc('&', fp); //��Ʒ�һ���¼
        fputs(ph->goods, fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt", "data_c\\user\\userinf.txt");
}
/**********************************************************
Function:  DrawrecordScreen
Description����ʾ����ʷ��¼
Attention:  ��
**********************************************************/
void DrawrecordScreen_j(setuser *person, int *judge, all_lines_stations *all)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
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
    returnBtn_c(550, 210, GREEN); //���ذ�ť

    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 25, person->accounts);
    puthz(90, 60, "���Ĺ�Ʊ��¼���£�", 16, 16, CYAN);
    puthz(170, 100, "���", 16, 16, GREEN);
    puthz(290, 100, "�յ�", 16, 16, GREEN);
    puthz(400, 100, "Ʊ��", 16, 16, GREEN);

    for (i = 0; person->record[i]; i++) //����������Ϊֹ
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
            puthz(420, 140 + 30 * (m / 8), "Ԫ", 16, 16, LIGHTMAGENTA);
            outtextxy(250, 130 + 30 * (m / 8), "->");
        }
    }

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, 6);
                return;
            }
        }
    }
}