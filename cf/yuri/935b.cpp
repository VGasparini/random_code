#include <bits/stdc++.h>

using namespace std;

typedef struct p{
    int x;
    int y;
}Point;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    Point point;
    int pos, cont = 0;

    // inicia movendo
    if (s[0] == 'R') {
        point.x = 1;
        point.y = 0;
        pos = 0;
    } else {
        point.x = 0;
        point.y = 1;
        pos = 1;
    }
    
    for (int i = 1; i < n; i++){
        if (point.x == point.y){
            if (s[i] == 'R' and pos){
                pos = 0;
                cont++;
            } else if (s[i] == 'U' and !pos){
                pos = 1;
                cont++;
            }
        }
        if (s[i] == 'R') point.x++;
        else point.y++;
    }
    cout << cont << endl;
    return 0;
}