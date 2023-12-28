#include <iostream>
using namespace std;
class queue{
    int n,front,rear,q[20],data;
    public:
      queue(){
         cout<<"enter q length:";
         cin>>n;
         front=-1;
         rear=-1;
      }
      void enque(){
        cout<<"enter data\n";
        cin>>data;
        if(rear==n-1){
            cout<<"q full";

        }
        else{
            if((front==-1)&&(rear==-1)){
                front++;
                rear++;
                q[rear]=data;
            }
            else{
            rear++;
            q[rear]=data;
            }
        }
      }
      void deque(){
        if (front==rear){
            cout<<"empty";
            front=-1;
            rear=-1;

        }
        else{
            int dout=q[front];
            front++;
            cout<<dout<<endl;
        }
      }
      void qfront(){
        if((front==-1)&&(rear==-1)){
            cout<<"empty";
        }
        else{
            int dout=q[front];
            cout<<dout<<endl;
        }
  
        }
        void qrear(){
            if((front==-1)&&(rear==-1)){
                cout<<"empty";

            }
            else{
                int dout=q[rear];
                cout<<dout<<endl;

            }
        }
        void qempty(){
            if ((front==-1)&&(rear==-1)){
                cout<<"qempty"<<endl;
            }
            else{
                cout<<"not empty"<<endl;
            }
        }
        void qfull(){
            if (rear==n-1){
                cout<<"full"<<endl;
            }
            else{
                cout<<"not full"<<endl;
            }
        }
        void dis(){
            if ((front==rear)){
                cout<<"empty";
            
            }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<q[i]<<endl;
                }
            }
        }
};
int main(){
    queue s;
    int choice;

     do{
     cout<<"1.enque\n2.deque\n3.qfront\n4.qrear\n5.qempty\n6.qfull\n7.dis\n";
     cout<<"enter an choice";
     cin>>choice;
     
     switch (choice)
     {
     case 1:
        s.enque(); /* constant-expression */
        /* code */
        break;
     case 2:
        s.deque();
        break;
     case 3:
        s.qfront();
        break;
     case 4:
        s.qrear();
        break;
     case 5:
        s.qempty();
        break;

      case 6:
          s.qfull();
          break;
      case 7:
         s.dis();
     default:
        break;
     }
     }
     while(choice!=8);
}
