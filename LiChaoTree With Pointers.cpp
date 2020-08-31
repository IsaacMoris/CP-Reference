#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld  double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct Line
{
    ll m, b;
    Line(ll m, ll b) : m(m), b(b) {}
    ll operator()(ll x)
    {
        return m * x + b;
    }
};
struct node
{
    node * left,* right ;
    Line line ;
    node(node * left, node *right, Line line):left(left), right(right), line(line) {}
    node * getLeft()
    {
        if(left==NULL)
            left= new node (NULL,NULL,Line(0,1e18)) ;
        return left ;
    }
    node * getright()
    {
        if(right==NULL)
            right= new node (NULL,NULL,Line(0,1e18)) ;
        return right ;
    }
    void insert(Line newline, int l, int r)
    {
        int m=(l+r)/2;
        bool lef=newline(l)<line(l);
        bool mid=newline(m)<line(m);

        if(mid)
            swap(line,newline);
        if(r-l==1)
            return ;
        else if(lef!=mid)
            getLeft()->insert(newline,l,m);
        else
            getright()->insert(newline,m,r);
    }
    ll query(int x, int l, int r)
    {
        int m = (l + r) / 2;
        if(r - l == 1)
            return line(x);
        else if(x < m)
            return min(line(x), getLeft()->query(x, l, m));
        else
            return min(line(x), getright()->query(x, m, r));
    }
    void deletee()
    {
        if(left!=NULL)
            left->deletee();
        if(right!=NULL)
            right->deletee();
        free(this);
    }
};
int main()
{
    IO
    node * root = new node(NULL,NULL,Line(0,5));
    root->insert(Line(1,-3),1,100);

    for(int i=1; i<=10; i++)
        cout<<root->query(i,1,100)<<"\n";
}
