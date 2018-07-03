#include "fem2d.h"

void CalcMatrix(int nelem, ElemPtr elem){
  int i, j, k;

  for(i=1; i<=nelem; i++){
    for(j=0; j<3; j++){
      for(k=0; k<3; k++){
	elem[i].se[j][k] = 
	  (elem[i].ex * elem[i].c[j] * elem[i].c[k]
	   +elem[i].ey * elem[i].d[j] * elem[i].d[k])*0.25/elem[i].delt;
      }
    }
  }
}
