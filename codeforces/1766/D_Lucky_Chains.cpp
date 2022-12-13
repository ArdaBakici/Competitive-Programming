#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

int n_max = 10000000+1; 
vi spf(n_max);

void seive(){
    forn(i, n_max){
        spf[i] = i;
    }
    
    for(int i = 2; i * i <= n_max; i++){
        if(spf[i] != i) continue;
        for(int x = i*i; x <= n_max; x+=i){
            spf[x] = min(spf[x], i);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    forn(i, n){
        int v1, v2;
        cin >> v1 >> v2;
        int m_gcd = __gcd(v1, v2); 
        if(m_gcd != 1){
            out(0);
            continue;
        }

        int diff = abs(v1 - v2);

        if(!(diff%2)){
            out((int)(m_gcd == 1));
            continue;
        }

        if(diff == 1){
            out(-1);
            continue;
        }

        int ans = INT_MAX;
        while(diff > 1){
            ans = min(ans, spf[diff] - (v1 % spf[diff]));
            diff /= spf[diff];
        }

        out(ans);
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    solve();
    return 0;
}
