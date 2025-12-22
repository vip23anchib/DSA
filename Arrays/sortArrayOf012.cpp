// sort an array of 0s, 1s and 2s 
//optimal method is DUTCH NATIONAL FLAG ALGORITHM
#include <iostream>
#include <vector>
using namespace std;

//brute force method- sort the array: o(nlogn) time and o(1) space 

void betterMethod(vector<int>& arr) {// counting sort O(n) time and O(1) space
    int count0 = 0, count1 = 0, count2 = 0;

    for (int num : arr) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else if (num == 2) count2++;
    }

    for (int i = 0; i < count0; i++) {
        arr[i] = 0;
    }
    for (int i = count0; i <count0+ count1; i++) {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < arr.size(); i++) {
        arr[i] = 2;
    }

    cout << "Sorted array by better: ";
    for (int num : arr) {
        cout << num << " "; 
    }
}



void optimalMethod(vector<int>& arr) {// dutch national flag algorithm O(n) time and O(1) space
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
    cout << "Sorted array by optimal: ";
    for (int num : arr) {
        cout << num << " "; 
    }
}

int main(){
    vector<int> arr={0,1,2,0,1,2,1,0,2,0,1};
    betterMethod(arr);
    cout<<endl;
    //resetting array for optimal method
    arr={0,1,2,0,1,2,1,0,2,0,1};
    optimalMethod(arr);
    return 0;
}