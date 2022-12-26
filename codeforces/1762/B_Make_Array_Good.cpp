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
    vector<p(2)> a;
    int maxim = 0;
    vector<p(2)> op;
    forn(i, n){
        int input;
        cin >> input;
        maxim = max(input, maxim);
        a.pb({input, i});
    }
    sort(iter(a));

    int goal = 1;

    forn(i, n){
        int diff = 0;
        int multiply = 0;
        if(a[i][0] > goal){
            if(a[i][0] % goal){
                multiply = (a[i][0]/goal) + 1;
                goal = (multiply*goal);
                op.pb({a[i][1], goal-a[i][0]});
            }
            else{
                goal = a[i][0];
            }
        }
        else if(a[i][0] < goal){
            op.pb({a[i][1], goal-a[i][0]});
        }
    }

    out(op.size());
    for(auto [ni, nx]: op){
        cout << ni + 1 << " " << nx << endl;
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt; cin >> tt; forn(i, tt)
    solve();
    return 0;
}
