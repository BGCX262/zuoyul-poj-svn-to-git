/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file 3617.cpp
 * @author zuoyul(zuoyul@baidu.com)
 * @date 2015/01/09 16:35:20
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>

int compare(char* right, char* reverse){

    while(*right!='\0'){
        if(*right<*reverse){
            return 1;
        }else if(*right>*reverse){
            return -1;
        }else{
            right++;
            reverse++;
        }
    }
    return 0;

}

int main(int argc, char* argv[]){

    int cnt;
    char right[2048], reverse[2048];
    char t;
    scanf("%d", &cnt);
    right[cnt] = 0;
    reverse[cnt] = 0;
    int i=0;
    while(i<cnt){
        scanf("%c", &t);
        scanf("%c", &right[i]);
        reverse[cnt-i-1] = right[i];
        i++;
    }
    int res = 0;
    int reverse_head = 0;
    int reverse_tail = cnt-1;
    int right_head = 0;
    int right_pos = cnt-1;
    int row = 0;
    while(1){
        if(right[right_head]=='\0' || reverse[reverse_head]=='\0'){
            break;
        }else if(compare(right+right_head, reverse+reverse_head)==1){
            printf("%c", right[right_head]);
            right[right_head++] = 0;
            reverse[reverse_tail--] = 0;
            if(++row >= 80){
                printf("\n");
                row=0;
            }
        }else if(compare(right+right_head, reverse+reverse_head)==-1){
            printf("%c", reverse[reverse_head]);
            reverse[reverse_head++]=0;
            right[right_pos--] = 0;
            if(++row >= 80){
                printf("\n");
                row=0;
            }
        }else{
            while(right[right_head]!='\0'){
                printf("%c", right[right_head++]);
                if(++row>=80){
                    printf("\n");
                    row=0;
                }
            }
            break;
        }
    }
    printf("\n");

}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
