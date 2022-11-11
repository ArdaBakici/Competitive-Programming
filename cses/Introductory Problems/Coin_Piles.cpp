    #include <iostream>
    #include <bits/stdc++.h>
    #define ll long long
    #define int ll
    #define forn(i, n) for(int i = 0; i < n; i++)
    #define fornn(i, n) for(int i = 1; i <= n; i++)
    #define em emplace_back
    #define iter(i) i.begin(),i.end()
    #define pb push_back
    #define endl "\n"
    #define out(x) cout<<x<<endl
    using namespace std;
     
     
    void solve(){
        int a, b;
        cin >> a >> b;
        int ma = max(a, b);
        int mi = min(a, b);
        int k = ((2*mi) - ma);

        if(k%3 || k<0){
            out("NO");
            return;
        }

        ma -= k;
        mi -= k;

        if(ma != 2*mi){
            out("NO");
            return;
        }

        out("YES");

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