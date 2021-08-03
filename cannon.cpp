#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int memo[51][101];
vector<pair<int, int>> blt;
int n; 

int knapsack(int i, int cap_left){
    if(cap_left < 0) return -INF;
    if(i == n) return 0;
    
    return (memo[i][cap_left] != -1) ? memo[i][cap_left] : memo[i][cap_left] = max(knapsack(i+1, cap_left), blt[i].f + knapsack(i+1, cap_left-blt[i].s));
}

int main(){_ 

    int t; cin >> t;
    while(t--){
        cin >> n;
        blt.resize(n);
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            blt[i] = {a, b};
            for(int j = 0; j < 101; j++){
                memo[i][j] = -1;
            }
        }
        int k, r; cin >> k >> r;
        if(knapsack(0,k) >= r)
            cout << "Missao completada com sucesso" << endl;
        else 
            cout << "Falha na missao" << endl;
    }

    return 0;
}