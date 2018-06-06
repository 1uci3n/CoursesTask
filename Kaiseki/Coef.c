/*
* @Author: weilantian
* @Date:   2018-06-06 14:45:02
* @Last Modified by:   weilantian
* @Last Modified time: 2018-06-06 17:27:47
*/
#include "fem2d.h"

void Coef(int np, int nband, MatrixPtr matrix, int nelem, ElemPtr elem, int nnode, NodePtr node){
	int i, j, k, l, m;

	for (i = 1; i <= np; ++i)
	{
		for (j = 1; j < nband; ++j)
		{
			matrix[i].h[j] = 0.0;
		}
	}

	for (ii = 1; i < nelem; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if ((l = elem[i].node[j]) > np)
			{
				continue;
			}
			for (k = 0; k < 3; ++k)
			{
				if ((m = elem(i).node[k]) < l)
				{
					continue;
				}
				if (m > np)
				{
					node[l].v -= elem[i].se[j][k] * node[m].v;
				} else {
					matrix[l].h[m - l + 1] += elem[i].se[j][k];
				}
			}
		}
	}
}