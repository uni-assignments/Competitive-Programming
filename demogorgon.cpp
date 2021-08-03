#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dmg first
#define mana second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, p;
vector<pair<int, int>> spell;
int memo[1001][2001];


int dp(int i, int health){
    if(i == n and health > 0) return INF;
    if(health <= 0) return 0;

    return (memo[i][health] != -1) ? memo[i][health] : memo[i][health] = min(dp(i+1, health - spell[i].dmg) + spell[i].mana, dp(i+1, health));
}

int main(){ _

    while(cin >> n >> p){
        spell.resize(n);
        int total_dmg = 0;
        for(int i = 0; i < n; i++){
            int dm, mn; cin >> dm >> mn;
            total_dmg += dm;
            spell[i] = {dm, mn};
        }
        memset(memo, -1, sizeof(memo));
        if(total_dmg < p) cout << -1 << endl;
        else cout << dp(0, p) << endl;
    }

    return 0;
}
