#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
struct header{
    int count;
    node *rear,*front;
};
class queueSLL{
    private:
        node *pnew,*temp;
        header *queue;
    public:
        queueSLL(){
            queue=new header;
            queue->rear=new node;
            queue->front=new node;
            queue->count=0;
            queue->rear=NULL;
            queue->front=NULL;
        }
        void enque(int x){
            pnew=new node;
            if (pnew==NULL){
                cout<<"memory is full\n";
                return;
            }
            pnew->data=x;
            pnew->next=NULL;
            if(queue->count==0){
                queue->front=pnew;
            }
            else{
            queue->rear->next=pnew;  
            }
            queue->rear=pnew;
            queue->count++;
            }
        void deque(){
            if(queue->count==0){
                cout<<"empty queue\n";
                return;
            }
            cout<<"element deleted:"<<queue->front->data;
            queue->front=queue->front->next;
            queue->count--;

        }
        void qfront(){
            if(queue->count==0){
                cout<<"empty queue\n";
                return;
            }
            cout<<"front element:"<<queue->front->data<<endl;
        }
        void qrear(){
             if(queue->count==0){
                cout<<"empty queue\n";
                return;
            }
            cout<<"rear element:"<<queue->rear->data<<endl;
        }
        void qempty(){
            if(queue->count==0){
                cout<<"empty queue\n";
                return;
            }
            else{
                cout<<"not empty"<<endl;
            }
        }
        void dis(){
            if(queue->count==0){
                cout<<"empty queue\n";
                return;
            }
            temp=queue->front;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
        ~queueSLL(){
            temp=queue->front;
            while(temp!=NULL){
                queue->front=temp->next;
                cout<<temp->data<<"is deleted"<<endl;
                delete temp;
                temp=queue->front;
            }
        }
};
int main(){
    queueSLL s;
    int choice,data;

     do{
     cout<<"1.enque\n2.deque\n3.qfront\n4.qrear\n5.qempty\n6.dis\n7.exit\n";
     cout<<"enter an choice";
     cin>>choice;
     
     switch (choice)
     {
     case 1:
        cout<<"enter data to insert:"<<endl;
        cin>>data;
        s.enque(data); 
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
          s.dis();
          break;
     }
     }
     while(choice!=7);
}

