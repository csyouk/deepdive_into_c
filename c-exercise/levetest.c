#include <stdio.h>
void main(void){
	int x = -2;
	int a, b, c;
	// 순차진행
	//  수학 식으로 써보면, a = -2,  b = -1,  c = 0  
	// 최종적으로 평가 되는 식은 다음과 같다.
	// if(c = 0) x++;
	// c = 0이므로 x++; 식은 평가되지 않는다.
	// 핵심은 순차연산자라는 것. 즉, ,를 거치기 전에 이미 식이 평가된다는 것이다.

	if (a = x++, b = x++, c = x++) x++;
	printf("%d\n", ++x);

	int y = 0x1234567; char yy;
	yy = y;
	printf("%x\n", yy);
}