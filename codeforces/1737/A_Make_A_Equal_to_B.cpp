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
    string a;
    string b;
    
    forn(i, n){
        char input;
        cin >> input;
        a.pb(input);
    }

    forn(i, n){
        char input;
        cin >> input;
        b.pb(input);
    }

    int na = 0;
    int nb = 0;

    forn(i, a.length()){
        if(a[i] == '1'){
            na++;
        }
    }

    forn(i, a.length()){
        if(b[i] == '1'){
            nb++;
        }
    }

    int nd = 0;

    forn(i, a.length()){
        if(a[i] != b[i]){
            nd++;
        }
    }

    cout << min(abs(na-nb) + 1, nd) << endl;
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