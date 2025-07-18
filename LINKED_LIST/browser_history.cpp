#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  string val;
  Node *next;
  Node* prev;

  Node(string val){
    this->val=val;
    this->next=NULL;
    this->prev = NULL;
  }
};


void insert_at_tail(Node* &head,Node* &tail,string val){
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

int main(){
  Node* head = NULL;
  Node* tail = NULL;

   string val;
   list<string> lst;


    while (true) {
        cin >> val;
        if (val == "end") {
            break;
        }
        insert_at_tail(head,tail,val);

    }
     int t;
    cin>>t;
    string s;
    Node* visit=NULL;
    while(cin>>s){

      if(s=="prev"){

        if(visit->prev!=NULL){
          visit=visit->prev;
          cout<<visit->val<<endl;
        }
        else{
          cout<<"Not Available"<<endl;
        }
        
      }
      else if(s=="next"){

        if(visit->next!=NULL){
          visit=visit->next;
          cout<<visit->val<<endl;
        }
        else{
          cout<<"Not Available"<<endl;
        }
       

      }
      else if(s=="visit"){

      }
      else{
        Node* tmp=head;
  
        while(true){
          if(s==tmp->val){
             visit=tmp;
             cout<<visit->val<<endl;
            break;
          }
          else{
            tmp=tmp->next;
          }
          if(tmp==NULL){
            cout<<"Not Available"<<endl;
            
            break;
          }
        }


      }
   

          
    }
        
    
 
    
return 0;
}