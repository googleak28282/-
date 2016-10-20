//by googleak28282
#include<bits/stdc++.h>
#define inf 10000005
using namespace std;
typedef long long ll;
ll fast_pow(ll n,ll m)
{
	ll ans=1;
    while(m>0) {
        if(m % 2 == 1)
        	ans = (ans * n);
        m = m/2;
        n = (n * n) ;
    }
	return ans;
}
ll fib[inf];
int main()
{
	ll number,power;
	cin>>number>>power;
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<inf;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%fast_pow(number,power);
	}
	for(int i=0;i<1000;i++)
	{ 
		cout<<i<<" "<<fib[i];
		if((fib[i]==0)&&(fib[i+1]==1)&&(fib[i+2]==1)) cout<<" *";
		cout<<"\n";
	}
	return 0;
}
