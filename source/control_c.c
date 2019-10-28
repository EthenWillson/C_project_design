#include"control_c.h"
#include"common_c.h"
#define LINENUM 3  //线路条数
#define INITCARNUM 2 //初始车辆
/**********************************************************
Function:  drawControlFrame
Description：	绘制控制框
Attention:  无
**********************************************************/
void drawControlFrame(int x,int y)
{
	puthz(0+x, 0+y, "列车速度：", 16, 16, LIGHTCYAN);
	puthz(0+x, 40+y, "停站时间：", 16, 16, LIGHTCYAN);
	puthz(0+x, 80+y, "发车间隔：", 16, 16, LIGHTCYAN);
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	//速度
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	pieslice(x+85,y+8,0,360,7);
	pieslice(x+180,y+8,0,360,7);
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	bar(x+79,y+7,x+91,y+9);
	bar(x+174,y+7,x+186,y+9);
	bar(x+84,y+2,x+86,y+14);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(x+124,y-5,"1");
	//等待
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	pieslice(x+85,y+48,0,360,7);
	pieslice(x+180,y+48,0,360,7);
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	bar(x+79,y+47,x+91,y+49);
	bar(x+174,y+47,x+186,y+49);
	bar(x+84,y+42,x+86,y+54);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(x+124,y+35,"10");
	//发车
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	pieslice(x+85,y+88,0,360,7);
	pieslice(x+180,y+88,0,360,7);
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	bar(x+79,y+87,x+91,y+89);
	bar(x+174,y+87,x+186,y+89);
	bar(x+84,y+82,x+86,y+94);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(x+124,y+75,"20");
}
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
	Info[0].stationNum=8;
	Info[1].stationNum=9;
	Info[2].stationNum=8;
	for(i=0;i<3;i++)
	{
		Info[i].num=0;
		Info[i].wait=10;//停站时间
		Info[i].speed=1;//速度
		Info[i].goTime=20;//发车
		Info[i].trainHead=NULL;//正向车链表
		Info[i].rtrainHead=NULL;//逆向车链表
	}
}
// void initTranInfo(setTrainInfo *Info,all_lines_stations *all)
// {
// 	int i,j;
// 	setTrain *temp;
// 	Info[0].lineHead=&(all->station_line1);
// 	Info[1].lineHead=&(all->station_line2);
// 	Info[2].lineHead=&(all->station_line4);
// 	for(i=0;i<LINENUM;i++)
// 	{
// 		Info[i].num=INITCARNUM;//默认两辆车
// 		Info[i].wait=10;//停站时间
// 		Info[i].speed=1;//速度
// 		Info[i].goTime=20;//发车
// 		//初始化第一辆车
// 		Info[i].trainHead=(setTrain*)malloc(sizeof(setTrain));
// 		if(Info[i].trainHead==NULL)
// 		{
// 			closegraph();
// 			printf("\nout of memory");
// 			exit(1);
// 		}
// 		Info[i].trainHead->next=NULL;
// 		Info[i].trainHead->k=0;
// 		Info[i].trainHead->i=0;
// 		Info[i].trainHead->x=0.0;
// 		Info[i].trainHead->y=0.0;
// 		Info[i].trainHead->count=1;
// 		Info[i].trainHead->reverse=0;
// 		Info[i].trainHead->setDotSave[0][0]=-100;
// 		Info[i].trainHead->distance[0]=0.0;//记录要经过多少个单位位移
// 		Info[i].trainHead->distance[1]=0.0;
// 		//初始化其它车
// 		for(temp=Info[i].trainHead,j=1;j<INITCARNUM;j++)
// 		{
// 			temp->next=(setTrain*)malloc(sizeof(setTrain));
// 			temp=temp->next;
// 			if(temp==NULL)
// 			{
// 				closegraph();
// 				printf("\nout of memory");
// 				exit(1);
// 			}
// 			temp->next=NULL;
// 			temp->i=0;
// 			temp->x=0.0;
// 			temp->y=0.0;
// 			temp->count=1;
// 			temp->setDotSave[0][0]=-100;
// 			temp->distance[0]=0.0;
// 			temp->distance[1]=0.0;
// 			if(j<INITCARNUM/2)//前一半车正向开
// 			{
// 				temp->reverse=0;
// 				temp->k=0;
// 			}
// 			else//后一半车反向开
// 			{
// 				temp->reverse=1;
// 				if(i==1)
// 					temp->k=8;
// 				else
// 					temp->k=7;
				
