#ifndef __c6_experiment_lib2_h__
#define __c6_experiment_lib2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_experiment_lib2InstanceStruct
#define typedef_SFc6_experiment_lib2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_experiment_lib2;
  real_T c6_Vn;
  real_T c6_wo;
  real_T c6_m;
  real_T c6_n;
  real_T c6_mp;
  real_T c6_Lv;
  real_T c6_ts;
  real_T c6_dr[4];
  real_T c6_t;
  boolean_T c6_t_not_empty;
  real_T c6_tc;
  boolean_T c6_tc_not_empty;
  real_T c6_drift;
  boolean_T c6_drift_not_empty;
} SFc6_experiment_lib2InstanceStruct;

#endif                                 /*typedef_SFc6_experiment_lib2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_experiment_lib2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_experiment_lib2_get_check_sum(mxArray *plhs[]);
extern void c6_experiment_lib2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
