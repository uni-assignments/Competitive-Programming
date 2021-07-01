#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const int INF = 0x3f3f3f3f;

int main (){

    int n, m; cin >> n >> m;
    bitset<1000> lamps;   
    vector<bitset<1000>> in(n);
    int l, aux; cin >> l;
    int ans = -1;
    
    while(l--){
        cin >> aux;
        lamps[aux - 1] = 1;
    } 
    
    for(int i = 0; i < n; i++){
        cin >> l;
        for(int j = 0; j < l; j++){
            cin >> aux;
            in[i][aux - 1] = 1;
        }      
    }  
    
    for(int i = 0; i < 2*n; i++){
        lamps ^= in[i % n];
        if(lamps.none()){
            ans = i + 1;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}