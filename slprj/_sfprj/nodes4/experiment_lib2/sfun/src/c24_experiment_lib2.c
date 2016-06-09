/* Include files */

#include <stddef.h>
#include "blas.h"
#include "experiment_lib2_sfun.h"
#include "c24_experiment_lib2.h"
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
static const char * c24_debug_family_names[20] = { "picontroller", "e_w",
  "nargin", "nargout", "f", "V", "en", "a", "wo", "kif", "kpf", "kiV", "kpV",
  "ts", "dr", "delta", "t", "tc", "drift", "integral" };

/* Function Declarations */
static void initialize_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance);
static void initialize_params_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance);
static void enable_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance);
static void disable_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance);
static void c24_update_debugger_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance);
static void set_sim_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance, const mxArray *c24_st);
static void finalize_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance);
static void sf_gateway_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance);
static void initSimStructsc24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_integral, const char_T *c24_identifier);
static real_T c24_b_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_c_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_drift, const char_T *c24_identifier);
static real_T c24_d_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_e_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_tc, const char_T *c24_identifier);
static real_T c24_f_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_g_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_t, const char_T *c24_identifier);
static real_T c24_h_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_i_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_delta, const char_T *c24_identifier, real_T
  c24_y[2]);
static void c24_j_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[2]);
static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_k_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4]);
static void c24_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_l_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_m_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_n_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_experiment_lib2, const
  char_T *c24_identifier);
static uint8_T c24_o_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_experiment_lib2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c24_t_not_empty = false;
  chartInstance->c24_tc_not_empty = false;
  chartInstance->c24_drift_not_empty = false;
  chartInstance->c24_integral_not_empty = false;
  chartInstance->c24_is_active_c24_experiment_lib2 = 0U;
}

