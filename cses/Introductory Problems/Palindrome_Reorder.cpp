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
        string s;
        cin >> s;
        string ans;
        int nod = 0;
        char odd_i = '0';
        int noe = 0;
        vector<int> carr(26, 0);
        
        for(auto x:s){
            carr[(int)(x - 'A')]++;
        }

        forn(x, carr.size()){
            if(carr[x]%2){
                nod++;
                odd_i = x+'A';
            }
            else{
                noe++;
            }
        }

        if(s.length()%2){
            if(nod>1){
                out("NO SOLUTION");
                return;
            }
        }
        else{
            if(nod>0){
                out("NO SOLUTION");
                return;
            }
        }

        forn(x, carr.size()){
            forn(i, carr[x]/2){
                char apx = x+'A';
                ans.pb(apx);
            }
        }

        string inv = ans;
        reverse(iter(inv));

        if(s.length()%2){
            ans.pb(odd_i);
        }
        
        ans.append(inv);
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