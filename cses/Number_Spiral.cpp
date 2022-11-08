    #include <iostream>
    #include <bits/stdc++.h>
    #define ll long long
    #define int ll
    #define forn(i, n) for(int i = 0; i < n; i++)
    #define em emplace_back
    #define iter(i) i.begin(),i.end()
    #define pb push_back
    #define endl "\n"
    #define out(x) cout<<x<<endl
    using namespace std;
     
     
    void solve(){
        int x, y;
        cin >> y >> x;
        int ans;
        if(x >= y){
            int tmp = x%2 ? x*x : ((x-1)*(x-1))+1;
            ans = x%2 ? tmp - y + 1 : tmp + y - 1;
        }
        if(y > x){
            int tmp = y%2 ? ((y-1)*(y-1))+1 : y*y;
            ans = y%2 ? tmp + x - 1 : tmp - x + 1;
        }

        out(ans);
    }
     
    int32_t main(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int tt;
        cin >> tt;
        forn(i, tt) solve();
        return 0;
    }
     
    /*
    * When you get WA:
        - Check for integer overflows
        - Bugs
        - Arrays with uninitialized values
    */