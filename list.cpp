#include<iostream>
#include<cstdlib>
using namespace std;
template<class type>class list
{
    public:
    list(){length=0;}
    ~list(){clear();}
    ///private nodes structures to hold the data and pointer to other nodes
    private:

    struct my_struct
    {
        struct my_struct *my_back;
        type data;
        struct my_struct *my_front;
    };
    ///typedef for simplicity
    typedef struct my_struct *NODE;

    void assert(int a)
    {
        if(a)return;
        exit(1);
    }

    NODE head;
    NODE tail;
    int length;

    public:

    bool isEmpty()
    {
        if(length==0)return 1;
        return 0;
    }

    int size()
    {
        return length;
    }

    void push_front(type var)
    {
        NODE n = (NODE)malloc(sizeof(NODE));
        n->my_front = n->my_back = NULL;
        n->data = var;
        if(!isEmpty())
        {
            tail->my_front = n;
            head->my_back = n;
            n->my_back = tail;
            n->my_front = head;
            tail = n;
        }
        else
            head = tail = n;
        length++;
    }

    void push_back(type var)
    {
        NODE n = (NODE)malloc(sizeof(NODE));
        n->my_front = n->my_back = NULL;
        n->data = var;
        if(!isEmpty())///if not empty
        {
            tail->my_front = n;
            head->my_back = n;
            n->my_front = head;
            n->my_back = tail;
            tail = n;
        }
        else
            head = tail = n;
        length++;
    }

    type pop_front()
    {
        assert(length);
        if(length==1)
        {
            type n = head->data;
            free(head);
            length=0;
            return n;
        }
        type n = head->data;
        tail->my_front = head->my_front;
        head->my_front->my_back = tail;
        free(head);
        length--;
        return n;
    }
    type pop_back()
    {
        assert(length);
        if(length==1)
        {
            type n = head->data;
            free(head);
            length = 0;
            return n;
        }
        type n = tail->data;
        tail->my_back->my_front = head;
        head->my_back = tail->my_back;
        free(tail);
        length--;
        return n;
    }
    void clear()
    {
        NODE n;
        for(int i=0;i<length;i++)
        {
            n = head->my_front;
            free(head);
            head = n;
        }
        length = 0;
    }

    void print()
    {
        NODE n;
        if(length==0)return;
        cout<<head->data<<" ";
        for(n=head->my_front;n != head; n=n->my_front)
        {
            cout<<n->data<<" ";
        }
    }
};
int main()
{
    list<int> l;
    while(true)
    {
        int n;
        cout<<"1.Push Front 2.Push Back 3.Pop Front 4.Pop Back 5.Clear 6.Print 7.Size 8.Is Empty?"<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            int a;
            cin>>a;
            l.push_front(a);
            break;
        case 2:
            int b;
            cin>>b;
            l.push_back(b);
            break;
        case 3:
            cout<<l.pop_front();
            break;
        case 4:
            cout<<l.pop_back();
            break;
        case 5:
            l.clear();
            break;
        case 6:
            l.print();
            break;
        case 7:
            cout<<l.size()?"Yes":"No";
            break;
        case 8:
            cout<<l.isEmpty();
            break;
        default: break;
        }
    }
}
