#include <bits/stdc++.h>

using namespace std;

long long t, w;
vector<pair<long long,long long>> times, times_tmp;
 
bool check(int mid){
 
    times_tmp.clear();
    for(auto it : times)
        times_tmp.push_back(it);
    long long restante = t;
    long long atual = t;
 
    priority_queue<long long> pq;
    while(!times_tmp.empty() and times_tmp.back().first > atual){
        pq.push(-(times_tmp.back().second - times_tmp.back().first + 1));
        times_tmp.pop_back();
    }
 
    while(!pq.empty() and pq.size() >= mid){
 
        long long tmp = -pq.top();
        pq.pop();
 
        if(tmp > restante)  return false;
        restante -= tmp;
        atual -= tmp;
 
        while(!times_tmp.empty() and times_tmp.back().first > atual){
            pq.push(-(times_tmp.back().second - times_tmp.back().first + 1));
            times_tmp.pop_back();
        }
    }
    return true;
}
 
 
 
int main(){ 
    int n; cin >> n; n--;
    cin >> t >> w;
    int ans = 1;
    for(int i=0;i<n;i++){
        long long tt, ww;
        cin >> tt >> ww;
        times.push_back({tt, ww});
        if(tt > t)  ans++;
    }

    sort(times.begin(), times.end());
 
    // busca binaria
    int lo = 1, hi = ans-1;
    while(lo <= hi){
 
        int mid = (lo + hi)/2;
        if(check(mid)){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
 
    cout << ans << endl;
}