#include "../run.h"

void kernel_case3(int (&B)[16][32], int (&C)[32][32], int (&D)[16][32], int &alpha, int &beta, int (&A)[16][32]) {
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
                      A[i][j] = (A[i][j]) + ((alpha) * ((B[i][k]) * (C[k][j])));
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
for(int i = 0; i < 16; ++i){
  for(int j = 0; j < 32; ++j){
    if (j < 32) {
      if (i < 16) {
        if (j < 32) {
          if (i < 16) {
            if (j < 32) {
              if (i < 16) {
                A[i][j] = (A[i][j]) + ((beta) * (D[i][j]));
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

