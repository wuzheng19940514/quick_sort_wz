//
//  main.c
//  quick_sort_wz
//
//  Created by Apple on 2018/10/9.
//  Copyright © 2018年 Apple. All rights reserved.
//

#include <stdio.h>
void quick_sort(int[], int, int, int);
int main()
{
    int data[20] = {39, 11, 48, 5, 77, 18, 70, 25, 55, 33};
    int size = 11, i;

    quick_sort(data, 0, --size-1, size-1);
    for(i = 0; i < size; i++)
        printf("%d  ", data[i]);
    printf("\n");
  //  system("PAUSE");
    return 0;
}

void quick_sort(int data[], int left, int right, int size)
{    
    int lbase, rbase, temp, i;
    if(left < right)
    {
        lbase = left+1;
        while(data[lbase] < data[left]) lbase++;
        rbase = right;
        while(data[rbase] > data[left]) rbase--;
        while(lbase < rbase)
        {
            temp = data[lbase];
            data[lbase] = data[rbase];
            data[rbase] = temp;
            lbase++;
            while(data[lbase] < data[left]) lbase++;
            rbase--;
            while(data[rbase] > data[left]) rbase--;
        }
        temp = data[left];
        data[left] = data[rbase];
        data[rbase] = temp;
        quick_sort(data, left, rbase-1, size);
        quick_sort(data, rbase+1, right, size);
    }
}

