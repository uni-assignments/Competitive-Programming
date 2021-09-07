#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dmg first
#define mana second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long  INF = 0x3f3f3f3f;

long long  n;


int  main(){

    cin >> n;

    vector<long long > v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    v.push_back(-1);

    long long  min = -1;

    for(int i = 0; i < (int)v.size() - 1; i++){
        if((i+1)%3 == 0){
            if(v[i] != v[i+1]){
                min = v[i];
            }
        }
    }

    cout << min << endl;

    return 0;
}