static void initialize_params_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c24_d0;
  real_T c24_d1;
  real_T c24_d2;
  real_T c24_d3;
  real_T c24_d4;
  real_T c24_d5;
  real_T c24_d6;
  real_T c24_dv0[4];
  int32_T c24_i0;
  sf_mex_import_named("a", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c24_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_a = c24_d0;
  sf_mex_import_named("wo", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c24_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_wo = c24_d1;
  sf_mex_import_named("kif", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c24_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_kif = c24_d2;
  sf_mex_import_named("kpf", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c24_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_kpf = c24_d3;
  sf_mex_import_named("kiV", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c24_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_kiV = c24_d4;
  sf_mex_import_named("kpV", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c24_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_kpV = c24_d5;
  sf_mex_import_named("ts", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c24_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c24_ts = c24_d6;
  sf_mex_import_named("dr", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c24_dv0, 0, 0, 0U, 1, 0U, 2, 1, 4);
  for (c24_i0 = 0; c24_i0 < 4; c24_i0++) {
    chartInstance->c24_dr[c24_i0] = c24_dv0[c24_i0];
  }
}

static void enable_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c24_update_debugger_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  int32_T c24_i1;
  real_T c24_u[2];
  const mxArray *c24_b_y = NULL;
  real_T c24_hoistedGlobal;
  real_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  real_T c24_b_hoistedGlobal;
  real_T c24_c_u;
  const mxArray *c24_d_y = NULL;
  real_T c24_c_hoistedGlobal;
  real_T c24_d_u;
  const mxArray *c24_e_y = NULL;
  real_T c24_d_hoistedGlobal;
  real_T c24_e_u;
  const mxArray *c24_f_y = NULL;
  uint8_T c24_e_hoistedGlobal;
  uint8_T c24_f_u;
  const mxArray *c24_g_y = NULL;
  real_T (*c24_delta)[2];
  c24_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellmatrix(6, 1), false);
  for (c24_i1 = 0; c24_i1 < 2; c24_i1++) {
    c24_u[c24_i1] = (*c24_delta)[c24_i1];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_hoistedGlobal = chartInstance->c24_drift;
  c24_b_u = c24_hoistedGlobal;
  c24_c_y = NULL;
  if (!chartInstance->c24_drift_not_empty) {
    sf_mex_assign(&c24_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c24_y, 1, c24_c_y);
  c24_b_hoistedGlobal = chartInstance->c24_integral;
  c24_c_u = c24_b_hoistedGlobal;
  c24_d_y = NULL;
  if (!chartInstance->c24_integral_not_empty) {
    sf_mex_assign(&c24_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c24_y, 2, c24_d_y);
  c24_c_hoistedGlobal = chartInstance->c24_t;
  c24_d_u = c24_c_hoistedGlobal;
  c24_e_y = NULL;
  if (!chartInstance->c24_t_not_empty) {
    sf_mex_assign(&c24_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_e_y, sf_mex_create("y", &c24_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c24_y, 3, c24_e_y);
  c24_d_hoistedGlobal = chartInstance->c24_tc;
  c24_e_u = c24_d_hoistedGlobal;
  c24_f_y = NULL;
  if (!chartInstance->c24_tc_not_empty) {
    sf_mex_assign(&c24_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_f_y, sf_mex_create("y", &c24_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c24_y, 4, c24_f_y);
  c24_e_hoistedGlobal = chartInstance->c24_is_active_c24_experiment_lib2;
  c24_f_u = c24_e_hoistedGlobal;
  c24_g_y = NULL;
  sf_mex_assign(&c24_g_y, sf_mex_create("y", &c24_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 5, c24_g_y);
  sf_mex_assign(&c24_st, c24_y, false);
  return c24_st;
}

static void set_sim_state_c24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  real_T c24_dv1[2];
  int32_T c24_i2;
  real_T (*c24_delta)[2];
  c24_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 0)),
    "delta", c24_dv1);
  for (c24_i2 = 0; c24_i2 < 2; c24_i2++) {
    (*c24_delta)[c24_i2] = c24_dv1[c24_i2];
  }

  chartInstance->c24_drift = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c24_u, 1)), "drift");
  chartInstance->c24_integral = c24_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c24_u, 2)), "integral");
  chartInstance->c24_t = c24_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c24_u, 3)), "t");
  chartInstance->c24_tc = c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c24_u, 4)), "tc");
  chartInstance->c24_is_active_c24_experiment_lib2 = c24_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 5)),
     "is_active_c24_experiment_lib2");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_experiment_lib2(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c24_experiment_lib2(SFc24_experiment_lib2InstanceStruct
  *chartInstance)
{
  real_T c24_hoistedGlobal;
  real_T c24_b_hoistedGlobal;
  real_T c24_c_hoistedGlobal;
  real_T c24_d_hoistedGlobal;
  real_T c24_e_hoistedGlobal;
  real_T c24_f_hoistedGlobal;
  real_T c24_g_hoistedGlobal;
  real_T c24_h_hoistedGlobal;
  real_T c24_i_hoistedGlobal;
  real_T c24_j_hoistedGlobal;
  real_T c24_f;
  real_T c24_V;
  real_T c24_en;
  real_T c24_b_a;
  real_T c24_b_wo;
  real_T c24_b_kif;
  real_T c24_b_kpf;
  real_T c24_b_kiV;
  real_T c24_b_kpV;
  real_T c24_b_ts;
  int32_T c24_i3;
  real_T c24_b_dr[4];
  uint32_T c24_debug_family_var_map[20];
  real_T c24_picontroller;
  real_T c24_e_w;
  real_T c24_nargin = 11.0;
  real_T c24_nargout = 1.0;
  real_T c24_delta[2];
  int32_T c24_i4;
  int32_T c24_i5;
  int32_T c24_i6;
  real_T *c24_b_f;
  real_T *c24_b_V;
  real_T *c24_b_en;
  real_T (*c24_b_delta)[2];
  c24_b_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_en = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c24_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c24_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c24_b_f, 0U);
  _SFD_DATA_RANGE_CHECK(*c24_b_V, 1U);
  _SFD_DATA_RANGE_CHECK(*c24_b_en, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_a, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_wo, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_kif, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_kpf, 6U);
  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = *c24_b_f;
  c24_b_hoistedGlobal = *c24_b_V;
  c24_c_hoistedGlobal = *c24_b_en;
  c24_d_hoistedGlobal = chartInstance->c24_a;
  c24_e_hoistedGlobal = chartInstance->c24_wo;
  c24_f_hoistedGlobal = chartInstance->c24_kif;
  c24_g_hoistedGlobal = chartInstance->c24_kpf;
  c24_h_hoistedGlobal = chartInstance->c24_kiV;
  c24_i_hoistedGlobal = chartInstance->c24_kpV;
  c24_j_hoistedGlobal = chartInstance->c24_ts;
  c24_f = c24_hoistedGlobal;
  c24_V = c24_b_hoistedGlobal;
  c24_en = c24_c_hoistedGlobal;
  c24_b_a = c24_d_hoistedGlobal;
  c24_b_wo = c24_e_hoistedGlobal;
  c24_b_kif = c24_f_hoistedGlobal;
  c24_b_kpf = c24_g_hoistedGlobal;
  c24_b_kiV = c24_h_hoistedGlobal;
  c24_b_kpV = c24_i_hoistedGlobal;
  c24_b_ts = c24_j_hoistedGlobal;
  for (c24_i3 = 0; c24_i3 < 4; c24_i3++) {
    c24_b_dr[c24_i3] = chartInstance->c24_dr[c24_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_picontroller, 0U,
    c24_g_sf_marshallOut, c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_e_w, 1U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 2U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 3U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_f, 4U, c24_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_V, 5U, c24_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_en, 6U, c24_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_a, 7U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_wo, 8U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_kif, 9U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_kpf, 10U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_kiV, 11U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_kpV, 12U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_ts, 13U, c24_g_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_dr, 14U, c24_f_sf_marshallOut,
    c24_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_delta, 15U, c24_e_sf_marshallOut,
    c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c24_t, 16U,
    c24_d_sf_marshallOut, c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c24_tc, 17U,
    c24_c_sf_marshallOut, c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c24_drift, 18U,
    c24_b_sf_marshallOut, c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c24_integral, 19U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 14);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c24_t_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 14);
    chartInstance->c24_t = 0.0;
    chartInstance->c24_t_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 15);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c24_tc_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 15);
    chartInstance->c24_tc = 0.0;
    chartInstance->c24_tc_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 16);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c24_drift_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 16);
    chartInstance->c24_drift = c24_b_dr[_SFD_EML_ARRAY_BOUNDS_CHECK("dr",
      (int32_T)_SFD_INTEGER_CHECK("a", c24_b_a), 1, 4, 1, 0) - 1];
    chartInstance->c24_drift_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 17);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c24_integral_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 17);
    chartInstance->c24_integral = 0.0;
    chartInstance->c24_integral_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 18);
  c24_picontroller = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 20);
  chartInstance->c24_tc = (chartInstance->c24_tc + c24_b_ts) +
    chartInstance->c24_drift;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 21);
  chartInstance->c24_t = (chartInstance->c24_t + c24_b_ts) +
    chartInstance->c24_drift;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 22);
  c24_e_w = c24_en * (c24_b_wo - 6.2831853071795862 * c24_f);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 23);
  chartInstance->c24_integral += (c24_b_ts + chartInstance->c24_drift) * c24_e_w;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 24);
  c24_picontroller = c24_b_kif * chartInstance->c24_integral + c24_b_kpf *
    c24_e_w;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 25);
  c24_delta[0] = c24_picontroller;
  c24_delta[1] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  for (c24_i4 = 0; c24_i4 < 2; c24_i4++) {
    (*c24_b_delta)[c24_i4] = c24_delta[c24_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c24_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_experiment_lib2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c24_i5 = 0; c24_i5 < 2; c24_i5++) {
    _SFD_DATA_RANGE_CHECK((*c24_b_delta)[c24_i5], 7U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c24_kiV, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_kpV, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c24_ts, 10U);
  for (c24_i6 = 0; c24_i6 < 4; c24_i6++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c24_dr[c24_i6], 11U);
  }
}

