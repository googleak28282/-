//by googleak28282
#include<bits/stdc++.h>
#define inf 10005
#define maxn 1000000
using namespace std;
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
int main(){
	int num,power;
	cin>>num>>power;
	int mod=fast_pow(num,power);
	fib[0]=0;
	fib[1]=1;
	for(int i=0;i<inf;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	}
	for(int i=0;i<inf;i++)
	{
		cout<<i<<" "<<fib[i];
		if((fib[i]==0)&&(fib[i+1]==1)&&(fib[i+2]==1)) cout<<" *";
		cout<<"\n";
	 } 
	return 0;
}
