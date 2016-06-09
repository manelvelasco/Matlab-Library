/* Include files */

#include <stddef.h>
#include "blas.h"
#include "experiment_lib2_sfun.h"
#include "c21_experiment_lib2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "experiment_lib2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c21_debug_family_names[14] = { "nargin", "nargout", "msg",
  "num_generators", "a", "f", "v", "q", "f_media", "v_media", "q_media", "dataf",
  "datav", "dataq" };

/* Function Declarations */
static void initialize_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance);
static void initialize_params_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance);
static void enable_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance);
static void disable_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance);
static void set_sim_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance, const mxArray *c21_st);
static void finalize_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance);
static void sf_gateway_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance);
static void c21_chartstep_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance);
static void initSimStructsc21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_dataq, const char_T *c21_identifier,
  real_T c21_y[100]);
static void c21_b_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_c_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_datav, const char_T *c21_identifier,
  real_T c21_y[100]);
static void c21_d_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100]);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_e_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_dataf, const char_T *c21_identifier,
  real_T c21_y[100]);
static void c21_f_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100]);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_g_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_q_media, const char_T *c21_identifier);
static real_T c21_h_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_info_helper(const mxArray **c21_info);
static const mxArray *c21_emlrt_marshallOut(const char * c21_u);
static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u);
static real_T c21_sum(SFc21_experiment_lib2InstanceStruct *chartInstance, real_T
                      c21_x[100]);
static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_i_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_j_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_experiment_lib2, const
  char_T *c21_identifier);
static uint8_T c21_k_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_experiment_lib2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_dataf_not_empty = false;
  chartInstance->c21_datav_not_empty = false;
  chartInstance->c21_dataq_not_empty = false;
  chartInstance->c21_is_active_c21_experiment_lib2 = 0U;
}

static void initialize_params_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c21_d0;
  sf_mex_import_named("num_generators", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c21_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c21_num_generators = c21_d0;
}

