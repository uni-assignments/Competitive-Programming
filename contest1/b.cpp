#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define ll long long

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

int main(){ _
    
    string str; 
    cin >> str;
    int count = 0;
    string new_str = "";
    
    // removes useless chars
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A' or str[i] == 'Q'){
            new_str.push_back(str[i]);
        }
    }
    int n_qs = 0, qs_left = 0;
    
    for (int i = 0; i < new_str.size(); i++) if (new_str[i] == 'Q') {
        n_qs++;
	}
    for (int i = 0; i < new_str.size(); i++) {
        if (new_str[i] == 'Q')  
            qs_left++, n_qs--;
        if (new_str[i] == 'A')  
            count += n_qs*qs_left;        
	}
    cout << count << endl;
    return 0;
}
