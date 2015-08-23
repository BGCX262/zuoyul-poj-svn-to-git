/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 2431.cpp
 * @author zuoyul(zuoyul@baidu.com)
 * @date 2015/01/13 15:46:18
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>
#include <stdlib.h>

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct st{
    int dis;
    int fuel;
};

int comp(const void* a, const void* b){
    int a1 = ((st*)a)->dis;
    int b1 = ((st*)b)->dis;
    if(a1<b1){
        return -1;
    }else if(a1>b1){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char* argv[]){
    int n;
    priority_queue<int> pq;
    int d, f;
    int i;
    int res;
    
    scanf("%d", &n);
    st *tmp = (st*)malloc(sizeof(st)*(n+1));
    i = 0;
    while(i<n){
        scanf("%d %d", &(tmp[i].dis), &(tmp[i].fuel));
        i++;
    }

    scanf("%d %d", &d, &f);
    i = 0;
    while(i<n){
        tmp[i].dis = d - tmp[i].dis;
        i++;
    }
    tmp[n].dis = d;
    tmp[n].fuel = 0;
    n++;
    qsort(tmp, n, sizeof(st), comp);
    
    i = 0;
    res = 0;
    while(i<n){
        //printf("i=%d, f=%d, tmp[i].dis=%d, tmp[i].fuel=%d\n", i, f, tmp[i].dis, tmp[i].fuel);
        while(f < tmp[i].dis){
            if(pq.empty()){
                res = -1;
                break;
            }
            f +=  pq.top();
            pq.pop();
            res++;
        }
        
        if(res == -1){
            break;
        }
        pq.push(tmp[i].fuel);
        //printf("\tpush f=%d into pq\n", tmp[i].fuel);
        i++;
    }
    cout << res << endl;
    free(tmp);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
