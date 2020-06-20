#include "../run2.h"

void grad_case5(float (&C)[32][32], float (&D)[4][32], float (&dA)[16][32], float (&dB)[16][32][4]) {
for(int i = 0; i < 16; ++i){
  for(int j = 0; j < 32; ++j){
    for(int k = 0; k < 32; ++k){
      for(int l = 0; l < 4; ++l){
        if (j < 32) {
          if (l < 4) {
            if (j < 32) {
              if (k < 32) {
                if (l < 4) {
                  if (k < 32) {
                    if (i < 16) {
                      if (j < 32) {
                        if (i < 16) {
                          dB[i][k][l] += ((((float)1.) * (C[k][j])) * (D[l][j])) * (dA[i][j]);
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
}

