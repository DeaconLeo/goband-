#include <graphics.h>
#include <draw.h>
#include <chessboard.h>
using namespace ege;

void play(){
    chessboard chess_game;
    bool clickButton = false;
    bool regretButton = false;
    PIMAGE abc = imgbuf();
    mouse_msg msg= {0};
    for(; is_run(); delay_fps(60)){
        while (mousemsg()) {
			msg = getmouse();
			if(msg.is_left() && msg.is_down()){
			    clickButton = chess_game.checkPosition(msg.x, msg.y);
			    regretButton = chess_game.checkRegretButton(msg.x, msg.y);
			}
			if(msg.is_move()){
                putimage(0, 0, abc);
                chess_game.redraw();
                chess_game.draw_player_info();
                showMousePosition(msg.x, msg.y);
		    }
        }
        if(clickButton==true){
            cleardevice();
            putimage(0, 0, abc);
            chess_game.redraw();
            chess_game.draw_player_info();
            clickButton=false;
            if(chess_game.set_win(chess_game.judge_win())){
                chess_game.draw_winner();
                while(1){
                    msg=getmouse();
                    if(msg.is_left() && msg.is_down()){
                        if(chess_game.restartButton(msg.x, msg.y)||chess_game.continueButton(msg.x, msg.y)){
                            if(chess_game.restartButton(msg.x, msg.y)){
                                chess_game.init(1);
                                break;
                            }
                            else{
                                chess_game.init(2);
                                break;
                            }
                        }
                    }
                }
                putimage(0, 0, abc);
                chess_game.redraw();
            }
        }
        if(regretButton==true){
            chess_game.regret();
            cleardevice();
            putimage(0, 0, abc);
            chess_game.redraw();
            chess_game.draw_player_info();
            regretButton=false;
        }
    }
}

int main(){

    initgraph(800,600,0);
    setinitmode(INIT_RENDERMANUAL);
    setcaption("goband");
    play();
    getch();
    closegraph();
    return 0;
}
