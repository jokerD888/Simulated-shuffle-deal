#define _CRT_SECURE_NO_WARNINGS 1
/*#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];//牌面点数
	char face[10];//花色
};
int main(void)
{
	char* Suit[]={ "Spades","Hearts","Clubs","Diamonds" };
	char* Face[] = { "A","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	int i, j;
	int result[52] = { 0 };//发牌顺序
	struct CARD card[52];//52个结构体数组存放52张牌
	for (i = 0; i < 52; i++)
	{
		result[i] = -1;//将数组result各元素赋值为-1，，可以不是-1，可选择除了0-51外的任意数，
	}
	for (i = 0; i < 52; i++)//将所有牌放到card[]中，按顺序赋值
	{
		strcpy(card[i].suit, Suit[i / 13]);//card数组中前13个元素牌都是同一花色Spades
		strcpy(card[i].face, Face[i % 13]);
	}
	srand(time(NULL));//设置时间戳，产生随机数种子
	i = 0;//清发牌计数器
	while (1)
	{
		result[i] = rand() % 52;//产生0-52的随机数
		for (j = 0; j < i; j++)
		{                        //避免随机数冲服，产生两张相同的牌，若产生的随机数以前出现过，则放弃此次产生的随机数
			if (result[j] == result[i]) break;
		}
		if (j < i) continue;//若就j<i,说明随机数重复，会到本次循环开始，再次生成随机数
		i++;
		if (i >= 52) break;
	}
	for (i = 0; i < 52; i++)
	{
		printf("%10s %5s\n", card[result[i]].suit, card[result[i]].face);
	}
	return 0;
}*/
//虽然此法可实现发牌要求，但随着随机数数量的增加，产生新的不同的随机数的概率越来越小，可能出现算法延迟问题
//为此，可以用for循环打乱原有的规矩排列的52张牌，将card[i]（i从0开始到51）与card[j](j为0-51的随机值）交换，只需经历52次交换即可完成洗牌
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];//牌面点数
	char face[10];//花色
};
int main(void)
{
	char* Suit[] = { "Spades","Hearts","Clubs","Diamonds" };
	char* Face[] = { "A","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	int i, j;
	struct CARD card[52],temp;//52个结构体数组存放52张牌，temp中间交换量与交换内容类型一致
	for (i = 0; i < 52; i++)//将所有牌放到card[]中，按顺序赋值
	{
		strcpy(card[i].suit, Suit[i / 13]);//card数组中前13个元素牌都是同一花色Spades
		strcpy(card[i].face, Face[i % 13]);
	}
	srand(time(NULL));//设置时间戳，产生随机数种子
	for (i = 0; i < 52; i++)//洗牌，打乱顺序
	{
		j = rand() % 52;
		temp = card[i];
		card[i] = card[j];
		card[j] = temp;
	}
	for (i = 0; i < 52; i++)//输出洗牌结果
	{
		printf("%10s %5s\n", card[i].suit, card[i].face);
	}
	return 0;
}