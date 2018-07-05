/* ***************************************************************
 *      Filename: MyMath.c
 *   Description: apply all kinds of math tool to use for the 
 *				  scroll compressor project
 *       Version: 1.0
 *       Created: 2018/07/04 
 *      Revision: none
 *      Compiler: gcc
 *        Author: Lv Hongbin
 *       Company: Shanghai JiaoTong Univerity
 * **************************************************************/
#include "MyMath.h"

double integral(double upperBound, double lowerBound, double(* func)(double)) {
	double sum = 0;
	double currentVal = 0;
	double step = (upperBound - lowerBound) / N;
	for(currentVal=lowerBound; currentVal<upperBound; currentVal += step) {
		sum += func(currentVal) * step;
	}
	return sum;
}