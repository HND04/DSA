#include <iostream>
using namespace std;
class Stack
{   
    int n,top=-1,arr[20],data;
    public:
    Stack(){
    cout<<"enter stack size:"<<endl;
    cin>>n;
    }
    void push(){
        cout<<"enter data to add to stack:"<<endl;
        cin>>data;
        if (top>=n-1){
            cout<<"stack full";
        }
        else{
            top++;
            arr[top]=data;
            cout<<arr[0];
        }
    }
    void pop(){
        if (top-1){
            cout<<"stack empty\n";
        }
        else{
            int dataout=arr[top];
            top--;
            cout<<"poped";
        }

    }
    void stop(){
        if (top==n-1){
            cout<<"empty\n";
        }
        else{
            int dataout=arr[top];
            cout<<dataout<<endl;
        }
    }
    bool isempty(){
        if (top<=-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isfull(){
        if (top>=n-1){
            return true;
        }
        else{
            return false;
        }
    }
    void dis(){
        if (top>-1){
            for (int i=top;i>0;i--){
                cout<<endl<<arr[i]<<endl;
            }
        }
        else{
            cout<<"empty\n";
        
        }
    }

    
};
int main(){
    int choice;
    Stack s;
    do{
     cout<<"1.push\n2.pop\n3.stop\n4.isemp\n5.isfull\n6.disp\n";
     cout<<"enter an choice";
     cin>>choice;
     
     switch (choice)
     {
     case 1:
        s.push(); /* constant-expression */
        /* code */
        break;
     case 2:
        s.pop();
        break;
     case 3:
        s.stop();
        break;
     case 4:
        if(s.isempty()){
            cout<<"empty";
        }
        else{
            cout<<"not empty";
        }
        break;
     case 5:
        if (s.isfull()){
            cout<<"is full";
        }
        else{
            cout<<"not full";
        }
        break;

      case 6:
          s.dis();
          break;
     default:
        break;
     }
     }
     while(choice!=7);
}