static void enable_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_debugger_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  real_T c21_hoistedGlobal;
  real_T c21_u;
  const mxArray *c21_b_y = NULL;
  real_T c21_b_hoistedGlobal;
  real_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  real_T c21_c_hoistedGlobal;
  real_T c21_c_u;
  const mxArray *c21_d_y = NULL;
  int32_T c21_i0;
  real_T c21_d_u[100];
  const mxArray *c21_e_y = NULL;
  int32_T c21_i1;
  real_T c21_e_u[100];
  const mxArray *c21_f_y = NULL;
  int32_T c21_i2;
  real_T c21_f_u[100];
  const mxArray *c21_g_y = NULL;
  uint8_T c21_d_hoistedGlobal;
  uint8_T c21_g_u;
  const mxArray *c21_h_y = NULL;
  real_T *c21_f_media;
  real_T *c21_q_media;
  real_T *c21_v_media;
  c21_q_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c21_v_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_f_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(7, 1), false);
  c21_hoistedGlobal = *c21_f_media;
  c21_u = c21_hoistedGlobal;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_hoistedGlobal = *c21_q_media;
  c21_b_u = c21_b_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  c21_c_hoistedGlobal = *c21_v_media;
  c21_c_u = c21_c_hoistedGlobal;
  c21_d_y = NULL;
  sf_mex_assign(&c21_d_y, sf_mex_create("y", &c21_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 2, c21_d_y);
  for (c21_i0 = 0; c21_i0 < 100; c21_i0++) {
    c21_d_u[c21_i0] = chartInstance->c21_dataf[c21_i0];
  }

  c21_e_y = NULL;
  if (!chartInstance->c21_dataf_not_empty) {
    sf_mex_assign(&c21_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_e_y, sf_mex_create("y", c21_d_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c21_y, 3, c21_e_y);
  for (c21_i1 = 0; c21_i1 < 100; c21_i1++) {
    c21_e_u[c21_i1] = chartInstance->c21_dataq[c21_i1];
  }

  c21_f_y = NULL;
  if (!chartInstance->c21_dataq_not_empty) {
    sf_mex_assign(&c21_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_f_y, sf_mex_create("y", c21_e_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c21_y, 4, c21_f_y);
  for (c21_i2 = 0; c21_i2 < 100; c21_i2++) {
    c21_f_u[c21_i2] = chartInstance->c21_datav[c21_i2];
  }

  c21_g_y = NULL;
  if (!chartInstance->c21_datav_not_empty) {
    sf_mex_assign(&c21_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_g_y, sf_mex_create("y", c21_f_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c21_y, 5, c21_g_y);
  c21_d_hoistedGlobal = chartInstance->c21_is_active_c21_experiment_lib2;
  c21_g_u = c21_d_hoistedGlobal;
  c21_h_y = NULL;
  sf_mex_assign(&c21_h_y, sf_mex_create("y", &c21_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 6, c21_h_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv0[100];
  int32_T c21_i3;
  real_T c21_dv1[100];
  int32_T c21_i4;
  real_T c21_dv2[100];
  int32_T c21_i5;
  real_T *c21_f_media;
  real_T *c21_q_media;
  real_T *c21_v_media;
  c21_q_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c21_v_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_f_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  *c21_f_media = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 0)), "f_media");
  *c21_q_media = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 1)), "q_media");
  *c21_v_media = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 2)), "v_media");
  c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 3)),
    "dataf", c21_dv0);
  for (c21_i3 = 0; c21_i3 < 100; c21_i3++) {
    chartInstance->c21_dataf[c21_i3] = c21_dv0[c21_i3];
  }

  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 4)),
                       "dataq", c21_dv1);
  for (c21_i4 = 0; c21_i4 < 100; c21_i4++) {
    chartInstance->c21_dataq[c21_i4] = c21_dv1[c21_i4];
  }

  c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 5)),
    "datav", c21_dv2);
  for (c21_i5 = 0; c21_i5 < 100; c21_i5++) {
    chartInstance->c21_datav[c21_i5] = c21_dv2[c21_i5];
  }

  chartInstance->c21_is_active_c21_experiment_lib2 = c21_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 6)),
     "is_active_c21_experiment_lib2");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_experiment_lib2(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c21_experiment_lib2(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  int32_T c21_i6;
  real_T *c21_f_media;
  real_T *c21_a;
  real_T *c21_f;
  real_T *c21_v;
  real_T *c21_v_media;
  real_T *c21_q;
  real_T *c21_q_media;
  real_T (*c21_msg)[5];
  c21_q_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c21_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c21_v_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c21_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c21_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c21_f_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c21_sfEvent);
  for (c21_i6 = 0; c21_i6 < 5; c21_i6++) {
    _SFD_DATA_RANGE_CHECK((*c21_msg)[c21_i6], 0U);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_experiment_lib2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_experiment_lib2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c21_f_media, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c21_num_generators, 2U);
  _SFD_DATA_RANGE_CHECK(*c21_a, 3U);
  _SFD_DATA_RANGE_CHECK(*c21_f, 4U);
  _SFD_DATA_RANGE_CHECK(*c21_v, 5U);
  _SFD_DATA_RANGE_CHECK(*c21_v_media, 6U);
  _SFD_DATA_RANGE_CHECK(*c21_q, 7U);
  _SFD_DATA_RANGE_CHECK(*c21_q_media, 8U);
}

