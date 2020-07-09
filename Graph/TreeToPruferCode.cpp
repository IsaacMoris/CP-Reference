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
    vector<int> degree;
    graph(int n) : n(n), adj(n+1), degree(n+1,0) {}
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++, degree[v]++;
    }
    vector<int> prufer_code()
    {
        vector<int> code ;
        int ptr=-1, leaf=-1;
        for(int i=1; i<=n; i++)
            if(degree[i]==1)
            {
                ptr=leaf=i;
                break;
            }
        for(int i=1; i<=n-2; i++)
        {
        cnt++;
            degree[leaf]=0;
            int next=-1;
            for(auto i : adj[leaf])
                if(degree[i])
                {
                    next=i;
                    break;
                }
            code.push_back(next);
            if(--degree[next]==1 && next<ptr)
                leaf=next;
            else
            {
                while(degree[ptr]!=1)
                    ptr++;
                leaf=ptr;
            }

        }
        return code;
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
        int x, y;
        cin>>x>>y;
        g.add_edge(x,y);
    }
    for(auto i : g.prufer_code())
        cout<<i<<" ";
}
