/* Include files */

#include <stddef.h>
#include "blas.h"
#include "experiment_lib2_sfun.h"
#include "c12_experiment_lib2.h"
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
static const char * c12_debug_family_names[6] = { "nargin", "nargout", "x",
  "val", "a", "out" };

/* Function Declarations */
static void initialize_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance);
static void initialize_params_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance);
static void enable_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance);
static void disable_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance);
static void set_sim_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance, const mxArray *c12_st);
static void finalize_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance);
static void sf_gateway_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance);
static void initSimStructsc12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_out, const char_T *c12_identifier, real_T
  c12_y[4]);
static void c12_b_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  real_T c12_y[4]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_c_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_d_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_e_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_experiment_lib2, const
  char_T *c12_identifier);
static uint8_T c12_f_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_experiment_lib2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_is_active_c12_experiment_lib2 = 0U;
}

static void initialize_params_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance)
{
  real_T c12_d0;
  sf_mex_import_named("a", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c12_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c12_a = c12_d0;
}

static void enable_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  real_T c12_u[4];
  const mxArray *c12_b_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T (*c12_out)[4];
  c12_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(2, 1), false);
  for (c12_i0 = 0; c12_i0 < 4; c12_i0++) {
    c12_u[c12_i0] = (*c12_out)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_hoistedGlobal = chartInstance->c12_is_active_c12_experiment_lib2;
  c12_b_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv0[4];
  int32_T c12_i1;
  real_T (*c12_out)[4];
  c12_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)),
                       "out", c12_dv0);
  for (c12_i1 = 0; c12_i1 < 4; c12_i1++) {
    (*c12_out)[c12_i1] = c12_dv0[c12_i1];
  }

  chartInstance->c12_is_active_c12_experiment_lib2 = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
     "is_active_c12_experiment_lib2");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_experiment_lib2(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c12_experiment_lib2(SFc12_experiment_lib2InstanceStruct
  *chartInstance)
{
  int32_T c12_i2;
  real_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  int32_T c12_i3;
  real_T c12_x[4];
  real_T c12_val;
  real_T c12_b_a;
  uint32_T c12_debug_family_var_map[6];
  real_T c12_nargin = 3.0;
  real_T c12_nargout = 1.0;
  real_T c12_out[4];
  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_i6;
  real_T *c12_b_val;
  real_T (*c12_b_out)[4];
  real_T (*c12_b_x)[4];
  c12_b_val = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_b_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  for (c12_i2 = 0; c12_i2 < 4; c12_i2++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_x)[c12_i2], 0U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_val;
  c12_b_hoistedGlobal = chartInstance->c12_a;
  for (c12_i3 = 0; c12_i3 < 4; c12_i3++) {
    c12_x[c12_i3] = (*c12_b_x)[c12_i3];
  }

  c12_val = c12_hoistedGlobal;
  c12_b_a = c12_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_x, 2U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_val, 3U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_a, 4U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_out, 5U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 2);
  for (c12_i4 = 0; c12_i4 < 4; c12_i4++) {
    c12_out[c12_i4] = c12_x[c12_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  c12_out[_SFD_EML_ARRAY_BOUNDS_CHECK("out", (int32_T)_SFD_INTEGER_CHECK("a",
    c12_b_a), 1, 4, 1, 0) - 1] = c12_val;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c12_i5 = 0; c12_i5 < 4; c12_i5++) {
    (*c12_b_out)[c12_i5] = c12_out[c12_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_experiment_lib2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c12_i6 = 0; c12_i6 < 4; c12_i6++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_out)[c12_i6], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c12_b_val, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_a, 3U);
}

static void initSimStructsc12_experiment_lib2
  (SFc12_experiment_lib2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i7;
  real_T c12_b_inData[4];
  int32_T c12_i8;
  real_T c12_u[4];
  const mxArray *c12_y = NULL;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i7 = 0; c12_i7 < 4; c12_i7++) {
    c12_b_inData[c12_i7] = (*(real_T (*)[4])c12_inData)[c12_i7];
  }

  for (c12_i8 = 0; c12_i8 < 4; c12_i8++) {
    c12_u[c12_i8] = c12_b_inData[c12_i8];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_out, const char_T *c12_identifier, real_T
  c12_y[4])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_out), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_out);
}

