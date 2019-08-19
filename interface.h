#ifndef _interface_h
#define _interface_h

#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"
void Drawloginscreen_c(setuser *person,int *judge,setuser *head);//开始界面函数
void Btn_change_manager_c();
void Btn_change_user_c();
void click_user_c(int color);
void click_pass_c(int color);
void click_limit_c(int color);
void clear_effect_c(int manager);
void Drawplane();//画飞机函数
void DrawControlSystem_c(setuser *person,int *judge);//管理员调控中心函数
#endif