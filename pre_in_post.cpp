#include <bits/stdc++.h>
using namespace std;

void post_order(string pre_order, string in_order, int lim){
    int index_root = in_order.find(pre_order[0]);

    if(index_root){
        string new_pre_order = pre_order.substr(1, pre_order.size());
        post_order(new_pre_order, in_order, index_root);
    }
    if(index_root != lim - 1){
        string new_pre_order =pre_order.substr(index_root + 1, pre_order.size());
        string new_in_order = in_order.substr(index_root + 1, in_order.size());
        int new_limit = lim - index_root - 1;
        post_order(new_pre_order, new_in_order, new_limit);
    }
    cout << pre_order[0];
}


int main (){
    int test_cases; cin >> test_cases;
    while (test_cases--){
        int number_nodes; string pre, in; 
        cin >> number_nodes; cin >> pre >> in;
        
        post_order(pre, in, number_nodes);
        cout << endl;
    }
    return 0;
}