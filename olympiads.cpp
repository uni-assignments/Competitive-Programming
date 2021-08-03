#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;



int main(){_

    int n, m, a; cin >> n >> m >> a;
    
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }


    return 0;
}