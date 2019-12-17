/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DualLinkList.c
* Description		: 	DualLinkList operation center

i=i-j+2:
ywf@ywf-pc:/work/workspace/test$ ./SimpleString ababd abd
ababd,abd index:3
pos:abd
ywf@ywf-pc:/work/workspace/test$ ./SimpleString abcd cd
abcd,cd index:3
pos:cd
ywf@ywf-pc:/work/workspace/test$ ./SimpleString abcd abd
abcd,abd index:0
ywf@ywf-pc:/work/workspace/test$ 


i++:
ywf@ywf-pc:/work/workspace/test$ ./SimpleString ababd abd
ababd,abd index:0

* Created			: 	2017.04.02.
* Author			: 	Yu Weifeng
* Function List 	: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
	
	
} T_String;

#define T_STRING_1 "abcdefg"
#define S_STRING_1 "abcdefghij"

/*****************************************************************************
-Fuction		: Index
-Description	: 求子串位置的定位函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int Index(char * s,char *t,int pos)
{
	int i,j;
	i=pos;j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(s[i] == t[j])
		{
			++i;
			++j;
			
		}
		else
		{//退回到前面下一个字符开始
			i=i-j+2;//1.记住这个,
			//2.该式符合i++效果(不等则一个个往下查找，然后和子串头部开始比较)
			//3.减去已相等的次数，又第一次肯定比了，故+2(从没有从头比过的开始)
			//4.如果用i++则漏一种情况，如ababd abd的情况
			//5.考虑ababd abd的情况
			
			j=1;//重新开始
		}
		
	}
	if(j>t[0])
		return i-t[0];
	else
		return 0;
	
	
}


/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char ** agrv)
{
	char S[128] ={0};
	char T[128] ={0};
	strncpy(S+1,agrv[1],strlen(agrv[1]));
	S[0] = strlen(agrv[1]);
	
	strncpy(T+1,agrv[2],strlen(agrv[2]));
	T[0] = strlen(agrv[2]);
	
	int pos = Index(S,T,1);
	printf("%s,%s index:%d\r\n",agrv[1],agrv[2],pos);
	if(pos != 0)
		printf("pos:%s\r\n",&S[pos]);
}






























