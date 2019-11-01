/**********************************************************
此文件专门存放调度界面及算法相关的函数
作者：陈俊玮
**********************************************************/
#include"control_c.h"
#include"common_c.h"
#define LINENUM 3  //线路条数
#define INITCARNUM 2 //初始车辆
#define TIMEUNIT 10 //时间单位
#define DISTANCEUNIT 300 //距离单位
#define DAULTSPEED 2
#define DAULTWAIT 10
#define DAULTGOTIME 60
#define MAXSPEED 8
#define MINSPEED 0
#define MAXWAIT 35
#define MINWAIT 5
#define MAXGOTIME 250
#define MINGOTIME 40
#define ACCUMTIME 1300
#define PNADDCYECLE 20
/**********************************************************
Function:  resetInfo
Description：	重置地铁
Attention:  无
**********************************************************/
void resetInfo(setTrainInfo *Info,all_lines_stations *all)
{
	int i;
	setTrain *p,*pb;
	station_information_j(all);
	for(i=0;i<3;i++)
	{
		//释放原储存空间
		for(pb=(Info+i)->trainHead,p=(Info+i)->trainHead;p!=NULL;)
		{
			p=p->next;
			free(pb);
			pb=p;
		}
		for(pb=(Info+i)->rtrainHead,p=(Info+i)->rtrainHead;p!=NULL;)
		{
			p=p->next;
			free(pb);
			pb=p;
		}
		(Info+i)->goTime=DAULTGOTIME;
		(Info+i)->speed=DAULTSPEED;
		(Info+i)->wait=DAULTWAIT;
		(Info+i)->rtrainHead=NULL;
		(Info+i)->trainHead=NULL;
	}
	
}
/**********************************************************
Function:  addPN_c
Description：	增加客流量
Attention:  无
**********************************************************/
void addPN_c(setTrainInfo *Info,int *timeCycle)
{
	int i,randomS;
	(*timeCycle)+=1;
	if(*timeCycle>=PNADDCYECLE)
	{
		*timeCycle=0;
		for(i=1;i<=Info->stationNum;i++)
		{
			randomS=(Info->lineHead->station+i)->station_name[time(NULL)%18];
			srand(randomS*clock()+randomS*time(NULL));
			if(rand()%2==0)
			{
				if((Info->lineHead->station+i)->level==0)
				{
					randomS*=(randomS+time(NULL));
					srand(randomS*clock()+randomS*time(NULL));
					(Info->lineHead->station+i)->peopleNum+=(rand()%6);
				}
				else if((Info->lineHead->station+i)->level==1)
				{
					randomS*=(randomS+time(NULL));
					srand(randomS*clock()+randomS*time(NULL));
					(Info->lineHead->station+i)->peopleNum+=(rand()%12);
				}
				else if((Info->lineHead->station+i)->level==2)
				{
					if((Info->lineHead->station+i)->peopleNum<300)
					{
						randomS*=(randomS+time(NULL));
						srand(randomS*clock()+randomS*time(NULL));
						(Info->lineHead->station+i)->peopleNum+=(rand()%25);
					}
					else
					{
						randomS*=(randomS+time(NULL));
						srand(randomS*clock()+randomS*time(NULL));
						(Info->lineHead->station+i)->peopleNum+=(rand()%6);
					}
					
				}
				else if((Info->lineHead->station+i)->level==3)
				{
					if((Info->lineHead->station+i)->peopleNum<400)
					{
						randomS*=(randomS+time(NULL));
						srand(randomS*clock()+randomS*time(NULL));
						(Info->lineHead->station+i)->peopleNum+=(rand()%55);
					}
					else
					{
						randomS*=(randomS+time(NULL));
						srand(randomS*clock()+randomS*time(NULL));
						(Info->lineHead->station+i)->peopleNum+=(rand()%10);
					}
					
				}
			}
		}
	}
	
}
/**********************************************************
Function:  drawControlFrame
Description：	绘制控制框
Attention:  无
**********************************************************/
void drawControlFrame(int x,int y,int *para)
{
	char wait[5];
	char speed[5];
	char goTime[5];
	itoa(*para,speed,10);
	itoa(*(para+1),wait,10);
	itoa(*(para+2),goTime,10);
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
	outtextxy(x+118,y-5,speed);
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
	outtextxy(x+118,y+35,wait);
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
	outtextxy(x+118,y+75,goTime);
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
	Info->lineHead=&(all->station_line1);
	(Info+1)->lineHead=&(all->station_line2);
	(Info+2)->lineHead=&(all->station_line4);
	(Info)->stationNum=8;
	(Info+1)->stationNum=9;
	(Info+2)->stationNum=8;
	for(i=0;i<3;i++)
	{
		(Info+i)->num=0;
		(Info+i)->wait=DAULTWAIT;//停站时间
		(Info+i)->speed=DAULTSPEED;//速度
		(Info+i)->goTime=DAULTGOTIME;//发车
		(Info+i)->trainHead=NULL;//正向车链表
		(Info+i)->rtrainHead=NULL;//逆向车链表
	}
	// closegraph();
	// printf("%d %d",Info->lineHead->number,(Info+1)->lineHead->number);
	// getch();
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
		if (*mx >= 10 && *mx <= 45 && *my >= 10&& *my <= 45)//退出按钮点击退出
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
		else if(*mx >= 560 && *mx <= 620 && *my >= 400&& *my <= 460)//点击reset
		{
			return 10;
		}
	}
	return -1;
}
/**********************************************************
Function:  controlGoTime
Description：	控制发车时间
Attention:  无
**********************************************************/
void controlGoTime(setTrainInfo *Info,int *GotimeI,long int *accum,int *timeCycle,station *line2)
{
	addPN_c(Info,timeCycle);
	*accum=*accum+1;
	if(*GotimeI>=(Info->goTime)*TIMEUNIT)
	{
		*GotimeI=0;
		createTrain(Info,0);
		createTrain(Info,1);
		changeDot(Info,line2);
	}
	else
	{
		*GotimeI=*GotimeI+1;
		changeDot(Info,line2);
	}
	// changeStationPN(35,190,DARKGRAY,LIGHTCYAN,currentStation);
	delay(5);
}
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
	delay(5);
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
	//正向车初始化
	if(reverse==0)
	{
		for(T=Info->trainHead,Tb=Info->trainHead;T!=NULL;T=T->next)
		{
			Tb=T;
		}
		T=(setTrain*)malloc(sizeof(setTrain));
		if(T==NULL)
		{
			printf("No memory.");
			getch();
		}
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
	//逆向车初始化
	if(reverse==1)
	{
		for(T=Info->rtrainHead,Tb=Info->rtrainHead;T!=NULL;T=T->next)
		{
			Tb=T;
		}
		T=(setTrain*)malloc(sizeof(setTrain));
		if(Tb==NULL)
		{
			Info->rtrainHead=T;
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
		T->x=Info->lineHead->station[Info->stationNum].x;
		T->y=Info->lineHead->station[Info->stationNum].y;
		T->reverse=0;
		T->k=Info->stationNum;
		T->Ti=0;
	}
}
/**********************************************************
Function:  changeDot
Description：	地铁前进动画
Attention:  无
**********************************************************/
void changeDot(setTrainInfo *Info,station *line2)
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
	//正向
	for(fT=Info->trainHead,fTb=Info->trainHead;fT!=NULL;fTb=fT,fT=fT->next)
	{
		if(fT->count==0)//车不在站台
		{
			if(fT->setDotSave[0][0]!=-100)//判断是不是第一次加载
			{
				hideDot(fT);
			}
			fT->i+=speed;//加上speed
			xnew=(line[fT->k].x)+((float)((line[fT->k+1].x)-(line[fT->k].x)))/(fT->Ti)*(fT->i);
			ynew=(line[fT->k].y)+((float)((line[fT->k+1].y)-(line[fT->k].y)))/(fT->Ti)*(fT->i);
			if(Info->lineHead->number==1)//一号线
			{
				fT->x=xnew;
				fT->y=ynew-3;
			}
			else if(Info->lineHead->number==2)//二号线
			{
				fT->x=xnew-3;
				fT->y=ynew;
			}
			else if(Info->lineHead->number==4)//四号线
			{
				fT->x=xnew;
				fT->y=ynew-3;
			}
			readDotbk(fT);
			//正向车用蓝色
			setcolor(BLUE);
			setfillstyle(1, BLUE);
			drawDot(fT,BLUE);
			if(fT->Ti<=fT->i)//到站
			{
				// line[fT->k+1].peopleNum=line[fT->k+1].peopleNum/2;
				if(fT->k!=Info->stationNum+1)//非终点站
				{
					fT->i=0;
					fT->k++;
					fT->count=(Info->wait)*TIMEUNIT;
				}
				else//终点站
				{
					// deleteTrain(fTb,fT);
					// fT=fTb;
					Info->trainHead=fT->next;
					free(fT);
				}
				
			}
			// delay(5);
		}
		else//车在站台
		{
			if(fT->count==1)//准备开车时
			{
				// line[fT->k].peopleNum=line[fT->k].peopleNum/2;
				if(Info->lineHead->number==1)//一号线
				{
					if(fT->k==4)
					{
						line2[2].peopleNum=line2[2].peopleNum/2;
					}
					else
					{
						line[fT->k].peopleNum=line[fT->k].peopleNum/2;
					}
					distance=(line[fT->k+1].distance.dx)-(line[fT->k].distance.dx);
				}
				else if(Info->lineHead->number==2)//二号线
				{
					distance=(line[fT->k+1].distance.dy)-(line[fT->k].distance.dy);
					line[fT->k].peopleNum=line[fT->k].peopleNum/2;
				}
				else if(Info->lineHead->number==4)//四号线
				{
					if(fT->k==4)
					{
						line2[7].peopleNum=line2[7].peopleNum/2;
					}
					else if(fT->k==3)
					{
						line2[8].peopleNum=line2[8].peopleNum/2;
					}
					else
					{
						line[fT->k].peopleNum=line[fT->k].peopleNum/2;
					}
					distance=(line[fT->k+1].distance.dz)-(line[fT->k].distance.dz);
				}
				distance=distance*DISTANCEUNIT;
				fT->Ti=(int)(distance);
			}
			fT->count--;
			// delay(5);
		}
		
		
	}
	//逆向
	for(rT=Info->rtrainHead,rTb=Info->rtrainHead;rT!=NULL;rTb=rT,rT=rT->next)
	{
		if(rT->count==0)//车不在站台
		{
			if(rT->setDotSave[0][0]!=-100)//判断是不是第一次加载
			{
				hideDot(rT);
			}
			rT->i+=speed;//加上speed
			xnew=(line[rT->k].x)-((float)((line[rT->k].x)-(line[rT->k-1].x)))/(rT->Ti)*(rT->i);
			ynew=(line[rT->k].y)-((float)((line[rT->k].y)-(line[rT->k-1].y)))/(rT->Ti)*(rT->i);
			if(Info->lineHead->number==1)//一号线
			{
				rT->x=xnew;
				rT->y=ynew+3;
			}
			else if(Info->lineHead->number==2)//二号线
			{
				rT->x=xnew+3;
				rT->y=ynew;
			}
			else if(Info->lineHead->number==4)//四号线
			{
				rT->x=xnew;
				rT->y=ynew+3;
			}
			readDotbk(rT);
			//逆向车用红色
			setcolor(RED);
			setfillstyle(1, RED);
			drawDot(rT,RED);
			if(rT->Ti<=rT->i)//到站
			{
				// line[fT->k-1].peopleNum=line[fT->k-1].peopleNum/2;
				if(rT->k!=1)//非起点站
				{
					rT->i=0;
					rT->k--;
					rT->count=(Info->wait)*TIMEUNIT;
				}
				else//起点站
				{
					// deleteTrain(rTb,rT);
					// rT=rTb;
					Info->rtrainHead=rT->next;
					free(rT);
				}
				
			}
			// delay(5);
		}
		else//车在站台
		{
			if(rT->count==1)//准备开车时
			{
				if(Info->lineHead->number==1)//一号线
				{
					if(rT->k==4)
					{
						line2[2].peopleNum=line2[2].peopleNum/2;
					}
					else
					{
						line[rT->k].peopleNum=line[rT->k].peopleNum/2;
					}
					distance=(line[rT->k].distance.dx)-(line[rT->k-1].distance.dx);
				}
				else if(Info->lineHead->number==2)//二号线
				{
					distance=(line[rT->k].distance.dy)-(line[rT->k-1].distance.dy);
					line[rT->k].peopleNum=line[rT->k].peopleNum/2;
				}
				else if(Info->lineHead->number==4)//四号线
				{
					if(rT->k==4)
					{
						line2[7].peopleNum=line2[7].peopleNum/2;
					}
					else if(rT->k==3)
					{
						line2[8].peopleNum=line2[8].peopleNum/2;
					}
					else
					{
						line[rT->k].peopleNum=line[rT->k].peopleNum/2;
					}
					distance=(line[rT->k].distance.dz)-(line[rT->k-1].distance.dz);
				}
				distance=distance*DISTANCEUNIT;
				rT->Ti=(int)(distance);
			}
			rT->count--;
			// delay(5);
		}
		
		
	}
}
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
	setfillstyle(1,DARKGRAY);
	bar(515,180,572,390);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	itoa(para[0],temp,10);
	outtextxy(528,185,temp);
	itoa(para[1],temp,10);
	outtextxy(528,225,temp);
	itoa(para[2],temp,10);
	outtextxy(528,265,temp);
}
/**********************************************************
Function:  clickStation
Description：	点击站点变化
Attention:  无
**********************************************************/
void clickStation(int x,int y,station *sta,station **currentStation,int *mx,int *my)
{
	mousehide(*mx, *my);
	*currentStation=sta;
	DrawCircles_j();
    // puthz(30,130,"站点名称：",16,16,RED);
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	bar(110,187,210,207);
    puthz(115,190,(*currentStation)->station_name,16,16,LIGHTCYAN);
    setcolor(RED);
    circle(x,y,5);
    circle(x,y,4);
	getMousebk(*mx, *my);
}
/**********************************************************
Function:  drawStationDetail
Description：	画显示站点信息模块
Attention:  无
**********************************************************/
void drawStationDetail(int x,int y,int bkcolor,int ccolor,station *currentStation)
{
	char strtemp[10];
	setcolor(bkcolor);
	setfillstyle(1,bkcolor);
	bar(x,y,x+200,y+130);
	puthz(x,y,"站点名：",16,16,ccolor);
	puthz(x+80,y,currentStation->station_name,16,16,ccolor);
	puthz(x,y+40,"客流量：",16,16,ccolor);
	itoa(currentStation->peopleNum,strtemp,10);
	puthz(x+80,y+40,strtemp,16,16,ccolor);
	setcolor(RED);
	circle(currentStation->x,currentStation->y,5);
    circle(currentStation->x,currentStation->y,4);
}
/**********************************************************
Function:  changeStationPN
Description：	改变站点客流量
Attention:  无
**********************************************************/
void changeStationPN(int x,int y,int bkcolor,int ccolor,station *currentStation)
{
	char strtemp[10];
	setcolor(bkcolor);
	setfillstyle(1,bkcolor);
	bar(x+77,y+37,x+177,y+57);
	itoa(currentStation->peopleNum,strtemp,10);
	puthz(x+80,y+40,strtemp,16,16,ccolor);
	setcolor(RED);
	circle(currentStation->x,currentStation->y,5);
    circle(currentStation->x,currentStation->y,4);
	delay(5);
}
/**********************************************************
Function:  drawControlScreen
Description：	画调度页面，实现动画
Attention:  无
**********************************************************/
void drawControlScreen(setuser *person,int *judge,setuser *head,all_lines_stations *all,setTrainInfo *Info)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
	int i;//划线循环变量
	long int accum=0;//累计器
	int currentNum=0;//当前调度线路
	int timeCycle=0;
	int para[3]={DAULTSPEED,DAULTWAIT,DAULTGOTIME};//当前参数存储  0：速度  1：停站时间  2：发车间隔 
	int goTimeI[3]={0,0,0};
	int reset=0;//判断鼠标移动到reset按钮上
    // setTrainInfo Info[3];//记录三条线调度的相关参数
	station *currentStation;//记录当前查看站点的地址
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(DARKGRAY);
	// initTranInfo(Info,all);
	currentStation=&all->line1[1];
	// closegraph();
	// printf("%d %d\n",Info->trainHead->x,Info->rtrainHead->y);
	// getch();

	//绘制界面
	//绘制返回按钮
	returnBtn_small_c(15,15,LIGHTBLUE);
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
    puthz(183,2,"地铁调度控制",32,32,BROWN);
	//绘制地铁线路
    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();
	//调度相关绘制
	//reset按钮
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(590,430,0,360,27);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(590,430,0,360,25);
	setcolor(LIGHTRED);
	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	outtextxy(567,420,"RESET");
	//选取地铁线圆
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(620,12,0,360,6);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(620,12,0,360,2);
	//调整模块
	drawControlFrame(410,190,para);
	//站点信息模块
	drawStationDetail(35,190,DARKGRAY,LIGHTCYAN,currentStation);
	

	// createTrain(&Info[0],0);
	// createTrain(&Info[0],1);
	// createTrain(&Info[1],0);
	// createTrain(&Info[1],1);
	// createTrain(&Info[2],0);
	// createTrain(&Info[2],1);
	createTrain(Info,0);
	createTrain(Info,1);
	createTrain(Info+1,0);
	createTrain(Info+1,1);
	createTrain(Info+2,0);
	createTrain(Info+2,1);

	while(1)
	{
		//debug精灵
		// debugElf(15,160,WHITE,LIGHTBLUE,timeCycle,rand(),clock());
		//车站人增加函数
		changeStationPN(35,190,DARKGRAY,LIGHTCYAN,currentStation);
		//一号线
		// controlGoTime(&Info[0],&goTimeI[0],&accum,&timeCycle,Info[1].lineHead->station);
		controlGoTime(Info,&goTimeI[0],&accum,&timeCycle,(Info+1)->lineHead->station);
		// changeDot(&Info[0]);
		//二号线
		// controlGoTime(&Info[1],&goTimeI[1],&accum,&timeCycle,Info[1].lineHead->station);
		controlGoTime(Info+1,&goTimeI[1],&accum,&timeCycle,(Info+1)->lineHead->station);
		// changeDot(&Info[1]);
		//四号线
		// controlGoTime(&Info[2],&goTimeI[2],&accum,&timeCycle,Info[1].lineHead->station);
		controlGoTime(Info+2,&goTimeI[2],&accum,&timeCycle,(Info+1)->lineHead->station);
		// changeDot(&Info[2]);
		if(accum>=ACCUMTIME)
		{
			accum=0;
			Drawstation1_j();
			Drawstation2_j();
			Drawstation4_j();
			DrawCircles_j();
		}
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
				if(para[0]>=MINSPEED&&para[0]<MAXSPEED)
				{
					para[0]++;
					Info[currentNum].speed=para[0];
					changeValue(para);
				}
				break;
			//点击速度-
			case 5:
				if(para[0]>MINSPEED&&para[0]<=MAXSPEED)
				{
					para[0]--;
					Info[currentNum].speed=para[0];
					changeValue(para);
				}
				break;
			//点击停站+
			case 6:
				if(para[1]>=MINWAIT&&para[1]<MAXWAIT)
				{
					para[1]++;
					Info[currentNum].wait=para[1];
					changeValue(para);
				}
				break;
			//点击停站-
			case 7:
				if(para[1]>MINWAIT&&para[1]<=MAXWAIT)
				{
					para[1]--;
					Info[currentNum].wait=para[1];
					changeValue(para);
				}
				break;
			//点击发车+
			case 8:
				if(para[2]>=MINGOTIME&&para[2]<MAXGOTIME)
				{
					para[2]+=10;
					Info[currentNum].goTime=para[2];
					changeValue(para);
				}
				break;
			//点击发车-
			case 9:
				if(para[2]>MINGOTIME&&para[2]<=MAXGOTIME)
				{
					para[2]-=10;
					Info[currentNum].goTime=para[2];
					changeValue(para);
				}
				break;
			//点击reset
			case 10:
				if(Choose_c("您正在重置调度模拟","此操作将无法撤销！", &mx, &my, LIGHTBLUE)==1)
				{
					resetInfo(Info,all);
					*judge=turnTo_c(person,11);
					return;
				}
				else
				{
					mousehide(mx,my);
					cleardevice();
					setbkcolor(DARKGRAY);
					//绘制返回按钮
					returnBtn_small_c(15,15,LIGHTBLUE);
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
					puthz(183,2,"地铁调度控制",32,32,BROWN);
					//绘制地铁线路
					Drawstation1_j();
					Drawstation2_j();
					Drawstation4_j();
					DrawCircles_j();
					//调度相关绘制
					//reset按钮
					setcolor(LIGHTBLUE);
					setfillstyle(1,LIGHTBLUE);
					pieslice(590,430,0,360,27);
					setcolor(WHITE);
					setfillstyle(1,WHITE);
					pieslice(590,430,0,360,25);
					setcolor(LIGHTRED);
					settextstyle(SMALL_FONT,HORIZ_DIR,6);
					outtextxy(567,420,"RESET");
					//选取地铁线圆
					setcolor(LIGHTBLUE);
					setfillstyle(1,LIGHTBLUE);
					pieslice(620,12,0,360,6);
					setcolor(WHITE);
					setfillstyle(1,WHITE);
					pieslice(620,12,0,360,2);
					//调整模块
					drawControlFrame(410,190,para);
					//站点信息模块
					drawStationDetail(35,190,DARKGRAY,LIGHTCYAN,currentStation);
					getMousebk(mx,my);
				}
				

		}
		if (mx >= 560 && mx <= 620 && my >= 400 && my <= 460 && reset==0) //鼠标移到reset
        {
			mousehide(mx,my);
			setcolor(LIGHTRED);
			setfillstyle(1,LIGHTRED);
			pieslice(590,430,0,360,27);
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			pieslice(590,430,0,360,25);
			setcolor(GREEN);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(567,420,"RESET");
			getMousebk(mx,my);
			reset=1;
        }
		if (!(mx >= 560 && mx <= 620 && my >= 400 && my <= 460) && reset==1) //鼠标移出reset
        {
            reset=0;
			mousehide(mx,my);
			setcolor(LIGHTBLUE);
			setfillstyle(1,LIGHTBLUE);
			pieslice(590,430,0,360,27);
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			pieslice(590,430,0,360,25);
			setcolor(LIGHTRED);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			outtextxy(567,420,"RESET");
			getMousebk(mx,my);
        }
		//点击不同站
		//三条线的圈圈
        //1号线的
        if (mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons) //第一次点击
        {
            clickStation(80, 100, &all->line1[1],&currentStation,&mx,&my);
        }
        if (mx >= 135 && mx <= 145 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(140, 100, &all->line1[2],&currentStation,&mx,&my);
        }
        if (mx >= 195 && mx <= 205 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(200, 100, &all->line1[3],&currentStation,&mx,&my);
        }
        if (mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons) //这个是循礼门站
        {
            clickStation(260, 100, &all->line2[2],&currentStation,&mx,&my);//所有的只用2号线
        }
        if (mx >= 315 && mx <= 325 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(320, 100, &all->line1[5], &currentStation,&mx,&my);
        }
        if (mx >= 375 && mx <= 385 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(380, 100, &all->line1[6], &currentStation,&mx,&my);
        }
        if (mx >= 435 && mx <= 445 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(440, 100, &all->line1[7], &currentStation,&mx,&my);
        }
        if (mx >= 495 && mx <= 505 && my >= 95 && my <= 105 && buttons)
        {
            clickStation(500, 100, &all->line1[8], &currentStation,&mx,&my);
        }
        //2号线的
        if (mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons) 
        {
            clickStation(300, 70, &all->line2[1], &currentStation,&mx,&my);
        }
        if (mx >= 255 && mx <= 265 && my >= 151 && my <= 161 && buttons)
        {
            clickStation(260, 156, &all->line2[3], &currentStation,&mx,&my);
        }
        if (mx >= 255 && mx <= 265 && my >= 207 && my <= 217 && buttons)
        {
            clickStation(260, 212, &all->line2[4], &currentStation,&mx,&my);
        }
        if (mx >= 255 && mx <= 265 && my >= 263 && my <= 273 && buttons)
        {
            clickStation(260, 268, &all->line2[5], &currentStation,&mx,&my);
        }
        if (mx >= 255 && mx <= 265 && my >= 319 && my <= 329 && buttons)
        {
            clickStation(260, 324, &all->line2[6], &currentStation,&mx,&my); 
        }                                                                   
        if (mx >= 255 && mx <= 265 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(260, 380, &all->line2[7], &currentStation,&mx,&my);//洪山广场
        }
        if (mx >= 195 && mx <= 205 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(200, 380, &all->line2[8], &currentStation,&mx,&my);//中南路
        }
        if (mx >= 235 && mx <= 245 && my >= 405 && my <= 415 && buttons)
        {
            clickStation(240, 410, &all->line2[9], &currentStation,&mx,&my);
        }
        //4号线的
        if (mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons) //第一次点击
        {
            clickStation(80, 380, &all->line4[1], &currentStation,&mx,&my);
        }
        if (mx >= 135 && mx <= 145 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(140, 380, &all->line4[2], &currentStation,&mx,&my);
        }
        if (mx >= 315 && mx <= 325 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(320, 380, &all->line4[5], &currentStation,&mx,&my);
        }
        if (mx >= 375 && mx <= 385 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(380, 380, &all->line4[6], &currentStation,&mx,&my);
        }
        if (mx >= 435 && mx <= 445 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(440, 380, &all->line4[7], &currentStation,&mx,&my);
        }
        if (mx >= 495 && mx <= 505 && my >= 375 && my <= 385 && buttons)
        {
            clickStation(500, 380, &all->line4[8], &currentStation,&mx,&my);
		}


	}
}