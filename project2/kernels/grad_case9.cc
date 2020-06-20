#include "../run2.h"

void grad_case9(float (&dB)[4][6], float (&dA)[4]) {
for(int i = 0; i < 4; ++i){
  for(int j = 0; j < 6; ++j){
    if (i < 4) {
      if (j < 6) {
        if (i < 4) {
          dA[i] += ((float)1.) * (dB[i][j]);
        } else {
        }
      } else {
      }
    } else {
    }
  }
}
}

