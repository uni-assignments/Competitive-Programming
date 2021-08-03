#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int main(){ _
    int n; cin >> n;
    vector<int> cols(n);
    vector<int> sz_l(n), sz_r(n);


    for(int i = 0; i < n; i++){
        cin >> cols[i];
    }

    sz_l[0] = 1;
    for(int i = 1; i < n; i++){
        if(cols[i] > sz_l[i-1])
            sz_l[i] = sz_l[i-1] + 1;
        else 
            sz_l[i] = cols[i];
    }

    sz_r[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(cols[i] > sz_r[i+1])
            sz_r[i] = sz_r[i+1] + 1;
         else 
            sz_r[i] = cols[i];
    }

    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << sz_l[i] << ' '; 
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << sz_r[i] << ' '; 
    // }

    int max_t = 0;

    for(int i = 0; i < n; i++){
        max_t = max(max_t, min(sz_l[i], sz_r[i]));
    }

    cout << max_t << endl;

    return 0;
}