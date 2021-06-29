#include<bits/stdc++.h>
using namespace std;


bool sortdesc(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    return (get<0>(a) > get<0>(b));
}

vector<int> id(1000005), sz(1000005);
vector<tuple<int, int, int>> g;
int n;

int find(int x){    
    if(id[x] == x) id[x] = x;
    else id[x] = find(id[x]);
    return id[x];
}

void uni(int x, int y){
    x = find(x); 
    y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x,y);
    id[x] = y;
    sz[y] += sz[x];
}

void preset(){
	for (int i = 0; i < n; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

int kruskal(){
    int cost = 0;
    preset();
    for(auto [w, a, b] : g){
        if(find(a) != find(b)){
            uni(a,b);
            cost += w;
        }
    }
    
    return cost;
}


int main (){ 
    cin >> n;
    int a, b, w;
    
    for (int i = 0 ; i < n; i++){
        cin >> a >> b >> w;
        g.emplace_back(w, a, b);
    }
    int min, max;
    
    sort(g.begin(), g.end());
    max =  kruskal();
    sort(g.begin(), g.end(), sortdesc);
    min =  kruskal();
    
    
    cout << min << endl << max << endl;

    return 0;
}