
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

string lines[10], names[10], numbers[10]; 

int get_amount_elements(string line){
    int amount_elements = 0;

    for(char c : line) if(c == 'P'){
        amount_elements++;
    }
    return amount_elements;
}

void print_ans(int num_cols){
    for(int i = 1; i <= num_cols; i++){
            cout << "P" << i << " ";
        }
        cout << "Totals" << endl;
}


void process_line(int current_seller){
    for(char ch : lines[current_seller]){
        if((int) ch > 57 or (int) ch < 48)
            names[current_seller].push_back(ch);
        else 
            numbers[current_seller].push_back(ch);
    }
}

void read_text(){
    int current_seller = 0;    
    while(true){
        cin >> lines[current_seller];
        
        if(lines[current_seller][0] == 'T' and lines[current_seller][1] == 'P') break;
        process_line(current_seller);
        current_seller++;
    }
}

int main(){
    
    int c; cin >> c;
    int num_cols;

    while(c>0){
        string header; cin >> header;
        int num_cols =  get_amount_elements(header); 
        read_text();
    }
    
    return 0;
}
