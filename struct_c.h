#ifndef _struct_c_h
#define _struct_c_h
/*****************************陈俊玮*********************************/
/*用户型结构*/
typedef struct User
{
	char accounts[11];  //用户的账号
	char code[11];  //用户的密码 
	int money;  //用户余额
	unsigned long int spend;//用户消费
	struct User *next;  //指向下一个用户的指针
}setuser;
/*管理员型结构*/
typedef struct Manager
{
	char accounts[11];  //用户的账号
	char code[11];  //用户的密码 
	int class[5];  //管理员权限码
}setManager;
#endif