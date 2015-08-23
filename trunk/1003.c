#include <stdio.h>
int main(int argc, char* argv[]){

	float len,sum;
	int n;
	while(1)
	{
		scanf("%f", &len);
		if(fabs(len)<=1e-6){break;}
		n=2;
		sum=0.0;
		while(len-sum>1e-6){sum+=(1./n++);}
		printf("%d card(s)\n", n-2);
	}
	return 0;
}
