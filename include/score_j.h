#ifndef _score_j_h
#define _score_j_h
#include"struct_c.h"
void DrawBag(int x,int y,int lcolor);
void DrawTrolly(int x,int y,int lcolor);
void DrawMineGFrame(int x,int y,int bkcolor,int lcolor);
void DrawStoreFrame(int x,int y,int bkcolor,int lcolor);
void DrawApple_c(int x,int y);
void DrawAppleFrame(int x,int y,int bkcolor,int ccolor);
void DrawPlaneFrame(int x,int y,int bkcolor,int ccolor);
void DrawMyChangeScreen(setuser* person,int *judge);
void DrawStoreScreen(setuser* person,int *judge,setuser* head);
void DrawscoreScreen_j(setuser* person,int *judge);

#endif