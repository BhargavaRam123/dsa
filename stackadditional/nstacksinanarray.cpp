// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class nstack{
    public:
    int* a, *next,*top;
    int size;
    int n;
    int freepointer;
    nstack(int n,int size){
        this->a = new int[size];
        this->next = new int[size];
        this->top = new int[n];
        this->size = size;
        this->freepointer = 0;
        for(int i=0;i<size;i++)
        {
            a[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            top[i]=-1;
        }
        for(int i=0;i<size;i++)
        {
            next[i]=i+1;
        }
        next[size-1] = -1;
    }
    bool push(int x,int m)
    {
        if(freepointer==-1)
        {
            cout<<"stack overflow"<<endl;
            return 0;
        }
        int index =  freepointer;
        freepointer= next[index];
        a[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
        return 1;
    }
    int pop(int m)
    {
        if(top[m-1]==-1)
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freepointer;
        freepointer = index;
        return a[index];
    }
};
int main() {
    // Write C++ code here
    nstack st(3,8);
    cout<<st.push(10,1);
    cout<<st.push(20,1);
    cout<<st.push(30,2);
    cout<<st.push(40,1);
    cout<<st.push(50,2);
    cout<<st.push(60,1);
    cout<<st.push(70,3);
    cout<<st.push(80,2);
    cout<<st.pop(2);
    cout<<st.pop(2);
    cout<<st.pop(2);
    cout<<st.pop(3);
    cout<<st.pop(1);
    cout<<st.pop(1);
    
    

    return 0;
}