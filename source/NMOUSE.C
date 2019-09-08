#include "nmouse.h"


union REGS regs;

int arrowMouse[10][16] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
{ 1,0,0,0,0,0,0,5,5,5,5,5,5,1,3,3 },
{ 3,1,0,0,0,0,0,5,5,5,5,5,1,3,3,3 },
{ 3,3,1,0,0,0,4,4,4,4,1,1,3,3,3,3 },
{ 3,3,3,1,0,0,5,4,6,1,3,3,3,3,3,3 },
{ 3,3,3,3,1,0,5,5,4,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,1,5,5,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,5,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,3,1,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3 },
};

int arrowMouse2[10][16] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3 },
{ 1,0,0,0,0,0,0,0,0,0,0,1,3,3,3,3 },
{ 3,1,0,0,0,0,0,0,0,0,1,3,3,3,3,3 },
{ 3,3,1,0,0,0,0,0,0,1,3,3,3,3,3,3 },
{ 3,3,3,1,0,0,0,0,0,0,1,1,3,3,3,3 },
{ 3,3,3,3,1,0,0,0,0,0,0,0,1,1,3,3 },
{ 3,3,3,3,3,1,0,0,1,1,1,0,0,0,1,3 },
{ 3,3,3,3,3,3,1,0,1,3,3,1,0,0,1,3 },
{ 3,3,3,3,3,3,3,1,1,3,3,3,1,1,3,3 },
{ 3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3 },
};

int AddMouse[10][16]={
{ 3,3,3,3,3,3,1,1,1,1,1,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,0,0,0,1,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,0,0,0,1,3,3,3,3,3 },
{ 3,3,1,1,1,1,1,0,0,0,1,1,1,1,3,3 },
{ 3,3,1,0,0,0,0,0,0,0,0,0,0,1,3,3 },
{ 3,3,1,0,0,0,0,0,0,0,0,0,0,1,3,3 },
{ 3,3,1,1,1,1,1,0,0,0,1,1,1,1,3,3 },
{ 3,3,3,3,3,3,1,0,0,0,1,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,0,0,0,1,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,1,1,1,1,3,3,3,3,3 },
};

// int Mouse[10][16] = {
// 	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3 },
// 	{ 1,0,0,0,0,0,0,0,0,0,0,1,3,3,3,3 },
// 	{ 3,1,0,0,0,0,0,0,0,0,1,3,3,3,3,3 },
// 	{ 3,3,1,0,0,0,0,0,0,1,3,3,3,3,3,3 },
// 	{ 3,3,3,1,0,0,0,0,0,0,1,1,3,3,3,3 },
// 	{ 3,3,3,3,1,0,0,0,0,0,0,0,1,1,3,3 },
// 	{ 3,3,3,3,3,1,0,0,1,1,1,0,0,0,1,3 },
// 	{ 3,3,3,3,3,3,1,0,1,3,3,1,0,0,1,3 },
// 	{ 3,3,3,3,3,3,3,1,1,3,3,3,1,1,3,3 },
// 	{ 3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3 },
// };


//  {
// { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
// { 1,0,0,0,0,0,0,0,0,0,0,0,0,1,3,3 },
// { 3,1,0,0,0,0,0,0,0,0,0,0,1,3,3,3 },
// { 3,3,1,0,0,0,0,0,0,0,1,1,3,3,3,3 },
// { 3,3,3,1,0,0,0,0,0,1,3,3,3,3,3,3 },
// { 3,3,3,1,1,0,0,0,0,1,3,3,3,3,3,3 },
// { 3,3,3,3,3,1,0,0,0,1,3,3,3,3,3,3 },
// { 3,3,3,3,3,3,1,0,0,1,3,3,3,3,3,3 },
// { 3,3,3,3,3,3,3,1,0,1,3,3,3,3,3,3 },
// { 3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3 },
// };
int Mouse[10][16] =   {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3 },
{ 1,0,0,0,0,0,0,5,5,5,5,5,5,1,3,3 },
{ 3,1,0,0,0,0,0,5,5,5,5,5,1,3,3,3 },
{ 3,3,1,0,0,0,4,4,4,4,1,1,3,3,3,3 },
{ 3,3,3,1,0,0,5,4,6,1,3,3,3,3,3,3 },
{ 3,3,3,1,1,0,5,5,4,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,1,5,5,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,1,5,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,3,1,5,1,3,3,3,3,3,3 },
{ 3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3 },
};
int MouseSave[10][16] = {0};


/*markΪ0����Ϊ��ͷ���??,markΪ1����Ϊ�Ӻ����??*/
void setMouseShape(int mark,int mx,int my)
{
	int i;
	int j;


	if (mark == 0)
	{
		for(i=0;i<10;i++)
			for (j = 0;j < 16;j++)
				Mouse[i][j] = arrowMouse[i][j];
	}
	else if (mark == 1)
	{
		for (i = 0;i<10;i++)
			for (j = 0;j < 16;j++)
				Mouse[i][j] = AddMouse[i][j];
	}
	else
	{
		printf("MouseShape doesn't exit!");
		//getchar();
		exit(1);
	}
	mousehide(mx,my);
	cursor(mx, my);
}


void cursor(int x, int y)       //�����??//��Ⱦ������?
{
	int i, j;
	for (i = 0;i<10;i++)
		for (j = 0;j<16;j++)
		{
			if (Mouse[i][j] == 0)
				putpixel(x + i, y + j, WHITE);
			else if (Mouse[i][j] == 1)
				putpixel(x + i, y + j, DARKGRAY);
			else if (Mouse[i][j] == 4)
				putpixel(x + i, y + j, YELLOW);
			else if (Mouse[i][j] == 5)
				putpixel(x + i, y + j, LIGHTBLUE);
			else if (Mouse[i][j] == 6)
				putpixel(x + i, y + j, LIGHTMAGENTA);
		}
}


