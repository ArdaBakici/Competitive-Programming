#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;



int dp(int index, int val1, int val2){
    if(val1 <= 1){

    }
}

void solve(){
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vi ext;

    forn(i, n){
        int input;
        cin >> input;
        ext.pb(input);
    }

    sort(iter(ext), greater<int>());

    if(b > a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    if(w > h){
        int tmp = h;
        h = w;
        w = tmp;
    }

    int ans = 0;
    bool flag = true;

    forn(i, n){
        if((long double)a/h <= 1 && (long double)b/w <= 1){
            flag = false;
            break;
        }
        if((long double)a/h > (long double)b/w){
            h *= ext[i];
            ans++;
        }
        else{
            w *= ext[i];
            ans++;
        }
    }
    if(flag){
        out(-1);
        return;
    }
    out(ans);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
