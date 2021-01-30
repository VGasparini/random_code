#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int tab[10][10];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin >> n;
    int val = true;
    for(int i = 0; i < n; i++){
        int d, l, r, c; cin >> d >> l >> r >> c;
        r--; c--;
        if(d == 0){
            for(int j = 0; j < l; j++){
                if(c+j >= 10){
                    val = false;
                    break;
                }
                tab[r][c+j]++;
            }
        } else {
            for(int j = 0; j < l; j++){
                if(r+j >= 10){
                    val = false;
                    break;
                }
                tab[r+j][c]++;
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(tab[i][j] >= 2) val = false;
        }
    }
    
    if(val) cout << "Y" << endl;
    else cout << "N" << endl;

}