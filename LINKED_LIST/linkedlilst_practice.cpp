#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
int count(Node *&head)
{
    Node *temp = head;
    int cnt=0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
     return cnt;
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

void duplicate_check(Node *temp){
    int f[105] = {0};
    while (temp != NULL){
        f[temp->val]++;
        temp = temp->next;
    }
    int flag = 0,cnt;
    for (int i = 1; i <= cnt; i++){
        if (f[i] > 1){
            flag = 1;
        }
    }
    if (flag == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

void insert_at_head(Node *&head,  Node* &tail,int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;

       if(tail == NULL){
      tail = newnode;
    }
}

void accending(Node* temp){
    int flag=1;
    while(temp->next!=NULL){
        if(temp->val<=temp->next->val){
            //flag=1;
        }
        else{
            flag=0;
        }
        temp=temp->next;
    }
    if(flag==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
void value_check(Node* &head){
  Node* temp = head;
  int flag=0,idx=0;
  int num=0;
  while(temp!=NULL){
    idx++;
    if(num==temp->val){
      flag=1;
      break;
    }
    temp=temp->next;
  }
  if(flag==1){
    cout<<idx-1<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
}
void val_equal_check(Node* head,Node* head2){
         Node* temp = head;
         Node* temp2=head2;
         int flag=1;
        while(temp != NULL){
        if(temp->val==temp2->val){
           flag=1;
        }
        else{
            flag=0;
            break;
        }
         temp=temp->next;
        temp2=temp2->next;


        }
}

void duplicate_erase(Node* head){   
    Node* temp = head;
    while(temp!=NULL){
          Node* temp2 = temp;    
        while(temp2->next!=NULL){
        if(temp->val==temp2->next->val){   
             Node* deletenode = temp2->next;
             temp2->next = deletenode->next;
             delete deletenode;
        }
        else{
          temp2=temp2->next;
        }
        }
        temp=temp->next;
    }
}
void max_min_check(Node* &head){
  Node* temp = head;
     int mx=0,mn=10000000,dif=0;
    while(temp!=NULL){
       
       mx = max(mx,temp->val);
       mn = min(mn,temp->val);
      temp = temp->next;
    }
    dif = mx - mn ;
    cout<<dif;
}
int main()
{
    
    Node *head = NULL;
    Node *tail = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val,flag = 1;
    
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail_optimize(head,tail,val);
    }

  
    if(count(head)!=count2(head2)){
        flag=0;
    }
    else{
       // val_check(head,head2);

         Node* temp = head;
         Node* temp2=head2;
        while(temp != NULL){
        if(temp->val==temp2->val){
           flag=1;
        }
        else{
            flag=0;
            break;
        }

        }

    }
    if(flag==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}