/* Include files */

#include <stddef.h>
#include "blas.h"
#include "experiment_lib2_sfun.h"
#include "c23_experiment_lib2.h"
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
static const char * c23_debug_family_names[27] = { "f_media", "v_media",
  "q_media", "uc", "e", "wpunt", "nargin", "nargout", "msg", "num_generators",
  "a", "f", "v", "q", "u", "en", "ts", "dr", "delta", "dataf", "datav", "dataq",
  "datau", "t", "tc", "drift", "integral" };

/* Function Declarations */
static void initialize_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance);
static void initialize_params_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance);
static void enable_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance);
static void disable_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance);
static void set_sim_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance, const mxArray *c23_st);
static void finalize_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance);
static void sf_gateway_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance);
static void c23_chartstep_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance);
static void initSimStructsc23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_integral, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_c_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_drift, const char_T *c23_identifier);
static real_T c23_d_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_e_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_tc, const char_T *c23_identifier);
static real_T c23_f_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_g_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_t, const char_T *c23_identifier);
static real_T c23_h_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_i_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_datau, const char_T *c23_identifier,
  real_T c23_y[100]);
static void c23_j_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100]);
static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_k_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_dataq, const char_T *c23_identifier,
  real_T c23_y[100]);
static void c23_l_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100]);
static void c23_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_g_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_m_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_datav, const char_T *c23_identifier,
  real_T c23_y[100]);
static void c23_n_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100]);
static void c23_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_h_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_o_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_dataf, const char_T *c23_identifier,
  real_T c23_y[100]);
static void c23_p_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100]);
static void c23_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_i_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_q_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_delta, const char_T *c23_identifier, real_T
  c23_y[2]);
static void c23_r_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[2]);
static void c23_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_j_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_s_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[4]);
static void c23_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_k_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_t_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_l_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_info_helper(const mxArray **c23_info);
static const mxArray *c23_emlrt_marshallOut(const char * c23_u);
static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u);
static real_T c23_sum(SFc23_experiment_lib2InstanceStruct *chartInstance, real_T
                      c23_x[100]);
static real_T c23_b_sum(SFc23_experiment_lib2InstanceStruct *chartInstance,
  real_T c23_x[4]);
static const mxArray *c23_m_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_u_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_v_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_experiment_lib2, const
  char_T *c23_identifier);
static uint8_T c23_w_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_experiment_lib2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_dataf_not_empty = false;
  chartInstance->c23_datav_not_empty = false;
  chartInstance->c23_dataq_not_empty = false;
  chartInstance->c23_datau_not_empty = false;
  chartInstance->c23_t_not_empty = false;
  chartInstance->c23_tc_not_empty = false;
  chartInstance->c23_drift_not_empty = false;
  chartInstance->c23_integral_not_empty = false;
  chartInstance->c23_is_active_c23_experiment_lib2 = 0U;
}

