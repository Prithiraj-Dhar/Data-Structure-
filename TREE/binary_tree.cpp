#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int val;
  Node* left;
  Node* right;

  Node(int val){
    this->val=val;
    this->left=NULL;
    this->right=NULL;
  }
};
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void level_order(Node* root){
    if(root == NULL){
        cout<<"NO TREE";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        //1.ber kore ana
        Node* f=q.front();
        q.pop();
        //2.node ke niye kaj kora
        cout<<f->val<<" ";
        //3.children push
        if(f->left!=NULL)
        q.push(f->left);
        if(f->right!=NULL)
        q.push(f->right);
    }
}
Node* input_tree(){
    int val;
    cin>>val;
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        //1.ber kore ana
        Node* p = q.front();
        q.pop();

        //2.node ke niye kaj kora
        int l,r;
        cin>>l>>r;
        Node *myleft,*myright;
        if(l == -1) myleft = NULL;
        else myleft = new Node(l);
        if(r == -1) myright = NULL;
        else myright = new Node(r);

        p->left = myleft;
        p->right = myright;

        //3.children ke push
        if(p->left)
        q.push(p->left);
        if(p->right)
        q.push(p->right);
    }
    return root;
}

int count_nodes(Node* root){
    if(root == NULL)
    return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l+r+1;
}
int count_leaf_nodes(Node* root){
    if(root == NULL)
    return 0;
    if(root->left == NULL && root->right == NULL)
    return 1;
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l+r;
}

int sum_leaf_nodes_values(Node* root){
    if(root == NULL)
    return 0;
    if(root->left == NULL && root->right == NULL)
    return root->val;
    
    int l = sum_leaf_nodes_values(root->left);
    int r = sum_leaf_nodes_values(root->right);
    return l+r;
}

int max_height(Node* root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
        
        int l=max_height(root->left);
        int r=max_height(root->right);
      return max(l,r)+1;  

    
}
int main(){
    
    Node* root = input_tree();
    level_order(root);
    //level_order(root);

return 0;
}