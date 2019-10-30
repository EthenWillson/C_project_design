#include"help_j.h"   
#include"common_c.h"

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
void judgestation_j(int station_name,int x,int y)
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
    else if(station_name==31) puthz(x,y,"�����վ",16,16,LIGHTMAGENTA);
    else if(station_name==32) puthz(x,y,"÷ԷС��",16,16,LIGHTMAGENTA);
    else if(station_name==35) puthz(x,y,"���Ӻ���",16,16,LIGHTMAGENTA);
    else if(station_name==36) puthz(x,y,"������",16,16,LIGHTMAGENTA);
    else if(station_name==37) puthz(x,y,"��ͤ",16,16,LIGHTMAGENTA);
    else if(station_name==38) puthz(x,y,"������",16,16,LIGHTMAGENTA);
}
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
void DrawrecordScreen_j(setuser *person,int *judge,all_lines_stations* all)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    char name[20];
    char temporary[4];
    int i,j;
    int x,y;
    int m;
    int station_name;
    j=50;
    x=50;
    y=50;
    m=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);//���ذ�ť

    for(i=0;person->record[i];i++)//����������Ϊֹ
    {
        
        if(person->record[i]='!')
        {
            m++;//��m��3�ı���ʱ������
            continue;
        }
        if(m%3==2)
        {
            temporary[i]=person->record[i];
            station_name=atoi(temporary);
            judgestation_j(50+90*(m/3),50+30*(m/8),station_name);    
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

void Draw_about_us_Screen_j(int *judge)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);//���ذ�ť

    puthz(60,60,"�人������ͨģ��ϵͳ HUST AUTO Version 1-0-1",16,16,LIGHTMAGENTA);
    puthz(60,90,"designed by �¿��⣬������ from HUST",16,16,LIGHTMAGENTA);
    puthz(60,120,"��ϵͳ��Ϊ�������飺",16,16,LIGHTMAGENTA);
    puthz(60,150,"A��ͨ�û�  B����Ա",16,16,LIGHTMAGENTA);
    puthz(60,180,"��ͨ�û�:",16,16,CYAN);
    puthz(60,210,"��ʵ�֣������˺ţ��������룬��Ʊ������ֵ���˻���ѯ�����ֶһ�",16,16,CYAN);
    puthz(60,240,"B.����Ա:",16,16,CYAN);
    puthz(60,270,"��ʵ�֣��û��˹��ܣ���������",16,16,CYAN);
    puthz(200,400,"��HUST AUTO��ɼ�����Э�顷",16,16,RED);
    puthz(200,430,"HUST��Ȩ����",16,16,RED);
    puthz(100,460,"Copyright @2019-2020 All Rights Reserved",16,16,RED);



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
   
    