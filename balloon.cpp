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

struct line { // reta
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
	
};

bool ccw(point p, point q, point r) { 
	return ((q-p)^(r-q))/2 > 0;
}

struct cmp_sweepline {
	bool operator () (const line& a, const line& b) const {
		if (a.p == b.p) return ccw(a.p, a.q, b.q);
		if (a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
			return ccw(a.p, a.q, b.p);
		return ccw(a.p, b.q, b.p);
	}
};



int main(){

    int n, c;
    while(cin >> n >> c){
        set<int, line> lines(cmp_sweepline);
        for(int i = 0; i < n; i++){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            lines.insert(line(point(x1, y1), point(x2, y2)));
        }
    }



    return 0;
}