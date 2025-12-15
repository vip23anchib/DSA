// check if array is sorted in ascending order

#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int num){
    for (int i=1;i<num;i++){
        if (arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<"enter no. of elements in array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int num=sizeof(arr)/sizeof(arr[0]);
    if(isSorted(arr,num)){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }
     // OR: cout<< isSorted(arr,n)? "True":"False"<<endl;

    return 0;
}