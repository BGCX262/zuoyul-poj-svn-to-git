/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 1013.cpp
 * @author zuoyul(zuoyul@baidu.com)
 * @date 2015/01/04 17:59:18
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "stdio.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool trans(char* left, char* right, char* res, char factor, int val){
    int left_val = 0;
    int right_val = 0;
    
    for(unsigned i=0; i<strlen(left); i++){
        if(left[i]!=factor){
            left_val ++;
        }else{
            left_val += val;
        }
    }
    for(unsigned i=0; i<strlen(right); i++){
        if(right[i]!=factor){
            right_val ++;
        }else{
            right_val += val;
        }
    }
    //printf("lv: %d, rv: %d\n", left_val, right_val);
    if(strcmp(res, "even")==0 && left_val==right_val){
        return true;
    }else if(strcmp(res, "up")==0 && left_val > right_val){
        return true;
    }else if(strcmp(res, "down")==0 && left_val < right_val){
        return true;
    }
    return false;
}

int main(int argc, char* argv[]){
    char left1[15], right1[15], res1[10];
    char left2[15], right2[15], res2[10];
    char left3[15], right3[15], res3[10];
    int cnt;
    scanf("%d", &cnt);
    vector<string> res;
    
    for(int i=0; i<cnt; i++){
        scanf("%s %s %s", left1, right1, res1);
        scanf("%s %s %s", left2, right2, res2);
        scanf("%s %s %s", left3, right3, res3);
        for(int j=0; j<12; j++){
            if(trans(left1, right1, res1, 'A'+j, 0) &&
                trans(left2, right2, res2, 'A'+j, 0) &&
                trans(left3, right3, res3, 'A'+j, 0)){
                //printf("%c is the counterfeit coin and it is light.\n", 'A'+j);
                char t[2];
                t[0] = 'A'+j;
                t[1] = '\0';
                string tmp = string(t);
                tmp += " is the counterfeit coin and it is light.";
                res.push_back(tmp);
            }else if(trans(left1, right1, res1, 'A'+j, 2) &&
                trans(left2, right2, res2, 'A'+j, 2) &&
                trans(left3, right3, res3, 'A'+j, 2)){
                //printf("%c is the counterfeit coin and it is heavy.\n", 'A'+j);
                char t[2];
                t[0] = 'A'+j;
                t[1] = '\0';
                string tmp = string(t);
                tmp += " is the counterfeit coin and it is heavy.";
                res.push_back(tmp);
            }
        }
    }
    for(vector<string>::iterator I=res.begin(), E=res.end(); I!=E; I++){
        cout << *I << endl;
    }

}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
