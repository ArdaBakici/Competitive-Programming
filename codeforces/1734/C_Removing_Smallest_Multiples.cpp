#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(ll i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back

using namespace std;

void solve(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    ll ans = 0;
    int num_op = 0;
    int num_req = 0;
    forn(i, n){
        if(t[i] == '0') num_req++;
    }

    forn(i, n){
        if(num_req == num_op){
            break;
        }
        for(ll x = 1; (i+1)*(x) <= n; x++){
            ll index = (((ll)i+1)*(x))-1;
            if(t[index] == '0'){
                ans += (i+1);
                num_op++;
                t[index] = '2';
            }
            else if(t[index] == '2'){
                continue;
            }
            else{
                break;
            }
        }
    }

    cout << ans << endl;
}

int main(){
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