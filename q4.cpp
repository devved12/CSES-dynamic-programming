#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
void solve(){
int n,x;cin>>n>>x;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<vector<int>>dp(n+1,vector<int>(x+1,0));
dp[0][0]=1;
for(int i=1;i<=n;i++){
for(int j=0;j<=x;j++){
    dp[i][j]=dp[i-1][j];
if(j>=arr[i-1]){
    dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i-1]])%mod;// dp[i][j]=dp[i-1][j] if not choosen to avoid 
}                                                // repeated cases like 131 113
else{
    dp[i][j]=dp[i-1][j];
}
}
}
cout<<dp[n][x];
}
int main(){
solve();
}