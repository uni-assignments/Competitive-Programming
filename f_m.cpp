#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 20;




int main(){
    int sz_v, sz_o;
    while(cin >> sz_v){
        ans = 'N';
        vector<int> v(sz_v);
        for(int i = 0; i < sz_v; i++) cin >> v[i];
        cin >> sz_o;
        vector<int> out(sz_o);
        for(int i = 0; i < sz_o; i++) cin >> out[i];
        
        if(accumulate(v.begin(), v.end(), 0) == accumulate(out.begin(), out.end(), 0)){
            solve(v, out);
            reverse(v.begin(), v.end());
            solve(v, out);
            reverse(out.begin(), out.end());
            solve(v, out);

        }
        
        file << ans << endl;

    }
    return 0;
}