#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int val;
  Node *next;
  Node* prev;

  Node(int val){
    this->val=val;
    this->next=NULL;
    this->prev=NULL;
  }
};
void insert_at_head(Node* &head,Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
   
}
void insert_at_anypos(Node* head,int idx,int val){
    Node* newnode = new Node(val);
    Node* temp =head;
    for(int i=1;i<idx;i++){
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

}
void insert_at_tail(Node* &head,Node* &tail,int val){
  Node* newnode = new Node(val);
  if(head==NULL){
    head=newnode;
    tail=newnode;
    return;
  }
  tail->next=newnode;
  newnode->prev=tail;
  tail=newnode;
}
void delete_at_head(Node* &head,Node* &tail){
  Node* deletenote = NULL;
  head = head->next;
  delete deletenote;
  if(head==NULL){
    tail = NULL;
    return;
  }
  head->prev = NULL;
}
void delete_at_anypos(Node* head,int idx){
   Node* temp = head;
    for(int i=1;i<idx;i++){
      temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = deletenode->next;
    temp->next->prev = temp;
    delete deletenode;
}
void delete_at_tail(Node* &head,Node* &tail){
  Node* deletenote = NULL;
  tail = tail->prev;
  delete deletenote;
  if(tail==NULL){
    head = NULL;
    return;
  }
  tail->next = NULL;
}
void print_forward(Node* &head){
      Node *temp=head;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
void print_backward(Node* &tail){
      Node *temp=tail;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->prev;
  }
  cout<<endl;
}
void reverse_linked_list(Node* head,Node* tail){
  for(Node *i=head,*j=tail; i!=j && i->prev!=j; i=i->next,j=j->prev){
     swap(i->val,j->val);
   }
}
void palindrome(Node* &head,Node* &tail,int val){
  int flag=1;
  for(Node *i=head,*j=tail; i!=j && i->prev!=j; i=i->next,j=j->prev){
     if(i->val!=j->val){
      flag=0;
      break;
     }
   }
   if(flag==1){
    cout<<"YES";
   }
   else{
    cout<<"NO";
   }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;

     while(true){
      cin>>val;
      if(val==-1){
        break;
      }
      insert_at_tail(head,tail,val);
    }
   

    
    //print_backward(tail);
    //insert_at_head(head,tail,100);
    //insert_at_tail(head,tail,200);
    //insert_at_anypos(head,2,500);
    //delete_at_head(head,tail);
    //delete_at_tail(head,tail);
    //delete_at_anypos(head,1);
   

    reverse_linked_list(head,tail);
    print_forward(head);


return 0;
}