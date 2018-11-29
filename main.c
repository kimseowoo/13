#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

int is_whitespace(char c)
{
	if (c ==' '||
		c =='\t' ||
		c =='\n' ||
		c =='\r' ||
		c =='('||
		c == ')')
		
		return 1;	//������ڴ�. 
	
		return 0;	//���ǹ��� ���ڴ�. 
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fget_word(FILE* fp, char* word)
{
	char c;
	int cnt;
	
	
	while((c=fgetc(fp))!=EOF)		//1���� ���� 
	{
		if(is_whitespace(c) == 0)	 
		{
			break;
		}							//���ǹ��� �����̸� ����
	}

	if (c == EOF) 					//���� ���� ���ڰ� �������϶� 
	{
		return 0;
	}
	
	//���������� �ܾ �ѱ��ھ� ���� 
	cnt=0;
	word[cnt++] = c;		//�Ʊ� ���� ù���� �Է� 
	word[cnt] = '\0';		//Ȥ�� �ڿ��� ������ �� �����Ƿ� (�ѱ���¥�� �ܾ�) 
	
	while ((word[cnt]=fgetc(fp))!= EOF)		//1���� ���� 
	{
		if(is_whitespace(word[cnt])==1)
		{
			word[cnt] = '\0';
			break;							//���鹮�ڸ� ������ ����ϰ� ���� 
		}
		cnt++;
	}
	
	return cnt;
	
	
}
int main(int argc, char *argv[]) {
	
	FILE* fp;
	char name[100];
	char word[100];
	
	printf("input a file name : ");
	scanf("%s",name); // name�� �����Ͷ� & ����			
	
	//fopen
	fp = fopen(name, "r");
	
	//error handling
	if (fp==NULL)
	{
		printf("ERROR! check the file name : %s\n",name);
		return -1;
	}
	//word reading
	while (fget_word(fp, word) !=0)
	{
		//word processing
		count_word(word);
	}
	print_word();	
	//fclose
	fclose(fp);
	
	return 0;
}
