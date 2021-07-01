#include <bits/stdc++.h>
using namespace std;


set<int> ans;


void naive_string_matching(string pattern, string text){
    int n = text.size(), m = pattern.size();
    for (int i = 0; i < n - m + 1; i++){
        int k = 0;
        while(pattern[k] != text[i + k]) k++;
        if(k >= m) {
            ans.insert(i);
        }
    }
}



int main (){
    string pattern, text;
    cin >> text;
    cin >> pattern;    

    naive_string_matching(pattern, text);
    cout << ans.size() << endl;

    return 0;
}
