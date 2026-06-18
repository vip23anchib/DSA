// 680. Valid Palindrome II

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

class Solution {
public:
    // helper function to find valid substring palindrome 
    bool isPalindrome(string &s, int l, int r) 
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};
