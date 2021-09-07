#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
const int MAX = 1e5+10;


int n, q; 
vector<vector<int>> seg(4*MAX, vector<int>(9, 0));

vector<int> keys(4*MAX, 1);
vector<int> zeros(9, 0);

vector<int> combina(vector<int> a, vector<int> b){
    for(int i = 0; i <= 9; i++)
        a[i] += b[i];

    return a;
}

vector<int> recalcula(vector<int> a, int v){
    for(int i = 0; i < 9; i++) if(a[i]){
        a[i]--, a[(i + v) % 9]++;
        break;
    }

    return a;
}

vector<int> build(int p, int l , int r){
    if(l == r){
        seg[p][1] = 1;
        return seg[p];
    } 
    int m = (l+r)/2;
   
    return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
}

vector<int> query(int a, int b, int p, int l, int r){
    if(b < l or r < a) return zeros;
    if(a <= l and r <= b) return seg[p];
    int m = (l+r)/2;

    return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

void update(int a, int b, int nv, int p, int l, int r){
    if (b < l or r < a or r < l) return;
    if (l == r) seg[p] = recalcula(seg[p], nv);
    else {
        int mid = (l+r)/2;
        update(a, b, nv, p*2, l, mid), update(a, b, nv, p*2+1, mid+1, r);
    
        seg[p] = combina(seg[p*2], seg[p*2+1]);
    }    
}

int get_most_freq(vector<int> freq){
    int f = 0;
    for(int j = 1; j < 9; j++) if(freq[f] <= freq[j]) 
            f = j;
    return f;
}

void get_ans(int p, int l, int r){
    if(l == r) cout << get_most_freq(seg[p]) << endl;
    else {
        int m = (l+r)/2; 
        get_ans(2*p, l, m), get_ans(2*p+1, m+1, r);
    }
}

int main (){

    cin >> n >> q;
    
    build(1, 0, n-1);
    
    while(q--){
        int a, b; cin >> a >> b;
        
        vector<int> freq = query(a, b, 1, 0, n-1);
        int f = get_most_freq(freq);
        update(a, b, f, 1, 0, n-1);     
    }

    get_ans(1, 0, n-1);

    return 0;
}