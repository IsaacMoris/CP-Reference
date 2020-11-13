#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld  double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert)
{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<int> &a, vector<int> &b)
{
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n=1;
    while(n<a.size()+b.size())
        n<<=1;
    fa.resize(n);
    fb.resize(n);

    fft(fa,0);
    fft(fb,0);

    for(int i=0; i<n; i++)
        fa[i]*=fb[i];
    fft(fa,1);
    vector<int> res(n);
    for(int i=0; i<n; i++)
        res[i]=round(fa[i].real());
    return res;
}
int main()
{
    IO
    
}
