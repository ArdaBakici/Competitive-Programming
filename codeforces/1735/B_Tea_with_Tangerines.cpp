#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

void solve(){
    int n;
    vector<int> arr;
    cin >> n;
    int min_val = INT_MAX;
    ll ans = 0;
    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
        min_val = min(min_val, input);
    }

    for(auto x: arr){
        if(x >= min_val*2){
            ans += (ll)ceil(((float)x/(((float)min_val*2)-1))-1);
            //cout << x << " " << (ll)ceil(((float)x/(((float)min_val*2)-1))-1) << endl;
        }
    }
    cout << ans << endl;
}

int main(){
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