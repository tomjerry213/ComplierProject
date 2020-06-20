#include "../run2.h"

void grad_case3(float (&B)[16][16], float (&dC)[4][16], float (&dA)[4][16]) {
for(int i = 0; i < 4; ++i){
  for(int j = 0; j < 16; ++j){
    for(int k = 0; k < 16; ++k){
      if (j < 16) {
        if (k < 16) {
          if (k < 16) {
            if (i < 4) {
              if (j < 16) {
                if (i < 4) {
                  dA[i][k] += (((float)1.) * (B[k][j])) * (dC[i][j]);
                } else {
                }
              } else {
              }
            } else {
            }
          } else {
          }
        } else {
        }
      } else {
      }
    }
  }
}
}

