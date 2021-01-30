#include <bits/stdc++.h>

#define MAXN 200309
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n,b) for(int x=0; (x)<int(n); (x)+=b)
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;


vector<long long> crivo_str;
vector<long long> pref;

void crivo(int n){
    crivo_str.assign(n, 1);
    FOR(i,n,1){
        int j = i+2;
        for(int k=i; k<n; k+=j){
            crivo_str[k] += j;
        }
    }
    pref.push_back(1);
    FOR(i, crivo_str.size(),1)
        pref.push_back(pref[i] + crivo_str[i]);
}

long long consulta(int n){
    return pref[n-1];
}


int main(){
    vector<int> queries;
    int n, max_n=-1;
    while(scanf("%d", &n) && n!=0){
        queries.push_back(n);
        max_n = max(n, max_n);
    }
    crivo(max_n);
    for(auto i : queries)
        printf("%lld\n", consulta(i));
}