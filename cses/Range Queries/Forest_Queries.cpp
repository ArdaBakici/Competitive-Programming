/*
* Readability first and foremost
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define forin(i, n) for(int i = 1; i <= n; i++)
#define rforn(i, n) for(int i = n-1; i >= 0; i--)
#define rforin(i, n) for(int i = n; i >= 0; i--)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vi> prefix(n, vi(n, 0));

    forn(x, n){
        string s;
        cin >> s;
        forn(i, n){
            if(s[i] == '*') prefix[x][i]++;
            if(x > 0) prefix[x][i] += prefix[x-1][i];
            if(i > 0) prefix[x][i] += prefix[x][i-1];
            if(x > 0 && i > 0) prefix[x][i] -= prefix[x-1][i-1];
        }
    }
    
    forn(i, q){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        int ans = prefix[x2][y2];
        if(x1 > 0) ans -= prefix[x1-1][y2];
        if(y1 > 0) ans -= prefix[x2][y1-1];
        if(x1 > 0 && y1 > 0) ans += prefix[x1-1][y1-1];
        out(ans);
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
