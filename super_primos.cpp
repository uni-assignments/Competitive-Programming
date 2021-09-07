#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
 

bool primo(int n){
    if(n <= 1) return false;

    for (int i = 2; i < n; i++) 
        if(!(n % i)) return false;
    
    return true;
}

bool super_primo(int n){
    int aux = n, digit;
    while(aux >= 1){
        digit = aux % 10;
        aux = aux / 10;
        if (!primo(digit)) return false;
    }
    return true;
}

int main(){

    int n;

    while(cin >> n){
        if(primo(n) and super_primo(n))
            cout << "Super" << endl;
        else if(primo(n))
            cout << "Primo" << endl;
        else
            cout << "Nada" << endl;
    }

    return 0;
}


