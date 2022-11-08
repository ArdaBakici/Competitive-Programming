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
        string s;
        cin >> s;
        int ans = 0;
        int count = 0;
        char prev = '0';
        for(auto x:s){
            if(x == prev){
                count++;
            }
            else{
                ans = max(count+1, ans);
                count = 0;
            }
            prev = x;
        }
        ans = max(count+1, ans);
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