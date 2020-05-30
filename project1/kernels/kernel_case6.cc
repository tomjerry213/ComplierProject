#include "../run.h"

void kernel_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3], float (&A)[2][8][5][5]) {
for(int n = 0; n < 2; ++n){
  for(int k = 0; k < 8; ++k){
    for(int p = 0; p < 5; ++p){
      for(int q = 0; q < 5; ++q){
        for(int c = 0; c < 16; ++c){
          for(int r = 0; r < 3; ++r){
            for(int s = 0; s < 3; ++s){
              if (s < 3) {
                if (r < 3) {
                  if (c < 16) {
                    if (k < 8) {
                      if ((q) + (s) < 7) {
                        if ((p) + (r) < 7) {
                          if (c < 16) {
                            if (n < 2) {
                              if (q < 5) {
                                if (p < 5) {
                                  if (k < 8) {
                                    if (n < 2) {
                                      if (q < 5) {
                                        if (p < 5) {
                                          if (k < 8) {
                                            if (n < 2) {
                                              A[n][k][p][q] = (A[n][k][p][q]) + ((B[n][c][(p) + (r)][(q) + (s)]) * (C[k][c][r][s]));
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
  }
}
}

