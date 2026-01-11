// Find the length of the longest consecutive sequence in an unsorted array of integers.
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x)
            return true;
    }
    return false;
}

int longestConsecutiveBrute(vector<int>& arr) {// brute force o(N^3)
    int n = arr.size();
    int longest = 1;

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;

        while (linearSearch(arr, x + 1)) {
            x = x + 1;
            cnt++;
        }

        longest = max(longest, cnt);
    }

    return longest;
}


int longestConsecutiveBetter(vector<int>& arr) { // O(N log N)
    if (arr.empty()) return 0;

    sort(arr.begin(), arr.end());

    int len = 1;
    int maxLen = 1;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i+1] == arr[i] + 1) {
            len++;
            maxLen = max(maxLen, len);
        }
        else if (arr[i+1] == arr[i]) {
            continue;   // skip duplicates
        }
        else {
            len = 1;
        }
    }

    return maxLen;  
}


int longestConsecutiveOptimal(vector<int>& arr) {// optimal o(3N) and SC= O(N)
    unordered_set<int> s;
    int n = arr.size();
    int longest = 0;

    // Insert all elements into the set
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        // Check if it's the start of a sequence
        if (s.find(arr[i] - 1) == s.end()) {
            int x = arr[i];
            int cnt = 1;

            // Count the length of the sequence
            while (s.find(x + 1) != s.end()) {
                x = x + 1;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence (Brute Force): " << longestConsecutiveBrute(arr) << endl;
    cout << "Longest Consecutive Sequence (Better): ";
    longestConsecutiveBetter(arr);
    cout << endl;
    cout << "Longest Consecutive Sequence (Optimal): " << longestConsecutiveOptimal(arr) << endl;

    return 0;
}