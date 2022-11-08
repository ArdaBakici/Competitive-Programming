#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

void solve(){
    string s;
    cin >> s;
    vector<int> nums(10, 0);
    vector<int> last_num(10, -1);
    
    forn(i, s.length()){
        last_num[(s[i] - '0')] = i;
    }

    int last_index = 0;

    vector<int> ans;

    forn(i, 10){
        if(last_num[i] > -1){
            for(int x = last_index; x < last_num[i]+1; x++){
                if((s[x]-'0') == i){
                    nums[(s[x]-'0')]++;
                }
                else if((s[x]-'0') > i){
                    if((s[x]-'0') == 9){
                        nums[9]++;    
                    }
                    else{
                        nums[(s[x]-'0')+1]++;
                    }
                }
            }
            last_index = max(last_num[i]+1, last_index);
        }
    }

    forn(i, 10){
        forn(x, nums[i]){
            cout << i;
        }
    }

    cout << endl;
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