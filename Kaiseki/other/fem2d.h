#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  int node[3];
  double c[3], d[3];
  double se[3][3];
  double delt;
  double ex, ey;
} Elem, *ElemPtr;

typedef struct
{
  double x, y;
  double v;
} Node, *NodePtr;

typedef struct
{
  int ndis, ndie;
  double diri;
} Diri, *DiriPtr;

typedef struct
{
  double h[100];
  int nk;
} Matrix, *MatrixPtr;

void ReadMesh(), CalcElem(), CalcMatrix(), SetBound(), Coef(), Gauss();
int ReadCond(), CalcBand();
