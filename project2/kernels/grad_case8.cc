#include "../run2.h"

void grad_case8(float (&dB)[32], float (&dA)[2][16]) {
for(int i = 0; i < 32; ++i){
  for(int temp0 = 0; temp0 < 2; ++temp0){
    for(int temp1 = 0; temp1 < 16; ++temp1){
      if (temp1 == (i) % (16)) {
        if (temp0 == (i) / (16)) {
          if (temp1 < 16) {
            if (temp0 < 2) {
              if (i < 32) {
                dA[temp0][temp1] += ((float)1.) * (dB[i]);
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

