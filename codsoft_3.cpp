#include<iostream>
using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player=1,position=0;

void introduction(){
    cout<<"Welcome to TIC-TAC-TOE"<<endl<<endl;
    cout<<"Player 1) X"<<endl<<"Player 2) O"<<endl<<endl;
    cout<<"  1  |  2  |  3  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  4  |  5  |  6  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  7  |  8  |  9  "<<endl;
    cout<<"     |     |     "<<endl;
}


bool iswinner(){
    bool winner=false;
    if((board[0]==board[1] && board[1]==board[2] && board[0]!=" ")){
        winner=true;
    }
    else if((board[3]==board[4] && board[4]==board[5] && board[3]!=" ")){
        winner=true;
    }
    else if((board[6]==board[7] && board[7]==board[8] && board[6]!=" ")){
        winner=true;
    }
    else if((board[0]==board[3] && board[3]==board[6] && board[0]!=" ")){
        winner=true;
    }
    else if((board[1]==board[4] && board[4]==board[7] && board[1]!=" ")){
        winner=true;
    }
    else if((board[2]==board[5] && board[5]==board[8] && board[2]!=" ")){
        winner=true;
    }
    else if((board[0]==board[4] && board[4]==board[8] && board[0]!=" ")){
        winner=true;
    }
    else if((board[2]==board[4] && board[4]==board[6] && board[2]!=" ")){
        winner=true;
    }
    return winner;
}


bool isfilled(){
    bool filled=true;
    for(int i=0;i<9;i++){
        if(board[i]==" "){
            filled=false;
        }
    }
    return filled;
}

void tic_tac_toe(){
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  "<<endl;
    cout<<"     |     |     "<<endl<<endl;
}

void inputPosition(){
    cout<<"Player "<<player<<"'s turn:";
	while(!(cin>>position))
	{
		cout<<"Please enter a valid number between (1-9)"<<endl;
		cin.clear();  
    	cin.ignore();  
	}
	cout<<endl;
	
	while (board[position -1] != " "){
    cout<<"Oops, that position is already filled\nTry again\n";
    cout << "Player " << player << "'s Turn (Enter 1-9): ";
    cin>>position;
    cout<<"\n";
}
}

void afterChance(){
    if(player%2==1){
        board[position-1]='X';
    }
    else{
        board[position-1]='O';
    }
}

void changeChance(){
    if(player==1){
        player++;
    }
    else{
        player--;
    }
}

void turnChange(){
    while(!iswinner() && !isfilled()){
        inputPosition();
        afterChance();
        changeChance();
        tic_tac_toe();
    }
}

void endgame(){
    if(iswinner()){
        cout<<"Congrats You are the Winner"<<endl;
    }

    else if(isfilled()){
        cout<<"Draw"<<endl;
    }
}

void playagain(){
    char choice;
    cout<<endl<<"Do you like to play again?"<<endl<<"1. YES"<<endl<<"2. NO"<<endl;
    cin>>choice;

    if(choice=='1'){
        for(int i=0;i<9;i++){
            board[i]=" ";
        }
        player=1;
        turnChange();
        endgame();
        playagain();
    }
    else{
        cout<<"Thanks for playing"<<endl;
    }
    cout<<endl;
}
int main(){
    introduction();
	turnChange();
	endgame();
    playagain();
	return 0;
}