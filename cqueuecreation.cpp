#include <iostream>
using namespace std;
class cqueue
{
  public:
  int *arr;
  int size;
  int front;
  int rear;
  cqueue(int val){
    arr = new int[val];
    size = val;
    front = -1;
    rear = -1;
  }
  void push(int val)
  {
    if((rear==size-1&&front == 0)||(rear==front-1))
    {
      cout<<"overflow condition"<<endl;
      return;
    }
    else if(front == rear && front == -1)
    {
      front++;
      rear++;
      arr[rear] = val; 
    }
    else if(rear==size-1&&front!=0)
    {
      rear=0;
      arr[rear] = val;
    }
    else
    {
      rear++;
      arr[rear] = val;
    }
  }
  void pop()
  {
    if(front==rear&&front==-1)
    {
      cout<<"underflow condition"<<endl;
      return;
    }
    else if(front==rear)
    {
      arr[front]= -1;
      front=-1;
      rear=-1;
    }
    else if(front==size-1)
    {
      // reverse wala case
      arr[front] = -1;
      front = 0 ;
    }
    else
    {
      arr[front]=-1;
      front++;
    }
  }
  void print()
  {
    cout<<"printing queue"<<endl;
    for(int i=0;i<size;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};
int main() {
  
  cqueue q(5);
  q.push(5);
  q.push(5);
  q.push(5);
  q.push(5);
  q.push(5);
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.print();
  return 0;
}