#include<bits/stdc++.h>
using namespace std;

void MultiSet(){
    //same as set but allows duplicates

    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);

    int cnt=ms.count(1);
    cout<<cnt<<endl;

    ms.erase(ms.find(1));//erases only one occurence of 1
    auto it1 = ms.find(1);
    auto it2 = next(it1, 2);   // safely move 2 steps forward
    ms.erase(it1, it2);


    ms.erase(1);//erases all occurences of 1's 

    for(int x:ms) cout<< x<<endl;

    //rest all functions same as set
}
int main(){
    MultiSet();
    return 0;
}