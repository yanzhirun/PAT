/*超市计费系统设计*/

#include <stdio.h>

int main(int argc, char * argv[])
{
	int num;
	double price;
	double discount;

	printf("bata 1.0\n");

	//1.输入商品数量
	printf("please input the number of things:");
	scanf("%d",&num);

	//2.输入价格
	printf("please input the price of things:");
	scanf("%lf",&price);
	
	//3.打折额度
	printf("please input the discount:");
	scanf("%lf",&discount);

	//4.计算对应款项
	printf("the totle price: %.2f $\n", num * price * discount);

	return 0;
}



