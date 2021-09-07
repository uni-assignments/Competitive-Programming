#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long

ll n, e, c; 

ll euler_phi(){
    ll phi = 0;
    for(int i = 2; i*i <= n; i++) if((n % i) == 0) {
        phi = (i - 1)*( n/i - 1); 
        break;
    }
    
    return phi;
}

int gcd_extended(ll a, ll b, ll &x1, ll &y1){
	if(a == 0){
		x1 = 0, y1 = 1;
		return b;
	}

	ll x2, y2, gcd = gcd_extended(b % a, a, x2, y2);
	y1 = x2;
	x1 = y2 - (b / a) * x2;

	return gcd;
}

ll fast_exp(ll a, ll b){
	if(b == 0) return 1;
	if(b % 2 == 0) return fast_exp(a * a % n, b/2);
	
    return a * fast_exp(a, b - 1) % n;
}

int main(){ _
	
    while(cin >> n >> e >> c){
        
        ll phi = euler_phi();
        ll x, y; gcd_extended(e, phi, x, y);
        ll ans =  fast_exp(c, ( x + phi ) % phi);
        
        cout << ans << endl;
    }

    return 0;
}