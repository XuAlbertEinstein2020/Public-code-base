#include <cstdio>
#include <iostream>
using namespace std;
long long n,a[1000005],m,sum,cnt=0,nmax;
int fun(long long p,long long b){
	if(b==0)	return a[p];
	else	return a[p]-a[b-1];
}
int main(){
	long long left,right,middle;
	cin>>n;
	for(long long i=0;i<n;i++)	cin>>a[i];
	for(long long i=1;i<n;i++)	a[i]+=a[i-1];
	cin>>m;
	for(long long i=0;i<n;i++){
		left=i,right=n-1,nmax=-1;
		while(left<=right){
			middle=(left+right)/2;
			//cout<<fun(middle,i)<<" "<<middle<<endl;
			if(fun(middle,i)>m){
				right=middle-1;
			}else{
				left=middle+1;
				nmax=nmax>middle?nmax:middle;
			}
		}
		if(nmax!=-1)	cnt+=(nmax-i+1);
	}cout<<cnt;
	return 0;
}
