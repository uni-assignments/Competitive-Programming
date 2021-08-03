#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int s,b;
vector<int> slots, balls;
int memo[130][260][520];


int dp(int i, int ini, int curr){
    if(i == b) return 0; //se colocamos todas as bolas
    if(curr == ini+s-1 or curr == ini+s) return INF; //se geramos uma disposicao invalida
    if(memo[i][ini][curr] != -1) return memo[i][ini][curr]; //se a posicao ja foi calculada
        
    return memo[i][ini][curr] = min(balls[i] * (slots[curr] + slots[curr+1]) + dp(i+1, ini, curr+2), dp(i, ini, curr+1));
}

int main(){ _

    while(true){
        cin >> s >> b;
        if(!s and !b) break;
        slots.resize(2*s), balls.resize(b);

        for(int i = 0; i < s; i++){
            cin >> slots[i];
            slots[s+i] = slots[i];
        }
    
        for(int i = 0; i < b; i++){
            cin >> balls[i];
        }
        memset(memo, -1, sizeof memo);

        int best = INF;
        for(int i = 0; i < s; i++){
            best = min(best, dp(0, i, i)); 
        }

        cout << -best << endl;
         
    }

    return 0;
}