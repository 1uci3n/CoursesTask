/*
* @Author: weilantian
* @Date:   2018-06-06 13:07:44
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-06-07 20:41:10
*/
#include "fem2d.h"

void CalcMatrix(int nelem, ElemPtr elem){
	int i, j, k;
	for (i = 1; i <= nelem; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				elem[i].se[j][k] = (elem[i].ex * elem[i].c[j] * elem[i].c[k]
					+ elem[i].ey * elem[i].d[j] * elem[i].d[k]) * 0.25 / elem[i].delt;
			}
		}
	}
}