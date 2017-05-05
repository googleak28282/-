//by googleak28282
#include<bits/stdc++.h>
#define inf 10005
#define maxn 1000000
using namespace std;
bool np[maxn]; 
int prime[maxn],cnt=0;
void p(){
	for(int i=0;i<maxn;++i) np[i]=0;
	np[0]=np[1]=true;
	for(int i=2;i<maxn;++i){
		if(!np[i]){
			prime[cnt]=i;cnt++;
			for(int j=i+i;j<maxn;j+=i){
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
int dp[505];
int main(){
	freopen("first.txt","w",stdout);
	p();
	int num,power=1;
	for(int i=0;i<500;i++){
		num=prime[i];
		int mod=fast_pow(num,power);
		fib[0]=0;
		fib[1]=1;
		for(int j=2;j<inf;j++){
			fib[j]=(fib[j-1]+fib[j-2])%mod;
		}
		for(int j=3;j<inf;j++){
			if((fib[j]==0)&&(fib[j+1]==1)&&(fib[j+2]==1)) {
				dp[i]=j;
				break;
			}
	 	} 
	}
	for(int i=0;i<500;i++){
		cout<<prime[i]<<" "<<dp[i]<<endl;
	}
	return 0;
}
