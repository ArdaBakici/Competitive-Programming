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
        int n;
        cin >> n;
        if(n==1){
            out(1);
            return;
        }
        if(n < 4){
            out("NO SOLUTION");
            return;
        }

        for(int i = 2; i <=n ; i+=2){
            cout << i << " ";
        }
        for(int i = 1; i <=n ; i+=2){
            cout << i << " ";
        }
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