    #include <iostream>
    #include <bits/stdc++.h>
    #define ll long long
    #define int ll
    #define forn(i, n) for(int i = 0; i < n; i++)
    #define em emplace_back
    #define iter(i) i.begin(),i.end()
    #define pb push_back
    #define endl "\n"
     
    using namespace std;
     
     
    void solve(){
        int n;
		cin >> n;
        cout << n << " ";
		while(n!=1){
			n = n%2 ? (3*n)+1 : n/2;
			cout << n << " ";
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