static void initialize_params_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c23_d0;
  real_T c23_d1;
  real_T c23_dv0[4];
  int32_T c23_i0;
  sf_mex_import_named("num_generators", sf_mex_get_sfun_param(chartInstance->S,
    1, 0), &c23_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c23_num_generators = c23_d0;
  sf_mex_import_named("ts", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c23_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c23_ts = c23_d1;
  sf_mex_import_named("dr", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c23_dv0, 0, 0, 0U, 1, 0U, 2, 1, 4);
  for (c23_i0 = 0; c23_i0 < 4; c23_i0++) {
    chartInstance->c23_dr[c23_i0] = c23_dv0[c23_i0];
  }
}

static void enable_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_i1;
  real_T c23_u[2];
  const mxArray *c23_b_y = NULL;
  int32_T c23_i2;
  real_T c23_b_u[100];
  const mxArray *c23_c_y = NULL;
  int32_T c23_i3;
  real_T c23_c_u[100];
  const mxArray *c23_d_y = NULL;
  int32_T c23_i4;
  real_T c23_d_u[100];
  const mxArray *c23_e_y = NULL;
  int32_T c23_i5;
  real_T c23_e_u[100];
  const mxArray *c23_f_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_f_u;
  const mxArray *c23_g_y = NULL;
  real_T c23_b_hoistedGlobal;
  real_T c23_g_u;
  const mxArray *c23_h_y = NULL;
  real_T c23_c_hoistedGlobal;
  real_T c23_h_u;
  const mxArray *c23_i_y = NULL;
  real_T c23_d_hoistedGlobal;
  real_T c23_i_u;
  const mxArray *c23_j_y = NULL;
  uint8_T c23_e_hoistedGlobal;
  uint8_T c23_j_u;
  const mxArray *c23_k_y = NULL;
  real_T (*c23_delta)[2];
  c23_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(10, 1), false);
  for (c23_i1 = 0; c23_i1 < 2; c23_i1++) {
    c23_u[c23_i1] = (*c23_delta)[c23_i1];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  for (c23_i2 = 0; c23_i2 < 100; c23_i2++) {
    c23_b_u[c23_i2] = chartInstance->c23_dataf[c23_i2];
  }

  c23_c_y = NULL;
  if (!chartInstance->c23_dataf_not_empty) {
    sf_mex_assign(&c23_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_c_y, sf_mex_create("y", c23_b_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c23_y, 1, c23_c_y);
  for (c23_i3 = 0; c23_i3 < 100; c23_i3++) {
    c23_c_u[c23_i3] = chartInstance->c23_dataq[c23_i3];
  }

  c23_d_y = NULL;
  if (!chartInstance->c23_dataq_not_empty) {
    sf_mex_assign(&c23_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_d_y, sf_mex_create("y", c23_c_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c23_y, 2, c23_d_y);
  for (c23_i4 = 0; c23_i4 < 100; c23_i4++) {
    c23_d_u[c23_i4] = chartInstance->c23_datau[c23_i4];
  }

  c23_e_y = NULL;
  if (!chartInstance->c23_datau_not_empty) {
    sf_mex_assign(&c23_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_e_y, sf_mex_create("y", c23_d_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c23_y, 3, c23_e_y);
  for (c23_i5 = 0; c23_i5 < 100; c23_i5++) {
    c23_e_u[c23_i5] = chartInstance->c23_datav[c23_i5];
  }

  c23_f_y = NULL;
  if (!chartInstance->c23_datav_not_empty) {
    sf_mex_assign(&c23_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_f_y, sf_mex_create("y", c23_e_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_setcell(c23_y, 4, c23_f_y);
  c23_hoistedGlobal = chartInstance->c23_drift;
  c23_f_u = c23_hoistedGlobal;
  c23_g_y = NULL;
  if (!chartInstance->c23_drift_not_empty) {
    sf_mex_assign(&c23_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_f_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c23_y, 5, c23_g_y);
  c23_b_hoistedGlobal = chartInstance->c23_integral;
  c23_g_u = c23_b_hoistedGlobal;
  c23_h_y = NULL;
  if (!chartInstance->c23_integral_not_empty) {
    sf_mex_assign(&c23_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_h_y, sf_mex_create("y", &c23_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c23_y, 6, c23_h_y);
  c23_c_hoistedGlobal = chartInstance->c23_t;
  c23_h_u = c23_c_hoistedGlobal;
  c23_i_y = NULL;
  if (!chartInstance->c23_t_not_empty) {
    sf_mex_assign(&c23_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_i_y, sf_mex_create("y", &c23_h_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c23_y, 7, c23_i_y);
  c23_d_hoistedGlobal = chartInstance->c23_tc;
  c23_i_u = c23_d_hoistedGlobal;
  c23_j_y = NULL;
  if (!chartInstance->c23_tc_not_empty) {
    sf_mex_assign(&c23_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_j_y, sf_mex_create("y", &c23_i_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c23_y, 8, c23_j_y);
  c23_e_hoistedGlobal = chartInstance->c23_is_active_c23_experiment_lib2;
  c23_j_u = c23_e_hoistedGlobal;
  c23_k_y = NULL;
  sf_mex_assign(&c23_k_y, sf_mex_create("y", &c23_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 9, c23_k_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T c23_dv1[2];
  int32_T c23_i6;
  real_T c23_dv2[100];
  int32_T c23_i7;
  real_T c23_dv3[100];
  int32_T c23_i8;
  real_T c23_dv4[100];
  int32_T c23_i9;
  real_T c23_dv5[100];
  int32_T c23_i10;
  real_T (*c23_delta)[2];
  c23_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)),
    "delta", c23_dv1);
  for (c23_i6 = 0; c23_i6 < 2; c23_i6++) {
    (*c23_delta)[c23_i6] = c23_dv1[c23_i6];
  }

  c23_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
    "dataf", c23_dv2);
  for (c23_i7 = 0; c23_i7 < 100; c23_i7++) {
    chartInstance->c23_dataf[c23_i7] = c23_dv2[c23_i7];
  }

  c23_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 2)),
    "dataq", c23_dv3);
  for (c23_i8 = 0; c23_i8 < 100; c23_i8++) {
    chartInstance->c23_dataq[c23_i8] = c23_dv3[c23_i8];
  }

  c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 3)),
    "datau", c23_dv4);
  for (c23_i9 = 0; c23_i9 < 100; c23_i9++) {
    chartInstance->c23_datau[c23_i9] = c23_dv4[c23_i9];
  }

  c23_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 4)),
    "datav", c23_dv5);
  for (c23_i10 = 0; c23_i10 < 100; c23_i10++) {
    chartInstance->c23_datav[c23_i10] = c23_dv5[c23_i10];
  }

  chartInstance->c23_drift = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 5)), "drift");
  chartInstance->c23_integral = c23_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 6)), "integral");
  chartInstance->c23_t = c23_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 7)), "t");
  chartInstance->c23_tc = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 8)), "tc");
  chartInstance->c23_is_active_c23_experiment_lib2 = c23_v_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 9)),
     "is_active_c23_experiment_lib2");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_experiment_lib2(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_experiment_lib2(SFc23_experiment_lib2InstanceStruct
  *chartInstance)
{
  int32_T c23_i11;
  int32_T c23_i12;
  int32_T c23_i13;
  int32_T c23_i14;
  real_T *c23_a;
  real_T *c23_f;
  real_T *c23_v;
  real_T *c23_q;
  real_T *c23_en;
  real_T (*c23_u)[2];
  real_T (*c23_delta)[2];
  real_T (*c23_msg)[5];
  c23_en = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c23_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 5);
  c23_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c23_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c23_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c23_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c23_sfEvent);
  for (c23_i11 = 0; c23_i11 < 5; c23_i11++) {
    _SFD_DATA_RANGE_CHECK((*c23_msg)[c23_i11], 0U);
  }

  chartInstance->c23_sfEvent = CALL_EVENT;
  c23_chartstep_c23_experiment_lib2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_experiment_lib2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c23_i12 = 0; c23_i12 < 2; c23_i12++) {
    _SFD_DATA_RANGE_CHECK((*c23_delta)[c23_i12], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c23_num_generators, 2U);
  _SFD_DATA_RANGE_CHECK(*c23_a, 3U);
  _SFD_DATA_RANGE_CHECK(*c23_f, 4U);
  _SFD_DATA_RANGE_CHECK(*c23_v, 5U);
  _SFD_DATA_RANGE_CHECK(*c23_q, 6U);
  for (c23_i13 = 0; c23_i13 < 2; c23_i13++) {
    _SFD_DATA_RANGE_CHECK((*c23_u)[c23_i13], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c23_en, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c23_ts, 9U);
  for (c23_i14 = 0; c23_i14 < 4; c23_i14++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c23_dr[c23_i14], 10U);
  }
}