static void c21_chartstep_c21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c21_hoistedGlobal;
  real_T c21_b_hoistedGlobal;
  real_T c21_c_hoistedGlobal;
  real_T c21_d_hoistedGlobal;
  real_T c21_e_hoistedGlobal;
  int32_T c21_i7;
  real_T c21_msg[5];
  real_T c21_b_num_generators;
  real_T c21_a;
  real_T c21_f;
  real_T c21_v;
  real_T c21_q;
  uint32_T c21_debug_family_var_map[14];
  real_T c21_nargin = 6.0;
  real_T c21_nargout = 3.0;
  real_T c21_f_media;
  real_T c21_v_media;
  real_T c21_q_media;
  int32_T c21_i8;
  int32_T c21_i9;
  int32_T c21_i10;
  int32_T c21_i11;
  real_T c21_f_hoistedGlobal[100];
  int32_T c21_i12;
  real_T c21_g_hoistedGlobal[100];
  int32_T c21_i13;
  boolean_T c21_x[100];
  real_T c21_y;
  int32_T c21_k;
  int32_T c21_b_k;
  int32_T c21_i14;
  real_T c21_h_hoistedGlobal[100];
  real_T c21_A;
  real_T c21_B;
  real_T c21_b_x;
  real_T c21_b_y;
  real_T c21_c_x;
  real_T c21_c_y;
  real_T c21_d_x;
  real_T c21_d_y;
  int32_T c21_i15;
  int32_T c21_i16;
  real_T c21_i_hoistedGlobal[100];
  real_T c21_b_A;
  real_T c21_b_B;
  real_T c21_e_x;
  real_T c21_e_y;
  real_T c21_f_x;
  real_T c21_f_y;
  real_T c21_g_x;
  real_T c21_g_y;
  int32_T c21_i17;
  int32_T c21_i18;
  real_T c21_j_hoistedGlobal[100];
  real_T c21_c_A;
  real_T c21_c_B;
  real_T c21_h_x;
  real_T c21_h_y;
  real_T c21_i_x;
  real_T c21_i_y;
  real_T c21_j_x;
  real_T c21_j_y;
  real_T *c21_b_q_media;
  real_T *c21_b_v_media;
  real_T *c21_b_f_media;
  real_T *c21_b_q;
  real_T *c21_b_v;
  real_T *c21_b_f;
  real_T *c21_b_a;
  real_T (*c21_b_msg)[5];
  c21_b_q_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c21_b_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c21_b_v_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_b_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c21_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c21_b_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c21_b_f_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_b_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c21_sfEvent);
  c21_hoistedGlobal = chartInstance->c21_num_generators;
  c21_b_hoistedGlobal = *c21_b_a;
  c21_c_hoistedGlobal = *c21_b_f;
  c21_d_hoistedGlobal = *c21_b_v;
  c21_e_hoistedGlobal = *c21_b_q;
  for (c21_i7 = 0; c21_i7 < 5; c21_i7++) {
    c21_msg[c21_i7] = (*c21_b_msg)[c21_i7];
  }

  c21_b_num_generators = c21_hoistedGlobal;
  c21_a = c21_b_hoistedGlobal;
  c21_f = c21_c_hoistedGlobal;
  c21_v = c21_d_hoistedGlobal;
  c21_q = c21_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_d_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_d_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_msg, 2U, c21_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b_num_generators, 3U,
    c21_d_sf_marshallOut, c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_a, 4U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_f, 5U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_v, 6U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_q, 7U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_f_media, 8U, c21_d_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_v_media, 9U, c21_d_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_q_media, 10U, c21_d_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c21_dataf, 11U,
    c21_c_sf_marshallOut, c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c21_datav, 12U,
    c21_b_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c21_dataq, 13U,
    c21_sf_marshallOut, c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c21_dataf_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 2);
    for (c21_i8 = 0; c21_i8 < 100; c21_i8++) {
      chartInstance->c21_dataf[c21_i8] = 0.0;
    }

    chartInstance->c21_dataf_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 3);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c21_datav_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 3);
    for (c21_i9 = 0; c21_i9 < 100; c21_i9++) {
      chartInstance->c21_datav[c21_i9] = 0.0;
    }

    chartInstance->c21_datav_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 4);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c21_dataq_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 4);
    for (c21_i10 = 0; c21_i10 < 100; c21_i10++) {
      chartInstance->c21_dataq[c21_i10] = 0.0;
    }

    chartInstance->c21_dataq_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 5);
  if (CV_EML_IF(0, 1, 3, c21_msg[0] > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 6);
    chartInstance->c21_dataf[_SFD_EML_ARRAY_BOUNDS_CHECK("dataf", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c21_msg[0]), 1, 100, 1, 0) - 1] = c21_msg[1];
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 7);
    chartInstance->c21_datav[_SFD_EML_ARRAY_BOUNDS_CHECK("datav", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c21_msg[0]), 1, 100, 1, 0) - 1] = c21_msg[2];
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 8);
    chartInstance->c21_dataq[_SFD_EML_ARRAY_BOUNDS_CHECK("dataq", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c21_msg[0]), 1, 100, 1, 0) - 1] = c21_msg[3];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 10);
  chartInstance->c21_dataf[_SFD_EML_ARRAY_BOUNDS_CHECK("dataf", (int32_T)
    _SFD_INTEGER_CHECK("a", c21_a), 1, 100, 1, 0) - 1] = c21_f;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 11);
  chartInstance->c21_datav[_SFD_EML_ARRAY_BOUNDS_CHECK("datav", (int32_T)
    _SFD_INTEGER_CHECK("a", c21_a), 1, 100, 1, 0) - 1] = c21_v;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 12);
  chartInstance->c21_dataq[_SFD_EML_ARRAY_BOUNDS_CHECK("dataq", (int32_T)
    _SFD_INTEGER_CHECK("a", c21_a), 1, 100, 1, 0) - 1] = c21_q;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 16);
  for (c21_i11 = 0; c21_i11 < 100; c21_i11++) {
    c21_f_hoistedGlobal[c21_i11] = chartInstance->c21_dataf[c21_i11];
  }

  for (c21_i12 = 0; c21_i12 < 100; c21_i12++) {
    c21_g_hoistedGlobal[c21_i12] = chartInstance->c21_dataf[c21_i12];
  }

  for (c21_i13 = 0; c21_i13 < 100; c21_i13++) {
    c21_x[c21_i13] = (c21_g_hoistedGlobal[c21_i13] > 0.0);
  }

  c21_y = (real_T)c21_x[0];
  for (c21_k = 2; c21_k < 101; c21_k++) {
    c21_b_k = c21_k;
    c21_y += (real_T)c21_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 100, 1, 0) - 1];
  }

  for (c21_i14 = 0; c21_i14 < 100; c21_i14++) {
    c21_h_hoistedGlobal[c21_i14] = c21_f_hoistedGlobal[c21_i14];
  }

  c21_A = c21_sum(chartInstance, c21_h_hoistedGlobal);
  c21_B = c21_y;
  c21_b_x = c21_A;
  c21_b_y = c21_B;
  c21_c_x = c21_b_x;
  c21_c_y = c21_b_y;
  c21_d_x = c21_c_x;
  c21_d_y = c21_c_y;
  c21_f_media = c21_d_x / c21_d_y;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 17);
  for (c21_i15 = 0; c21_i15 < 100; c21_i15++) {
    c21_f_hoistedGlobal[c21_i15] = chartInstance->c21_datav[c21_i15];
  }

  for (c21_i16 = 0; c21_i16 < 100; c21_i16++) {
    c21_i_hoistedGlobal[c21_i16] = c21_f_hoistedGlobal[c21_i16];
  }

  c21_b_A = c21_sum(chartInstance, c21_i_hoistedGlobal);
  c21_b_B = c21_b_num_generators;
  c21_e_x = c21_b_A;
  c21_e_y = c21_b_B;
  c21_f_x = c21_e_x;
  c21_f_y = c21_e_y;
  c21_g_x = c21_f_x;
  c21_g_y = c21_f_y;
  c21_v_media = c21_g_x / c21_g_y;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 18);
  for (c21_i17 = 0; c21_i17 < 100; c21_i17++) {
    c21_f_hoistedGlobal[c21_i17] = chartInstance->c21_dataq[c21_i17];
  }

  for (c21_i18 = 0; c21_i18 < 100; c21_i18++) {
    c21_j_hoistedGlobal[c21_i18] = c21_f_hoistedGlobal[c21_i18];
  }

  c21_c_A = c21_sum(chartInstance, c21_j_hoistedGlobal);
  c21_c_B = c21_b_num_generators;
  c21_h_x = c21_c_A;
  c21_h_y = c21_c_B;
  c21_i_x = c21_h_x;
  c21_i_y = c21_h_y;
  c21_j_x = c21_i_x;
  c21_j_y = c21_i_y;
  c21_q_media = c21_j_x / c21_j_y;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c21_b_f_media = c21_f_media;
  *c21_b_v_media = c21_v_media;
  *c21_b_q_media = c21_q_media;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_experiment_lib2
  (SFc21_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)c21_machineNumber;
  (void)c21_chartNumber;
  (void)c21_instanceNumber;
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i19;
  real_T c21_b_inData[100];
  int32_T c21_i20;
  real_T c21_u[100];
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i19 = 0; c21_i19 < 100; c21_i19++) {
    c21_b_inData[c21_i19] = (*(real_T (*)[100])c21_inData)[c21_i19];
  }

  for (c21_i20 = 0; c21_i20 < 100; c21_i20++) {
    c21_u[c21_i20] = c21_b_inData[c21_i20];
  }

  c21_y = NULL;
  if (!chartInstance->c21_dataq_not_empty) {
    sf_mex_assign(&c21_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_dataq, const char_T *c21_identifier,
  real_T c21_y[100])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dataq), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dataq);
}

