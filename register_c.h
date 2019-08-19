#ifndef _register_c_h
#define _register_c_h

#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"

void register_c(setManager managertemp);
int turnTo_c(setuser *person,int direct);
void login_c(setManager managertemp,setuser *head,setuser *person);//登陆函数
void createuserlist_c(setuser *head);//创建用户链表
void freeuserlist_c(setuser **head);//释放用户链表

#endif