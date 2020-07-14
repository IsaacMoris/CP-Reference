#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct graph // assume: |V| <= 64F
{
    typedef  unsigned long long state ;
    int n;
    unordered_map<state,state> adj;
    graph(int n) : n(n) {}
    void add_edge(int u, int v)
    {
        u--, v--;
        adj[1ull<<u]|=(1ull<<v);
        adj[1ull<<v]|=(1ull<<u);
    }
    int maximum_maximal_cliques()
    {
        // enumerate cliques that include R, exclude X, arbitrary P.
        function<int(state,state,state)> rec = [&](state R, state P, state X)
        {
            if(!(P|X))  // R is a bitset of maximal clique
                return __builtin_popcountll(R);
            int ans=0;
            state u = P;
            u=u &(-u);
            if(!u)
                u=(X & -X );
            while(P & ~ adj[u])
            {
                state v= P & -P;
                ans=max(ans,rec(R|v,P&adj[v],X & adj[v]));
                P^=v;
                X|=v;
            }
            return ans;
        };
        return rec(0,(1ull<<n)-1,0);
    }
};
