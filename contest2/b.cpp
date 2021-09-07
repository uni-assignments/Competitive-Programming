#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int main(){

    long long n, m; cin >> n >> m;
    cout<< m % (long long )pow(2,n) <<endl;

    return 0;
}