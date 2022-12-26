/*
! ----- THIS IS AN ALGORITHM FILE ----- !
* 
* Codes inside this file are tested and accurate algorithm codes
* for quick copy and paste.
*
* Do not use the whole file
*
* Data structures are usually implemented as struct not classes
* since I don't like classes in cpp
*
* 
! ----- THIS IS AN ALGORITHM FILE ----- !
*/
/*
* As Always Readability First and Foremost
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

/*
* Addition + Single Update ST
*/
struct segment_tree{
    vi seg;
    int n;
    
    segment_tree(vi arr){
        n = arr.size();
        seg = vi(2*n);

        forn(i, n){
            seg[i+n] = arr[i];
        }

        for(int i = n-1; i > 0; i--){
            seg[i] = seg[i<<1] + seg[i<<1 | 1];
        }
    }

    int querry(int l, int r){
        int ans = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans += seg[l++];
            if(r&1) ans += seg[r-1];
        }
        return ans;
    }

    void modify(int p, int v){
        for(seg[p+=n] = v; p > 1; p >>= 1) seg[p>>1] = seg[p] + seg[p^1];
    }
};

/*
* Minimum + Single Update ST
*/
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

/*
* Range Update + Single Querry ST
*/
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

/*
* Maximum + Perfect Binary Tree for Arbitary Sizes of N
*/
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