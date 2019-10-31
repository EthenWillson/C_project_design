#include"help_j.h"   
#include"common_c.h"
/**********************************************************
Function:  DrawpriceScreen
Description���۸�ͼ
Attention:  ��
**********************************************************/
void DrawpriceScreen_j(setuser* person,int* judge)
{
    
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);//���ذ�ť

    
    puthz(60,60,"�𾴵��û������ã�",16,16,LIGHTMAGENTA);
    puthz(60,90,"�����人���������շѱ�׼��",16,16,LIGHTMAGENTA);
    puthz(60,120,"��1���г�4�������ڣ���4�����2Ԫ��",16,16,LIGHTMAGENTA);
    puthz(60,150,"��2���г�4����12�����12�����1Ԫÿ4���",16,16,LIGHTMAGENTA);
    puthz(60,180,"��3���г�12����24�����24�����1Ԫÿ6���",16,16,LIGHTMAGENTA);
    puthz(60,210,"������ڵ�ͼ�ϲ�ѯ",16,16,LIGHTMAGENTA);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, 5);
                return;
            }
        }
    }   
}
/**********************************************************
Function:  judgestation
Description����վ��ļ��ױ�����վ�������ڣ�x��y������ʾ����
Attention:  ��
**********************************************************/
void judgestation_j(int x,int y,int station_name)
{
    if(station_name==10) puthz(x,y,"ѭ����",16,16,LIGHTMAGENTA);
    else if(station_name==11) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==12) puthz(x,y,"���ñ�·",16,16,LIGHTMAGENTA);
    else if(station_name==13) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==15) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==16) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==17) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==18) puthz(x,y,"ͷ����",16,16,LIGHTMAGENTA);
    else if(station_name==21) puthz(x,y,"��ɽ��԰",16,16,LIGHTMAGENTA);
    else if(station_name==23) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==24) puthz(x,y,"������",16,16,LIGHTMAGENTA);
    else if(station_name==25) puthz(x,y,"�з�",16,16,LIGHTMAGENTA);
    else if(station_name==26) puthz(x,y,"С��ɽ",16,16,LIGHTMAGENTA);
    else if(station_name==20) puthz(x,y,"��ɽ�㳡",16,16,LIGHTMAGENTA);
    else if(station_name==29) puthz(x,y,"��ͨ��",16,16,LIGHTMAGENTA);
    else if(station_name==30) puthz(x,y,"����·",16,16,LIGHTMAGENTA);
    else if(station_name==41) puthz(x,y,"�����վ",16,16,LIGHTMAGENTA);
    else if(station_name==42) puthz(x,y,"÷ԷС��",16,16,LIGHTMAGENTA);
    else if(station_name==45) puthz(x,y,"���Ӻ���",16,16,LIGHTMAGENTA);
    else if(station_name==46) puthz(x,y,"������",16,16,LIGHTMAGENTA);
    else if(station_name==47) puthz(x,y,"��ͤ",16,16,LIGHTMAGENTA);
    else if(station_name==48) puthz(x,y,"������",16,16,LIGHTMAGENTA);
}
/**********************************************************
Function:  DrawDistance
Description����ʾվ��֮��ľ���
Attention:  ��
**********************************************************/
void DrawDistance_j()
{
    setcolor(RED);
    settextstyle(0,0,1);
    //line1
    outtextxy(100,100,"0.9");
    outtextxy(160,100,"0.9");
    outtextxy(220,100,"1.0");
    outtextxy(280,100,"1.1");
    outtextxy(340,100,"2.7");
    outtextxy(400,100,"1.2");
    outtextxy(460,100,"1.2");
    //line2
    outtextxy(280,85,"1.5");
    outtextxy(255,120,"2.6");
    outtextxy(255,180,"3.4");
    outtextxy(255,240,"1.6");
    outtextxy(255,290,"0.9");
    outtextxy(255,350,"1.3");
    outtextxy(220,395,"1.4");
    //line4
    outtextxy(100,380,"1.0");
    outtextxy(160,380,"1.1");
    outtextxy(220,380,"0.9");
    outtextxy(280,380,"1.1");
    outtextxy(340,380,"1.4");
    outtextxy(400,380,"0.9");
    outtextxy(460,380,"1.0");
}
/**********************************************************
Function:  DrawrecordScreen
Description����ʾ����ʷ��¼
Attention:  ��
**********************************************************/
void DrawrecordScreen_j(setuser *person,int *judge,all_lines_stations* all)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    char name[20];
    char temporary[4];
    char price[2];
    int i;
    int m;
    int station_name;    
    m=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);//���ذ�ť

    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 25, person->accounts);
    puthz(90,60,"���Ĺ�Ʊ��¼���£�",16,16,CYAN);
    puthz(170,100,"���",16,16,GREEN);
    puthz(290,100,"�յ�",16,16,GREEN);
    puthz(400,100,"Ʊ��",16,16,GREEN);

    for(i=0;person->record[i];i++)//����������Ϊֹ
    {
        m++;
        if(m%8==3||m%8==6)
        {
            station_name=atoi(temporary);
            judgestation_j(50+40*(m%8),140+30*(m/8),station_name);
            temporary[0]='0';
            temporary[1]='0';
        }
        else if(m%8==1||m%8==4)
        {
            temporary[0]=person->record[i];
        }
        else if(m%8==2||m%8==5)
        {
            temporary[1]=person->record[i];
        }
        else if(m%8==7)
        {
            itoa(person->record[i]-48,price,10);
            puthz(400,140+30*(m/8),price,16,16,LIGHTMAGENTA);
            puthz(420,140+30*(m/8),"Ԫ",16,16,LIGHTMAGENTA);
            outtextxy(250,130+30*(m/8),"->");
        }
    }

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, 6);
                return;
            }
        }
    }   
}
/**********************************************************
Function:  Draw_about_us_Screen
Description����������
Attention:  ��
**********************************************************/
void Draw_about_us_j(int *judge)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);//���ذ�ť

    puthz(60,60,"�人������ͨģ��ϵͳ",16,16,LIGHTMAGENTA);
    setcolor(YELLOW);
    outtextxy(240,54,"Version 1.0.1");
    setcolor(LIGHTMAGENTA);
    outtextxy(60,84,"designed by");
    puthz(200,90,"�¿��⣬������",16,16,LIGHTMAGENTA);
    outtextxy(320,84,"from HUST");
    puthz(60,120,"��ϵͳ��Ϊ�������飺",16,16,LIGHTMAGENTA);
    puthz(60,150,"A��ͨ�û�  B����Ա",16,16,LIGHTMAGENTA);
    puthz(60,180,"��ͨ�û���",16,16,CYAN);
    puthz(60,210,"��ʵ�֣������˺ţ��������룬��Ʊ������ֵ���˻���ѯ�����ֶһ�",16,16,CYAN);
    puthz(60,240,"����Ա��",16,16,CYAN);
    puthz(60,270,"��ʵ�֣��û��˹��ܣ���������",16,16,CYAN);
    puthz(170,350,"��HUST AUTO��ɼ�����Э�顷",16,16,YELLOW);
    puthz(230,380,"HUST��Ȩ����",16,16,YELLOW);
    setcolor(YELLOW);
    outtextxy(130,410,"Copyright @2019 All Rights Reserved");
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = 1;
                return;
            }
        }
    }   
}
   
    