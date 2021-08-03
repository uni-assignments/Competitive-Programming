#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int n;
int memo[1001][1001];
vector<int> seq;

int dp(int l, int r, bool turn){
    
    if(r < l) return 0;
    if(memo[l][r] != -1) return memo[l][r];

    if(!turn){ 
        if((seq[l] - seq[r])%2 == 0) return memo[l][r] = max(dp(l+1, r, !turn) + !(seq[l]%2), dp(l, r-1, !turn) + !(seq[r]%2));
        else if(seq[r]%2) return memo[l][r] = dp(l+1, r, !turn) + 1;
        else return memo[l][r] = dp(l, r-1, !turn) + 1;
        
    }
    else {
        if((seq[l] - seq[r])%2 == 0) return memo[l][r] = min(dp(l+1, r, !turn), dp(l, r-1, !turn));
        else if(seq[r]%2) return memo[l][r] = dp(l+1, r, !turn);
        else return memo[l][r] = dp(l, r-1, !turn);
    }    
}

int main(){

    while(true){
        cin >> n;
        if(!n) break;
        seq.resize(2*n);
        for(int i = 0; i < 2*n; i++){
            cin >> seq[i];
        }
        memset(memo, -1, sizeof(memo));
		cout << dp(0, (2*n)-1, false) << endl;
    }

    return 0;
}