#include "player.h"

player::player(int first_turn)
{

    init_history_set();
    win=0;
    winTimes=0;
    turn=first_turn;
    TotalChessNum=-1;
}

player::~player()
{

}

void player::init_history_set(){
    for (int i=0; i<2; i++){
        for (int j=0; j<256; j++){
            history_set[i][j]=-1;
        }
    }

}

void player::set_move(int r,int c){
    TotalChessNum++;
    history_set[0][TotalChessNum]=r;
    history_set[1][TotalChessNum]=c;

}
void player::init(){
    init_history_set();
    win=0;
    turn=0;
    TotalChessNum=-1;
}

int& player::get_turn(){
    return turn;
}
int& player::get_win(){
    return win;
}

int& player::getHistory_set_r(int n){
    return history_set[0][n];
}
int& player::getHistory_set_c(int n){
    return history_set[1][n];
}
int& player::getTotalChessNum(){
    return TotalChessNum;
}
int& player::get_winTimes(){
    return winTimes;
}
