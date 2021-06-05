#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;

void print_f_row(int d){
    if((d == 1) or (d == 2) or (d == 5) or (d == 8))
        printf("*.");
    else if((d == 3) or (d == 4) or (d == 6) or (d == 7))
        printf("**");
    else 
        printf(".*");
}

void print_s_row(int d){
    if((d == 1) or (d == 3))
        printf("..");
    else if((d == 2) or (d == 6) or (d == 9))
        printf("*.");
    else if ((d == 4) or (d == 5)) 
        printf(".*");
    else 
        printf("**");
}

void print_digits(char **mat, int d){
    for(int i = 0; i < 2*d; i+=2){
        if((mat[0][i] == '*') and (mat[0][i+1] == '.') and (mat[1][i] == '.') and (mat[1][i+1] == '.')) printf("1");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '.') and (mat[1][i] == '*') and (mat[1][i+1] == '.')) printf("2");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '*') and (mat[1][i] == '.') and (mat[1][i+1] == '.')) printf("3");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '*') and (mat[1][i] == '.') and (mat[1][i+1] == '*')) printf("4");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '.') and (mat[1][i] == '.') and (mat[1][i+1] == '*')) printf("5");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '*') and (mat[1][i] == '*') and (mat[1][i+1] == '.')) printf("6");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '*') and (mat[1][i] == '*') and (mat[1][i+1] == '*')) printf("7");
        else if((mat[0][i] == '*') and (mat[0][i+1] == '.') and (mat[1][i] == '*') and (mat[1][i+1] == '*')) printf("8");
        else if((mat[0][i] == '.') and (mat[0][i+1] == '*') and (mat[1][i] == '*') and (mat[1][i+1] == '.')) printf("9");
        else if((mat[0][i] == '.') and (mat[0][i+1] == '*') and (mat[1][i] == '*') and (mat[1][i+1] == '*')) printf("0");
    }
    printf("\n");
}


int main(){
    int d;
    while(true){
        scanf("%d", &d);
        if(!d) break;
        char op; cin >> op;
        if(op == 'S'){
            vector<int> digits(d);
            for (int i = 0; i < d; i++) {
                scanf("%1d", &digits[i]);
            }    
            
            print_f_row(digits[0]);
            for (int i = 1; i < d; i++) {
                printf(" ");
                print_f_row(digits[i]);
            }            
            printf("\n");
            print_s_row(digits[0]);
            for (int i = 1; i < d; i++) {
                printf(" ");
                print_s_row(digits[i]);
            }
            printf("\n");
            printf("..");
            for (int i = 1; i < d; i++) {
                printf(" ..");
            }
            printf("\n");
        }
        else {
            char **mat = (char**) malloc (3*sizeof(char*));
            for (size_t i = 0; i < 3; i++){
                mat[i] = (char*) malloc(2*d*sizeof(char));
            }
            
            for(int i = 0; i < 3; i++){
                scanf("\n%c%c", &mat[i][0], &mat[i][1]);
                for(int j = 2; j < 2*d; j+=2){                    
                    scanf(" %c%c", &mat[i][j], &mat[i][j+1]);
                }
            }
            print_digits(mat, d);
        }
    }
}