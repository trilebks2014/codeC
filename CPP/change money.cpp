/// Dung quy hoach dong de doi tien voi so luong it nhat




#include <stdio.h>
int check =1;//check =1 : can't change; check =0 can change
int k=4; // how many elements of array a
int a[6]={2,3,6,10}; //sort grown up
int b[6000][6000];
int min(int a,int b){
	a = a>b?b:a;
	return a;
}

void changeMoney(int n){//n : money
	int f[n];
	int temp;
	for(int i=0;i<=n;i++)f[i]=0;
	for(int i=0;i<k;i++) f[a[i]]=1;
	for(int i=0;i<=n;i++)b[i][0]=0;
	for(int i=0;i<k;i++)b[0][i]=0;
	b[a[0]][0]=1;
	for(int i=a[0]+1;i<=n;i+=1){
		check=1;
		f[i]=100000000;
		for(int j=0;j<k;j++){			
			if((i-a[j])>=0&&(f[i]>=f[i-a[j]]+1)&&((i-a[j]==0)||f[i-a[j]]!=0)){
					f[i]=f[i-a[j]]+1;
				//	printf("i = %d , j= %d %d-a[%d]=%d  a[j]=%d f[i-a[j]=%d f[i]=%d \n ",i,j,i,a[j],i-a[j],a[j],f[i-a[j]],f[i]);
					temp=j;
					check=0;					
			}			
		}
		if (check==1){
			f[i]=0;
		}
		else {
			for(int u=0;u<k;u++){
				b[i][u]+=b[i-a[temp]][u];
				
			}
			b[i][temp]+=1;
		}
	}
	printf("All the number for change: %d\n",f[n]);
	f[0]=0;
	
}
main(){
	int n=15;
	changeMoney(n);
	
	for (int i=0;i<k;i++){
		printf("%d : %d \t",a[i],b[n][i]);
	}	

}
