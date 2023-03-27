#ifndef PLAYER_H
#define PLAYER_H


class player
{
    public:
        player(int first_turn);
        ~player();
        void set_move(int r,int c);
        void init();
        void init_history_set();//set for regret
        int& get_turn();
        int& get_win();
        int& getHistory_set_r(int n);
        int& getHistory_set_c(int n);
        int& getTotalChessNum();
        int& get_winTimes();

    protected:
        int TotalChessNum;
        int history_set[2][256];
        int win;
        int turn;
        int winTimes;


    private:



};

#endif // PLAYER_H
