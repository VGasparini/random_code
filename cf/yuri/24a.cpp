#include<bits/stdc++.h>
using namespace std;

#define MAXN 103

int res,ans,v,u,w;
int s[MAXN],e[MAXN];

int main(){
	int n; cin >> n;
	for (int i=0; i<n; i++){
		cin >> v >> u >> w;
		if (s[v] or e[u]){
            res += w;
            s[u]= 1;
            e[v]= 1;
        } else{
            s[v]= 1;
            e[u]= 1;
        }    
		ans+=w;
	}
	cout << min(res,ans-res) << endl;
}
