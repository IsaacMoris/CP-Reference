#include<iostream>
#include <bits/stdc++.h>
//#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using  ptype =  double edit this first ;
double EPS = 1e-9;
struct point {

    ptype x,  y;
    point(ptype x, ptype y) : x(x), y(y) {}

    point operator -(const point & other)const {
        return point(x - other.x, y - other.y);
    }

    point operator +(const point & other)const {
        return point(x + other.x, y + other.y);
    }

    point operator *(ptype c) const {
        return point(x * c, y * c);
    }

    point operator /(ptype c) const {
        return point(x / c, y / c);
    }

};
ptype cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

ptype dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
double abs(point a) {
    return sqrt(dot(a, a));
}
// angle between [0 , pi]
double angle (point a, point b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
// a : point in Line
// d : Line slope
point LineLineIntersect(point a1, point d1, point a2, point d2) {
    return a1 + d1 * cross(a2 - a1, d2) / cross(d1, d2);
}
point ProjectPointLine(point a, point b, point c) {
    return a + (b - a) * 1.0 * dot(c - a, b - a) / dot(b - a, b - a);
}

point ProjectPointSegment(point a, point b, point c) {
    double r = dot(c - a, b - a) / dot(b - a, b - a);
    if(r < 0)
        return a;
    if(r > 1)
        return b;
    return a + (b - a) * r ;
}

point reflectAroundLine(point a, point b, point p) {
    //(proj-p) *2 + p
    return ProjectPointLine(a, b, p) * 2 - p;
}

point RotateCCW(point p, double t) {
    return point(p.x * cos(t) - p.y * sin(t),
                 p.x * sin(t) + p.y * cos(t));
}

vector<point> CircleLineIntersect(point a, point b, point center, double r) {
    a = a - center;
    b = b - center;
    point p = ProjectPointLine(a, b, point(0, 0)); // project point from center to the Line
    if(dot(p, p) > r * r)
        return {};
    double len = sqrt(r * r - dot(p, p));
    if(len < EPS)
        return {center + p};

    point d = (a - b) / abs(a - b);
    return {center + p + d * len, center + p - d * len};
}
vector<point> CircleCircleIntersect(point c1, double r1, point c2, double r2) {

    if(r1 < r2) {
        swap(r1, r2);
        swap(c1, c2);
    }
    double d = abs(c1 - c2); // distance between c1,c2
    if(d > r1 + r2 || d < r1 - r2)
        return {};

    double angle = acos(min((d * d + r1 * r1 - r2 * r2) / (2 * r1 * d), 1.0));
    point p = (c2 - c1) / d * r1;

    if(angle < EPS)
        return {p};

    return {RotateCCW(p, angle), RotateCCW(p, -angle)};

}
int main() {
    IO
   
}
