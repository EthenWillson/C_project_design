#ifndef _reg_h
#define _reg_h

#include"struct_c.h"
#include"common_c.h"

void register_c(setManager managertemp,setuser *head);
int turnTo_c(setuser *person,int direct);
int login_c(setManager managertemp,setuser *head,setuser *person);//登陆函数
void createuserlist_c(setuser *head);//创建用户链表
void freeuserlist_c(setuser **head);//释放用户链表
void changeGoods_c(setuser *head,setuser *person);
int changePass_c(setChangePass *managerTemp,char *accounts,setuser *head);

#endif