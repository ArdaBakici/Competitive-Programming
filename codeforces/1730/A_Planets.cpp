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
    ll n, c;
    cin >> n >> c;
    vector<ll> orbit(101, 0);
    forn(i, n){
        ll input;
        cin >> input;
        orbit[input]++;
    }
    ll ans = 0;

    forn(i,101){
        if(orbit[i] > c){
            ans += c;
        }
        else{
            ans += orbit[i];
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