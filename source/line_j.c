#include"line_j.h"
#include"common_c.h"

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
    puthz(60,60,temp,16,16,BROWN);

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
void Initstation(station *sta,int x,int y,int radius,char *station_name)
{
    int i;//��ӡ��վ��ѭ����ѭ������
    sta->x=x;//ȷ��վ��������ͼ�ϵ�����
    sta->y=y;
    setlinestyle(0,0,3);
    setcolor(YELLOW);
    circle(sta->x,sta->y,radius);
    circle(sta->x,sta->y,radius-1);
    strcpy(sta->station_name,station_name);
    outputname(x-8,y+10,sta->station_name);

}

void Drawstation()
{
    station line2[7];//��վ�ṹ����
    // Initstation(&line2[0],80,235,8,"��ӻ���");
    Initstation(&line2[0],80,235,8,"��ӻ���");
    Initstation(&line2[1],150,235,8,"��ȹ㳡");
    Initstation(&line2[2],220,235,8,"����·");
    Initstation(&line2[3],290,235,8,"���пƼ���ѧ");
    Initstation(&line2[4],360,235,8,"��ȴ��");
    Initstation(&line2[5],430,235,8,"��԰·");
    Initstation(&line2[6],500,235,8,"������");
}