#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dmg first
#define mana second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int n;

int main (){

    cin >> n;
    int dif = -1, a, b;
    bool flag = true;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if(dif != -1 and dif != a - b){
            flag = false;
        }
        dif = a - b;
    }

    if(flag)
        cout << "idades corretas" << endl;
    else 
        cout << "mentiu a idade" << endl;

}