#include <stdio.h>

int min(int a,int b){
	a=a>b ? b:a;
	return a;
}

void tonglapphuong(int n){
	int f[n+1],p[n+1];
	f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+1;
		p[i]=1;
		for(int j=2;j*j*j<=i;j++){
			f[i]=min(f[i],f[i-j*j*j]+1);
			if(f[i]==f[i-j*j*j]+1){
				p[i]=j;
			}
		}
	}
	while(n>0){
		printf("%d ",p[n]);
		n-=p[n]*p[n]*p[n];
	}
		
}
main(){
	int n = 1100;
	tonglapphuong(n);
}
