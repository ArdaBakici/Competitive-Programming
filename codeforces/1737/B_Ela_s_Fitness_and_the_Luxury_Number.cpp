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
    ll l, r, ans = 0;
    cin >> l >> r;

    ll prev = 0;
    ll high_prev = 0;
    ll low_limit = floor(sqrtl(l));
    ll high_limit = floor(sqrtl(r));

    if(sqrtl(l) == low_limit){
        prev = (low_limit*3)-3; 
    }
    else{
        prev = (low_limit*3)-2;
        ll prev_sqrt = pow(low_limit, 2);
        forn(w, 2){
            if((prev_sqrt+(low_limit*(w+1))) < l){
                prev++;
            }
        }
    }

    if(sqrtl(r) == high_limit){
        high_prev = (high_limit*3)-2; 
    }
    else{
        high_prev = (high_limit*3)-2;
        ll prev_sqrt = pow(high_limit, 2);
        forn(w, 2){
            if((prev_sqrt+(high_limit*(w+1))) <= r){
                high_prev++;
            }
        }
    }

    cout << high_prev - prev << endl;
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