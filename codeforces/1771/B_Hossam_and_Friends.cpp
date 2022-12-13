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
    int n, m;
    cin >> n >> m;
    vi a(n, INT_MAX);
    int ans = 0;

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        if(v1 > v2) swap(v1, v2);
        a[v1] = min(a[v1], v2-1);
    }

    int ma = n-1;
    for(int i = n-2; i >= 0; i--){
        if(a[i] == -1) a[i] = ma;
        if(a[i] > ma){
            a[i] = ma;
        }
        else if(a[i] < ma){
            ma = a[i];
        }
    }

    forn(i, n-1){
        ans += (a[i]+1 - i);    
    }
    ans++;
    out(ans);
}

int32_t main(){
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
