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

/*距离三元组结构*/
typedef struct{
    float dx;
	float dy;
	float dz; 
}Triple_distance;//购票界面的坐标三元组，用于计算两站之间的距离

/*车站结构*/
typedef struct station{
    int x;//存放站点的x,y坐标
	int y;
	Triple_distance distance;//距离三元组结构体（原先是float）
    char station_name[20];//站名
	int simple_name;//站点的简称
}station;

/*线路结构*/
typedef struct line{
    int number;//线路编号
    struct station *station;
}setline;

/*包含地铁线以及车站的所有变量的超级结构体*/
typedef struct all{
    station line1[9];//车站结构数组，line1[0]未用
    station line2[10];//line2[0]未用
    station line4[9];//line4[0]未用
    setline station_line1;//线路结构体
    setline station_line2;
    setline station_line4;
}all_lines_stations;

//记录某辆车的相关信息
typedef struct train
{
	float x;
	float y;
	int k;//标志着进入第k个站与第k+1站之间
	int i;//标志着进入第几个位移量
	int Ti;//总共要多少位移
	int reverse;//0标志正向，1标志反向
	int count;//记录停车时间：0不停车
	int setDotSave[6][6];//列车保存点阵
	struct train *next;
}setTrain;

//记录一条线调度相关参数
typedef struct trainInfo
{
	setline *lineHead;//一条地铁线的指针
	setTrain *trainHead;//一条线上正向车的列表
	setTrain *rtrainHead;//一条线上逆向车的列表
	int speed;//速度
	int wait;//停站时间
	int goTime;//发车时间间隔
	int num;//车辆总数
	int safeInstance;//安全距离
	int stationNum;//站的总数
}setTrainInfo;




#endif