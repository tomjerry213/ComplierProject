#include "../run.h"

void kernel_case8(int (&A)[32][16]) {
for(int i = 0; i < 32; ++i){
  for(int j = 0; j < 16; ++j){
    if (j < 16) {
      if (i < 32) {
        A[i][j] = 2;
      } else {
      }
    } else {
    }
  }
}
}

