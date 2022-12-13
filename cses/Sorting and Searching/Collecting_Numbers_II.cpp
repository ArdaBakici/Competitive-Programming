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
    vi locs(n+1, INT_MAX);
    vi arr;
    int total = 0;

    forn(i, n){
        int input;
        cin >> input;
        arr.pb(input);
        if(locs[input-1] > i){
            total += 1;
        }
        locs[input] = i;
    }

    forn(i, m){
        int q_total = total;
        int q1, q2;
        cin >> q1 >> q2;
        if(q1 > q2) swap(q1, q2);
        q1--; q2--;

        if(locs[arr[q1]-1] < q1){
            // q1 not header
            if(locs[arr[q1]+1] < q2){
                q_total++;
            }
            else if(locs[arr[q1]+1] == q2){
                // np
            }
        }
        else{
            if(locs[arr[q1]-1] < q2) q_total--;
            if(locs[arr[q1]+1] > q1){
                if(locs[arr[q1]+1] < q2)
            }
        }

    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
