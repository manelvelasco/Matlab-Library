#ifndef __c23_experiment_lib2_h__
#define __c23_experiment_lib2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_experiment_lib2InstanceStruct
#define typedef_SFc23_experiment_lib2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_experiment_lib2;
  real_T c23_num_generators;
  real_T c23_ts;
  real_T c23_dr[4];
  real_T c23_dataf[100];
  boolean_T c23_dataf_not_empty;
  real_T c23_datav[100];
  boolean_T c23_datav_not_empty;
  real_T c23_dataq[100];
  boolean_T c23_dataq_not_empty;
  real_T c23_datau[100];
  boolean_T c23_datau_not_empty;
  real_T c23_t;
  boolean_T c23_t_not_empty;
  real_T c23_tc;
  boolean_T c23_tc_not_empty;
  real_T c23_drift;
  boolean_T c23_drift_not_empty;
  real_T c23_integral;
  boolean_T c23_integral_not_empty;
} SFc23_experiment_lib2InstanceStruct;

#endif                                 /*typedef_SFc23_experiment_lib2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_experiment_lib2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c23_experiment_lib2_get_check_sum(mxArray *plhs[]);
extern void c23_experiment_lib2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
