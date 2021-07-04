#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long


const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

class Hand {
    public:
        Hand(){}
        bool wild_card = false;
        bool this_round;
        map<char, int> hand;


        bool first_is_smaller(char f, char s){
            map<char, int> order;
            order['A'] = 1;
            order['2'] = 2;
            order['3'] = 3;
            order['4'] = 4;
            order['5'] = 5;
            order['6'] = 6;
            order['7'] = 7;
            order['8'] = 8;
            order['9'] = 9;
            order['D'] = 10;
            order['Q'] = 11;
            order['J'] = 12;
            order['K'] = 13;

            if(order[f] < order[s]){
                return true;
            }
            return false;
        }

        bool check_if_won(){
            if(wild_card) return false;
            for (auto i = hand.begin(); i != hand.end(); i++) if(i->second == 4){
                return true;
            }
            return false;
        }
        void recieve_card(char c){
            if(c == 'W'){
                // cout << " recebeu wildcard ";
                wild_card = true, this_round = true;
            }
            else {
                // cout << " recebeu " << c;
                hand[c]++;

            }
        }
        char discard(){
            if(wild_card and !this_round){
                // cout << " e descartou wildcard" << endl;
                wild_card = false;
                return 'W';
            } 
            this_round = false;
            auto min = hand.begin();
            while(!min->second) min++;
            for (auto i = hand.begin(); i != hand.end(); i++) if(i->second){
                if(min->second == i->second and first_is_smaller(i->first, min->first)) min = i;
                else if(min->second > i->second)  min = i;
            }
            hand[min->first] -= 1;
            // cout << " e descartou " << min->first << endl;
            return min->first;
        }
        void print_hand(){
             for (auto i = hand.begin(); i != hand.end(); i++){
                for(int j = 0; j < i->second;j++){
                    cout << i->first;
                }
            }
            if(wild_card) cout << 'W';
        }
};

int main (){
    int n, k; cin >> n >> k;
    string str;
    vector<Hand> pl(n);
    for(int i = 0; i < n; i++){
        Hand h = Hand();
        char aux;
        for(int j = 0; j < 4; j++){
            cin >> aux;
            h.hand[aux]++;
        }
        pl[i] = h;
    }
    char c = 'W';  int i = k - 1;

    for(int i = 0; i < n; i++){
        if(i != k - 1){
            if(pl[i].check_if_won()){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }    


    while(true){
        // cout << i << " - ";
        // pl[i].print_hand();
        pl[i].recieve_card(c);
        if(pl[i].check_if_won()){
            cout << i + 1 << endl;
            break;
        }
        c = pl[i].discard();
        if(pl[i].check_if_won()){
            cout << i + 1 << endl;
            break;
        }
        i++;
        if(i == n) i = 0;
    }
    return 0;
}