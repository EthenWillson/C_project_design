#include"control_c.h"
#include"common_c.h"
#define LINENUM 3  //��·����
#define INITCARNUM 2 //��ʼ����
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
	for(i=0;i<LINENUM;i++)
	{
		Info[i].num=INITCARNUM;//Ĭ��������
		//��ʼ����һ����
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
		//��ʼ��������
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
			if(j<INITCARNUM/2)//ǰһ�복����
			{
				temp->reverse=0;
				temp->k=0;
			}
			else//��һ�복����
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
Description��	�����¼��������ĸ��º͵���¼���
Attention:  ��
**********************************************************/
int otherEvent(int *mx,int *my,int *buttons)
{
    newxy(mx, my, buttons);
	if(*buttons)//����¼�
	{
		if (*mx >= 550 && *mx <= 610 && *my >= 210&& *my <= 270)//�˳���ť����˳�
		{
			return 0;
		}
	}
	return 1;
}
/**********************************************************
Function:  changePlace
Description��	����ǰ������
Attention:  ��
**********************************************************/
void changePlace(setTrain *dot,station *line,int speed,int length,int wait,int linenum)//linenum��ʾ�ڼ�����
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
	if(dot->count==0)//������վ̨
	{
		if(dot->reverse==0)//��������ʻ
		{
			//������վ���
			if(linenum==1)//һ����
			{
				distance=(line[dot->k+2].distance.dx)-(line[dot->k+1].distance.dx);
			}
			else if(linenum==2)//������
			{
				distance=(line[dot->k+2].distance.dy)-(line[dot->k+1].distance.dy);
			}
			else if(linenum==4)//�ĺ���
			{
				distance=(line[dot->k+2].distance.dz)-(line[dot->k+1].distance.dz);
			}
			distance=distance*100;
			xnew=(line[dot->k+1].x)+((float)((line[dot->k+2].x)-(line[dot->k+1].x)))/distance*speed*(dot->i);
			ynew=(line[dot->k+1].y)+((float)((line[dot->k+2].y)-(line[dot->k+1].y)))/distance*speed*(dot->i);
			if(dot->setDotSave[0][0]!=-100)//�ж��ǲ��ǵ�һ�μ���
			{
				hideDot(dot);
			}
			dot->x=xnew;
			dot->y=ynew;
			readDotbk(dot);
			//��������ɫ
			setcolor(BLUE);
			setfillstyle(1, BLUE);
			drawDot(dot,BLUE);
			//λ������1
			dot->i++;
			if(dot->i==(int)(distance/speed))//�������վ
			{
				dot->i=0;
				dot->k++;
				dot->count=wait;
			}
			if(dot->k==length-1)//�������յ�վ
			{
				dot->reverse=1;
				//����������֮������
				if(linenum==1)//һ����
				{
					Drawstation1_j();
					DrawCircles_j();
				}
				else if(linenum==2)//������
				{
					Drawstation2_j();
					DrawCircles_j();
				}
				else if(linenum==4)//�ĺ���
				{
					Drawstation4_j();
					DrawCircles_j();
				}
			}
			delay(5);
		}
		else//��������ʻ
		{
			if(linenum==1)//һ����
			{
				distance=(line[dot->k+1].distance.dx)-(line[dot->k].distance.dx);
			}
			else if(linenum==2)//������
			{
				distance=(line[dot->k+1].distance.dy)-(line[dot->k].distance.dy);
			}
			else if(linenum==4)//�ĺ���
			{
				distance=(line[dot->k+1].distance.dz)-(line[dot->k].distance.dz);
			}
			distance=distance*100;
			xnew=(line[dot->k+1].x)-((float)((line[dot->k+1].x)-(line[dot->k].x)))/distance*speed*(dot->i);
			ynew=(line[dot->k+1].y)-((float)((line[dot->k+1].y)-(line[dot->k].y)))/distance*speed*(dot->i);
			if(dot->setDotSave[0][0]!=-100)//�ж��ǲ��ǵ�һ�μ���
			{
				hideDot(dot);
			}
			dot->x=xnew;
			dot->y=ynew;
			readDotbk(dot);
			//��������ɫ
			setcolor(RED);
			setfillstyle(1, RED);
			drawDot(dot,RED);
			//λ������1
			dot->i++;
			if(dot->i==(int)distance/speed)//�������վ
			{
				dot->i=0;
				dot->k--;
				dot->count=wait;
				
			}
			if(dot->k==0)//������ʼ��վ
			{
				dot->reverse=0;
				//����������֮������
				if(linenum==1)//һ����
				{
					Drawstation1_j();
					DrawCircles_j();
				}
				else if(linenum==2)//������
				{
					Drawstation2_j();
					DrawCircles_j();
				}
				else if(linenum==4)//�ĺ���
				{
					Drawstation4_j();
					DrawCircles_j();
				}
			}
			delay(5);
		}
		
	}
	else//����վ̨
	{
		dot->count--;
		delay(5);
	}
	
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
    setTrainInfo Info[3];//��¼�����ߵ��ȵ���ز���
	// ��ʼ��
	// ����ʼ��
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

	//���ƽ���
	//���Ʒ��ذ�ť
	returnBtn_c(550,210,GREEN);
	//���Ƶ�����·
	line(460,0,460,75);
    line(460,75,640,75);

    setlinestyle(0,0,3);
    setcolor(LIGHTCYAN);
    line(500,10,550,10);
    outtextxy(560,0,"1");
    puthz(570,5,"����",16,16,LIGHTBLUE);
    setcolor(LIGHTGREEN);
    line(500,30,550,30);
    outtextxy(560,20,"2");
    puthz(570,25,"����",16,16,LIGHTGREEN);
    setcolor(YELLOW);
    line(500,50,550,50);
    outtextxy(560,40,"4");
    puthz(570,45,"����",16,16,YELLOW);
    puthz(180,0,"��������һ��",32,32,BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();



	
	while(1)
	{
		// changePlace(&Info[0].lineHead[0],Info[0].lineHead->station,1,8,200);
		//һ����
		changePlace(Info[0].trainHead,Info[0].lineHead->station,2,8,20,1);
		changePlace(Info[0].trainHead->next,Info[0].lineHead->station,1,8,20,1);
		//������
		changePlace(Info[1].trainHead,Info[1].lineHead->station,2,9,20,2);
		changePlace(Info[1].trainHead->next,Info[1].lineHead->station,2,9,20,2);
		//�ĺ���
		changePlace(Info[2].trainHead,Info[2].lineHead->station,2,8,20,4);
		changePlace(Info[2].trainHead->next,Info[2].lineHead->station,2,8,20,4);
		if(otherEvent(&mx,&my,&buttons)==0)
		{
			*judge=turnTo_c(person,2);
			return;
		}
	}
}