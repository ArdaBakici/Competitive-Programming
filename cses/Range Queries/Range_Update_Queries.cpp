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

struct segment_tree{
    vi seg;
    int n;

    segment_tree(vi arr){
        n = arr.size();
        seg = vi(2*n);
        
        forn(i, n){
            seg[i+n] = arr[i];
        }
    }

    int querry(int v){
        int ans = 0;
        for(v += n; v > 0; v >>= 1) ans += seg[v];
        return ans;
    }

    void modify(int l, int r, int val){
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) seg[l++] += val;
            if(r&1) seg[r-1] += val;
        }
    }

    void push(){
        for(int i = 1; i < n; i++){
            seg[i << 1] += seg[i];
            seg[i << 1 | 1] += seg[i];
            seg[i] = 0;
        }
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
        int t, v1, v2, val;
        cin >> t >> v1;
        v1--;
        if(t==1){
            cin >> v2 >> val;
            seg.modify(v1, v2, val);
        }
        else out(seg.querry(v1));
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
