//Largest Element in an Array

#include<bits/stdc++.h>
using namespace std;

void largestElement1(){ //method 1 using STL
    int a[]={3,6,1,9,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int maxi=*max_element(a,a+n);
    cout<<"the maximum element in the array is : "<<maxi<<endl;
}

void largestElement2(int arr[], int n){// method 2 -OPTIMAL approach O(N)
    int maxEl=arr[0];
    for (int i=1;i<n;i++){
        if(arr[i]>maxEl){
            maxEl=arr[i];
        }
    }
    cout<<"the maximum element in the array is : "<<maxEl<<endl;
}

void largestElement3(){//method 3 using sorting: o(NlogN)
    vector<int> my={3,7,2,9,1,0,3};
    int s=sizeof(my)/sizeof(my[0]);
    sort(my.begin(),my.end(),greater<int>());
    cout<<"the maximum element in the array is : "<<my[0]<<endl;
}



int main(){
    largestElement1();


    cout<<"enter no. of elements in array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    largestElement2(arr, n);

    
    largestElement3();


    return 0;
}