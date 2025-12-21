//Find two indices whose values add up to a target
/*needed = target - nums[i]
→ the number required to form the sum

if (needed is already in map)
→ found the answer
→ return { index_of_needed, i }

Else
→ store current number:
map[nums[i]] = i*/

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

void two_sum1(vector<int> &arr,int num){// brute force O(n^2)
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==num){
                cout<<"yes: indices are-> "<<i<<" and "<<j<<endl;
                return;
            }
        }
    }
    cout << "no" << endl;
}

void two_sum2(vector<int>& arr, int target) {// using hashing O(n) time and O(n) space
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < arr.size(); i++) {
        int needed = target - arr[i];

        // check if needed already exists
        if (mp.find(needed) != mp.end()) {
            cout << "yes: indices are -> "
                 << mp[needed] << " and " << i << endl;
            return;
        }

        // if not present in map yet thenstore current value with its index
        mp[arr[i]] = i;
    }

    cout << "no" << endl;
}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    int num=11;
    two_sum1(arr,num);
    two_sum2(arr,num);
}