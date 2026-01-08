// for element to be leader, everything on the right should be smaller 

#include <bits/stdc++.h>
using namespace std;

void leaderBruteForce(const vector<int>& arr) {// o(N^2) time and o(1) space
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        bool isLeader = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] >= arr[i]) {
                isLeader = false;
                break;
            }
        }
        if(isLeader) {
            cout << arr[i] << " ";
        }
    }
}


void leadersOptimal(vector<int>& a) {
    // O(N)
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    // O(N)
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]);
        }
        // keep track of right max
        maxi = max(maxi, a[i]);
    }

    // O(N log N)
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }
}

int main () {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    cout << "Leaders (Brute Force): ";
    leaderBruteForce(arr);
    cout << endl;
    
    cout << "Leaders (Optimal): ";
    leadersOptimal(arr);
    cout << endl;
    
    return 0;
}