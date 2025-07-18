#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1.ber kore ana
        Node *p = q.front();
        q.pop();

        // 2.node ke niye kaj kora
        int l, r;
        cin >> l >> r;
        Node *myleft, *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);

        p->left = myleft;
        p->right = myright;

        // 3.children ke push
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

int without_leaf_sum(Node* root){
    if(root == NULL)
    return 0;

    if(root->left == NULL && root->right == NULL)
    return 0;
    else root->val;

     int l = without_leaf_sum(root->left);
     int r = without_leaf_sum(root->right);
     return root->val + l + r;
}

void leaf_decending(Node* root,vector<int> &v){
    if(root == NULL)
    return;

    if(root->left == NULL && root->right == NULL)
    v.push_back(root->val);

    leaf_decending(root->left,v);
    leaf_decending(root->right,v);

}

int count_nodes(Node* root){
    if(root == NULL)
    return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l+r+1;
}

int max_height(Node* root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;

        int l=max_height(root->left);
        int r=max_height(root->right);
      return max(l,r)+1;

}

void lefter_node(Node *root)
{
    if (root->left)
        lefter_node(root->left);

    else if (root->right)
        lefter_node(root->right);

    cout << root->val << " ";
}

void righter_node(Node *root)
{
    cout << root->val << " ";
    if (root->right)
        righter_node(root->right);

    else if (root->left)
        righter_node(root->left);
}

int main()
{
    Node *root = input_tree();

    if(root->left == NULL && root->right == NULL)
        cout<<root->val;
    else if(root->left && root->right){
        lefter_node(root);
        righter_node(root->right);
    }
    else if(root->left){
        lefter_node(root);
    }
    else if(root->right){
        righter_node(root);
    }
    


    return 0;
}