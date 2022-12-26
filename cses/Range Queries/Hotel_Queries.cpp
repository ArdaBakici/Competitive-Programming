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
        int tmp_n = n;
        int new_n = -1;
        while(tmp_n > 0){
            tmp_n >>= 1;
            new_n++;
        } 

        if(n > (1 << new_n)){
            n = 1 << (new_n+1);
        }

        seg = vi(2*n);

        forn(i, n){
            if(i >= arr.size()){
                seg[i+n] = 0;
            }
            else seg[i+n] = arr[i];
        }

        rforn(i, n){
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    void modify(int v, int delta){
        for(seg[v+=n] += delta; v > 1; v >>= 1) seg[v >> 1] = max(seg[v], seg[v^1]);
    }

    int querry(int val){
        int ans;
        for(int i = 1; i < n;){
            if(seg[i << 1] >= val){
                ans = i<<1;
                i <<= 1;
            }
            else if(seg[i << 1 | 1] >= val){
                ans = i << 1 | 1;
                i= i << 1 | 1;
            }
            else{
                ans = 0;
                break;
            }
        }
        return ans;
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
        int v1;
        cin >> v1;
        int ans = seg.querry(v1);
        if(ans != 0){
            ans += 1 - seg.n;
            seg.modify(ans-1, -v1);
        }
        cout << ans << " ";
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
