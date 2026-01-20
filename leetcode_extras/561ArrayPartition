#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};


/*
🔹 The Greedy Strategy (why it works)
Step 1: Sort the array
[1,4,3,2] → [1,2,3,4]

Step 2: Pair adjacent elements
(1,2), (3,4)

Step 3: Add the first element of each pair
1 + 3 = 4


This is provably optimal.

🔹 Why pairing adjacent elements is optimal

Think like this:

If you pair:

1 with 4 → min = 1
2 with 3 → min = 2
Total = 3 ❌


But if you pair:

1 with 2 → min = 1
3 with 4 → min = 3
Total = 4 ✅


👉 Pairing close numbers maximizes the smaller value in each pair.

🔹 Final Algorithm

Sort the array

Iterate through it in steps of 2

Add elements at even indices
*/