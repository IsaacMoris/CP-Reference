#include<iostream>
#include <bits/stdc++.h>
//#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct point {
    using  type =  long long edit this first ;
    type x,  y;
    point(type x, type y) : x(x), y(y) {}

    point operator -(const point & other)const {
        return point(x-other.x, y-other.y);
    }

    point operator +(const point & other)const {
        return point(x+other.x, y+other.y);
    }

    point operator *(type c) const {
        return point(x * c, y * c);
    }

    point operator /(type c) const {
        return point(x / c, y / c);
    }


};
auto cross(point a, point b) {
    return a.x*b.y-a.y*b.x;
}

auto dot(point a, point b) {
    return a.x*b.x+a.y*b.y;
}

point ProjectPointLine(point a, point b, point c) {
    return a + (b-a) * dot(c-a,b-a)/dot(b-a,b-a);
}

point ProjectPointSegment(point a, point b, point c) {
    auto r=dot(c-a,b-a)/dot(b-a,b-a);
    if(r<0)
        return a;
    if(r>1)
        return b;
    return a+ (b-a) * r ;
}

point reflectAroundLine(point a, point b, point p) {
    //(proj-p) *2 + p
    return ProjectPointLine(a,b,p)*2 - p;
}

point RotateCCW(point p, auto t) {
    return point(p.x * cos(t) - p.y * sin(t),
                 p.x * sin(t) + p.y * cos(t));
}

int main() {
    IO

}
