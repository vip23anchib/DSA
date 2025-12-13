#include <bits/stdc++.h>
using namespace std;

void otherAlgos(){
    int num=7;
    int cnt=__builtin_popcount(num); //counts no. of 1's in binary 7
    cout<<"cnt="<<cnt<<endl;

    long long num2=1654238745904782;
    int cnt2=__builtin_popcountll(num2);
    cout<<"cnt="<<cnt2<<endl;

    string s="123";
    sort(s.begin(),s.end());// always sort so that u get all permutations
    do{
        cout<<s<<endl;
    } while(next_permutation(s.begin(),s.end()));

    int arr[]={3,6,1,9,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxi=*max_element(arr,arr+n);
    cout<<"max is: "<<maxi<<endl;


}
int main(){
    otherAlgos();
    return 0;
}