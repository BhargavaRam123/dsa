#include <iostream>
using namespace std;
class Heap{
public:
int *arr;
int capacity;
int size;
Heap(int capacity)
{
this->capacity = capacity;
arr = new int[capacity];
size = 0;
}
void insert(int element)
{
  size++;
  if(size == capacity){
  cout<<"heap overflow cannot insert"<<endl;
  return;
  }
  cout<<"element inserted at:"<<size<<endl;
  arr[size]=element;
  cout<<arr[size]<<endl;
  int index = size ;
  int parentindex ;
  while(index>1)
  {
     parentindex = index/2;
    if(arr[parentindex]<arr[index])
    {
      swap(arr[parentindex],arr[index]);
    }
    else
    {
      break;
    }
    index/=2;
  }
}
int deleteval()
{
    int ans = arr[1];
    arr[1] = arr[size];
    size--;
    int index =1;
    
    while(index<size)
    {
        int leftindex = 2*index;
        int rightindex = 2*index +1;
        
        int largestindex = index;
        
        if(leftindex<=size&&arr[index]<arr[leftindex])
        largestindex = leftindex;
        
        if(rightindex<=size&&arr[index]<arr[rightindex])
        largestindex = rightindex;
        
        if(largestindex==index)
        {
            break;
        }
        else
        {
            swap(arr[index],arr[largestindex]);
            index = largestindex;
        }
    }
        return ans;
}

void printheap()
{
  for(int i=1;i<=size;i++)
  {
      cout<<arr[i]<<"->";
  }
  cout<<endl;
}
};

void heapify(int *arr,int n,int index)
{
    
    int largest = index ;
    int left = index*2+1;
    int right = index*2+2;
    if(left <= n && arr[index]<arr[left]  )
    largest = left;
    
    if(right <= n && arr[index]<arr[right]  )
    largest = right;
    
    if(index!=largest)
    {
        swap(arr[index],arr[largest]);
        index = largest;
        heapify(arr,n,index);
    }
}

void heapsort(int arr[],int n)
{
    while(n>0)
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
        cout<<"after heapify"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }
}

void buildheap(int arr[],int n)
{
    // bhayya kyoki n/2+1 se n thak already heap hei iske liye check kyu karna he 
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
int main() {
  // cout << "Hello world!" << endl;
//   Heap h(8);
//   h.insert(10);
//   h.insert(20);
//   h.insert(5);
//   h.insert(11);
//   h.insert(6);
//   h.printheap();
//   cout<<"deleted node"<< h.deleteval()<<endl;
//   h.printheap();
    // int arr[] = {1,3,4,5,6,7};
    int arr[] ={5,6,2,8,9,22};
    buildheap(arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<endl;
    }
    heapsort(arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<endl;
    }
    
  return 0;
}