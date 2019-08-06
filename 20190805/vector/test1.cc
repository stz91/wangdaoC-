
#include <stdio.h>

 

#define PR(...) printf(##__VA__ARGS__);    //Note：需编译器支持__VA__ARGS__

int main(void)

{

	int age = 26;

	int weight = 75;

	float BMI = 26.4;

	PR("oh mashuai");

	PR("Age:%d, weight:%d,BMI:%d",age,weight,BMI);

}
