// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int *rear;
    int *front;
    int *next;
    int freespot;
    int n;
    int k;
    queue(int _n,int _k){
        n=_n;
        k=_k;
        arr = new int [n];
        rear = new int [k];
        front = new int [k];
        next = new int [n];
        freespot = 0;
        for(int i=0;i<k;i++)
        {
            front[i]=rear[i]=-1;
        }
        for(int i=0;i<n;i++)
        next[i]=i+1;
        next[n-1] = -1;
    }
    void push(int a,int qi)
    {
        if(freespot==-1)
        {
            cout<<"overflow condition"<<endl;
            return;
        }
        int index = freespot;
        freespot = next[index];
        if(front[qi]==-1)
        {
            front[qi]=index;
        }
        else
        {
            next[rear[qi]]=index;
        }
        next[index]=-1;
        rear[qi]=index;
        arr[index]=a;
    }
    int pop(int qi)
    {
        if(front[qi]==-1)
        {
            return -1;
        }
        int index = front[qi];
        front[qi]=next[index];
        next[index]=freespot;
        freespot = index;
        return arr[index];
    }
};
int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    queue q1(9,3);
    q1.push(5,0);
    q1.push(6,0);
    q1.push(7,0);
    cout<<q1.pop(0);
    cout<<q1.pop(0);
    cout<<q1.pop(0);

    return 0;
}