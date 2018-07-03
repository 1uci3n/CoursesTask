#include "fem2d.h"

int ReadCond(int *ndiri, DiriPtr diri){
  FILE *fp;
  int i, count;

  if((fp = fopen("cond.dat", "r")) == NULL){
    printf("Error: Can't open cond.dat !\n");
    exit(1);
  }

  fscanf(fp, "%d", ndiri);
 
  count = 0;
  for(i=0; i<*ndiri; i++){
    fscanf(fp, "%d%d%lf", &diri[i].ndis, &diri[i].ndie, &diri[i].diri);
    count += diri[i].ndie - diri[i].ndis + 1;
  }

  fclose(fp);
  
  return count;
}
