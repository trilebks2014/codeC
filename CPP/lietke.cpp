#include <stdio.h>
#include <conio.h>
char A[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char B[50];
int k=0;
void lietke16(int n){
	if(n==0){
		puts(B);
	k++;
	}else{
		for(int i=0;i<16;i++){
			B[n-1]=A[i];		
			lietke16(n-1);
		}
	}
}
main(){
	int n=5;
	lietke16(2);
	printf("%d",k);
}
