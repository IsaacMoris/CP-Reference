#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n ;
string s ;
void count_sort(vector<int> &p, vector<int> &c)
{
    int n=p.size();

    vector<int> cnt(n);
    for(auto i  : c)
        cnt[i]++;

    vector<int> new_p(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1; i<n; i++)
        pos[i]=pos[i-1]+cnt[i-1];

    for(auto i : p)
    {
        int j=c[i];
        new_p[pos[j]++]=i;
    }
    p=new_p;

}
int main()
{
    IO
    cin>>s;
    s+='$';
    n=s.size();
    vector<int> p(n), c(n);
    {
        // k=0
        vector<pair<int,int> > a(n) ;
        for(int i=0; i<n; i++)
            a[i]= {s[i],i};
        sort(a.begin(),a.end());

        for(int i=0; i<n; i++)
            p[i]=a[i].second;

        c[p[0]]=0;
        for(int i=1; i<n; i++)
            c[p[i]] = a[i].first==a[i-1].first ? c[p[i-1]] : c[p[i-1]]+1;
    }
    int k=0;
    while((1 << k) < n)
    {
        for(int i=0; i<n; i++)
            p[i]=(p[i]-(1<<k) + n) %n;
        count_sort(p,c);
        vector<int> new_c(n);

        new_c[p[0]]=0;
        for(int i=1; i<n; i++)
        {
            pair<int,int> now= {c[p[i]], c[(p[i] + (1<<k))%n]};
            pair<int,int> prv= {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
            new_c[p[i]]= now== prv ? new_c[p[i-1]] : new_c[p[i-1]] +1 ;
        }
        c=new_c;
        k++;
    }
    for(auto i : p)
        cout<<i<<" ";
}
