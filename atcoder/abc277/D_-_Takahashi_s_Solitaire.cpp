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
    vi a;
    int total = 0;
    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
        total += input;
    }

    if(n == 1){
        out(0);
        return;
    }

    sort(iter(a));

    int ans = 0;
    int first_sq = -1;
    int tmp_ans = 0;
    forn(i, n){
        if(i == 0){tmp_ans += a[i]; continue;}
        if(a[i] - a[i-1] > 1){
            // broke squence
            if(first_sq == -1){
                first_sq = tmp_ans;
            }
            else{
                ans = max(ans, tmp_ans);
            }
            tmp_ans = 0;
        }
        tmp_ans += a[i];
    }
    if((a[n-1] + 1) % m == a[0]){
        tmp_ans += first_sq == -1 ? 0 : first_sq;
    }
    else{
        ans = max(ans, first_sq);
    }
    ans = max(ans, tmp_ans);
    out(total-ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
