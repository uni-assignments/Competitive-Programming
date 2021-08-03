#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, k, v;
vector<int> lf, bs;
double memo[1001][101];
bool calc[1001][101];

double dp(int i, int mn){
    if(i == n) return 0;
    
    if(calc[i][mn])
        return memo[i][mn];

    calc[i][mn] = true;    

    if(mn > 0)
	    return memo[i][mn] = min((double)lf[i]/(double)v + dp(i+1, mn), (double)lf[i]/((double)v + (double)bs[i])+ dp(i+1, mn-1));
	
    return memo[i][mn] = (double)lf[i]/(double)v  + dp(i+1, mn);
    
}


int main(){_

    while(cin >> n >> k >> v){
        lf.resize(n), bs.resize(n);
        for(int i = 0; i < n; i++){
            cin >> lf[i] >> bs[i];
        }
        memset(memo, 0, sizeof(memo));
        memset(calc, false, sizeof(calc));
        cout << setprecision(4) << fixed;
        cout <<  dp(0,k)  << endl;
    }
    
    return 0;
}