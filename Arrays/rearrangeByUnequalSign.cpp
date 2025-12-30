// rearrange an array with unequal no. of positive and negative numbers
// such that positive and negative numbers alternate
#include <bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int>& a) {
    vector<int> pos, neg;
    int n = a.size();

    // Separate positives and negatives
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    // If positives are more
    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    // If negatives are more or equal
    else {
        for (int i = 0; i < pos.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    return a;
}
int main() {
    vector<int> arr = {3, -2, 1, -5, 2, -4, -6, 7, 8};
    vector<int> result = alternateNumbers(arr);

    cout << "Rearranged array with unequal positives and negatives: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}