#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    string w;
    int p;
    int price = 0;
    map<char, vector<int>> price_array;
    cin >> w >> p;

    forn(i, w.length()){
        price += int(w[i])-96;
        price_array[int(w[i])-96].emplace_back(i);
    }

    if (price > p){
        for(int v = 26; v > 0;){
            if (price <= p){
                break;
            }
            if (price_array[v].size() == 0){
                v--;
                continue;
            }
            int index = price_array[v].back();
            price_array[v].pop_back();
            w[index] = '0';
            price -= v;
        }
    }
    for(int i = w.length(); i>=0; i--){
        if (w[i] == '0'){
            w.erase(i, 1);
        }
    }
    if(w.size() == 0) cout << "" << endl; else cout << w << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}