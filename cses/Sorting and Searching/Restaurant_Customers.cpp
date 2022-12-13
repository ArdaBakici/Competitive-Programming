/*
* Readability first and foremost
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define forin(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    multiset<p(2)> a;

    forn(i, n){
        int v1, v2;
        cin >> v1 >> v2;
        a.insert({v1, 0});
        a.insert({v2, 1});
    }

    int tmp_ans = 0;
    for(auto [x, p]: a){
        if(p == 0) tmp_ans++;
        else tmp_ans--;
        ans = max(tmp_ans, ans);
    }

    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
