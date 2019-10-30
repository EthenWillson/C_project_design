#include"line_j.h"
#include"common_c.h"
void Initstation_j(station *sta,int x,int y,char* station_name,int code,float dx,float dy,float dz);
void station_information_j(all_lines_stations *all);
void DrawCircles_j();
void Drawstation1_j();
void Drawstation2_j();
void Drawstation4_j();
void Draw_start_sta_j(int x,int y,station *sta,int *sta_checkclick,int *start_station,int *flag);
void Draw_end_sta_j(all_lines_stations *all,int x,int y,station sta,int *sta_checkclick,int *start_station,int *end_station,int *flag,int *price);
float cal_distance_j(all_lines_stations *all,int *start_name,int *end_name);
int cal_price_j(float distance);
void transform1(float num,char* str);
void transform2(float num,char* str);
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
    //cjw
    srand(clock()+time(NULL));
    sta->peopleNum=rand()%2000;
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
    /*
    closegraph();
    printf("%f\n",all->line1[4].distance.dx);
    printf("%f\n",all->line1[4].distance.dy);
    printf("%f\n",all->line1[4].distance.dz);
    getch();
    */
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
    Initstation_j(&(all->line2[5]),260,268,"螃蟹岬",25,0,9.1,0);//修改278->268
    Initstation_j(&(all->line2[6]),260,324,"小龟山",26,0,10.0,0);//修改334->224
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
/**********************************************************
 Function:  cal_distance
 Description:  根据三元组，计算
 Attention:  &(all->line1[0])，三个交点在每条线里的定义是一样的；
             注意10 20 30 00简易编码，后面文字读取会用到。
**********************************************************/
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
            x1=all->line1[i].distance.dx;
            y1=all->line1[i].distance.dy;
            z1=all->line1[i].distance.dz;
            line_of_sta1=1;
        }
        if(all->line1[i].simple_name==*end_name)
        {
            x2=all->line1[i].distance.dx;
            y2=all->line1[i].distance.dy;
            z2=all->line1[i].distance.dz;
            line_of_sta2=1;
        }
    }
    for(i=1;i<=9;i++)//判断是不是2号线的，并且对xyz分量赋值
    {
        if(all->line2[i].simple_name==*start_name)
        {
            x1=all->line2[i].distance.dx;
            y1=all->line2[i].distance.dy;
            z1=all->line2[i].distance.dz;
            line_of_sta1=2;
        }
        if(all->line2[i].simple_name==*end_name)
        {
            x2=all->line2[i].distance.dx;
            y2=all->line2[i].distance.dy;
            z2=all->line2[i].distance.dz;
            line_of_sta2=2;
        }
    }
    for(i=1;i<=8;i++)//判断是不是3号线的，并且对xyz分量赋值
    {
        if(all->line4[i].simple_name==*start_name)
        {
            x1=all->line4[i].distance.dx;
            y1=all->line4[i].distance.dy;
            z1=all->line4[i].distance.dz;
            line_of_sta1=4;
        }
        if(all->line4[i].simple_name==*end_name)
        {
            x2=all->line4[i].distance.dx;
            y2=all->line4[i].distance.dy;
            z2=all->line4[i].distance.dz;
            line_of_sta2=4;
        }
    }
    /*
    closegraph();
    printf("%f\n",x1);
    printf("%f\n",y1);
    printf("%f\n",z1);
    printf("%f\n",x2);
    printf("%f\n",y2);
    printf("%f\n",z2);
    getch();
    */

    //至此，三元组赋值完毕，但具体属于哪条线需要考虑节点
    //10，20，30为节点，需要先特殊考虑!
    if(*start_name==29&&*end_name==30)
    {
        return 1.4;
    }
    if(*end_name==29&&*start_name==30)
    {
        return 1.4;
    }
    else if(*start_name==10)
    {
        if(line_of_sta2==1&&*end_name!=20&&*end_name!=30)//10和line1的
        {
            return fabs(2.8-x2);//Δx
        }
        if(line_of_sta2==2||*end_name==20||*end_name==30)//10和line2的,包括了20和30
        {
            return fabs(1.5-y2);//Δy
        }
        if(line_of_sta2==4)//10和4号线的
        {
            return 9.8+fabs(z2-3);//终点和Node2距离+Node1与Node2距离
        }
    }
    else if(*start_name==20)
    {
        if(line_of_sta2==1||*end_name==10&&*end_name!=30)
        {
            return fabs(2.8-x2)+9.8;//终点与Node1距离+Node1与Node2距离
        }
        if(line_of_sta2==2||*end_name==30)
        {
            return fabs(11.3-y2);//Δy
        }
        if(line_of_sta2==4)
        {
            return fabs(3.0-z2);//Δz
        }
    }
    else if(*start_name==30)
    {
        if(*end_name=29)
        {
            return fabs(13.6-12.2);
        }
        if(line_of_sta2==1||*end_name==10&&*end_name!=20)
        {
            return fabs(2.8-x1)+9.8+0.9;//终点和Node1距离+Node1与Node2距离+Node2与Node3距离
        }
        if(line_of_sta2==2||*end_name==20)
        {
            return fabs(11.3-y2)+0.9;//终点和Node2距离+Node2与Node3距离
        }
        if(line_of_sta2==4)
        {
            return fabs(3.0-z2);//Δz
        }
        
    }
    else if(*end_name==10)
    {
        if(line_of_sta1==1&&*start_name!=20&&*start_name!=30)//10和line1的
        {
            return fabs(2.8-x1);//Δx
        }
        if(line_of_sta1==2||*start_name==20||*start_name==30)//10和line2的,包括了20和30
        {
            return fabs(1.5-y1);//Δy
        }
        if(line_of_sta1==4)//10和4号线的
        {
            return 9.8+fabs(z1-3);//起点和Node2距离+Node1与Node2距离
        }
    }
    else if(*end_name==20)
    {
        if(line_of_sta1==1||*start_name==10&&*start_name!=30)
        {
            return fabs(2.8-x1)+9.8;//起点与Node1距离+Node1与Node2距离
        }
        if(line_of_sta1==2||*start_name==30)
        {
            return fabs(11.3-y1);//Δy
        }
        if(line_of_sta1==4)
        {
            return fabs(3.0-z1);//Δz
        }
    }
    else if(*end_name==30)
    {
        if(*start_name==29)
        {
            return fabs(13.6-12.2);
        }
        if(line_of_sta1==1||*start_name==10&&*start_name!=20)
        {
            return fabs(2.8-x1)+9.8+0.9;//起点和Node1距离+Node1与Node2距离+Node2与Node3距离
        }
        if(line_of_sta1==2||*start_name==20)
        {
            return fabs(11.3-y1)+0.9;//起点和Node2距离+Node2与Node3距离
        }
        if(line_of_sta1==4)
        {
            return fabs(3.0-z1);//Δz
        }
    }
    else if(line_of_sta1==1&&line_of_sta2==1)
    {
        return fabs(x1-x2);//Δx
    }
    else if(line_of_sta1==1&&line_of_sta2==2)
    {
        return fabs(2.8-x1)+fabs(1.5-y2);//起点到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==1&&line_of_sta2==4)
    {
        return fabs(2.8-x1)+9.8+fabs(3.0-z2);//起点到Node1距离+Node1到Node2距离+Node2距离到终点距离
    }
    else if(line_of_sta1==2&&line_of_sta2==1)
    {
        return fabs(1.5-y1)+fabs(2.8-x2);//起点到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==2&&line_of_sta2==2)
    {
        return fabs(y1-y2);//Δy
    }
    else if(line_of_sta1==2&&line_of_sta2==4)
    {
        return fabs(11.3-y1)+fabs(3.0-z2);//起点到Node2距离+Node2到终点距离
    }
    else if(line_of_sta1==4&&line_of_sta2==1)
    {
        return fabs(3.0-z1)+9.8+fabs(2.8-x2);//起点到Node2距离+Node2到Node1距离+Node1到终点距离
    }
    else if(line_of_sta1==4&&line_of_sta2==2)
    {
        return fabs(3.0-z1)+fabs(11.3-y2);//起点到Node2距离+Node2到终点距离
    }
    else if(line_of_sta1==4&&line_of_sta2==4)
    {
        return fabs(z1-z2);//Δz
    }
    
}
int cal_price_j(float distance)
{
    int price=0;
    if(distance<=4) price=2;
    else if(distance>4&&distance<=8) price=3;
    else if(distance>8&&distance<=12) price=4;
    else if(distance>12&&distance<=18) price=5;
    else return 0;
    return price;
}

void transform1(float num,char* str)
{
    int n;
	n=(int)num;
	itoa(n,str,10);
}

void transform2(float num,char *str)
{
    int n;
	n=(int)((((num)-(int)num)*10)+0.5);//5.1怎么变成了5.0?
    itoa(n,str,10);
    
    // closegraph();
    // printf("n=%d\n",n);
    // printf("num=%f\n",num);
    // printf("%d\n%f\n%f",(int)num,(((num)-(int)num)*10),((((num)-(int)num)*10)+0.5));
    // printf("str=%s",str);
    // getch();
    
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

void Draw_end_sta_j(all_lines_stations *all,int x,int y,station sta,int *sta_checkclick,int *start_station,int *end_station,int *flag,int *price)
{
    float distance=0;
    char price_string[2];//存放价格的字符串形式的数组
    char distance_string1[3];//存放距离的整数部分的字符串形式的数组
    char distance_string2[2];//小数部分
    //eg：16.7，则str1={1，6，'\0'}，str2={7,'\0'}。
    //起点终点相同，就什么也不做
    *end_station=sta.simple_name;
    if(*start_station!=*end_station)
    {
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
        getch();//否则一闪而过
        */
        *sta_checkclick=1;//代表这站也点过了
        distance=cal_distance_j(all,start_station,end_station);
        *price=cal_price_j(distance);
        itoa(*price,price_string,10);//将价格数转化成字符串，便于输出
        transform1(distance,distance_string1);
        transform2(distance,distance_string2);
        /*
        closegraph();
        printf("%f\n",distance);
        getch();
        */
        /*
        printf("%d\n",price);
        printf("%s\n",distance_string1);
        printf("%s\n",distance_string2);
        printf("%s\n",price_string);
        getch();
        */
        settextstyle(0,0,2);
        puthz(30,190,"距离：",16,16,RED);
        outtextxy(80,190,distance_string1);//输出距离
        outtextxy(105,190,".");
        outtextxy(115,190,distance_string2);
        outtextxy(130,190,"km");
        puthz(30,220,"票价：",16,16,RED);
        outtextxy(80,220,price_string);//输出票价
        puthz(95,220,"元",16,16,RED);
        *flag=2;
    }
    
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
