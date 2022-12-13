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
    int n;
    cin >> n;
    multiset<int> a;

    forn(i, n){
        int input;
        cin >> input;
        a.insert(input);
    }

    int m = 1;

    for(auto x: a){
        if(m < x){
            out(m);
            return;
        }
        else{
            m += x;
        }
    }
    out(m);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
