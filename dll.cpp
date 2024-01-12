#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
struct header{
    int count;
    node *front;
    node *rear;
};
class DLL{
    header *plist;
    node *pnew,*temp,*pred,*succ;
    public:
    DLL(){
        plist=new header;
        plist->count=0;
        plist->rear=NULL;
        plist->front=NULL;
    }
    void insertion(int x){
        pnew= new node;
        if(pnew==NULL){
            cout<<"memory is full\n";
            return;
        }
        bool found=search(x);
        if(found){
            cout<<"element is duplicate"<<endl;
            return;
        }
        pnew->data=x;
        if(pred==NULL){
            pnew->prev=NULL;
            pnew->next=plist->front;
            plist->front=pnew;
        }
        else{
            pred->next=pnew;
            pnew->next=succ;
            pnew->prev=pred;
        }
        if(succ==NULL){
            plist->rear=pnew;
        }
        else{
            succ->prev=pnew;
        }
        plist->count--;
    }
    void deletion(int x){
        bool found=search(x);
        if(plist->count==0){
            cout<<"empty list"<<endl;
            return;
        }
        if (!found){
            cout<<"element not found"<<endl;
            return;
        }
        temp=succ;
        if(pred==NULL){
            plist->front=succ->next;
        }
        else{
            pred->next=succ->next;
        }
        if(succ->next==NULL){
            plist->rear=pred;
    }
    else{
        succ->next->prev=pred;
    }
    delete temp;
    plist->count--;
    }
    bool search(int target)
        {
            pred=NULL;
            succ=plist->front;
            while(succ!=NULL && succ->data <target)
            {
                pred=succ;
                succ=succ->next;
            }
            if(succ==NULL)
            {
                return false;
            }
            else
            {
                if(succ->data==target)
                    return true;
                else 
                    return false;
            }
        }
       bool isempty()
        {
            if(plist->count==0)
                return true;
            else
                return false;
        }
        void displayFromFront()
        {
            if(isempty())
            {
                cout<<"List is empty";
                return;
            }
            temp=plist->front;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
        void displayFromRear()
        {
            if(isempty())
            {
                cout<<"List is empty";
                return;
            }
            temp=plist->rear;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->prev;
            }
        }
        ~DLL()
        {
             temp=plist->front;
             while(temp!=NULL)
             {
                plist->front=temp->next;
                cout<<temp->data<<"is deleted"<<endl;
                delete temp;
                plist->count--;
                temp=plist->front;
             }
            delete plist;
        }

};
int main()
{
    DLL s1;
    int choice,data;
    do{
			cout<<" 1.Insertion \n 2.Deletion \n 3.Search \n 4.isempty \n 5.Display from front \n 6.Display from rear \n 7.exit "<<endl;
			cout<<"Enter choice";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Enter Data to Enter:";
					cin>>data;
					s1.insertion(data);
					break;
				case 2:
					cout<<"Enter Data to Delete:";
                    cin>>data;
                    s1.deletion(data);
					break;
				case 3:
					cout<<"Enter Data to search:";
                    cin>>data;
                    if(s1.search(data))
                        cout<<"Data Present in the List"<<endl;
                    else
                        cout<<"Data not Found in the List"<<endl;
					break;
				case 4:
					if(s1.isempty())
						cout<<"Sll is empty"<<endl;
					else 
						cout<<"SLL is not empty"<<endl;
					break;
				case 5:
					s1.displayFromFront();
                    break;
				case 6:
					s1.displayFromRear();
					break;
				case 7:
					break;
				default:
					cout<<"Invalid choice"<<endl;
					break;

			}

		}while(choice!=7);
}