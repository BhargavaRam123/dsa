#include <iostream>
#include <stack>

using namespace std;
void solve(stack<int> &s,int l){
  if(s.size()==0)
  {
    // cout<<"hello";
    s.push(l);
    return;
  }
  int temp = s.top();
  s.pop();
  solve(s,l);
  s.push(temp);
}
void reversestack(stack<int> &s)
{
  if(s.size()==0)
  {
    return;
  }
  int temp = s.top();
  s.pop();
  reversestack(s);
  solve(s,temp);
}
int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout<<"previous stack top:"<<s.top()<<endl;
  reversestack(s);
  cout<<"new stack top:"<<s.top()<<endl;
  cout<<"size is:"<<s.size()<<endl;
  int l = s.size();
  for(int i=0;i<l;i++)
  {
    cout<<s.top()<<endl;
    s.pop();
  }
  // cout<<"s"<<s.top()<<endl;
  return 0;
}