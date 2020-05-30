#include "../run.h"

void kernel_example(float (&B)[32][16], float (&C)[32][16], float (&A)[32][16]) {
for(int i = 0; i < 32; ++i){
  for(int j = 0; j < 16; ++j){
    if (j < 16) {
      if (i < 32) {
        if (j < 16) {
          if (i < 32) {
            if (j < 16) {
              if (i < 32) {
                A[i][j] = (C[i][j]) * (B[i][j]);
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

