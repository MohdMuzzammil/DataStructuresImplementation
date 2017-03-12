#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
template<class type> class queue
{
    list<type> l;
    public:

    void push(type a)
    {
        l.push_back(a);
    }

    void pop()
    {
        if(l.size()==0)exit(1);
        l.pop_back();
    }

    type top()
    {
        return l.front();
    }

    int size()
    {
        return l.size();
    }

};
int main()
{
    queue<int> s;
    while(true)
    {
        cout<<"1.Enqueue 2.Dequeue 3.Top 4.Size"<<endl;
        int n;
        cin>>n;
        switch(n)
        {
        case 1:
            int a;
            cin>>a;
            s.push(a);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout<<s.top();
            break;
        case 4:
            cout<<s.size();
            break;
        default: break;
        }
    }
    return 0;
}
