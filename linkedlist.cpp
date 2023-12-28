#include <iostream>
using namespace std;
struct node
{   int data;
    node *next;
};
struct header
{
    int count;
    node *head;
    node *pos;

};
class SLL{
    private:
        node *pnew,*ploc,*temp,*pred;
        header *plist;
    public:
    SLL(){
        plist= new header;
        plist->count=0;
        plist->head=NULL;
        plist->pos=NULL;
    }
    void insertion(int x){
        bool isdup=search(x);
        if (isdup){
            cout<<"duplicate elemetn"<<endl;
            return;
        }
        pnew=new node;
        if(pnew==NULL){
            cout<<"full\n";
            return;
        }
        pnew->data=x;
        if(pred==NULL){
            pnew->next=plist->head;
            plist->head=pnew;
            

        }
        else{
            pnew->next=pred->next;
            pred->next=pnew;
        }
        plist->count++;
    }
    void deletion(int x){
        if(plist->count==0){
            cout<<"empty sll\n";
        }
        bool present=search(x);
        if (!present){
            cout<<"element not found\n";
        }
        if(pred==NULL){
            plist->head=ploc->next;

        }
        else{
            pred->next=ploc->next;
        }
        plist->count--;
    }
    bool search(int element){
        pred=NULL;
        ploc=plist->head;
        while(ploc!=NULL && (ploc->data) <element ){
            pred=ploc;
            ploc=ploc->next;
        }
        if (ploc==NULL){
            return false;
        }
        else{
            if (ploc->data==element){
                return true;
            }
            else{
                return false;
            }
        }
    }
    void transversal(){
        if(isempty()){
            cout<<"its empty\n";
            return;
        }
        if(plist->pos==NULL){
            plist->pos=plist->head;
        }
        cout<<"elemets:"<<plist->pos->data<<endl;
        plist->pos=plist->pos->next;
        if (plist->pos==NULL){
            cout<<"end of list"<<endl;
            return;
        }
    }
    bool isempty(){
        if(plist->head==NULL){
            return true;
        }
        else
           return false;
    }
    void display(){
        cout<<"elelemts in the SLL are:\n";
        temp=plist->head;
        while(temp!= NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }

    }
    ~SLL()
        {
             temp=plist->head;
             while(temp!=NULL)
             {
                plist->head=temp->next;
                cout<<temp->data<<"is deleted"<<endl;
                delete temp;
                plist->count--;
                temp=plist->head;
             }
            delete plist;
        }
};

int main(){
    SLL s;
    int choice, data;
    
    do{
        cout<<"1.insertion\n2.deletion\n3.search\n4.transversal\n5.isempty\n6.display\n7.exit\n";
        cin>>choice;

        switch (choice)
    {
    case 1:
          cout<<"enter a data:"<<endl;
          cin>>data;
          s.insertion(data);
          break;

    case 2:
        cout<<"enter element to delete:"<<endl;
        cin>>data;
        s.deletion(data);
        break;
    case 3:
        cout<<"enter search elemetn:"<<endl;
        cin>>data;
        if(s.search(data)){
            cout<<"elemetn found at"<<endl;
        }
        else{
            cout<<"element not found"<<endl;
        }
        break;
    case 4:
        s.transversal();
        break;
    case 5:
        if(s.isempty()){
            cout<<"SLL is empty"<<endl;
        }
        else{
            cout<<"SLL is not empty"<<endl;
        }
        break;
    case 6:
        s.display();
        break;
    
    }
        
    }while(choice!=7);
}