static void initSimStructsc24_experiment_lib2
  (SFc24_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber)
{
  (void)c24_machineNumber;
  (void)c24_chartNumber;
  (void)c24_instanceNumber;
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  if (!chartInstance->c24_integral_not_empty) {
    sf_mex_assign(&c24_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_integral, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_integral),
    &c24_thisId);
  sf_mex_destroy(&c24_b_integral);
  return c24_y;
}

static real_T c24_b_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d7;
  if (mxIsEmpty(c24_u)) {
    chartInstance->c24_integral_not_empty = false;
  } else {
    chartInstance->c24_integral_not_empty = true;
    sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d7, 1, 0, 0U, 0, 0U, 0);
    c24_y = c24_d7;
  }

  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_integral;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_integral = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_integral),
    &c24_thisId);
  sf_mex_destroy(&c24_b_integral);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  if (!chartInstance->c24_drift_not_empty) {
    sf_mex_assign(&c24_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_c_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_drift, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_drift),
    &c24_thisId);
  sf_mex_destroy(&c24_b_drift);
  return c24_y;
}

static real_T c24_d_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d8;
  if (mxIsEmpty(c24_u)) {
    chartInstance->c24_drift_not_empty = false;
  } else {
    chartInstance->c24_drift_not_empty = true;
    sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d8, 1, 0, 0U, 0, 0U, 0);
    c24_y = c24_d8;
  }

  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_drift;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_drift = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_drift),
    &c24_thisId);
  sf_mex_destroy(&c24_b_drift);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  if (!chartInstance->c24_tc_not_empty) {
    sf_mex_assign(&c24_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_e_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_tc, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_tc),
    &c24_thisId);
  sf_mex_destroy(&c24_b_tc);
  return c24_y;
}

