#include <iostream>
using namespace std;
class Queue{
  public:
  int *arr;
  int size;
  int front;
  int  rear;

  Queue(int size){
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void push(int data)
  {
    if(rear==size-1)
    {
      cout<<"overflow condition"<<endl;
      return;
    }
    if(front ==-1&&rear==-1)
    {
      front++;
      rear++;
      arr[front] = data;
    }
    else
    {
    rear++;
    arr[rear] = data;
    }
  }

  void pop(){
     if(front==-1&&rear==-1)
     {
      cout<<"queue is empty cannot remove anything"<<endl;
      return;
     }
     else if(front == rear)
     {
      arr[rear] = -1;
      front = -1;
      rear = -1;
     }
     else{
      arr[front] = -1;
      front++;
     }
  }

  bool isempty()
  {
    if(front==rear&&front==-1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  int getsize()
  {
    if(rear==front&&rear==-1)
    return 0;
    else
    return rear-front +1;
  }
  int getfront()
  {
    if(rear==front&&rear==-1)
    {
      cout<<"stack is empty"<<endl;
      return -1;
    }
    return arr[front];
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
  Queue q(10);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.push(1);
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  cout<<endl;
  cout<<q.getsize();
  // q.push(10);
  // q.pop();
  q.print();
  cout<<q.isempty();
  cout<<q.getfront();
  return 0;
}