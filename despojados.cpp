#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

void find_prime_divisors(ll n){ //o(sqrt(n))
    int div = 2;
    set<ll> primes;
    while(div*div <= n){
        if(!(n % div)){
            primes.insert(div);
            while(!(n % div)) n = n / div;
        }
        div++;
    }
    if(n != 1) primes.insert(n);

    cout << (1LL << primes.size()) - primes.size() - 1 << endl;
}

int main(){_
    ll n; cin >> n;
    find_prime_divisors(n); 

    return 0;
}