static void c23_chartstep_c23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  real_T c23_c_hoistedGlobal;
  real_T c23_d_hoistedGlobal;
  real_T c23_e_hoistedGlobal;
  real_T c23_f_hoistedGlobal;
  real_T c23_g_hoistedGlobal;
  int32_T c23_i15;
  real_T c23_msg[5];
  real_T c23_b_num_generators;
  real_T c23_a;
  real_T c23_f;
  real_T c23_v;
  real_T c23_q;
  int32_T c23_i16;
  real_T c23_u[2];
  real_T c23_en;
  real_T c23_b_ts;
  int32_T c23_i17;
  real_T c23_b_dr[4];
  uint32_T c23_debug_family_var_map[27];
  real_T c23_f_media;
  real_T c23_v_media;
  real_T c23_q_media;
  real_T c23_uc;
  real_T c23_e;
  real_T c23_wpunt;
  real_T c23_nargin = 10.0;
  real_T c23_nargout = 1.0;
  real_T c23_delta[2];
  int32_T c23_i18;
  int32_T c23_i19;
  int32_T c23_i20;
  int32_T c23_i21;
  int32_T c23_i22;
  real_T c23_h_hoistedGlobal[100];
  int32_T c23_i23;
  real_T c23_i_hoistedGlobal[100];
  int32_T c23_i24;
  boolean_T c23_x[100];
  real_T c23_y;
  int32_T c23_k;
  int32_T c23_b_k;
  int32_T c23_i25;
  real_T c23_j_hoistedGlobal[100];
  real_T c23_A;
  real_T c23_B;
  real_T c23_b_x;
  real_T c23_b_y;
  real_T c23_c_x;
  real_T c23_c_y;
  real_T c23_d_x;
  real_T c23_d_y;
  int32_T c23_i26;
  int32_T c23_i27;
  real_T c23_k_hoistedGlobal[100];
  real_T c23_b_A;
  real_T c23_b_B;
  real_T c23_e_x;
  real_T c23_e_y;
  real_T c23_f_x;
  real_T c23_f_y;
  real_T c23_g_x;
  real_T c23_g_y;
  int32_T c23_i28;
  int32_T c23_i29;
  real_T c23_l_hoistedGlobal[100];
  real_T c23_c_A;
  real_T c23_c_B;
  real_T c23_h_x;
  real_T c23_h_y;
  real_T c23_i_x;
  real_T c23_i_y;
  real_T c23_j_x;
  real_T c23_j_y;
  real_T c23_b_u;
  int32_T c23_i30;
  real_T c23_dv6[4];
  int32_T c23_i31;
  real_T c23_b_f[4];
  int32_T c23_i32;
  real_T *c23_b_en;
  real_T *c23_b_q;
  real_T *c23_b_v;
  real_T *c23_c_f;
  real_T *c23_b_a;
  real_T (*c23_b_delta)[2];
  real_T (*c23_c_u)[2];
  real_T (*c23_b_msg)[5];
  c23_b_en = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c23_c_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 5);
  c23_b_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c23_b_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c23_c_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c23_b_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c23_sfEvent);
  c23_hoistedGlobal = chartInstance->c23_num_generators;
  c23_b_hoistedGlobal = *c23_b_a;
  c23_c_hoistedGlobal = *c23_c_f;
  c23_d_hoistedGlobal = *c23_b_v;
  c23_e_hoistedGlobal = *c23_b_q;
  c23_f_hoistedGlobal = *c23_b_en;
  c23_g_hoistedGlobal = chartInstance->c23_ts;
  for (c23_i15 = 0; c23_i15 < 5; c23_i15++) {
    c23_msg[c23_i15] = (*c23_b_msg)[c23_i15];
  }

  c23_b_num_generators = c23_hoistedGlobal;
  c23_a = c23_b_hoistedGlobal;
  c23_f = c23_c_hoistedGlobal;
  c23_v = c23_d_hoistedGlobal;
  c23_q = c23_e_hoistedGlobal;
  for (c23_i16 = 0; c23_i16 < 2; c23_i16++) {
    c23_u[c23_i16] = (*c23_c_u)[c23_i16];
  }

  c23_en = c23_f_hoistedGlobal;
  c23_b_ts = c23_g_hoistedGlobal;
  for (c23_i17 = 0; c23_i17 < 4; c23_i17++) {
    c23_b_dr[c23_i17] = chartInstance->c23_dr[c23_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_media, 0U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_v_media, 1U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_q_media, 2U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_uc, 3U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e, 4U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_wpunt, 5U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 6U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 7U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_msg, 8U, c23_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_num_generators, 9U,
    c23_k_sf_marshallOut, c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_a, 10U, c23_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_f, 11U, c23_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_v, 12U, c23_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_q, 13U, c23_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c23_u, 14U, c23_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_en, 15U, c23_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_ts, 16U, c23_k_sf_marshallOut,
    c23_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_b_dr, 17U, c23_j_sf_marshallOut,
    c23_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c23_delta, 18U, c23_i_sf_marshallOut,
    c23_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c23_dataf, 19U,
    c23_h_sf_marshallOut, c23_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c23_datav, 20U,
    c23_g_sf_marshallOut, c23_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c23_dataq, 21U,
    c23_f_sf_marshallOut, c23_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c23_datau, 22U,
    c23_e_sf_marshallOut, c23_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c23_t, 23U,
    c23_d_sf_marshallOut, c23_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c23_tc, 24U,
    c23_c_sf_marshallOut, c23_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c23_drift, 25U,
    c23_b_sf_marshallOut, c23_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c23_integral, 26U,
    c23_sf_marshallOut, c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c23_dataf_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 2);
    for (c23_i18 = 0; c23_i18 < 100; c23_i18++) {
      chartInstance->c23_dataf[c23_i18] = 0.0;
    }

    chartInstance->c23_dataf_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c23_datav_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
    for (c23_i19 = 0; c23_i19 < 100; c23_i19++) {
      chartInstance->c23_datav[c23_i19] = 0.0;
    }

    chartInstance->c23_datav_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c23_dataq_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
    for (c23_i20 = 0; c23_i20 < 100; c23_i20++) {
      chartInstance->c23_dataq[c23_i20] = 0.0;
    }

    chartInstance->c23_dataq_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c23_datau_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
    for (c23_i21 = 0; c23_i21 < 100; c23_i21++) {
      chartInstance->c23_datau[c23_i21] = 0.0;
    }

    chartInstance->c23_datau_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c23_t_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
    chartInstance->c23_t = 0.0;
    chartInstance->c23_t_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c23_tc_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
    chartInstance->c23_tc = 0.0;
    chartInstance->c23_tc_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c23_drift_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
    chartInstance->c23_drift = c23_b_dr[_SFD_EML_ARRAY_BOUNDS_CHECK("dr",
      (int32_T)_SFD_INTEGER_CHECK("a", c23_a), 1, 4, 1, 0) - 1];
    chartInstance->c23_drift_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 10);
  if (CV_EML_IF(0, 1, 7, !chartInstance->c23_integral_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 10);
    chartInstance->c23_integral = 7.9577471545947667;
    chartInstance->c23_integral_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 12);
  if (CV_EML_IF(0, 1, 8, c23_msg[0] > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 13);
    chartInstance->c23_dataf[_SFD_EML_ARRAY_BOUNDS_CHECK("dataf", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c23_msg[0]), 1, 100, 1, 0) - 1] = c23_msg[1];
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 14);
    chartInstance->c23_datav[_SFD_EML_ARRAY_BOUNDS_CHECK("datav", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c23_msg[0]), 1, 100, 1, 0) - 1] = c23_msg[2];
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 15);
    chartInstance->c23_dataq[_SFD_EML_ARRAY_BOUNDS_CHECK("dataq", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c23_msg[0]), 1, 100, 1, 0) - 1] = c23_msg[3];
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 16);
    chartInstance->c23_datau[_SFD_EML_ARRAY_BOUNDS_CHECK("datau", (int32_T)
      _SFD_INTEGER_CHECK("msg(1)", c23_msg[0]), 1, 100, 1, 0) - 1] = c23_msg[4];
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 18);
  chartInstance->c23_dataf[_SFD_EML_ARRAY_BOUNDS_CHECK("dataf", (int32_T)
    _SFD_INTEGER_CHECK("a", c23_a), 1, 100, 1, 0) - 1] = c23_f;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 19);
  chartInstance->c23_datav[_SFD_EML_ARRAY_BOUNDS_CHECK("datav", (int32_T)
    _SFD_INTEGER_CHECK("a", c23_a), 1, 100, 1, 0) - 1] = c23_v;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 20);
  chartInstance->c23_dataq[_SFD_EML_ARRAY_BOUNDS_CHECK("dataq", (int32_T)
    _SFD_INTEGER_CHECK("a", c23_a), 1, 100, 1, 0) - 1] = c23_q;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 21);
  chartInstance->c23_datau[_SFD_EML_ARRAY_BOUNDS_CHECK("datau", (int32_T)
    _SFD_INTEGER_CHECK("a", c23_a), 1, 100, 1, 0) - 1] = c23_u[0];
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 23);
  for (c23_i22 = 0; c23_i22 < 100; c23_i22++) {
    c23_h_hoistedGlobal[c23_i22] = chartInstance->c23_dataf[c23_i22];
  }

  for (c23_i23 = 0; c23_i23 < 100; c23_i23++) {
    c23_i_hoistedGlobal[c23_i23] = chartInstance->c23_dataf[c23_i23];
  }

  for (c23_i24 = 0; c23_i24 < 100; c23_i24++) {
    c23_x[c23_i24] = (c23_i_hoistedGlobal[c23_i24] > 0.0);
  }

  c23_y = (real_T)c23_x[0];
  for (c23_k = 2; c23_k < 101; c23_k++) {
    c23_b_k = c23_k;
    c23_y += (real_T)c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c23_b_k), 1, 100, 1, 0) - 1];
  }

  for (c23_i25 = 0; c23_i25 < 100; c23_i25++) {
    c23_j_hoistedGlobal[c23_i25] = c23_h_hoistedGlobal[c23_i25];
  }

  c23_A = c23_sum(chartInstance, c23_j_hoistedGlobal);
  c23_B = c23_y;
  c23_b_x = c23_A;
  c23_b_y = c23_B;
  c23_c_x = c23_b_x;
  c23_c_y = c23_b_y;
  c23_d_x = c23_c_x;
  c23_d_y = c23_c_y;
  c23_f_media = c23_d_x / c23_d_y;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 24);
  for (c23_i26 = 0; c23_i26 < 100; c23_i26++) {
    c23_h_hoistedGlobal[c23_i26] = chartInstance->c23_datav[c23_i26];
  }

  for (c23_i27 = 0; c23_i27 < 100; c23_i27++) {
    c23_k_hoistedGlobal[c23_i27] = c23_h_hoistedGlobal[c23_i27];
  }

  c23_b_A = c23_sum(chartInstance, c23_k_hoistedGlobal);
  c23_b_B = c23_b_num_generators;
  c23_e_x = c23_b_A;
  c23_e_y = c23_b_B;
  c23_f_x = c23_e_x;
  c23_f_y = c23_e_y;
  c23_g_x = c23_f_x;
  c23_g_y = c23_f_y;
  c23_v_media = c23_g_x / c23_g_y;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 25);
  for (c23_i28 = 0; c23_i28 < 100; c23_i28++) {
    c23_h_hoistedGlobal[c23_i28] = chartInstance->c23_dataq[c23_i28];
  }

  for (c23_i29 = 0; c23_i29 < 100; c23_i29++) {
    c23_l_hoistedGlobal[c23_i29] = c23_h_hoistedGlobal[c23_i29];
  }

  c23_c_A = c23_sum(chartInstance, c23_l_hoistedGlobal);
  c23_c_B = c23_b_num_generators;
  c23_h_x = c23_c_A;
  c23_h_y = c23_c_B;
  c23_i_x = c23_h_x;
  c23_i_y = c23_h_y;
  c23_j_x = c23_i_x;
  c23_j_y = c23_i_y;
  c23_q_media = c23_j_x / c23_j_y;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 27);
  c23_b_u = c23_u[0];
  for (c23_i30 = 0; c23_i30 < 4; c23_i30++) {
    c23_dv6[c23_i30] = chartInstance->c23_datau[c23_i30] - c23_b_u;
  }

  c23_uc = 0.1 * c23_b_sum(chartInstance, c23_dv6);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 28);
  for (c23_i31 = 0; c23_i31 < 4; c23_i31++) {
    c23_b_f[c23_i31] = c23_f - chartInstance->c23_dataf[c23_i31];
  }

  c23_e = 0.01 * c23_b_sum(chartInstance, c23_b_f) + 2.0 * (50.0 - c23_f);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 29);
  c23_wpunt = c23_e + c23_uc;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 31);
  chartInstance->c23_tc = (chartInstance->c23_tc + c23_b_ts) +
    chartInstance->c23_drift;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 32);
  chartInstance->c23_t = (chartInstance->c23_t + c23_b_ts) +
    chartInstance->c23_drift;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 34);
  chartInstance->c23_integral += (c23_b_ts + chartInstance->c23_drift) *
    c23_wpunt;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 37);
  c23_delta[0] = chartInstance->c23_integral - c23_f;
  c23_delta[1] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
  for (c23_i32 = 0; c23_i32 < 2; c23_i32++) {
    (*c23_b_delta)[c23_i32] = c23_delta[c23_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c23_sfEvent);
}

