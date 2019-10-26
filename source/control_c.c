#include"control_c.h"
#include"common_c.h"
#define LINENUM 3  //线路条数
#define INITCARNUM 2 //初始车辆
/**********************************************************
Function:  drawDot
Description：	画地铁点
Attention:  无
**********************************************************/
void drawDot(setTrain *dot,int color)
{
	setcolor(color);
	setfillstyle(1, color);
	bar((int)dot->x-2,(int)dot->y-2,(int)dot->x+2,(int)dot->y+2);
}
/**********************************************************
Function:  hideDot
Description：	隐藏地铁点并显现背景
Attention:  无
**********************************************************/
void hideDot(setTrain *dot)
{
	int i, j;
	for (i = 0;i<6;i++)
	{
		for (j = 0;j<6;j++)
		{
			putpixel((int)dot->x -3 + i, (int)dot->y -3 + j, dot->setDotSave[i][j]);
		}
	}
}
/**********************************************************
Function:  readDotbk
Description：	读取地铁点背景
Attention:  无
**********************************************************/
void readDotbk(setTrain *dot)
{
	int i, j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			dot->setDotSave[i][j] = getpixel(dot->x -3 + i, dot->y -3 + j);
		}
	}
}
/**********************************************************
Function:  initTranInfo
Description：	相关结构体的初始化
Attention:  无
**********************************************************/
void initTranInfo(setTrainInfo *Info,all_lines_stations *all)
{
	int i,j;
	setTrain *temp;
	Info[0].lineHead=&(all->station_line1);
	Info[1].lineHead=&(all->station_line2);
	Info[2].lineHead=&(all->station_line4);
	for(i=0;i<LINENUM;i++)
	{
		Info[i].num=INITCARNUM;//默认两辆车
		//初始化第一辆车
		Info[i].trainHead=(setTrain*)malloc(sizeof(setTrain));
		if(Info[i].trainHead==NULL)
		{
			closegraph();
			printf("\nout of memory");
			exit(1);
		}
		Info[i].trainHead->next=NULL;
		Info[i].trainHead->k=0;
		Info[i].trainHead->i=0;
		Info[i].trainHead->x=0.0;
		Info[i].trainHead->y=0.0;
		Info[i].trainHead->count=0;
		Info[i].trainHead->reverse=0;
		Info[i].trainHead->setDotSave[0][0]=-100;
		//初始化其它车
		for(temp=Info[i].trainHead,j=1;j<INITCARNUM;j++)
		{
			temp->next=(setTrain*)malloc(sizeof(setTrain));
			temp=temp->next;
			if(temp==NULL)
			{
				closegraph();
				printf("\nout of memory");
				exit(1);
			}
			temp->next=NULL;
			temp->i=0;
			temp->x=0.0;
			temp->y=0.0;
			temp->count=0;
			temp->setDotSave[0][0]=-100;
			if(j<INITCARNUM/2)//前一半车正向开
			{
				temp->reverse=0;
				temp->k=0;
			}
			else//后一半车反向开
			{
				temp->reverse=1;
				if(i==1)
					temp->k=8;
				else
					temp->k=7;
				
			}
			
		}
	}
}
/**********************************************************
Function:  otherEvent
Description：	其它事件，如鼠标的更新和点击事件等
Attention:  无
**********************************************************/
int otherEvent(int *mx,int *my,int *buttons)
{
    newxy(mx, my, buttons);
	if(*buttons)//点击事件
	{
		if (*mx >= 550 && *mx <= 610 && *my >= 210&& *my <= 270)//退出按钮点击退出
		{
			return 0;
		}
	}
	return 1;
}
/**********************************************************
Function:  changePlace
Description：	地铁前进动画
Attention:  无
**********************************************************/
void changePlace(setTrain *dot,station *line,int speed,int length,int wait,int linenum)//linenum表示第几条线
{
	float xnew,ynew;
	int i;
	float distance;
	// closegraph();
	// 			printf("%d\n",line[8].x);
	// 			printf("%d\n",line[9].x);
	// 			printf("%d\n",line[8].y);
	// 			printf("%d\n",line[9].y);
	// 			getch();
	if(dot->count==0)//车不在站台
	{
		if(dot->reverse==0)//车正向行驶
		{
			//计算两站间距
			if(linenum==1)//一号线
			{
				distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
			}
			else if(linenum==2)//二号线
			{
				distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
			}
			else if(linenum==4)//四号线
			{
				distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
			}
			distance=distance*100;
			xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
			ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i);
			if(dot->setDotSave[0][0]!=-100)//判断是不是第一次加载
			{
				hideDot(dot);
			}
			dot->x=xnew;
			dot->y=ynew;
			readDotbk(dot);
			//正向车用蓝色
			setcolor(BLUE);
			setfillstyle(1, BLUE);
			drawDot(dot,BLUE);
			//位移量进1
			dot->i++;
			if(dot->i==(int)(distance/speed))//车如果到站
			{
				dot->i=0;
				dot->k++;
				dot->count=wait;
			}
			if(dot->k==length-1)//车到了终点站
			{
				dot->reverse=1;
				//清除两车向蹭之后的噪点
				if(linenum==1)//一号线
				{
					Drawstation1_j();
					DrawCircles_j();
				}
				else if(linenum==2)//二号线
				{
					Drawstation2_j();
					DrawCircles_j();
				}
				else if(linenum==4)//四号线
				{
					Drawstation4_j();
					DrawCircles_j();
				}
			}
			delay(5);
		}
		else//车逆向行驶
		{
			if(linenum==1)//一号线
			{
				distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
			}
			else if(linenum==2)//二号线
			{
				distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
			}
			else if(linenum==4)//四号线
			{
				distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
			}
			distance=distance*100;
			xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
			ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
			if(dot->setDotSave[0][0]!=-100)//判断是不是第一次加载
			{
				hideDot(dot);
			}
			dot->x=xnew;
			dot->y=ynew;
			readDotbk(dot);
			//逆向车用蓝色
			setcolor(RED);
			setfillstyle(1, RED);
			drawDot(dot,RED);
			//位移量进1
			dot->i++;
			if(dot->i==(int)distance/speed)//车如果到站
			{
				dot->i=0;
				dot->k--;
				dot->count=wait;
				
			}
			if(dot->k==0)//车到了始发站
			{
				dot->reverse=0;
				//清除两车向蹭之后的噪点
				if(linenum==1)//一号线
				{
					Drawstation1_j();
					DrawCircles_j();
				}
				else if(linenum==2)//二号线
				{
					Drawstation2_j();
					DrawCircles_j();
				}
				else if(linenum==4)//四号线
				{
					Drawstation4_j();
					DrawCircles_j();
				}
			}
			delay(5);
		}
		
	}
	else//车在站台
	{
		dot->count--;
		delay(5);
	}
	
}
/**********************************************************
Function:  drawControlScreen
Description：	画调度页面，实现动画
Attention:  无
**********************************************************/
void drawControlScreen(setuser *person,int *judge,setuser *head,all_lines_stations *all)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
	int i;//划线循环变量
    setTrainInfo Info[3];//记录三条线调度的相关参数
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	initTranInfo(Info,all);


	// closegraph();
	// printf("\n%f\n%f",Info[2].lineHead->station[0].distance.dz,Info[2].lineHead->station[1].distance.dz);
	// printf("\n%f\n%f",Info[2].lineHead->station[2].distance.dz,Info[2].lineHead->station[3].distance.dz);
	// printf("\n%f\n%f",Info[2].lineHead->station[4].distance.dz,Info[2].lineHead->station[5].distance.dz);
	// printf("\n%f\n%f",Info[1].lineHead->station[9].distance.dx,Info[1].lineHead->station[9].distance.dy);
	// printf("\n%d\n%d",Info[1].lineHead->station[8].x,Info[1].lineHead->station[9].x);
	// printf("\n%d\n%d",Info[1].lineHead->station[8].y,Info[1].lineHead->station[9].y);
	// printf("\n%d\n%d",Info[1].lineHead->station[9].x,all->line2[9].x);
	// printf("\n%f\n%f",Info[1].lineHead->station[6].distance.dy,Info[1].lineHead->station[7].distance.dy);
	// printf("\n%f\n%f",Info[1].lineHead->station[8].distance.dy,Info[1].lineHead->station[9].distance.dy);
	// getch() ;

	//绘制界面
	//绘制返回按钮
	returnBtn_c(550,210,GREEN);
	//绘制地铁线路
	line(460,0,460,75);
    line(460,75,640,75);

    setlinestyle(0,0,3);
    setcolor(LIGHTCYAN);
    line(500,10,550,10);
    outtextxy(560,0,"1");
    puthz(570,5,"号线",16,16,LIGHTBLUE);
    setcolor(LIGHTGREEN);
    line(500,30,550,30);
    outtextxy(560,20,"2");
    puthz(570,25,"号线",16,16,LIGHTGREEN);
    setcolor(YELLOW);
    line(500,50,550,50);
    outtextxy(560,40,"4");
    puthz(570,45,"号线",16,16,YELLOW);
    puthz(180,0,"地铁调度一览",32,32,BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();



	
	while(1)
	{
		// changePlace(&Info[0].lineHead[0],Info[0].lineHead->station,1,8,200);
		//一号线
		changePlace(Info[0].trainHead,Info[0].lineHead->station,2,8,20,1);
		changePlace(Info[0].trainHead->next,Info[0].lineHead->station,1,8,20,1);
		//二号线
		changePlace(Info[1].trainHead,Info[1].lineHead->station,2,9,20,2);
		changePlace(Info[1].trainHead->next,Info[1].lineHead->station,2,9,20,2);
		//四号线
		changePlace(Info[2].trainHead,Info[2].lineHead->station,2,8,20,4);
		changePlace(Info[2].trainHead->next,Info[2].lineHead->station,2,8,20,4);
		if(otherEvent(&mx,&my,&buttons)==0)
		{
			*judge=turnTo_c(person,2);
			return;
		}
	}
}