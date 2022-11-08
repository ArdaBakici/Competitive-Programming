#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

int to_num(char f){
    return (f-'a');
}

char char_add(char f, int l){
    return ((char) (f + l));
}

void solve(){
    int n;
    string s;
    string t;
    int assigned_num = 0;
    vector<char> alph(26, '[');
    vector<char> used(26, '[');
    cin >> n >> s;
    forn(i, n){
        if(alph[to_num(s[i])] == '['){
            vector<bool> cantuse(26, false);
            int check_index = to_num(s[i]); 
            while(true){
                cantuse[check_index] = true;
                if(used[check_index] == '['){
                    break;
                }
                else{
                    check_index = to_num(used[check_index]);
                }
            }
            forn(x, 26){
                if(used[x] == '[' && (!cantuse[x] || assigned_num==25)){ 
                    alph[to_num(s[i])] = char_add('a', x);
                    used[x] = s[i];
                    assigned_num++;
                    break;
                }
            }
        }
        t.pb(alph[to_num(s[i])]);
    }

    cout << t << endl;
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