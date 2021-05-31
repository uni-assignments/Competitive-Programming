#include <bits/stdc++.h>
using namespace std;

bool try_dim(int dim1, int dim2, int l, map<int, int, greater<int>> planks){
      
    int rows_needed = dim1*100/l, planks_used = 0;
    map<int, int>::iterator it;
    if(!(dim1*100 % l)){
        for (it=planks.begin(); it!=planks.end() ; it++){
            while((*it).second != 0 and rows_needed){ //enquanto ainda tem tabuas desse tamanho
                (*it).second--;
                if((*it).first == dim2) {
                    rows_needed--, planks_used++; } //se for do tamanho certinho adiciona
                
                else if(planks[dim2 - (*it).first]){ //se tiver tabua que complementa
                    rows_needed--, planks_used +=2,  planks[dim2 - (*it).first]--; }
                
                else break;
            }
        }
        if(!rows_needed) {
            cout << planks_used<< endl;
            return true;
        }
    }
    return false;
}

void check_if_its_possible(int n, int m, int l, map<int, int, greater<int>> planks){
    if(!try_dim(n, m, l, planks) and !try_dim(m, n, l, planks))
        cout << "impossivel" << endl;
}

int main(){
    int n, m, l, k, aux;

    while(true){
        map<int, int, greater<int> > planks;
        cin >> n >> m;
        if(!n and !m) 
            break;
        
        cin >> l; cin >> k;
        for (int i = 0; i < k; i++){
            cin >> aux;
            if(aux <= max(m, n)) 
                planks[aux]++;
        }
        check_if_its_possible(n, m, l, planks);
    }    
}