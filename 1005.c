#include <stdio.h>
int main(int argc, char* argv[]){
	
	int n,i;
	float x,y,r;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%f %f", &x, &y);
		printf("Property %d: This property will begin eroding in year %d.\n", i,  (int)((float)3.14*(x*x+y*y)/100)+1);
		
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
