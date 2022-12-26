#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi prefix(n);
    int prev = 0;
    forn(i, n){
        char x = s[i];
        int cur = 0;
        if(x == 'T') cur = 1;
        if(x == 'A') cur = 2;
        if(x == 'M') cur = 3;
        if(x == 'U') cur = 4;
        prefix[i] = cur+prev;
        prev = cur;
    }

    for(int s = 4; s <= n; s+=4){
        forn()
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
