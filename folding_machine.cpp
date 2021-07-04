#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 20;

ofstream file("output.txt");
char ans;
bool check_fold(vector<int> &v, vector<int> &out){
    
    if(v.size() != out.size()) return false;
    int i = 0;
    while(v[i] == out[i] and i < out.size()) i++;
    if(i == v.size()) return true;
    
    return false;    
}

vector<int> gen_fold(vector<int> &v, int cut){
        
    vector<int> new_v;
    list<int> left, right;
    for(int i = 0; i < v.size(); i++){
        if(i < cut) left.push_front(v[i]);
        else right.push_back(v[i]);
    }

    std::list<int>::iterator it_l = left.begin(), it_r = right.begin();
    while(it_l != left.end() and it_r != right.end()){
        new_v.push_back(*it_l + *it_r);
        it_l++, it_r++;
    }
    while(it_l != left.end()) new_v.push_back(*it_l), it_l++;
    while(it_r != right.end()) new_v.push_back(*it_r), it_r++;   
    return new_v;
}

void solve(vector<int> v, vector<int> &out){
    if(v.size() < out.size()) return;
    if(check_fold(v, out)){
        ans = 'S';
        return;
    }
    
    for(int i = 1; i < v.size(); i++){
        vector<int> n = gen_fold(v, i);
        solve(n, out);
    }   
    
}


int main(){_

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