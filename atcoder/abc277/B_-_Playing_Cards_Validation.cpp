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
    int n;
    cin >> n;
    bool flag = false;
    vector<vector<bool>> a(4, vector<bool>(13, false));
    forn(i, n){
        string s;
        cin >> s;
        if(flag) continue;
        int x = 0;
        int y = 0;
        switch (s[0]){
        case 'H':
            x = 0;
            break;
        case 'D':
            x = 1;
            break;
        case 'C':
            x = 2;
            break;
        case 'S':
            x = 3;
            break;
        default:
            out("No");
            flag = true;
            continue;
        }

        switch (s[1]){
        case 'A':
            y = 0;
            break;
        case 'T':
            y = 9;
            break;
        case 'J':
            y = 10;
            break;
        case 'Q':
            y = 11;
            break;
        case 'K':
            y = 12;
            break;
        default:
            if(s[1]-'0' < 10){
                if(s[1] == '0' || s[1] == '1'){
                    out("No");
                    flag = true;
                    continue;
                }
                y = (s[1] - '0') - 1;
            }
            else{
                out("No");
                flag = true;
                continue;
            }
            break;
        }

        if(a[x][y]){
            out("No");
            flag = true;
            continue;
        }

        a[x][y] = true;
    }
    if(flag) return;
    out("Yes");
}

int32_t main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