static void initSimStructsc23_experiment_lib2
  (SFc23_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  if (!chartInstance->c23_integral_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_integral, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_integral),
    &c23_thisId);
  sf_mex_destroy(&c23_b_integral);
  return c23_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d2;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_integral_not_empty = false;
  } else {
    chartInstance->c23_integral_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d2, 1, 0, 0U, 0, 0U, 0);
    c23_y = c23_d2;
  }

  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_integral;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_integral = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_integral),
    &c23_thisId);
  sf_mex_destroy(&c23_b_integral);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  if (!chartInstance->c23_drift_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_c_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_drift, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_drift),
    &c23_thisId);
  sf_mex_destroy(&c23_b_drift);
  return c23_y;
}

static real_T c23_d_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d3;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_drift_not_empty = false;
  } else {
    chartInstance->c23_drift_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d3, 1, 0, 0U, 0, 0U, 0);
    c23_y = c23_d3;
  }

  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_drift;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_drift = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_drift),
    &c23_thisId);
  sf_mex_destroy(&c23_b_drift);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  if (!chartInstance->c23_tc_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_e_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_tc, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_tc),
    &c23_thisId);
  sf_mex_destroy(&c23_b_tc);
  return c23_y;
}

static real_T c23_f_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d4;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_tc_not_empty = false;
  } else {
    chartInstance->c23_tc_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d4, 1, 0, 0U, 0, 0U, 0);
    c23_y = c23_d4;
  }

  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_tc;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_tc = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_tc),
    &c23_thisId);
  sf_mex_destroy(&c23_b_tc);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  if (!chartInstance->c23_t_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_g_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_t, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_t), &c23_thisId);
  sf_mex_destroy(&c23_b_t);
  return c23_y;
}

