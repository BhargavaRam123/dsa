#include <iostream>
#include <stack>
using namespace std;
void insertinasortedstack(stack<int> &s,int value)
{
  
  if(s.size()==0||value>s.top())
  {
    s.push(value);
    return;
  }
  int temp = s.top();
  s.pop();
  insertinasortedstack(s,value);
  s.push(temp);
}
void sortstack(stack<int> &s)
{
  if(s.size()==0)
  {
    return;
  }
  int temp = s.top();
  s.pop();
  sortstack(s);
  insertinasortedstack(s,temp);

}
int main() {
  stack<int> s;
  s.push(1);
  s.push(40);
  s.push(12);
  s.push(18);
  int len = s.size(); 
  cout<<"length is:"<<len<<endl;
  // for(int i=0;i<len;i++)
  // {
  //   cout<<s.top()<<endl;
  //   s.pop();
  // }
  sortstack(s);
  cout<<"after"<<endl;
  
  for(int i=0;i<len;i++)
  {
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}