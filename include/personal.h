#ifndef _personal_h
#define _personal_h

#include"struct_c.h"
#include"common_c.h"
void DrawBeautifulFrame_c(void);//Ư���ı߿�
void Drawxctubiaoone(int x, int y, int color);
void Drawxctubiaotwo(int x, int y, int color);
void Drawbuttons(int x, int y, int color);
void Drawxc_self( int x, int y, int color);//�޸����밴ť
void Drawxc_auto( int x, int y, int color);//��ֵ��ť
void returnBtn_c(int x,int y,int color);//���ذ�ť
void returnBtn_small_c(int x,int y,int color);//С���ذ�ť
void returnBtn_next_c(int x,int y,int color);//��һ��
void inputBoxGroup(int x, int y, int framecolor,int color);//����������庯��
void frameChange_c(int x1,int y1,int x2,int y2,int color);//������ɫ����
void changePasswordScreen_c(setuser *person,int *judge,setuser *head);//�޸��������
void PersonalCenter_c(setuser *person,int *judge);//�������Ľ���
#endif