void getMousebk(int x, int y)//�洢��걳���ͼ��//�����λ��?1?7���ڶ�ά������?1?7?
{
	int i, j;
	for(i=0;i<10;i++)
		for(j=0;j<16;j++)
				MouseSave[i][j] = getpixel(x + i, y + j);
}


void mousehide(int x, int y)//����MouseSave����������
{
	int i, j;
	for (i = 0;i<10;i++)
		for (j = 0;j<16;j++)
		{
			putpixel(x + i, y + j, MouseSave[i][j]);
		}
}

int init(int xmi, int xma, int ymi, int yma)  //�������ʼ������??
{
	int retcode;
	regs.x.ax = 0;
	int86(51, &regs, &regs);
	retcode = regs.x.ax;
	if (retcode == 0)
		return 0;
	regs.x.ax = 7;
	regs.x.cx = xmi;
	regs.x.dx = xma;
	int86(51, &regs, &regs);
	regs.x.ax = 8;
	regs.x.cx = ymi;
	regs.x.dx = yma;
	int86(51, &regs, &regs);
	return retcode;
}
void mouseInit(int *mx,int *my, int *mbutt)
{

	if (init(2, 638, 8, 477) == 0)
	{
		closegraph();
		printf("Mouse or Mouse Driver Absent,Please Install");
		delay(5000);
		exit(1);
	}

	*mx = 3;
	*my = 460;
	*mbutt = 0;

	getMousebk(*mx, *my);
	cursor(*mx, *my);

}


int read(int *mx, int *my, int *mbutt)      //��ȡ����λ��
{
	static int mark = 0;  //�������ɿ���־
	int xx0 = *mx, yy0 = *my, buto = *mbutt;
	int xnew, ynew;
	do
	{
		
		regs.x.ax = 3;
		int86(51, &regs, &regs);

		xnew = regs.x.cx;
		ynew = regs.x.dx;
		if (mark == 0 && regs.x.bx != 0)
		{
			mark = 1;
			//delay(10);
			if(regs.x.bx != 0)*mbutt = regs.x.bx;			
		}
		else if (regs.x.bx == 0)
		{
			mark = 0;
			*mbutt = 0;
		}
		else *mbutt = 0;
		

	} while (xnew == xx0&&ynew == yy0&&*mbutt == buto);
	*mx = xnew;
	*my = ynew;
	if (*mbutt)
	{
		*mx = xnew;
		*my = ynew;
		return -1;
	}
	else
	{
		*mx = xnew;
		*my = ynew;
		return 1;
	}
}

void newxy(int *mx, int *my, int *mbutt)    //���µ�λ�ô������??
{
	//static int i = 0;
	int ch, xx0 = *mx, yy0 = *my;
	int xm, ym;


	read(&xm, &ym, mbutt);


	if (xm != xx0 || ym != yy0)
	{
		mousehide(xx0, yy0);
		getMousebk(xm, ym);
		cursor(xm, ym);
		*mx = xm;
		*my = ym;
	}
}

void backgroundChange(int mx, int my,int x1,int y1,int x2,int y2)
{
	int i, j;
	int mark = 0;

	for(i=0;i<10;i++)
		for (j = 0;j < 16;j++)
		{
			if (mx + i >= x1&&mx + i <= x2&&my + j >= y1&&my + j <= y2)
			{
				MouseSave[i][j] = getpixel(mx + i, my + j);
				mark = 1;
			}
		}
	if (mark == 1)
	{
		mousehide(mx,my);
		getMousebk(mx, my);
		cursor(mx, my);
	}
}

void AddFrame(int mx, int my, int x1, int y1, int x2, int y2,int color)
{
	int i, j;
	struct linesettingstype  lineinfo;
	setcolor(color);
	rectangle(x1, y1, x2, y2);

	getlinesettings(&lineinfo);

	if (lineinfo.thickness == 3)
	{
		for (i = 0;i < 10;i++)
			for (j = 0;j < 16;j++)
			{
				if (mx + i <= x2&&mx + i >= x1&&(my + j == y1 || my + j == y2))
					MouseSave[i][j] = getpixel(mx + i, my + j);
				if (my + j <= y2&&my + j >= y1&&mx + i == x1 || mx + i == x2)
					MouseSave[i][j] = getpixel(mx + i, my + j);

				if (mx + i <= x2&&mx + i >= x1&&(my + j == y1 + 1 || my + j == y2 + 1))
					MouseSave[i][j] = getpixel(mx + i, my + j);
				if (my + j <= y2&&my + j >= y1&&(mx + i == x1 + 1 || mx + i == x2 + 1))
					MouseSave[i][j] = getpixel(mx + i, my + j);

				if (mx + i <= x2&&mx + i >= x1&&(my + j == y1 - 1 || my + j == y2 - 1))
					MouseSave[i][j] = getpixel(mx + i, my + j);
				if (my + j <= y2&&my + j >= y1&&(mx + i == x1 - 1 || mx + i == x2 - 1))
					MouseSave[i][j] = getpixel(mx + i, my + j);
			}
	}
	else if (lineinfo.thickness == 1)
	{
		for (i = 0;i < 10;i++)
			for (j = 0;j < 16;j++)
			{
				if (mx + i <= x2&&mx + i >= x1&&(my + j == y1 || my + j == y2))
					MouseSave[i][j] = getpixel(mx + i, my + j);
				if (my + j <= y2&&my + j >= y1&&(mx + i == x1 || mx + i == x2))
					MouseSave[i][j] = getpixel(mx + i, my + j);
			}
	}
}