// rearrange an array with equal no. of positive and negative numbers
// such that positive and negative numbers alternate
#include <bits/stdc++.h>
using namespace std;
void rearrangeBySign1(vector<int>& arr) {// BRUTE FORCE
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;

    // Separate positive and negative numbers
    for (int num : arr) {
        if (num >= 0) {
            pos.push_back(num);
        } else {
            neg.push_back(num);
        }
    }

    // Rearrange the array by alternating positive and negative numbers
    for (int i = 0; i < n / 2; i++) {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
    cout << "Rearranged array by brute force: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void rearrangeBySign2(vector<int>& arr) {// OPTIMAL METHOD
    int n = arr.size();
    int posIndex = 0; // Pointer for the next positive number
    int negIndex = 1; // Pointer for the next negative number
    vector<int> ans(n,0);
    for (int i=0;i<n;i++){
            if (arr[i]<0){
                ans[negIndex]=arr[i];
                negIndex+=2;
            }
            else{
                ans[posIndex]=arr[i];
                posIndex+=2;
            }
        }
     cout << "Rearranged array by optimal method: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3,1,-2,-5,2,-4};
    rearrangeBySign1(arr);
    

    vector<int> arr2 = {3,1,-2,-5,2,-4};
    rearrangeBySign2(arr2);

    return 0;
}