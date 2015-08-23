#include <stdio.h>
#include <string.h>

char sort[51];
char tmp[51];
int ret;

typedef struct{
	char buf[51];
	int order;
	int visited;
} node_t;

void mergesort(int s,int e){
     int i,j,r,k;
     r = (s+e)/2;
     if(e>s+1){
          mergesort(s, r);
          mergesort(r, e);
          k = 0;
          for(i=s,j=r,k=0;i<r&&j<e;){
               if(sort[i]<=sort[j]){
                    tmp[k]=sort[i];
                    i++;
               }else{
                    ret+=(r-i);
                    tmp[k]=sort[j];
                    j++;
               }
               k++;
          }
          while(i<r) tmp[k++]=sort[i++];
          while(j<e) tmp[k++] = sort[j++];
          i=0;
          while(i<k){
               sort[s+i] = tmp[i];
               i++;
          }
     }else{
          return;
     }
    
}

int main(int argc, char *argv[])
{
	int n,m,i,max,pos,visited;
	node_t all[100];

	while(scanf("%d %d", &n, &m)!=EOF){
		for(i=0;i<100;i++){
			all[i].order = -1;
			all[i].visited = 0;
		}

		for(i=0;i<m;i++){
			scanf("%s", all[i].buf);
			memcpy(sort, all[i].buf, 51);
			ret = 0;
			mergesort(0,n);
			all[i].order = ret;
			//printf("%d\n", all[i].order);
		}
		
		pos = -1;
		visited=0;
		while(visited<m){
			max = 0x7FFFFFFF;
			for(i=0;i<m;i++){
				if(all[i].visited==0 && all[i].order<max){
					max = all[i].order;
					pos = i;
				}
			}
			all[pos].visited = 1;
			printf("%s\n", all[pos].buf);
			visited++;
		}

	}
	
	return 0;
}
