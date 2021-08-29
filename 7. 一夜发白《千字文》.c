#include <stdio.h>

struct uni{
	int num;
	unsigned char s[5]
}f[65536];//unicode范围  3字节16次方 

int main(){
	unsigned char c,d,e;
	int i=0,flag=0,unicode=0;
	
	for(i=1;i<65536;i++){
		f[i].num=0;
	}
	
	while(scanf("%c",&c)!=EOF){
		if((c>>4)<8){
			continue;
		} 
		if((c>>4)>=12&&(c>>4)<=13){//2字节 
			d=getchar();
			unicode=((c&31)<<6)+(d&63);//范围：2^16 
			f[unicode].num++;
			f[unicode].s[0]=c;
			f[unicode].s[1]=d;
			f[unicode].s[2]='\0'; 
		}
		if((c>>4)==14){
			d=getchar();
			e=getchar();
			unicode=((c&15)<<12)+((d&63)<<6)+(e&63);
			f[unicode].num++;
			f[unicode].s[0]=c;
			f[unicode].s[1]=d;
			f[unicode].s[2]=e;
			f[unicode].s[3]='\0';		
		}
	}
	
	for(i=1;i<65536;i++){
		if(f[i].num>1){
			printf("%s 0x%04x %d\n",f[i].s,i,f[i].num);
			flag=1;
		}
	}
	if(flag==0){
		printf("No repeat!\n");
	}
	
	
	return 0;
}
