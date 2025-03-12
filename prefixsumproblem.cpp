// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void function1(const vector<int>& arr, int targetSum){
    map <int,vector<int>> prefixsum;
    prefixsum[0].push_back(-1);
    int current=0;
    int count =0;
    for(int i=0;i<arr.size();i++)
    {
        current+=arr[i];
        if(prefixsum.find(current-targetSum)!=prefixsum.end())
        {
            vector<int> indices = prefixsum[current-targetSum];
            for(int index:indices)
            {
                cout<<index+1<<"..."<<i<<endl;
            }
        }
        prefixsum[current].push_back(i);
    }
}
int main() {
    // Write C++ code here
    vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8, 9};
    function1(arr,15);
    return 0;
}
