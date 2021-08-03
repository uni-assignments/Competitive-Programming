#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int n;
vector<int> st1, st2, st3;
int memo[101][101][101];

bool movement_is_valid(int a, int b, int c, int amount_a, int amount_b, int amount_c){
    int sum = 0;

    if(!amount_a and !amount_b and !amount_c) return false;
    if( (a + amount_a) > n or (b + amount_b) > n or (c + amount_c) > n) return false;
    
    while(amount_a--)  sum += st1[a], a++;
    while(amount_b--)  sum += st2[b], b++;
    while(amount_c--)  sum += st3[c], c++;
    
    if(sum % 3 == 0) return true;

    return false;
}

int dp(int a, int b, int c){
    if(a == n and b == n and c == n){
        return 1;
    }

    if(memo[a][b][c] != -1) return memo[a][b][c];

    int best_option = 0;

    if(movement_is_valid(a, b, c, 0, 0, 1))
        best_option = max(best_option, dp(a+0, b+0, c+1));
    if(movement_is_valid(a, b, c, 0, 1, 0))
        best_option = max(best_option, dp(a+0, b+1, c+0));  
    if(movement_is_valid(a, b, c, 0, 1, 1))
        best_option = max(best_option, dp(a+0, b+1, c+1));    
    if(movement_is_valid(a, b, c, 1, 0, 0))
        best_option = max(best_option, dp(a+1, b+0, c+0));
    if(movement_is_valid(a, b, c, 1, 0, 1))
        best_option = max(best_option, dp(a+1, b+0, c+1));
    if(movement_is_valid(a, b, c, 1, 1, 0))
        best_option = max(best_option, dp(a+1, b+1, c+0));
    if(movement_is_valid(a, b, c, 1, 1, 1))
        best_option = max(best_option, dp(a+1, b+1, c+1));
    
    return memo[a][b][c] = best_option;
}


int main (){

    while(true){
        cin >> n; 
        if(!n) break;
        st1.resize(n), st2.resize(n), st3.resize(n); 
        for(int i = 0; i < n; i++){
            cin >> st1[i] >> st2[i] >> st3[i];
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0, 0) << endl;
    }

    return 0;
}