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
    int n, m;
    cin >> n >> m;
    multiset<int> pr;
    vi c(m);
    forn(i, n){
        int inp;
        cin >> inp;
        pr.insert(inp);
    } 
    forn(i, m) cin >> c[i];

    for(auto x: c){
        if(pr.size() == 0){
            out(-1);
            continue;
        }
        auto it = pr.lower_bound(x);
        if(it == pr.begin()){
            if(*it <= x){
                out(*it);
                pr.erase(it);
            }
            else out(-1);
            continue;
        }

        if(*it != x){
            it--;
        }

        out(*it);
        pr.erase(it);
    }

}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
