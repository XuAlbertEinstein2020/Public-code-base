#include <cstdio>
#include <iostream>
using namespace std;
int n,a[10005],m,sum,cnt=0,nmax;
int fun(int p,int b){
	if(b==0)	return a[p];
	else	return a[p]-a[b-1];
}
int main(){
	int left,right,middle;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=1;i<n;i++)	a[i]+=a[i-1];
	cin>>m;
	for(int i=0;i<n;i++){
		left=i,right=n-1,nmax=0;
		while(left<=right){
			middle=(left+right)/2;
			//cout<<fun(middle,i)<<" "<<middle<<endl;
			if(fun(middle,i)>m){
				right=middle-1;
			}else if(fun(middle,i)==m){
				nmax=nmax>middle?nmax:middle;
				break;
			}else{
				left=middle+1;
				nmax=nmax>middle?nmax:middle;
			}
		};
		if(nmax!=0)	cnt+=(nmax-i+1);
	}cout<<cnt;
	return 0;
}
