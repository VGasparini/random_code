#include <bits/stdc++.h>
 
using namespace std;

typedef pair<long long, long long> ii;

vector<ii> times, times_restantes;
 
bool teste(int mid){
    long long restantes = t;
    long long atual = t;
 
    times_restantes.clear();
    for(auto it : times) times_restantes.push_back(it);
 
    priority_queue<long long> pq;
    while(!times_restantes.empty() and times_restantes.back().first > atual){
        pq.push(-(times_restantes.back().second - times_restantes.back().first + 1));
        times_restantes.pop_back();
    }
 
    while(!pq.empty() and pq.size() >= mid){
 
        long long tmp = -pq.top();
        pq.pop();
 
        if(tmp > restantes) return false;
        restantes -= tmp;
        atual -= tmp;
 
 
        while(!times_restantes.empty() and times_restantes.back().first > atual){
            pq.push(-(times_restantes.back().second - times_restantes.back().first + 1));
            times_restantes.pop_back();
        }
    }
 
    return true;
}
 
int main(){
 
    int n; cin >> n;
    n--;
    long long t,w; cin >> t >> w;
    int ans = 1;
    
    for(int i=0;i<n;i++){
        long long tt, ww; cin >> tt >> ww;
        times.push_back(make_pair(tt, ww));
        if(tt > t) ans++;
    }

    sort(times.begin(), times.end());
 
    int lo = 1, hi = ans-1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(teste(mid)){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
 
    cout << ans << endl;
    return 0;
}