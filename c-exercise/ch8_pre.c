#include <stdio.h>

void main(void){

	//int a[][4] = { { 1, 2, 3, }, {3,4,5} };

	//for (int i = 0; i < sizeof a / sizeof a[0]; i++)
	//{
	//	for (int j = 0; j < sizeof a[0] / sizeof a[0][0]; j++)
	//	{
	//		printf("%d ", a[i][j]);
	//	}
	//	printf("\n");
	//}


	struct st
	{
		int a;
		char b;
		int c;
	} x = {1, 'A', 10};

	union uni1
	{
		int a;
		unsigned char b; 
	} y = {0x12345678};

	union uni2
	{
		unsigned char a;
		short  b;
	} z = { 0x12345678 };

	struct tag_Friend1
	{
		int x, y;
	};

	typedef struct
	{
		int x, y;
	} tag_Friend2;

	union IP
	{
		unsigned long addr;
		unsigned char sub[4];
	} ip = {0xff3953d2};

	printf("ip addr : %d.%d.%d.%d\n", ip.sub[3], ip.sub[2], ip.sub[1], ip.sub[0]);

	union IP2
	{
		unsigned long addr;
		unsigned char sub[4];
	} ip2;
	
	ip2.sub[0] = 0x12;
	ip2.sub[1] = 0x34;
	ip2.sub[2] = 0x56;
	ip2.sub[3] = 0x78;

	printf("ip addr : %d.%d.%d.%d", ip2.sub[3], ip2.sub[2], ip2.sub[1], ip2.sub[0]);

	union IP ip_1 = { 0x12345678 };

	struct st xx = { 0x12345678 };
}

