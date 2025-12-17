// intersection of sorted arrays 

#include<bits/stdc++.h>
using namespace std;

void intersection1(vector<int>& arr1, vector<int>& arr2) { // BRUTE FORCE using nested loops
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> visited(n2, 0);
    vector<int> intersectionArr;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j] && visited[j] == 0) {
                intersectionArr.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            else if (arr2[j] > arr1[i]) {
                break;
            }
        }
    }

    cout<<"Intersection Array by brute force method: ";
    for (int x : intersectionArr) {
        cout << x << " ";
    }
}

void intersection2(vector<int>& arr1, vector<int>& arr2) {// OPTIMAL using two pointers
    int n = arr1.size();
    int m = arr2.size();
    vector<int> intersectionArr;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if ( arr2[j]< arr1[i]) {
            j++;
        }
        else {
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    cout<<"Intersection Array by optimal method: ";
    for (int x : intersectionArr) {
        cout << x << " ";
    }
}

int main(){
    vector<int> arr1 = {1, 2, 2, 3, 4, 5};
    vector<int> arr2 = {2, 2, 3, 5, 6};

    intersection1(arr1, arr2);
    cout << endl;
    intersection2(arr1, arr2);
    cout << endl;

    return 0;
}

