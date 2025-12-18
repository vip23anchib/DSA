// give N find missing number in array of size N-1

#include<bits/stdc++.h>
using namespace std;


void missingNumber1(vector<int>& arr,int N){ //BRUTE FORCE : O(N^2)
    int flag=0;
    for(int i=1;i<N+1;i++){
        flag=0;
        for(int j=0;j<N-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"The missing1 number is: "<<i<<endl;
            return;
        }

    }
}

void missingNumber2(vector<int>&arr,int N){// Better method using hashing
    vector<int> hash(N+1,0);
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=N;i++){
        if(hash[i]==0){
            cout<<"The missing2 number is: "<<i<<endl;
            return;
        }
    }
}

void missingNumber3(vector<int>& arr, int N) {
    int total = N * (N + 1) / 2; // Sum of first N natural numbers
    int sumOfArray = 0;

    for (int num : arr) {
        sumOfArray += num;
    }

    int missingNum = total - sumOfArray;
    cout << "The missing3 number is: " << missingNum << endl;
}

void missingNumber4(vector<int> &arr, int N){
    int xor1=0;
    int xor2=0;
/*
    for(int i=1;i<=N;i++){
        xor1=xor1^i;
    }
    for(int i=0;i<arr.size();i++){
        xor2=xor2^arr[i];
    }
*/
    for(int i=0;i<N-1;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);

    }
    xor1 = xor1 ^ N; // Include N in the XOR
    int missingNum=xor1^xor2;
    cout<<"The missing4 number is: "<<missingNum<<endl;
}

int main(){
    vector<int> arr = { 1, 2, 4, 5};
    int N = 5;
    missingNumber1(arr, N);
    missingNumber2(arr, N);
    missingNumber3(arr, N);
    missingNumber4(arr, N);

    return 0;
}