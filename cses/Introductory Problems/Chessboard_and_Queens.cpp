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
    #define vi vector<int>
    using namespace std;

    int n = 8;
    int ans = 0;
    bool board[8][8];
    vector<bool> diag_a((2*n)-1, true);
    vector<bool> diag_b((2*n)-1, true);
    vector<bool> column(n, true);

    void search(int y){
        if(y == (n)){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(board[y][i] && column[i] && diag_a[y+i] && diag_b[y+n-1-i]){
                column[i] = false;
                diag_a[y+i] = false;
                diag_b[y+n-1-i] = false;
                search(y+1);
                column[i] = true;
                diag_a[y+i] = true;
                diag_b[y+n-1-i] = true;
            }
        }
    }

    void solve(){
        forn(i, n){
            forn(x, n){
                char input;
                cin >> input;
                board[i][x] = (input == '.');
            }
        }
        search(0);
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