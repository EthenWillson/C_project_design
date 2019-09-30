#ifndef _struct_c_h
#define _struct_c_h
/*****************************陈俊玮*********************************/
/*用户型结构*/
typedef struct User
{
	char accounts[13];  //用户的账号
	char code[13];  //用户的密码 
	char class[6];  //管理员权限码,用户为00000
	char money[6];  //用户余额
	unsigned long int spend;//用户消费
	struct User *next;  //指向下一个用户的指针
}setuser;
/*管理员型结构*/
typedef struct Manager
{
	char accounts[13];  //用户的账号
	char code[13];  //用户的密码 
	char class[6];  //管理员权限码,用户为00000
	char money[6];  //用户余额
}setManager;
/*修改密码结构*/

typedef struct changePass
{
	char old[13];  //用户的原密码
	char new[13];  //用户的新密码
	char confirm[13];  //确认密码
}setChangePass;

typedef struct station{
    int x;//存放站点的x,y坐标
	int y;
	int radius;//存放站点的图上半径大小
    char station_name[20];
}station;//车站结构体

typedef struct line{
    int number;
    struct station station;
}setline;//线路结构体
#endif