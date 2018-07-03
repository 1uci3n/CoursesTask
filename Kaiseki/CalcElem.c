/*
* @Author: weilantian
* @Date:   2018-06-06 12:58:57
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-06-07 20:40:51
*/
#include "fem2d.h"

void CalcElem(int nelem, ElemPtr elem, int nnode, NodePtr node){
	int i;

	for (i = 1; i <= nelem; i++)
	{
		int j1 = elem[i].node[0];
		int j2 = elem[i].node[1];
		int j3 = elem[i].node[2];

		elem[i].c[0] = node[j2].y - node[j3].y;
		elem[i].c[1] = node[j3].y - node[j1].y;
		elem[i].c[2] = node[j1].y - node[j2].y;
		elem[i].d[0] = node[j3].x - node[j2].x;
		elem[i].d[1] = node[j1].x - node[j3].x;
		elem[i].d[2] = node[j2].x - node[j1].x;

		elem[i].delt = 0.5 * (elem[i].c[1] * elem[i].d[2] - elem[i].c[2] * elem[i].d[1]);
	}
}