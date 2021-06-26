#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 20;

ofstream file("output.txt");

bool check_fold(vector<int> v, vector<int> out, int sz_v, int sz_o){
    int i = 0, j = sz_v - 1;
    while(v[i] == out[i]){
        i++;
    }
    while(v[i] + v[j] == out[i]){
        i++, j--;
    }
    return i == sz_o;
}

bool solve(vector<int> v, vector<int> out, int sz_v, int sz_o){
    if (accumulate(v.begin(), v.end(), 0) != accumulate(out.begin(), out.end(), 0)) return false;
    if(sz_v < sz_o) return false;
    if(sz_v == sz_o) 
        if (v == out) return true;
        else return false;
}

int main(){_

    int sz_v, sz_o;

    while(cin >> sz_v){
        vector<int> v(sz_v);
        for(int i = 0; i < sz_v; i++) cin >> v[i];
        cin >> sz_o;
        vector<int> out(sz_o);
        for(int i = 0; i < sz_o; i++) cin >> out[i];

        if(check_fold(v, out, sz_v, sz_o)){
            file << "S" << endl;
        }
        else {
            reverse(v.begin(), v.end());    
            if(check_fold(v, out, sz_v, sz_o))
                file << "S" << endl;
            else 
                file << "N" << endl;
        }
    }
    return 0;
}