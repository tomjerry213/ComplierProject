#include "../run.h"

void kernel_case4(float (&B)[16][32], float (&C)[32][32], float (&A)[16][32]) {
for(int i = 0; i < 16; ++i){
  for(int j = 0; j < 32; ++j){
    for(int k = 0; k < 32; ++k){
      if (j < 32) {
        if (k < 32) {
          if (k < 32) {
            if (i < 16) {
              if (j < 32) {
                if (i < 16) {
                  if (j < 32) {
                    if (i < 16) {
                      A[i][j] = (A[i][j]) + ((B[i][k]) * (C[k][j]));
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

