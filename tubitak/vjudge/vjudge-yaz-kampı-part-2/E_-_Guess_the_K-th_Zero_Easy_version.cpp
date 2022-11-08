#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long int

using namespace std;

void solve();

int main(){
    solve();
    return 0;
}

void solve(){
    int n, t, k;
    cin >> n >> t >> k;

    int l=1, r=n;
    int ans = INT_MAX;

    forn(i, 20){
        if(l > r || r < l){
            break;
        }
        int m = l + ((r-l)/2);
        int res;
        cout << "? 1 " << m << endl;
        cin >> res;
        if((m-res) > k){
            r = m-1;
        }
        else if((m-res) < k){
            l = m+1;
        }
        else{
            ans = min(m, ans);
            r = m-1;
        }
    }
    cout << "! " << ans << endl;
    return;
}
