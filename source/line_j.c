#include"line_j.h"
#include"common_c.h"
void Initstation_j(station *sta,int x,int y,char* station_name,int code,float dx,float dy,float dz);
void station_information_j(all_lines_stations *all);
void DrawCircles_j();
void Drawstation1_j();
void Drawstation2_j();
void Drawstation4_j();
void Draw_start_sta_j(int x,int y,station *sta,int *sta_checkclick,int *start_station,int *flag);
void Draw_end_sta_j(all_lines_stations *all,int x,int y,station sta,int *sta_checkclick,int *start_station,int *end_station,int *flag);
float cal_distance_j(all_lines_stations *all,int *start_name,int *end_name);
//float cal_price_j(float distance);
//int judge_sta_checkclick_j(int** sta_checkclick);
/**********************************************************
 Function:  Initstation
 Description:  给站点赋值（图里的坐标x、y，距离三元组，站名，简易站名代码）
 Attention:  注意->与.的区别
**********************************************************/
void Initstation_j(station *sta,int x,int y,char* station_name,int code,float dx,float dy,float dz)
{
    sta->x=x;//确认站点中心在图上的坐标
    sta->y=y;
    sta->distance.dx=dx;
    sta->distance.dy=dy;
    sta->distance.dz=dz;
    strcpy(sta->station_name,station_name);//站点名
    sta->simple_name=code;//站点的简易编码，便于文件读取操作
}
/**********************************************************
 Function:  station_information
 Description:  给all里面所有变量下定义
 Attention:  &(all->line1[0])，三个交点在每条线里的定义是一样的；
             注意10 20 30 00简易编码，后面文字读取会用到。
**********************************************************/
void station_information_j(all_lines_stations *all)
{
    all->station_line1.number=1;//给每条线路编号
    all->station_line2.number=2;
    all->station_line4.number=4;
    all->station_line1.station=all->line1;//每条线路赋第一个站点的地址
    all->station_line2.station=all->line2;
    all->station_line4.station=all->line4;
    //循礼门站为1号与2号线的交点，编码为“1”；类似地，洪山广场站编码为2，中南路站编码为3
    Initstation_j(&(all->line1[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line1[1]),80,100,"崇仁路",11,0,0,0);
    Initstation_j(&(all->line1[2]),140,100,"利济北路",12,0.9,0,0);
    Initstation_j(&(all->line1[3]),200,100,"友谊路",13,1.8,0,0);
    Initstation_j(&(all->line1[4]),260,100,"循礼门",10,2.8,1.5,0);
    Initstation_j(&(all->line1[5]),320,100,"大智路",15,3.9,0,0);
    Initstation_j(&(all->line1[6]),380,100,"三阳路",16,6.6,0,0);
    Initstation_j(&(all->line1[7]),440,100,"黄浦路",17,7.8,0,0);
    Initstation_j(&(all->line1[8]),500,100,"头道街",18,9.0,0,0);

    //all->line1[8].distance=0;//最后一站距离默认为0

    Initstation_j(&(all->line2[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line2[1]),300,70,"中山公园",21,0,0,0);
    Initstation_j(&(all->line2[2]),260,100,"循礼门",10,2.8,1.5,0);
    Initstation_j(&(all->line2[3]),260,156,"江汉路",23,0,4.1,0);
    Initstation_j(&(all->line2[4]),260,212,"积玉桥",24,0,7.5,0);
    Initstation_j(&(all->line2[5]),260,278,"螃蟹岬",25,0,9.1,0);
    Initstation_j(&(all->line2[6]),260,334,"小龟山",26,0,10.0,0);
    Initstation_j(&(all->line2[7]),260,380,"洪山广场",20,0,11.3,3.0);
    Initstation_j(&(all->line2[8]),200,380,"中南路",30,0,12.2,2.1);
    Initstation_j(&(all->line2[9]),240,410,"宝通寺",29,0,13.6,0);
    //all->line2[9].distance=0;

    Initstation_j(&(all->line4[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line4[1]),80,380,"武昌火车站",41,0,0,0);
    Initstation_j(&(all->line4[2]),140,380,"梅苑小区",42,0,0,1.0);
    Initstation_j(&(all->line4[3]),200,380,"中南路",30,0,12.2,2.1);
    Initstation_j(&(all->line4[4]),260,380,"洪山广场",20,0,11.3,3.0);
    Initstation_j(&(all->line4[5]),320,380,"楚河汉街",45,0,0,4.1);
    Initstation_j(&(all->line4[6]),380,380,"青鱼嘴",46,0,0,5.5);
    Initstation_j(&(all->line4[7]),440,380,"东亭",47,0,0,6.4);
    Initstation_j(&(all->line4[8]),500,380,"岳家嘴",48,0,0,7.4);
    
    //all->line4[8].distance=0;
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
    
    puthz(61,110,"崇仁路",16,16,LIGHTMAGENTA);
    puthz(108,75,"利济北路",16,16,LIGHTMAGENTA);
    puthz(176,110,"友谊路",16,16,LIGHTMAGENTA);
    puthz(210,75,"循礼门",16,16,LIGHTMAGENTA);
    puthz(296,75,"大智路",16,16,LIGHTMAGENTA);
    puthz(348,110,"三阳路",16,16,LIGHTMAGENTA);
    puthz(416,75,"黄浦路",16,16,LIGHTMAGENTA);
    puthz(486,110,"头道街",16,16,LIGHTMAGENTA);

    setcolor(LIGHTCYAN);
    for(i=0;i<7;i++)//画线
    {
        line(85+60*i,100,135+60*i,100);
    }
}

void Drawstation2_j()
{
    int i;
    puthz(268,45,"中山公园",16,16,LIGHTMAGENTA);
    
    puthz(275,148,"江汉路",16,16,LIGHTMAGENTA);
    puthz(275,204,"积玉桥",16,16,LIGHTMAGENTA);
    puthz(275,260,"螃蟹岬",16,16,LIGHTMAGENTA);
    puthz(275,316,"小龟山",16,16,LIGHTMAGENTA);

    puthz(216,420,"宝通寺",16,16,LIGHTMAGENTA);
    
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
    puthz(40,355,"武昌火车站",16,16,LIGHTMAGENTA);
    puthz(108,390,"梅苑小区",16,16,LIGHTMAGENTA);
    puthz(168,355,"中南路",16,16,LIGHTMAGENTA);
    puthz(238,390,"洪山广场",16,16,LIGHTMAGENTA);
    puthz(288,355,"楚河汉街",16,16,LIGHTMAGENTA);
    puthz(356,390,"青鱼嘴",16,16,LIGHTMAGENTA);
    puthz(424,355,"东亭",16,16,LIGHTMAGENTA);
    puthz(486,390,"岳家嘴",16,16,LIGHTMAGENTA);

    setcolor(YELLOW);
    for(i=0;i<7;i++)
    {
        line(85+60*i,380,135+60*i,380);
    }
}

float cal_distance_j(all_lines_stations *all,int *start_name,int *end_name)//计算距离的算法
{
    station sta1,sta2;
    int line_of_sta1,line_of_sta2;
    int i,j;
    float x1,y1,z1;
    float x2,y2,z2;
    //float distance;

    for(i=1;i<=8;i++)//判断是不是1号线的，并且对xyz分量赋值
    {
        if(all->line1[i].simple_name==*start_name)
        {
            x1=sta1.distance.dx;
            y1=sta1.distance.dy;
            z1=sta1.distance.dz;
            line_of_sta1=1;
        }
        if(all->line1[i].simple_name==*end_name)
        {
            x2=sta2.distance.dx;
            y2=sta2.distance.dy;
            z2=sta2.distance.dz;
            line_of_sta2=1;
        }
    }
    for(i=1;i<=9;i++)//判断是不是2号线的，并且对xyz分量赋值
    {
        if(all->line2[i].simple_name==*start_name)
        {
            x1=sta1.distance.dx;
            y1=sta1.distance.dy;
            z1=sta1.distance.dz;
            line_of_sta1=2;
        }
        if(all->line2[i].simple_name==*end_name)
        {
            x2=sta2.distance.dx;
            y2=sta2.distance.dy;
            z2=sta2.distance.dz;
            line_of_sta2=2;
        }
    }
    for(i=1;i<=8;i++)//判断是不是3号线的，并且对xyz分量赋值
    {
        if(all->line4[i].simple_name==*start_name)
        {
            x1=sta1.distance.dx;
            y1=sta1.distance.dy;
            z1=sta1.distance.dz;
            line_of_sta1=4;
        }
        if(all->line4[i].simple_name==*end_name)
        {
            x2=sta2.distance.dx;
            y2=sta2.distance.dy;
            z2=sta2.distance.dz;
            line_of_sta2=4;
        }
    }
    //至此，三元组赋值完毕，但具体属于哪条线需要考虑节点
    //10，20，30为节点，需要先特殊考虑!
    if(start_name==10)
    {
        if(line_of_sta2==1&&end_name!=20&&end_name!=30)//10和line1的
        {
            return abs(2.8-x2);//Δx
        }
        if(line_of_sta2==2||end_name==20||end_name==30)//10和line2的,包括了20和30
        {
            return abs(1.5-y2);//Δy
        }
        if(line_of_sta2==4)//10和4号线的
        {
            return 9.8+abs(z2-3);//终点和Node2距离+Node1与Node2距离
        }
    }
    else if(start_name==20)
    {
        if(line_of_sta2==1||end_name==10&&end_name!=30)
        {
            return abs(2.8-x2)+9.8;//终点与Node1距离+Node1与Node2距离
        }
        if(line_of_sta2==2||end_name==30)
        {
            return abs(11.3-y2);//Δy
        }
        if(line_of_sta2==4)
        {
            return abs(3.0-z2);//Δz
        }
    }
    else if(start_name==30)
    {
        if(line_of_sta2==1||end_name==10&&end_name!=20)
        {
            return abs(2.8-x1)+9.8+0.9;//终点和Node1距离+Node1与Node2距离+Node2与Node3距离
        }
        if(line_of_sta2==2||end_name==20)
        {
            return abs(11.3-y2)+0.9;//终点和Node2距离+Node2与Node3距离
        }
        if(line_of_sta2==4)
        {
            return abs(3.0-z2);//Δz
        }
    }
    else if(end_name==10)
    {
        if(line_of_sta1==1&&start_name!=20&&start_name!=30)//10和line1的
        {
            return abs(2.8-x1);//Δx
        }
        if(line_of_sta1==2||start_name==20||start_name==30)//10和line2的,包括了20和30
        {
            return abs(1.5-y1);//Δy
        }
        if(line_of_sta1==4)//10和4号线的
        {
            return 9.8+abs(z1-3);//起点和Node2距离+Node1与Node2距离
        }
    }
    else if(end_name==20)
    {
        if(line_of_sta1==1||start_name==10&&start_name!=30)
        {
            return abs(2.8-x1)+9.8;//起点与Node1距离+Node1与Node2距离
        }
        if(line_of_sta1==2||start_name==30)
        {
            return abs(11.3-y1);//Δy
        }
        if(line_of_sta1==4)
        {
            return abs(3.0-z1);//Δz
        }
    }
    else if(end_name==30)
    {
        if(line_of_sta1==1||start_name==10&&start_name!=20)
        {
            return abs(2.8-x1)+9.8+0.9;//起点和Node1距离+Node1与Node2距离+Node2与Node3距离
        }
        if(line_of_sta1==2||start_name==20)
        {
            return abs(11.3-y1)+0.9;//起点和Node2距离+Node2与Node3距离
        }
        if(line_of_sta1==4)
        {
            return abs(3.0-z1);//Δz
        }
    }
    else if(line_of_sta1==1&&line_of_sta2==1)
    {
        return abs(x1-x2);//Δx
    }
    else if(line_of_sta1==1&&line_of_sta2==2)
    {
        return abs(2.8-x1)+abs(1.5-y2);//起点到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==1&&line_of_sta2==3)
    {
        return abs(2.8-x1)+9.8+abs(3.0-z2);//起点到Node1距离+Node1到Node2距离+Node2距离到终点距离
    }
    else if(line_of_sta1==2&&line_of_sta1==1)
    {
        return abs(1.5-y1)+abs(2.8-x2);//起点到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==2&&line_of_sta2==2)
    {
        return abs(y1-y2);//Δy
    }
    else if(line_of_sta1==2&&line_of_sta2==3)
    {
        return abs(11.3-y1)+abs(3.0-z2);//起点到Node2距离+Node2到终点距离
    }
    else if(line_of_sta1==3&&line_of_sta2==1)
    {
        return abs(3.0-z1)+9.8+abs(2.8-x2);//起点到Node2距离+Node2到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==3&&line_of_sta2==2)
    {
        return abs(3.0-z1)+abs(11.3-y2);//起点到Node2距离+Node2到终点距离
    }
    else if(line_of_sta1==3&&line_of_sta2==3)
    {
        return abs(z1-z2);//Δz
    }
    
}

void Draw_start_sta_j(int x,int y,station *sta,int *sta_checkclick,int *start_station,int *flag)
{
    puthz(30,130,"起点：",16,16,RED);
    puthz(80,130,sta->station_name,16,16,RED);
    setcolor(RED);
    circle(x,y,5);
    circle(x,y,4);
    *sta_checkclick=1;
    *start_station=sta->simple_name;//起点简易代码
    *flag=1;
}

void Draw_end_sta_j(all_lines_stations *all,int x,int y,station sta,int *sta_checkclick,int *start_station,int *end_station,int *flag)
{
    float distance=0;
    float price=0;
    /*
    if(*start_station==*end_station)
    {
        setcolor(LIGHTMAGENTA);
        circle(x,y,5);
        circle(x,y,4);
        *sta_checkclick=0;//点击了两次，就当作没点击
        *start_station=0;//起点没了
        *end_station=0;//终点没了
        setfillstyle(1,WHITE);//把原来的涂掉
        bar(20,120,200,100);
        *flag=0;
    }
    */
       *end_station=sta.simple_name;
    //if(*start_station!=*end_station)
    //{
        //float s;
        //int a[10];//把distance变成字符串后存储的数组
        //int i;

        puthz(30,160,"终点：",16,16,RED);
        puthz(80,160,sta.station_name,16,16,RED);
        setcolor(RED);
        circle(x,y,5);
        circle(x,y,4);
        /*
        closegraph();
        printf("%d  %d\n",x,y);
        printf("%d  %d\n",sta.distance.dx,sta.distance.dx);
        printf("\n%s",sta.station_name);
        getch();
        */
        *sta_checkclick=1;//代表这站也点过了
        distance=cal_distance_j(all,start_station,end_station);
        //price=cal_price_j(distance);
        puthz(30,190,"距离：",16,16,RED);
        //outtextxy(80,190,distance);//计算距离
        //puthz(30,220,"票价：",16,16,RED);
        //outtextxy(80,220,price);//计算票价
        *flag=2;
    //}
    
}
/*
int judge_sta_checkclick_j(int** sta_checkclick)//标志数组都是0，返回1，代表“还没点击”
{
    int i,j;
    int flag=1;
    for(i=0;i<5;i++)
    {
        for(j=0;j<10;j++)
        {
            if(sta_checkclick[i][j])
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}
*/
