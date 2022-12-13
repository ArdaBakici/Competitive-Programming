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

// segment implementation

struct segment_tree{
    vi seg;
    int n;

    segment_tree(vi arr){
        n = arr.size();
        seg = vi(2*n);

        forn(i, n){
            seg[i+n] = arr[i];
        }

        for(int i = n-1; i >= 0; i--){
            seg[i] = seg[2*i] + seg[(2*i)+1];
        }
    }

    int query(int l, int r){
        // caution [l, r)
        int ans = 0;
        for(l += n, r+=n; l < r; l>>=1, r>>=1){
            if(l&1) ans += seg[l++];
            if(r&1) ans += seg[r - 1]; 
        }
        return ans;
    }

    void modify(int v, int val){
        v+=n;
        int diff = val - seg[v];
        for(seg[v] += diff; v > 0; v >>= 1){
            seg[v>>1] += diff;
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
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        out(seg.query(v1, v2));
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
