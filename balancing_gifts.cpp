#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n;
vector<int> gifts;
int memo[10001][10];

int dp(int i, int dif, int l, int r){
    if(i == n) return 1;
    if(memo[i][abs(dif)] != -1) return memo[i][abs(dif)];
    
    int biggest = 0;

    if (abs(l+gifts[i] - r) <= 5)
		biggest = dp(i+1, abs(l+gifts[i] - r), l+gifts[i], r);
	if (abs(r+gifts[i] - l) <= 5)
		biggest = max(biggest, dp(i+1, abs(r+gifts[i] - l), l, r+gifts[i]));

    return memo[i][abs(dif)] = biggest;
}

int main(){ _

    int t; cin >> t;

    while(t--){
        cin >> n;
        gifts.resize(n);
        for(int i = 0; i < n; i++){
            cin >> gifts[i];
        }
        memset(memo, -1, sizeof memo);
        cout << (dp(0, 0, 0, 0) ? "Feliz Natal!" : "Ho Ho Ho!") << endl;
    }   
    return 0;
}