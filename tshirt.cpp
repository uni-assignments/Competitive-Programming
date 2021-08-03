#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, m;
int graph[36][30];
bool vis[36];
int tshirts[36];

bool dfs(int vol){
    for (int i = 0; i < n; i++) if (graph[vol][i] && !vis[i]){
        vis[i] = true;
        if (tshirts[i] == -1 or dfs(tshirts[i])){
            tshirts[i] = vol;
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


map<string, int> dict = {{"XS", 0}, {"S", 1}, {"M", 2}, {"L", 3}, {"XL", 4}, {"XXL", 5}};

int main (){ _

        
    int t; cin >> t;
    while(t--){
        cin >> n >> m;

        for(int i = 0; i < 36; i++){
            for(int j = 0; j < 30; j++){
                graph[i][j] = 0;
            }
        }
        string str1, str2;
        int t1, t2;
        for(int i = 0; i < m; i++){
            cin >> str1 >> str2;
            t1 = dict[str1], t2 = dict[str2];
            for(int j = 0; j < n/6; j++){
                graph[i][t1*n/6 + j] = 1;
                graph[i][t2*n/6 + j] = 1;
            }
        }

        memset(tshirts, -1, sizeof(tshirts));
        cout << (match() == m ? "YES" : "NO") << endl;
    }
    return 0;
}