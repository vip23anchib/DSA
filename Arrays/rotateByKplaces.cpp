// LEFT rotate an array by k places

#include<bits/stdc++.h>
using namespace std;

void rotateBykPlaces1(vector<int>arr,int k){ //method 1: brute force
    int n=arr.size();
    k=k%n; //in case k is grater than n

    vector<int> temp(k); // or int temp[k];

    for (int i=0; i<k;i++){
        temp[i]=arr[i];
    }

    for (int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    for (int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];     // or do arr[i]=temp[j] with j starting from 0 and then j++
    }
    cout<<"Array after rotating by "<<k<<" places: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

    //method 2: using reverse function
    void rotateByKPlaces2(vector<int>arr,int k){
        int n=arr.size();
        k=k%n; 

        reverse(arr.begin(),arr.begin()+k);   //if array then reverse(arr,arr+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());

        cout<<"Array after rotating by "<<k<<" places: ";
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
    }


int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter number of places to rotate: ";
    int k;
    cin>>k;
    rotateBykPlaces1(arr,k);
    cout<<endl;
    rotateByKPlaces2(arr,k);
}


