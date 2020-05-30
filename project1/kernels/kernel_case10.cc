#include "../run.h"

void kernel_case10(float (&B)[10][10], float (&A)[8][8]) {
for(int i = 0; i < 8; ++i){
  for(int j = 0; j < 8; ++j){
    if (j < 10) {
      if ((i) + (2) < 10) {
        if (j < 10) {
          if ((i) + (1) < 10) {
            if (j < 10) {
              if (i < 10) {
                if (j < 8) {
                  if (i < 8) {
                    A[i][j] = (((B[i][j]) + (B[(i) + (1)][j])) + (B[(i) + (2)][j])) / ((float)3.);
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

