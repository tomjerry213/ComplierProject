#include "../run2.h"

void grad_case10(float (&dA)[8][8], float (&dB)[10][8]) {
for(int i = 0; i < 8; ++i){
  for(int j = 0; j < 8; ++j){
    for(int temp0 = 0; temp0 < 10; ++temp0){
      for(int temp1 = 0; temp1 < 10; ++temp1){
        if (temp1 == (i) + (2)) {
          if (temp0 == (i) + (1)) {
            if (j < 8) {
              if (temp1 < 10) {
                if (j < 8) {
                  if (temp0 < 10) {
                    if (j < 8) {
                      if (i < 10) {
                        if (j < 8) {
                          if (i < 8) {
                            dB[i][j] += (((float)1.) / ((float)3.)) * (dA[i][j]);
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
        if (temp1 == (i) + (2)) {
          if (temp0 == (i) + (1)) {
            if (j < 8) {
              if (temp1 < 10) {
                if (j < 8) {
                  if (temp0 < 10) {
                    if (j < 8) {
                      if (i < 10) {
                        if (j < 8) {
                          if (i < 8) {
                            dB[temp0][j] += (((float)1.) / ((float)3.)) * (dA[i][j]);
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
        if (temp1 == (i) + (2)) {
          if (temp0 == (i) + (1)) {
            if (j < 8) {
              if (temp1 < 10) {
                if (j < 8) {
                  if (temp0 < 10) {
                    if (j < 8) {
                      if (i < 10) {
                        if (j < 8) {
                          if (i < 8) {
                            dB[temp1][j] += (((float)1.) / ((float)3.)) * (dA[i][j]);
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

