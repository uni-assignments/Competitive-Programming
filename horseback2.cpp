#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


struct Dinic {
	struct edge { 
		int to, id, cap; 
		edge (int to_, int id_, int cap_) : to(to_), id(id_), cap(cap_) {}
	};

	vector<vector<edge>> g;
	vector<int> flow, lvl, it;
	
	Dinic (int sz) : g(sz), lvl(sz), it(sz) {}
	
	void add_edge(int u, int v, int cap) {
		g[u].emplace_back(v, flow.size(), cap), flow.push_back(0);
		g[v].emplace_back(u, flow.size(), cap), flow.push_back(cap);
	}
	
    int dfs(int v, int flow_aug, int t) {
		if (v == t) return flow_aug;
		for (int& i = it[v]; i < g[v].size(); i++) {
			edge e = g[v][i];
			int left = e.cap - flow[e.id];
			if (lvl[e.to] == lvl[v] + 1 and left) {
				if (int aug = dfs(e.to, min(flow_aug, left), t)) {
					flow[e.id] += aug, flow[e.id^1] -= aug;
					return aug;
				}
			}
		}
		return 0;
	}
	
    bool bfs(int s, int t) {
		fill(begin(lvl), end(lvl), -1); 
		lvl[s] = 0;
		queue<int> q; 
		q.push(s);
		while (not q.empty()) {
			int u = q.front(); 
			q.pop();
			for (edge e : g[u]) if (e.cap - flow[e.id] > 0 and lvl[e.to] == -1)
				lvl[e.to] = lvl[u] + 1, q.push(e.to);
		}
		return lvl[t] != -1;
	}

	int max_flow(int s, int t) {
		int max_flow = 0;
		while (bfs(s, t)) {
			fill(begin(it), end(it), 0);
			while (int aug = dfs(s, INF, t)) max_flow += aug;
		}
		return max_flow;	
	}
};


int n, m, k, amount;


int main (){ _
    int inst = 0;
    while(cin >> n >> m >> k){
        inst++;
        Dinic graph(n+m+2);

        for (int i = 0; i < n; i++){
            int aux; cin >> aux;
            graph.add_edge(m+i, n+m+1, aux);
        }
        for (int i = 0; i < m; i++)
            graph.add_edge(n+m, i, 1);

        for (int i = 0; i < k; i++){
            int u, v; cin >> u >> v; u--; v--;
            graph.add_edge(v, m+u, 1);
        }
        cout << "Instancia " << inst << endl;
        cout << graph.max_flow(n+m, n+m+1) << endl << endl;
    }
}