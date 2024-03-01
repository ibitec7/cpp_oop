#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class TicTacToe{
    private:

    int board[3][3];
    int status = 0;

    //TO CHECK IF PLAYER WINS IN LINE
    int in_line(int board[3][3]){

        for (int i=0; i<3; i++){
            bool con1 = (board[0][i]==board[1][i]) && (board[1][i]==board[2][i]) && (board[0][i]!=0);
            bool con2 = (board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][0]!=0);

            if (con1){
                return board[0][i];
            }
            else if (con2){
                return board[i][0];
            }
        }

        return 0;
    }

    //TO CHECK IF PLAYER WINS DIAGONALLY
    int diag(int board[3][3]){
        bool con1 = (board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && (board[0][0]!=0);
        bool con2 = (board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && (board[0][2]!=0);

        if (con1 || con2){
            return board[1][1];
        }
        else{
            return 0;
        }
    }

    //TO CHECK IF BOARD FILLED SO ITS DRAW
    bool filled(int board[3][3]){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }

    //TO CHECK OPPONENT WINNING HORIZONTALLY AND MOVE
    bool horizontal(int player){
        int mov1 = -1, mov2 = -1;
        int safe[2] = {0};
        int win[2] = {0};
        int opp = 0;
        if (player == 1){
            opp = 2;
        }
        else{
            opp = 1;
        }

        for (int i = 0; i<3; i++){
            int count = 0,count2 = 0;
            for (int j = 0; j<3; j++){
                if (board[i][j]==opp){
                    count++;
                }
                if (board[i][j]==player){
                    count2++;
                }
                if (board[i][j]==0){
                    mov1 = i;
                    mov2 = j;
                }
                if (count==2){
                    safe[0] = mov1;
                    safe[1] = mov2;
                }
                if (count2==2){
                    win[0] = mov1;
                    win[1] = mov2;
                }
            }
        }
        if (win[0]!=0){
            return move(player,win[0],win[1]);
        }
        else if (safe[1]!=0){
            return move(player,safe[0],safe[1]);
        }
        else{
            return false;
        }
    }

    //TO CHECK OPPONENT WINNING VERTICALLY AND MOVE
    bool vertical(int player){
        int mov1 = -1, mov2 = -1;
        int safe[2] = {0};
        int win[2] = {0};
        int opp = 0;
        if (player == 1){
            opp = 2;
        }
        else{
            opp = 1;
        }

        for (int i = 0; i<3; i++){
            int count = 0, count2 = 0;
            for (int j = 0; j<3; j++){
                if (board[j][i]==opp){
                    count++;
                }
                if (board[j][i]==player){
                    count2++;
                }
                if (board[j][i]==0){
                    mov1 = j;
                    mov2 = i;
                }
                if (count==2){
                    safe[0] = mov1;
                    safe[1] = mov2;
                }
                if (count2==2){
                    win[0] = mov1;
                    win[1] = mov2;
                }
            }
        }

        if (win[0]!=0){
            return move(player,win[0],win[1]);
        }
        else if (safe[1]!=0){
            return move(player,safe[0],safe[1]);
        }
        else{
            return false;
        }
    }

    //TO CHECK IF PLAYER WINNING DIAGONALLY AND MOVE
    bool diagonal(int player){
        int opp = 0;
        int safe[2] = {0};
        int win[2] = {0};
        if (player == 1){
            opp = 2;
        }
        else{
            opp = 1;
        }

        for (int i = 0; i<2; i++){
            int mov1 = -1;
            int count = 0,count2 = 0;
            if(i == 0){
                for (int j = 0; j<3; j++){
                    if (board[j][j]==opp){
                        count++;
                    }
                    if (board[j][j]==player){
                        count2++;
                    }
                    if (board[j][j]==0){
                        mov1 = j;
                    }
                    if (count==2){
                    safe[0] = mov1;
                    safe[1] = mov1;
                    }
                    if (count2==2){
                        win[0] = mov1;
                        win[1] = mov1;
                    }
                }
            }
            if (i == 1){
                for (int j = 0; j<3; j++){
                    if (board[j][2-j]==opp){
                        count++;
                    }
                    if (board[j][2-j]==player){
                        count2++;
                    }
                    if (board[j][2-j]==0){
                        mov1 = j;
                    }
                    if (count==2){
                    safe[0] = mov1;
                    safe[1] = 2 - mov1;
                    }
                    if (count2==2){
                        win[0] = mov1;
                        win[1] = 2 - mov1;
                    }
                }
            }
        }

        if (win[0]!=0){
            return move(player,win[0],win[1]);
        }
        else if (safe[1]!=0){
            return move(player,safe[0],safe[1]);
        }
        else{
            return false;
        }
    }

    char token(int player){
        if (player == 1){
            return 'X';
        }
        else if (player == 2){
            return 'O';
        }
        else{
            return ' ';
        }
    }
    
    public:

    TicTacToe(){

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                board[i][j]=0;
            }
        }

    }

    void clearBoard(){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                board[i][j]=0;
            }
        }
    }

    void to_string(){
        for (int i=0; i<3; i++){
            printf(" %c | %c | %c ",token(board[i][0]),token(board[i][1]),token(board[i][2]));
            cout<<endl;
            if (i<2){ 
                cout<<endl;
                cout<<"----------"<<endl;
            }
        }
    }

    int gameStatus(){

        if (in_line(board)!=0){
            status = in_line(board);
        }
        else if(diag(board)!=0){
            status = diag(board);
        }
        else if(filled(board)){
            status = 3;
        }
        else{
            status = 0;
        }

        return status;
    }

    bool move(int player, int row, int col){
        if (board[row][col] == 0){
            board[row][col] = player;
            return true;
        }
        else{
            return false;
        }
    }

    void autoMove(int player){
        srand(static_cast<int>(time(nullptr)));
        int row = rand() % 3;
        int col = rand() % 3;
        while (!(move(player,row,col))){
            row = rand() % 3;
            col = rand() % 3;
        }
        move(player,row,col);
    }

    void bot(int player){
        if (horizontal(player)){
            return;
        }
        else if (vertical(player)){
            return;
        }
        else if (diagonal(player)){
            return;
        }
        else{
            autoMove(player);
            return;
        }
    }

};

int main(){
    int row=0,col=0;
    TicTacToe game = TicTacToe();

    cout<<"WELCOME TO TICTACTOE!!! PRESS -1 TO EXIT"<<endl;
    cout<<"PLAYER 2 IS A BOT USING AUTOMOVE"<<endl;

    while (game.gameStatus()==0){
        cout<<"Player 1 move: enter row and column: ";
        cin>>row>>col;
        if (row==-1){
            cout<<endl;
            cout<<"EXITING....";
            return 0;
        }
        game.move(1,row,col);
        cout<<endl;
        game.to_string();

        if (game.gameStatus() != 0){
            break;
        }

        cout<<"Player 2 move: enter row and column: ";
        game.bot(2);
        if (row==-1){
            cout<<endl;
            cout<<"EXITING....";
            return 0;
        }
        cout<<endl;
        game.to_string();

        if (game.gameStatus() != 0){
            break;
        }

    }

    switch (game.gameStatus()){
    case 1:
        cout<<endl;
        cout<<"PLAYER 1 WINS !!!";
        break;
    
    case 2:
        cout<<endl;
        cout<<"PLAYER 2 WINS !!!";
        break;
    
    default:
        cout<<endl;
        cout<<"GAME IS A DRAW !!!";
        break;
    }
}