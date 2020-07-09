#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct graph
{
    int n;
    vector<vector<int> > adj;
    vector<int> degree, code;
    graph(int n) : n(n), adj(n+1), degree(n+1,1) {}
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void prufer_decode()
    {
        for(auto i : code)
            degree[i]++;
        int ptr=-1, leaf=-1;
        for(int i=1; i<=n; i++)
            if(degree[i]==1)
            {
                ptr=leaf=i;
                break;
            }
        for(auto i : code)
        {
            degree[leaf]=0;
            add_edge(leaf,i);
            if(--degree[i]==1 && i<ptr)
                leaf=i;
            else
            {
                while(degree[ptr]!=1)
                    ptr++;
                leaf=ptr;
            }
        }
    }

};
int n;
int main()
{
    IO
    cin>>n;
    graph g(n);
    for(int i=1; i<n; i++)
    {
        int x;
        cin>>x;
        g.code.push_back(x);
    }
    g.prufer_decode();
    for(int i=1; i<=n; i++)
    {
        sort(g.adj[i].begin(),g.adj[i].end());
        cout<<i<<":";
        for(auto j : g.adj[i])
            cout<<" "<<j;
        cout<<"\n";
    }
}
