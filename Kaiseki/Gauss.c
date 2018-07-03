/*
* @Author: weilantian
* @Date:   2018-06-06 14:58:59
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-06-07 20:40:32
*/
#include "fem2d.h"

void Gauss(int np, int nband, MatrixPtr matrix, NodePtr node){
	int mnp, i, j, k, l, ij, kj, nb;
	double r, q;

	mnp = np - 1;

	for (i = 1; i <= mnp; i++)
	{
		r = 1.0 / matrix[i].h[1];
		nb = matrix[i].nk;
		for (j = 2; j <= nb; j++)
		{
			q = r * matrix[i].h[j];
			ij = i + j - 1;
			for (k = j; k <= nb; k++)
			{
				kj = k - j + 1;
				matrix[ij].h[kj] -= q * matrix[i].h[k];
			}
			node[ij].v -= q * node[i].v;
			matrix[i].h[j] = q;
		}
		node[i].v *= r;
	}

	node[np].v /= matrix[np].h[1];

	for (i = 2; i <= np; i++)
	{
		k = np - i + 1;
		nb = matrix[k].nk;
		for (j = 2; j <= nb; j++)
		{
			l = k + j - 1;
			node[k].v -= matrix[k].h[j] * node[l].v;
		}
	}
}