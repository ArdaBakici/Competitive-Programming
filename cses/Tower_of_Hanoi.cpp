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
    
    void swap(int num, int s, int m, int t){
        if(num == 1){
            cout << s << " " << t << endl;
            return;
        }
        swap(num-1, s, t, m);
        cout << s << " " << t << endl;
        swap(num-1, m, s, t);
    }
    
    void solve(){
        int n;
        cin >> n;
        out(pow(2, n) - 1);
        swap(n, 1, 2, 3);
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