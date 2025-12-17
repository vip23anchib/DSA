#include<bits/stdc++.h>
using namespace std;

void rightRotateBykPlaces1(vector<int>& arr, int k) { //method 1: brute force
    int n = arr.size();
    k = k % n;

    vector<int> temp(k);

    // Step 1: store last k elements
    for (int i = n - k; i < n; i++) {
        temp[i - (n - k)] = arr[i];
    }

    // Step 2: shift remaining elements to the right
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Step 3: copy temp to front
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

void rightRotateByKPlaces2(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;

    // 1. reverse last k elements
    reverse(arr.begin() + (n - k), arr.end());

    // 2. reverse first n-k elements
    reverse(arr.begin(), arr.begin() + (n - k));

    // 3. reverse whole array
    reverse(arr.begin(), arr.end());
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
    rightRotateBykPlaces1(arr,k);
    cout<<"Array after right rotating by "<<k<<" places: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rightRotateByKPlaces2(arr,k);
    cout<<"Array after right rotating by "<<k<<" places: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
}

}