/*
* @Author: weilantian
* @Date:   2018-06-06 13:29:13
* @Last Modified by:   weilantian
* @Last Modified time: 2018-06-06 17:27:20
*/
#include "fem2d.j"

void SetBound(int nnode, NodePtr node, int ndiri, DiriPtr diri){
	int i, j;

	for (i = 1; i <= nnode; ++i)
	{
		node[i].v = 0.0;
	}

	for (i = 0; i < ndiri; ++i)
	{
		for (int j = diri[i].ndis; j <= diri[i].ndie; ++j)
		{
			node[j].v = diri[i].diri;
		}
	}
}