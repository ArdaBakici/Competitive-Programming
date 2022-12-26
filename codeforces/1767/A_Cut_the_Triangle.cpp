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
    vector<p(2)> tri;
    int prev_x = 0;
    int prev_y = 0;

    forn(i, 3){
        int v1, v2;
        cin >> v1 >> v2;
        tri.pb({v1, v2});
    }

    forn(i, 3){
        if(tri[0][0] == tri[1][0]){
            if(tri[0][1] == tri[2][1])
        }
        else if(tri[0][0] == tri[2][0])
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt; cin >> tt; forn(i, tt)
    solve();
    return 0;
}
