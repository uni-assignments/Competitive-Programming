#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int MAX = 1e5+10;


int n, q; 

vector<vector<int>> segtr(4*MAX, vector<int> (9));
vector<vector<int>> lazy(4*MAX, vector<int> (9));
vector<int> zeros(9, 0);


vector<int> combina(vector<int> a, vector<int> b){
    for(int i = 0; i <= 9; i++)
        a[i] += b[i];

    return a;
}

void build(int v, int l, int r){
    if (r == l) segtr[v][1] = 1;
    else {
        int m = (l + r)/2, nxt = v << 1;
        
        build(nxt, l, m);
        build(nxt + 1, m+1, r);
        
        segtr[v] = combina(segtr[nxt], segtr[nxt+1]);
    }
}

void prop(int v, int l, int r){
    if (!lazy[v]) return;
    
    int m = (l+r)/2, nxt = v << 1;

    segtr[nxt] += lazy[v]*(m - l + 1);
    segtr[nxt+1] += lazy[v]*(r - (m+1) + 1);
    lazy[nxt] += lazy[v], lazy[nxt+1] += lazy[v];
    lazy[v] = 0;
}

// vector<int> update(int v, int l, int r, int lx, int rx, vector<int> val){
//     if (r < lx || l > rx) return segtr[v];
//     if (l >= lx && r <= rx) {
//         segtr[v] += val*(r-l+1);
//         lazy[v] += val;
//         return segtr[v];
//     }
    
//     int m = (l + r)/2, nxt = v << 1;

//     prop(v, l, r);

//     vector<int> s1 = update(nxt, l, m, lx, rx, val);
//     vector<int> s2 = update(nxt+1, m+1, r, lx, rx, val);

//     return segtr[v] = combina(s1, s2);
// }

vector<int> query(int v, int l, int r, int lx, int rx){
    if (r < lx || l > rx) return zeros;
    if (l >= lx && r <= rx)
        return segtr[v];
    
    int m = (l + r)/2, nxt = v << 1;

    prop(v, l, r);

    vector<int> s1 = query(nxt, l, m, lx, rx);
    vector<int> s2 = query(nxt+1, m+1, r, lx, rx);

    return combina(s1, s2);
	

int main (){

    cin >> n >> q;
    
    segTree <vector<int>> st(4*MAX);


    while(q--){
        int a, b; cin >> a >> b;
        
    
    }

    return 0;
}