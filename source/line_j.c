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
 Description:  ��վ�㸳ֵ��ͼ�������x��y��������Ԫ�飬վ��������վ�����룩
 Attention:  ע��->��.������
**********************************************************/
void Initstation_j(station *sta,int x,int y,char* station_name,int code,float dx,float dy,float dz)
{
    sta->x=x;//ȷ��վ��������ͼ�ϵ�����
    sta->y=y;
    sta->distance.dx=dx;
    sta->distance.dy=dy;
    sta->distance.dz=dz;
    strcpy(sta->station_name,station_name);//վ����
    sta->simple_name=code;//վ��ļ��ױ��룬�����ļ���ȡ����
    //cjw
    srand(clock()+time(NULL));
    sta->peopleNum=rand()%2000;
}
/**********************************************************
 Function:  station_information
 Description:  ��all�������б����¶���
 Attention:  &(all->line1[0])������������ÿ������Ķ�����һ���ģ�
             ע��10 20 30 00���ױ��룬�������ֶ�ȡ���õ���
**********************************************************/
void station_information_j(all_lines_stations *all)
{
    all->station_line1.number=1;//��ÿ����·���
    all->station_line2.number=2;
    all->station_line4.number=4;
    all->station_line1.station=all->line1;//ÿ����·����һ��վ��ĵ�ַ
    all->station_line2.station=all->line2;
    all->station_line4.station=all->line4;
    //ѭ����վΪ1����2���ߵĽ��㣬����Ϊ��1�������Ƶأ���ɽ�㳡վ����Ϊ2������·վ����Ϊ3
    Initstation_j(&(all->line1[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line1[1]),80,100,"����·",11,0,0,0);
    Initstation_j(&(all->line1[2]),140,100,"���ñ�·",12,0.9,0,0);
    Initstation_j(&(all->line1[3]),200,100,"����·",13,1.8,0,0);
    Initstation_j(&(all->line1[4]),260,100,"ѭ����",10,2.8,1.5,0);
    /*
    closegraph();
    printf("%f\n",all->line1[4].distance.dx);
    printf("%f\n",all->line1[4].distance.dy);
    printf("%f\n",all->line1[4].distance.dz);
    getch();
    */
    Initstation_j(&(all->line1[5]),320,100,"����·",15,3.9,0,0);
    Initstation_j(&(all->line1[6]),380,100,"����·",16,6.6,0,0);
    Initstation_j(&(all->line1[7]),440,100,"����·",17,7.8,0,0);
    Initstation_j(&(all->line1[8]),500,100,"ͷ����",18,9.0,0,0);

    //all->line1[8].distance=0;//���һվ����Ĭ��Ϊ0

    Initstation_j(&(all->line2[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line2[1]),300,70,"��ɽ��԰",21,0,0,0);
    Initstation_j(&(all->line2[2]),260,100,"ѭ����",10,2.8,1.5,0);
    Initstation_j(&(all->line2[3]),260,156,"����·",23,0,4.1,0);
    Initstation_j(&(all->line2[4]),260,212,"������",24,0,7.5,0);
    Initstation_j(&(all->line2[5]),260,268,"�з�",25,0,9.1,0);//�޸�278->268
    Initstation_j(&(all->line2[6]),260,324,"С��ɽ",26,0,10.0,0);//�޸�334->224
    Initstation_j(&(all->line2[7]),260,380,"��ɽ�㳡",20,0,11.3,3.0);
    Initstation_j(&(all->line2[8]),200,380,"����·",30,0,12.2,2.1);
    Initstation_j(&(all->line2[9]),240,410,"��ͨ��",29,0,13.6,0);
    //all->line2[9].distance=0;

    Initstation_j(&(all->line4[0]),0,0,"0",00,0,0,0);
    Initstation_j(&(all->line4[1]),80,380,"�����վ",41,0,0,0);
    Initstation_j(&(all->line4[2]),140,380,"÷ԷС��",42,0,0,1.0);
    Initstation_j(&(all->line4[3]),200,380,"����·",30,0,12.2,2.1);
    Initstation_j(&(all->line4[4]),260,380,"��ɽ�㳡",20,0,11.3,3.0);
    Initstation_j(&(all->line4[5]),320,380,"���Ӻ���",45,0,0,4.1);
    Initstation_j(&(all->line4[6]),380,380,"������",46,0,0,5.5);
    Initstation_j(&(all->line4[7]),440,380,"��ͤ",47,0,0,6.4);
    Initstation_j(&(all->line4[8]),500,380,"������",48,0,0,7.4);
    
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
    
    puthz(61,110,"����·",16,16,LIGHTMAGENTA);
    puthz(108,75,"���ñ�·",16,16,LIGHTMAGENTA);
    puthz(176,110,"����·",16,16,LIGHTMAGENTA);
    puthz(210,75,"ѭ����",16,16,LIGHTMAGENTA);
    puthz(296,75,"����·",16,16,LIGHTMAGENTA);
    puthz(348,110,"����·",16,16,LIGHTMAGENTA);
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
    puthz(275,260,"�з�",16,16,LIGHTMAGENTA);
    puthz(275,316,"С��ɽ",16,16,LIGHTMAGENTA);

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
/**********************************************************
 Function:  cal_distance
 Description:  ������Ԫ�飬����
 Attention:  &(all->line1[0])������������ÿ������Ķ�����һ���ģ�
             ע��10 20 30 00���ױ��룬�������ֶ�ȡ���õ���
**********************************************************/
float cal_distance_j(all_lines_stations *all,int *start_name,int *end_name)//���������㷨
{
    station sta1,sta2;
    int line_of_sta1,line_of_sta2;
    int i,j;
    float x1,y1,z1;
    float x2,y2,z2;
    //float distance;

    for(i=1;i<=8;i++)//�ж��ǲ���1���ߵģ����Ҷ�xyz������ֵ
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
    for(i=1;i<=9;i++)//�ж��ǲ���2���ߵģ����Ҷ�xyz������ֵ
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
    for(i=1;i<=8;i++)//�ж��ǲ���3���ߵģ����Ҷ�xyz������ֵ
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

    //���ˣ���Ԫ�鸳ֵ��ϣ�������������������Ҫ���ǽڵ�
    //10��20��30Ϊ�ڵ㣬��Ҫ�����⿼��!
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
        if(line_of_sta2==1&&*end_name!=20&&*end_name!=30)//10��line1��
        {
            return fabs(2.8-x2);//��x
        }
        if(line_of_sta2==2||*end_name==20||*end_name==30)//10��line2��,������20��30
        {
            return fabs(1.5-y2);//��y
        }
        if(line_of_sta2==4)//10��4���ߵ�
        {
            return 9.8+fabs(z2-3);//�յ��Node2����+Node1��Node2����
        }
    }
    else if(*start_name==20)
    {
        if(line_of_sta2==1||*end_name==10&&*end_name!=30)
        {
            return fabs(2.8-x2)+9.8;//�յ���Node1����+Node1��Node2����
        }
        if(line_of_sta2==2||*end_name==30)
        {
            return fabs(11.3-y2);//��y
        }
        if(line_of_sta2==4)
        {
            return fabs(3.0-z2);//��z
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
            return fabs(2.8-x1)+9.8+0.9;//�յ��Node1����+Node1��Node2����+Node2��Node3����
        }
        if(line_of_sta2==2||*end_name==20)
        {
            return fabs(11.3-y2)+0.9;//�յ��Node2����+Node2��Node3����
        }
        if(line_of_sta2==4)
        {
            return fabs(3.0-z2);//��z
        }
        
    }
    else if(*end_name==10)
    {
        if(line_of_sta1==1&&*start_name!=20&&*start_name!=30)//10��line1��
        {
            return fabs(2.8-x1);//��x
        }
        if(line_of_sta1==2||*start_name==20||*start_name==30)//10��line2��,������20��30
        {
            return fabs(1.5-y1);//��y
        }
        if(line_of_sta1==4)//10��4���ߵ�
        {
            return 9.8+fabs(z1-3);//����Node2����+Node1��Node2����
        }
    }
    else if(*end_name==20)
    {
        if(line_of_sta1==1||*start_name==10&&*start_name!=30)
        {
            return fabs(2.8-x1)+9.8;//�����Node1����+Node1��Node2����
        }
        if(line_of_sta1==2||*start_name==30)
        {
            return fabs(11.3-y1);//��y
        }
        if(line_of_sta1==4)
        {
            return fabs(3.0-z1);//��z
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
            return fabs(2.8-x1)+9.8+0.9;//����Node1����+Node1��Node2����+Node2��Node3����
        }
        if(line_of_sta1==2||*start_name==20)
        {
            return fabs(11.3-y1)+0.9;//����Node2����+Node2��Node3����
        }
        if(line_of_sta1==4)
        {
            return fabs(3.0-z1);//��z
        }
    }
    else if(line_of_sta1==1&&line_of_sta2==1)
    {
        return fabs(x1-x2);//��x
    }
    else if(line_of_sta1==1&&line_of_sta2==2)
    {
        return fabs(2.8-x1)+fabs(1.5-y2);//��㵽Node1����+Node1���յ����
    }
    else if(line_of_sta1==1&&line_of_sta2==4)
    {
        return fabs(2.8-x1)+9.8+fabs(3.0-z2);//��㵽Node1����+Node1��Node2����+Node2���뵽�յ����
    }
    else if(line_of_sta1==2&&line_of_sta2==1)
    {
        return fabs(1.5-y1)+fabs(2.8-x2);//��㵽Node1����+Node1���յ����
    }
    else if(line_of_sta1==2&&line_of_sta2==2)
    {
        return fabs(y1-y2);//��y
    }
    else if(line_of_sta1==2&&line_of_sta2==4)
    {
        return fabs(11.3-y1)+fabs(3.0-z2);//��㵽Node2����+Node2���յ����
    }
    else if(line_of_sta1==4&&line_of_sta2==1)
    {
        return fabs(3.0-z1)+9.8+fabs(2.8-x2);//��㵽Node2����+Node2��Node1����+Node1���յ����
    }
    else if(line_of_sta1==4&&line_of_sta2==2)
    {
        return fabs(3.0-z1)+fabs(11.3-y2);//��㵽Node2����+Node2���յ����
    }
    else if(line_of_sta1==4&&line_of_sta2==4)
    {
        return fabs(z1-z2);//��z
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
	n=(int)((((num)-(int)num)*10)+0.5);//5.1��ô�����5.0?
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
    puthz(30,130,"��㣺",16,16,RED);
    puthz(80,130,sta->station_name,16,16,RED);
    setcolor(RED);
    circle(x,y,5);
    circle(x,y,4);
    *sta_checkclick=1;
    *start_station=sta->simple_name;//�����״���
    *flag=1;
    
}

void Draw_end_sta_j(all_lines_stations *all,int x,int y,station sta,int *sta_checkclick,int *start_station,int *end_station,int *flag,int *price)
{
    float distance=0;
    char price_string[2];//��ż۸���ַ�����ʽ������
    char distance_string1[3];//��ž�����������ֵ��ַ�����ʽ������
    char distance_string2[2];//С������
    //eg��16.7����str1={1��6��'\0'}��str2={7,'\0'}��
    //����յ���ͬ����ʲôҲ����
    *end_station=sta.simple_name;
    if(*start_station!=*end_station)
    {
        puthz(30,160,"�յ㣺",16,16,RED);
        puthz(80,160,sta.station_name,16,16,RED);
        setcolor(RED);
        circle(x,y,5);
        circle(x,y,4);
        /*
        closegraph();
        printf("%d  %d\n",x,y);
        printf("%d  %d\n",sta.distance.dx,sta.distance.dx);
        printf("\n%s",sta.station_name);
        getch();//����һ������
        */
        *sta_checkclick=1;//������վҲ�����
        distance=cal_distance_j(all,start_station,end_station);
        *price=cal_price_j(distance);
        itoa(*price,price_string,10);//���۸���ת�����ַ������������
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
        puthz(30,190,"���룺",16,16,RED);
        outtextxy(80,190,distance_string1);//�������
        outtextxy(105,190,".");
        outtextxy(115,190,distance_string2);
        outtextxy(130,190,"km");
        puthz(30,220,"Ʊ�ۣ�",16,16,RED);
        outtextxy(80,220,price_string);//���Ʊ��
        puthz(95,220,"Ԫ",16,16,RED);
        *flag=2;
    }
    
}
/*
int judge_sta_checkclick_j(int** sta_checkclick)//��־���鶼��0������1��������û�����
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
