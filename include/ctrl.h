#ifndef  _ctrl_h
#define  _ctrl_h

#include"common_c.h"

void drawControlScreen(setuser *person,int *judge,setuser *head,all_lines_stations *all,setTrainInfo *Info);
int otherEvent(int *mx,int *my,int *buttons);
void createTrain(setTrainInfo *Info,int reverse);
void deleteTrain(setTrain *before,setTrain *current);
int otherEvent(int *mx,int *my,int *buttons);
void changeDot(setTrainInfo *Info,station *line2);
void controlGoTime(setTrainInfo *Info,int *GotimeI,long int *accum,int *timeCycle,station *line2);
void changeStationPN(int x,int y,int bkcolor,int ccolor,station *currentStation);
void drawStationDetail(int x,int y,int bkcolor,int ccolor,station *currentStation);
void clickStation(int x,int y,station *sta,station **currentStation,int *mx,int *my);
void initTranInfo(setTrainInfo *Info,all_lines_stations *all);
void drawControlFrame(int x,int y,int *para);
void resetInfo(setTrainInfo *Info,all_lines_stations *all);


#endif