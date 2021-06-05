#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int dijkstra(vector<vector<int>> g, map<int, int> weights, int n, int src, int destiny){
    vector<int> dist(n, INF);
    dist[src] = weights[src];
	priority_queue<pair<int,int>> pq;
    pq.push(make_pair(-weights[src], src));
    while (pq.size()) {
		pair<int, int> node = pq.top(); pq.pop();
        if (-node.first > dist[node.second]) continue;

		for (int neighb : g[node.second]) {
            if (dist[neighb] > dist[node.second] + weights[neighb]) {
                dist[neighb] = dist[node.second] + weights[neighb];
			    pq.push({-dist[neighb], neighb});
		    }
        }    
	}

    return dist[destiny];
}


int main(){
    
    int n, m, k;
    float p;
    while(cin >> n >> m >> k >> p){
        vector<vector<int>> g(n);
        map<int, int> weights;
        
        for (int i = 0; i < m; i++){
            int a, b; 
            cin >> a >> b; a--, b--;
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int s; cin >> s;
        while(s--){
            int aux; cin >> aux; aux--;
            weights[aux]++;
        }
        int src, destiny; cin >> src >> destiny; src--, destiny--;
        int soldiers_on_way = dijkstra(g, weights, n, src, destiny);
        if(k >= soldiers_on_way)
            cout << std::setprecision(3) << std::fixed << pow(p,soldiers_on_way) << endl;
        else 
            cout << std::setprecision(3) << std::fixed << 0.000 << endl;
    }

    return 0;
}
