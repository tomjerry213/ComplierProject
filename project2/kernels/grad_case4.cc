#include "../run2.h"

void grad_case4(float (&B)[16][32], float (&C)[32][32], float (&dA)[16][32], float (&dB)[16][32], float (&dC)[32][32]) {
for(int i = 0; i < 16; ++i){
  for(int j = 0; j < 32; ++j){
    for(int k = 0; k < 32; ++k){
      if (j < 32) {
        if (k < 32) {
          if (k < 32) {
            if (i < 16) {
              if (j < 32) {
                if (i < 16) {
                  dB[i][k] += (((float)1.) * (C[k][j])) * (dA[i][j]);
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
      if (j < 32) {
        if (k < 32) {
          if (k < 32) {
            if (i < 16) {
              if (j < 32) {
                if (i < 16) {
                  dC[k][j] += ((B[i][k]) * ((float)1.)) * (dA[i][j]);
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

