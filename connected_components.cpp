#include <bits/stdc++.h>
using namespace std;

vector<int> vis(26);
vector<int> component;

void dfs (vector<vector<int>> &graph, int vertex){
    component.push_back(vertex);
    vis[vertex] = true;
    for(auto v : graph[vertex]) if(!vis[v]){
        dfs(graph, v);
    }
}

int main(){

    int test_cases; cin >> test_cases;
    int n_vertices, n_edges;
    char cv1, cv2;
    int v1, v2;
    
    for(int test = 1; test <= test_cases; test++){
        
        cin >> n_vertices >> n_edges;
        vector<vector<int>> graph(n_vertices);
        fill(vis.begin(), vis.end(), 0);

        while(n_edges--){
            cin >> cv1 >> cv2; v1 = (int) cv1 - 97, v2 = (int) cv2 - 97;
            graph[v1].push_back(v2); graph[v2].push_back(v1);
        }        

        cout << "Case #" << test << ":" << endl;
        int comp = 0;
        
        for(int i = 0; i < n_vertices; i++) if(!vis[i]){
            dfs(graph, i);
            sort(component.begin(), component.end());
            for(auto v : component) cout << (char) (v + 97) << ",";
            cout << endl;
            component.clear();
            comp++;
        }
        cout << comp << " connected components" << endl << endl;
    }

    return 0;
}