// union of two SORTED arrays

#include<bits/stdc++.h>
using namespace std;

void union1(vector<int>& arr1, vector<int> & arr2){ // BRUTE FORCE using set
    set<int> st;
    for(int i=0;i<arr1.size();i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        st.insert(arr2[i]);
    }
    vector<int>unionArray(st.size());
    int i=0;
    for (auto it: st){
        unionArray[i]=it;
        i++;
    }
    cout<<"Union Array by brute force method: ";
    for(int x : unionArray){
        cout << x << " ";
    }
    cout << endl;
}

void union2(vector<int>& arr1, vector<int> & arr2){ // OPTIMAL using two pointers
    int n=arr1.size();
    int m=arr2.size();
    vector<int> unionArr;
    int i=0,j=0;
    while(i<n&& j<m){
        if (arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]) // to avoid duplicates
                unionArr.push_back(arr1[i]);
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]) 
                unionArr.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]) 
            unionArr.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]) 
            unionArr.push_back(arr2[j]);
        j++;
    }
    cout<<"Union Array by optimal method: ";
    for(int x : unionArr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {1,2,2,3,4,5};
    vector<int> arr2 = {2,3,5,6,7};
    union1(arr1,arr2);
    union2(arr1,arr2);
    return 0;
}
