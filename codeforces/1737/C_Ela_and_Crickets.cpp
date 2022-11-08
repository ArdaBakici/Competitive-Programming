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
    int n;
    cin >> n;
    int empty_x = 0, empty_y = 0;
    int x_a = 0, x_a_num = 0, y_a = 0, y_a_num = 0;
    int x_b = 0, y_b = 0;
    forn(i, 3){
        int x_cor, y_cor;
        cin >> x_cor >> y_cor;
        if(x_a == 0){
            x_a = x_cor;
            x_a_num++;
        }
        else if(x_cor == x_a){
            x_a_num++;
        }
        else if(x_b == 0){
            x_b = x_cor;
        }
        
        if(y_a == 0){
            y_a = y_cor;
            y_a_num++;
        }
        else if(y_cor == y_a){
            y_a_num++;
        }
        else if(y_b == 0){
            y_b = y_cor;
        }
        
    }

    empty_x = (x_a_num == 2) ? x_b : x_a;
    empty_y = (y_a_num == 2) ? y_b : y_a;

    int goal_x, goal_y;
    cin >> goal_x >> goal_y;

    if(empty_x == n-1 || empty_x == 2){
        if(empty_y==n-1 || empty_y == 2){
            if(empty_x == 2){
                if(empty_y == 2){
                    if(goal_x == 1 || goal_y == 1){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
                else{
                    if(goal_x == 1 || goal_y == n){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
            }
            if(empty_x == n-1){
                if(empty_y == 2){
                    if(goal_x == n || goal_y == 1){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
                else{
                    if(goal_x == n || goal_y == n){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
            }
            return;
        }
    }

    if((empty_x%2 == goal_x%2) && (empty_y%2 == goal_y%2)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
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