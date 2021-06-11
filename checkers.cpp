#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX = 20;

vector<vector<int>> current_board;
vector<pair<int, int>> movements = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int calc_pont(pair<int, int> pc){
    int max_mov = 0, new_mov;
    for(auto m : movements){
        if(current_board[pc.f+m.f][pc.s+m.s] == 2) if(current_board[pc.f+2*m.f][pc.s+2*m.s] == 0){
            current_board[pc.f][pc.s] = 0, current_board[pc.f+m.f][pc.s+m.s] = 0;
            max_mov = max(max_mov, 1 + calc_pont({pc.f+2*m.f, pc.s+2*m.s}));
            current_board[pc.f+m.f][pc.s+m.s] = 2;
        }
    }
    return max_mov;
}

int main(){

    int n, m;

    while(cin >> n >> m){

        if(n == 0 and m == 0) break;

        vector<pair<int, int>> my_p;
        vector<vector<int>> board(22, vector<int>(22,22));
        for(int i = 0; i < n+2; i++){
            board[i][0] = 8, board[i][m+1] = 8;
        }
        
        for(int i = 0; i < m+2; i++){
            board[0][i] = 8, board[n+1][i] = 8;
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if((j-i)%2 == 1 or (i-j)%2 == 1) board[i][j] = 0;    
                else {cin >> board[i][j];}
                if(board[i][j] == 1){
                    my_p.push_back(make_pair(i, j));
                }
            }
        }
        int max_p = 0;
        for(auto p : my_p){
            current_board = board;
            max_p = max(max_p, calc_pont(p));
        }

        cout << max_p << endl;
    }

    return 0;
}
