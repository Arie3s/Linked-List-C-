/*
Author : Aries
*/
#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* nextNode;   
    Node(int d){
      value=d;
      nextNode=nullptr;
      }
};

class list{
    private:
        Node* Head;
		Node* temp;
		Node* Tail;
		int index=0;
    public:
        list(){
         Head=nullptr;
         Tail=Head;
         }
        void getTail(){
            temp=Head;
            while(temp->nextNode!=nullptr){
                temp=temp->nextNode;
            }
            Tail=temp;
        }  
        void addFirst(int d){
        	Node* temp=new Node(d);
        	temp->nextNode=Head;
        	Head=temp;
        	getTail();
        	cout<<"New Node added first!!!\n"<<endl;
          }
        void addLast(int d){
            getTail();
            temp=new Node(d);
            Tail->nextNode=temp;
            Tail=temp;
        }  
        void deleteFirst(){
            temp=Head;
            Head=Head->nextNode;
            delete temp;
            temp=nullptr;
            getTail();
            cout<<"First Node deleted!!!"<<endl;
        }    
        void deleteLast(){
            getTail();    
            temp=Head;
            while(temp->nextNode->nextNode!=nullptr){
               temp=temp->nextNode;
           }
           temp->nextNode=nullptr;
           Tail=temp;
        }
        Node* getIndex(int pos){
            temp=Head;
            while(temp->nextNode!=nullptr && pos!=0){
                temp=temp->nextNode;
                pos--;
            }
            return temp;
        }
        Node* getValue(int val){
            temp=Head;
            index=0;
            while(temp->nextNode!=nullptr && temp->value!=val){
                temp=temp->nextNode;
                index++;
            }
            return temp;
        }
        void Insert(int d,int pos){
            if(pos==0){
                addFirst(d);
                return;
            }
            temp=getIndex(pos-1);
            Node* newNode=new Node(d);
            newNode->nextNode=temp->nextNode;
            temp->nextNode=newNode;
        }
        void Delete(int pos){
            if(pos==0){
                deleteFirst();
                return;
            }
            temp=getIndex(pos-1);
            Node* current=temp->nextNode;
            temp->nextNode=current->nextNode;
            delete[] current;
            current=nullptr;
        }
        void DeleteVal(int val){
        	temp=getValue(val);
        	Delete(index);
        	
		}
        void view(){
            temp=Head;
            index=0;
            while(temp!=nullptr){
                cout<<"Index :"<<index<<" Value: "<<temp->value<<endl;
                temp=temp->nextNode;
                index++;
            }}
};
int main(){
    list mylist;
    mylist.addFirst(2);
    mylist.addFirst(3);
    mylist.addFirst(69);
    mylist.addFirst(4);
    mylist.addFirst(1);
    mylist.view();
    cout<<"After deleting tail node"<<endl;
    mylist.deleteLast();
    mylist.view();
    cout<<"insert at 3rd position"<<endl;
    mylist.Insert(7,0);
    mylist.view();
    mylist.addLast(11);
    mylist.addLast(22);
    cout<<endl<<"Before deletion"<<endl;
    mylist.view();
    cout<<endl<<"delete at 4th index"<<endl;
    mylist.Delete(4);
    mylist.view();
    cout<<endl<<"delete by value"<<endl;
    mylist.DeleteVal(69);
    mylist.view();
    return 0;
}