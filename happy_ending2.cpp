#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


struct point {
    int x, y;
	point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}    
    bool operator < (const point &p) const { return x < p.x or (x == p.x and y < p.y);}
    bool operator == (const point &p) const { return x == p.x and y == p.y; }
    point operator - (const point &p) const { return point(x - p.x , y - p.y); }   
    float operator ^ (const point &p) const { return x*p.y - y*p.x; }     
};

int cross_product(point &p, point &q, point &r){
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

float tarea(point &p, point &q, point &r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

vector<point> convex_hull(vector<point> points){
    int n = points.size();
    vector<point> upper_hull, lower_hull;
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) {
		while (lower_hull.size() > 1 and cross_product(lower_hull[lower_hull.size()-2], lower_hull.back(), points[i]) < 0) lower_hull.pop_back();
		lower_hull.push_back(points[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		while (upper_hull.size() > 1 and cross_product(upper_hull[upper_hull.size()-2], upper_hull.back(), points[i]) < 0) upper_hull.pop_back();
		upper_hull.push_back(points[i]);
	}
	lower_hull.pop_back(); upper_hull.pop_back();
	for (point i : upper_hull) lower_hull.push_back(i);
	return lower_hull;
}


float get_area(point p1, point p2, point p3, point p4){
    vector<point> quad;
    quad.push_back(p1), quad.push_back(p2), quad.push_back(p3), quad.push_back(p4);
    vector<point> hull = convex_hull(quad);
    if(hull.size() != 4) return 0;
    return tarea(hull[0], hull[1], hull[2]) +  tarea(hull[2], hull[3], hull[0]);
}


int main (){ _

    while(true){
        vector<point> points(5);
        for(auto &p: points){
            cin >> p.x >> p.y;
        }
        if(!points[0].x and !points[0].y and !points[1].x and !points[1].y) break;

        
        float max_area = 0;
        
        max_area = max(max_area, get_area(points[0], points[1], points[2], points[3]));
        max_area = max(max_area, get_area(points[1], points[2], points[3], points[4]));
        max_area = max(max_area, get_area(points[2], points[3], points[4], points[0]));
        max_area = max(max_area, get_area(points[3], points[4], points[0], points[1]));
        max_area = max(max_area, get_area(points[4], points[0], points[1], points[2]));

        cout << max_area << endl;
    }

    return 0;
}