static real_T c24_f_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d9;
  if (mxIsEmpty(c24_u)) {
    chartInstance->c24_tc_not_empty = false;
  } else {
    chartInstance->c24_tc_not_empty = true;
    sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d9, 1, 0, 0U, 0, 0U, 0);
    c24_y = c24_d9;
  }

  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_tc;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_tc = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_tc),
    &c24_thisId);
  sf_mex_destroy(&c24_b_tc);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  if (!chartInstance->c24_t_not_empty) {
    sf_mex_assign(&c24_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_g_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_t, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_t), &c24_thisId);
  sf_mex_destroy(&c24_b_t);
  return c24_y;
}

static real_T c24_h_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d10;
  if (mxIsEmpty(c24_u)) {
    chartInstance->c24_t_not_empty = false;
  } else {
    chartInstance->c24_t_not_empty = true;
    sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d10, 1, 0, 0U, 0, 0U, 0);
    c24_y = c24_d10;
  }

  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_t;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_t = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_t), &c24_thisId);
  sf_mex_destroy(&c24_b_t);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i7;
  real_T c24_b_inData[2];
  int32_T c24_i8;
  real_T c24_u[2];
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i7 = 0; c24_i7 < 2; c24_i7++) {
    c24_b_inData[c24_i7] = (*(real_T (*)[2])c24_inData)[c24_i7];
  }

  for (c24_i8 = 0; c24_i8 < 2; c24_i8++) {
    c24_u[c24_i8] = c24_b_inData[c24_i8];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_i_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_delta, const char_T *c24_identifier, real_T
  c24_y[2])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_delta), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_delta);
}

static void c24_j_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[2])
{
  real_T c24_dv2[2];
  int32_T c24_i9;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c24_i9 = 0; c24_i9 < 2; c24_i9++) {
    c24_y[c24_i9] = c24_dv2[c24_i9];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_delta;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[2];
  int32_T c24_i10;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_delta = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_delta), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_delta);
  for (c24_i10 = 0; c24_i10 < 2; c24_i10++) {
    (*(real_T (*)[2])c24_outData)[c24_i10] = c24_y[c24_i10];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i11;
  real_T c24_b_inData[4];
  int32_T c24_i12;
  real_T c24_u[4];
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i11 = 0; c24_i11 < 4; c24_i11++) {
    c24_b_inData[c24_i11] = (*(real_T (*)[4])c24_inData)[c24_i11];
  }

  for (c24_i12 = 0; c24_i12 < 4; c24_i12++) {
    c24_u[c24_i12] = c24_b_inData[c24_i12];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_k_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4])
{
  real_T c24_dv3[4];
  int32_T c24_i13;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c24_i13 = 0; c24_i13 < 4; c24_i13++) {
    c24_y[c24_i13] = c24_dv3[c24_i13];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_dr;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[4];
  int32_T c24_i14;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_dr = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_dr), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_b_dr);
  for (c24_i14 = 0; c24_i14 < 4; c24_i14++) {
    (*(real_T (*)[4])c24_outData)[c24_i14] = c24_y[c24_i14];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_l_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d11;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d11, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d11;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_ts;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_ts = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_ts),
    &c24_thisId);
  sf_mex_destroy(&c24_b_ts);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_experiment_lib2_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c24_nameCaptureInfo;
}

static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static int32_T c24_m_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i15;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i15, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i15;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_n_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_experiment_lib2, const
  char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_experiment_lib2), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_experiment_lib2);
  return c24_y;
}

static uint8_T c24_o_emlrt_marshallIn(SFc24_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_experiment_lib2InstanceStruct
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

void sf_c24_experiment_lib2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2018056345U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(256758047U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2498586856U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2777335024U);
}

