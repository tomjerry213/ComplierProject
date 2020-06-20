#include "../run2.h"

void grad_case6(float (&C)[8][16][3][3], float (&dA)[2][8][5][5], float (&dB)[2][16][7][7]) {
for(int n = 0; n < 2; ++n){
  for(int k = 0; k < 8; ++k){
    for(int p = 0; p < 5; ++p){
      for(int q = 0; q < 5; ++q){
        for(int c = 0; c < 16; ++c){
          for(int temp0 = 0; temp0 < 7; ++temp0){
            for(int temp1 = 0; temp1 < 7; ++temp1){
              for(int r = 0; r < 3; ++r){
                for(int s = 0; s < 3; ++s){
                  if (temp1 == (q) + (s)) {
                    if (temp0 == (p) + (r)) {
                      if (s < 3) {
                        if (r < 3) {
                          if (c < 16) {
                            if (k < 8) {
                              if (temp1 < 7) {
                                if (temp0 < 7) {
                                  if (c < 16) {
                                    if (n < 2) {
                                      if (q < 5) {
                                        if (p < 5) {
                                          if (k < 8) {
                                            if (n < 2) {
                                              dB[n][c][temp0][temp1] += (((float)1.) * (C[k][c][r][s])) * (dA[n][k][p][q]);
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
}
}

