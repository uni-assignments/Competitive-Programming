#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const ll INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
ll n, c, t; 
const ll MAX = 1e5+10;
ll pc[MAX];

bool time_is_possible(ll time){
    ll cmp = 1, pop = t*time;
    
    for(ll i = 0; i < n; i++){
        if(time*t < pc[i]) return false;
        if(pop < pc[i]){
            cmp++;
            pop = t*time - pc[i];   
        } 
        else {
            pop -= pc[i];
        }
        if(cmp > c) return false;
    }

    return true;
}


int main(){ _

    cin >> n >> c >> t;
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        cin >> pc[i];
    }

    ll l = 0, r = 1e9+1, time;
    while(l < r){
        time = (l+r)/2;
        if(time_is_possible(time)) r = time;
        else l = time + 1;
    }
    cout << l << endl;
    return 0;
}
