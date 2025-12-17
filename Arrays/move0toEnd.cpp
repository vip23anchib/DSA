// move all 0s to the end of the array

#include<bits/stdc++.h>
using namespace std;

void move0ToEnd1(vector<int>& arr) {// method 1: brute force using extra array 
    int n=arr.size();
    vector<int> temp;
    for (int i=0;i<n;i++){ //make temp array with only non 0 elements
        if (arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0; i<temp.size();i++){ //copy back non 0 elements to original array
        arr[i]=temp[i];
    }
    
    int zeroCount= n - temp.size();
    for(int i=n-zeroCount;i<n;i++){ // fill remaining with 0s
        arr[i]=0;
    }
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}



void move0ToEnd2(vector<int>& arr) { //*** method 2: OPTIMAL approach using two pointers
    int n=arr.size();
    int j=-1;
    for(int i=0;i<n;i++){
        if (arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if (arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}



int main(){
    vector<int> arr = {1,0,2,0,0,3,4,0,5};
    move0ToEnd1(arr);
    move0ToEnd2(arr);
    return 0;
}