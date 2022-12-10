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
    int n;
    cin >> n;
    int m = 1000000007;
    int goal = (n*(n+1))/2;
    if(goal % 2){
        out(0);
        return;
    }
    goal /= 2;
    vector<vi> dp(n, vi(goal+1, 0));

    for(int i = n-1; i >= 0; i--){
        for(int k = 0; k <= goal; k++){
            if(k == 0){
                dp[i][k] = 1;
                continue;
            }

            if(i == n-1){
                continue;
            }
            
            if(k-i-1 >= 0) dp[i][k] = dp[i+1][k-i-1];
            dp[i][k] += dp[i+1][k];
            dp[i][k] %= m;
        }
    }
    
    out(dp[0][goal]);
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
