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

vi a;
vector<vi> dp;
vi rldp;

int f(int m, int low, int high){
    int zeros = -1;
    int ones = 0;

    int l = low;
    int r = high;

    while(l <= r){
        int mid = l + (r-l)/2;
        if(dp[mid][m]){
            //go left
            r = mid-1;
        }
        else{
            zeros = max(zeros, mid);
            l = mid + 1;
        }
    }
    if(zeros < 0){
        zeros = 0;
        ones = high - low + 1;
    }
    else{
        zeros -= low;
        zeros++;
        ones = (high - low + 1) - zeros;
    } 
    if(!ones || !zeros){
        if(!m) rldp[m] = 0;
        else rldp[m] = f(m-1, low, high);
    }
    else if(ones == 1 || zeros == 1){
        rldp[m] = 1 << m;
    }
    else{
        if(!m) rldp[m] = 1;
        else rldp[m] = (1 << m) + min(f(m-1, low, low+zeros-1), f(m-1, low+zeros, high));
    }
    return rldp[m];
}

int solve1(int fs, vector<int> input){
    int n;
    n = fs;
    dp = vector<vi>(n, vi(31, 0));
    rldp = vi(31, -2);

    a = input;

    sort(iter(a));

    forn(x, n){
        int i = 0;
        while(a[x] > 0){
            if(a[x] & 1) dp[x][i] = 1;
            i++;
            a[x] >>= 1;
        }
    }

    return f(30, 0, n-1);
}

int dfs(int cur,vector<int> a){
	if(cur==-1) return 0;
	vector<int> S,T;
	
	for(int i=0;i<a.size();i++){
		if(((a[i]>>cur) & 1) ==0) S.push_back(a[i]);
		else T.push_back(a[i]);
	}
	
	if(S.size()==0) return dfs(cur-1,T);
	if(T.size()==0) return dfs(cur-1,S);
	return min(dfs(cur-1,S),dfs(cur-1,T)) | (1<<cur);
}

int solve2(int fs, vi input){
    int N;
	N = fs;
	
	vector<int> a(N);
	a = input;
	return dfs(29,a);
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans1 = 0, ans2 = 0, n1;
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
