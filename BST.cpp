#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
template<class type>class BST
{
    typedef struct my_node
    {
        struct my_node *left;
        type data;
        struct my_node *right;
    }*NODE;

    NODE root;
    int length;

    BST()
    {
        root = NULL;
        length = 0;
    }

    ~BST()
    {

    }

    void add(type info)
    {
        NODE n = new NODE;
        n->left = n->right = NULL;
        n->data = info;

        if(root==NULL)
        {
            root = n;
            length++;
            return;
        }
        NODE parent,prev;
        parent = root;
        while(parent!=NULL)
        {
            if(info<parent->data)
            {
                prev = parent;
                parent = parent->left;
            }
            else
            {
                prev = parent;
                parent = parent->right;
            }
        }
        if(info<prev->data)
        {
            prev->left = n;
        }
        else
        {
            prev->right = n;
        }
        return;
    }

    NODE find(type info,NODE *parent)
    {
        NODE temp;
        *parent = NULL;
        temp = root;
        while(temp!=NULL && temp->data != info)
        {
            *parent = temp;
            if(info<temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return temp;
    }

    bool search(type info)
    {
        NODE temp,te;
        te = find(info,temp);
        if(te == NULL)return false;
        else return true;
    }

    void remove(type info)
    {
        NODE parent = NULL;
        NODE temp = find(info,&parent);
        if(temp==NULL)
        {
            return;
        }
        if(temp == root)
        {
            NODE tempParent;
            temp = temp->right;
            tempParent = root;
            while(temp->left!=NULL)
            {
                tempParent = temp;
                temp=temp->left;
            }
            if(temp->right==NULL)
            {
                root->data = temp->data;
                free(temp);
                tempParent->left = NULL;
            }
            else
            {
                root->data = temp->data;
                tempParent->left = temp->right;
                free(temp);
            }
        }
        else
        {
            if(temp->left==NULL && temp->right==NULL)
            {
                if(parent->left == temp)parent->left=NULL;
                else parent->right=NULL;
                free(temp);
                return;
            }
            if(temp->left==NULL)
            {
                if(parent->left == temp)
                {
                    parent->left = temp->right;
                }
                else
                {
                    parent->right = temp->right;
                }
                return;
            }
            if(temp->right==NULL)
            {
                if(parent->left==temp)
                {
                    parent->left = temp->left;
                }
                else
                {
                    parent->right = temp->left;
                }
                return;
            }
            parent = temp;
            parent = parent->right;
            NODE tempParent=temp;;
            while(parent->left!=NULL)
            {
                tempParent=parent;
                parent = parent->left;
            }
            temp->data = parent->data;
            if(parent->right==NULL)
            {
                tempParent->left=NULL;
                free(parent);
            }
            else
            {
                tempParent->left = parent->right;
                free(parent);
            }
        }
    }

    void print()
    {
        stack<NODE> s;
        s.push(root);
        while(s.size()!=0)
        {
            NODE temp = s.top();
            cout<<temp->data<<" ";
            s.pop();
            if(temp->left != NULL)s.push(temp->left);
            if(temp->right !=NULL)s.push(temp->right);
        }
    }

};

