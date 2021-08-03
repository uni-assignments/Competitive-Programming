#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int n, k;
int memo[101][101];

int dp(vector<int> &seq){
    int ans = 0;
 
    for (int i = 0; i < n; i++){
        memo[i][0] = 1;
        for (int j = 0; j < i; j++) if (seq[i] > seq[j]){
            for (int l = n - j; l >= 0; l--){
                    memo[i][l + 1] += memo[j][l];
            }
        }
        ans += memo[i][k - 1];        
    }
 
    return ans;
}


int main(){ _

    while(true){
        cin >> n >> k;
        if(!n and !k) break;
        
        vector<int> seq(n);
        for(int i = 0; i < n; i++){
            cin >> seq[i];
        }
        memset(memo, 0, sizeof(memo));
        cout << dp(seq) << endl;
    }

    return 0;
}