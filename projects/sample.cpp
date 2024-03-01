#include <iostream>

using namespace std;

void horizontal(int board[3][3], int player){
    int mov1 = 0, mov2 = 0;
    int opp = 0;
    if (player == 1){
        opp = 2;
    }
    else{
        opp = 1;
    }

    for (int i = 0; i<3; i++){
        int count = 0;
        for (int j = 0; j<3; j++){
            if (board[i][j]==0){
                count++;
            }
            if (board[i][j]==0){
                mov1 = i;
                mov2 = j;
            }
            if (count == 2){
                board[mov1][mov2] = player;
            }
        }
    }
}

void vertical(int board[3][3], int player){
    int mov1 = 0, mov2 = 0;
    int opp = 0;
    if (player == 1){
        opp = 2;
    }
    else{
        opp = 1;
    }

    for (int i = 0; i<3; i++){
        int count = 0;
        for (int j = 0; j<3; j++){
            if (board[j][i]==0){
                count++;
            }
            if (board[j][i]==0){
                mov1 = j;
                mov2 = i;
            }
            if (count == 2){
                board[mov1][mov2] = player;
            }
        }
    }
}

void diagonal(int board[3][3], int player){
    int mov1 = 0;
    int opp = 0;
    if (player == 1){
        opp = 2;
    }
    else{
        opp = 1;
    }

    for (int i = 0; i<2; i++){
        int count = 0;
        if(i == 0){
            for (int j = 0; j<3; j++){
                if (board[j][j]==opp){
                    count++;
                }
                if (board[j][j]==0){
                    mov1 = j;
                }
                if (count==2){
                    board[mov1][mov1] = player;
                }
            }
        }
        if (i == 1){
            for (int j = 0; j<3; j++){
                if (board[j][2-j]==opp){
                    count++;
                }
                if (board[j][2-j]==0){
                    mov1 = j;
                }
                if (count==2){
                    board[mov1][2-mov1] = player;
                }
            }
        }
    }
}

int main(){

}