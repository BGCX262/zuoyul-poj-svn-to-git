/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 1852.cpp
 * @author zuoyul(zuoyul@baidu.com)
 * @date 2015/01/09 15:51:31
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char* argv[]){

    int n, l, an;
    int min, max;
    int pos;
    vector<int> min_res;
    vector<int> max_res;
    
    scanf("%d", &n);
    while(n-- > 0){
        scanf("%d %d", &l, &an);
        max = 0;
        min = 2000000;
        while(an-- > 0){
            scanf("%d", &pos);
            if(pos>(l/2)){
                pos = l - pos;
            }
            if(pos<min){
                min = pos;
            }
            if(pos>max){
                max = pos;
            }
        }
        min_res.push_back(max);
        max_res.push_back(l-min);
    }
    for(int i=0;i<max_res.size();++i){
        cout << min_res[i] << " " << max_res[i] << endl;
    }


}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
