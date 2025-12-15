// remove duplicates from sorted array 
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force using set O(NlogN)
void removeDuplicates(){
    vector<int> arr={1,1,2,2,3,4,4,5,5,5,6};
    set<int> st;
    for (int i=0; i<arr.size(); i++){
        st.insert(arr[i]);
    }

    int index=0;
    for (auto it:st){
        arr[index]=it;
        index++;
    }

    cout<<"Array after removing duplicates: ";
    for (int i=0; i<index; i++){
        cout<<arr[i]<<" ";
    }
}

//method 2: optimal approach using two pointers O(N)
void removeDuplicatesOptimal(){
    vector<int> arr={1,1,2,2,3,4,4,5,5,5,6};
    int n=arr.size();
    int i=0;
    for (int j=0;j<n;j++){
        if (arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    cout<<"Number of unique elements: "<<i+1<<endl;

}

int main(){
    removeDuplicates();
    removeDuplicatesOptimal();

    
}