static void c21_b_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100])
{
  real_T c21_dv3[100];
  int32_T c21_i21;
  if (mxIsEmpty(c21_u)) {
    chartInstance->c21_dataq_not_empty = false;
  } else {
    chartInstance->c21_dataq_not_empty = true;
    sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv3, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c21_i21 = 0; c21_i21 < 100; c21_i21++) {
      c21_y[c21_i21] = c21_dv3[c21_i21];
    }
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_dataq;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[100];
  int32_T c21_i22;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_b_dataq = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dataq), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dataq);
  for (c21_i22 = 0; c21_i22 < 100; c21_i22++) {
    (*(real_T (*)[100])c21_outData)[c21_i22] = c21_y[c21_i22];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i23;
  real_T c21_b_inData[100];
  int32_T c21_i24;
  real_T c21_u[100];
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i23 = 0; c21_i23 < 100; c21_i23++) {
    c21_b_inData[c21_i23] = (*(real_T (*)[100])c21_inData)[c21_i23];
  }

  for (c21_i24 = 0; c21_i24 < 100; c21_i24++) {
    c21_u[c21_i24] = c21_b_inData[c21_i24];
  }

  c21_y = NULL;
  if (!chartInstance->c21_datav_not_empty) {
    sf_mex_assign(&c21_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_c_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_datav, const char_T *c21_identifier,
  real_T c21_y[100])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_datav), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_datav);
}

