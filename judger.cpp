#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

int solve1(int vn, vi vinput){
    int ans = 0;
    return ans;
}

int solve2(int vn, vi vinput){
    int ans = 0;
    return ans;
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans1 = 0, ans2 = 0, n1;
    
    // Write limits to below
    int limitn =  1.5 * 10e5, limita = (1 << 30);
    //int limitn = 4, limita = (1 << 2);
    
    vi input1;
    srand(time(0));
    while(ans1 == ans2){
        n1 = rand() % limitn+1;
        input1 = vi(n1, 0);
        forn(i, n1){
            input1[i] = (rand() % limita);
        }
        ans1 = solve1(n1, input1);
        ans2 = solve2(n1, input1);
    }
    out("Wrong in case : ");
    cout << "N is : " << n1 << endl;
    cout << "Input is:" << endl;
    for(auto x: input1) cout << x << " ";
    cout << endl;
    cout << "Judge Output: " << ans2 << endl;
    cout << "User Output: " << ans1 << endl;
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
