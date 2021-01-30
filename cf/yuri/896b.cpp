#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int t[MAXN];

int main(){
    int n,m,c; cin >> n >> m >> c;
	while(m--){
		int x; cin >> x;
		if(c >= x<<1 ){
            for(int i=1; i<=n; i++){
                if(t[i]>x or !t[i]){
                    t[i]= x;
                    cout << i << endl;
                    break;
                }
            }
        } else {
            for(int i=n; i>0; i--) {
                if(t[i]<x or !t[i]){
                    t[i]=x;
                    cout << i << endl;
                    break;
                }
			}
	    }
        fflush(stdout);
    }
}