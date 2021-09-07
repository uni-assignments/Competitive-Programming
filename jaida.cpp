#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

const int MAX = 1e7;

vector <long long int> primos;
bitset <MAX> is_prime;

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (long long int i = 2; i < MAX; i++){
		if (is_prime[i]){
			primos.push_back(i);
			for (long long int j = i*i; j < MAX; j += i)
				is_prime[j] = 0;
		}
	}
}

int main(){ _

    int t; cin >> t;

    primos.push_back(1);
    sieve();

    while(t--){
        int n; cin >> n;
        vector<int> num(n);
        
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }

        sort(num.begin(), num.end());
        if(num[0] > 1) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;

        for (int i = 0; i < primos.size(); i++){
            int l = 0, m, r = n - 1;
            bool flag = false;
            while(l <= r){
                m = (l+r)/2;
                if (num[m] == primos[i]){
					flag = true;
					ans = max(ans, i);
					break;
				}
				else if (num[m] <= primos[i]) l = m + 1;
				else r = m - 1;
            }

            if (!flag) break;
        }
        
        cout << primos[ans+1] - 1 << endl;
    }

    return 0;
}