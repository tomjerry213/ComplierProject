#include "../run2.h"

void grad_case7(float (&dB)[16][32], float (&dA)[32][16]) {
for(int i = 0; i < 16; ++i){
  for(int j = 0; j < 32; ++j){
    if (i < 16) {
      if (j < 32) {
        if (j < 32) {
          if (i < 16) {
            dA[j][i] += ((float)1.) * (dB[i][j]);
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

