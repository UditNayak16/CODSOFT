#include<iostream>
using namespace std;
int main(){
    float num1, num2;
    char operation;
    float ans;
    cout<<"Simple Calculator"<<endl<<endl<<"Choose the Operation"<<endl<<"+ for Addition"<<endl<<"- for Subtraction"<<endl<<"* for Multiplication"<<endl<<"/ for Division"<<endl<<endl;
    cout<<"Enter Number 1: ";
    cin>>num1;
    cout<<"Choose Operation: ";
    cin>>operation;
    cout<<"Enter Number 2: ";
    cin>>num2;
    

    switch (operation)
    {
        case '+':
            ans=num1+num2;
            cout<<endl<<num1<<" + "<<num2<<" = "<<ans<<endl;
            break;

        case '-':
            ans=num1-num2;
            cout<<endl<<num1<<" - "<<num2<<" = "<<ans<<endl;
            break;

        case '*':
            ans=num1*num2;
            cout<<endl<<num1<<" * "<<num2<<" = "<<ans<<endl;
            break;

        case '/':
            if(num2!=0){
                ans=(float)num1/num2;
                cout<<endl<<num1<<" / "<<num2<<" = "<<ans<<endl;
            }
            else{
                cout<<endl<<"Error.... Division By Zero";
            }
            break;

        default:
            cout<<endl<<"Invalid Operation"<<endl;
            break;

    }
    return 0;
}