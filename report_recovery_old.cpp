#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;


int calc_number(int n, string header){
    
    int amount = 0;
    for(int i = 0; i <= n; i++){
        amount += pow(10, n - i) * ((int) header[i] -  48);  
    }
    // cout << amount << " " << " ";
    return amount;
}

void div1(string header){
    for(int i = 0; i < header.size() - 1; i++){
        int p1 = calc_number(i, header.substr(0, i + 1));
        int total = calc_number(header.size() - i - 2, header.substr(i + 1, header.size()));

        if((header.substr(0, i + 1)[0] - '0' == 0) and i > 0) continue;
        if((header.substr(i + 1, header.size())[0] - '0' == 0) and (header.size() - i - 2) > 0) continue;

        if(p1 == total){
            cout << p1 << " " << total << endl;
            return ;
        }
    }
}
//problema 01
void div2(string header){
    for(int i = 0; i < header.size() - 1; i++){
        for (int j = i + 1; j < header.size(); j++){
            if(i == j) continue;
            int p1 = calc_number(i, header.substr(0, i + 1));
            int p2 = calc_number(j - i - 1, header.substr(i+1, j));
            int total = calc_number(header.size() - j - 2, header.substr(j + 1, header.size()));
            
            if((header.substr(0, i + 1)[0] - '0' == 0) and i > 0) continue;
            if((header.substr(i+1, j)[0] - '0' == 0) and (j - i - 1) > 0) continue;
            if((header.substr(j + 1, header.size())[0] - '0' == 0) and (header.size() - j - 2) > 0) continue;

            if(p1 + p2 == total){
                cout << p1 << " " << p2 <<" "<< total << endl;
                return ;
            }
        }
    }
}


void div3(string header){
    for(int i = 0; i < header.size() - 2; i++){
        for (int j = i + 1; j < header.size() - 1; j++){
            if(i == j) continue;
            for (int l = j + 1; l < header.size(); l++){
                if(l == j or l == i) continue;
                int p1 = calc_number(i, header.substr(0, i + 1));
                int p2 = calc_number(j - i - 1, header.substr(i+1, j));
                int p3 = calc_number(l - j - 1, header.substr(j+1, l));
                int total = calc_number(header.size() - l - 2, header.substr(l + 1, header.size()));

                if((header.substr(0, i + 1)[0] - '0' == 0) and i > 0) continue;
                if((header.substr(i+1, j)[0] - '0' == 0) and (j - i - 1) > 0) continue;
                if((header.substr(j + 1, l)[0] - '0' == 0) and (l - j - 1) > 0) continue;
                if((header.substr(l + 1, header.size())[0] - '0' == 0) and (header.size() - l - 2) > 0) continue;

                if(p1 + p2 + p3 == total){
                    cout << p1 << " " << p2 << " "<< p3 <<" "<< total << endl;
                    return ;
                }
            }
        }
    }
}

void div4(string header){
    for(int i = 0; i < header.size() - 3; i++){
        for (int j = i + 1; j < header.size() - 2; j++){
            if(i == j) continue;
            for (int l = j + 1; l < header.size() - 1; l++){
                if(l == j or l == i) continue;
                for (int k = l + 1; k < header.size(); k++){
                    if(k == l or k == j or k == i) continue;

                    int p1 = calc_number(i, header.substr(0, i + 1));
                    int p2 = calc_number(j - i - 1, header.substr(i+1, j));
                    int p3 = calc_number(l - j - 1, header.substr(j+1, l));
                    int p4 = calc_number(k - l - 1, header.substr(l+1, k));
                    int total = calc_number(header.size() - k - 2, header.substr(k + 1, header.size()));


                    if((header.substr(0, i + 1)[0] - '0' == 0) and i > 0) continue;
                    if((header.substr(i+1, j)[0] - '0' == 0) and (j - i - 1) > 0) continue;
                    if((header.substr(j + 1, l)[0] - '0' == 0) and (l - j - 1) > 0) continue;
                    if((header.substr(l+1, k)[0] - '0' == 0) and (k - l - 1) > 0) continue;
                    if((header.substr(k + 1, header.size())[0] - '0' == 0) and (header.size() - k - 2) > 0) continue;

                    if(p1 + p2 + p3 +p4 == total){
                        cout << p1 << " " << p2 << " "<< p3 <<" "<< p4 <<" " << total << endl;
                        return ;
                    }
                }
            }
        }
    }
}

void div5(string header){
    for(int i = 0; i < header.size() - 4; i++){
        for (int j = i + 1; j < header.size() - 3; j++){
            if(i == j) continue;
            for (int l = j + 1; l < header.size() - 2; l++){
                if(l == j or l == i) continue;
                for (int k = l + 1; k < header.size() - 1; k++){
                    if(k == l or k == j or k == i) continue;
                    for(int m = k + 1; m < header.size(); m++){
                        if(m == l or m == j or m == i or m == k) continue;
                        
                        int p1 = calc_number(i, header.substr(0, i + 1));
                        int p2 = calc_number(j - i - 1, header.substr(i+1, j));
                        int p3 = calc_number(l - j - 1, header.substr(j+1, l));
                        int p4 = calc_number(k - l - 1, header.substr(l+1, k));
                        int p5 = calc_number(m - k - 1, header.substr(k+1, m));
                        int total = calc_number(header.size() - m - 2, header.substr(m + 1, header.size()));

                        if((header.substr(0, i + 1)[0] - '0' == 0) and i > 0) continue;
                        if((header.substr(i+1, j)[0] - '0' == 0) and (j - i - 1) > 0) continue;
                        if((header.substr(j+1, l)[0] - '0' == 0) and (l - j - 1) > 0) continue;
                        if((header.substr(l+1, k)[0] - '0' == 0) and (k - l - 1) > 0) continue;
                        if((header.substr(k+1, m)[0] - '0' == 0) and (m - k - 1) > 0) continue;
                        if((header.substr(m+1, header.size())[0] - '0' == 0) and (header.size() - m - 2) > 0) continue;
                        
                        if(p1 + p2 + p3 + p4 + p5 == total){
                            cout << p1 << " " << p2 << " "<< p3 <<" "<< p4 <<" " << p5 << " " << total << endl;
                            return ;
                        }
                    }    
                }
            }
        }
    }
}

void switch_amount_columns(string header, int num_divs){
    switch (num_divs){
        case 1:
            div1(header);
            break;
        case 2:
            div2(header);
            break;
        case 3:
            div3(header);
            break;
        case 4:
            div4(header);
            break;
        case 5:
            div5(header);
            break;
        default:
            break;
    }
}

int get_amount_elements(string line){
    int amount_elements = 0;

    for(char c : line) if(c == 'P'){
        amount_elements++;
    }
    return amount_elements;
}

int main(){
    
    int c; cin >> c;
    int amount_elements;

    while(c>0){
        string line, name, numbers; cin >> line;

        if(line.find("Totals") != string::npos){
            amount_elements = get_amount_elements(line); 
            for(int i = 1; i <= amount_elements; i++){
                cout << "P" << i << " ";
            }
            cout << "Totals" << endl;
        }
        else {
            if(line[0] == 'T' and line[1] == 'P') c--;
            for(char ch : line){
                if((int) ch > 57 or (int) ch < 48)
                    name.push_back(ch);
                else 
                    numbers.push_back(ch);
            }
            cout << name << " ";
            switch_amount_columns(numbers, amount_elements);            
        }
    }
    
    return 0;
}
