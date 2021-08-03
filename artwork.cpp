#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

bool sensors_overlap(int s1, int s2, pair<int, int> v1, pair<int, int> v2){
    float min_dist = sqrt((v1.f - v2.f)*(v1.f - v2.f) + (v1.s - v2.s)*(v1.s - v2.s));
    
    if(min_dist <= (s1 + s2)) return true;
    
    
    return false;
}
int visited[1001];
vector<vector<int>> graph;

void dfs(int node){
	visited[node] = 1;

	for (auto nei : graph[node]) if(!visited[nei]){
		dfs(nei);
	}
}


void print_graph(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << " ";
        for(auto node : graph[i]){
            cout << node << " ";
        }
        cout << endl;
    }
}

int main(){ _
    int m, n, k;   cin >> m >> n >> k;
    map<pair<int,int>, int> mp1;
    // map<int, pair<int,int>> mp2; 
    vector<int> sensitivity(k);
    
    graph.resize(k+4);


    for(int &sen : sensitivity){
        int x, y;
        cin >> x >> y >> sen;
        mp1[{x, y}] = mp1.size();
        // mp2[mp2.size()] = {x, y};
    }

    for(auto [coord1, v1] : mp1){
        for(auto [coord2, v2] : mp1){
            if(v1 != v2 and sensors_overlap(sensitivity[v1], sensitivity[v2], coord1, coord2)){
                graph[v1].push_back(v2);
            }
        }
        if(coord1.f + sensitivity[v1] >= m) graph[k].push_back(v1), graph[v1].push_back(k);
        if(coord1.f - sensitivity[v1] <= 0) graph[k+1].push_back(v1), graph[v1].push_back(k+1);
        if(coord1.s + sensitivity[v1] >= n) graph[k+2].push_back(v1), graph[v1].push_back(k+2);
        if(coord1.s - sensitivity[v1] <= 0) graph[k+3].push_back(v1), graph[v1].push_back(k+3);
    }
    // print_graph();
    memset(visited, 0, sizeof(visited));
    dfs(k);
    if(visited[k+1]){
        cout << 'N' << endl;
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    dfs(k+2);
    if(visited[k+3]){
        cout << 'N' << endl;
        return 0;
    }
    // memset(visited, 0, sizeof(visited));
    // dfs(k);
    // if(visited[k+2]){
    //     cout << 'N' << endl;
    //     return 0;
    // }
    // memset(visited, 0, sizeof(visited));
    // dfs(k+1);
    // if(visited[k+3]){
    //     cout << 'N' << endl;
    //     return 0;
    // }

    cout << 'S' << endl;
    return 0;
}