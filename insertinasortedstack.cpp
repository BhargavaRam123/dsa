#include <iostream>
#include <stack>
using namespace std;
void insertinasortedstack(stack<int> &s,int value)
{

  int temp = s.top();
  if(s.size()==0||value>temp)
  {
    s.push(value);
    return;
  }
  s.pop();
  insertinasortedstack(s,value);
  s.push(temp);
}
int main() {
  stack<int> s;
  s.push(1);
  s.push(12);
  s.push(18);
  s.push(40);
  insertinasortedstack(s,10);
  int len = s.size(); 
  cout<<"length is:"<<len<<endl;
  for(int i=0;i<len;i++)
  {
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}