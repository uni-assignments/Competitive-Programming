#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int min_dist = INF, max_dist = 0;
int dist[1001];
vector<vector<pair<int, int>>> g;

void dijkstra(int ini){
    priority_queue<pair<ll,int>> q;
    q.push({0,ini});
    dist[ini] = 0;

    while(!q.empty()){
        pair<int,int> v = q.top(); q.pop();
		if (-v.f> dist[v.s]) continue;

        for(auto nei: g[v.s]){
            if(v.s == ini) min_dist = min(min_dist, nei.f);
            
            if (dist[nei.s] > nei.f + dist[v.s]){
                dist[nei.s] =  dist[v.s] + nei.f;
                q.push({-dist[nei.s], nei.s});
            } 
        }
    }
}

int main (){
    int v, e; cin >> v >> e;
    
    memset(dist, INF, sizeof(dist));
    g.resize(v+1);
    
    for(int i = 0; i < e; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        g[a].push_back({w,b});
        g[b].push_back({w,a});
    }
    int s; cin >> s; s--;
    
    dijkstra(s);
    for(int i = 0; i < v; i++){
        max_dist = max(max_dist, dist[i]);
    }
    cout << max_dist -  min_dist << endl;

    return 0;
}