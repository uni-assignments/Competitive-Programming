#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAX = 1e5+10;
int road[MAX];
bitset<60> seg[4*MAX];

bitset<60> build(int p, int l, int r){
    if (l == r){
        seg[p][road[l]] = 1;
        return seg[p];
    } 
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) | build(2*p+1, m+1, r);
    
}

bitset<60> query(int a, int b, int p, int l, int r){
    if(b < l or r < a) return std::bitset<60>(std::string(60, '0'));
    if(a <= l and r <= b) return seg[p];
    int m = (l+r)/2;

    return query(a, b, 2*p, l, m) | query(a, b, 2*p+1, m+1, r);
}

void update(int c, int t, int p, int l, int r){
	if (l == r) seg[p] &= std::bitset<60>(std::string(60, '0')), seg[p][t] = 1;
	else {
		int m = (l + r)/2;
		if (c <= m) update( c, t, p*2, l, m);
		else update(c, t, p*2+1, m+1, r);
		seg[p] = seg[p*2] | seg[p*2+1];
	}
}


int main (){ _
    
    int n, q, m;
    while(cin >> n >> q >> m){
        for (int i = 0; i < n; i++){
            cin >> road[i];
        }    
        build(1, 0, n-1);

        while(q--){
            int op;
            cin >> op;
            if(op == 1){ //query
                int l, r; cin >> l >> r; l--, r--;
                bitset <60> ans = query(l, r, 1, 0, n-1);            
                cout << ans.count() << endl;
            } 
            else { //update
                int c, t; cin >> c >> t; c--;
                update(c, t, 1, 0, n-1);
            }
        }
    
    }
    
    return 0;
}