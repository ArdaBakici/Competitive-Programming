#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> memo(n+1, 0);
    int m = 1000000007;
    memo[0] = 1;
    fornn(i, n){
        int ans = 0;
        fornn(x, 6){
            if(i-x >= 0){
                ans += memo[i-x];
                ans %= m;
            }
        }
        memo[i] = ans;
    }
    out(memo[n]);
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