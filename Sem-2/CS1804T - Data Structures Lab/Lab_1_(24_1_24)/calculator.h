#include <stdio.h>


int Add(int *num1 , int *num2){
    return *num1 + *num2;
}
int Sub(int *num1 , int *num2){
    return *num1 - *num2;
}
int Mul(int *num1 , int *num2){
    return *num1 * *num2;
}
float Div(int *num1 , int *num2){
    return (float)*num1 / *num2;
}