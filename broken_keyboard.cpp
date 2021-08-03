#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int solve(string str, int chrs){
    int mx = 0, ans = 0, aux = 0;
    map<char, int> mp;
    for(int i = 0; i < str.size(); i++){
        mp[str[i]]++, mx++;
        if(mp.size() > chrs){
            while(aux < i){
                mx--, mp[str[aux]]--;
                if(mp[str[aux]] == 0){
                    mp.erase(str[aux]);
                    aux++;
                    break;
                }
                aux++;
            }
        }
        ans =  max(mx, ans);
    }
    return ans;
}


int main(){ _

    int n;
    while(true){
        cin >> n;
        cin.ignore();
        if(n == 0) break;
        string str;
        getline(cin, str);
        cout << solve(str, n) << endl;
    }

}