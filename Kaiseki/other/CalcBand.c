#include "fem2d.h"

int CalcBand(int np, MatrixPtr matrix, int nelem, ElemPtr elem){
  int i, j, k, l, m, nd, count;
  
  for(i=1; i<=np; i++){
    matrix[i].nk = 0;
  }
  
  for(i=1; i<=nelem; i++){
    for(j=0; j<3; j++){
      if((l = elem[i].node[j]) > np) continue;
      for(k=0; k<3; k++){
	if(((m = elem[i].node[k]) > np) || (m < 1)) continue;
	if((nd = m - l + 1) > matrix[l].nk) matrix[l].nk = nd;
      }
    }
  }
  
  count = matrix[1].nk;
  
  for(i=2; i<=np; i++){
    j = i-1;
    nd = matrix[j].nk-1;
    if(matrix[j].nk < nd) matrix[i].nk = nd;
    if(count < nd) count = nd;
  }

  return count;
}
