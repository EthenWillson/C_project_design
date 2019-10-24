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
	bar(dot->x-2,dot->y-2,dot->x+2,dot->y+2);
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
			putpixel(dot->x -3 + i, dot->y -3 + j, dot->setDotSave[i][j]);
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
			temp->k=0;
			temp->i=0;
			temp->x=0.0;
			temp->y=0.0;
			temp->count=0;
			temp->setDotSave[0][0]=-100;
			if(j<INITCARNUM/2)//前一半车正向开
			{
				temp->reverse=0;
			}
			else//后一半车反向开
			{
				temp->reverse=1;
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
void changePlace(setTrain *dot,station *line,int speed,int length,int wait)
{
	float xnew,ynew;
	int i;
	if(dot->count==0)//车不在站台
	{
		if(dot->reverse==0)//车正向行驶
		{
			xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/(line[dot->k+1].distance)*speed*(dot->i);
			ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/(line[dot->k+1].distance)*speed*(dot->i);
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
			if(dot->i==(line[dot->k+1].distance)/speed)//车如果到站
			{
				dot->i=0;
				dot->k++;
				dot->count=wait;
			}
			if(dot->k==length-1)//车到了终点站
			{
				dot->reverse=1;
			}
			delay(20);
		}
		else//车逆向行驶
		{
			xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/(line[dot->k].distance)*speed*(dot->i);
			ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/(line[dot->k].distance)*speed*(dot->i);
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
			if(dot->i==(line[dot->k].distance)/speed)//车如果到站
			{
				dot->i=0;
				dot->k--;
				dot->count=wait;
			}
			if(dot->k==0)//车到了始发站
			{
				dot->reverse=0;
			}
			delay(20);
		}
		
	}
	else//车在站台
	{
		dot->count--;
		delay(20);
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
	// printf("\n%d\n%d",Info[0].trainHead->k,Info[0].trainHead->i);
	// printf("\n%d\n%d",Info[1].trainHead->k,Info[1].trainHead->i);
	// printf("\n%d\n%d",Info[2].trainHead->k,Info[2].trainHead->i);
	// printf("\n%d\n%d",Info[0].trainHead->next->k,Info[0].trainHead->next->i);
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
    outtextxy(560,40,"3");
    puthz(570,45,"号线",16,16,YELLOW);
    puthz(180,0,"地铁调度一览",32,32,BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();

	// closegraph();
	// printf("\n%d",Info[0].trainHead->reverse);
	// printf("\n%d",Info[1].trainHead->reverse);
	// printf("\n%d",Info[2].trainHead->reverse);
	// printf("\n%d",Info[0].trainHead->next->reverse);
	// printf("\n%d",Info[1].trainHead->next->reverse);
	// printf("\n%d",Info[2].trainHead->next->reverse);
	// getch();

	// closegraph();
	// printf("\n%d",Info[0].trainHead->k);
	// printf("\n%f\n%f",line[dot->k+1].x,line[dot->k+2].x);
	// printf("\n%f\n%f",line[dot->k+1].x,((float)((line[dot->k+1].x)-(line[dot->k+2].x))));
	// printf("\n%f\n%f",xnew,ynew);
	// getch() ;



	
	while(1)
	{
		// changePlace(&Info[0].lineHead[0],Info[0].lineHead->station,1,8,200);
		//一号线
		changePlace(Info[0].trainHead,Info[0].lineHead->station,1,8,200);
		//二号线
		changePlace(Info[1].trainHead,Info[1].lineHead->station,1,8,200);
		//四号线
		changePlace(Info[2].trainHead,Info[2].lineHead->station,1,8,200);
		if(otherEvent(&mx,&my,&buttons)==0)
		{
			*judge=turnTo_c(person,2);
			return;
		}
	}
}