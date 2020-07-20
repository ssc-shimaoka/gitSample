#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

const char* FILENAME = "./name.txt";

int searchString(const char* path, char* inputName, int* i);


int main()
{
	// 発見した桁数
	int i = 1;
	// 検索文字
	char inputName[12];
	// 文字入力
	scanf("%s", inputName);

	//　検索文字がファイルの文字列にあるか
	int res = searchString(FILENAME, inputName, &i);

	if (res == 1)
	{
		printf("%d桁目に発見\n", i);
	}
	else {
		printf("発見できませんでした\n");
	}

	return 1;
}


int searchString(const char* path, char* inputName, int* count)
{
	FILE* fp;
	char buf[200] = { 0 };
	int res = 0;

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		return 0;
	}

	while (1)
	{
		fgets(buf, 20, fp);
		printf("%s\n", buf);

		if (strstr(buf, inputName) != NULL)
		{
			res = 1;
			break;
		}
		else {
			*count = *count + 1;
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);

	return res;
}

