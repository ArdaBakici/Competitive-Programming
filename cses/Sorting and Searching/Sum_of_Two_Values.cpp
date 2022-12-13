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
    int n, x;
    cin >> n >> x;
    multiset<int> a;
    vi arr;

    forn(i, n){
        int input;
        cin >> input;
        a.insert(input);
        arr.pb(input);
    }
    
    for(auto it = a.begin(); it != a.end(); it++){
        int g = x - *it;
        auto comp = a.find(g);
        if(comp == it || comp == a.end()){
            continue;
        }
        int found = 0;
        bool f1 = true;
        bool f2 = true;
        forn(i, n){
            if(f1 && arr[i] == *comp){
                f1 = false;
                cout << i+1 << " ";
            }
            else if(f2 && arr[i] == *it){
                f2 = false;
                cout << i+1 << " ";
            }
            if(!f1 && !f2){
                return;
            }
        }
    }
    out("IMPOSSIBLE");
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
