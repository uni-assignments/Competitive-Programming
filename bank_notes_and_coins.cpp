#include <bits/stdc++.h>
using namespace std;

int main(){
    
    double n; 
    vector<int> notes = {100, 50, 20, 10, 5, 2};
    vector<int> coins = {50, 25, 10, 5, 1};
    
    vector<int> ans(12, 0);
    
    cin >> n;
    int notes_amount = floor(n);
    int coins_amount = (int) ((n - notes_amount) * 100);

    cout << "NOTAS:" << endl;
    for(int i = 0; i < notes.size(); i++){
        cout << notes_amount/notes[i] << " nota(s) de R$ " << std::fixed << setprecision(2) << (float)  notes[i]  <<endl;
        notes_amount = notes_amount % notes[i];
    }
    cout << "MOEDAS:" << endl;
    cout << notes_amount/1 << " moeda(s) de R$ "<< std::fixed << setprecision(2) << 1.00  << endl;
    for(int i = 0; i < coins.size(); i++){
        cout << coins_amount/coins[i] << " moeda(s) de R$ " << std::fixed << setprecision(2) << (float) coins[i]/100  <<endl;
        coins_amount = coins_amount % coins[i];
    }
    
    return 0;
}