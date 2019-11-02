/**********************************************************
Description�� ���ļ�ר�Ŵ�Ż����̳���صĺ���
Attention:  ����Ҫ��GB2312���뱣�棬��Ȼ���ֻ�������
Author���¿���
**********************************************************/
#include "score_j.h"
#include "common_c.h"
/**********************************************************
Function:  DrawBag
Description��	���������
Attention:  ��
**********************************************************/
void DrawBag(int x,int y,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(lcolor);
    setfillstyle(1,lcolor);
    line(x+40,y+80,x+140,y+80);
    line(x+40,y+80,x+40,y+190);
    line(x+140,y+80,x+140,y+190);
    line(x+40,y+190,x+140,y+190);
    line(x+50,y+180,x+130,y+180);
    ellipse(x+90,y+75,360,180,37,52);
    ellipse(x+90,y+75,360,180,29,45);
}
/**********************************************************
Function:  DrawTrolly
Description��	���������Ƴ�
Attention:  ��
**********************************************************/
void DrawTrolly(int x,int y,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(lcolor);
    setfillstyle(1,lcolor);
    line(x,y+80,x+25,y+80);
    line(x+31,y+115,x+130,y+115);
    line(x+25,y+80,x+45,y+170);
    line(x+130,y+115,x+116,y+170);
    line(x+45,y+170,x+116,y+170);
    circle(x+50,y+188,10);
    circle(x+111,y+188,10);
}
/**********************************************************
Function:  DrawMineGFrame
Description��	�����ҵĶһ�ͼ��
Attention:  ��
**********************************************************/
void DrawMineGFrame(int x,int y,int bkcolor,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+180,y+220);
    DrawBag(x,y,lcolor);
    
}
/**********************************************************
Function:  DrawStoreFrame
Description��	�����̳�ͼ��
Attention:  ��
**********************************************************/
void DrawStoreFrame(int x,int y,int bkcolor,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+180,y+220);
    DrawTrolly(x+13,y-20,lcolor);
}
/**********************************************************
Function:  DrawMagicStar_c
Description������â��
Attention:  ��
**********************************************************/
void DrawMagicStar_c(int x,int y,int color)
{
    setlinestyle(0,0,3);
    setcolor(color);
    line(x,y-40,x+34,y+20);
    line(x,y-40,x-34,y+20);
    line(x+34,y+20,x-34,y+20);
    line(x-34,y-20,x+34,y-20);
    line(x,y+40,x-34,y-20);
    line(x,y+40,x+34,y-20);
    circle(x,y,15);
}
/**********************************************************
Function:  DrawCKS_c
Description��	c������������  ��Ʒ����3
Attention:  ��
**********************************************************/
void DrawCKS_c(int x,int y,int color)
{
    setlinestyle(0,0,3);
    setcolor(color);
    circle(x,y,45);
    settextstyle(SMALL_FONT,HORIZ_DIR,10);
    outtextxy(x-32,y-22,"CKS");
}
/**********************************************************
Function:  DrawCKSFrame
Description��	����c��������������Ʒ��  ��Ʒ����4
Attention:  ��
**********************************************************/
void DrawCKSFrame(int x,int y,int bkcolor,int ccolor)
{
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+120,y+140);
    DrawCKS_c(x+60, y+58, YELLOW);
    puthz(x+2, y+110, "�����", 16, 16, ccolor); 
    setcolor(ccolor);
    setfillstyle(1,ccolor);
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(x+51,y+105,":99999");
}
/**********************************************************
Function:  DrawMagicFrame
Description��	����ħ����Ʒ��  ��Ʒ����3
Attention:  ��
**********************************************************/
void DrawMagicFrame(int x,int y,int bkcolor,int ccolor)
{
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+120,y+140);
    DrawMagicStar_c(x+60, y+60, LIGHTMAGENTA);
    puthz(x+2, y+110, "�����", 16, 16, ccolor); 
    setcolor(ccolor);
    setfillstyle(1,ccolor);
    outtextxy(x+51,y+105,":32000");
}
/**********************************************************
Function:  DrawPlaneFrame
Description��	����ʧ�µķɻ���Ʒ��  ��Ʒ����2
Attention:  ��
**********************************************************/
void DrawPlaneFrame(int x,int y,int bkcolor,int ccolor)
{
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+120,y+140);
    Drawxctubiaoone(x-125, y-60, LIGHTBLUE);
    puthz(x+2, y+110, "�����", 16, 16, ccolor); 
    setcolor(ccolor);
    setfillstyle(1,ccolor);
    outtextxy(x+51,y+105,":5000");
}
/**********************************************************
Function:  DrawAppleFrame
Description��	����ƻ����Ʒ��  ��Ʒ����1
Attention:  ��
**********************************************************/
void DrawAppleFrame(int x,int y,int bkcolor,int ccolor)
{
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+120,y+140);
    DrawApple_c(x+60,y+60);
    puthz(x+2, y+110, "�����", 16, 16, ccolor); 
    setcolor(ccolor);
    setfillstyle(1,ccolor);
    outtextxy(x+51,y+105,":800");
}
/**********************************************************
Function:  DrawAppleFrame
Description��	��ƻ��
Attention:  ��
**********************************************************/
void DrawApple_c(int x,int y)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(LIGHTRED);
    setfillstyle(1,LIGHTRED);
    sector(x,y,0,360,40,33);
    setcolor(BROWN);
    line(x-15,y-15,x+15,y-15);
    line(x,y-15,x+4,y-50);
}
/**********************************************************
Function:  DrawscoreScreen
Description��	�������ֶһ�����
Attention:  ��
**********************************************************/
void DrawscoreScreen_j(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    int mouseover[2]={0,0};
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(260,25,"�����̳�",32,32,CYAN);
    puthz(80, 80, "�û���", 16, 16, CYAN); 
    puthz(450, 80, "���֣�", 16, 16, CYAN); 
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(140,76,person->accounts);
    outtextxy(510,76,person->score);
    DrawMineGFrame(100,150,DARKGRAY,LIGHTGRAY);
    DrawStoreFrame(360,150,DARKGRAY,LIGHTGRAY);

    while(1)
    {
        newxy(&mx,&my,&buttons);
        //��������
        if (mx >= 100 && mx <= 280 && my >= 150 && my <= 370 && mouseover[0]==0) //��������ҵĶһ�
        {
            mousehide(mx,my);
            DrawMineGFrame(100,150,DARKGRAY,LIGHTBLUE);
            puthz(160, 260, "�ҵĶһ�", 16, 16, LIGHTBLUE);
            mouseover[0]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 100 && mx <= 280 && my >= 150 && my <= 370) && mouseover[0]==1) 
        {
            mousehide(mx,my);
            DrawMineGFrame(100,150,DARKGRAY,LIGHTGRAY);
            mouseover[0]=0;
            getMousebk(mx,my);
        }
        if (mx >= 360 && mx <= 540 && my >= 150 && my <= 370 && mouseover[1]==0) //���������Ʒ�һ�
        {
            mousehide(mx,my);
            DrawStoreFrame(360,150,DARKGRAY,LIGHTBLUE);
            puthz(423, 263, "��Ʒ�һ�", 16, 16, LIGHTBLUE);
            mouseover[1]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 360 && mx <= 540 && my >= 150 && my <= 370) && mouseover[1]==1) 
        {
            mousehide(mx,my);
            DrawStoreFrame(360,150,DARKGRAY,LIGHTGRAY);
            mouseover[1]=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge=turnTo_c(person,-1);
                return;
            }
            else if (mx >= 100 && mx <= 280 && my >= 150 && my <= 370)
            {
                *judge=turnTo_c(person,26);
                return;
            }
            else if (mx >= 360 && mx <= 540 && my >= 150 && my <= 370)
            {
                *judge=turnTo_c(person,25);
                return;
            }
        }
    }

}
/**********************************************************
Function:  BuyThing_c()
Description��	�һ���Ʒ
Attention:  sign��Ʒ��� 1��800���� 2��5000���� 3��32000����  4��99999����
**********************************************************/
int BuyThing_c(setuser* person,int sign)
{
    long int temp;
    if(sign==1 && atol(person->score)>=800)
    {
        ltoa(atol(person->score)-800,person->score,10);
        strcat(person->goods,"1");
        return 1;
    }
    else if(sign==2 && atol(person->score)>=5000)
    {
        ltoa(atol(person->score)-5000,person->score,10);
        strcat(person->goods,"2");
        return 2;
    }
    else if(sign==3 && atol(person->score)>=32000)
    {
        ltoa(atol(person->score)-32000,person->score,10);
        strcat(person->goods,"3");
        return 3;
    }
    else if(sign==4 && atol(person->score)>=99999)
    {
        ltoa(atol(person->score)-99999,person->score,10);
        strcat(person->goods,"4");
        return 4;
    }
    else
        return 0;
    
}
/**********************************************************
Function:  DrawStoreScreen
Description��	������Ʒ�һ����� ����25
Attention:  ��
**********************************************************/
void DrawStoreScreen(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //�����ر���
    int mouseover[4]={0,0,0,0};
    cleardevice();
    setbkcolor(WHITE);
    mouseInit(&mx, &my, &buttons);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(260,25,"��Ʒ�һ�",32,32,CYAN);
    puthz(80, 80, "�û���", 16, 16, CYAN); 
    puthz(450, 80, "���֣�", 16, 16, CYAN); 
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(140,76,person->accounts);
    outtextxy(510,76,person->score);
    DrawAppleFrame(50,115,DARKGRAY,WHITE);
    DrawPlaneFrame(190,115,DARKGRAY,WHITE);
    DrawMagicFrame(330,115,DARKGRAY,WHITE);
    DrawCKSFrame(470,115,DARKGRAY,WHITE);
    // DrawCKSFrame(470,270,DARKGRAY,WHITE);

    while(1)
    {
        newxy(&mx,&my,&buttons);
        //��������
        //��ѩ�����ĺ�ƻ��
        if(mx >= 50 && mx <= 170 && my >= 115 && my <= 255 && mouseover[0]==0)
        {
            mousehide(mx,my);
            DrawAppleFrame(50,115,LIGHTGRAY,LIGHTBLUE);
            mouseover[0]=1;
            getMousebk(mx,my);
        }
        if(!(mx >= 50 && mx <= 170 && my >= 115 && my <= 255) && mouseover[0]==1)
        {
            mousehide(mx,my);
            DrawAppleFrame(50,115,DARKGRAY,WHITE);
            mouseover[0]=0;
            getMousebk(mx,my);
        }
        //ʧ�µķɻ�
        if(mx >= 190 && mx <= 310 && my >= 115 && my <= 255 && mouseover[1]==0)
        {
            mousehide(mx,my);
            DrawPlaneFrame(190,115,LIGHTGRAY,LIGHTBLUE);
            mouseover[1]=1;
            getMousebk(mx,my);
        }
        if(!(mx >= 190 && mx <= 310 && my >= 115 && my <= 255) && mouseover[1]==1)
        {
            mousehide(mx,my);
            DrawPlaneFrame(190,115,DARKGRAY,WHITE);
            mouseover[1]=0;
            getMousebk(mx,my);
        }
        //�����ħ��
        if(mx >= 330 && mx <= 450 && my >= 115 && my <= 255 && mouseover[2]==0)
        {
            mousehide(mx,my);
            DrawMagicFrame(330,115,LIGHTGRAY,LIGHTBLUE);
            mouseover[2]=1;
            getMousebk(mx,my);
        }
        if(!(mx >= 330 && mx <= 450 && my >= 115 && my <= 255) && mouseover[2]==1)
        {
            mousehide(mx,my);
            DrawMagicFrame(330,115,DARKGRAY,WHITE);
            mouseover[2]=0;
            getMousebk(mx,my);
        }
        //c������������ŶŶŶ~
        if(mx >= 470 && mx <= 590 && my >= 115 && my <= 255 && mouseover[3]==0)
        {
            mousehide(mx,my);
            DrawCKSFrame(470,115,LIGHTGRAY,LIGHTBLUE);
            mouseover[3]=1;
            getMousebk(mx,my);
        }
        if(!(mx >= 470 && mx <= 590 && my >= 115 && my <= 255) && mouseover[3]==1)
        {
            mousehide(mx,my);
            DrawCKSFrame(470,115,DARKGRAY,WHITE);
            mouseover[3]=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge=turnTo_c(person,10);
                return;
            }
            if(mx >= 50 && mx <= 170 && my >= 115 && my <= 255)//��ѩ�����ĺ�ƻ��
            {
                if(Choose_c("��������800���ֶһ�","��ѩ�����ĺ�ƻ��һ��", &mx, &my, BROWN)==1)
                {
                    if(BuyThing_c(person,1)==1)
                    {
                        changeGoods_c(head,person);
                        infoWindow_c("�һ��ɹ���","", GREEN, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                    else
                    {
                        infoWindow_c("���Ļ��ֲ��㣡","", LIGHTRED, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                }
                else
                {
                    *judge=turnTo_c(person,25);
                    break;
                }
            }
            if(mx >= 190 && mx <= 310 && my >= 115 && my <= 255)//�ɻ�
            {
                if(Choose_c("��������5000����","�һ�һ�ܷɻ�ģ��", &mx, &my, BROWN)==1)
                {
                    if(BuyThing_c(person,2)==2)
                    {
                        changeGoods_c(head,person);
                        infoWindow_c("�һ��ɹ���","", GREEN, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                    else
                    {
                        infoWindow_c("���Ļ��ֲ��㣡","", LIGHTRED, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                }
                else
                {
                    *judge=turnTo_c(person,25);
                    break;
                }
            }
            if(mx >= 330 && mx <= 450 && my >= 115 && my <= 255)//ħ��
            {
                if(Choose_c("��������32000����","�һ����ܵ�ħ��", &mx, &my, BROWN)==1)
                {
                    if(BuyThing_c(person,3)==3)
                    {
                        changeGoods_c(head,person);
                        infoWindow_c("�һ��ɹ���","", GREEN, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                    else
                    {
                        infoWindow_c("���Ļ��ֲ��㣡","", LIGHTRED, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                }
                else
                {
                    *judge=turnTo_c(person,25);
                    break;
                }
            }
            if(mx >= 470 && mx <= 590 && my >= 115 && my <= 255)//cks
            {
                if(Choose_c("��������99999����","�һ�C������������", &mx, &my, BROWN)==1)
                {
                    if(BuyThing_c(person,4)==4)
                    {
                        changeGoods_c(head,person);
                        infoWindow_c("�һ��ɹ���","", GREEN, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                    else
                    {
                        infoWindow_c("���Ļ��ֲ��㣡","", LIGHTRED, 2000);
                        *judge=turnTo_c(person,25);
                        break;
                    }
                }
                else
                {
                    *judge=turnTo_c(person,25);
                    break;
                }
            }
        }
    }
}
/**********************************************************
Function:  DrawMyChangeScreen
Description��	�����ҵĶһ����� ����26
Attention:  ��
**********************************************************/
void DrawMyChangeScreen(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //�����ر���
    int i,m=0;
    char temp[3]={'\0','\0','\0'};
    cleardevice();
    setbkcolor(WHITE);
    mouseInit(&mx, &my, &buttons);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(90,60,"���Ķһ���¼���£�",16,16,CYAN);
    puthz(150,100,"���",16,16,CYAN);
    puthz(290,100,"��Ʒ��",16,16,CYAN);
    puthz(430,100,"���ѻ���",16,16,CYAN);
    for(i=0;person->goods[i];i++)
    {
        if(person->goods[i]>='0' && person->goods[i]<='9')//����Ƿ���0��9֮��
        {
            itoa(i+1,temp,10);
            outtextxy(160,130+i*30,temp);
            if(person->goods[i]=='1')
            {
                puthz(270,133+i*30,"��ѩ������ƻ��",16,16,CYAN);
                outtextxy(430,130+i*30,"800");
            }
            else if(person->goods[i]=='2')
            {
                puthz(270,133+i*30,"�ɻ�ģ��",16,16,CYAN);
                outtextxy(430,130+i*30,"5000");
            }
            else if(person->goods[i]=='3')
            {
                puthz(270,133+i*30,"���ܵ�ħ��",16,16,CYAN);
                outtextxy(430,130+i*30,"32000");
            }
            else if(person->goods[i]=='4')
            {
                puthz(270,133+i*30,"C������������",16,16,CYAN);
                outtextxy(430,130+i*30,"99999");
            }
        }
    }
    while(1)
    {
        newxy(&mx,&my,&buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge=turnTo_c(person,10);
                return;
            }
        }
    }
}