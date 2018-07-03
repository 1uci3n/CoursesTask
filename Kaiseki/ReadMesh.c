/*
* @Author: weilantian
* @Date:   2018-06-05 16:06:21
* @Last Modified by:   1uci3n
* @Last Modified time: 2018-06-07 20:42:24
*/
#include "fem2d.h"

void ReadMesh(int *nelem, ElemPtr elem, int *nnode, NodePtr node){
	FILE *fp;
	int i;

	if ((fp = fopen("mesh.dat", "r")) == NULL)
	{
		printf("Error: Can't open mash.dat !\n");
		exit(1);
	}

	fscanf(fp, "%d%d", nelem, nnode);

	for (i = 1; i <= *nelem; i++)
	{
		fscanf(fp, "%d%d%d", &elem[i].node[0], &elem[i].node[1], &elem[i].node[2]);
	}

	for (i = 1; i <= *nnode; i++)
	{
		fscanf(fp, "%lf%lf", &node[i].x, &node[i].y);
	}
	
	fclose(fp);
}