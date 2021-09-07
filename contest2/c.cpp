#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, m;

const long long mod = 1e9+7;
int memo[1001][25];

int dp(int i,int j){
    
    if(j <= 0) return 0;
    if(j == 1) return memo[i][j] = n - i + 1;
    
    if(memo[i][j] != -1) return memo[i][j];
    
    int ans = 0;
    for(int k = i; k <= n; k++){
        ans += dp(k,j-1);
        ans %= mod;
    }
    return memo[i][j] = ans;
}

int main(){ _
    
    cin >> n >> m;
    memset(memo, -1, sizeof memo);
    cout << dp(1, 2*m) << endl;

    return 0;
}
