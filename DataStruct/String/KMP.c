/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	KMP.c
* Description		: 	KMP operation center

GetNext:
ywf@ywf-pc:/work/workspace/test$ gcc -o KMP KMP.c 
ywf@ywf-pc:/work/workspace/test$ ./KMP ababd abd
ababd,abd index:3
pos:abd

GetNextVal:
ywf@ywf-pc:/work/workspace/test$ gcc -o KMP KMP.c 
ywf@ywf-pc:/work/workspace/test$ ./KMP ababd abd
ababd,abd index:3
pos:abd

ywf@ywf-pc:/work/workspace/test$ gcc -o KMP KMP.c 
ywf@ywf-pc:/work/workspace/test$ ./KMP ababcababcabababc  ababcabababc
Next   :0 1 1 2 3 1 2 3 4 5 4 5 
NextVal:0 1 0 1 3 0 1 0 1 5 1 3 
ababcababcabababc,ababcabababc index:6
pos:ababcabababc

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
-Fuction		: GetNext
-Description	: 求模式串t的next函数并存入数组 next
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetNext(char *t,int next[])
{
	int i,j;
	i=1;//数组坐标
	next[1]=0;j=0;
	while(i<t[0])
	{
		if(j==0 || t[i] == t[j])
		{//第二个元素的next值比为1
			++i;
			++j;//相等，前面next值加1
			next[i]=j;//1.前面相等字符串加1   /*********************************不一样的地方***************************************/
		}
		else
		{//不等，匹配问题
			j=next[j];//2.如果不等，则等同于前面求子串问题，用KMP
		}
		
	}
	return 0;

}

/*****************************************************************************
-Fuction		: GetNextVal
-Description	: 求模式串t的next函数修正值并存入数组 nextval
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetNextVal(char *t,int nextval[])
{
	int i,j;
	i=1;//数组坐标
	nextval[1]=0;j=0;
	while(i<t[0])
	{
		if(j==0 || t[i] == t[j])
		{//第二个元素的next值比为1
			++i;
			++j;//相等，前面next值加1
			/*********************************不一样的地方***************************************/
			if(t[i] != t[j])//1'包括当前和前面相同的最大长度(正好是next值(来自相等(++)))+1 的末尾字符比较，
				nextval[i]=j;//3.不等，保持原来的next值(前面相等字符串加1)
			else
				nextval[i]=nextval[j];//2.相等，使用前(上)一个同字符的next值，(取现在next值(上一次的值))
		}
		else
		{//不等，匹配问题
			j=nextval[j];//3.如果不等，则等同于前面求子串问题，用KMP
		}
		
	}
	return 0;

}

/*****************************************************************************
-Fuction		: Index
-Description	: 利用模式串t的next函数求t在主串s中第pos个字符之后的位置
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int IndexKMP(char *s,char *t,int pos,int next[])
{
	int i,j;
	i=pos;j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0 || s[i] == t[j])
		{//3.退回到0则是无效值,i++,j++ //5.为0必然比较过第一个元素且不等，并且前面相等的部分已经经过Next处理过了，不相等的部分更加判断过，所以此时该i++,j++
			++i;
			++j;
			
		}
		else
		{//2.i不变,j退回到next[j]位置再比较 //4.s和t相等字符串中，s后半段必然等于t后半段，又t后半段等于t前半段,所以s后半段必等于t前半段,所以这个必相等的长度就不用再比较了
			j=next[j];//1.next为 前面相等字符串+1,0是无效值,1表示不存在相等
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
	int next[128] ={0};//t size
	int nextval[128] ={0};//t size
	int i=0;
	
	
	strncpy(S+1,agrv[1],strlen(agrv[1]));
	S[0] = strlen(agrv[1]);
	
	strncpy(T+1,agrv[2],strlen(agrv[2]));
	T[0] = strlen(agrv[2]);
	
	GetNext(T,next);//GetNext
	printf("Next   :");
	for(i=1;i<strlen(agrv[2])+1;i++)
	{
		printf("%d ",next[i]);	
	}	
	printf("\r\nNextVal:");
	GetNextVal(T,nextval);//GetNextVal
	for(i=1;i<strlen(agrv[2])+1;i++)
	{
		printf("%d ",nextval[i]);	
	}	
	printf("\r\n");
	
	int pos = IndexKMP(S,T,1,nextval);
	printf("%s,%s index:%d\r\n",agrv[1],agrv[2],pos);
	if(pos != 0)
		printf("pos:%s\r\n",&S[pos]);
}






























