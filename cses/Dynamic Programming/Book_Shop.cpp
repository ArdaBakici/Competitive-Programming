#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define vi vector<int>
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vi price, pages;
    int maxim = 0;

    vi memo(x+1, 0);

    forn(i, n){
        int input;
        cin >> input;
        price.pb(input);
    }

    forn(i, n){
        int input;
        cin >> input;
        pages.pb(input);
    }

    forn(k, n){
        for(int i = x; i - price[k] >= 0; i--){
            memo[i] = max(memo[i], memo[i-price[k]]+pages[k]);
        }
    }

    out(memo[x]);
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