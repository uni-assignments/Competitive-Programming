#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const int MOD = 1e6;


vector<vector<long long>> mult(vector<vector<long long>> A, vector<vector<long long>> B){
	
    vector<vector<long long>> ans = {{0, 0}, {0, 0}};

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				ans[i][j] = (ans[i][j] % MOD + A[i][k] * B[k][j] % MOD) % MOD;

	return ans;
}

vector<vector<long long>> exp(vector<vector<long long>> m, long long exp){
	
    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
	
    while(exp){
		if(!(exp % 2)) m = mult(m, m), exp /= 2;
		else ans = mult(ans, m), exp--;
	}

    return ans;
}

int main(){	

    long long n, l, k;
	
	while (cin >> n >> k >> l){
		n /= 5;
		vector<vector<long long>> mtx = {{0, l % MOD}, {1, k % MOD}};
		vector<vector<long long>> ans = exp(mtx, n);
		
        if(!ans[1][1]) cout << "000000" << endl;
        else {
            for (int i = 0; i < 5 - floor(log10(ans[1][1])); i++) 
                cout << 0;
            
            cout << ans[1][1] << endl;
        }
    }

	return 0;
}