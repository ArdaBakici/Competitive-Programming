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
    vi dp(n, INT_MAX);

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    forn(i, n){
        int l = 0;
        int r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(dp[m] < a[i]) l = m+1;
            else r = m-1;
        }
        dp[min(l, r)+1] = a[i];
    }

    for(int i = n-1; i >= 0; i--){
        if(dp[i] != INT_MAX){
            out(i+1);
            return;
        }
    }
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