static void c21_d_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100])
{
  real_T c21_dv4[100];
  int32_T c21_i25;
  if (mxIsEmpty(c21_u)) {
    chartInstance->c21_datav_not_empty = false;
  } else {
    chartInstance->c21_datav_not_empty = true;
    sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv4, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c21_i25 = 0; c21_i25 < 100; c21_i25++) {
      c21_y[c21_i25] = c21_dv4[c21_i25];
    }
  }

  sf_mex_destroy(&c21_u);
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_datav;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[100];
  int32_T c21_i26;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_b_datav = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_datav), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_datav);
  for (c21_i26 = 0; c21_i26 < 100; c21_i26++) {
    (*(real_T (*)[100])c21_outData)[c21_i26] = c21_y[c21_i26];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i27;
  real_T c21_b_inData[100];
  int32_T c21_i28;
  real_T c21_u[100];
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i27 = 0; c21_i27 < 100; c21_i27++) {
    c21_b_inData[c21_i27] = (*(real_T (*)[100])c21_inData)[c21_i27];
  }

  for (c21_i28 = 0; c21_i28 < 100; c21_i28++) {
    c21_u[c21_i28] = c21_b_inData[c21_i28];
  }

  c21_y = NULL;
  if (!chartInstance->c21_dataf_not_empty) {
    sf_mex_assign(&c21_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_e_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_dataf, const char_T *c21_identifier,
  real_T c21_y[100])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dataf), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dataf);
}

static void c21_f_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[100])
{
  real_T c21_dv5[100];
  int32_T c21_i29;
  if (mxIsEmpty(c21_u)) {
    chartInstance->c21_dataf_not_empty = false;
  } else {
    chartInstance->c21_dataf_not_empty = true;
    sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv5, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c21_i29 = 0; c21_i29 < 100; c21_i29++) {
      c21_y[c21_i29] = c21_dv5[c21_i29];
    }
  }

  sf_mex_destroy(&c21_u);
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_dataf;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[100];
  int32_T c21_i30;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_b_dataf = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dataf), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dataf);
  for (c21_i30 = 0; c21_i30 < 100; c21_i30++) {
    (*(real_T (*)[100])c21_outData)[c21_i30] = c21_y[c21_i30];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_g_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_q_media, const char_T *c21_identifier)
{
  real_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_q_media),
    &c21_thisId);
  sf_mex_destroy(&c21_q_media);
  return c21_y;
}

