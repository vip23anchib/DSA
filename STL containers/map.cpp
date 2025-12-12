#include<bits/stdc++.h>
using namespace std;

void Maps(){
    map<int, int> mpp;
    map<pair<int,int>,int> mpp;
    map<int, pair<int,int>> mpp;

    mpp[1]=2;
    mpp.insert({2,3});
    mpp.emplace(4,2);
    
    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mpp[1]<<endl;
    cout<<mpp[4]<<endl;

    auto it1 =mpp.find(2);
    cout<<it1->first<<" " << it1->second<<endl;

    auto it3=mpp.find(5); //not present so returns mpp.end()

    auto it4=mpp.lower_bound(2);
    cout<<it4->first<<it4->second<<endl;

    // multi map can have duplicate keys
    //unordered map has unsorted unique keys

    }


