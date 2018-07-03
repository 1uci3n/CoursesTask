#include "fem2d.h"

void SetBound(int nnode, NodePtr node, int ndiri, DiriPtr diri){
  int i, j;
  
  for(i=1; i<=nnode; i++){
    node[i].v = 0.0;
  }
  
  for(i=0; i<ndiri; i++){
    for(j=diri[i].ndis; j<=diri[i].ndie; j++){
      node[j].v = diri[i].diri;
    }
  }
}
