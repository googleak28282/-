//by googleak28282
#include<bits/stdc++.h>
#define inf 10000005
#define maxn 1000000
using namespace std;
typedef long long ll; 
bool np[maxn];//0借计  1计  
int prime[maxn],cnt=0;
void p(){
	for(int i=0;i<maxn;++i) np[i]=0;
	np[0]=np[1]=true;
	for(int i=2;i<maxn;++i)
	{
		if(!np[i])// !np[i] =>  np[i]==0 
		{
			prime[cnt]=i;cnt++;//р借计prime皚 
			for(int j=i+i;j<maxn;j+=i)//р借计计夹Θ计(true) 
			{
				np[j]=true;
			}
		}
	}
}
int fast_pow(int n,int m){
	int ans=1;
	while(m>0) {
    	if(m % 2 == 1)
    		ans = (ans * n);
    	m = m/2;
    	n = (n * n) ;
	}
	return ans;
}
int fib[inf];
int dp[505][15];
int main(){
	freopen("all.txt","w",stdout);
	p();
	int num,power;
	for(int i=0;i<500;i++){
		num=prime[i];
		for(int j=0;j<10;j++)
		{
			power=j;
			int mod=fast_pow(num,power);
			fib[0]=0;
			fib[1]=1;
			for(int k=2;k<inf;k++)
			{
				fib[k]=(fib[k-1]+fib[k-2])%mod;
			}
			for(int k=3;k<inf;k++)
			{
				if((fib[k]==0)&&(fib[k+1]==1)&&(fib[k+2]==1)) {
					dp[i][j]=k;
					break;
				}
			}
		}
	}
	for(int i=0;i<500;i++){
		cout<<prime[i]<<" ";
		for(int j=1;j<10;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
