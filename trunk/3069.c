/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 3069.c
 * @author zuoyul(zuoyul@baidu.com)
 * @date 2015/01/13 11:32:41
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>

int comp(void* a, void* b){
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    if(a1<b1){
        return -1;
    }else if(a1>b1){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char* argv[]){
    int R, N;
    int X[1000];
    int i,j;
    int s,p;
    int res = 0;
    while(1){
        scanf("%d %d", &R, &N);
        if(-1==R && -1==N){
            break;
        }
        for(i=0;i<N;++i){
            scanf("%d", &X[i]);
        }
        qsort(X, N, sizeof(int), comp);

        res = 0;
        s = 0;
        p = 0;
        i = 0;
        while(i<N){
            //move to right, until found p
            s = X[i++];
            while(i<N && s+R>=X[i]){i++;}
            p = X[i-1];
            while(i<N && p+R>=X[i]){i++;}
            res++;
        }
        
        printf("%d\n", res);
    }


}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
