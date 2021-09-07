#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const int MAX = 2*1e6+100;

int n;
vector<int> divisors(MAX), ans(MAX);
bitset <MAX> is_prime;

void hyperprimes() {
    is_prime.set();
	is_prime[0] = 0, is_prime[1] = 0;

	for (int i = 2; i < MAX; i++) if(is_prime[i]){
        divisors[i] = 2;
        for (int j = (i + i); j < MAX; j += i){
            int cnt = 0, aux = j;
            is_prime[j] = 0;
            while (aux % i == 0) aux /= i, cnt++;
            if (aux != 1) cnt *= 2;
            cnt++;
            if (divisors[j] == 0) divisors[j] += cnt;
            else divisors[j] *= cnt;
        }
	}

    ans[1] = 0;
    for (int i = 2; i < MAX; i++){
        ans[i] = ans[i - 1];
		if (is_prime[divisors[i]]) ans[i]++;
	}
}

int main() { _

    hyperprimes();
    while(cin >> n) {
        cout << ans[n] << endl;
    }
    
    return 0;
}