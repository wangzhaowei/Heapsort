//
//  main.c
//  heapSort
//
//  Created by Nico-Mac on 14/12/27.
//  Copyright (c) 2014年 王 昭威. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

void randomSequence(int* nums, int len);
void heapFixedUp(int* nums, int idx);
void heapFixedDown(int* nums, int idx, int len);
void insertNum(int* nums, int idx, int num);
void makeMaxHeap(int* nums, int len);
void deleteNum(int* nums, int len);

const int numArrayLen = 21;
const int capcity = 30;

int main(int argc, const char * argv[]) {
    int num[capcity] = {9,15,13,10,6,18,5,17,7,19,4,3,12,14,20,1,8,2,11,16};
    makeMaxHeap(num, numArrayLen - 1);
    
    srand((unsigned int)time(NULL));
    insertNum(num, numArrayLen, rand() % 100 * (int)pow(-1, rand() % 2));
    for (int i = 0; i < numArrayLen; i++) {
        printf("%d ", num[0]);
        deleteNum(num, numArrayLen - i);
    }
    printf("\n");
    
    return 0;
}

void insertNum(int* nums, int len, int num){
    nums[len - 1] = num;
    nums[len] = num - 1;
    heapFixedUp(nums, len - 1);
}

void deleteNum(int* nums, int len){
    nums[0] = nums[len - 1];
    heapFixedDown(nums, 0, len - 1);
}

void makeMaxHeap(int* nums, int len){
    
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapFixedDown(nums, i, len);
    }
}

void heapFixedUp(int* nums, int idx){
    int tmp = 0;
    int end = 0;
    int currentIdx = idx;
    for (int i = (idx - 1) / 2; i >= 0 && !end; i = (i - 1) / 2) {
        if (nums[currentIdx] > nums[i]) {
            tmp = nums[currentIdx];
            nums[currentIdx] = nums[i];
            nums[i] = tmp;
            currentIdx = i;
        }
        else{
            end = 1;
        }
    }
}

void heapFixedDown(int* nums, int idx, int len){
    int end = 0;
    int parentIdx = idx;
    nums[len] = INT_MIN;
    for (int i = parentIdx * 2 + 1; i < len && !end; i = parentIdx * 2 + 1) {
        int maxNumId = nums[i] >= nums[i + 1] ? i : i + 1;
        if (nums[parentIdx] < nums[maxNumId]) {
            int tmp = nums[maxNumId];
            nums[maxNumId] = nums[parentIdx];
            nums[parentIdx] = tmp;
            parentIdx = maxNumId;
        }
        else{
            end = 1;
        }
    }
}

void randomSequence(int* nums, int len){
    int numsBuffer[len];
    for (int i = 0; i < len; i++) {
        numsBuffer[i] = nums[i];
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < len; i++) {
        int randIdx = rand() % (len - i);
        nums[i] = numsBuffer[randIdx];
        for (int j = randIdx; j < (len - i - 1); j++) {
            numsBuffer[j] = numsBuffer[j + 1];
        }
    }
}
