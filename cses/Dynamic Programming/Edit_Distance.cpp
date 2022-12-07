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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    vector<vi> dp(n+1, vi(m+1, 0));
    
    for(int i = 0; i <= n; i++){
        for(int x = 0; x <= m; x++){
            if(i == 0){
                dp[i][x] = x;
                continue;
            }
            if(x == 0){
                dp[i][x] = i;
                continue;
            }

            if(a[i-1] == b[x-1]) dp[i][x] = min(dp[i-1][x]+1, min(dp[i][x-1]+1, dp[i-1][x-1]));
            else dp[i][x] = min(dp[i-1][x]+1, min(dp[i][x-1]+1, 1+dp[i-1][x-1]));
        }
    }

    out(dp[n][m]);
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
