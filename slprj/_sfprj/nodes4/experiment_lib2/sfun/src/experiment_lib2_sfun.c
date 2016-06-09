/* Include files */

#include "experiment_lib2_sfun.h"
#include "experiment_lib2_sfun_debug_macros.h"
#include "c7_experiment_lib2.h"
#include "c9_experiment_lib2.h"
#include "c10_experiment_lib2.h"
#include "c11_experiment_lib2.h"
#include "c12_experiment_lib2.h"
#include "c13_experiment_lib2.h"
#include "c22_experiment_lib2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _experiment_lib2MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void experiment_lib2_initializer(void)
{
}

void experiment_lib2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_experiment_lib2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==7) {
    c7_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_experiment_lib2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_experiment_lib2_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"experiment_lib2")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1751156685U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1942681140U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(271131672U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(261980197U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 7:
            {
              extern void sf_c7_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c7_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 9:
            {
              extern void sf_c9_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c9_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 10:
            {
              extern void sf_c10_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c10_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 11:
            {
              extern void sf_c11_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c11_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 12:
            {
              extern void sf_c12_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c12_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 13:
            {
              extern void sf_c13_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c13_experiment_lib2_get_check_sum(plhs);
              break;
            }

           case 22:
            {
              extern void sf_c22_experiment_lib2_get_check_sum(mxArray *plhs[]);
              sf_c22_experiment_lib2_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_experiment_lib2_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 7:
      {
        if (strcmp(aiChksum, "LUAtSmig4cRJi41oiJFus") == 0) {
          extern mxArray *sf_c7_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c7_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "7uNZl71NFKsc09BO0EbhzF") == 0) {
          extern mxArray *sf_c9_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c9_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "VLIkn25zFK3tCGSDRd38TH") == 0) {
          extern mxArray *sf_c10_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c10_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "PgrRA2F70zquM2D7ROfGUG") == 0) {
          extern mxArray *sf_c11_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c11_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "0ApAAmvn4d6h3hKEF53xVD") == 0) {
          extern mxArray *sf_c12_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c12_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "0ApAAmvn4d6h3hKEF53xVD") == 0) {
          extern mxArray *sf_c13_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c13_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "XLXtQBaPguJOXr5bsjMvXC") == 0) {
          extern mxArray *sf_c22_experiment_lib2_get_autoinheritance_info(void);
          plhs[0] = sf_c22_experiment_lib2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_experiment_lib2_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 7:
      {
        extern const mxArray
          *sf_c7_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_experiment_lib2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_experiment_lib2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_experiment_lib2_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 7:
      {
        if (strcmp(tpChksum, "H9J4qoWTZO2QhtHIMEQP9E") == 0) {
          extern mxArray *sf_c7_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c7_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "GIJRXyg35F3lpUk5bmbq1") == 0) {
          extern mxArray *sf_c9_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c9_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "VuDhJI9ceM46u8P3kQa1ZF") == 0) {
          extern mxArray *sf_c10_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c10_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Lc5lgMkQf1Ilc1QHXaxNME") == 0) {
          extern mxArray *sf_c11_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c11_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "R8WV3rSBV4rW6i1bt11MyB") == 0) {
          extern mxArray *sf_c12_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c12_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "R8WV3rSBV4rW6i1bt11MyB") == 0) {
          extern mxArray *sf_c13_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c13_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "O9KZ72JxM01wWXAKoaPopB") == 0) {
          extern mxArray *sf_c22_experiment_lib2_third_party_uses_info(void);
          plhs[0] = sf_c22_experiment_lib2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_experiment_lib2_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 7:
      {
        if (strcmp(tpChksum, "H9J4qoWTZO2QhtHIMEQP9E") == 0) {
          extern mxArray *sf_c7_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "GIJRXyg35F3lpUk5bmbq1") == 0) {
          extern mxArray *sf_c9_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "VuDhJI9ceM46u8P3kQa1ZF") == 0) {
          extern mxArray *sf_c10_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Lc5lgMkQf1Ilc1QHXaxNME") == 0) {
          extern mxArray *sf_c11_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "R8WV3rSBV4rW6i1bt11MyB") == 0) {
          extern mxArray *sf_c12_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "R8WV3rSBV4rW6i1bt11MyB") == 0) {
          extern mxArray *sf_c13_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "O9KZ72JxM01wWXAKoaPopB") == 0) {
          extern mxArray *sf_c22_experiment_lib2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_experiment_lib2_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void experiment_lib2_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _experiment_lib2MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "experiment_lib2","sfun",1,7,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _experiment_lib2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _experiment_lib2MachineNumber_,0);
}

void experiment_lib2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_experiment_lib2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("experiment_lib2",
      "nodes4");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_experiment_lib2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
