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
    int total = 0;
    int ans = INT_MAX;
    forn(i, n){
        int input;
        cin >> input;
        total += input;
        if(input%2){
            int x = input;
            int tmp_ans = 0;
            while(x & 1){
                x >>= 1;
                tmp_ans++;
            }
            ans = min(tmp_ans, ans);
        }
        else{
            int x = input;
            int tmp_ans = 0;
            while(!(x & 1)){
                x >>= 1;
                tmp_ans++;
            }
            ans = min(tmp_ans, ans);
        }
    }

    if(!(total%2)){
        out(0);
        return;
    }
    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt; cin >> tt; forn(i, tt)
    solve();
    return 0;
}
