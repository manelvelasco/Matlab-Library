#include "__cf_nodes4.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( int64_T ) , sizeof ( int64_T
) , sizeof ( uint64_T ) } ; static const char_T * rtDataTypeNames [ ] = {
"real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "int64_T" , "int64_T" , "uint64_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
ek3a1451ay [ 0 ] ) , 0 , 0 , 311 } , { ( char_T * ) ( & rtB . ozftnlfeg3 .
n0fuel1bnn ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . jrosma4ai4 . hgxfgflt2m
[ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . jlne01gbu0 . hgxfgflt2m [ 0
] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . nybhsuuh1p . mesgqmrxmy [ 0 ] )
, 0 , 0 , 4 } , { ( char_T * ) ( & rtB . b4zolxyidp . c03pdi1rvc [ 0 ] ) , 0
, 0 , 4 } , { ( char_T * ) ( & rtB . pz2stfwruz . bbcbwrpqmg [ 0 ] ) , 0 , 0
, 4 } , { ( char_T * ) ( & rtB . nlrcxogbog . ovjujdzpjt [ 0 ] ) , 0 , 0 , 4
} , { ( char_T * ) ( & rtB . j20pq3r21f . ioo1a4zpmx [ 0 ] ) , 0 , 0 , 2 } ,
{ ( char_T * ) ( & rtB . avezulewcn . n0fuel1bnn ) , 0 , 0 , 3 } , { ( char_T
* ) ( & rtB . k04lp2vsfm . hgxfgflt2m [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * )
( & rtB . p0jpb31wlq . hgxfgflt2m [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( &
rtB . l1cumv5mxc . mesgqmrxmy [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB
. pcljl3fmii . c03pdi1rvc [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
mmnlogmmqe . bbcbwrpqmg [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
ipvzgutla1 . ovjujdzpjt [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
dvrqjotubu . ioo1a4zpmx [ 0 ] ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtB .
cwkcdvwsyb . n0fuel1bnn ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . gpr5ewbwvu
. hgxfgflt2m [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . pmll2wrcy3 .
hgxfgflt2m [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . omwjydko3j .
mesgqmrxmy [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . ejkqkpkoqg .
c03pdi1rvc [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . pxgmr2o0yw .
bbcbwrpqmg [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . mrc3jz2kzs .
ovjujdzpjt [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . jwxitznkuq .
ioo1a4zpmx [ 0 ] ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtB . a21clfzxwp .
n0fuel1bnn ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . loojatj1b3 . hgxfgflt2m
[ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . ae0vvuvpaf . hgxfgflt2m [ 0
] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . lkguggosm5 . mesgqmrxmy [ 0 ] )
, 0 , 0 , 4 } , { ( char_T * ) ( & rtB . n3la5yge0s . c03pdi1rvc [ 0 ] ) , 0
, 0 , 4 } , { ( char_T * ) ( & rtB . mfw2ixjjzd . bbcbwrpqmg [ 0 ] ) , 0 , 0
, 4 } , { ( char_T * ) ( & rtB . i0nb5cbdli . ovjujdzpjt [ 0 ] ) , 0 , 0 , 4
} , { ( char_T * ) ( & rtB . pxlv2lf0yq . ioo1a4zpmx [ 0 ] ) , 0 , 0 , 2 } ,
{ ( char_T * ) ( & rtDW . f5c0nsumji ) , 0 , 0 , 2090 } , { ( char_T * ) ( &
rtDW . izfteet4gt . LoggedData ) , 11 , 0 , 9 } , { ( char_T * ) ( & rtDW .
c5eu0ckh53 ) , 10 , 0 , 9 } , { ( char_T * ) ( & rtDW . dli3x1zfp1 ) , 8 , 0
, 4 } , { ( char_T * ) ( & rtDW . ozftnlfeg3 . ka4hfanbtx ) , 0 , 0 , 3 } , {
( char_T * ) ( & rtDW . j20pq3r21f . j4oaer2coe ) , 0 , 0 , 4 } , { ( char_T
* ) ( & rtDW . j20pq3r21f . pk5yc5rzah ) , 8 , 0 , 1 } , { ( char_T * ) ( &
rtDW . avezulewcn . ka4hfanbtx ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtDW .
dvrqjotubu . j4oaer2coe ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtDW .
dvrqjotubu . pk5yc5rzah ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
cwkcdvwsyb . ka4hfanbtx ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtDW .
jwxitznkuq . j4oaer2coe ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtDW .
jwxitznkuq . pk5yc5rzah ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
a21clfzxwp . ka4hfanbtx ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtDW .
pxlv2lf0yq . j4oaer2coe ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtDW .
pxlv2lf0yq . pk5yc5rzah ) , 8 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 49U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . array_num_generators ) , 0 ,
0 , 679 } , { ( char_T * ) ( & rtP . KSencondaryless_Value ) , 8 , 0 , 4 } ,
{ ( char_T * ) ( & rtP . ozftnlfeg3 . primarycontroldroopZv_Lv ) , 0 , 0 , 11
} , { ( char_T * ) ( & rtP . jrosma4ai4 . replacer5_a ) , 0 , 0 , 1 } , { (
char_T * ) ( & rtP . jlne01gbu0 . replacer5_a ) , 0 , 0 , 1 } , { ( char_T *
) ( & rtP . nybhsuuh1p . replacer4_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP
. b4zolxyidp . replacer3_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
pz2stfwruz . replacer2_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
nlrcxogbog . replacer1_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
j20pq3r21f . integratorcontrol_a ) , 0 , 0 , 11 } , { ( char_T * ) ( & rtP .
avezulewcn . primarycontroldroopZv_Lv ) , 0 , 0 , 11 } , { ( char_T * ) ( &
rtP . k04lp2vsfm . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
p0jpb31wlq . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
l1cumv5mxc . replacer4_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
pcljl3fmii . replacer3_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
mmnlogmmqe . replacer2_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
ipvzgutla1 . replacer1_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
dvrqjotubu . integratorcontrol_a ) , 0 , 0 , 11 } , { ( char_T * ) ( & rtP .
cwkcdvwsyb . primarycontroldroopZv_Lv ) , 0 , 0 , 11 } , { ( char_T * ) ( &
rtP . gpr5ewbwvu . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
pmll2wrcy3 . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
omwjydko3j . replacer4_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
ejkqkpkoqg . replacer3_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
pxgmr2o0yw . replacer2_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
mrc3jz2kzs . replacer1_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
jwxitznkuq . integratorcontrol_a ) , 0 , 0 , 11 } , { ( char_T * ) ( & rtP .
a21clfzxwp . primarycontroldroopZv_Lv ) , 0 , 0 , 11 } , { ( char_T * ) ( &
rtP . loojatj1b3 . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
ae0vvuvpaf . replacer5_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
lkguggosm5 . replacer4_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
n3la5yge0s . replacer3_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
mfw2ixjjzd . replacer2_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
i0nb5cbdli . replacer1_a ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
pxlv2lf0yq . integratorcontrol_a ) , 0 , 0 , 11 } } ; static
DataTypeTransitionTable rtPTransTable = { 34U , rtPTransitions } ;
