#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long  INF = 0x3f3f3f3f;

int  main(){ _
    int n;
    cin >> n;
    vector<pair<int, char>> t;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        t.emplace_back(a, ')');
        t.emplace_back(b, '(');
    }

    sort(t.begin(), t.end());

    int pessoas = 0;
    int left, right, ans = 0;
    for(int i = 0; i < t.size(); i++){
        if(pessoas == 0) left = t[i].first; 

        if(t[i].second == ')'){
            pessoas++;
        }
        if(t[i].second == '('){
            pessoas--;
            if(pessoas == 0){
                right = t[i].first;
                ans = max((left <= 0 and right - 1 >= 0 ? 1 : 0) + (right-1)/5 - (left-1)/5, ans);
            }
        }
    }

    cout << ans << endl;
}