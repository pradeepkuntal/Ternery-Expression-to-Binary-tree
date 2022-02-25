#include<bits/stdc++.h>
using namespace std;

/*
Convert a Ternary Expression string to a Binary Tree.
Here you can have a string instead of char between the ternary operators.
Hard level problem

Input :  ab ? bcd : efgh

Output
               ab
  	          /  \
  		   bcd    efgh
*/

struct Node
{
    string val;
    Node* left;
    Node* right;
};
Node* GetNode(string val)
{
    Node* temp=new Node();
    temp->left=NULL;
    temp->right=NULL;
    temp->val=val;
    return temp;
}

int GetRootString(string str)
{
    int i=0;
    while(i<str.size()&&str[i]!='?')
    {
        i++;
    }
    return i;
}
int GetLeftString(string str)
{
    int count=0;int i=0;
    while(count<=0&&i<str.size())
    {
        while(i<str.size()&&str[i]!='?'&&str[i]!=':')i++;
        if(i<str.size())
        {
            if(str[i]=='?')count--;
            else count++;
            i++;
        }
    }
    return i;
}

Node* CreateTree(string str)
{
    if(str.size()==0)return NULL;
    int ind=GetRootString(str);
    string root_str=str.substr(0,ind);
    Node* root=GetNode(root_str);

    //cout<<root_str<<endl;

    if(ind==str.size())return root;

    string rem_str=str.substr(ind+1);
   // cout<<rem_str<<endl;

    int left_ind=GetLeftString(rem_str);

    root->left=CreateTree(rem_str.substr(0,left_ind-1));
    root->right=CreateTree(rem_str.substr(left_ind));

    return root;

}
void Print(Node* root)
{
    if(!root)return;
    cout<<root->val<<" ";
    Print(root->left);
    Print(root->right);
}

int main()
{
      freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout<<"Hello world"<<endl;

    string str;
    cin>>str;
   Node* root=CreateTree(str);
   Print(root);  
    return 0;
}