static void c12_b_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  real_T c12_y[4])
{
  real_T c12_dv1[4];
  int32_T c12_i9;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c12_i9 = 0; c12_i9 < 4; c12_i9++) {
    c12_y[c12_i9] = c12_dv1[c12_i9];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_out;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[4];
  int32_T c12_i10;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_out = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_out), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_out);
  for (c12_i10 = 0; c12_i10 < 4; c12_i10++) {
    (*(real_T (*)[4])c12_outData)[c12_i10] = c12_y[c12_i10];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_c_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d1;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d1, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_a;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_b_a = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_a), &c12_thisId);
  sf_mex_destroy(&c12_b_a);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_experiment_lib2_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_d_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i11;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i11, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i11;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_experiment_lib2, const
  char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_experiment_lib2), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_experiment_lib2);
  return c12_y;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_experiment_lib2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_experiment_lib2InstanceStruct
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

void sf_c12_experiment_lib2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3546657856U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(217512103U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2855096593U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3953762781U);
}

mxArray *sf_c12_experiment_lib2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0ApAAmvn4d6h3hKEF53xVD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

mxArray *sf_c12_experiment_lib2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_experiment_lib2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c12_experiment_lib2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c12_experiment_lib2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_experiment_lib2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_experiment_lib2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_experiment_lib2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _experiment_lib2MachineNumber_,
           12,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"val");
          _SFD_SET_DATA_PROPS(3,10,0,0,"a");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,50);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)
            c12_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);

        {
          real_T *c12_val;
          real_T (*c12_x)[4];
          real_T (*c12_out)[4];
          c12_val = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c12_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_val);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c12_a);
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
  return "R8WV3rSBV4rW6i1bt11MyB";
}

static void sf_opaque_initialize_c12_experiment_lib2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
  initialize_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_experiment_lib2(void *chartInstanceVar)
{
  enable_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c12_experiment_lib2(void *chartInstanceVar)
{
  disable_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_experiment_lib2(void *chartInstanceVar)
{
  sf_gateway_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_experiment_lib2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_experiment_lib2
    ((SFc12_experiment_lib2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_experiment_lib2();/* state var info */
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

extern void sf_internal_set_sim_state_c12_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c12_experiment_lib2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_experiment_lib2(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_experiment_lib2(S);
}

static void sf_opaque_set_sim_state_c12_experiment_lib2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_experiment_lib2(S, st);
}

static void sf_opaque_terminate_c12_experiment_lib2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_experiment_lib2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_experiment_lib2_optimization_info();
    }

    finalize_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
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
  initSimStructsc12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_experiment_lib2(SimStruct *S)
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
    initialize_params_c12_experiment_lib2((SFc12_experiment_lib2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_experiment_lib2(SimStruct *S)
{
  /* Actual parameters from chart:
     a
   */
  const char_T *rtParamNames[] = { "a" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for a*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_experiment_lib2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4184006935U));
  ssSetChecksum1(S,(63019893U));
  ssSetChecksum2(S,(3472704211U));
  ssSetChecksum3(S,(194741901U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_experiment_lib2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_experiment_lib2(SimStruct *S)
{
  SFc12_experiment_lib2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_experiment_lib2InstanceStruct *)utMalloc(sizeof
    (SFc12_experiment_lib2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_experiment_lib2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_experiment_lib2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_experiment_lib2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_experiment_lib2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_experiment_lib2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_experiment_lib2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_experiment_lib2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_experiment_lib2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_experiment_lib2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_experiment_lib2;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_experiment_lib2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_experiment_lib2;
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

void c12_experiment_lib2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_experiment_lib2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_experiment_lib2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_experiment_lib2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_experiment_lib2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
