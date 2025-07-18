#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    getline(cin,s);
    stringstream ss(s);
    string word;
    map<string,int> mp;
    while (ss >> word)
    {
        mp[word]++;
    }
    
      
    // map<string,int> mp;
    // mp["raj"]=5;
    // mp["babu"]=6;
    // mp["pri"]=7;
    //  for(auto it : mp){
    //         cout<<it.first<<" "<<it.second<<endl;
            
    //     }

    for(auto it = mp.begin(); it!=mp.end(); it++){ //O(NlogN)
        cout<<it->first<<" "<<it->second<<endl; // o(logN)
    }

    // if(mp.count("babu"))
    // cout<<"ache";
    // else cout<<"nai";
return 0;
}