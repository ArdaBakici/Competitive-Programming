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
    vi a;
    vi dp(n, 0);

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    int ans = 0;

    forn(i, n){
        int maxim = 0;
        forn(x, i){
            if(a[x] < a[i]){
                maxim = max(maxim, dp[x]);
            }
        }
        dp[i] = maxim+1;
        ans = max(ans, maxim+1);
    }

    out(ans);
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
