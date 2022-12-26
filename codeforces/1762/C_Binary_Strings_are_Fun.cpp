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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 998244353;
    char prev;
    int prev_int = 0;
    int ans = 0;
    forn(i, n){
        if(i == 0){
            ans += 1;
            prev_int = 1;
            prev = s[i];
            continue;
        }
        if(s[i] == prev){
            prev_int *= 2;
            prev_int %= m;
        }
        else{
            prev_int = 1;
        }
        prev = s[i];
        ans += prev_int;
        ans %= m;
    }
    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt; cin >> tt; forn(i, tt)
    solve();
    return 0;
}
