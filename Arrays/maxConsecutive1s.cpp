// maximum consecutive no. of 1s in a binary array
#include <iostream>
#include<vector>
using namespace std;
void maxConsecutive(vector<int>& arr){
    int count=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        if (arr[i]==1){
            count+=1;
            if (count>maxi){
                maxi=count;
            }
        }
        else{
            count=0;
            continue;
        }
    }
    cout<< "max is "<<maxi;
}
int main(){
    vector<int> arr={1,1,0,1,1,1,0,1,1};
    maxConsecutive(arr);
}
// Time Complexity: O(n)
// Space Complexity: O(1)