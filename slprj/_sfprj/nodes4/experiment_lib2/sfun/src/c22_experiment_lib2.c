/* Include files */

#include <stddef.h>
#include "blas.h"
#include "experiment_lib2_sfun.h"
#include "c22_experiment_lib2.h"
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
static const char * c22_debug_family_names[7] = { "nargin", "nargout", "valfa",
  "vbeta", "R", "ialfa", "ibeta" };

/* Function Declarations */
static void initialize_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance);
static void initialize_params_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance);
static void enable_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance);
static void disable_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance);
static void c22_update_debugger_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance);
static void set_sim_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance, const mxArray *c22_st);
static void finalize_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance);
static void sf_gateway_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance);
static void initSimStructsc22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_ibeta, const char_T *c22_identifier);
static real_T c22_b_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_info_helper(const mxArray **c22_info);
static const mxArray *c22_emlrt_marshallOut(const char * c22_u);
static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_c_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_d_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_experiment_lib2, const
  char_T *c22_identifier);
static uint8_T c22_e_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_experiment_lib2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_is_active_c22_experiment_lib2 = 0U;
}

static void initialize_params_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  real_T c22_hoistedGlobal;
  real_T c22_u;
  const mxArray *c22_b_y = NULL;
  real_T c22_b_hoistedGlobal;
  real_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  uint8_T c22_c_hoistedGlobal;
  uint8_T c22_c_u;
  const mxArray *c22_d_y = NULL;
  real_T *c22_ialfa;
  real_T *c22_ibeta;
  c22_ibeta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_ialfa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(3, 1), false);
  c22_hoistedGlobal = *c22_ialfa;
  c22_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_b_hoistedGlobal = *c22_ibeta;
  c22_b_u = c22_b_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  c22_c_hoistedGlobal = chartInstance->c22_is_active_c22_experiment_lib2;
  c22_c_u = c22_c_hoistedGlobal;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 2, c22_d_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T *c22_ialfa;
  real_T *c22_ibeta;
  c22_ibeta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_ialfa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c22_doneDoubleBufferReInit = true;
  c22_u = sf_mex_dup(c22_st);
  *c22_ialfa = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 0)), "ialfa");
  *c22_ibeta = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 1)), "ibeta");
  chartInstance->c22_is_active_c22_experiment_lib2 = c22_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 2)),
     "is_active_c22_experiment_lib2");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_experiment_lib2(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c22_experiment_lib2(SFc22_experiment_lib2InstanceStruct
  *chartInstance)
{
  real_T c22_hoistedGlobal;
  real_T c22_b_hoistedGlobal;
  real_T c22_c_hoistedGlobal;
  real_T c22_valfa;
  real_T c22_vbeta;
  real_T c22_R;
  uint32_T c22_debug_family_var_map[7];
  real_T c22_nargin = 3.0;
  real_T c22_nargout = 2.0;
  real_T c22_ialfa;
  real_T c22_ibeta;
  real_T c22_A;
  real_T c22_B;
  real_T c22_x;
  real_T c22_y;
  real_T c22_b_x;
  real_T c22_b_y;
  real_T c22_c_x;
  real_T c22_c_y;
  real_T c22_b_A;
  real_T c22_b_B;
  real_T c22_d_x;
  real_T c22_d_y;
  real_T c22_e_x;
  real_T c22_e_y;
  real_T c22_f_x;
  real_T c22_f_y;
  real_T *c22_b_ibeta;
  real_T *c22_b_ialfa;
  real_T *c22_b_R;
  real_T *c22_b_vbeta;
  real_T *c22_b_valfa;
  c22_b_ibeta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_b_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c22_b_vbeta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c22_b_ialfa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_b_valfa = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c22_b_valfa, 0U);
  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c22_sfEvent);
  c22_hoistedGlobal = *c22_b_valfa;
  c22_b_hoistedGlobal = *c22_b_vbeta;
  c22_c_hoistedGlobal = *c22_b_R;
  c22_valfa = c22_hoistedGlobal;
  c22_vbeta = c22_b_hoistedGlobal;
  c22_R = c22_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_valfa, 2U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_vbeta, 3U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_R, 4U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_ialfa, 5U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_ibeta, 6U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
  c22_A = c22_valfa;
  c22_B = c22_R;
  c22_x = c22_A;
  c22_y = c22_B;
  c22_b_x = c22_x;
  c22_b_y = c22_y;
  c22_c_x = c22_b_x;
  c22_c_y = c22_b_y;
  c22_ialfa = c22_c_x / c22_c_y;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 4);
  c22_b_A = c22_vbeta;
  c22_b_B = c22_R;
  c22_d_x = c22_b_A;
  c22_d_y = c22_b_B;
  c22_e_x = c22_d_x;
  c22_e_y = c22_d_y;
  c22_f_x = c22_e_x;
  c22_f_y = c22_e_y;
  c22_ibeta = c22_f_x / c22_f_y;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *c22_b_ialfa = c22_ialfa;
  *c22_b_ibeta = c22_ibeta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c22_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_experiment_lib2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c22_b_ialfa, 1U);
  _SFD_DATA_RANGE_CHECK(*c22_b_vbeta, 2U);
  _SFD_DATA_RANGE_CHECK(*c22_b_R, 3U);
  _SFD_DATA_RANGE_CHECK(*c22_b_ibeta, 4U);
}

static void initSimStructsc22_experiment_lib2
  (SFc22_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc22_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real_T c22_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_ibeta, const char_T *c22_identifier)
{
  real_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_ibeta),
    &c22_thisId);
  sf_mex_destroy(&c22_ibeta);
  return c22_y;
}

