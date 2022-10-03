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
    point prep() {
        return point(-y, x);
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
// d : Line direction
point LineLineIntersect(point a1, point d1, point a2, point d2) {
    return a1 + d1 * cross(a2 - a1, d2) / cross(d1, d2);
}
// Line a---b
// point C
point ProjectPointLine(point a, point b, point c) {
    return a + (b - a) * 1.0 * dot(c - a, b - a) / dot(b - a, b - a);
}
// segment a---b
// point C
point ProjectPointSegment(point a, point b, point c) {
    double r = dot(c - a, b - a) / dot(b - a, b - a);
    if(r < 0)
        return a;
    if(r > 1)
        return b;
    return a + (b - a) * r ;
}
// Line a---b
// point p
point reflectAroundLine(point a, point b, point p) {
    //(proj-p) *2 + p
    return ProjectPointLine(a, b, p) * 2 - p;
}
// Around origin 
point RotateCCW(point p, double t) {
    return point(p.x * cos(t) - p.y * sin(t),
                 p.x * sin(t) + p.y * cos(t));
}
// Line a---b
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

vector<point> CircleCircleIntersect(point c1, ld r1, point c2, ld r2) {

    if (r1 < r2) {
        swap(r1, r2);
        swap(c1, c2);
    }
    ld d = abs(c2 - c1); // distance between c1,c2
    if (d > r1 + r2 || d < r1 - r2 || d < EPS)  // zero or infinite solutions
        return {};
    ld angle = acos(min((d * d + r1 * r1 - r2 * r2) / (2 * r1 * d), (ld) 1.0));
    point p = (c2 - c1) / d * r1;

    if (angle < EPS)
        return {c1 + p};

    return {c1 + RotateCCW(p, angle), c1 + RotateCCW(p, -angle)};

}

point circumcircle(point p1, point p2, point p3) {

    return LineLineIntersect((p1 + p2) / 2, (p1 - p2).prep(),
                             (p1 + p3) / 2, (p1 - p3).prep() );
}
//S : Area.
//I : number points with integer coordinates lying strictly inside the polygon.
//B : number of points lying on polygon sides by B.
//S = I + B/2 −1
