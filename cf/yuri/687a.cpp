#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
 
bool flag=true;
bool visitados[MAXN];
int col[MAXN];
vector<int> ans[2];
vector<int> vertex[MAXN];
 
int dfs(int u){
	visitados[u]=1;
	ans[col[u]==1].push_back(u);
	for(int i=0;i<vertex[u].size();i++)	{
		int v=vertex[u][i];
		if(!col[v]){
			col[v]=-col[u];
			dfs(v);
		} else if(col[v]==col[u]) {
			flag=false;
		}
	}
	return 1;
}
 
int main(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y; cin >> x >> y;
		vertex[x].push_back(y);
		vertex[y].push_back(x);
	}

    for(int i=1;i<=n;i++){
    	if(!visitados[i]){
			col[i]=1;
			dfs(i);
		}
	}
	
	if(!flag){
		cout << -1 << endl;
	} else {
		for(int i=0;i<2;i++){
			cout<< ans[i].size() << endl;
			for(int j=0; j<ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
