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

int solve1(int vn, int vircap, vi vinput){
    int n = vn, cap = vircap;
    multiset<int> a;

    forn(i, n){
        int input;
        input = vinput[i];
        a.insert(input);
    }
    
    int ans = 0;
    while(a.size() > 0){
        auto it = a.cend();
        it--;
        if(*it == cap || a.size() == 1){
            a.erase(it);
            ans++;
        }
        else{
            auto com = a.lower_bound(cap - *it);
            if(com == a.begin() && *com > cap-*it){
                ans++;     
                a.erase(it);
                continue;
            }
            if(com == it){
                com--;
            }
            if(com == a.end()){
               com--; com--; 
            }
            a.erase(com);
            ans++;     
            a.erase(it);
        }
    }
    return ans;
}

int solve2(int vn, int vircap, vi vinput){
    const int maxN = 2e5;
    int N, X, l, ans, p[maxN];
	N = vn;
    X = vircap;
    ans = 0;

    for(int i = 0; i < N; i++)
        p[i] = vinput[i];
    
    sort(p, p+N);

    l = 0;
    for(int r = N-1; r >= l; r--){
        if(p[l] + p[r] <= X)
            l++;
        ans++;
    }
    return ans;
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans1 = 0, ans2 = 0, n1, cap;
    
    // Write limits to below
    int limitn =  5, limita = 10;
    //int limitn =  2 * 10e5, limita = 10e9;
    
    vi input1;
    srand(time(0));
    while(ans1 == ans2){
        n1 = (rand() % limitn)+1;
        cap = (rand() % limita)+1;
        input1 = vi(n1, 0);
        forn(i, n1){
            input1[i] = (rand() % cap)+1;
        }
        ans1 = solve1(n1, cap, input1);
        ans2 = solve2(n1, cap, input1);
    }
    out("Wrong in case : ");
    cout << n1 << " " << cap << endl;
    for(auto x: input1) cout << x << " ";
    cout << endl;
    cout << "Judge Output: " << ans2 << endl;
    cout << "User Output: " << ans1 << endl;
    return 0;
}
