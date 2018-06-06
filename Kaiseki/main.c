/*
* @Author: weilantian
* @Date:   2018-06-05 15:54:05
* @Last Modified by:   weilantian
* @Last Modified time: 2018-06-06 16:04:53
*/

#include "fem2d.h"

int main(int argc, char const *argv[])
{
	int nelem = 0;
	int nnode = 0;
	int nbound = 0;
	int np = 0;
	int nband = 0;
	int ndiri = 0;

	double eair = 1.0;

	Elem elem[100];
	Node node[100];
	Diri diri[5];
	Matrix matrix[200];
	int i;

	ReadMesh(&nelem, &elem, &nnode, &node);

	nbound = ReadCond(&ndiri, &diri);

	printf("nbound = %d\n", nbound);

	for (i = 1; i <= nelem; ++i)
	{
		elem[i].ex = elem[i].ey = eair;
	}

	CalcElem(nelem, &elem, nnode, &node);

	CalcMatrix(nelem, &elem);

	np = nnode - nbound;

	printf("np = %d\n", np);

	nband = CalcBand(np, &matrix, nelem, &nelem);

	printf("nband = %d\n", nband);

	SetBound(nnode, &node, ndiri, &diri);

	Coef(np, nband, &matrix, nelem, &elem, nnode, &node);

	Gauss(np, nband, &matrix, &node);

	for (i = 1; i <= nnode; ++i)
	{
		printf("No. %d: %f\n", i, node[i].v);
	}

	return 0;
}