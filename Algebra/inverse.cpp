// Sometimes, the questions are complicated - and the answers are simple. //
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector < vector<double> > gauss (vector < vector<double> > a) {

    int n = (int) a.size();
    vector<vector<double> > ans(n, vector<double>(n, 0));

    for(int i = 0; i < n; i++)
        ans[i][i] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            if(a[j][i] > a[i][i]) {
                swap(a[j], a[i]);
                swap(ans[j], ans[i]);
            }
        double val = a[i][i];
        for(int j = 0; j < n; j++) {
            a[i][j] /= val;
            ans[i][j] /= val;
        }
        for(int j = 0; j < n; j++) {
            if(j == i)continue;
            val = a[j][i];
            for(int k = 0; k < n; k++) {
                a[j][k] -= val * a[i][k];
                ans[j][k] -= val * ans[i][k];
            }
        }
    }
    return ans;
}
int main() {

    IO
    vector<vector<double> > v(3, vector<double> (3) );
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> v[i][j];

    for(auto i : gauss(v)) {
        for(auto j : i)
            cout << j << " ";
        cout << "\n";
    }
}
