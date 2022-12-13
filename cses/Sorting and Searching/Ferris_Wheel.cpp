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
    int n, cap;
    cin >> n >> cap;
    vi a(n);
    int ans = 0;
    vector<bool> put(n, false);
    forn(i, n) cin >> a[i];
    sort(iter(a));
    int p1 = 0, p2 = n-1;

    while(p1 < p2){
        if((a[p1] + a[p2]) <= cap){
            ans++;
            put[p1] = true;
            put[p2] = true;
            p1++; p2--;
        }
        else{
            put[p2] = true;
            p2--;
            ans++;
        }
    }
    if(p1==p2 && !put[p1]) ans++;
    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
