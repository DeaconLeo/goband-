#include "draw.h"
using namespace ege;

void draw_chessPiece(int r,int c,int color){
    ege_enable_aa(1);
    if(color==1){

        //setcolor(EGEACOLOR(0xFF, YELLOW));
        setfillcolor(EGEACOLOR(0xFF, WHITE));
        ege_fillellipse(40.0+c*35.0,40.0+r*35.0,30.0,30.0);
    }
    else{

        //setcolor(EGEACOLOR(0xFF, YELLOW));
        setfillcolor(EGEACOLOR(0xFF,BLACK ));
        ege_fillellipse(40.0+c*35.0,40.0+r*35.0,30.0,30.0);

    }

}


void showMousePosition(int x, int y){

	setcolor(BLACK);
	setfont(20, 0, "consolas");
	setbkmode(TRANSPARENT);
	xyprintf(250,15, "鼠标位置 x:%d y:%d",x,y);
}

PIMAGE imgbuf(){
    setbkcolor(WHITE);
    PIMAGE imgBuff = newimage(800, 600);
    ege_enable_aa(1);
    PIMAGE bk_img = newimage();
    PIMAGE bk_wood = newimage();
    getimage(bk_img, "backround.png",0,0);
    getimage(bk_wood, "backround_goband.png",0,0);
    putimage(imgBuff,0,0,bk_img);
    putimage(imgBuff,50,50,bk_wood);
    delimage(bk_img);
    delimage(bk_wood);
    setcolor(EGEACOLOR(0xFF, BLACK),imgBuff);
    setfillcolor(EGEACOLOR(0xFF, BLACK),imgBuff);
    setlinewidth(2.5,imgBuff);
    ege_rectangle(55,55,490,490,imgBuff);
    setlinewidth(2.0,imgBuff);
    for(int i=0;i<13;i++ ){
        ege_line(55,90+i*35,545,90+i*35,imgBuff);
        ege_line(90+i*35,55,90+i*35,545,imgBuff);
    }
    for(int i=0;i<3;i++ ){
        for(int j=0;j<3;j++ ){
            ege_fillellipse(155+i*140,155+j*140,10,10,imgBuff);
        }
    }
    setfillcolor(EGEACOLOR(0xFF, YELLOW),imgBuff);
    ege_fillrect(630,400,60,40,imgBuff);
    ege_fillrect(630,460,60,40,imgBuff);
    ege_fillrect(630,520,60,40,imgBuff);
    setcolor(GREEN,imgBuff);
	setfont(40, 0, "consolas");
	setbkmode(TRANSPARENT,imgBuff);
    outtextxy(645,413, "悔棋",imgBuff);
    outtextxy(645,473, "继续",imgBuff);
    outtextxy(645,533, "重开",imgBuff);
    return imgBuff;
    delete imgBuff;

}
