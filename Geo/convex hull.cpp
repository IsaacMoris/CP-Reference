struct point
{
    int x,  y;
    point(int x, int y) : x(x), y(y) {}
    point operator -(point other)
    {
        return point(x-other.x, y-other.y);
    }
    bool operator <(const point  &other) const
    {
        return x!=other.x ? x<other.x : y<other.y;
    }
};
int cross(point a, point b)
{
    return a.x*b.y-a.y*b.x;
}
struct sortCCW
{
    point center ;
    sortCW(point center) : center(center) {}
    bool operator () (point  a,point  b)
    {
        int res=cross(a-center, b-center);
        if(res)
            return res>0;
        return a.y!=b.y ? a.y>b.y : a.x < b.x;
    }
};
vector<point> hull(vector<point> v)
{
    sort(v.begin(),v.end());
    sort(v.begin()+1,v.end(),sortCCW(v[0]));
    v.push_back(v[0]);
    vector<point> ans ;
    for(auto i : v)
    {
        int sz=ans.size();
        while(sz > 1 && cross(i-ans[sz-1], ans[sz-2]-ans[sz-1])<=0)
            ans.pop_back(), sz--;
        ans.push_back(i);
    }
    ans.pop_back();
    return ans;
}
