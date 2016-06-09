#include "__cf_nodes4.h"
#ifndef RTW_HEADER_nodes4_private_h_
#define RTW_HEADER_nodes4_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef UCHAR_MAX
#include <limits.h>
#endif
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif
#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif
#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif
#if 0
#if ( ULONG_MAX != (0xFFFFFFFFFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFFFFFFFFFL) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif
#endif
#if 0
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFUL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFL) )
#error "Code was generated for compiler with different sized ulong_long/long_long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif
#endif
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif
extern real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) ; extern void ttkernelMATLAB ( SimStruct *
rts ) ; extern void ttnetwork ( SimStruct * rts ) ; extern void e1ux3zzmti (
nd455pykna * localDW ) ; extern void onerdwipjp ( real_T ftvqqnmjes , real_T
movojndwwy , cq33sumodo * localB , nd455pykna * localDW , n1y0minqnv * localP
) ; extern void kpi03nmwlh ( const real_T ia53et2zmy [ 4 ] , real_T
cnqnja1cvu , mjvusmhnt4 * localB , drnct5ly2o * localP ) ; extern void
kjaxztqeed ( const real_T mh1dxhbrfm [ 4 ] , real_T kr3sjenk15 , lxgqip2r3j *
localB , ewvp3cxhdz * localP ) ; extern void h4j3c4exvj ( const real_T
che20jmnsq [ 4 ] , real_T dhq1cyd0eq , ai0etet4ec * localB , ndkw5mnz3z *
localP ) ; extern void akzc515hdq ( const real_T j5dvrlnda0 [ 4 ] , real_T
iniuk4qaft , m0q1lbf303 * localB , nbb0zpvvhm * localP ) ; extern void
jtbhfmltwq ( const real_T b114fmir4d [ 4 ] , real_T hytbtazndq , jojddljsvc *
localB , ozv2axw2sw * localP ) ; extern void ait2csy21y ( freptvnt4s *
localDW ) ; extern void o3zilu53kc ( real_T bwxjuvtnnx , real_T dpg4kt2y5y ,
real_T kxdfg2miwh , real_T kc0wy2r5y5 , real_T gb1cduktq3 , real_T f3otagz1zj
, real_T amncivy1n5 , kfdidjbyrv * localB , freptvnt4s * localDW , m5tur4wi4k
* localP ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
