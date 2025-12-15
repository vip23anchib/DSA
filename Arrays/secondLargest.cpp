// program to find second largest element in an array

#include<bits/stdc++.h>
using namespace std;

//method 1- BRUTE FORCE O(NlogN) : sort the array and return the second last element
void secondLargest1(){
    vector<int>my={3,7,2,9,1,0,3};
    sort(my.begin(),my.end(),greater<int>());
    cout<<"the second largest element by brute force: "<<my[1]<<endl;
}

//method 2- BETTER- two loops: first find largest then slargest -> o(2N)
void secondLargest2(int arr[], int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if (arr[i]>largest){
            largest=arr[i];
        }
    }
    int slargest=INT_MIN;
    for(int i=0;i<n;i++){
        if (arr[i]>slargest && arr[i]!=largest){
            slargest=arr[i];
        }
    }
    cout<<"the second largest element by better method : "<<slargest<<endl;
}

//method 3- OPTIMAL- single traversal O(N)
void secondLargest3(int arr[], int n){
    int largest=arr[0];
    int slargest=INT_MIN;
    for (int i=0;i<n;i++){
        if (arr[i]>largest){
            slargest=largest;
            largest=arr[i]; 
        }
        else if (arr[i]>slargest && arr[i]!=largest){
            slargest=arr[i];
        }

    }
    cout<<"the second largest element by optimal method : "<<slargest<<endl;
}

int main(){
    cout<<"enter no.of elements "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    secondLargest1();

    secondLargest2(arr, n);

    secondLargest3(arr, n);
}


/* to find second smallest number:

int secondSmallest(vector<int> &a, int n) {
    int smallest = a[0];
    int ssmallest = INT_MAX;

    for (int i = 1; i < n; i++) {
        if (a[i] < smallest) {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest && a[i] < ssmallest) {
            ssmallest = a[i];
        }
    }

    return ssmallest;
}


*/