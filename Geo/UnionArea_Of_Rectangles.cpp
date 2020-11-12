#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
class Rectangle {
public:
    int x1, y1, x2, y2;
    static Rectangle empt;
    Rectangle() {
        x1 = y1 = x2 = y2 = 0;
    }
    Rectangle(int X1, int Y1, int X2, int Y2) {
        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
    }
};
struct Event {
    int x, y1, y2, type;
    Event() {}
    Event(int x, int y1, int y2, int type): x(x), y1(y1), y2(y2), type(type) {}
};
bool operator < (const Event&A, const Event&B) {
//if(A.x != B.x)
    return A.x < B.x;
//if(A.y1 != B.y1) return A.y1 < B.y1;
//if(A.y2 != B.y2()) A.y2 < B.y2;
}
const int MX = (1 << 17);
struct Node {
    int prob, sum, ans;
    Node() {}
    Node(int prob, int sum, int ans): prob(prob), sum(sum), ans(ans) {}
};
Node tree[MX * 4];
int interval[MX];
void build(int x, int a, int b) {
    tree[x] = Node(0, 0, 0);
    if(a == b) {
        tree[x].sum += interval[a];
        return;
    }
    build(x * 2, a, (a + b) / 2);
    build(x * 2 + 1, (a + b) / 2 + 1, b);
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
}
int ask(int x) {
    if(tree[x].prob)
        return tree[x].sum;
    return tree[x].ans;
}
int st, en, V;
void update(int x, int a, int b) {
    if(st > b || en < a)
        return;
    if(a >= st && b <= en) {
        tree[x].prob += V;
        return;
    }
    update(x * 2, a, (a + b) / 2);
    update(x * 2 + 1, (a + b) / 2 + 1, b);
    tree[x].ans = ask(x * 2) + ask(x * 2 + 1);
}
Rectangle Rectangle::empt = Rectangle();
vector < Rectangle > Rect;
vector < int > sorted;
vector < Event > sweep;
void compressncalc() {
    sweep.clear();
    sorted.clear();
    for(auto R : Rect) {
        sorted.push_back(R.y1);
        sorted.push_back(R.y2);
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int sz = sorted.size();
    for(int j = 0; j < sorted.size() - 1; j++)
        interval[j + 1] = sorted[j + 1] - sorted[j];
    for(auto R : Rect) {
        sweep.push_back(Event(R.x1, R.y1, R.y2, 1));
        sweep.push_back(Event(R.x2, R.y1, R.y2, -1));
    }
    sort(sweep.begin(), sweep.end());
    build(1, 1, sz - 1);
}
long long ans;
void Sweep() {
    ans = 0;
    if(sorted.empty() || sweep.empty())
        return;
    int last = 0, sz_ = sorted.size();
    for(int j = 0; j < sweep.size(); j++) {
        ans += 1ll * (sweep[j].x - last) * ask(1);
        last = sweep[j].x;
        V = sweep[j].type;
        st = lower_bound(sorted.begin(), sorted.end(), sweep[j].y1) - sorted.begin() + 1;
        en = lower_bound(sorted.begin(), sorted.end(), sweep[j].y2) - sorted.begin();
        update(1, 1, sz_ - 1);
    }
}
int main() {
//    freopen("in.in","r",stdin);
    int n;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        Rect.push_back(Rectangle(a, b, c, d));
    }
    compressncalc();
    Sweep();
    cout << ans << endl;
}
