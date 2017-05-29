#include "globalVariable.h"

void set_max_var() {
  TMAX_WALK = T_WALK + EPS;
  TMAX_BUS = T_BUS + EPS;
  TMAX_CAR = T_CAR + EPS;
  TMAX_SLEEP = T_SLEEP + EPS;
}
