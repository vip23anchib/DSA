// find the longest subarray with sum equal to k
#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int>& arr, int k) {// o(N^2) time and o(1) space
    int n = arr.size();
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    cout << "Brute Force: Longest subarray length with sum " << k << " is " << maxLength << endl;
}

int betterLongest(vector<int> a, long long k) { // for positives , negatives as well as zeros
    map<long long, int> preSumMap;   // stores prefixSum -> first index
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        // Case 1: subarray from 0 to i
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: subarray ending at i with sum k
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // store first occurrence only in case of array with 0s (edge case)
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}


int optimal(vector<int> a, long long k) {//only for positives and zeros - o(N) time and o(1) space
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n) {

        // shrink window if sum exceeds k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // check if current window sum is k
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // expand window
        right++;
        if (right < n) {
            sum += a[right];
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;

    bruteForce(arr, k);

    int betterLen = betterLongest(arr, k);
    cout << "Better Approach: Longest subarray length with sum " << k << " is " << betterLen << endl;

    vector<int> arr2 = {1, 2, 1, 1, 1};
    int k2 = 3;
    int optimalLen = optimal(arr2, k2);
    cout << "Optimal Approach: Longest subarray length with sum " << k2 << " is " << optimalLen << endl;

    return 0;
}