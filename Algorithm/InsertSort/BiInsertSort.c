/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BiInsertSort.c
* Description		: 	BiInsertSort operation center
* Created			: 	2017.06.16.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"




/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_RecordType atRecord[RECORD_NUMBER]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
	T_RecordSeqList tSeqList1, tSeqList2, tSeqList3;
	int i;
	for(i=0;i<RECORD_NUMBER;i++) // ��l1.r��ֵ
		tSeqList1.atRecord[i+1]=atRecord[i];
	tSeqList1.iLength=RECORD_NUMBER;
	tSeqList3=tSeqList2=tSeqList1; // ����˳���l2��l3��l1��ͬ
	printf("����ǰ:\n");
	TraverseRecordSeqList(&tSeqList1);
	MergeSort(&tSeqList1);
	printf("�۰���������:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

