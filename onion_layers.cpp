#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


struct point {
    int x, y;
    bool operator < (const point &p) const { return x < p.x or (x == p.x and y < p.y);}
    bool operator == (const point &p) const { return x == p.x and y == p.y; }
};

int cross_product(point &p, point &q, point &r){
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
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


int main(){ _
    
    int n;
    while (cin >> n) {
        if(!n) break;
        
        vector<point> points(n);
        for(int i = 0; i < n; i++) 
            cin >> points[i].x >> points[i].y;
        
        int ans = 0;
        while (points.size()){
            ans++;
            vector<point> hull = convex_hull(points);
            
            set<point> exterior;
            for (auto &point : hull) exterior.insert(point);
            
            vector<point> interior;
            for (auto &point : points) if (!exterior.count(point)) interior.push_back(point);
            
            points = interior;
        }
        cout << (ans % 2 ? "Take this onion to the lab!" : "Do not take this onion to the lab!" ) << endl;
    }

    return 0;
}