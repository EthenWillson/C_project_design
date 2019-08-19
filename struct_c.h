#ifndef _struct_c_h
#define _struct_c_h
/*****************************陈俊玮*********************************/
/*用户型结构*/
typedef struct User
{
	char accounts[13];  //用户的账号
	char code[13];  //用户的密码 
	char class[6];  //管理员权限码,用户为00000
	int money;  //用户余额
	unsigned long int spend;//用户消费
	struct User *next;  //指向下一个用户的指针
}setuser;
/*管理员型结构*/
typedef struct Manager
{
	char accounts[13];  //用户的账号
	char code[13];  //用户的密码 
	char class[6];  //管理员权限码,用户为00000
}setManager;
#endif