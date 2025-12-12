#include <bits/stdc++.h>
using namespace std;

//making our own custom sort where:
bool comp(const pair<int,int>& p1, const pair<int,int>& p2) {
    // sort by second element (ascending)
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // if second elements are the same → sort by first element (descending)
    return p1.first > p2.first;
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}


void printPairs(const pair<int,int> arr[], int n) {
    //or void printPairs(const pair<int,int> *arr, int n)
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << '(' << arr[i].first << ',' << arr[i].second << ')';
    }
    cout << '\n';
}

void algo() {
    int a[] = {2, 6, 4, 7, 1};
    const int n = sizeof(a)/sizeof(a[0]);

    // full ascending sort
    sort(a, a + n);
    cout << "after sort(a, a+n): ";
    printArray(a, n);

    // sort subrange a[2..n-1] (already sorted here since we sorted whole array previously)
    sort(a + 2, a + n);
    cout << "after sort(a+2, a+n): ";
    printArray(a, n);

    // sort descending using greater<int>()
    sort(a, a + n, greater<int>());
    cout << "after sort(a, a+n, greater<int>()): ";
    printArray(a, n);

    // pairs: fix size to 3 (only 3 elements)
    pair<int,int> arr[] = {{1,2}, {2,1}, {4,1}};
    const int m = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + m, comp);
    cout << "sorted pairs (by second asc, first desc if tie): ";
    printPairs(arr, m);
}

int main() {
    ios::sync_with_stdio(false);//unties C and C++ streams hences makes it faster 
    cin.tie(nullptr); //unties cin and cout hence faster 
    algo();
    return 0;
}
