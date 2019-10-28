#include"control_c.h"
#include"common_c.h"
#define LINENUM 3  //��·����
#define INITCARNUM 2 //��ʼ����
/**********************************************************
Function:  drawControlFrame
Description��	���ƿ��ƿ�
Attention:  ��
**********************************************************/
void drawControlFrame(int x,int y)
{
	puthz(0+x, 0+y, "�г��ٶȣ�", 16, 16, LIGHTCYAN);
	puthz(0+x, 40+y, "ͣվʱ�䣺", 16, 16, LIGHTCYAN);
	puthz(0+x, 80+y, "���������", 16, 16, LIGHTCYAN);
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	//�ٶ�
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
	//�ȴ�
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
	//����
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
Description��	��������
Attention:  ��
**********************************************************/
void drawDot(setTrain *dot,int color)
{
	setcolor(color);
	setfillstyle(1, color);
	bar((int)dot->x-2,(int)dot->y-2,(int)dot->x+2,(int)dot->y+2);
}
/**********************************************************
Function:  hideDot
Description��	���ص����㲢���ֱ���
Attention:  ��
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
Description��	��ȡ�����㱳��
Attention:  ��
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
Description��	��ؽṹ��ĳ�ʼ��
Attention:  ��
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
		Info[i].wait=10;//ͣվʱ��
		Info[i].speed=1;//�ٶ�
		Info[i].goTime=20;//����
		Info[i].trainHead=NULL;//��������
		Info[i].rtrainHead=NULL;//��������
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
// 		Info[i].num=INITCARNUM;//Ĭ��������
// 		Info[i].wait=10;//ͣվʱ��
// 		Info[i].speed=1;//�ٶ�
// 		Info[i].goTime=20;//����
// 		//��ʼ����һ����
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
// 		Info[i].trainHead->distance[0]=0.0;//��¼Ҫ�������ٸ���λλ��
// 		Info[i].trainHead->distance[1]=0.0;
// 		//��ʼ��������
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
// 			if(j<INITCARNUM/2)//ǰһ�복����
// 			{
// 				temp->reverse=0;
// 				temp->k=0;
// 			}
// 			else//��һ�복����
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
Description��	�����¼��������ĸ��º͵���¼���
Attention:  ��
**********************************************************/
int otherEvent(int *mx,int *my,int *buttons)
{
    newxy(mx, my, buttons);
	if(*buttons)//����¼�
	{
		if (*mx >= 10 && *mx <= 70 && *my >= 210&& *my <= 270)//�˳���ť����˳�
		{
			return 0;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 0&& *my <= 25)//���һ�����л���
		{
			return 1;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 25&& *my <= 45)//����������л���
		{
			return 2;
		}
		else if(*mx >= 430 && *mx <= 640 && *my >= 45&& *my <= 70)//����ĺ����л���
		{
			return 3;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 191&& *my <= 205)//����ٶ�+��
		{
			return 4;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 191&& *my <= 205)//����ٶ�-��
		{
			return 5;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 231&& *my <= 245)//���ͣվ+��
		{
			return 6;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 231&& *my <= 245)//���ͣվ-��
		{
			return 7;
		}
		else if(*mx >= 488 && *mx <= 502 && *my >= 271&& *my <= 285)//�������+��
		{
			return 8;
		}
		else if(*mx >= 583 && *mx <= 597 && *my >= 271&& *my <= 285)//�������-��
		{
			return 9;
		}
	}
	return -1;
}
/**********************************************************
Function:  judgeCrash
Description��	����������ײ���¼�
Input:  Info һ������ز���
Attention:  ��
**********************************************************/
// void judgeCrash(setTrainInfo Info)
// {

// }
/**********************************************************
Function:  debugElf
Description��	debug����
Attention:  ��
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
Description��	ɾ������
Attention:  ��
**********************************************************/
void deleteTrain(setTrain *before,setTrain *current)
{
	before->next=current->next;
	free(current);
}
/**********************************************************
Function:  createTrain
Description��	���ɵ���
Attention:  reverseΪ0����reverseΪ1����
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
		
		//��ʼ��
		
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
Description��	����ǰ������
Attention:  ��
**********************************************************/
void changeDot(setTrainInfo *Info)
{
	//�ֲ�����
	int i,j;
	setTrain *fT,*fTb,*rT,*rTb;//fT����rT����
	station *line=Info->lineHead->station;
	float xnew,ynew,distance;
	int speed=Info->speed,wait=Info->wait,goTime=Info->goTime;
	//��ʼ��
	fT=Info->trainHead;
	rT=Info->rtrainHead;

	for(fT=Info->trainHead,fTb=Info->trainHead;fT!=NULL;fTb=fT,fT=fT->next)
	{
		if(fT->count==0)//������վ̨
		{
			if(fT->setDotSave[0][0]!=-100)//�ж��ǲ��ǵ�һ�μ���
			{
				hideDot(fT);
			}
			// xnew=(fT->x)+fT->distance[0]*speed;
			// ynew=(fT->y)+fT->distance[1]*speed;
			fT->i+=speed;//����speed
			xnew=(line[fT->k].x)+((float)((line[fT->k+1].x)-(line[fT->k].x)))/(fT->Ti)*(fT->i);
			ynew=(line[fT->k].y)+((float)((line[fT->k+1].y)-(line[fT->k].y)))/(fT->Ti)*(fT->i);
			if(Info->lineHead->number==1)//һ����
			{
				// distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
				// distance=distance*100;
				fT->x=xnew;
				fT->y=ynew-3;
			}
			else if(Info->lineHead->number==2)//������
			{
				// distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
				fT->x=xnew-3;
				fT->y=ynew;
			}
			else if(Info->lineHead->number==4)//�ĺ���
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
			//��������ɫ
			setcolor(BLUE);
			setfillstyle(1, BLUE);
			drawDot(fT,BLUE);
			if(fT->Ti<=fT->i)//��վ
			{
				if(fT->k!=Info->stationNum+1)//���յ�վ
				{
					fT->i=0;
					fT->k++;
					fT->count=Info->wait;
				}
				else//�յ�վ
				{
					deleteTrain(fTb,fT);
					fT=fTb;
				}
				
			}
			delay(5);
		}
		else//����վ̨
		{
			if(fT->count==1)//׼������ʱ
			{
				if(Info->lineHead->number==1)//һ����
				{
					distance=(line[fT->k+1].distance.dx)-(line[fT->k].distance.dx);
				}
				else if(Info->lineHead->number==2)//������
				{
					distance=(line[fT->k+1].distance.dy)-(line[fT->k].distance.dy);
				}
				else if(Info->lineHead->number==4)//�ĺ���
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
Description��	����ǰ������
Attention:  ��
**********************************************************/
// void changePlace(setTrain *dot,station *line,int speed,int length,int wait,int linenum)//linenum��ʾ�ڼ�����
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
// 	if(dot->count==0)//������վ̨
// 	{
// 		if(dot->reverse==0)//��������ʻ
// 		{
// 			//������վ���
// 			if(linenum==1)//һ����
// 			{
// 				// distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
// 				// distance=distance*100;
// 				xnew=(dot->x)+dot->distance[0]*speed;
// 				ynew=(dot->y)+dot->distance[1]*speed-3;
// 				// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
// 				// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i)-3;
// 			}
// 			else if(linenum==2)//������
// 			{
// 				// distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
// 				// distance=distance*100;
// 				xnew=(dot->x)+dot->distance[0]*speed-3;
// 				ynew=(dot->y)+dot->distance[1]*speed;
// 				// xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i)-3;
// 				// ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i);
// 			}
// 			else if(linenum==4)//�ĺ���
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
// 			if(dot->setDotSave[0][0]!=-100)//�ж��ǲ��ǵ�һ�μ���
// 			{
// 				hideDot(dot);
// 			}
// 			dot->x=xnew;
// 			dot->y=ynew;
// 			readDotbk(dot);
// 			//��������ɫ
// 			setcolor(BLUE);
// 			setfillstyle(1, BLUE);
// 			drawDot(dot,BLUE);
// 			//λ������1
// 			dot->i++;
// 			// if(dot->i==(int)(distance/speed))//�������վ
// 			// {
// 			// 	dot->i=0;
// 			// 	dot->k++;
// 			// 	dot->count=wait;
// 			// }
// 			if((int)dot->x>(int)line[dot->k+2].x && (int)dot->y>(int)line[dot->k+2].y)//�������վ
// 			{
// 				dot->i=0;
// 				dot->k--;
// 				dot->count=wait;
// 			}
// 			// if(dot->k==length-1)//�������յ�վ
// 			// {
// 				// dot->reverse=1;
// 				//����������֮������
// 				// if(linenum==1)//һ����
// 				// {
// 				// 	Drawstation1_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==2)//������
// 				// {
// 				// 	Drawstation2_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==4)//�ĺ���
// 				// {
// 				// 	Drawstation4_j();
// 				// 	DrawCircles_j();
// 				// }
// 			// }
// 			delay(5);
// 		}
// 		else//��������ʻ
// 		{
// 			if(linenum==1)//һ����
// 			{
// 				distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 			}
// 			else if(linenum==2)//������
// 			{
// 				distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i)+3;
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 			}
// 			else if(linenum==4)//�ĺ���
// 			{
// 				distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
// 				distance=distance*100;
// 				xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 				ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 			}
// 			// distance=distance*100;
// 			// xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 			// ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 			if(dot->setDotSave[0][0]!=-100)//�ж��ǲ��ǵ�һ�μ���
// 			{
// 				hideDot(dot);
// 			}
// 			dot->x=xnew;
// 			dot->y=ynew;
// 			readDotbk(dot);
// 			//��������ɫ
// 			setcolor(RED);
// 			setfillstyle(1, RED);
// 			drawDot(dot,RED);
// 			//λ������1
// 			dot->i++;
// 			// if(dot->i==(int)distance/speed)//�������վ
// 			// {
// 			// 	dot->i=0;
// 			// 	dot->k--;
// 			// 	dot->count=wait;
				
// 			// }
// 			if(dot->x==line[dot->k].x && dot->y==line[dot->k].y)//�������վ
// 			{
// 				dot->i=0;
// 				dot->k--;
// 				dot->count=wait;
				
// 			}
// 			if(dot->k==0)//������ʼ��վ
// 			{
// 				dot->reverse=0;
// 				//����������֮������
// 				// if(linenum==1)//һ����
// 				// {
// 				// 	Drawstation1_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==2)//������
// 				// {
// 				// 	Drawstation2_j();
// 				// 	DrawCircles_j();
// 				// }
// 				// else if(linenum==4)//�ĺ���
// 				// {
// 				// 	Drawstation4_j();
// 				// 	DrawCircles_j();
// 				// }
// 			}
// 			delay(5);
// 		}
		
// 	}
// 	else//����վ̨
// 	{
		
// 		if(dot->count==1)
// 		{
// 			if(dot->reverse==0)//����
// 			{
// 				if(linenum==1)//һ����
// 				{
// 					distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==2)//������
// 				{
// 					distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==4)//�ĺ���
// 				{
// 					distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				distance=distance*100;
// 				dot->distance[0]=(((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance);
// 				dot->distance[1]=(((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance);
// 			}
// 			else if(dot->reverse==1)//����
// 			{
// 				if(linenum==1)//һ����
// 				{
// 					distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==2)//������
// 				{
// 					distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 					dot->x=(line[dot->k+1].x);
// 					dot->y=(line[dot->k+1].y);
// 				}
// 				else if(linenum==4)//�ĺ���
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
// 		// if(linenum==1)//һ����
// 		// 	{
// 		// 		distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
// 		// 		distance=distance*100;
// 		// 		xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
// 		// 		ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i)+3;
// 		// 	}
// 		// 	else if(linenum==2)//������
// 		// 	{
// 		// 		distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
// 		// 		distance=distance*100;
// 		// 		xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i)+3;
// 		// 		ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
// 		// 	}
// 		// 	else if(linenum==4)//�ĺ���
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
Description��	��ֵ�䶯����
Attention:  ��
**********************************************************/
void changeValue(int *para)
{
	char temp[4];
	//Ϳ��ԭ�ȵ���
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
Description��	������ҳ�棬ʵ�ֶ���
Attention:  ��
**********************************************************/
void drawControlScreen(setuser *person,int *judge,setuser *head,all_lines_stations *all)
{
    int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int i;//����ѭ������
	int currentNum=0;//��ǰ������·
	int para[3]={1,10,10};//��ǰ�����洢  0���ٶ�  1��ͣվʱ��  2��������� 
    setTrainInfo Info[3];//��¼�����ߵ��ȵ���ز���
	// ��ʼ��
	// ����ʼ��
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

	//���ƽ���
	//���Ʒ��ذ�ť
	returnBtn_c(15,210,LIGHTBLUE);
	//���ƻ�������
	setcolor(GREEN);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	line(460,0,460,75);
    line(460,75,640,75);
    setlinestyle(0,0,3);
    setcolor(LIGHTCYAN);
    line(500,10,550,10);
    outtextxy(560,5,"1");
    puthz(570,5,"����",16,16,CYAN);
    setcolor(LIGHTGREEN);
    line(500,30,550,30);
    outtextxy(560,25,"2");
    puthz(570,25,"����",16,16,LIGHTGREEN);
    setcolor(YELLOW);
    line(500,50,550,50);
    outtextxy(560,45,"4");
    puthz(570,45,"����",16,16,YELLOW);
    puthz(180,0,"��������һ��",32,32,BROWN);
	//���Ƶ�����·
    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();
	//������ػ���
	//ѡȡ������Բ
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	pieslice(620,12,0,360,6);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(620,12,0,360,2);
	//����ģ��
	//�ȴ�ʱ�����ģ��
	drawControlFrame(410,190);

	createTrain(&Info[0],0);
	while(1)
	{
		//debug
		// debugElf(15,160,WHITE,LIGHTBLUE,int a,int b,int c);
		// changePlace(&Info[0].lineHead[0],Info[0].lineHead->station,1,8,200);
		//һ����
		
		// debugElf(15,160,WHITE,LIGHTBLUE,Info->trainHead->count,Info->speed,Info->stationNum);
		// closegraph();
		// printf("%d\n%d\n%d\n",Info->trainHead->count,Info->speed,Info->stationNum);
		// getch();
		changeDot(&Info[0]);
		
		// changePlace(Info[0].trainHead,Info[0].lineHead->station,Info[0].speed,8,Info[0].wait,1);
		// changePlace(Info[0].trainHead->next,Info[0].lineHead->station,Info[0].speed,8,Info[0].wait,1);
		//������
		// changePlace(Info[1].trainHead,Info[1].lineHead->station,Info[1].speed,9,Info[1].wait,2);
		// changePlace(Info[1].trainHead->next,Info[1].lineHead->station,Info[1].speed,9,Info[1].wait,2);
		//�ĺ���
		// changePlace(Info[2].trainHead,Info[2].lineHead->station,Info[2].speed,8,Info[1].wait,4);
		// changePlace(Info[2].trainHead->next,Info[2].lineHead->station,Info[2].speed,8,Info[1].wait,4);
		switch(otherEvent(&mx,&my,&buttons))
		{
			case 0:
				*judge=turnTo_c(person,2);
				return;
			//���һ�����л���
			case 1:
				mousehide(mx,my);
				//Ϳ��ԭ�ȵĵ�
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//���Ƶ�
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,12,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,12,0,360,2);
				//����
				currentNum=0;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//����������л���
			case 2:
				mousehide(mx,my);
				//Ϳ��ԭ�ȵĵ�
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//���Ƶ�
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,32,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,32,0,360,2);
				//����
				currentNum=1;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//����ĺ����л���
			case 3:
				mousehide(mx,my);
				//Ϳ��ԭ�ȵĵ�
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(605,0,640,60);
				//���Ƶ�
				setcolor(LIGHTBLUE);
				setfillstyle(1,LIGHTBLUE);
				pieslice(620,52,0,360,6);
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(620,52,0,360,2);
				//����
				currentNum=2;
				para[0]=Info[currentNum].speed;
				para[1]=Info[currentNum].wait;
				para[2]=Info[currentNum].goTime;
				changeValue(para);

				getMousebk(mx,my);
				break;
			//����ٶ�+
			case 4:
				//Ϳ��ԭ�ȵ���
				para[0]++;
				Info[currentNum].speed=para[0];
				changeValue(para);
				break;
			//����ٶ�+
			case 5:
				//Ϳ��ԭ�ȵ���
				para[0]--;
				Info[currentNum].speed=para[0];
				changeValue(para);
				break;
			//���ͣվ+
			case 6:
				//Ϳ��ԭ�ȵ���
				para[1]++;
				Info[currentNum].wait=para[1];
				changeValue(para);
				break;
			//���ͣվ-
			case 7:
				//Ϳ��ԭ�ȵ���
				para[1]--;
				Info[currentNum].wait=para[1];
				changeValue(para);
				break;
			//�������+
			case 8:
				//Ϳ��ԭ�ȵ���
				para[2]++;
				Info[currentNum].goTime=para[2];
				changeValue(para);
				break;
			//�������-
			case 9:
				//Ϳ��ԭ�ȵ���
				para[2]--;
				Info[currentNum].goTime=para[2];
				changeValue(para);
				break;
		}
	}
}