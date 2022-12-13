/*
* Readability first and foremost | 
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

struct segment_tree{
    vi seg;
    int n;

    segment_tree(vi arr){
        n = arr.size();
        seg = vi(2*n);

        forn(i, n){
            seg[i+n] = arr[i];
        }

        rforn(i, n){
            seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    int querry(int l, int r){
        int ans = INT_MAX;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans = min(ans, seg[l++]);
            if(r&1) ans = min(ans, seg[r-1]);
        }
        return ans;
    }

    void modify(int v, int val){
        for(seg[v+=n] = val; v > 1; v >>= 1) seg[v >> 1] = min(seg[v], seg[v ^ 1]);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vi a;

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    segment_tree seg(a);

    forn(i, q){
        int t, v1, v2;
        cin >> t >> v1 >> v2;
        v1--;
        if(t==1) seg.modify(v1, v2);
        else out(seg.querry(v1, v2));
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
