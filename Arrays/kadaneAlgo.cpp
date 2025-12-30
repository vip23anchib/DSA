// Kadane's algorithm to optimally find the maximum sum of a contiguous subarray
// also print the subarray itself
/*
| Variable   | Meaning                             |
| ---------- | ----------------------------------- |
| `start`    | Temporary start of current subarray |
| `ansStart` | Start index of best subarray        |
| `ansEnd`   | End index of best subarray          |

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();

    int sum = 0;
    int maxi = INT_MIN;

    int start = 0;        // potential start index
    int ansStart = -1;    // final answer start
    int ansEnd = -1;      // final answer end

    for (int i = 0; i < n; i++) {

        // If sum is 0, a new subarray can start here
        if (sum == 0) {
            start = i;
        }

        sum += arr[i];

        // Update maximum sum and store indices
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If sum becomes negative, reset
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum Subarray Sum = " << maxi << endl;
    cout << "Subarray = ";

    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