static real_T c23_h_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d5;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_t_not_empty = false;
  } else {
    chartInstance->c23_t_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d5, 1, 0, 0U, 0, 0U, 0);
    c23_y = c23_d5;
  }

  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_t;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_t = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_t), &c23_thisId);
  sf_mex_destroy(&c23_b_t);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i33;
  real_T c23_b_inData[100];
  int32_T c23_i34;
  real_T c23_u[100];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i33 = 0; c23_i33 < 100; c23_i33++) {
    c23_b_inData[c23_i33] = (*(real_T (*)[100])c23_inData)[c23_i33];
  }

  for (c23_i34 = 0; c23_i34 < 100; c23_i34++) {
    c23_u[c23_i34] = c23_b_inData[c23_i34];
  }

  c23_y = NULL;
  if (!chartInstance->c23_datau_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_i_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_datau, const char_T *c23_identifier,
  real_T c23_y[100])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_datau), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_datau);
}

static void c23_j_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100])
{
  real_T c23_dv7[100];
  int32_T c23_i35;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_datau_not_empty = false;
  } else {
    chartInstance->c23_datau_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv7, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c23_i35 = 0; c23_i35 < 100; c23_i35++) {
      c23_y[c23_i35] = c23_dv7[c23_i35];
    }
  }

  sf_mex_destroy(&c23_u);
}

static void c23_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_datau;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[100];
  int32_T c23_i36;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_datau = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_datau), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_datau);
  for (c23_i36 = 0; c23_i36 < 100; c23_i36++) {
    (*(real_T (*)[100])c23_outData)[c23_i36] = c23_y[c23_i36];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_f_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i37;
  real_T c23_b_inData[100];
  int32_T c23_i38;
  real_T c23_u[100];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i37 = 0; c23_i37 < 100; c23_i37++) {
    c23_b_inData[c23_i37] = (*(real_T (*)[100])c23_inData)[c23_i37];
  }

  for (c23_i38 = 0; c23_i38 < 100; c23_i38++) {
    c23_u[c23_i38] = c23_b_inData[c23_i38];
  }

  c23_y = NULL;
  if (!chartInstance->c23_dataq_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_k_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_dataq, const char_T *c23_identifier,
  real_T c23_y[100])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dataq), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_dataq);
}

static void c23_l_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100])
{
  real_T c23_dv8[100];
  int32_T c23_i39;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_dataq_not_empty = false;
  } else {
    chartInstance->c23_dataq_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv8, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c23_i39 = 0; c23_i39 < 100; c23_i39++) {
      c23_y[c23_i39] = c23_dv8[c23_i39];
    }
  }

  sf_mex_destroy(&c23_u);
}

static void c23_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_dataq;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[100];
  int32_T c23_i40;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_dataq = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dataq), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_dataq);
  for (c23_i40 = 0; c23_i40 < 100; c23_i40++) {
    (*(real_T (*)[100])c23_outData)[c23_i40] = c23_y[c23_i40];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_g_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i41;
  real_T c23_b_inData[100];
  int32_T c23_i42;
  real_T c23_u[100];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i41 = 0; c23_i41 < 100; c23_i41++) {
    c23_b_inData[c23_i41] = (*(real_T (*)[100])c23_inData)[c23_i41];
  }

  for (c23_i42 = 0; c23_i42 < 100; c23_i42++) {
    c23_u[c23_i42] = c23_b_inData[c23_i42];
  }

  c23_y = NULL;
  if (!chartInstance->c23_datav_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_m_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_datav, const char_T *c23_identifier,
  real_T c23_y[100])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_datav), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_datav);
}