mxArray *sf_c24_experiment_lib2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8v2B7HC0XC5IJ1vFCyKqc");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      pr[1] = (double)(4);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c24_experiment_lib2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_experiment_lib2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c24_experiment_lib2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"delta\",},{M[4],M[0],T\"drift\",S'l','i','p'{{M1x2[578 583],M[0],}}},{M[4],M[0],T\"integral\",S'l','i','p'{{M1x2[633 641],M[0],}}},{M[4],M[0],T\"t\",S'l','i','p'{{M1x2[474 475],M[0],}}},{M[4],M[0],T\"tc\",S'l','i','p'{{M1x2[536 538],M[0],}}},{M[8],M[0],T\"is_active_c24_experiment_lib2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_experiment_lib2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_experiment_lib2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc24_experiment_lib2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _experiment_lib2MachineNumber_,
           24,
           1,
           1,
           0,
           12,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"f");
          _SFD_SET_DATA_PROPS(1,1,1,0,"V");
          _SFD_SET_DATA_PROPS(2,1,1,0,"en");
          _SFD_SET_DATA_PROPS(3,10,0,0,"a");
          _SFD_SET_DATA_PROPS(4,10,0,0,"wo");
          _SFD_SET_DATA_PROPS(5,10,0,0,"kif");
          _SFD_SET_DATA_PROPS(6,10,0,0,"kpf");
          _SFD_SET_DATA_PROPS(7,2,0,1,"delta");
          _SFD_SET_DATA_PROPS(8,10,0,0,"kiV");
          _SFD_SET_DATA_PROPS(9,10,0,0,"kpV");
          _SFD_SET_DATA_PROPS(10,10,0,0,"ts");
          _SFD_SET_DATA_PROPS(11,10,0,0,"dr");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",405,-1,889);
        _SFD_CV_INIT_EML_IF(0,1,0,477,490,-1,500);
        _SFD_CV_INIT_EML_IF(0,1,1,540,554,-1,565);
        _SFD_CV_INIT_EML_IF(0,1,2,585,602,-1,620);
        _SFD_CV_INIT_EML_IF(0,1,3,643,663,-1,680);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_e_sf_marshallOut,(MexInFcnForType)
            c24_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_g_sf_marshallOut,(MexInFcnForType)
          c24_g_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_f_sf_marshallOut,(MexInFcnForType)
            c24_f_sf_marshallIn);
        }

        {
          real_T *c24_f;
          real_T *c24_V;
          real_T *c24_en;
          real_T (*c24_delta)[2];
          c24_delta = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c24_en = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c24_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c24_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c24_f);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_V);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_en);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c24_a);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c24_wo);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c24_kif);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c24_kpf);
          _SFD_SET_DATA_VALUE_PTR(7U, *c24_delta);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c24_kiV);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c24_kpV);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c24_ts);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c24_dr);
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
  return "WcajfcM8W9lNlTjSKFzgyG";
}

static void sf_opaque_initialize_c24_experiment_lib2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
  initialize_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c24_experiment_lib2(void *chartInstanceVar)
{
  enable_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c24_experiment_lib2(void *chartInstanceVar)
{
  disable_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c24_experiment_lib2(void *chartInstanceVar)
{
  sf_gateway_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_experiment_lib2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_experiment_lib2
    ((SFc24_experiment_lib2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_experiment_lib2();/* state var info */
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

extern void sf_internal_set_sim_state_c24_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c24_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_experiment_lib2(SimStruct* S)
{
  return sf_internal_get_sim_state_c24_experiment_lib2(S);
}

static void sf_opaque_set_sim_state_c24_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c24_experiment_lib2(S, st);
}

static void sf_opaque_terminate_c24_experiment_lib2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_experiment_lib2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_experiment_lib2_optimization_info();
    }

    finalize_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
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
  initSimStructsc24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_experiment_lib2(SimStruct *S)
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
    initialize_params_c24_experiment_lib2((SFc24_experiment_lib2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_experiment_lib2(SimStruct *S)
{
  /* Actual parameters from chart:
     a dr kiV kif kpV kpf ts wo
   */
  const char_T *rtParamNames[] = { "a", "dr", "kiV", "kif", "kpV", "kpf", "ts",
    "wo" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for a*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for dr*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for kiV*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for kif*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for kpV*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for kpf*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for ts*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for wo*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_experiment_lib2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,24,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3293847813U));
  ssSetChecksum1(S,(2708609170U));
  ssSetChecksum2(S,(1099601341U));
  ssSetChecksum3(S,(1412342097U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_experiment_lib2(SimStruct *S)
{
  SFc24_experiment_lib2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc24_experiment_lib2InstanceStruct *)utMalloc(sizeof
    (SFc24_experiment_lib2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_experiment_lib2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_experiment_lib2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_experiment_lib2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_experiment_lib2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c24_experiment_lib2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c24_experiment_lib2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_experiment_lib2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_experiment_lib2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_experiment_lib2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_experiment_lib2;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_experiment_lib2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_experiment_lib2;
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

void c24_experiment_lib2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_experiment_lib2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_experiment_lib2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_experiment_lib2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_experiment_lib2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
