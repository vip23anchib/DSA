/*
TOPIC:
- Sorting
- Custom Comparator
- Strings

PROBLEM:
Given an array of numbers stored as strings,
return the kth largest number.

OBSERVATION:
We cannot convert strings to int/long long because
the numbers may be extremely large and cause overflow.

Example:
"999999999999999999999999999"
So we compare the strings directly.

KEY LOGIC:
1. If two numeric strings have different lengths:
   - More digits => Larger number

2. If two numeric strings have the same length:
   - Lexicographical comparison works exactly like
     numerical comparison.
   Example:
   "123" < "456"

CUSTOM COMPARATOR:

bool cmp(string a, string b)

returns true when 'a' should come before 'b'.


kth Largest = nums[n-k]

TIME COMPLEXITY:
O(n log n)

SPACE COMPLEXITY:
O(1) extra space (excluding sorting internals)

IMPORTANT INTERVIEW CONCEPT:

Custom Comparator:
A function passed to sort() that decides the ordering
of elements.

Template:

bool cmp(Type a, Type b)
{
    // return true if a should appear before b
}

sort(arr.begin(), arr.end(), cmp);

COMMON COMPARATOR PATTERNS:

Ascending:
return a < b;

Descending:
return a > b;

Sort strings by length:
return a.size() < b.size();

Sort pairs by second element:
return a.second < b.second;
*/

// For equal-length numeric strings:
// Lexicographical Order == Numerical Order



class Solution {
public:

    static bool cmp(string a , string b){
            if (a.size()==b.size()){
                return a<b;
            }
            return a.size()<b.size();
        }
    string kthLargestNumber(vector<string>& nums, int k) {
        
        
        sort(nums.begin(),nums.end(),cmp);

        return nums[nums.size() - k];
    }
};


// OR using lambda comparator function
sort(nums.begin(), nums.end(),
     [](string a, string b) {

        if (a.size() == b.size())
            return a < b;

        return a.size() < b.size();
     });