static void c23_n_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100])
{
  real_T c23_dv9[100];
  int32_T c23_i43;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_datav_not_empty = false;
  } else {
    chartInstance->c23_datav_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv9, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c23_i43 = 0; c23_i43 < 100; c23_i43++) {
      c23_y[c23_i43] = c23_dv9[c23_i43];
    }
  }

  sf_mex_destroy(&c23_u);
}

static void c23_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_datav;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[100];
  int32_T c23_i44;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_datav = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_datav), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_datav);
  for (c23_i44 = 0; c23_i44 < 100; c23_i44++) {
    (*(real_T (*)[100])c23_outData)[c23_i44] = c23_y[c23_i44];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_h_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i45;
  real_T c23_b_inData[100];
  int32_T c23_i46;
  real_T c23_u[100];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i45 = 0; c23_i45 < 100; c23_i45++) {
    c23_b_inData[c23_i45] = (*(real_T (*)[100])c23_inData)[c23_i45];
  }

  for (c23_i46 = 0; c23_i46 < 100; c23_i46++) {
    c23_u[c23_i46] = c23_b_inData[c23_i46];
  }

  c23_y = NULL;
  if (!chartInstance->c23_dataf_not_empty) {
    sf_mex_assign(&c23_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  false);
  }

  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_o_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_dataf, const char_T *c23_identifier,
  real_T c23_y[100])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dataf), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_dataf);
}

static void c23_p_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[100])
{
  real_T c23_dv10[100];
  int32_T c23_i47;
  if (mxIsEmpty(c23_u)) {
    chartInstance->c23_dataf_not_empty = false;
  } else {
    chartInstance->c23_dataf_not_empty = true;
    sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv10, 1, 0, 0U, 1, 0U, 2,
                  1, 100);
    for (c23_i47 = 0; c23_i47 < 100; c23_i47++) {
      c23_y[c23_i47] = c23_dv10[c23_i47];
    }
  }

  sf_mex_destroy(&c23_u);
}

static void c23_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_dataf;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[100];
  int32_T c23_i48;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_dataf = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dataf), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_b_dataf);
  for (c23_i48 = 0; c23_i48 < 100; c23_i48++) {
    (*(real_T (*)[100])c23_outData)[c23_i48] = c23_y[c23_i48];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_i_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i49;
  real_T c23_b_inData[2];
  int32_T c23_i50;
  real_T c23_u[2];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i49 = 0; c23_i49 < 2; c23_i49++) {
    c23_b_inData[c23_i49] = (*(real_T (*)[2])c23_inData)[c23_i49];
  }

  for (c23_i50 = 0; c23_i50 < 2; c23_i50++) {
    c23_u[c23_i50] = c23_b_inData[c23_i50];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_q_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_delta, const char_T *c23_identifier, real_T
  c23_y[2])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_delta), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_delta);
}

