#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

int factorial(int n){
    int fac = 1;
    for(int i=1; i<=n; i++){
        fac *= i;
    }
    return fac;
}

void solve(){
    string s;
    cin >> s;
    vector<int> carr(26, 0);
    string ans;

    for(auto x:s){
        int index = x - 'a';
        carr[index]++;
    }
    
    int fac = factorial(s.length());

    forn(x, carr.size()){
        if(carr[x]>=1){
            char c = x + 'a';
            forn(i, carr[x]) ans.pb(c);
            fac /= factorial(carr[x]);
        }
    }
    
    out(fac);
    out(ans);

    while(next_permutation(iter(ans))){
        out(ans);
    }
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