#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
const int maxn=1000005;
const int minn=105;
//ll dp[minn][maxn];
ll dp[maxn];
void solve(){
int n,x;cin>>n>>x;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
dp[0]=1;//base case 
// here order doesnt matter
for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
        if(i>=arr[j]){
            dp[i]=(dp[i]+dp[i-arr[j]])%mod;
        }
    }
}
cout<<dp[x];
}
int main(){
solve();
}
