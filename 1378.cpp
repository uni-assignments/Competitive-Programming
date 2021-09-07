#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 1e3;


struct point {
    ll x, y;
	point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}    
};


double dist(point p, point q){
    return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

int main(){
    int n;
    while(cin >> n){
        if (!n) break;
        
        vector<point> points(n);
        vector<vector<ll>> amount_t(n, vector<ll>(n));
        
        for(int i = 0; i < n; i++){
            ll x, y; cin >> x >> y;
            points[i] = point(x, y);
        }
        
        ll ans = 0;
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < n; j++) amount_t[i][j] = dist(points[i], points[j]);
            sort(amount_t[i].begin(), amount_t[i].end());
            
            ll aux = 0; 
            for(int k = 1; k < n; k++){
                if (amount_t[i][k] != amount_t[i][k-1]){
                    ans += aux * aux - aux;
                    aux = 0;
                }
                aux++;
            }
            ans += aux * aux - aux;

        }
        cout << ans / 2 << endl;
    }
    
    return 0;
}
