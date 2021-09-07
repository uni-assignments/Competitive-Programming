#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

const int MAX = 1e7+10;

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

    sieve();

    bool achou = false;
    int l = 0, m, r = primos.size() - 1, i = INF, j = -INF;
    int a, b; cin >> a >> b;
    
    if(a == b) {
        cout << "?" << endl;
        return 0;
    }

    if(a > b) swap(a, b);
    
    while(l < r){
        m = (l+r)/2;
        if(primos[m] < a) l = m + 1;
        else i = min(i, m), r = m, achou = true;
    }

    if(!achou) {
        cout << "Bob" << endl;
        return 0;
    }

    achou = false;
    l = 0, r = primos.size() - 1;
    while(l < r){
        m = (l+r)/2;
        if(primos[m] > b)  r = m;
        else j = max(j, m), l = m + 1, achou = true;
    }
    
    if(!achou) {
        cout << "Bob" << endl;
        return 0;
    }

    int qtd_primos = j - i + 1, k = b - a;
    cout << (((k + (qtd_primos - 1)) | k) == (k + (qtd_primos - 1)) ? "Alice" : "Bob" ) << endl;

    return 0;
}