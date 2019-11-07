#ifndef _face_h
#define _face_h

#include"struct_c.h"
#include"common_c.h"
void Drawloginscreen_c(setuser *person,int *judge,setuser *head);//开始界面函数
void Btn_change_manager_c(void);
void Btn_change_user_c(void);
void click_user_c(int color);
void click_pass_c(int color);
void click_limit_c(int color);
void clear_effect_c(int manager);
void failConfirm_c(int sign);
void Drawplane(void);//画飞机函数
void DrawControlSystem_c(setuser *person,int *judge);//管理员调控中心界面函数
void DrawPersonalCenter_c(setuser *person,int *judge);//个人中心界面
void drawSignal(int x,int y,int r);
#endif