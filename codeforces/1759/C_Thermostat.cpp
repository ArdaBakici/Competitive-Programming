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
#define vi vector<int>
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int l, r , x, a, b;
    cin >> l >> r >> x >> a >> b;

    int dist = abs(a-b);
    int per = r-l;

    // case 0

    if(a == b){
        out(0);
        return;
    }

    // case 1

    if(dist >= x){
        out(1);
        return;
    }

    // case 2
    bool atl = (a-l) >= x;
    bool ltb = (b-l) >= x;
    bool atr = (r-a) >= x;
    bool rtb = (r-b) >= x;
    
    if(!(ltb || rtb)){
        out(-1);
        return;
    }

    if(!(atl || atr)){
        out(-1);
        return;
    }

    if((atl && ltb) || (atr && rtb)){
        out(2);
        return;
    }

    out(3);
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
