#include <iostream>
using namespace std;
class stack{
  public:
  int top;
  int *arr;
  int size;
  stack(int size)
  {
    this->size = size;
    this->arr = new int[size];
    this->top = -1;
  }
  void push(int data)
  {
    if(top<size){
      // cout<<"pushed"<<data<<endl;
    top++;
    arr[top] = data;
    }
    else
    {
      cout<<"cannot insert overflow condition"<<endl;
    }
  }
  void pop()
  {
    if(top==-1)
    {
      cout<<"stack underflow condition"<<endl;
    }
    else
    {
    top--;
    }
  }
  bool isempty()
  {
    if(top==-1)
    {
      return true;
    }
    return false;
  }
  void gettop(){
    if(top==-1)
    {
      cout<<"there are no elements in the stack cannot get the top element"<<endl;

    }else{
    cout<<"top element is:"<<arr[top]<<endl;
    }
  }
};
int main() {
  // cout << "Hello world!" << endl;
  stack s(8);
  s.push(10);
  s.gettop();
  cout<<"is stack empty:"<<s.isempty();
  return 0;
}