// from a sorted array where every element appears twice except for one element which appears once find it

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int numAppearsOnce1(vector<int>& arr) {// brute force : O(n^2)
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;

        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count == 1) {
            cout<<"by brute force:" <<arr[i]<<endl;
        }
    }
    return -1; // if no unique element
}

void  numApppearsOnce2(vector<int>& arr){// hashing : O(n) time but not space efficient for big numbers
    int maxi=0;
    for(int x:arr){
        maxi=max(maxi,x);
    }
    vector<int> hash(maxi+1,0);
    for(int x:arr){
        hash[x]++;
    }
    for (int x:arr){
        if (hash[x]==1){
            cout<<"by hashing:"<<x<<endl;
            return;
        }
    }

}

void numAppearsOnce3(vector<int>& arr){// using unordered maps 
    unordered_map<long,long> freq;
    for (int x:arr){
        freq[x]++;
    }
    for(int x:arr){
        if (freq[x]==1){
            cout<<"by unordered maps:"<<x<<endl;
            return;
        }
    }

}

void numAppearsOnce4(vector<int>& arr){// optimal approach using xor : O(n) time and O(1) space
    int res=0;
    for(int x:arr){
        res=res^x;
    }
    cout<<"by xor:"<<res<<endl;
}


int main() {
    vector<int> arr = {1,2,3,2,1,4,4};
    numAppearsOnce1(arr);
    numApppearsOnce2(arr);
    numAppearsOnce3(arr);
    numAppearsOnce4(arr);
    return 0;
}