// 			}
			
// 		}
// 	}
// }
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
		if (*mx >= 10 && *mx <= 70 && *my >= 210&& *my <= 270)//退出按钮点击退出
		{
			return 0;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 0&& *my <= 25)//点击一号线切换点
		{
			return 1;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 25&& *my <= 45)//点击二号线切换点
		{
			return 2;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 45&& *my <= 70)//点击四号线切换点
		{
			return 3;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 191&& *my <= 205)//点击速度+号
		{
			return 4;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 191&& *my <= 205)//点击速度-号
		{
			return 5;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 231&& *my <= 245)//点击停站+号
		{
			return 6;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 231&& *my <= 245)//点击停站-号
		{
			return 7;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 271&& *my <= 285)//点击发车+号
		{
			return 8;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 271&& *my <= 285)//点击发车-号
		{
			return 9;
		}
	}
	return -1;
}
/**********************************************************
Function:  judgeCrash
Description：	监测地铁“碰撞”事件
Input:  Info 一条线相关参数
Attention:  无
**********************************************************/
// void judgeCrash(setTrainInfo Info)
// {

// }
/**********************************************************
Function:  debugElf
Description：	debug精灵
Attention:  无
**********************************************************/
void debugElf(int x,int y,int bkcolor,int ccolor,int a,int b,int c)
{
	char ac[10],bc[10],cc[10];
	itoa(a,ac,10);
	itoa(b,bc,10);
	itoa(c,cc,10);
	setcolor(bkcolor);
	setfillstyle(1,bkcolor);
	bar(x,y,x+200,y+130);
	setcolor(ccolor);
	outtextxy(x+2,y+2,ac);
	outtextxy(x+2,y+32,bc);
	outtextxy(x+2,y+62,cc);
}
/**********************************************************
Function:  deleteTrain
Description：	删除地铁
Attention:  无
**********************************************************/
void deleteTrain(setTrain *before,setTrain *current)
{
	before->next=current->next;
	free(current);
}
/**********************************************************
Function:  createTrain
Description：	生成地铁
Attention:  reverse为0正向，reverse为1反向
**********************************************************/
void createTrain(setTrainInfo *Info,int reverse)
{
	setTrain *T,*Tb;
	if(reverse==0)
	{
		for(T=Info->trainHead,Tb=Info->trainHead;T!=NULL;T=T->next)
		{
			Tb=T;
		}
		T=(setTrain*)malloc(sizeof(setTrain));
		if(Tb==NULL)
		{
			Info->trainHead=T;
		}
		else
		{
			Tb->next=T;
		}
		
		//初始化
		
		T->count=1;
		T->setDotSave[0][0]=-100;
		T->next=NULL;
		T->i=0;
		T->x=Info->lineHead->station[1].x;
		T->y=Info->lineHead->station[1].y;
		T->reverse=0;
		T->k=1;
		T->Ti=0;
	}
	// closegraph();
	// printf("%d\n%d\n%d\n",Info->trainHead->count,Info->speed,Info->stationNum);
	// printf("%d\n%d\n%d\n",Info->trainHead->count,Info->speed,Info->stationNum);
	// getch();
}
/**********************************************************
Function:  changeDot
Description：	地铁前进动画
Attention:  无
**********************************************************/
void changeDot(setTrainInfo *Info)
{
	//局部变量
	int i,j;
	setTrain *fT,*fTb,*rT,*rTb;//fT正向，rT逆向
	station *line=Info->lineHead->station;
	float xnew,ynew,distance;
	int speed=Info->speed,wait=Info->wait,goTime=Info->goTime;
	//初始化
	fT=Info->trainHead;
	rT=Info->rtrainHead;

	for(fT=Info->trainHead,fTb=Info->trainHead;fT!=NULL;fTb=fT,fT=fT->next)
	{
		if(fT->count==0)//车不在站台
		{
			if(fT->setDotSave[0][0]!=-100)//判断是不是第一次加载
			{
				hideDot(fT);
			}
			// xnew=(fT->x)+fT->distance[0]*speed;
			// ynew=(fT->y)+fT->distance[1]*speed;
			fT->i+=speed;//加上speed
			xnew=(line[fT->k].x)+((float)((line[fT->k+1].x)-(line[fT->k].x)))/(fT->Ti)*(fT->i);
			ynew=(line[fT->k].y)+((float)((line[fT->k+1].y)-(line[fT->k].y)))/(fT->Ti)*(fT->i);
			if(Info->lineHead->number==1)//一号线
			{
				// distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
				// distance=distance*100;
				fT->x=xnew;
				fT->y=ynew-3;
			}
			else if(Info->lineHead->number==2)//二号线
			{
				// distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
				fT->x=xnew-3;
				fT->y=ynew;
			}
			else if(Info->lineHead->number==4)//四号线
			{
				// distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
				fT->x=xnew;
				fT->y=ynew-3;
			}
			// xnew=fT->x+(fT->distance[0])*speed;
			// ynew=fT->y+(fT->distance[1])*speed;
			// dot->x=xnew;
			// dot->y=ynew;
			readDotbk(fT);
			//正向车用蓝色
			setcolor(BLUE);
			setfillstyle(1, BLUE);
			drawDot(fT,BLUE);
			if(fT->Ti<=fT->i)//到站
			{
				if(fT->k!=Info->stationNum+1)//非终点站
				{
					fT->i=0;
					fT->k++;
					fT->count=Info->wait;
				}
				else//终点站
				{
					deleteTrain(fTb,fT);
					fT=fTb;
				}
				
			}
			delay(5);
		}
		else//车在站台
		{
			if(fT->count==1)//准备开车时
			{
				if(Info->lineHead->number==1)//一号线
				{
					distance=(line[fT->k+1].distance.dx)-(line[fT->k].distance.dx);
				}
				else if(Info->lineHead->number==2)//二号线
				{
					distance=(line[fT->k+1].distance.dy)-(line[fT->k].distance.dy);
				}
				else if(Info->lineHead->number==4)//四号线
				{
					distance=(line[fT->k+1].distance.dz)-(line[fT->k].distance.dz);
				}
				distance=distance*500;
				fT->Ti=(int)(distance);
			}
			fT->count--;
			delay(5);
		}
		
		
	}
}

