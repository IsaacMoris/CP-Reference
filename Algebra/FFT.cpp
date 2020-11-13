#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld  double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<int> &a, vector<int> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, 0);
    fft(fb, 0);

    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, 1);
    vector<int> res(n);
    for(int i = 0; i < n; i++)
        res[i] = round(fa[i].real());
    return res;
}
int main() {
    IO
    //Applications
    //1-All possible sums
    
    //2-All possible scalar products
    // We are given two arrays a[] and b[] of length n. 
    //We have to compute the products of a with every cyclic shift of b.
    //We generate two new arrays of size 2n: We reverse a and append n zeros to it. 
    //And we just append b to itself. When we multiply these two arrays as polynomials, 
    //and look at the coefficients c[n−1], c[n], …, c[2n−2] of the product c, we get:
    //c[k]=∑ i+j=k  a[i]b[j]
    
    //3-Two stripes
    //We are given two Boolean stripes (cyclic arrays of values 0 and 1) a and b.
    //We want to find all ways to attach the first stripe to the second one,
    //such that at no position we have a 1 of the first stripe next to a 1 of the second stripe.
}
