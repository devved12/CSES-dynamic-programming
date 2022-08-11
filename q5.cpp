#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
// here greedy solution of max digit selection also works
void solve(){
int n;cin>>n;
vector<int>dp(n+1,INT_MAX);
dp[0]=0;
for(int i=1;i<=n;i++){
  string s=to_string(i);
  for(auto x:s){
    dp[i]=min(dp[i],dp[i-(x-'0')]+1);
  }
}
cout<<dp[n];
}
int main(){
solve();
}