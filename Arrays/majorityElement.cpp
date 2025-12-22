// majority element = element that appears more than n/2 times in the array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;    

int majorityElement1(vector<int>& nums) {// brute force O(n^2) time and O(1) space
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        
        if (count > n / 2) {
            return nums[i];
        }
    }
    
    return -1; // This line should never be reached if input is valid
}

int majorityElement2(vector<int>& nums) {// using hashing O(n) time and O(n) space
    unordered_map<int, int> countMap;
    int n = nums.size();
    
    for (int num : nums) {
        countMap[num]++;
        
        if (countMap[num] > n / 2) {
            return num;
        }
    }
    
    return -1; // This line should never be reached if input is valid
}

int majorityElement3(vector<int>& nums) {// optimal approach using moore's voting algorithm O(n) time and O(1) space
    int count = 0;
    int candidate = -1;
    
    // Phase 1: Find a candidate for majority element
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    if (count > nums.size() / 2) {
        return candidate;
    }
    
    return -1; // This line should never be reached if input is valid
}

int main() {
    vector<int> nums = {3, 2, 3};
    
    cout << "Majority Element (Brute Force): " << majorityElement1(nums) << endl;
    cout << "Majority Element (Hashing): " << majorityElement2(nums) << endl;
    cout << "Majority Element (Moore's Voting): " << majorityElement3(nums) << endl;
    
    return 0;
}