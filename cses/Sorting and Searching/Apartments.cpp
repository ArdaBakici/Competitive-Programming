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
    int n, m, k;
    cin >> n >> m >> k;
    vi a, b;

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    forn(i, m){
        int input;
        cin >> input;
        b.pb(input);
    }

    sort(iter(a));
    sort(iter(b));

    int pt1 = 0, pt2 = 0;
    int ans = 0;

    while(pt1 < n && pt2 < m){
        if(abs(a[pt1] - b[pt2]) <= k){
            ans++; pt1++; pt2++;
        }
        else{
            if(a[pt1] < b[pt2]) pt1++;
            else pt2++;
        }
    }

    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
