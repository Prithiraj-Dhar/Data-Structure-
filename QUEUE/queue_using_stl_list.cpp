#include <bits/stdc++.h>
using namespace std;

class myqueue
{
public:
  list<int> l;
   int sz=0;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_front();
    }
    int front(){
        return l.front();
    }
    int back(){
        return l.back();
    }
    int size(){
        return l.size();
    }
    bool empty(){
        return l.empty();
    }
};
int main()
{
    myqueue mq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mq.push(x);
    }
    while(!mq.empty()){
        cout<<mq.front()<<endl;
        mq.pop();
    }

    return 0;
}