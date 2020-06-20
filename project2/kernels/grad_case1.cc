#include "../run2.h"

void grad_case1(float (&B)[4][16], float (&dC)[4][16], float (&dA)[4][16]) {
for(int i = 0; i < 4; ++i){
  for(int j = 0; j < 16; ++j){
    if (j < 16) {
      if (i < 4) {
        if (j < 16) {
          if (i < 4) {
            if (j < 16) {
              if (i < 4) {
                dA[i][j] += (((float)1.) * (B[i][j])) * (dC[i][j]);
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