/**********************************************************
Function:  changePlace
Description：	地铁前进动画
Attention:  无
**********************************************************/
// void changePlace(setTrain *dot,station *line,int speed,int length,int wait,int linenum)//linenum表示第几条线
// {
// 	float xnew,ynew;
// 	int i;
// 	float distance;
// 	// closegraph();
// 	// 			printf("%d\n",line[8].x);
// 	// 			printf("%d\n",line[9].x);
// 	// 			printf("%d\n",line[8].y);
// 	// 			printf("%d\n",line[9].y);
// 	// 			getch();
// 	if(dot->count==0)//车不在站台
// 	{
// 		if(dot->reverse==0)//车正向行驶
// 		{
// 			//计算两站间距
// 			if(linenum==1)//一号线
// 			{
// 				// distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
// 				// distance=distance*100;
// 				xnew=(dot->x)+dot->distance[0]*speed;
// 				ynew=(dot->y)+dot->distance[1]*speed-3;
// 				// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
// 				// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i)-3;
// 			}
// 			else if(linenum==2)//二号线
// 			{
// 				// distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
// 				// distance=distance*100;
// 				xnew=(dot->x)+dot->distance[0]*speed-3;
// 				ynew=(dot->y)+dot->distance[1]*speed;
// 				// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i)-3;
// 				// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i);
// 			}
// 			else if(linenum==4)//四号线
// 			{
// 				// distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
// 				// distance=distance*100;
// 				xnew=(dot->x)+dot->distance[0]*speed;
// 				ynew=(dot->y)+dot->distance[1]*speed-3;
// 				// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
// 				// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i)-3;
// 			}
// 			// distance=distance*100;
// 			// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
// 			// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i);
// 			if(dot->setDotSave[0][0]!=-100)//判断是不是第一次加载
// 			{
// 				hideDot(dot);
// 			}
// 			dot->x=xnew;
// 			dot->y=ynew;
// 			readDotbk(dot);
// 			//正向车用蓝色
// 			setcolor(BLUE);
// 			setfillstyle(1, BLUE);
// 			drawDot(dot,BLUE);
// 			//位移量进1
// 			dot->i++;
// 			// if(dot->i==(int)(distance/speed))//车如果到站
// 			// {
// 			// 	dot->i=0;
// 			// 	dot->k++;
// 			// 	dot->count=wait;
// 			// }
// 			if((int)dot->x>(int)line[dot->k+2].x && (int)dot->y>(int)line[dot->k+2].y)//车如果到站
// 			{
// 				dot->i=0;
// 				dot->k--;
// 				dot->count=wait;
// 			}
// 			// if(dot->k==length-1)//车到了终点站
// 			// {
// 				// dot->reverse=1;
// 				//清除两车向蹭之后的噪点
// 				// if(linenum==1)//一号线
// 				// {
// 				// 	Drawstation1_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==2)//二号线
// 				// {
// 				// 	Drawstation2_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==4)//四号线
// 				// {
// 				// 	Drawstation4_j();
// 				// 	DrawCircles_j();
// 				// }
// 			// }
// 			delay(5);
// 		}
// 		else//车逆向行驶
// 		{
// 			if(linenum==1)//一号线
// 			{
// 				distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 			}
// 			else if(linenum==2)//二号线
// 			{
// 				distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i)+3;
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 			}
// 			else if(linenum==4)//四号线
// 			{
// 				distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 			}
// 			// distance=distance*100;
// 			// xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 			// ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 			if(dot->setDotSave[0][0]!=-100)//判断是不是第一次加载
// 			{
// 				hideDot(dot);
// 			}
// 			dot->x=xnew;
// 			dot->y=ynew;
// 			readDotbk(dot);
// 			//逆向车用蓝色
// 			setcolor(RED);
// 			setfillstyle(1, RED);
// 			drawDot(dot,RED);
// 			//位移量进1
// 			dot->i++;
// 			// if(dot->i==(int)distance/speed)//车如果到站
// 			// {
// 			// 	dot->i=0;
// 			// 	dot->k--;
// 			// 	dot->count=wait;
				
