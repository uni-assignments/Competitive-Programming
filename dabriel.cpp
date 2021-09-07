#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n, m, x, y;
int mat[101][101];

int memo[101][101][3][21][21];
bool calc[101][101][3][21][21];

int dp(int i, int j, int dir, int zer, int neg){
  
    if(i == n-1 and j == m-1){
        if ((mat[i][j] == 0 and zer > 0) or (mat[i][j] < 0 and neg > 0) or (mat[i][j] > 0)) return mat[i][j];
        else return INF;
    } 

    int down = INF, left = INF, right = INF;

    if(calc[i][j][dir][zer][neg])
        return memo[i][j][dir][zer][neg];

    if(i < n-1){
        if (mat[i][j] == 0 and zer > 0)
            down = mat[i][j] + dp(i+1, j, 1, zer-1, neg);
        if (mat[i][j] < 0 and neg > 0)
            down = mat[i][j] + dp(i+1, j, 1, zer, neg - 1);
        if (mat[i][j] > 0)
            down = mat[i][j] + dp(i+1, j, 1, zer, neg);
    } 

    if(j < m-1 and dir != 3){
        if (mat[i][j] == 0 and zer > 0)
            right = mat[i][j] + dp(i, j+1, 2, zer-1, neg);
        if (mat[i][j] < 0 and neg > 0)
            right = mat[i][j] + dp(i, j+1, 2, zer, neg-1);
        if (mat[i][j] > 0)
            right = mat[i][j] + dp(i, j+1, 2, zer, neg);
    } 

    if(j > 0 and dir != 2){
        if (mat[i][j] == 0 and zer > 0)
            left = mat[i][j] + dp(i, j-1, 3, zer-1, neg);
        if (mat[i][j] < 0 and neg > 0)
            left = mat[i][j] + dp(i, j-1, 3, zer, neg-1);
        if (mat[i][j] > 0)
            left = mat[i][j] + dp(i, j-1, 3, zer, neg);
    } 

    calc[i][j][dir][zer][neg] = true;

    return memo[i][j][dir][zer][neg] = min(min(down, left), right);
}

int main(){ _

    while(cin >> n >> m >> x >> y){
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mat[i][j];
            }
        }
        memset(calc, false, sizeof(calc));
        int ans = dp(0, 0, 2, x, y);

        if(ans > 1000000) 
            cout << "Impossivel" << endl;
        else 
            cout << ans << endl;
    }

    return 0;
}