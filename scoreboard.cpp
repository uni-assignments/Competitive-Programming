#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 20;

void read_input(vector<vector<tuple<float, float, float>>> &teams, int p){
    tuple<float, float, float> crnt_p = {0, 0, 0};
    string tmp1; float tmp0; int solved_problems = 0;
    
    for(int i = 0; i < p; i++){
        cin >> tmp0 >> tmp1;
        if(tmp1[1] != '-'){
            get<0>(crnt_p) = get<0>(crnt_p) + tmp0;
            stringstream ss(tmp1.substr(1, tmp1.size()));
            solved_problems++;
            ss >> tmp0; 
            get<1>(crnt_p) = get<1>(crnt_p) + tmp0;
        }
    }
    get<2>(crnt_p) = 20 * get<0>(crnt_p) + get<1>(crnt_p);
    
    teams[solved_problems].push_back(crnt_p);
}

bool old_scores(const tuple<float, float, float>& a, const tuple<float, float, float>& b){
    return (get<2>(a) > get<2>(b));
}
  
void solve (vector<vector<tuple<float, float, float>>> &teams, int p){
    
    int lower_bound = 1, upper_bound = INF;
    bool flag_ub = false;
    float aux;
    for(int i = 1; i < p + 1; i++){
        if(teams[i].size() < 2) continue;
        for(int j = 0; j < teams[i].size() - 1; j++){
            if(get<0>(teams[i][j+1]) == get<0>(teams[i][j])) continue;
            if(get<0>(teams[i][j]) > get<0>(teams[i][j+1]) and get<1>(teams[i][j]) > get<1>(teams[i][j+1])) continue;
            if(get<2>(teams[i][j]) == get<2>(teams[i][j+1]) or abs(get<1>(teams[i][j]) - get<1>(teams[i][j+1]))/(get<0>(teams[i][j]) - get<0>(teams[i][j+1])) == 20){
                cout << 20 << " " << 20 << endl;
                return ;
            }
            if(get<0>(teams[i][j]) > get<0>(teams[i][j+1])){
                aux = abs(get<1>(teams[i][j]) - get<1>(teams[i][j+1]))/(get<0>(teams[i][j]) - get<0>(teams[i][j+1]));
                if(aux - floor(aux) > 0.0) lower_bound = max(lower_bound, (int) ceil(aux));
                else lower_bound = max(lower_bound, (int) aux + 1);
            } 
            else if(get<0>(teams[i][j]) < get<0>(teams[i][j+1])){
                aux = (get<1>(teams[i][j+1]) - get<1>(teams[i][j]))/(get<0>(teams[i][j]) - get<0>(teams[i][j+1]));
                if(aux - floor(aux) > 0.0) upper_bound = min(upper_bound, (int) floor(aux));
                else upper_bound = min(upper_bound, (int) aux - 1);
                flag_ub = true;
            }
        }
    }
    cout << lower_bound << " ";
    if(flag_ub) cout << upper_bound<< endl;
    else cout << "*" << endl;

}

void print(vector<vector<tuple<float, float, float>>> &teams, int p){
    for (int i = 0; i < p+1 ; i++){
        cout << "Got " << i << " problems correctly" << endl;
        for(auto t: teams[i]){
            cout << "tries: " << get<0>(t) << " time needed: " << get<1>(t) << " total penalty: " << get<2>(t)<< endl;
        }
    }
}

int main(){
    int t, p;
    string line;    

    while(cin >> t >> p){
        if(!t and !p) break;
        vector<vector<tuple<float, float, float>>> teams(p+1);
        while(t--){
            read_input(teams, p);
        }
        for (auto &by_prob : teams){
            sort(by_prob.begin(), by_prob.end(), old_scores);
        }
        // print(teams, p);
        solve(teams, p);
    }
    
    
    return 0;
}