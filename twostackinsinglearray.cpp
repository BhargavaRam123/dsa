#include <iostream>
// #include <stack>
using namespace std;
class stack{
  public:
  int* arr;
  int top1;
  int top2;
  int size;
  stack(int size)
  {
    this->arr = new int[size];
    this->size = size;
    top1=-1;
    top2=size;
  }
  void push1(int data)
  {
    if(top1+1==top2)
    {
      cout<<"memory occupied stack will overflow"<<endl;
    }
    else
    {
    top1++;
    arr[top1] = data;    
    }
  }
  void push2(int data)
  {
     if(top1+1==top2)
    {
      cout<<"memory occupied stack will overflow"<<endl;
    }
    else{
    top2--;
    arr[top2] = data;
    }
  }
  void pop1()
  {
    if(top1==-1)
    {
      cout<<"stack underflow condition"<<endl;
    }
    else
    {
    arr[top1]=-1;
    top1--;
    }
  }
  void pop2()
  {
      if(top2==size)
    {
      cout<<"stack underflow condition"<<endl;
    }
    else
    {
    arr[top2]=-1;
    top2++;
    }
  }
  void print()
  {
    cout<<"printing stack"<<endl;
    for(int i=0;i<size;i++)
    {
      cout<<" "<<arr[i];
    }
    cout<<endl;
  }
};
int main() {
  stack s(10);
  s.push1(2);
  s.push1(1);
  s.push1(1);
  s.push1(2);
  s.push2(10);
  s.push2(10);
  s.push2(10);
  s.push2(10);
  s.push2(10);
  s.pop2();
  s.pop2();
  s.pop2();
  s.pop2();
  s.pop1();
  s.pop1();
  s.pop1();
  s.print();
  return 0;
}