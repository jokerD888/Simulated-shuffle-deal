#define _CRT_SECURE_NO_WARNINGS 1
/*#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];//�������
	char face[10];//��ɫ
};
int main(void)
{
	char* Suit[]={ "Spades","Hearts","Clubs","Diamonds" };
	char* Face[] = { "A","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	int i, j;
	int result[52] = { 0 };//����˳��
	struct CARD card[52];//52���ṹ��������52����
	for (i = 0; i < 52; i++)
	{
		result[i] = -1;//������result��Ԫ�ظ�ֵΪ-1�������Բ���-1����ѡ�����0-51�����������
	}
	for (i = 0; i < 52; i++)//�������Ʒŵ�card[]�У���˳��ֵ
	{
		strcpy(card[i].suit, Suit[i / 13]);//card������ǰ13��Ԫ���ƶ���ͬһ��ɫSpades
		strcpy(card[i].face, Face[i % 13]);
	}
	srand(time(NULL));//����ʱ������������������
	i = 0;//�巢�Ƽ�����
	while (1)
	{
		result[i] = rand() % 52;//����0-52�������
		for (j = 0; j < i; j++)
		{                        //������������������������ͬ���ƣ����������������ǰ���ֹ���������˴β����������
			if (result[j] == result[i]) break;
		}
		if (j < i) continue;//����j<i,˵��������ظ����ᵽ����ѭ����ʼ���ٴ����������
		i++;
		if (i >= 52) break;
	}
	for (i = 0; i < 52; i++)
	{
		printf("%10s %5s\n", card[result[i]].suit, card[result[i]].face);
	}
	return 0;
}*/
//��Ȼ�˷���ʵ�ַ���Ҫ�󣬵�������������������ӣ������µĲ�ͬ��������ĸ���Խ��ԽС�����ܳ����㷨�ӳ�����
//Ϊ�ˣ�������forѭ������ԭ�еĹ�����е�52���ƣ���card[i]��i��0��ʼ��51����card[j](jΪ0-51�����ֵ��������ֻ�辭��52�ν����������ϴ��
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
struct CARD
{
	char suit[10];//�������
	char face[10];//��ɫ
};
int main(void)
{
	char* Suit[] = { "Spades","Hearts","Clubs","Diamonds" };
	char* Face[] = { "A","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	int i, j;
	struct CARD card[52],temp;//52���ṹ��������52���ƣ�temp�м佻�����뽻����������һ��
	for (i = 0; i < 52; i++)//�������Ʒŵ�card[]�У���˳��ֵ
	{
		strcpy(card[i].suit, Suit[i / 13]);//card������ǰ13��Ԫ���ƶ���ͬһ��ɫSpades
		strcpy(card[i].face, Face[i % 13]);
	}
	srand(time(NULL));//����ʱ������������������
	for (i = 0; i < 52; i++)//ϴ�ƣ�����˳��
	{
		j = rand() % 52;
		temp = card[i];
		card[i] = card[j];
		card[j] = temp;
	}
	for (i = 0; i < 52; i++)//���ϴ�ƽ��
	{
		printf("%10s %5s\n", card[i].suit, card[i].face);
	}
	return 0;
}