static real_T c22_b_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_ibeta;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc22_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c22_ibeta = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_ibeta),
    &c22_thisId);
  sf_mex_destroy(&c22_ibeta);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_experiment_lib2_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c22_info_helper(&c22_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(const mxArray **c22_info)
{
  const mxArray *c22_rhs0 = NULL;
  const mxArray *c22_lhs0 = NULL;
  const mxArray *c22_rhs1 = NULL;
  const mxArray *c22_lhs1 = NULL;
  const mxArray *c22_rhs2 = NULL;
  const mxArray *c22_lhs2 = NULL;
  const mxArray *c22_rhs3 = NULL;
  const mxArray *c22_lhs3 = NULL;
  const mxArray *c22_rhs4 = NULL;
  const mxArray *c22_lhs4 = NULL;
  const mxArray *c22_rhs5 = NULL;
  const mxArray *c22_lhs5 = NULL;
  const mxArray *c22_rhs6 = NULL;
  const mxArray *c22_lhs6 = NULL;
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1388460096U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c22_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c22_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c22_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363714556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c22_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c22_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c22_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1389307920U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c22_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c22_rhs0);
  sf_mex_destroy(&c22_lhs0);
  sf_mex_destroy(&c22_rhs1);
  sf_mex_destroy(&c22_lhs1);
  sf_mex_destroy(&c22_rhs2);
  sf_mex_destroy(&c22_lhs2);
  sf_mex_destroy(&c22_rhs3);
  sf_mex_destroy(&c22_lhs3);
  sf_mex_destroy(&c22_rhs4);
  sf_mex_destroy(&c22_lhs4);
  sf_mex_destroy(&c22_rhs5);
  sf_mex_destroy(&c22_lhs5);
  sf_mex_destroy(&c22_rhs6);
  sf_mex_destroy(&c22_lhs6);
}

static const mxArray *c22_emlrt_marshallOut(const char * c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c22_u)), false);
  return c22_y;
}

static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 7, 0U, 0U, 0U, 0), false);
  return c22_y;
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc22_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_c_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i0, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc22_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_d_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_experiment_lib2, const
  char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_experiment_lib2), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_experiment_lib2);
  return c22_y;
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_experiment_lib2InstanceStruct
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

void sf_c22_experiment_lib2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1784658626U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1374250337U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(178987363U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(91049577U);
}

mxArray *sf_c22_experiment_lib2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XLXtQBaPguJOXr5bsjMvXC");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_experiment_lib2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_experiment_lib2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c22_experiment_lib2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"ialfa\",},{M[1],M[20],T\"ibeta\",},{M[8],M[0],T\"is_active_c22_experiment_lib2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_experiment_lib2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_experiment_lib2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_experiment_lib2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _experiment_lib2MachineNumber_,
           22,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"valfa");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ialfa");
          _SFD_SET_DATA_PROPS(2,1,1,0,"vbeta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"R");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ibeta");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,76);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);

        {
          real_T *c22_valfa;
          real_T *c22_ialfa;
          real_T *c22_vbeta;
          real_T *c22_R;
          real_T *c22_ibeta;
          c22_ibeta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c22_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c22_vbeta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c22_ialfa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c22_valfa = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_valfa);
          _SFD_SET_DATA_VALUE_PTR(1U, c22_ialfa);
          _SFD_SET_DATA_VALUE_PTR(2U, c22_vbeta);
          _SFD_SET_DATA_VALUE_PTR(3U, c22_R);
          _SFD_SET_DATA_VALUE_PTR(4U, c22_ibeta);
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
  return "O9KZ72JxM01wWXAKoaPopB";
}

static void sf_opaque_initialize_c22_experiment_lib2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
  initialize_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_experiment_lib2(void *chartInstanceVar)
{
  enable_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c22_experiment_lib2(void *chartInstanceVar)
{
  disable_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c22_experiment_lib2(void *chartInstanceVar)
{
  sf_gateway_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c22_experiment_lib2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_experiment_lib2
    ((SFc22_experiment_lib2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_experiment_lib2();/* state var info */
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

extern void sf_internal_set_sim_state_c22_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c22_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c22_experiment_lib2(SimStruct* S)
{
  return sf_internal_get_sim_state_c22_experiment_lib2(S);
}

static void sf_opaque_set_sim_state_c22_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c22_experiment_lib2(S, st);
}

static void sf_opaque_terminate_c22_experiment_lib2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_experiment_lib2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_experiment_lib2_optimization_info();
    }

    finalize_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
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
  initSimStructsc22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_experiment_lib2(SimStruct *S)
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
    initialize_params_c22_experiment_lib2((SFc22_experiment_lib2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_experiment_lib2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2275986366U));
  ssSetChecksum1(S,(2928135706U));
  ssSetChecksum2(S,(287263188U));
  ssSetChecksum3(S,(574059485U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_experiment_lib2(SimStruct *S)
{
  SFc22_experiment_lib2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_experiment_lib2InstanceStruct *)utMalloc(sizeof
    (SFc22_experiment_lib2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_experiment_lib2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c22_experiment_lib2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_experiment_lib2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c22_experiment_lib2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_experiment_lib2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_experiment_lib2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_experiment_lib2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_experiment_lib2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_experiment_lib2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_experiment_lib2;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_experiment_lib2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c22_experiment_lib2;
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

void c22_experiment_lib2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_experiment_lib2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_experiment_lib2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_experiment_lib2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_experiment_lib2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
