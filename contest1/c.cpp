#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

queue<ll> divs;


void find_divisors(ll n){
    ll div = 2;
    while(n > 1){
        while((n % div) == 0){
            divs.push(div);
            n = n / div;
        }
        div++;
    }
}

ll sum(int n){
    if(n == 1) return n;
    else {
        ll f_div = divs.front(); divs.pop();
        return n + sum(n/f_div);
    }
}

int main (){
    ll n; cin >> n;
    find_divisors(n);
     
    cout << sum(n)<< endl; 
}