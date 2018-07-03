/*
* @Author: weilantian
* @Date:   2018-06-06 13:29:13
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-06-07 20:42:39
*/
#include "fem2d.h"

void SetBound(int nnode, NodePtr node, int ndiri, DiriPtr diri){
	int i, j;

	for (i = 1; i <= nnode; i++)
	{
		node[i].v = 0.0;
	}

	for (i = 0; i < ndiri; i++)
	{
		for (j = diri[i].ndis; j <= diri[i].ndie; j++)
		{
			node[j].v = diri[i].diri;
		}
	}
}