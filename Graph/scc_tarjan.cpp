#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct graph
{
    int n ;
    vector<vector<int> > adj;
    graph(int n) : n(n), adj(n+1) {}
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }
    vector<vector<int> > strongly_connected_components()
    {
        stack<int> st;
        vector<int> id(n+1,0);
        vector<vector<int> >scc;
        int t=-n-1;
        function<void(int)> dfs=[&](int node)
        {
            st.push(node);
            int curTime=id[node]=t++;
            for(auto i : adj[node])
            {
                if(id[i]>0)
                    continue;
                if(id[i]==0)
                    dfs(i);
                id[node]=min(id[node],id[i]);
            }
            if(curTime==id[node])
            {
                scc.push_back({});
                while(1)
                {
                    int u=st.top();
                    st.pop();
                    scc.back().push_back(u);
                    id[u]=scc.size()+1;
                    if(u==node)
                        break;
                }
            }
        };
        for(int i=1; i<=n; i++)
            if(id[i]==0)
                dfs(i);
        return scc;
    }
};
int main()
{
    IO
    graph g(5);
    g.add_edge(1,2), g.add_edge(2, 3), g.add_edge(3,1);
    g.add_edge(3,4);
    g.add_edge(5,4);
    for(auto i : g.strongly_connected_components())
    {
        for(auto j : i)
            cout<<j<<" ";
        cout<<"\n";
    }
}
