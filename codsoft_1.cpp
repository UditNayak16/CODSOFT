#include<iostream>
#include<ctime>
using namespace std;
int main(){
    cout<<"WELCOME TO THE NUMBER GUESSING GAME"<<endl<<endl;
    cout<<"Please enter numbers between 1 to 100"<<endl;
    srand(time(0));
    int randomNuber=(rand()%(100-1))+1;
    int guess;
    int leftchance=10;
    
    for(int i=0;i<=9;i++){
        cout<<"Enter the number: ";
        cin>>guess;
        if(guess>100){
            cout<<"Please enter a valid number"<<endl;
            break;
        }
        if(guess==randomNuber){
            cout<<"Congratulation!!!!  You guess the correct number"<<endl;
            break;
        }     
        else if(guess>randomNuber){
            cout<<guess<<" is greater than the random number"<<endl;
            cout<<leftchance-1<<" chances left"<<endl;
        } 
        else{
            cout<<guess<<" is smaller than the random number"<<endl;
            cout<<leftchance-1<<" chances left"<<endl;
        }
        leftchance--;
        if(leftchance==0){
            cout<<endl<<"Sorry!! You lost......."<<endl;
            cout<<"The random number was "<<randomNuber;
        }
    }
}