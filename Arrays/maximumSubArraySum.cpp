//finding maximum subarray sum using bruute and better method
//optimal kadane's  algo implemented in another file


#include<bits/stdc++.h>
using namespace std;
//bruute force method
int maxSubArraySumBrute(int arr[], int n) {
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;          
}
//better method
int maxSubArraySumBetter(int arr[], int n) {
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;          
}

int maxSubArraySumOptimal(int arr[], int n) {//kadane's algorithm
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;          
}

int main() {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr) / sizeof(arr[0]);   
    cout << "Maximum Subarray Sum (Brute Force): " << maxSubArraySumBrute(arr, n) << endl;
    cout << "Maximum Subarray Sum (Better Method): " << maxSubArraySumBetter(arr, n) << endl;
    return 0;
}