#include<iostream>
using namespace std;
#include<string>

const int MaxNoOfTasks=1000;

struct Task{
    string description;
    bool IsDone;
};

int main(){
    Task tasks[MaxNoOfTasks];
    int numTasks=0;

    while (true){
        cout<<"1. Add Tasks"<<endl;
        cout<<"2. List Tasks"<<endl;
        cout<<"3. Mark Task as Done"<<endl;
        cout<<"4. Remove Task"<<endl;
        cout<<"5. Quit"<<endl;
        
        int choice;
        cin>>choice;

        if(choice==1){
            if(numTasks<MaxNoOfTasks){
                cout<<endl<<"Enter Task:";
                cin.ignore();
                getline(cin,tasks[numTasks].description);
                tasks[numTasks].IsDone=false;
                numTasks++;
                cout<<"Task Added"<<endl<<endl<<endl;
            }
            else{
                cout<<"Task List Full. Cannot add more tasks."<<endl<<endl<<endl;
            }
        }

        else if(choice==2){
            cout<<endl<<"Tasks:"<<endl;
            for(int i=0;i<numTasks;i++){
                cout<<(i+1)<<". ";
                if(tasks[i].IsDone){
                    cout<<"[X]";
                }
                else{
                    cout<<"[ ]";
                }
                cout<<tasks[i].description<<endl;
            }
            cout<<endl;
        }

        else if(choice==3){
            cout<<"Enter the task number to be marked done: ";
            int task_to_be_marked;
            cin>>task_to_be_marked;
            if(task_to_be_marked>0 && task_to_be_marked<=MaxNoOfTasks ){
                tasks[task_to_be_marked-1].IsDone=true;
                cout<<"Task Marked as Done"<<endl;
            }
            else{
                cout<<"Invalid Task Number"<<endl;
            }   
            cout<<"Tasks:"<<endl;
            for(int i=0;i<numTasks;i++){
                cout<<(i+1)<<". ";
                if(tasks[i].IsDone){
                    cout<<"[X]";
                }
                else{
                    cout<<"[ ]";
                }
                cout<<tasks[i].description<<endl;
            }
            cout<<endl;
        }

        else if(choice==4){
            cout<<"Enter the Task Number to be removed: ";
            int TaskRemove;
            cin>>TaskRemove;
            if(TaskRemove>0 && TaskRemove<=numTasks){
                for(int i=TaskRemove-1;i<numTasks-1;i++){
                    tasks[i]=tasks[i+1];
                }
                numTasks--;
                cout<<"Task Removed"<<endl;
            }
            else{
                cout<<"Invalid Task"<<endl;
            }
            cout<<"Tasks:"<<endl;
            for(int i=0;i<numTasks;i++){
                cout<<(i+1)<<". ";
                if(tasks[i].IsDone){
                    cout<<"[X]";
                }
                else{
                    cout<<"[ ]";
                }
                cout<<tasks[i].description<<endl;
            }
            cout<<endl;
        }

        else if(choice==5){
            cout<<endl<<"Goodbye!!!"<<endl;
            break;
        }
        
        else{
            cout<<"Invalid Number"<<endl;
        }

    }
    return 0;
}