#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

int char_to_int(char x){
    return (int)x - 'a';
}

void solve(){
    int n, k;
    cin >> n >> k;
    string ans;
    vector<int> alph(26, 0);
    
    forn(i, n){
        char input;
        cin >> input;
        alph[char_to_int(input)]++;
    }
    
    forn(i, k){
        int cur = 0;
        forn(al, n/k){
            if(alph[cur] > 0){
                alph[cur]--;
                cur++;
            }
            else{
                bool flag = false;
                ans.push_back((char)('a' + cur));
                forn(p, 26){
                    if(alph[p] > (k-i-1)){
                        alph[p]--;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    for(int w = 25; w >= 0; w--){
                        if(alph[w] > 0){
                            alph[w]--;
                            break;
                        }
                    }
                }
                break;
            }
            if(al == (n/k)-1){
                ans.push_back((char)('a' + cur));
            }
        }
    }
    cout << ans << endl;
}

int main(){
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