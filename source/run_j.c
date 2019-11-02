#include "common_c.h"
/**********************************************************
Description�� ���ļ�ר�Ŵ����Ӫ��صĺ���
Attention:  ��ѯ�û��������������֣����м�¼�����ҿ���ע���û�
Author��������
**********************************************************/
void DrawLine_j(int x1,int y1,int x2,int y2,int x3,int y3,int color);
void DrawStar_j();
void Draw_run_Screen_j(setuser *person,int* judge,setuser *head);
/**********************************************************
Function:  DrawLine
Description��������
Attention:  ��
**********************************************************/
void DrawLine_j(int x1,int y1,int x2,int y2,int x3,int y3,int color)
{
    setlinestyle(0,0,3);
    setcolor(color);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}
/**********************************************************
Function:  DrawStar
Description������â��
Attention:  ��
**********************************************************/
void DrawStar_j()
{
    setlinestyle(0,0,3);
    setcolor(YELLOW);
    line(320,100,185,340);
    line(185,340,455,340);
    line(455,340,320,100);
    line(185,180,455,180);
    line(455,180,320,420);
    line(320,420,185,180);
}
/**********************************************************
Function:  Draw_run_Screen
Description����Ӫ����Ա��������
Attention:  ��
**********************************************************/
void Draw_run_Screen_j(setuser *person,int* judge,setuser *head)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    int sign[2]={0,0};//�����ж�����ƶ�����ť�ϵı�־
    int page;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);//������Ϣ��ʾ��
	//ͷ��ͼ��
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	pieslice(25,25,0,360,20);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	pieslice(25,20,0,360,9);
	pieslice(25,25,232,308,19);
	//����
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	puthz(60, 17, "�û���", 16, 16, WHITE);
	puthz(250, 17, "��ݣ���Ӫ����Ա", 16, 16, WHITE);
    //�û���
    outtextxy(110,13,person->accounts);
	//���˳�ϵͳ��ť
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(600, 30, 110, 430, 15);
	line(600, 5, 600, 31);
    //����â�ǣ�����
    DrawStar_j();
    //������
    puthz(305,140,"��Ʊ",16,16,WHITE);
    puthz(215,185,"�޸�",16,16,WHITE);
    puthz(215,210,"����",16,16,WHITE);
    puthz(395,185,"����",16,16,WHITE);
    puthz(395,210,"�̳�",16,16,WHITE);
    puthz(215,295,"�û�",16,16,WHITE);
    puthz(215,320,"��ѯ",16,16,WHITE);
    puthz(395,295,"Ȩ��",16,16,WHITE);
    puthz(395,320,"����",16,16,WHITE);
    puthz(305,360,"��ֵ",16,16,WHITE);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)//����¼�
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45 && buttons)//ע����ť����˳�
			{
				page=Choose_c("���Ƿ�Ҫע��","", &mx, &my, BROWN);
				if(page==1)
				{
					*judge=1;
					return;
				}
				else if(page==0)
				{
					*judge=2;
					return;
				}
			}
			else if(mx >= 0 && mx <= 50 && my >= 0&& my <= 50 && buttons)//�����������
			{
				*judge=turnTo_c(person,4);
				return;
			}
		}
        if(mx>=276&&mx<=364&&my>=100&&my<=179)//��Ʊ
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                //DrawLine_j(320,100,275,180,365,180,DARKGRAY);
                DrawLine_j(320,100,275,180,365,180,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               *judge=turnTo_c(person,5);
                return;
            } 
        }
        else if(mx>=185&&mx<=274&&my>=181&&my<=259)//�޸�����
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                DrawLine_j(185,180,275,180,230,260,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               *judge=turnTo_c(person,14);
                return;
            } 
        }
        else if(mx>=366&&mx<=455&&my>=181&&my<=259)//�����̳�
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                DrawLine_j(365,180,455,180,410,260,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               *judge=turnTo_c(person,10);
                return;
            } 
        }
        else if(mx>=185&&mx<=274&&my>=261&&my<=339)//�û���ѯ
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                DrawLine_j(230,260,185,340,275,340,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               //��ûд
            } 
        }
        else if(mx>=366&&mx<=455&&my>=261&&my<=339)//Ȩ�޹���
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                DrawLine_j(410,260,365,340,455,340,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               //��ûд
            } 
        }
        else if(mx>=276&&mx<=364&&my>=341&&my<=420)//��ֵ
        {
            if(sign[0]==0)
            {
                mousehide(mx,my);
                sign[0]=1;
                DrawLine_j(275,340,365,340,320,420,WHITE);
                getMousebk(mx,my);
            }
            if(buttons)
            {
               *judge=turnTo_c(person,7);
                return;
            } 
        }
        else if(sign[0]==1&&!(mx>=275&&mx<=365&&my>=100&&my<=180&&sign[0]==0)&&!(mx>=185&&mx<=275&&my>=180&&my<=260)&&!(mx>=365&&mx<=455&&my>=180&&my<=260)
        &&!(mx>=185&&mx<=275&&my>=260&&my<=340)&&!(mx>=365&&mx<=455&&my>=260&&my<=340)&&!(mx>=275&&mx<=365&&my>=340&&my<=420))
        {
            mousehide(mx,my);
            DrawStar_j();
            sign[0]=0;
            getMousebk(mx,my);
        }
    }
}