#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
ll dp[20][10][2][2];
// digit dp
ll ans(string num,int n,int dig,bool zero,int tight){
  if(n==0)return 1;
  if(dig!=-1 &&dp[n][dig][zero][tight]!=-1){
    return dp[n][dig][zero][tight];
  }
  int upper;
  if(tight)upper=9;
  else upper=(num[num.size()-n]-'0');
  ll val=0;
  for(int i=0;i<=upper;i++){
    if(i==dig && zero==0)continue;
    int check=tight;
    if(tight==0 && i<upper)check=1;
     val+=ans(num,n-1,i,(zero&i==0),check);
  }
  return dp[n][dig][zero][tight]= val;
}
void solve(){
ll a,b;cin>>a>>b;a--;
 string a1=to_string(a);
 string b1=to_string(b);
 memset(dp,-1,sizeof(dp));
 ll val1=ans(b1,b1.size(),-1,1,0);
  memset(dp,-1,sizeof(dp));
  ll val2;
  if(a==-1)val2=0;
  else{
  val2=ans(a1,a1.size(),-1,1,0);}
  cout<<(ll)val1-(ll)val2;
}
int main(){
solve();
}