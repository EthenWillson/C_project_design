#include"line_j.h"
#include"common_c.h"

void outputname(int a,int b,char* sta_name)
{
    int n;//用于存放车站名的字数
    int i;//循环变量
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
    int i;//打印车站名循环的循环变量
    sta->x=x;//确认站点中心在图上的坐标
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
    station line2[7];//车站结构数组
    // Initstation(&line2[0],80,235,8,"天河机场");
    Initstation(&line2[0],80,235,8,"天河机场");
    Initstation(&line2[1],150,235,8,"光谷广场");
    Initstation(&line2[2],220,235,8,"珞雄路");
    Initstation(&line2[3],290,235,8,"华中科技大学");
    Initstation(&line2[4],360,235,8,"光谷大道");
    Initstation(&line2[5],430,235,8,"佳园路");
    Initstation(&line2[6],500,235,8,"佛祖岭");
}