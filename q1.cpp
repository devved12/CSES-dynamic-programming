#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
const int maxn=1000005;
ll dp[maxn];
void solve(){
int n;cin>>n;
dp[0]=1;// empty subset
for(int i=1;i<=n;i++){
for(int j=1;j<=6;j++){
    if(i>=j){
        dp[i]=(dp[i]+dp[i-j])%mod;
    }
}
}
cout<<dp[n]<<"\n";
}
int main(){
solve();
}