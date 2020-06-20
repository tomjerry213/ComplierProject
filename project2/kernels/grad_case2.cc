#include "../run2.h"

void grad_case2(float (&A)[4][16], float (&dB)[4][16], float (&dA)[4][16]) {
for(int i = 0; i < 4; ++i){
  for(int j = 0; j < 16; ++j){
    if (j < 16) {
      if (i < 4) {
        if (j < 16) {
          if (i < 4) {
            if (j < 16) {
              if (i < 4) {
                dA[i][j] += (((float)1.) * (A[i][j])) * (dB[i][j]);
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
    if (j < 16) {
      if (i < 4) {
        if (j < 16) {
          if (i < 4) {
            if (j < 16) {
              if (i < 4) {
                dA[i][j] += ((A[i][j]) * ((float)1.)) * (dB[i][j]);
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

