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
    cin >> n;
    vector<int> a;
    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    forn(i, n-2){
        int next = __gcd(a[i], a[i+2]);
        int cur = __gcd(a[i], a[i+1]);
        if(next > cur){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
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