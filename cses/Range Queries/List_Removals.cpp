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

    segment_tree(vi a){
        n = a.size();

        int tmp_n = n;
        int n_new = -1;
        while(tmp_n > 0){
            tmp_n >>= 1;
            n_new++;
        }

        if(n > (1 << n_new)){
            n = (1 << (n_new+1));
        }

        seg = vi(2*n, 0);

        forn(i, n){
            seg[i+n] = 1;
        }

        rforn(i, n){
            seg[i] = seg[i << 1] + seg[i << 1 | 1];
        }
    }

    void modify(int v){
        for(v+=n; v > 0; v >>= 1) seg[v]--;
    }

    int querry(int v){
        int ans = 1;
        for(int i = 1; i < n;){
            if(v > seg[i<<1]){
                v -= seg[i<<1];
                i = i<<1 |1;
            }
            else{
                i <<= 1;
            }
            ans = i;
        }
        return ans;
    }
};

void solve(){
    int n;
    cin >> n;
    vi a;

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    segment_tree seg(a);

    forn(i, n){
        int v;
        cin >> v;
        int ans = seg.querry(v);
        cout << a[ans-seg.n] << " ";
        seg.modify(ans-seg.n);   
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
