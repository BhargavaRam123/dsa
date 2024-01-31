#include <iostream>
using namespace std;
#include <stack>
#include <vector>
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
   vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++)
    {
        while(arr[i]<=st.top())
        {
            st.pop();
        }
        ans[i] = st.top(); 
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
  vector<int> arr = {8,4,6,2,3};
  vector<int> ans = prevSmallerElement(arr,arr.size());
  for(int i=0;i<arr.size();i++)
  {
    cout<<ans[i]<<" ";
  }
  return 0 ;
}e