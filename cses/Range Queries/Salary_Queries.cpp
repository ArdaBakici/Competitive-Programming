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

vi vals;

struct segment_tree{
    vi seg;
    int n;

    segment_tree(int s, vi arr){
        n = s;
        seg = vi(2*n, 0);

        for(auto x: arr){
            seg[x+n]++;
        }

        rforn(i, n){
            seg[i] = seg[i << 1] + seg[i << 1 | 1];
        }
    }

    void modify(int v, int q){
        for(v+=n; v > 0; v >>= 1) seg[v]--;
        for(q+=n; q > 0; q >>= 1) seg[q]++;
    }

    int querry(int l, int r){
        int ans = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans += seg[l++];
            if(r&1) ans += seg[r-1];
        }
        return ans;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<p(3)> queries;
    vi a;

    forn(i, n){
        int input;
        cin >> input;
        vals.pb(input);
        a.pb(input);
    }

    forn(i, q){
        char type;
        int v1, v2;
        cin >> type >> v1 >> v2;
        if(type == '!'){
            vals.pb(v2);
        }
        queries.pb({type == '!', v1, v2});
    }

    int index = 0;

    sort(iter(vals));
    vals.erase(unique(iter(vals)), vals.end());

    forn(i, n){
        auto it = lower_bound(iter(vals), a[i]);
        a[i] = it - vals.begin(); 
    }

    segment_tree seg(vals.size(), a);
    auto it = vals.begin();
    for(auto [t, v1, v2]: queries){
        if(t == 0){
            // querry
            it = lower_bound(iter(vals), v1);
            v1 = it - vals.begin();
            it = lower_bound(iter(vals), v2);
            if(!(*it == v2 || it == vals.begin())){
                it--;
            }
            v2 = it - vals.begin();
            out(seg.querry(v1, v2+1));
        }
        else{
            // modify
            v1--;
            it = lower_bound(iter(vals), v2);
            v2 = it - vals.begin();
            seg.modify(a[v1], v2);
            a[v1] = v2;
        }
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
