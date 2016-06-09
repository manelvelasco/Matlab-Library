#ifndef __c24_experiment_lib2_h__
#define __c24_experiment_lib2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_experiment_lib2InstanceStruct
#define typedef_SFc24_experiment_lib2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_experiment_lib2;
  real_T c24_a;
  real_T c24_wo;
  real_T c24_kif;
  real_T c24_kpf;
  real_T c24_kiV;
  real_T c24_kpV;
  real_T c24_ts;
  real_T c24_dr[4];
  real_T c24_t;
  boolean_T c24_t_not_empty;
  real_T c24_tc;
  boolean_T c24_tc_not_empty;
  real_T c24_drift;
  boolean_T c24_drift_not_empty;
  real_T c24_integral;
  boolean_T c24_integral_not_empty;
} SFc24_experiment_lib2InstanceStruct;

#endif                                 /*typedef_SFc24_experiment_lib2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_experiment_lib2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c24_experiment_lib2_get_check_sum(mxArray *plhs[]);
extern void c24_experiment_lib2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
