#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dmg first
#define mana second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int main(){

    int n; cin >> n;
    int aux, saldo = 0, min_i = 0, min_v;

    vector<int> sus_i;
    for(int i = 0; i < n; i++){
        cin >> aux;
        saldo += aux; 
        sus_i[i] = saldo;
        if(aux < min_v){
            min_v = aux;
            min_i = i;
        }
    }

    for(int i = min_i; i < n; i++){
        sus_i[i] -= min_v;
        if()
    }

    if(sus == 0){
        cout << "morete chapou: errou conta" << endl;
    }
    else if(sus == 1){
        cout << "morete chapou: ficou com saldo negativo" << endl;
    }
    else{
        cout << sus;
        for(int i = 0; i < sus_i.size(); i++){
            cout << " " << sus_i[i] + 1;
        }
    }
}