#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int main(){
    
    string jwl;
    set<string> jwls;
    while(cin >> jwl){
        jwls.insert(jwl);
    }

    cout << jwls.size() << endl;
    
    return 0;
}