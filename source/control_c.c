#include"control_c.h"
#include"common_c.h"
void otherEvent()//�����¼��������ĸ��º͵���¼���
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
		otherEvent();
	}
}