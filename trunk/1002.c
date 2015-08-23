#include <stdio.h>

typedef struct _node{
	char telnum[8];
}node;

int g_map[] = { 2,2,2,
				3,3,3,
				4,4,4,
				5,5,5,
				6,6,6,
				7,7,7,7,
				8,8,8,
				9,9,9};
int compare(const void* p, const void* q){
	int i=0;
	for(i=0;i<7;i++){
		if(((node*)p)->telnum[i]==((node*)q)->telnum[i]){
			continue;
		}else{
			return ((node*)p)->telnum[i] - ((node*)q)->telnum[i];
		}
	}
	return 0;
	
}


int main(int argc, char* argv[]){
	
	int num;
	scanf("%d", &num);

	char line[1000];
	node* input = malloc(num*sizeof(node));
 
	int i=0, j=0, k=0;
	for(i=0;i<num;i++){
		scanf("%s", line);
		//将输入转化为标准的7位电话号码存储		
        j=0,k=0;
		while(j<strlen(line)){
			if(line[j]=='-'){
				j++;
				continue;
			}else if((line[j]>='0') && (line[j]<='9')){
				input[i].telnum[k]=line[j];
				k++;
				j++;
			}else{
				input[i].telnum[k]=g_map[line[j]-'A']+'0';
				k++;
				j++;
			}
		}
		input[i].telnum[7]='\0';
	}

	qsort(input, num, sizeof(node), compare);
	
	//printf("%d\n", num);
	//for(i=0;i<num;i++){
	//	printf("%s\n", input[i].telnum);
	//}

	
	int cnt=1;
	int dup=0;
	for(i=1;i<num;i++){
		//cnt = 1;
		//printf("in the final: %s %s\n", input[i-1].telnum, input[i].telnum);
		if(compare((void*)&input[i-1], (void*)&input[i])==0){
			cnt++;
			dup++;
		}else{
			if(cnt>1){
				printf("%c%c%c-%c%c%c%c %d\n", 
						input[i-1].telnum[0],input[i-1].telnum[1],input[i-1].telnum[2],
						input[i-1].telnum[3],input[i-1].telnum[4],input[i-1].telnum[5],
						input[i-1].telnum[6],cnt);
			}
			cnt=1;
		}
	}
	if(cnt>1){
		printf("%c%c%c-%c%c%c%c %d\n",
				input[num-1].telnum[0],input[num-1].telnum[1],input[num-1].telnum[2],
				input[num-1].telnum[3],input[num-1].telnum[4],input[num-1].telnum[5],
				input[num-1].telnum[6],cnt);
	}
	if(dup==0){
		printf("No duplicates.\n");
	}
	return 0;
}