static void c23_r_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[2])
{
  real_T c23_dv11[2];
  int32_T c23_i51;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv11, 1, 0, 0U, 1, 0U, 1, 2);
  for (c23_i51 = 0; c23_i51 < 2; c23_i51++) {
    c23_y[c23_i51] = c23_dv11[c23_i51];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_delta;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[2];
  int32_T c23_i52;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_delta = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_delta), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_delta);
  for (c23_i52 = 0; c23_i52 < 2; c23_i52++) {
    (*(real_T (*)[2])c23_outData)[c23_i52] = c23_y[c23_i52];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_j_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i53;
  real_T c23_b_inData[4];
  int32_T c23_i54;
  real_T c23_u[4];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i53 = 0; c23_i53 < 4; c23_i53++) {
    c23_b_inData[c23_i53] = (*(real_T (*)[4])c23_inData)[c23_i53];
  }

  for (c23_i54 = 0; c23_i54 < 4; c23_i54++) {
    c23_u[c23_i54] = c23_b_inData[c23_i54];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static void c23_s_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[4])
{
  real_T c23_dv12[4];
  int32_T c23_i55;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv12, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c23_i55 = 0; c23_i55 < 4; c23_i55++) {
    c23_y[c23_i55] = c23_dv12[c23_i55];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_dr;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[4];
  int32_T c23_i56;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_dr = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dr), &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_dr);
  for (c23_i56 = 0; c23_i56 < 4; c23_i56++) {
    (*(real_T (*)[4])c23_outData)[c23_i56] = c23_y[c23_i56];
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_k_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_t_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d6;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d6, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d6;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_ts;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_ts = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_ts),
    &c23_thisId);
  sf_mex_destroy(&c23_b_ts);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_l_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i57;
  real_T c23_b_inData[5];
  int32_T c23_i58;
  real_T c23_u[5];
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  for (c23_i57 = 0; c23_i57 < 5; c23_i57++) {
    c23_b_inData[c23_i57] = (*(real_T (*)[5])c23_inData)[c23_i57];
  }

  for (c23_i58 = 0; c23_i58 < 5; c23_i58++) {
    c23_u[c23_i58] = c23_b_inData[c23_i58];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

const mxArray *sf_c23_experiment_lib2_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_createstruct("structure", 2, 23, 1),
                false);
  c23_info_helper(&c23_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c23_nameCaptureInfo);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(const mxArray **c23_info)
{
  const mxArray *c23_rhs0 = NULL;
  const mxArray *c23_lhs0 = NULL;
  const mxArray *c23_rhs1 = NULL;
  const mxArray *c23_lhs1 = NULL;
  const mxArray *c23_rhs2 = NULL;
  const mxArray *c23_lhs2 = NULL;
  const mxArray *c23_rhs3 = NULL;
  const mxArray *c23_lhs3 = NULL;
  const mxArray *c23_rhs4 = NULL;
  const mxArray *c23_lhs4 = NULL;
  const mxArray *c23_rhs5 = NULL;
  const mxArray *c23_lhs5 = NULL;
  const mxArray *c23_rhs6 = NULL;
  const mxArray *c23_lhs6 = NULL;
  const mxArray *c23_rhs7 = NULL;
  const mxArray *c23_lhs7 = NULL;
  const mxArray *c23_rhs8 = NULL;
  const mxArray *c23_lhs8 = NULL;
  const mxArray *c23_rhs9 = NULL;
  const mxArray *c23_lhs9 = NULL;
  const mxArray *c23_rhs10 = NULL;
  const mxArray *c23_lhs10 = NULL;
  const mxArray *c23_rhs11 = NULL;
  const mxArray *c23_lhs11 = NULL;
  const mxArray *c23_rhs12 = NULL;
  const mxArray *c23_lhs12 = NULL;
  const mxArray *c23_rhs13 = NULL;
  const mxArray *c23_lhs13 = NULL;
  const mxArray *c23_rhs14 = NULL;
  const mxArray *c23_lhs14 = NULL;
  const mxArray *c23_rhs15 = NULL;
  const mxArray *c23_lhs15 = NULL;
  const mxArray *c23_rhs16 = NULL;
  const mxArray *c23_lhs16 = NULL;
  const mxArray *c23_rhs17 = NULL;
  const mxArray *c23_lhs17 = NULL;
  const mxArray *c23_rhs18 = NULL;
  const mxArray *c23_lhs18 = NULL;
  const mxArray *c23_rhs19 = NULL;
  const mxArray *c23_lhs19 = NULL;
  const mxArray *c23_rhs20 = NULL;
  const mxArray *c23_lhs20 = NULL;
  const mxArray *c23_rhs21 = NULL;
  const mxArray *c23_lhs21 = NULL;
  const mxArray *c23_rhs22 = NULL;
  const mxArray *c23_lhs22 = NULL;
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c23_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c23_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c23_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c23_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c23_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c23_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c23_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sum"), "name", "name", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c23_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c23_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("isequal"), "name", "name", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c23_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c23_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c23_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c23_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c23_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c23_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c23_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c23_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("intmax"), "name", "name", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c23_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1381850300U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c23_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(""), "context", "context", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("sum"), "name", "name", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c23_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c23_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c23_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c23_info, c23_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c23_info, c23_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c23_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c23_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c23_info, sf_mex_duplicatearraysafe(&c23_lhs22), "lhs", "lhs",
                  22);
  sf_mex_destroy(&c23_rhs0);
  sf_mex_destroy(&c23_lhs0);
  sf_mex_destroy(&c23_rhs1);
  sf_mex_destroy(&c23_lhs1);
  sf_mex_destroy(&c23_rhs2);
  sf_mex_destroy(&c23_lhs2);
  sf_mex_destroy(&c23_rhs3);
  sf_mex_destroy(&c23_lhs3);
  sf_mex_destroy(&c23_rhs4);
  sf_mex_destroy(&c23_lhs4);
  sf_mex_destroy(&c23_rhs5);
  sf_mex_destroy(&c23_lhs5);
  sf_mex_destroy(&c23_rhs6);
  sf_mex_destroy(&c23_lhs6);
  sf_mex_destroy(&c23_rhs7);
  sf_mex_destroy(&c23_lhs7);
  sf_mex_destroy(&c23_rhs8);
  sf_mex_destroy(&c23_lhs8);
  sf_mex_destroy(&c23_rhs9);
  sf_mex_destroy(&c23_lhs9);
  sf_mex_destroy(&c23_rhs10);
  sf_mex_destroy(&c23_lhs10);
  sf_mex_destroy(&c23_rhs11);
  sf_mex_destroy(&c23_lhs11);
  sf_mex_destroy(&c23_rhs12);
  sf_mex_destroy(&c23_lhs12);
  sf_mex_destroy(&c23_rhs13);
  sf_mex_destroy(&c23_lhs13);
  sf_mex_destroy(&c23_rhs14);
  sf_mex_destroy(&c23_lhs14);
  sf_mex_destroy(&c23_rhs15);
  sf_mex_destroy(&c23_lhs15);
  sf_mex_destroy(&c23_rhs16);
  sf_mex_destroy(&c23_lhs16);
  sf_mex_destroy(&c23_rhs17);
  sf_mex_destroy(&c23_lhs17);
  sf_mex_destroy(&c23_rhs18);
  sf_mex_destroy(&c23_lhs18);
  sf_mex_destroy(&c23_rhs19);
  sf_mex_destroy(&c23_lhs19);
  sf_mex_destroy(&c23_rhs20);
  sf_mex_destroy(&c23_lhs20);
  sf_mex_destroy(&c23_rhs21);
  sf_mex_destroy(&c23_lhs21);
  sf_mex_destroy(&c23_rhs22);
  sf_mex_destroy(&c23_lhs22);
}

static const mxArray *c23_emlrt_marshallOut(const char * c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c23_u)), false);
  return c23_y;
}

static const mxArray *c23_b_emlrt_marshallOut(const uint32_T c23_u)
{
  const mxArray *c23_y = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 7, 0U, 0U, 0U, 0), false);
  return c23_y;
}

static real_T c23_sum(SFc23_experiment_lib2InstanceStruct *chartInstance, real_T
                      c23_x[100])
{
  real_T c23_y;
  int32_T c23_k;
  int32_T c23_b_k;
  (void)chartInstance;
  c23_y = c23_x[0];
  for (c23_k = 2; c23_k < 101; c23_k++) {
    c23_b_k = c23_k;
    c23_y += c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c23_b_k), 1, 100, 1, 0) - 1];
  }

  return c23_y;
}

static real_T c23_b_sum(SFc23_experiment_lib2InstanceStruct *chartInstance,
  real_T c23_x[4])
{
  real_T c23_y;
  int32_T c23_k;
  int32_T c23_b_k;
  (void)chartInstance;
  c23_y = c23_x[0];
  for (c23_k = 2; c23_k < 5; c23_k++) {
    c23_b_k = c23_k;
    c23_y += c23_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c23_b_k), 1, 4, 1, 0) - 1];
  }

  return c23_y;
}

static const mxArray *c23_m_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_u_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i59;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i59, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i59;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_v_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_experiment_lib2, const
  char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_experiment_lib2), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_experiment_lib2);
  return c23_y;
}

static uint8_T c23_w_emlrt_marshallIn(SFc23_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_experiment_lib2InstanceStruct
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

void sf_c23_experiment_lib2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1163871094U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3004067454U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(424791462U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1355493055U);
}

