#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "player.h"
#include "math.h"
#include "draw.h"
class chessboard
{
    public:
        chessboard();
        ~chessboard();
        //find function of the position of the mouse
        bool checkPosition(int x,int y);
        bool checkRegretButton(int x,int y);
        bool restartButton(int x, int y);
        bool continueButton(int x, int y);
        // exchange turn
        void transTurn(player &temp);
        // judge the winner
        int judge_win();
        //initial the game
        void init(int i);
        void init_chessGrid();
        void player_set(player &temp,int i,int j);
        int set_win(int flag);
        //regret fuction
        void regret();
        //draw game info
        void draw_winner();
        void draw_player_info();
        void redraw();


    protected:
        int chessGrid[15][15];
        player a;
        player b;

    private:
};

#endif // CHESSBOARD_H
