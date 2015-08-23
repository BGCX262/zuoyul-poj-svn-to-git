#include <stdio.h>

typedef struct{
	unsigned int left;
	unsigned int right;
} val_t;


int main(int argc, char* argv[]){
	
	val_t val[12];
	char buf[100];
	int i=0;
	int j=0;
	for(i=0;i<12;i++){
		val[i].left = 0;
		val[i].right = 0;
	}
	for(i=0;i<12;i++){
		gets(buf);
		j=0;
		while(buf[j]!='.' && buf[j]!='\0'){
			val[i].left = val[i].left*10+buf[j]-'0';
			j++;
		}
		if(buf[j]=='.'){
			j++;
			while(buf[j]!='\0'){
				val[i].right = val[i].right*10+buf[j]-'0';
				j++;
			}
		}
	}
	unsigned int leftSum=0;
	unsigned int rightSum=0;
	for(i=0;i<12;i++){
		leftSum+=val[i].left;
		rightSum+=val[i].right;
	}
	printf("$%.2f\n", (float)(leftSum*100+rightSum)/1200);
	return 0;
}
