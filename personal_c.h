#ifndef _personal_c_h
#define _personal_c_h

#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"
void DrawBeautifulFrame_c();//漂亮的边框
void Drawxctubiaoone(int x, int y, int color);
void Drawxctubiaotwo(int x, int y, int color);
void Drawbuttons(int x, int y, int color);
void Drawxc_self( int x, int y, int color);//修改密码按钮
void Drawxc_auto( int x, int y, int color);//充值按钮
void returnBtn_c(int x,int y,int color);//返回按钮
void inputBoxGroup(int x, int y, int framecolor,int color);//绘制输入框体函数
void frameChange_c(int x1,int y1,int x2,int y2,int color);//输入框变色函数
// void DrawPersonalCenter_c(setuser *person,int *judge,setuser *head);//个人中心界面
// void changePasswordScreen_c(setuser *person,int *judge,setuser *head);//修改密码界面
void DrawPersonalCenter_c(setuser *person,int *judge);//个人中心界面
void changePasswordScreen_c(setuser *person,int *judge);//修改密码界面
#endif