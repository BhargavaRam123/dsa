#include <iostream>
#include <stack>

using namespace std;
int solve(stack<int> s,int l){
  if(l==1)
  return s.top();
  int temp = s.top();
  s.pop();
  int ans = solve(s,--l);
  s.push(temp);
  return ans;
}
int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout<<"middle element is:"<<solve(s,s.size()/2+1)<<endl;
  cout<<s.size();     
  return 0;
}