mxArray *sf_c23_experiment_lib2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Jl7aWgMpRxR0ew3rbRNiZG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_experiment_lib2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_experiment_lib2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c23_experiment_lib2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"delta\",},{M[4],M[0],T\"dataf\",S'l','i','p'{{M1x2[79 84],M[0],}}},{M[4],M[0],T\"dataq\",S'l','i','p'{{M1x2[205 210],M[0],}}},{M[4],M[0],T\"datau\",S'l','i','p'{{M1x2[268 273],M[0],}}},{M[4],M[0],T\"datav\",S'l','i','p'{{M1x2[142 147],M[0],}}},{M[4],M[0],T\"drift\",S'l','i','p'{{M1x2[435 440],M[0],}}},{M[4],M[0],T\"integral\",S'l','i','p'{{M1x2[490 498],M[0],}}},{M[4],M[0],T\"t\",S'l','i','p'{{M1x2[331 332],M[0],}}},{M[4],M[0],T\"tc\",S'l','i','p'{{M1x2[393 395],M[0],}}},{M[8],M[0],T\"is_active_c23_experiment_lib2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_experiment_lib2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_experiment_lib2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_experiment_lib2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _experiment_lib2MachineNumber_,
           23,
           1,
           1,
           0,
           11,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"delta");
          _SFD_SET_DATA_PROPS(2,10,0,0,"num_generators");
          _SFD_SET_DATA_PROPS(3,1,1,0,"a");
          _SFD_SET_DATA_PROPS(4,1,1,0,"f");
          _SFD_SET_DATA_PROPS(5,1,1,0,"v");
          _SFD_SET_DATA_PROPS(6,1,1,0,"q");
          _SFD_SET_DATA_PROPS(7,1,1,0,"u");
          _SFD_SET_DATA_PROPS(8,1,1,0,"en");
          _SFD_SET_DATA_PROPS(9,10,0,0,"ts");
          _SFD_SET_DATA_PROPS(10,10,0,0,"dr");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1024);
        _SFD_CV_INIT_EML_IF(0,1,0,86,103,-1,128);
        _SFD_CV_INIT_EML_IF(0,1,1,149,166,-1,191);
        _SFD_CV_INIT_EML_IF(0,1,2,212,229,-1,254);
        _SFD_CV_INIT_EML_IF(0,1,3,275,292,-1,317);
        _SFD_CV_INIT_EML_IF(0,1,4,334,347,-1,357);
        _SFD_CV_INIT_EML_IF(0,1,5,397,411,-1,422);
        _SFD_CV_INIT_EML_IF(0,1,6,442,459,-1,477);
        _SFD_CV_INIT_EML_IF(0,1,7,500,520,-1,545);
        _SFD_CV_INIT_EML_IF(0,1,8,548,561,-1,669);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_l_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_i_sf_marshallOut,(MexInFcnForType)
            c23_i_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)
          c23_k_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_k_sf_marshallOut,(MexInFcnForType)
          c23_k_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_j_sf_marshallOut,(MexInFcnForType)
            c23_j_sf_marshallIn);
        }

        {
          real_T *c23_a;
          real_T *c23_f;
          real_T *c23_v;
          real_T *c23_q;
          real_T *c23_en;
          real_T (*c23_msg)[5];
          real_T (*c23_delta)[2];
          real_T (*c23_u)[2];
          c23_en = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c23_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 5);
          c23_q = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c23_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c23_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c23_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c23_msg = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c23_msg);
          _SFD_SET_DATA_VALUE_PTR(1U, *c23_delta);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c23_num_generators);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_a);
          _SFD_SET_DATA_VALUE_PTR(4U, c23_f);
          _SFD_SET_DATA_VALUE_PTR(5U, c23_v);
          _SFD_SET_DATA_VALUE_PTR(6U, c23_q);
          _SFD_SET_DATA_VALUE_PTR(7U, *c23_u);
          _SFD_SET_DATA_VALUE_PTR(8U, c23_en);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c23_ts);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c23_dr);
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
  return "HKNlOeUwKDa4pwACzoR6kE";
}

static void sf_opaque_initialize_c23_experiment_lib2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
  initialize_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c23_experiment_lib2(void *chartInstanceVar)
{
  enable_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_experiment_lib2(void *chartInstanceVar)
{
  disable_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_experiment_lib2(void *chartInstanceVar)
{
  sf_gateway_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_experiment_lib2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_experiment_lib2
    ((SFc23_experiment_lib2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_experiment_lib2();/* state var info */
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

extern void sf_internal_set_sim_state_c23_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c23_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_experiment_lib2(SimStruct* S)
{
  return sf_internal_get_sim_state_c23_experiment_lib2(S);
}

static void sf_opaque_set_sim_state_c23_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c23_experiment_lib2(S, st);
}

static void sf_opaque_terminate_c23_experiment_lib2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_experiment_lib2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_experiment_lib2_optimization_info();
    }

    finalize_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
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
  initSimStructsc23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_experiment_lib2(SimStruct *S)
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
    initialize_params_c23_experiment_lib2((SFc23_experiment_lib2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_experiment_lib2(SimStruct *S)
{
  /* Actual parameters from chart:
     dr num_generators ts
   */
  const char_T *rtParamNames[] = { "dr", "num_generators", "ts" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for dr*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for num_generators*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for ts*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_experiment_lib2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1345297160U));
  ssSetChecksum1(S,(3854211704U));
  ssSetChecksum2(S,(37982412U));
  ssSetChecksum3(S,(2643637891U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_experiment_lib2(SimStruct *S)
{
  SFc23_experiment_lib2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_experiment_lib2InstanceStruct *)utMalloc(sizeof
    (SFc23_experiment_lib2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_experiment_lib2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_experiment_lib2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_experiment_lib2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_experiment_lib2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_experiment_lib2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_experiment_lib2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_experiment_lib2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_experiment_lib2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_experiment_lib2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_experiment_lib2;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_experiment_lib2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_experiment_lib2;
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

void c23_experiment_lib2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_experiment_lib2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_experiment_lib2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_experiment_lib2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_experiment_lib2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
