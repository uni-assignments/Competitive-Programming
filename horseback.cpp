#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, m, k, amount;

bool vis[10010];
int h[10010];
int graph[101][10010];

bool dfs(int vol){
    for (int i = 0; i < amount; i++) if (graph[vol][i] && !vis[i]){
        vis[i] = true;
        if (h[i] == -1 or dfs(h[i])){
            h[i] = vol;
            return true;
        }
    }
    return false;
}
 
int match(){
    int ans = 0;
    for (int vol = 0; vol < m; vol++){
        memset(vis, false, sizeof(vis)); 
        if (dfs(vol)) ans++;
    }
    return ans;
}

int main (){ _
    int inst = 0;
    while(cin >> n >> m >> k){
        inst++;
        vector<pair<int, int>> horses(n); // ini, amount
        memset(graph, 0 , sizeof graph);
        amount = 0;
        for(int i = 0; i < n; i++){
            horses[i].first = amount;
            cin >> horses[i].second;
            amount += horses[i].second;
        }
        for(int i = 0; i < k; i++){
            int u, v; cin >> u >> v; u--, v--;
            for(int j = horses[u].first; j < horses[u].first + horses[u].second; j++){
                graph[v][j] = 1;
                graph[j][v] = 1;
            }
        }
        memset(h, -1, sizeof h);
        cout << "Instancia " << inst << endl;
        cout << match() << endl;
    }
}