// 			// }
// 			if(dot->x==line[dot->k].x && dot->y==line[dot->k].y)//车如果到站
// 			{
// 				dot->i=0;
// 				dot->k--;
// 				dot->count=wait;
				
// 			}
// 			if(dot->k==0)//车到了始发站
// 			{
// 				dot->reverse=0;
// 				//清除两车向蹭之后的噪点
// 				// if(linenum==1)//一号线
// 				// {
// 				// 	Drawstation1_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==2)//二号线
// 				// {
// 				// 	Drawstation2_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==4)//四号线
// 				// {
// 				// 	Drawstation4_j();
// 				// 	DrawCircles_j();
// 				// }
// 			}
// 			delay(5);
// 		}
		
// 	}
// 	else//车在站台
// 	{
		
// 		if(dot->count==1)
// 		{
// 			if(dot->reverse==0)//正向
// 			{
// 				if(linenum==1)//一号线
// 				{
// 					distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==2)//二号线
// 				{
// 					distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==4)//四号线
// 				{
// 					distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				distance=distance*100;
// 				dot->distance[0]=(((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance);
// 				dot->distance[1]=(((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance);
// 			}
// 			else if(dot->reverse==1)//反向
// 			{
// 				if(linenum==1)//一号线
// 				{
// 					distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==2)//二号线
// 				{
// 					distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==4)//四号线
// 				{
// 					distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				distance=distance*100;
// 				dot->distance[0]=(((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance);
// 				dot->distance[1]=(((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance);
// 			}
// 		}
// 		// if(linenum==1)//一号线
// 		// 	{
// 		// 		distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 		// 		distance=distance*100;
// 		// 		xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 		// 		ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 		// 	}
// 		// 	else if(linenum==2)//二号线
// 		// 	{
// 		// 		distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 		// 		distance=distance*100;
// 		// 		xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i)+3;
// 		// 		ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 		// 	}
// 		// 	else if(linenum==4)//四号线
// 		// 	{
// 		// 		distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
// 		// 		distance=distance*100;
// 		// 		xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 		// 		ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 		// 	}
// 		dot->count--;
// 		delay(5);
// 	}
	
