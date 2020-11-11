#include<iostream>
#include <bits/stdc++.h>
//#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using  ptype =  long long edit this first ;
struct point {

    ptype x,  y;
    point(ptype x, ptype y) : x(x), y(y) {}

    point operator -(const point & other)const {
        return point(x-other.x, y-other.y);
    }

    point operator +(const point & other)const {
        return point(x+other.x, y+other.y);
    }

    point operator *(ptype c) const {
        return point(x * c, y * c);
    }

    point operator /(ptype c) const {
        return point(x / c, y / c);
    }


};
ptype cross(point a, point b) {
    return a.x*b.y-a.y*b.x;
}

ptype dot(point a, point b) {
    return a.x*b.x+a.y*b.y;
}

point ProjectPointLine(point a, point b, point c) {
    return a + (b-a) * dot(c-a,b-a)/dot(b-a,b-a);
}

point ProjectPointSegment(point a, point b, point c) {
    ptype r=dot(c-a,b-a)/dot(b-a,b-a);
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

point RotateCCW(point p, long double t) {
    return point(p.x * cos(t) - p.y * sin(t),
                 p.x * sin(t) + p.y * cos(t));
}

int main() {
    IO

}
