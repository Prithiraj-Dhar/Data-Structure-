#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int val;
  Node *next;
  
//constructor 
  Node(int val){
    this->val=val;
    this->next=NULL;
  }
};
void insert_at_head(Node* &head, Node* &tail,int val){
    Node* newnode = new Node(val);
      if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;

     
}

void insert_tail_optimize(Node* &head,Node* &tail,int val){
  Node* newnode = new Node(val);
  if(head==NULL){
    head=newnode;
    tail=newnode;
    return;
  }
  tail->next=newnode;
  tail=newnode;
}
void insert_any_pos(Node* &head,int idx,int val){
  Node* newnode = new Node(val);
  Node* temp = head;
  for(int i=1;i<idx;i++){
    temp = temp->next;
  }
  newnode->next = temp->next;
  temp->next = newnode;

}

void linked_list_print(Node* &head){
      Node *temp=head;
  while(temp!=NULL){
    cout<<temp->val<<endl;
    temp=temp->next;

  }
}

int size(Node* &head){
    Node* temp = head;
   int cnt=0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
  return cnt;  
}  
void reverse_print(Node* temp){
  if(temp==NULL){
    return;
  }

  reverse_print(temp->next);
  cout<<temp->val<<endl;
}
void reverse_linked_list(Node* &head,Node* &tail,Node* temp){
  if(temp->next==NULL){
    head = temp;
    return;
  }

  reverse_linked_list(head,tail,temp->next);
  temp->next->next = temp;
  temp->next = NULL;
  tail = temp;
  
}
void delete_at_head(Node* &head){
  Node* deletenote = NULL;
  head = head->next;
  delete deletenote;
    if(head==NULL){
    tail = NULL;
  }
}
void delete_at_any_pos(Node* &head,int idx){
  Node* temp = head;
  for(int i=1;i<idx;i++){
    temp=temp->next;
  }
  Node* deletenode = temp->next;
  temp->next = deletenode->next;
  delete deletenode;
}
void delete_at_tail(Node* &head,Node* &tail,int idx){
  Node* temp = head;
  for(int i=1;i<idx;i++){
    temp=temp->next;
  }
  Node* deletenode = temp->next;
  temp->next = deletenode->next;
  delete deletenode;
  tail = temp;
}
void sort_linked_list(Node* &head){
  for(Node* i = head;i->next != NULL;i = i->next){
    for(Node* j = i->next;j != NULL;j = j->next){
        if(i->val > j->val){
        swap(i->val,j->val);
        }
    }
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
      insert_tail_optimize(head,tail,val);
    }

    // sort_linked_list(head);
    // linked_list_print(head);
   // insert_at_head(head,tail,10);
   // linked_list_print(head);
    reverse_linked_list(head,tail,head);
    // linked_list_print(head);
    cout<<head->val<<" "<<tail->val;

    
return 0;
}