#include"control_c.h"
#include"common_c.h"
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
		if (*mx >= 585 && *mx <= 615 && *my >= 5&& *my <= 45)//�˳���ť����˳�
		{
			return 0;
		}
	}
	return 1;
}
/**********************************************************
Function:  drawControlScreen
Description��	������ҳ�棬ʵ�ֶ���
Attention:  ��
**********************************************************/
void drawControlScreen(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int i;//����ѭ������
    setTrainInfo Info[2];//��¼�����ߵ��ȵ���ز���
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();

	// //���Ƶ�����·









	
	while(1)
	{
		if(otherEvent(&mx,&my,&buttons)==0)
		{
			*judge=turnTo_c(person,2);
			return;
		}
	}
}