#include "chessboard.h"
using namespace ege;
chessboard::chessboard():a(1),b(0)
{
    init_chessGrid();

}

chessboard::~chessboard()
{

}

void chessboard::init_chessGrid(){
    for (int i=0; i<2; i++){
        for (int j=0; j<256; j++){
            chessGrid[i][j]=0;
        }
    }

}

bool chessboard::checkPosition(int x,int y){
    x -= 55;
    y -= 55;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(abs(y-i*35)<17&&abs(x-j*35)<17){
                if(chessGrid[i][j]!=0)
                    return 0;
                else if(a.get_turn()==1){
                    chessGrid[i][j]=1;
                    player_set(a,i,j);
                    return 1;

                }

                else if(b.get_turn()==1){
                    chessGrid[i][j]=2;
                    player_set(b,i,j);
                    return 1;
                }
                else
                    return 0;
            }
        }
    }
}

bool chessboard::checkRegretButton(int x,int y){
    if(x>630&&x<690&&y>400&&y<440){
        return 1;
    }
    else
        return 0;

}
bool chessboard::continueButton(int x, int y){
    if(x>630&&x<690&&y>460&&y<500){
        return 1;
    }
    else
        return 0;
}

bool chessboard::restartButton(int x, int y){
    if(x>630&&x<690&&y>520&&y<560){
        return 1;
    }
    else
        return 0;
}
void chessboard::transTurn(player &temp){
        if(temp.get_turn()==0)
            temp.get_turn()=1;
        else
            temp.get_turn()=0;
}

void chessboard::player_set(player &temp,int i,int j){
    transTurn(a);
    transTurn(b);
    temp.set_move(i,j);

}

void chessboard::redraw(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(chessGrid[i][j]==0){}
            else{
                draw_chessPiece(i,j,chessGrid[i][j]);
            }
        }
    }
}

int chessboard::judge_win(){
    int sum=1,flag=0;
    for(int r=0;r<15;r++){
        sum=1;
        for(int c=0;c<14;c++){

            if(chessGrid[r][c]==chessGrid[r][c+1]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[r][c]!=0){
                flag=chessGrid[r][c];//1 a 2 b
            }

        }
    }//水平方向
    for(int c=0;c<15;c++){
        sum=1;
        for(int r=0;r<14;r++){

            if(chessGrid[r][c]==chessGrid[r+1][c]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[r][c]!=0){
                flag=chessGrid[r][c];//1 a 2 b
            }

        }
    }//竖直方向

    for(int r=0;r<15;r++){
        sum=1;
        for(int c_left=0,rr=r;rr>0;c_left++,rr--){

            if(chessGrid[rr][c_left]==chessGrid[rr-1][c_left+1]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[rr][c_left]!=0){
                flag=chessGrid[rr][c_left];//1 a 2 b
            }
        }
        sum=1;
        for(int c_left=0,rr=r;rr<14;c_left++,rr++){

            if(chessGrid[rr][c_left]==chessGrid[rr+1][c_left+1]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[rr][c_left]!=0){
                flag=chessGrid[rr][c_left];//1 a 2 b
            }
        }
        sum=1;
        for(int c_right=14,rr=r;rr<14;c_right--,rr++){

            if(chessGrid[rr][c_right]==chessGrid[rr+1][c_right-1]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[rr][c_right]!=0){
                flag=chessGrid[rr][c_right];//1 a 2 b
            }

        }
        sum=1;
        for(int c_right=14,rr=r;rr>0;c_right--,rr--){

            if(chessGrid[rr][c_right]==chessGrid[rr-1][c_right-1]){
                sum++;
            }
            else{
                sum=1;
            }
            if(sum==5&&chessGrid[rr][c_right]!=0){
                flag=chessGrid[rr][c_right];//1 a 2 b
            }

        }
    }//左右斜方向

    return flag;

}

void chessboard::init(int i){
    init_chessGrid();
    a.init();
    b.init();
    a.get_turn()=1;
    if(i==1){
        a.get_winTimes()=0;
        b.get_winTimes()=0;
    }
    else{}

}
int chessboard::set_win(int flag){
    if(flag==1){
        a.get_win()=1;
        a.get_winTimes()++;
        return 1;
    }

    else if(flag==2){
        b.get_win()=1;
        b.get_winTimes()++;
        return 1;
    }

    else
        return 0;
}

void chessboard::regret(){
    if(b.getTotalChessNum()!=-1){
        if(a.get_turn()==1){
        chessGrid[b.getHistory_set_r(b.getTotalChessNum())][b.getHistory_set_c(b.getTotalChessNum())]=0;
        b.getHistory_set_r(b.getTotalChessNum())=-1;
        b.getHistory_set_c(b.getTotalChessNum())=-1;
        b.getTotalChessNum()--;
        }
        else{
        chessGrid[a.getHistory_set_r(a.getTotalChessNum())][a.getHistory_set_c(a.getTotalChessNum())]=0;
        a.getHistory_set_r(a.getTotalChessNum())=-1;
        a.getHistory_set_c(a.getTotalChessNum())=-1;
        a.getTotalChessNum()--;
        }
        transTurn(a);
        transTurn(b);
    }


}

void chessboard::draw_winner(){
    setcolor(RED);
	setfont(30, 0, "consolas");
	setbkmode(TRANSPARENT);
    if(a.get_win()==1)
        outtextxy(570,5, "胜利者为1号玩家");
    else
        outtextxy(570,5, "胜利者为2号玩家");
}

void chessboard::draw_player_info(){
    setfont(30, 0, "consolas");
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	outtextxy(600,100, "1 player");
	outtextxy(600,250, "2 player");
    setfillcolor(EGEACOLOR(0xFF, WHITE));
    ege_fillellipse(635,150,50.0,50.0);
    setfillcolor(EGEACOLOR(0xFF, BLACK));
    ege_fillellipse(635,300,50.0,50.0);
	PIMAGE arrow = newimage();
    getimage(arrow, "arrow.png");
    if(a.get_turn()==1)
        putimage_withalpha(NULL, arrow, 570, 107);
    else
        putimage_withalpha(NULL, arrow, 570, 258);
    delimage(arrow);
    xyprintf(580,40,"比分[ %d : %d ]",a.get_winTimes(),b.get_winTimes());
}
