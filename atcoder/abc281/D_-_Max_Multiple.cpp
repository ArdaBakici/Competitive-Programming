#include <iostream>
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

void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    vi a;
    vi fac(n, 0);
    vector<vector<vi>> dp(n, vector<vi>(k+1, vi(d, 0)));

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    forn(i, n){
        fac[i] = a[i]/d;
        a[i] = a[i]%d;
    }

    for(int i = n-1; i >= 0; i--){
        for(int x = 0; x <= k; x++){
            forn(f, d){
                if(x == 0){
                    if(f == 0){
                        dp[i][x][f] = 0;
                        continue;
                    }
                    else{
                        dp[i][x][f] = -1*10e10;
                        continue;
                    }
                }
                if(i == n-1){
                    if(x == 1){
                        if(!((f+a[i])%d)){
                            if(f+a[i] == d) dp[i][x][f] = fac[i]+1;
                            else dp[i][x][f] = fac[i];
                        }
                        else dp[i][x][f] = -1*10e10;
                    }
                    else dp[i][x][f] = -1*10e10;
                    continue;
                }
                if(f+a[i] >= d){
                    dp[i][x][f] = dp[i+1][x-1][(f+a[i]) % d] + 1 + fac[i];    
                }
                else{
                    dp[i][x][f] = dp[i+1][x-1][f+a[i]] + fac[i];
                }
                dp[i][x][f] = max(dp[i][x][f], dp[i+1][x][f]);

            }
        }
    }
    if(dp[0][k][0] < 0){
        out(-1);
        return;
    }
    out(dp[0][k][0] * d);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
