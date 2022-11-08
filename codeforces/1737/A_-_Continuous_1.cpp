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
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int first_one_index = -1;
    int last_one_index = -1;
    bool connected = true;

    forn(i, s.length()){
        if(s[i] == '1'){
            if(first_one_index == -1){
                first_one_index = i;
            }
            else{
                if(!connected){
                    cout << "No" << endl;
                    return;
                }
                last_one_index = i;
            }
        }
        else if(s[i] == '0'){
            if(first_one_index != -1){
                connected = false;
            }
        }
    }

    if(last_one_index == -1 && first_one_index == -1){
        int num_of_chains = 0;
        int cur_chain = 0;
        forn(i, s.length()){
            if(s[i] == '?'){
                if(cur_chain == k){
                    cout << "No" << endl;
                    return;
                }
                cur_chain++;
            }
            else{
                if(cur_chain == k){
                    num_of_chains++;
                }
                cur_chain = 0;
            }
        }
        if(cur_chain == k){
            num_of_chains++;
        }
        if(num_of_chains == 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return;
    }

    if(last_one_index == -1){
        last_one_index = first_one_index;
    }

    int num_of_ones = last_one_index - first_one_index + 1; 

    if(num_of_ones > k){
        cout << "No" << endl;
        return;
    }
    if(num_of_ones == k){
        cout << "Yes" << endl;
        return;
    }
    
    int b_p = 0;
    int e_p = 0;

    for(int i = first_one_index-1; i>=0;i--){
        if(s[i] == '?'){
            b_p++;
        }
        else{
            break;
        }
    }
    for(int i = last_one_index+1; i<s.length();i++){
        if(s[i] == '?'){
            e_p++;
        }
        else{
            break;
        }
    }

    if((b_p + e_p + num_of_ones) == k){
        cout << "Yes" << endl;
        return;
    }
    if((b_p == 0 && (e_p + num_of_ones) >= k) || (e_p == 0 && (b_p + num_of_ones) >= k)){
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
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