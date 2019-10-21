#include"line_j.h"
#include"common_c.h"
void Initstation_j(station *sta,int x,int y,char* station_name);
void station_information_j(all_lines_stations *all);
void DrawCircles_j();
void Drawstation1_j();
void Drawstation2_j();
void Drawstation4_j();
/**********************************************************
 *
/**********************************************************/
/*
void outputname(int a,int b,char* sta_name)
{
    int n;//���ڴ�ų�վ��������
    int i;//ѭ������
    char arr[3]={'\0','\0','\0'};
    char temp[100];
    char kkk[5];
    strcpy(temp,sta_name);
    
    arr[0]=temp[0];
    arr[1]=temp[1];
    puthz(200,200,temp,16,16,BROWN);

    n=strlen(temp);
    itoa(n,kkk,10);
    outtextxy(80,80,kkk);
    puthz(160,160,arr,16,16,BROWN);
    // for(i=0;i<n;i++)
    // {
    //     arr[0]=sta_name[i];
    //     puthz(a,b+18*i,arr,16,16,BROWN);
    // }
}
*/
/**********************************************************
 * 
 * 
 * 
**********************************************************/
void Initstation_j(station *sta,int x,int y,char* station_name)
{
    sta->x=x;//ȷ��վ��������ͼ�ϵ�����
    sta->y=y;
    sta->distance=100;//distanceָ��վ����һվ�ľ���
    strcpy(sta->station_name,station_name);//վ����
}
void station_information_j(all_lines_stations *all)
{
    all->station_line1.number=1;//��ÿ����·���
    all->station_line2.number=2;
    all->station_line4.number=4;
    all->station_line1.station=all->line1;//ÿ����·����һ��վ��ĵ�ַ
    all->station_line2.station=all->line2;
    all->station_line4.station=all->line4;
    Initstation_j(&(all->line1[0]),0,0,"0");
    Initstation_j(&(all->line1[1]),80,100,"������");
    Initstation_j(&(all->line1[2]),140,100,"���ñ�·");
    Initstation_j(&(all->line1[3]),200,100,"����·");
    Initstation_j(&(all->line1[4]),260,100,"ѭ����");
    Initstation_j(&(all->line1[5]),320,100,"����·");
    Initstation_j(&(all->line1[6]),380,100,"�ݼö�·");
    Initstation_j(&(all->line1[7]),440,100,"����·");
    Initstation_j(&(all->line1[8]),500,100,"ͷ����");

    all->line1[8].distance=0;//���һվ����Ĭ��Ϊ0

    Initstation_j(&(all->line2[0]),0,0,"0");
    Initstation_j(&(all->line2[1]),300,70,"��ɽ��԰");
    Initstation_j(&(all->line2[2]),260,100,"ѭ����");
    Initstation_j(&(all->line2[3]),260,156,"����·");
    Initstation_j(&(all->line2[4]),260,212,"������");
    Initstation_j(&(all->line2[5]),260,278,"�з�");
    Initstation_j(&(all->line2[6]),260,334,"С��ɽ");
    Initstation_j(&(all->line2[7]),260,380,"��ɽ�㳡");
    Initstation_j(&(all->line2[8]),200,380,"����·");
    Initstation_j(&(all->line2[9]),240,410,"��ͨ��");
    all->line2[9].distance=0;

    Initstation_j(&(all->line4[0]),0,0,"0");
    Initstation_j(&(all->line4[1]),80,380,"�����վ");
    Initstation_j(&(all->line4[2]),140,380,"÷ԷС��");
    Initstation_j(&(all->line4[3]),200,380,"����·");
    Initstation_j(&(all->line4[4]),260,380,"��ɽ�㳡");
    Initstation_j(&(all->line4[5]),320,380,"���Ӻ���");
    Initstation_j(&(all->line4[6]),380,380,"������");
    Initstation_j(&(all->line4[7]),440,380,"��ͤ");
    Initstation_j(&(all->line4[8]),500,380,"������");
    
    all->line4[8].distance=0;
}
void DrawCircles_j()
{
    int i;
    setlinestyle(0, 0, 3);
    setcolor(LIGHTMAGENTA);
    for(i=0;i<=7;i++)
    {

            circle(80+60*i,100,5);
            circle(80+60*i,100,4);
            circle(80+60*i,380,5);
            circle(80+60*i,380,4);
            //circle(80+60*i,235,8);
            //circle(80+60*i,235,7);
            //circle(80+60*i,380,8);
            //circle(80+60*i,380
            
    }
    for(i=0;i<=3;i++)
    {
        circle(260,156+56*i,5);
        circle(260,156+56*i,4);
    }
    circle(300,70,5);
    circle(300,70,4);
    circle(240,410,5);
    circle(240,410,4);
}
void Drawstation1_j()
{
    int i;
    
    puthz(61,110,"������",16,16,LIGHTMAGENTA);
    puthz(108,75,"���ñ�·",16,16,LIGHTMAGENTA);
    puthz(176,110,"����·",16,16,LIGHTMAGENTA);
    puthz(210,75,"ѭ����",16,16,LIGHTMAGENTA);
    puthz(296,75,"����·",16,16,LIGHTMAGENTA);
    puthz(348,110,"�ݼö�·",16,16,LIGHTMAGENTA);
    puthz(416,75,"����·",16,16,LIGHTMAGENTA);
    puthz(486,110,"ͷ����",16,16,LIGHTMAGENTA);

    setcolor(LIGHTCYAN);
    for(i=0;i<7;i++)//����
    {
        line(85+60*i,100,135+60*i,100);
    }
}

void Drawstation2_j()
{
    int i;
    puthz(268,45,"��ɽ��԰",16,16,LIGHTMAGENTA);
    
    puthz(275,148,"����·",16,16,LIGHTMAGENTA);
    puthz(275,204,"������",16,16,LIGHTMAGENTA);
    puthz(275,270,"�з�",16,16,LIGHTMAGENTA);
    puthz(275,326,"С��ɽ",16,16,LIGHTMAGENTA);

    puthz(216,420,"��ͨ��",16,16,LIGHTMAGENTA);
    
    setcolor(LIGHTGREEN);
    for(i=0;i<5;i++)
    {
        line(260,105+56*i,260,151+56*i);
    }
    line(263,97,297,73);
    line(203,383,237,407);
    line(205,377,255,377);
}
void Drawstation4_j()
{
    int i;
    puthz(40,355,"�����վ",16,16,LIGHTMAGENTA);
    puthz(108,390,"÷ԷС��",16,16,LIGHTMAGENTA);
    puthz(168,355,"����·",16,16,LIGHTMAGENTA);
    puthz(238,390,"��ɽ�㳡",16,16,LIGHTMAGENTA);
    puthz(288,355,"���Ӻ���",16,16,LIGHTMAGENTA);
    puthz(356,390,"������",16,16,LIGHTMAGENTA);
    puthz(424,355,"��ͤ",16,16,LIGHTMAGENTA);
    puthz(486,390,"������",16,16,LIGHTMAGENTA);

    setcolor(YELLOW);
    for(i=0;i<7;i++)
    {
       line(85+60*i,380,135+60*i,380);
    }
}