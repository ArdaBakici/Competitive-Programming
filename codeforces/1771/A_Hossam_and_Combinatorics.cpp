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
    int max_el = 0;
    int min_el = INT_MAX;

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
        min_el = min(min_el, input);
        max_el = max(max_el, input);
    }

    int t = 0;
    int b = 0;
    if(min_el == max_el){
        out(n*(n-1));
        return;
    }
    for(auto x: a){
        if(x == min_el) t++;
        if(x == max_el) b++;
    }

    out(2*t*b);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