static real_T c21_h_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d1;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d1, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d1;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_q_media;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_q_media = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_q_media),
    &c21_thisId);
  sf_mex_destroy(&c21_q_media);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i31;
  real_T c21_b_inData[5];
  int32_T c21_i32;
  real_T c21_u[5];
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i31 = 0; c21_i31 < 5; c21_i31++) {
    c21_b_inData[c21_i31] = (*(real_T (*)[5])c21_inData)[c21_i31];
  }

  for (c21_i32 = 0; c21_i32 < 5; c21_i32++) {
    c21_u[c21_i32] = c21_b_inData[c21_i32];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

const mxArray *sf_c21_experiment_lib2_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_createstruct("structure", 2, 23, 1),
                false);
  c21_info_helper(&c21_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(const mxArray **c21_info)
{
  const mxArray *c21_rhs0 = NULL;
  const mxArray *c21_lhs0 = NULL;
  const mxArray *c21_rhs1 = NULL;
  const mxArray *c21_lhs1 = NULL;
  const mxArray *c21_rhs2 = NULL;
  const mxArray *c21_lhs2 = NULL;
  const mxArray *c21_rhs3 = NULL;
  const mxArray *c21_lhs3 = NULL;
  const mxArray *c21_rhs4 = NULL;
  const mxArray *c21_lhs4 = NULL;
  const mxArray *c21_rhs5 = NULL;
  const mxArray *c21_lhs5 = NULL;
  const mxArray *c21_rhs6 = NULL;
  const mxArray *c21_lhs6 = NULL;
  const mxArray *c21_rhs7 = NULL;
  const mxArray *c21_lhs7 = NULL;
  const mxArray *c21_rhs8 = NULL;
  const mxArray *c21_lhs8 = NULL;
  const mxArray *c21_rhs9 = NULL;
  const mxArray *c21_lhs9 = NULL;
  const mxArray *c21_rhs10 = NULL;
  const mxArray *c21_lhs10 = NULL;
  const mxArray *c21_rhs11 = NULL;
  const mxArray *c21_lhs11 = NULL;
  const mxArray *c21_rhs12 = NULL;
  const mxArray *c21_lhs12 = NULL;
  const mxArray *c21_rhs13 = NULL;
  const mxArray *c21_lhs13 = NULL;
  const mxArray *c21_rhs14 = NULL;
  const mxArray *c21_lhs14 = NULL;
  const mxArray *c21_rhs15 = NULL;
  const mxArray *c21_lhs15 = NULL;
  const mxArray *c21_rhs16 = NULL;
  const mxArray *c21_lhs16 = NULL;
  const mxArray *c21_rhs17 = NULL;
  const mxArray *c21_lhs17 = NULL;
  const mxArray *c21_rhs18 = NULL;
  const mxArray *c21_lhs18 = NULL;
  const mxArray *c21_rhs19 = NULL;
  const mxArray *c21_lhs19 = NULL;
  const mxArray *c21_rhs20 = NULL;
  const mxArray *c21_lhs20 = NULL;
  const mxArray *c21_rhs21 = NULL;
  const mxArray *c21_lhs21 = NULL;
  const mxArray *c21_rhs22 = NULL;
  const mxArray *c21_lhs22 = NULL;
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("sum"), "name", "name", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c21_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c21_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("isequal"), "name", "name", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c21_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c21_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c21_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c21_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c21_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c21_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c21_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c21_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("intmax"), "name", "name", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c21_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c21_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("sum"), "name", "name", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c21_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c21_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c21_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c21_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("mrdivide"), "name", "name",
                  16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c21_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c21_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("rdivide"), "name", "name",
                  18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c21_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c21_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c21_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_div"), "name", "name",
                  21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c21_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c21_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs22), "lhs", "lhs",
                  22);
  sf_mex_destroy(&c21_rhs0);
  sf_mex_destroy(&c21_lhs0);
  sf_mex_destroy(&c21_rhs1);
  sf_mex_destroy(&c21_lhs1);
  sf_mex_destroy(&c21_rhs2);
  sf_mex_destroy(&c21_lhs2);
  sf_mex_destroy(&c21_rhs3);
  sf_mex_destroy(&c21_lhs3);
  sf_mex_destroy(&c21_rhs4);
  sf_mex_destroy(&c21_lhs4);
  sf_mex_destroy(&c21_rhs5);
  sf_mex_destroy(&c21_lhs5);
  sf_mex_destroy(&c21_rhs6);
  sf_mex_destroy(&c21_lhs6);
  sf_mex_destroy(&c21_rhs7);
  sf_mex_destroy(&c21_lhs7);
  sf_mex_destroy(&c21_rhs8);
  sf_mex_destroy(&c21_lhs8);
  sf_mex_destroy(&c21_rhs9);
  sf_mex_destroy(&c21_lhs9);
  sf_mex_destroy(&c21_rhs10);
  sf_mex_destroy(&c21_lhs10);
  sf_mex_destroy(&c21_rhs11);
  sf_mex_destroy(&c21_lhs11);
  sf_mex_destroy(&c21_rhs12);
  sf_mex_destroy(&c21_lhs12);
  sf_mex_destroy(&c21_rhs13);
  sf_mex_destroy(&c21_lhs13);
  sf_mex_destroy(&c21_rhs14);
  sf_mex_destroy(&c21_lhs14);
  sf_mex_destroy(&c21_rhs15);
  sf_mex_destroy(&c21_lhs15);
  sf_mex_destroy(&c21_rhs16);
  sf_mex_destroy(&c21_lhs16);
  sf_mex_destroy(&c21_rhs17);
  sf_mex_destroy(&c21_lhs17);
  sf_mex_destroy(&c21_rhs18);
  sf_mex_destroy(&c21_lhs18);
  sf_mex_destroy(&c21_rhs19);
  sf_mex_destroy(&c21_lhs19);
  sf_mex_destroy(&c21_rhs20);
  sf_mex_destroy(&c21_lhs20);
  sf_mex_destroy(&c21_rhs21);
  sf_mex_destroy(&c21_lhs21);
  sf_mex_destroy(&c21_rhs22);
  sf_mex_destroy(&c21_lhs22);
}

