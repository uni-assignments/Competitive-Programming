#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const int INF = 0x3f3f3f3f;
const int MAX_PAC = 101;
const int MAX_W = 51;

vector<pair<int, int>> pac;
vector <int> chosen;
int memo[MAX_PAC][MAX_W];
int n; 

int knap_sack(int i, int w_left){
    if(w_left < 0) return -INF;
    if(i == n) return 0;
    return (memo[i][w_left] != -1) ? memo[i][w_left] : memo[i][w_left] = max(knap_sack(i+1, w_left), pac[i].f + knap_sack(i+1, w_left-pac[i].s));
}

void retrieve(int i, int w_left){
	if (i == n) return;
	if ((pac[i].f + knap_sack(i+1, w_left-pac[i].s)) >= knap_sack(i+1, w_left))
		chosen.push_back(i), retrieve(i+1, w_left-pac[i].s);
	else retrieve(i+1, w_left);
}

int main (){
    int t; cin >> t;
    while(t--){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            int qt, w; cin >> qt >> w;
            pac.push_back({qt, w});
            for(int j = 0; j <= 50; j++){
                memo[i][j] = -1;
            }
        }
        int total_w = 0, p_l = 0, toys = knap_sack(0, 50);
        retrieve(0, 50);
        for (auto p : chosen){
            total_w += pac[p].s;
        }
        cout << toys << " brinquedos" << endl;
        cout << "Peso: " << total_w << " kg" << endl;
        cout << "sobra(m) " << n-chosen.size() << " pacote(s)" << endl << endl;
        pac.clear();
        chosen.clear();        
    }
    return 0;
}