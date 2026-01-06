// find the next permutation of the given array
//brute force method is finding all permutations then linear searching for the given one and returning the next one
//but time complexity is high, uses recursion (O(n! * n) time and O(n) space for recursion stack
//better would be to use STL next_permutation function which uses lexicographical ordering (O(n) time and O(1) space
// STL next_permutation uses the following algorithm (O(n) time and O(1) space):

#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int index = -1;
    int n = nums.size();

    // Step 1: Find the first index from the right where nums[i] < nums[i+1]
    // This identifies the "break point" where the next permutation change can happen
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: If no such index exists, the array is in descending order
    // This means we are at the last permutation
    // Reverse the entire array to get the first permutation
    if (index == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the smallest element greater than nums[index] on the right side
    // Swap it with nums[index] to get the next larger permutation
    for (int i = n - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }
    }

    // Step 4: Reverse the subarray to the right of index
    // This makes the suffix as small as possible (lexicographically)
    reverse(nums.begin() + index + 1, nums.end());
}

    int main() {
        vector<int> nums = {1, 2, 3};
        nextPermutation(nums);
        cout << "Next Permutation: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return 0;
    }