static const mxArray *c21_emlrt_marshallOut(const char * c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c21_u)), false);
  return c21_y;
}

static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 7, 0U, 0U, 0U, 0), false);
  return c21_y;
}

static real_T c21_sum(SFc21_experiment_lib2InstanceStruct *chartInstance, real_T
                      c21_x[100])
{
  real_T c21_y;
  int32_T c21_k;
  int32_T c21_b_k;
  (void)chartInstance;
  c21_y = c21_x[0];
  for (c21_k = 2; c21_k < 101; c21_k++) {
    c21_b_k = c21_k;
    c21_y += c21_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c21_b_k), 1, 100, 1, 0) - 1];
  }

  return c21_y;
}

static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_i_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i33;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i33, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i33;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_j_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_experiment_lib2, const
  char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_experiment_lib2), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_experiment_lib2);
  return c21_y;
}

static uint8_T c21_k_emlrt_marshallIn(SFc21_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void init_dsm_address_info(SFc21_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c21_experiment_lib2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(233670166U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2934310717U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(239102530U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1919260082U);
}

mxArray *sf_c21_experiment_lib2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AfZFlQnLLV7pYhWjFlY99G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_experiment_lib2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_experiment_lib2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c21_experiment_lib2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"f_media\",},{M[1],M[57],T\"q_media\",},{M[1],M[55],T\"v_media\",},{M[4],M[0],T\"dataf\",S'l','i','p'{{M1x2[82 87],M[0],}}},{M[4],M[0],T\"dataq\",S'l','i','p'{{M1x2[208 213],M[0],}}},{M[4],M[0],T\"datav\",S'l','i','p'{{M1x2[145 150],M[0],}}},{M[8],M[0],T\"is_active_c21_experiment_lib2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_experiment_lib2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_experiment_lib2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc21_experiment_lib2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _experiment_lib2MachineNumber_,
           21,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_experiment_lib2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_experiment_lib2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _experiment_lib2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"msg");
          _SFD_SET_DATA_PROPS(1,2,0,1,"f_media");
          _SFD_SET_DATA_PROPS(2,10,0,0,"num_generators");
          _SFD_SET_DATA_PROPS(3,1,1,0,"a");
          _SFD_SET_DATA_PROPS(4,1,1,0,"f");
          _SFD_SET_DATA_PROPS(5,1,1,0,"v");
          _SFD_SET_DATA_PROPS(6,2,0,1,"v_media");
          _SFD_SET_DATA_PROPS(7,1,1,0,"q");
          _SFD_SET_DATA_PROPS(8,2,0,1,"q_media");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,499);
        _SFD_CV_INIT_EML_IF(0,1,0,89,106,-1,131);
        _SFD_CV_INIT_EML_IF(0,1,1,152,169,-1,194);
        _SFD_CV_INIT_EML_IF(0,1,2,215,232,-1,257);
        _SFD_CV_INIT_EML_IF(0,1,3,260,273,-1,355);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)
          c21_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)
          c21_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)
          c21_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)
          c21_d_sf_marshallIn);

        {
          real_T *c21_f_media;
          real_T *c21_a;
          real_T *c21_f;
          real_T *c21_v;
          real_T *c21_v_media;
          real_T *c21_q;
          real_T *c21_q_media;
          real_T (*c21_msg)[5];
          c21_q_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c21_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c21_v_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c21_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c21_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c21_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c21_f_media = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c21_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c21_msg);
          _SFD_SET_DATA_VALUE_PTR(1U, c21_f_media);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c21_num_generators);
          _SFD_SET_DATA_VALUE_PTR(3U, c21_a);
          _SFD_SET_DATA_VALUE_PTR(4U, c21_f);
          _SFD_SET_DATA_VALUE_PTR(5U, c21_v);
          _SFD_SET_DATA_VALUE_PTR(6U, c21_v_media);
          _SFD_SET_DATA_VALUE_PTR(7U, c21_q);
          _SFD_SET_DATA_VALUE_PTR(8U, c21_q_media);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _experiment_lib2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "D7O5lrk2FDY0aVkLZZKoiB";
}

