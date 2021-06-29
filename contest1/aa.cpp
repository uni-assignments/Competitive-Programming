#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int main(){ _
    
    int t; cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
    
        cout << (n - n%k) + min((int) (k/2), (n % k)) << endl;
    }
    return 0;
}
