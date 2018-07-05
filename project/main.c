/* ***************************************************************
 *      Filename: main.c
 *   Description: debug for the 
 *				  scroll compressor project
 *       Version: 1.0
 *       Created: 2018/07/04 
 *      Revision: none
 *      Compiler: gcc
 *        Author: Lv Hongbin
 *       Company: Shanghai JiaoTong Univerity
 * **************************************************************/

#include<stdio.h>
#include<math.h>
#include "./utilities/MyMath.h"

double func(double a);
int main() {
	printf("f0->5(a)da = %lf\n", integral(5,0,func));
	return 0;
}

double func(double a) {
	return pow(a,2);
}