static void sf_opaque_initialize_c21_experiment_lib2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
  initialize_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_experiment_lib2(void *chartInstanceVar)
{
  enable_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_experiment_lib2(void *chartInstanceVar)
{
  disable_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_experiment_lib2(void *chartInstanceVar)
{
  sf_gateway_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c21_experiment_lib2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_experiment_lib2
    ((SFc21_experiment_lib2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c21_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c21_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c21_experiment_lib2(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_experiment_lib2(S);
}

static void sf_opaque_set_sim_state_c21_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c21_experiment_lib2(S, st);
}

static void sf_opaque_terminate_c21_experiment_lib2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_experiment_lib2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_experiment_lib2_optimization_info();
    }

    finalize_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_experiment_lib2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c21_experiment_lib2((SFc21_experiment_lib2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_experiment_lib2(SimStruct *S)
{
  /* Actual parameters from chart:
     num_generators
   */
  const char_T *rtParamNames[] = { "num_generators" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for num_generators*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_experiment_lib2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3768437946U));
  ssSetChecksum1(S,(173925827U));
  ssSetChecksum2(S,(1298500195U));
  ssSetChecksum3(S,(2180116795U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_experiment_lib2(SimStruct *S)
{
  SFc21_experiment_lib2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc21_experiment_lib2InstanceStruct *)utMalloc(sizeof
    (SFc21_experiment_lib2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_experiment_lib2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_experiment_lib2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_experiment_lib2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_experiment_lib2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_experiment_lib2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_experiment_lib2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_experiment_lib2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_experiment_lib2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_experiment_lib2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_experiment_lib2;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_experiment_lib2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_experiment_lib2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c21_experiment_lib2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_experiment_lib2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_experiment_lib2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_experiment_lib2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_experiment_lib2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
