#include "__cf_nodes4.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "nodes4_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  15
#endif
#ifndef SS_UINT64
#define SS_UINT64  16
#endif
#else
#include "builtin_typeid_types.h"
#include "nodes4.h"
#include "nodes4_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"nodes4/Control/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "nodes4/Control/Data Store Read" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"nodes4/Control/Data Store Read1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
0 } , { 3 , 0 , TARGET_STRING ( "nodes4/Control/Data Store Read2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"nodes4/Control/Data Store Read3" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
0 } , { 5 , 0 , TARGET_STRING ( "nodes4/Control/Data Store Read4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"nodes4/Control/Data Store Read5" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
0 } , { 7 , 0 , TARGET_STRING ( "nodes4/L4/Memory1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING ( "nodes4/L4/Memory2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"nodes4/TrueTime Network1/ttnetwork" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0
, 1 } , { 10 , 0 , TARGET_STRING ( "nodes4/TrueTime Network1/ttnetwork" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 2 , 0 , 1 } , { 11 , 4 , TARGET_STRING (
"nodes4/g1/integratorcontrol" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 }
, { 12 , 11 , TARGET_STRING ( "nodes4/g1/primary control (droop + Zv)" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 13 , 11 , TARGET_STRING (
"nodes4/g1/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 1 , 0 , 0
, 0 , 2 } , { 14 , 11 , TARGET_STRING (
"nodes4/g1/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 2 , 0 , 0
, 0 , 2 } , { 15 , 0 , TARGET_STRING ( "nodes4/g1/Central_Integral" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"nodes4/g1/Degenerated" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 17
, 0 , TARGET_STRING ( "nodes4/g1/Distributed_integral" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 2 } , { 18 , 0 , TARGET_STRING (
"nodes4/g1/Distributed_integral_w" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 19 , 0 , TARGET_STRING ( "nodes4/g1/Memory1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING ( "nodes4/g1/Memory2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"nodes4/g1/Memory3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0
, TARGET_STRING ( "nodes4/g1/Memory4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 23 , 0 , TARGET_STRING ( "nodes4/g1/Memory5" ) , TARGET_STRING (
"" ) , 0 , 0 , 3 , 0 , 1 } , { 24 , 0 , TARGET_STRING ( "nodes4/g1/Memory6" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"nodes4/g1/Memory7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 26 , 0
, TARGET_STRING ( "nodes4/g1/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 27 , 0 , TARGET_STRING ( "nodes4/g1/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 0 } , { 28 , 0 , TARGET_STRING ( "nodes4/g1/LPF p" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 29 , 0 , TARGET_STRING (
"nodes4/g1/LPF q" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 30 , 14
, TARGET_STRING ( "nodes4/g2/integratorcontrol" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 2 } , { 31 , 21 , TARGET_STRING (
"nodes4/g2/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 32 , 21 , TARGET_STRING (
"nodes4/g2/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 1 , 0 , 0
, 0 , 2 } , { 33 , 21 , TARGET_STRING (
"nodes4/g2/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 2 , 0 , 0
, 0 , 2 } , { 34 , 0 , TARGET_STRING ( "nodes4/g2/Central_Integral" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"nodes4/g2/Degenerated" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 36
, 0 , TARGET_STRING ( "nodes4/g2/Distributed_integral" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 2 } , { 37 , 0 , TARGET_STRING (
"nodes4/g2/Distributed_integral_w" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 38 , 0 , TARGET_STRING ( "nodes4/g2/Memory1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 39 , 0 , TARGET_STRING ( "nodes4/g2/Memory2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"nodes4/g2/Memory3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 41 , 0
, TARGET_STRING ( "nodes4/g2/Memory4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 42 , 0 , TARGET_STRING ( "nodes4/g2/Memory5" ) , TARGET_STRING (
"" ) , 0 , 0 , 3 , 0 , 1 } , { 43 , 0 , TARGET_STRING ( "nodes4/g2/Memory6" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 44 , 0 , TARGET_STRING (
"nodes4/g2/Memory7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 45 , 0
, TARGET_STRING ( "nodes4/g2/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 46 , 0 , TARGET_STRING ( "nodes4/g2/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 0 } , { 47 , 0 , TARGET_STRING ( "nodes4/g2/LPF p" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 48 , 0 , TARGET_STRING (
"nodes4/g2/LPF q" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 49 , 24
, TARGET_STRING ( "nodes4/g3/integratorcontrol" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 2 } , { 50 , 31 , TARGET_STRING (
"nodes4/g3/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 51 , 31 , TARGET_STRING (
"nodes4/g3/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 1 , 0 , 0
, 0 , 2 } , { 52 , 31 , TARGET_STRING (
"nodes4/g3/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 2 , 0 , 0
, 0 , 2 } , { 53 , 0 , TARGET_STRING ( "nodes4/g3/Central_Integral" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"nodes4/g3/Degenerated" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 55
, 0 , TARGET_STRING ( "nodes4/g3/Distributed_integral" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 2 } , { 56 , 0 , TARGET_STRING (
"nodes4/g3/Distributed_integral_w" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 57 , 0 , TARGET_STRING ( "nodes4/g3/Memory1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 58 , 0 , TARGET_STRING ( "nodes4/g3/Memory2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"nodes4/g3/Memory3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 60 , 0
, TARGET_STRING ( "nodes4/g3/Memory4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 61 , 0 , TARGET_STRING ( "nodes4/g3/Memory5" ) , TARGET_STRING (
"" ) , 0 , 0 , 3 , 0 , 1 } , { 62 , 0 , TARGET_STRING ( "nodes4/g3/Memory6" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 63 , 0 , TARGET_STRING (
"nodes4/g3/Memory7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 64 , 0
, TARGET_STRING ( "nodes4/g3/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 65 , 0 , TARGET_STRING ( "nodes4/g3/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 0 } , { 66 , 0 , TARGET_STRING ( "nodes4/g3/LPF p" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 67 , 0 , TARGET_STRING (
"nodes4/g3/LPF q" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 68 , 34
, TARGET_STRING ( "nodes4/g4/integratorcontrol" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 2 } , { 69 , 41 , TARGET_STRING (
"nodes4/g4/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 70 , 41 , TARGET_STRING (
"nodes4/g4/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 1 , 0 , 0
, 0 , 2 } , { 71 , 41 , TARGET_STRING (
"nodes4/g4/primary control (droop + Zv)" ) , TARGET_STRING ( "" ) , 2 , 0 , 0
, 0 , 2 } , { 72 , 0 , TARGET_STRING ( "nodes4/g4/Central_Integral" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 73 , 0 , TARGET_STRING (
"nodes4/g4/Degenerated" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 74
, 0 , TARGET_STRING ( "nodes4/g4/Distributed_integral" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 2 } , { 75 , 0 , TARGET_STRING (
"nodes4/g4/Distributed_integral_w" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 76 , 0 , TARGET_STRING ( "nodes4/g4/Memory1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 77 , 0 , TARGET_STRING ( "nodes4/g4/Memory2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 78 , 0 , TARGET_STRING (
"nodes4/g4/Memory3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 79 , 0
, TARGET_STRING ( "nodes4/g4/Memory4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 80 , 0 , TARGET_STRING ( "nodes4/g4/Memory5" ) , TARGET_STRING (
"" ) , 0 , 0 , 3 , 0 , 1 } , { 81 , 0 , TARGET_STRING ( "nodes4/g4/Memory6" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 82 , 0 , TARGET_STRING (
"nodes4/g4/Memory7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 83 , 0
, TARGET_STRING ( "nodes4/g4/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 84 , 0 , TARGET_STRING ( "nodes4/g4/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 3 , 0 , 0 } , { 85 , 0 , TARGET_STRING ( "nodes4/g4/LPF p" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 86 , 0 , TARGET_STRING (
"nodes4/g4/LPF q" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 87 , 0 ,
TARGET_STRING ( "nodes4/L4/va/do not delete this gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 88 , 0 , TARGET_STRING (
"nodes4/L4/vb/do not delete this gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 89 , 0 , TARGET_STRING ( "nodes4/MCC/control secundario/Gain1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 90 , 0 , TARGET_STRING (
"nodes4/MCC/control secundario/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 91 , 0 , TARGET_STRING ( "nodes4/g1/TrueTime Kernel/ttkernel" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 92 , 0 , TARGET_STRING (
"nodes4/g1/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0
, 1 } , { 93 , 0 , TARGET_STRING ( "nodes4/g1/TrueTime Kernel/ttkernel" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 94 , 0 , TARGET_STRING (
"nodes4/g1/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0
, 1 } , { 95 , 0 , TARGET_STRING ( "nodes4/g1/TrueTime Kernel1/ttkernel" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 96 , 0 , TARGET_STRING (
"nodes4/g1/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 ,
0 , 1 } , { 97 , 0 , TARGET_STRING ( "nodes4/g1/TrueTime Kernel1/ttkernel" )
, TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 98 , 0 , TARGET_STRING (
"nodes4/g1/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 ,
0 , 1 } , { 99 , 0 , TARGET_STRING ( "nodes4/g1/control secundario1/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 100 , 0 , TARGET_STRING (
"nodes4/g1/control secundario1/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 101 , 0 , TARGET_STRING ( "nodes4/g1/control secundario1/Gain2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 102 , 0 , TARGET_STRING (
"nodes4/g1/control secundario1/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 103 , 0 , TARGET_STRING ( "nodes4/g1/control secundario1/Gain4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 104 , 0 , TARGET_STRING (
"nodes4/g1/control secundario1/Gain5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 105 , 5 , TARGET_STRING ( "nodes4/g1/measures/replacer1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 106 , 6 , TARGET_STRING (
"nodes4/g1/measures/replacer2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 107 , 7 , TARGET_STRING ( "nodes4/g1/measures/replacer3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 108 , 8 , TARGET_STRING (
"nodes4/g1/measures/replacer4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 109 , 9 , TARGET_STRING ( "nodes4/g1/measures/replacer5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 110 , 10 , TARGET_STRING (
"nodes4/g1/measures/replacer6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 111 , 0 , TARGET_STRING ( "nodes4/g1/measures/Data Store Read1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 112 , 0 , TARGET_STRING (
"nodes4/g1/measures/Data Store Read2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 113 , 0 , TARGET_STRING ( "nodes4/g1/measures/Data Store Read3" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 114 , 0 , TARGET_STRING (
"nodes4/g1/measures/Data Store Read4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 115 , 0 , TARGET_STRING ( "nodes4/g1/measures/Data Store Read5" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 116 , 0 , TARGET_STRING (
"nodes4/g1/measures/Data Store Read6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 117 , 0 , TARGET_STRING ( "nodes4/g2/TrueTime Kernel/ttkernel" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 118 , 0 , TARGET_STRING (
"nodes4/g2/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0
, 1 } , { 119 , 0 , TARGET_STRING ( "nodes4/g2/TrueTime Kernel/ttkernel" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 120 , 0 , TARGET_STRING (
"nodes4/g2/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0
, 1 } , { 121 , 0 , TARGET_STRING ( "nodes4/g2/TrueTime Kernel1/ttkernel" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 122 , 0 , TARGET_STRING (
"nodes4/g2/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 ,
0 , 1 } , { 123 , 0 , TARGET_STRING ( "nodes4/g2/TrueTime Kernel1/ttkernel" )
, TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 124 , 0 , TARGET_STRING (
"nodes4/g2/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 ,
0 , 1 } , { 125 , 0 , TARGET_STRING ( "nodes4/g2/control secundario1/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 126 , 0 , TARGET_STRING (
"nodes4/g2/control secundario1/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 127 , 0 , TARGET_STRING ( "nodes4/g2/control secundario1/Gain2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 128 , 0 , TARGET_STRING (
"nodes4/g2/control secundario1/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 129 , 0 , TARGET_STRING ( "nodes4/g2/control secundario1/Gain4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 130 , 0 , TARGET_STRING (
"nodes4/g2/control secundario1/Gain5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 131 , 15 , TARGET_STRING ( "nodes4/g2/measures/replacer1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 132 , 16 , TARGET_STRING (
"nodes4/g2/measures/replacer2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 133 , 17 , TARGET_STRING ( "nodes4/g2/measures/replacer3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 134 , 18 , TARGET_STRING (
"nodes4/g2/measures/replacer4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 135 , 19 , TARGET_STRING ( "nodes4/g2/measures/replacer5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 136 , 20 , TARGET_STRING (
"nodes4/g2/measures/replacer6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 137 , 0 , TARGET_STRING ( "nodes4/g2/measures/Data Store Read1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 138 , 0 , TARGET_STRING (
"nodes4/g2/measures/Data Store Read2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 139 , 0 , TARGET_STRING ( "nodes4/g2/measures/Data Store Read3" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 140 , 0 , TARGET_STRING (
"nodes4/g2/measures/Data Store Read4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 141 , 0 , TARGET_STRING ( "nodes4/g2/measures/Data Store Read5" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 142 , 0 , TARGET_STRING (
"nodes4/g2/measures/Data Store Read6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 143 , 0 , TARGET_STRING ( "nodes4/g3/TrueTime Kernel/ttkernel" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 144 , 0 , TARGET_STRING (
"nodes4/g3/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0
, 1 } , { 145 , 0 , TARGET_STRING ( "nodes4/g3/TrueTime Kernel/ttkernel" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 146 , 0 , TARGET_STRING (
"nodes4/g3/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0
, 1 } , { 147 , 0 , TARGET_STRING ( "nodes4/g3/TrueTime Kernel1/ttkernel" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 148 , 0 , TARGET_STRING (
"nodes4/g3/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 ,
0 , 1 } , { 149 , 0 , TARGET_STRING ( "nodes4/g3/TrueTime Kernel1/ttkernel" )
, TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 150 , 0 , TARGET_STRING (
"nodes4/g3/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 ,
0 , 1 } , { 151 , 0 , TARGET_STRING ( "nodes4/g3/control secundario1/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 152 , 0 , TARGET_STRING (
"nodes4/g3/control secundario1/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 153 , 0 , TARGET_STRING ( "nodes4/g3/control secundario1/Gain2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 154 , 0 , TARGET_STRING (
"nodes4/g3/control secundario1/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 155 , 0 , TARGET_STRING ( "nodes4/g3/control secundario1/Gain4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 156 , 0 , TARGET_STRING (
"nodes4/g3/control secundario1/Gain5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 157 , 25 , TARGET_STRING ( "nodes4/g3/measures/replacer1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 158 , 26 , TARGET_STRING (
"nodes4/g3/measures/replacer2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 159 , 27 , TARGET_STRING ( "nodes4/g3/measures/replacer3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 160 , 28 , TARGET_STRING (
"nodes4/g3/measures/replacer4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 161 , 29 , TARGET_STRING ( "nodes4/g3/measures/replacer5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 162 , 30 , TARGET_STRING (
"nodes4/g3/measures/replacer6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 163 , 0 , TARGET_STRING ( "nodes4/g3/measures/Data Store Read1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 164 , 0 , TARGET_STRING (
"nodes4/g3/measures/Data Store Read2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 165 , 0 , TARGET_STRING ( "nodes4/g3/measures/Data Store Read3" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 166 , 0 , TARGET_STRING (
"nodes4/g3/measures/Data Store Read4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 167 , 0 , TARGET_STRING ( "nodes4/g3/measures/Data Store Read5" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 168 , 0 , TARGET_STRING (
"nodes4/g3/measures/Data Store Read6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 169 , 0 , TARGET_STRING ( "nodes4/g4/TrueTime Kernel/ttkernel" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 170 , 0 , TARGET_STRING (
"nodes4/g4/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0
, 1 } , { 171 , 0 , TARGET_STRING ( "nodes4/g4/TrueTime Kernel/ttkernel" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 172 , 0 , TARGET_STRING (
"nodes4/g4/TrueTime Kernel/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0
, 1 } , { 173 , 0 , TARGET_STRING ( "nodes4/g4/TrueTime Kernel1/ttkernel" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 174 , 0 , TARGET_STRING (
"nodes4/g4/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 ,
0 , 1 } , { 175 , 0 , TARGET_STRING ( "nodes4/g4/TrueTime Kernel1/ttkernel" )
, TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 176 , 0 , TARGET_STRING (
"nodes4/g4/TrueTime Kernel1/ttkernel" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 ,
0 , 1 } , { 177 , 0 , TARGET_STRING ( "nodes4/g4/control secundario1/Gain" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 178 , 0 , TARGET_STRING (
"nodes4/g4/control secundario1/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 179 , 0 , TARGET_STRING ( "nodes4/g4/control secundario1/Gain2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 180 , 0 , TARGET_STRING (
"nodes4/g4/control secundario1/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 181 , 0 , TARGET_STRING ( "nodes4/g4/control secundario1/Gain4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 182 , 0 , TARGET_STRING (
"nodes4/g4/control secundario1/Gain5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 183 , 35 , TARGET_STRING ( "nodes4/g4/measures/replacer1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 184 , 36 , TARGET_STRING (
"nodes4/g4/measures/replacer2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 185 , 37 , TARGET_STRING ( "nodes4/g4/measures/replacer3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 186 , 38 , TARGET_STRING (
"nodes4/g4/measures/replacer4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 187 , 39 , TARGET_STRING ( "nodes4/g4/measures/replacer5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 188 , 40 , TARGET_STRING (
"nodes4/g4/measures/replacer6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 }
, { 189 , 0 , TARGET_STRING ( "nodes4/g4/measures/Data Store Read1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 190 , 0 , TARGET_STRING (
"nodes4/g4/measures/Data Store Read2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 191 , 0 , TARGET_STRING ( "nodes4/g4/measures/Data Store Read3" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 192 , 0 , TARGET_STRING (
"nodes4/g4/measures/Data Store Read4" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 193 , 0 , TARGET_STRING ( "nodes4/g4/measures/Data Store Read5" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 194 , 0 , TARGET_STRING (
"nodes4/g4/measures/Data Store Read6" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 0 } , { 195 , 0 , TARGET_STRING (
"nodes4/g1/generator/ialpha/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 196 , 0 , TARGET_STRING (
"nodes4/g1/generator/ibeta/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 197 , 0 , TARGET_STRING (
"nodes4/g2/generator/ialpha/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 198 , 0 , TARGET_STRING (
"nodes4/g2/generator/ibeta/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 199 , 0 , TARGET_STRING (
"nodes4/g3/generator/ialpha/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 200 , 0 , TARGET_STRING (
"nodes4/g3/generator/ibeta/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 201 , 0 , TARGET_STRING (
"nodes4/g4/generator/ialpha/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 202 , 0 , TARGET_STRING (
"nodes4/g4/generator/ibeta/do not delete this gain" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } }
;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lc3tl5isia , & rtB . clfpixb40s [
0 ] , & rtB . fl0i4sb4vv [ 0 ] , & rtB . gmhqlr0ded [ 0 ] , & rtB .
carjwykir1 [ 0 ] , & rtB . caywsc2yvv [ 0 ] , & rtB . eyrg550icf [ 0 ] , &
rtB . ec4ppad44q , & rtB . awk2wo0fe2 , & rtB . ktweuvg11j [ 0 ] , & rtB .
gcnh1cojbn [ 0 ] , & rtB . pxlv2lf0yq . ioo1a4zpmx [ 0 ] , & rtB . a21clfzxwp
. n0fuel1bnn , & rtB . a21clfzxwp . dberndtk2w , & rtB . a21clfzxwp .
on2dguwvvl , & rtB . ctf1kxqmdo [ 0 ] , & rtB . l523yuyruu [ 0 ] , & rtB .
f5aj101k3a [ 0 ] , & rtB . krez0hg5v1 , & rtB . hx0wj5yo2m , & rtB .
kcng2h2ox5 , & rtB . pdvnbdhjm2 , & rtB . mj22h2mmx5 , & rtB . kdglpydeda [ 0
] , & rtB . d4jrh0gj3t , & rtB . nhbi4wyipn , & rtB . pgkimqavpk , & rtB .
lgfjmq2ecm [ 0 ] , & rtB . hen0mtsi3a , & rtB . mfwsny1flw , & rtB .
jwxitznkuq . ioo1a4zpmx [ 0 ] , & rtB . cwkcdvwsyb . n0fuel1bnn , & rtB .
cwkcdvwsyb . dberndtk2w , & rtB . cwkcdvwsyb . on2dguwvvl , & rtB .
dbqcdqyhwy [ 0 ] , & rtB . n10inqqacb [ 0 ] , & rtB . pugsu0nevr [ 0 ] , &
rtB . enmfzw4wn5 , & rtB . pazkwcssox , & rtB . brmhwzxuee , & rtB .
fpqii21x5i , & rtB . ek0x1ax1lz , & rtB . lzsvpxojnz [ 0 ] , & rtB .
g4tkowhewi , & rtB . j52dskeymb , & rtB . c02zl0czxs , & rtB . na2ttkkmwd [ 0
] , & rtB . eoyd4uc25o , & rtB . n2mcguhbur , & rtB . dvrqjotubu . ioo1a4zpmx
[ 0 ] , & rtB . avezulewcn . n0fuel1bnn , & rtB . avezulewcn . dberndtk2w , &
rtB . avezulewcn . on2dguwvvl , & rtB . aee3tydqqe [ 0 ] , & rtB . p4eyqrx5tw
[ 0 ] , & rtB . o4komacgjl [ 0 ] , & rtB . kknf5smhy4 , & rtB . b3buxfo0jq ,
& rtB . m4ofszhbm4 , & rtB . gdvqwx5p4u , & rtB . g03umd0jya , & rtB .
ozch1m2xun [ 0 ] , & rtB . b30gw04tpb , & rtB . irpgyparai , & rtB .
l2ny1ho3uf , & rtB . blvbd5kgbi [ 0 ] , & rtB . oqxkfo2dq5 , & rtB .
do20asbnvu , & rtB . j20pq3r21f . ioo1a4zpmx [ 0 ] , & rtB . ozftnlfeg3 .
n0fuel1bnn , & rtB . ozftnlfeg3 . dberndtk2w , & rtB . ozftnlfeg3 .
on2dguwvvl , & rtB . d2kvmgvdht [ 0 ] , & rtB . ibl2erstls [ 0 ] , & rtB .
m1vu1obgik [ 0 ] , & rtB . dti2carlq5 , & rtB . fntkhkkhap , & rtB .
biin3vhjc0 , & rtB . fypbjuyz3n , & rtB . mco3v3iige , & rtB . fchnjsvgwh [ 0
] , & rtB . kkx4ezyhkw , & rtB . mpyof2qigx , & rtB . okzfmxk5yy , & rtB .
mguxqfcdvk [ 0 ] , & rtB . iewvn51hd3 , & rtB . hbtkhijkte , & rtB .
pnwecd2kft , & rtB . gej5khtvm2 , & rtB . fo5rqi15o1 , & rtB . f2q5magsot , &
rtB . ellko3pdhd , & rtB . e4hzm4gatj , & rtB . podole3fca , & rtB .
lhfof1cyys , & rtB . n2zlvavzvj [ 0 ] , & rtB . lvxcghiadw , & rtB .
iz5ulgunhl , & rtB . falp0kne2f , & rtB . kkm103ywxt , & rtB . lxk0xwc3vx , &
rtB . e1nfog11ri , & rtB . hkkbhcvcxm , & rtB . d535qgtjbe , & rtB .
lmpvvsgbzc , & rtB . i0nb5cbdli . ovjujdzpjt [ 0 ] , & rtB . mfw2ixjjzd .
bbcbwrpqmg [ 0 ] , & rtB . n3la5yge0s . c03pdi1rvc [ 0 ] , & rtB . lkguggosm5
. mesgqmrxmy [ 0 ] , & rtB . ae0vvuvpaf . hgxfgflt2m [ 0 ] , & rtB .
loojatj1b3 . hgxfgflt2m [ 0 ] , & rtB . aczh1lvgar [ 0 ] , & rtB . dzuta0dnpn
[ 0 ] , & rtB . cbfpuf2or0 [ 0 ] , & rtB . abwh33q232 [ 0 ] , & rtB .
b4slefd2sz [ 0 ] , & rtB . i52hyrlq2j [ 0 ] , & rtB . nastbsm32g , & rtB .
nxnoiv0pth , & rtB . au5g3iyahf , & rtB . ffbtpjovm2 , & rtB . iodvmyfik4 [ 0
] , & rtB . fobyeqif54 , & rtB . iftyjztmep , & rtB . cyfk1qotlx , & rtB .
bw14bin5hh , & rtB . cawwajqazb , & rtB . ldw4br50ng , & rtB . d1h14ldyu4 , &
rtB . gsofcjddvn , & rtB . cs2wisepbp , & rtB . mrc3jz2kzs . ovjujdzpjt [ 0 ]
, & rtB . pxgmr2o0yw . bbcbwrpqmg [ 0 ] , & rtB . ejkqkpkoqg . c03pdi1rvc [ 0
] , & rtB . omwjydko3j . mesgqmrxmy [ 0 ] , & rtB . pmll2wrcy3 . hgxfgflt2m [
0 ] , & rtB . gpr5ewbwvu . hgxfgflt2m [ 0 ] , & rtB . fg3wll3qdz [ 0 ] , &
rtB . keuugvf2im [ 0 ] , & rtB . as33t0f0ow [ 0 ] , & rtB . meko05j0sc [ 0 ]
, & rtB . lhj2ghm2f4 [ 0 ] , & rtB . eux2brobbv [ 0 ] , & rtB . dzlnvksxlk ,
& rtB . iy2ry2qx1u , & rtB . jw5211g3vm , & rtB . ctjaojcbjq , & rtB .
dnqnzblmbp [ 0 ] , & rtB . cwaxgcfgm2 , & rtB . of4z3nxnpu , & rtB .
mpet5fjgog , & rtB . h4tgjphw5q , & rtB . oues2lcti4 , & rtB . ldmwux2zhx , &
rtB . eelx0pksev , & rtB . kms2jmv2td , & rtB . lg5rqpaf2e , & rtB .
ipvzgutla1 . ovjujdzpjt [ 0 ] , & rtB . mmnlogmmqe . bbcbwrpqmg [ 0 ] , & rtB
. pcljl3fmii . c03pdi1rvc [ 0 ] , & rtB . l1cumv5mxc . mesgqmrxmy [ 0 ] , &
rtB . p0jpb31wlq . hgxfgflt2m [ 0 ] , & rtB . k04lp2vsfm . hgxfgflt2m [ 0 ] ,
& rtB . p0z5ebkftq [ 0 ] , & rtB . fsr4klu2iw [ 0 ] , & rtB . nyh5uqpipi [ 0
] , & rtB . p1j2mjcnmh [ 0 ] , & rtB . a2j3heg5ll [ 0 ] , & rtB . hjgncjfz4l
[ 0 ] , & rtB . bxyd4fbh0g , & rtB . pijde51qab , & rtB . gehrrnez0b , & rtB
. dwdpwj5pni , & rtB . dpgwwjc2rz [ 0 ] , & rtB . kycfwls143 , & rtB .
ee5gbg0io5 , & rtB . avlxjfrevq , & rtB . kcbmknce0k , & rtB . h1tgqdz5v2 , &
rtB . lq5dbqfp25 , & rtB . gq1khgfhm2 , & rtB . ld4l31qhaw , & rtB .
n0mg2py0tt , & rtB . nlrcxogbog . ovjujdzpjt [ 0 ] , & rtB . pz2stfwruz .
bbcbwrpqmg [ 0 ] , & rtB . b4zolxyidp . c03pdi1rvc [ 0 ] , & rtB . nybhsuuh1p
. mesgqmrxmy [ 0 ] , & rtB . jlne01gbu0 . hgxfgflt2m [ 0 ] , & rtB .
jrosma4ai4 . hgxfgflt2m [ 0 ] , & rtB . ek3a1451ay [ 0 ] , & rtB . hoq5gatyaq
[ 0 ] , & rtB . ljwqffhvl4 [ 0 ] , & rtB . h4k23zmq31 [ 0 ] , & rtB .
jsillufvig [ 0 ] , & rtB . nebhkpb5ai [ 0 ] , & rtB . jkgsoin4ud , & rtB .
adhev5qmdl , & rtB . kurks2zcva , & rtB . d4qvlfmvmy , & rtB . c24lrwyun4 , &
rtB . hm532ngjvw , & rtB . f5kuq3shj4 , & rtB . poglkcfqy3 , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 4 , 1 , 5 , 1 , 2 , 1 , 6 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 0.0001 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 4 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 203 , ( NULL
) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 } ,
{ rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , { 1063567491U , 88383218U ,
3038457091U , 3990997617U } , ( NULL ) , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * nodes4_GetCAPIStaticMap ( ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void nodes4_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void nodes4_host_InitializeDataMapInfo ( nodes4_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
