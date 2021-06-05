#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;


int main (){
    int n;
    while(cin >> n){
        int flag_st = 1, flag_qu = 1, flag_pq = 1; 
        stack<int> st; queue<int> qu; priority_queue<int> pq;
        while(n--){
            int op, num; cin >> op >> num;
            if(op == 1)
                st.push(num), qu.push(num), pq.push(num);
            else {
                if(st.top() == num) st.pop();
                else flag_st = 0;
                if(qu.front() == num) qu.pop();
                else flag_qu = 0;
                if(pq.top() == num) pq.pop();
                else flag_pq = 0;
            }
        }
        if((flag_st and flag_pq) or (flag_st and flag_qu) or (flag_qu and flag_pq))
            cout << "not sure" << endl;
        else if(flag_st)
            cout << "stack" << endl;
        else if(flag_qu)
            cout << "queue" << endl;
        else if(flag_pq)
            cout << "priority queue" << endl;
        else 
            cout << "impossible" << endl;
    }
    
    return 0;
}