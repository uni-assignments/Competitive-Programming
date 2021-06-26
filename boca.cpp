#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int main(){ _
    
    unsigned long long int num = 0; 
    string str; cin >> str;
    
    for(int i = 0; i < str.size();i++)   num += str[i]-'0';
    cout << num % 3 << endl;
    
    return 0;
}
