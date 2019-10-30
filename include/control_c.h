#ifndef  _control_c_h
#define  _control_c_h

#include"common_c.h"

void drawControlScreen(setuser *person,int *judge,setuser *head,all_lines_stations *all);
int otherEvent(int *mx,int *my,int *buttons);
void createTrain(setTrainInfo *Info,int reverse);
void deleteTrain(setTrain *before,setTrain *current);
int otherEvent(int *mx,int *my,int *buttons);
void changeDot(setTrainInfo *Info);
void controlGoTime(setTrainInfo *Info,int *GotimeI,long int *accum);
void changeStationPN(int x,int y,int bkcolor,int ccolor,station *currentStation);
void drawStationDetail(int x,int y,int bkcolor,int ccolor,station *currentStation);
void clickStation(int x,int y,station *sta,station **currentStation,int *mx,int *my);


#endif