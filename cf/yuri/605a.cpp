#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> cars;
    cars.assign(n+1,0);
    int maxi = -1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        cars[x] = cars[x-1]+1;
        maxi = max(maxi,cars[x]);
    }
    cout << n-maxi << endl;
    return 0;
}