#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n";

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if(n%2 || m%2 || k >(floor(n/2)*floor(m/2))){
        cout << "NO" << endl;
        return;
    }
    
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