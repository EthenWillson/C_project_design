#include"control_c.h"
#include"common_c.h"

void drawControlScreen(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int i;//����ѭ������
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();

	//���Ƶ�����·
	setbkcolor(BLACK);
	setlinestyle(0, 0, 3);
    setcolor(BROWN);
    outtextxy(28,76,"1");
    puthz(35,71,"����",16,16,BROWN);

    outtextxy(28,231,"2");
    puthz(35,226,"����",16,16,BROWN);

    outtextxy(28,386,"3");
    puthz(35,381,"����",16,16,BROWN);

    puthz(260,5,"���ȿ���",32,32,BROWN);

    setlinestyle(0, 0, 3);
    setcolor(YELLOW);
    //1���ߵ���·
    circle(80,80,8);
    circle(80,80,7);
    circle(136,80,8);
    circle(136,80,7);//x+56
    circle(192,80,8);
    circle(192,80,7);
    circle(248,80,8);
    circle(248,80,7);
    circle(304,80,8);
    circle(304,80,7);
    circle(360,80,8);
    circle(360,80,7);
    circle(416,80,8);
    circle(416,80,7);
    circle(472,80,8);
    circle(472,80,7);
    circle(528,80,7);
    circle(528,80,7);
    setcolor(GREEN);//x1+10,x2-10
    for(i=0;i<=7;i++)
    {
        line(90+56*i,80,126+56*i,80);
    }
    
    setcolor(YELLOW);
    //2���ߵ���·
    circle(80,235,8);
    circle(80,235,7);
    circle(150,235,8);
    circle(150,235,7);
    circle(220,235,8);
    circle(220,235,7);
    circle(290,235,8);
    circle(290,235,7);
    circle(360,235,8);
    circle(360,235,7);
    circle(430,235,8);
    circle(430,235,7);
    circle(500,235,8);
    circle(500,235,7);
    setcolor(GREEN);
    for(i=0;i<6;i++)
    {
        line(90+70*i,235,140+70*i,235);
    }

    puthz(72,245,"��",16,16,BROWN);
    puthz(72,263,"��",16,16,BROWN);
    puthz(72,281,"��",16,16,BROWN);
    puthz(142,245,"��",16,16,BROWN);
    puthz(142,263,"��",16,16,BROWN);
    puthz(142,281,"��",16,16,BROWN);
    puthz(142,299,"��",16,16,BROWN);
    puthz(212,245,"��",16,16,BROWN);
    puthz(212,263,"��",16,16,BROWN);
    puthz(212,281,"·",16,16,BROWN); 
    puthz(282,245,"��",16,16,BROWN);
    puthz(282,263,"��",16,16,BROWN);
    puthz(282,281,"��",16,16,BROWN);
    puthz(282,299,"��",16,16,BROWN);
    puthz(282,317,"��",16,16,BROWN);
    puthz(282,335,"ѧ",16,16,BROWN);
    

    setcolor(YELLOW);
    //3���ߵ���·
    circle(80,390,8);
    circle(80,390,7);
    circle(136,390,8);
    circle(136,390,7);//x+56
    circle(192,390,8);
    circle(192,390,7);
    circle(248,390,8);
    circle(248,390,7);
    circle(304,390,8);
    circle(304,390,7);
    circle(360,390,8);
    circle(360,390,7);
    circle(416,390,8);
    circle(416,390,7);
    circle(472,390,8);
    circle(472,390,7);
    circle(528,390,7);
    circle(528,390,7);
    setcolor(GREEN);
    for(i=0;i<=7;i++)
    {
        line(90+56*i,390,126+56*i,390);
    }

    line(198,88,284,227);
    line(296,243,410,382);








	
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45)//�˳���ť����˳�
			{
				*judge=turnTo_c(person,2);
				return;
			}
		}
	}
}