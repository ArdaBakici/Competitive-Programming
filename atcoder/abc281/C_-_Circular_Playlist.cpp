#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n, t;
    cin >> n >> t;
    vi a;
    vi prefix;
    int prev = 0;
    int total = 0;

    forn(i, n){
        int input;
        cin >> input;
        prefix.pb(input + prev);
        total += input;
        a.pb(input);
        prev += input;
    }

    t -= (int)(t/total) * total;
    while(t > total) t -= total;
    
    forn(i, n){
        if(t > a[i]){
            t -= a[i];
            continue;
        }
        cout << i+1 << " " << t;
        return;
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