// }
/**********************************************************
Function:  changeValue
Description：	数值变动函数
Attention:  无
**********************************************************/
void changeValue(int *para)
{
	char temp[4];
	//涂掉原先的数
	setcolor(DARKGRAY);
	// setfillstyle(1,DARKGRAY);
	// bar(515,180,572,210);
	setfillstyle(1,DARKGRAY);
	bar(515,180,572,390);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	itoa(para[0],temp,10);
	outtextxy(534,185,temp);
	itoa(para[1],temp,10);
	outtextxy(534,225,temp);
	itoa(para[2],temp,10);
	outtextxy(534,265,temp);
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
	int currentNum=0;//当前调度线路
	int para[3]={1,10,10};//当前参数存储  0：速度  1：停站时间  2：发车间隔 
    setTrainInfo Info[3];//记录三条线调度的相关参数
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(DARKGRAY);
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
	returnBtn_c(15,210,LIGHTBLUE);
	//绘制基本界面
	setcolor(GREEN);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	line(460,0,460,75);
    line(460,75,640,75);
    setlinestyle(0,0,3);
    setcolor(LIGHTCYAN);
    line(500,10,550,10);
    outtextxy(560,5,"1");
    puthz(570,5,"号线",16,16,CYAN);
    setcolor(LIGHTGREEN);
    line(500,30,550,30);
    outtextxy(560,25,"2");
    puthz(570,25,"号线",16,16,LIGHTGREEN);
    setcolor(YELLOW);
    line(500,50,550,50);
    outtextxy(560,45,"4");
    puthz(570,45,"号线",16,16,YELLOW);
    puthz(180,0,"地铁调度一览",32,32,BROWN);
	//绘制地铁线路
    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();
	//调度相关绘制
	//选取地铁线圆
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(620,12,0,360,6);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(620,12,0,360,2);
	//调整模块
	//等待时间调整模块
	drawControlFrame(410,190);

	createTrain(&Info[0],0);
	while(1)
	{
		//debug
		// debugElf(15,160,WHITE,LIGHTBLUE,int a,int b,int c);
		// changePlace(&Info[0].lineHead[0],Info[0].lineHead->station,1,8,200);
		//一号线
		
		// debugElf(15,160,WHITE,LIGHTBLUE,Info->trainHead->count,Info->speed,Info->stationNum);
		// closegraph();
		// printf("%d\n%d\n%d\n",Info->trainHead->count,Info->speed,Info->stationNum);
		// getch();
		changeDot(&Info[0]);
		
		// changePlace(Info[0].trainHead,Info[0].lineHead->station,Info[0].speed,8,Info[0].wait,1);
		// changePlace(Info[0].trainHead->next,Info[0].lineHead->station,Info[0].speed,8,Info[0].wait,1);
		//二号线
		// changePlace(Info[1].trainHead,Info[1].lineHead->station,Info[1].speed,9,Info[1].wait,2);
		// changePlace(Info[1].trainHead->next,Info[1].lineHead->station,Info[1].speed,9,Info[1].wait,2);
		//四号线
		// changePlace(Info[2].trainHead,Info[2].lineHead->station,Info[2].speed,8,Info[1].wait,4);
		// changePlace(Info[2].trainHead->next,Info[2].lineHead->station,Info[2].speed,8,Info[1].wait,4);
		switch(otherEvent(&mx,&my,&buttons))
		{
			case 0:
				*judge=turnTo_c(person,2);
				return;
			//点击一号线切换点
			case 1:
				mousehide(mx,my);
				//涂掉原先的点
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//绘制点
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,12,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,12,0,360,2);
				//控制
				currentNum=0;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//点击二号线切换点
			case 2:
				mousehide(mx,my);
				//涂掉原先的点
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//绘制点
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,32,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,32,0,360,2);
				//控制
				currentNum=1;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//点击四号线切换点
			case 3:
				mousehide(mx,my);
				//涂掉原先的点
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//绘制点
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,52,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,52,0,360,2);
				//控制
				currentNum=2;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//点击速度+
			case 4:
				//涂掉原先的数
				para[0]++;
				Info[currentNum].speed=para[0];
				changeValue(para);
				break;
			//点击速度+
			case 5:
				//涂掉原先的数
				para[0]--;
				Info[currentNum].speed=para[0];
				changeValue(para);
				break;
			//点击停站+
			case 6:
				//涂掉原先的数
				para[1]++;
				Info[currentNum].wait=para[1];
				changeValue(para);
				break;
			//点击停站-
			case 7:
				//涂掉原先的数
				para[1]--;
				Info[currentNum].wait=para[1];
				changeValue(para);
				break;
			//点击发车+
			case 8:
				//涂掉原先的数
				para[2]++;
				Info[currentNum].goTime=para[2];
				changeValue(para);
				break;
			//点击发车-
			case 9:
				//涂掉原先的数
				para[2]--;
				Info[currentNum].goTime=para[2];
				changeValue(para);
				break;
		}
	}
}