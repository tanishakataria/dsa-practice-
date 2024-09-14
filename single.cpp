// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    // constructor 
    Node (int d){
        this->data = d;
        this->next = NULL;
    }
    // destructor 
    ~Node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"MEMORY IS FREE AT : "<<value<<endl;
    }
};
void insertathead(Node *&head , int d){ // insertion at front
    Node * temp = new Node (d);
    temp->next = head;
    head = temp;
}
// insertion at tail
void insertattail(Node * & tail , int d){
    Node * temp = new Node (d);
    if(tail){
    tail->next = temp;
    }
    tail = temp;
}
// print 
void print(Node * &head){
    Node * temp = head;
    while(temp!= NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
// insertion at middle
void insertatmiddle(Node * &head , Node * &tail , int position , int d){
    if(position == 1){ // insertion at first 
        insertathead(head , d);
        return ;
    }
    Node * temp = head;
    int cnt = 1;
    while(cnt<position - 1){ // middle and last
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertattail(tail , d);
        return;
    }
    Node * nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void deletenode(Node * & head , Node * & tail , int position ){
    if(position==1){ // first position delete 
        Node * temp = head;
        head = head ->next;
        temp->next  = NULL;
        delete temp;
    }
    else{
    Node * prev = NULL;
    Node * curr = head;
    int cnt = 1;
    while(cnt < position){
        prev = curr;
         curr = curr->next;
         cnt++;
    }
   prev->next = curr->next;
   delete curr;
}
}
void deletevalue(Node *&head , Node *& tail , int value){
    if(head == NULL){
        return;
    }
    if(head->data == value){
        Node * temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }
    
        temp->next = NULL;
        delete temp;
        return;
    }
    Node * prev= NULL;
    Node * curr = head;
    while(curr!=NULL && curr->data!=value){
        prev = curr;
        curr = curr->next;
    }
    if(curr== NULL){
        return;
    }
    prev->next = curr->next;
    if(curr->next == NULL){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}
int main(){
    Node * node1 = new Node(10);
    Node * head = node1;
    Node * tail = node1;
    print(head);
    
    cout<<"INSERTION AT FRONT : "<<endl;
    insertathead(head , 11);
    print(head);
    cout<<endl;
    
    cout<<"INSERTION AT TAIL : "<<endl;
    insertattail(tail , 12);
    print(head);
    cout<<endl;
    
    cout<<"INSERTION AT THE FIRST OF POSITION IN MIDDLE : "<<endl;
    insertatmiddle(head , tail , 1 , 9);
    print(head);
    cout<<endl;
    
    cout<<"INSERTION AT MIDDLE OF POSITION IN MIDDLE: "<<endl;
    insertatmiddle(head , tail , 3 , 14);
    print(head);
    cout<<endl;
    
    cout<<"INSERTION AT LAST OF POSITION IN MIDDLE : "<<endl;
    insertatmiddle(head  , tail , 6 ,15);
    print(head);
    cout<<endl;
    
    cout<<"DELETE FROM THE POSITION : "<<endl;
    deletenode(head , tail , 1);
    print(head);
    cout<<endl;
    
    cout<<"DELETE FROM THE VALUE : "<<endl;
    deletevalue(head , tail , 12);
    print(head);
    cout<<endl;
    
    return 0;
    
}
