#include "__cf_nodes4.h"
#include <math.h>
#include "nodes4_acc.h"
#include "nodes4_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
jqn10cjm5e ; int_T iy ; int_T ci ; real_T eeslnumswv [ 10 ] ; static const
int8_T ir [ 11 ] = { 0 , 0 , 0 , 2 , 4 , 6 , 8 , 11 , 14 , 17 , 20 } ; static
const int8_T ir_p [ 11 ] = { 0 , 1 , 2 , 2 , 2 , 3 , 4 , 4 , 4 , 4 , 4 } ;
static const int8_T jc [ 20 ] = { 2 , 12 , 3 , 13 , 4 , 6 , 5 , 7 , 0 , 4 , 8
, 1 , 5 , 9 , 0 , 2 , 10 , 1 , 3 , 11 } ; static const int8_T jc_p [ 4 ] = {
2 , 3 , 8 , 9 } ; n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; f1xhd02yjc * _rtX ;
ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtX
= ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
ssReadFromDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g1/measures/Data Store Read1" , NULL ) ; _rtB -> e2gtviwlt2 [ 0 ] =
_rtDW -> h1t1phh10c [ 0 ] ; _rtB -> e2gtviwlt2 [ 1 ] = _rtDW -> h1t1phh10c [
1 ] ; _rtB -> e2gtviwlt2 [ 2 ] = _rtDW -> h1t1phh10c [ 2 ] ; _rtB ->
e2gtviwlt2 [ 3 ] = _rtDW -> h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 25 , 1 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtDW -> h1t1phh10c [ 0 ] = _rtB -> hnwyjibwqn [ 0 ]
; _rtDW -> h1t1phh10c [ 1 ] = _rtB -> hnwyjibwqn [ 1 ] ; _rtDW -> h1t1phh10c
[ 2 ] = _rtB -> hnwyjibwqn [ 2 ] ; _rtDW -> h1t1phh10c [ 3 ] = _rtB ->
hnwyjibwqn [ 3 ] ; ssWriteToDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g1/measures/Data Store Write1" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g1/measures/Data Store Read2" , NULL ) ; _rtB -> ffvwbdkfcs [ 0 ] =
_rtDW -> foiy3odoz1 [ 0 ] ; _rtB -> ffvwbdkfcs [ 1 ] = _rtDW -> foiy3odoz1 [
1 ] ; _rtB -> ffvwbdkfcs [ 2 ] = _rtDW -> foiy3odoz1 [ 2 ] ; _rtB ->
ffvwbdkfcs [ 3 ] = _rtDW -> foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
foiy3odoz1 [ 0 ] = _rtB -> b5dgsab0jz [ 0 ] ; _rtDW -> foiy3odoz1 [ 1 ] =
_rtB -> b5dgsab0jz [ 1 ] ; _rtDW -> foiy3odoz1 [ 2 ] = _rtB -> b5dgsab0jz [ 2
] ; _rtDW -> foiy3odoz1 [ 3 ] = _rtB -> b5dgsab0jz [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g1/measures/Data Store Write2" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g1/measures/Data Store Read3" , NULL ) ; _rtB -> kd5auhq0xy [ 0 ] =
_rtDW -> pizmexwruz [ 0 ] ; _rtB -> kd5auhq0xy [ 1 ] = _rtDW -> pizmexwruz [
1 ] ; _rtB -> kd5auhq0xy [ 2 ] = _rtDW -> pizmexwruz [ 2 ] ; _rtB ->
kd5auhq0xy [ 3 ] = _rtDW -> pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
pizmexwruz [ 0 ] = _rtB -> d22x0dugpi [ 0 ] ; _rtDW -> pizmexwruz [ 1 ] =
_rtB -> d22x0dugpi [ 1 ] ; _rtDW -> pizmexwruz [ 2 ] = _rtB -> d22x0dugpi [ 2
] ; _rtDW -> pizmexwruz [ 3 ] = _rtB -> d22x0dugpi [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g1/measures/Data Store Write3" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g1/measures/Data Store Read4" , NULL ) ; _rtB -> mipjufukcy [ 0 ] =
_rtDW -> k5wmx351m0 [ 0 ] ; _rtB -> mipjufukcy [ 1 ] = _rtDW -> k5wmx351m0 [
1 ] ; _rtB -> mipjufukcy [ 2 ] = _rtDW -> k5wmx351m0 [ 2 ] ; _rtB ->
mipjufukcy [ 3 ] = _rtDW -> k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 4 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
k5wmx351m0 [ 0 ] = _rtB -> jcdxzkh4wk [ 0 ] ; _rtDW -> k5wmx351m0 [ 1 ] =
_rtB -> jcdxzkh4wk [ 1 ] ; _rtDW -> k5wmx351m0 [ 2 ] = _rtB -> jcdxzkh4wk [ 2
] ; _rtDW -> k5wmx351m0 [ 3 ] = _rtB -> jcdxzkh4wk [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g1/measures/Data Store Write4" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g1/measures/Data Store Read5" , NULL ) ; _rtB -> hao4xj5qdo [ 0 ] =
_rtDW -> fmmswgsion [ 0 ] ; _rtB -> hao4xj5qdo [ 1 ] = _rtDW -> fmmswgsion [
1 ] ; _rtB -> hao4xj5qdo [ 2 ] = _rtDW -> fmmswgsion [ 2 ] ; _rtB ->
hao4xj5qdo [ 3 ] = _rtDW -> fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
fmmswgsion [ 0 ] = _rtB -> gwcdfogeuw [ 0 ] ; _rtDW -> fmmswgsion [ 1 ] =
_rtB -> gwcdfogeuw [ 1 ] ; _rtDW -> fmmswgsion [ 2 ] = _rtB -> gwcdfogeuw [ 2
] ; _rtDW -> fmmswgsion [ 3 ] = _rtB -> gwcdfogeuw [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g1/measures/Data Store Write5" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g1/measures/Data Store Read6" , NULL ) ; _rtB -> eogpquk5bd [ 0 ] =
_rtDW -> aboia0klkk [ 0 ] ; _rtB -> eogpquk5bd [ 1 ] = _rtDW -> aboia0klkk [
1 ] ; _rtB -> eogpquk5bd [ 2 ] = _rtDW -> aboia0klkk [ 2 ] ; _rtB ->
eogpquk5bd [ 3 ] = _rtDW -> aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 6 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
aboia0klkk [ 0 ] = _rtB -> hwoaj3zeyu [ 0 ] ; _rtDW -> aboia0klkk [ 1 ] =
_rtB -> hwoaj3zeyu [ 1 ] ; _rtDW -> aboia0klkk [ 2 ] = _rtB -> hwoaj3zeyu [ 2
] ; _rtDW -> aboia0klkk [ 3 ] = _rtB -> hwoaj3zeyu [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g1/measures/Data Store Write6" , NULL ) ; } if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> iuya4tbrhf = _rtP -> P_62 ; ssCallAccelRunBlock ( S , 25
, 20 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 25 , 21 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 25 , 22 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> l31mez0frs = _rtDW -> h31mfjlljs ; _rtB ->
afhf5b1wyr = _rtDW -> efdih4dveq ; } jqn10cjm5e = ssGetT ( S ) ; _rtB ->
gqrx0pyk2k = ssGetTStart ( S ) ; jqn10cjm5e -= _rtB -> gqrx0pyk2k ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fnpwdkzgt0 = _rtP -> P_107 ; }
jqn10cjm5e = muDoubleScalarRem ( jqn10cjm5e , _rtB -> fnpwdkzgt0 ) ; _rtB ->
i2tibichem = look1_binlxpw ( jqn10cjm5e , * ( real_T ( * ) [ 4 ] ) & _rtP ->
P_109 [ 0 ] , * ( real_T ( * ) [ 4 ] ) & _rtP -> P_108 [ 0 ] , 3U ) ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> izx2kxgh3s
[ 0 ] = _rtB -> pxkg1ecogy [ 4 ] ; _rtB -> izx2kxgh3s [ 1 ] = _rtB ->
pxkg1ecogy [ 5 ] ; _rtB -> izx2kxgh3s [ 2 ] = _rtB -> jtlnkz1mpr [ 4 ] ; _rtB
-> izx2kxgh3s [ 3 ] = _rtB -> jtlnkz1mpr [ 5 ] ; _rtB -> izx2kxgh3s [ 4 ] =
_rtB -> lmnlqljr4o [ 4 ] ; _rtB -> izx2kxgh3s [ 5 ] = _rtB -> lmnlqljr4o [ 5
] ; _rtB -> izx2kxgh3s [ 6 ] = _rtB -> kbvzfuknhg [ 4 ] ; _rtB -> izx2kxgh3s
[ 7 ] = _rtB -> kbvzfuknhg [ 5 ] ; _rtB -> izx2kxgh3s [ 8 ] = _rtB ->
hahkwn1qkd ; _rtB -> izx2kxgh3s [ 9 ] = _rtB -> ifuuwgao1a ; for ( iy = 0 ;
iy < 10 ; iy ++ ) { eeslnumswv [ iy ] = 0.0 ; } for ( iy = 0 ; iy < 10 ; iy
++ ) { for ( ci = ir [ iy ] ; ci < ir [ iy + 1 ] ; ci ++ ) { eeslnumswv [ iy
] += _rtP -> P_112 [ ci ] * _rtX -> jqdufexgzv [ jc [ ci ] ] ; } } for ( iy =
0 ; iy < 10 ; iy ++ ) { for ( ci = ir_p [ iy ] ; ci < ir_p [ iy + 1 ] ; ci ++
) { eeslnumswv [ iy ] += _rtP -> P_113 [ ci ] * _rtB -> izx2kxgh3s [ jc_p [
ci ] ] ; } } _rtB -> gtgdkap21x = _rtP -> P_115 * eeslnumswv [ 9 ] ; _rtB ->
gazqjnl000 = _rtP -> P_116 * eeslnumswv [ 8 ] ; ssReadFromDataStoreWithPath (
S , _rtDW -> gakv1pwvvm , "nodes4/g2/measures/Data Store Read1" , NULL ) ;
_rtB -> cdbq1czgha [ 0 ] = _rtDW -> h1t1phh10c [ 0 ] ; _rtB -> cdbq1czgha [ 1
] = _rtDW -> h1t1phh10c [ 1 ] ; _rtB -> cdbq1czgha [ 2 ] = _rtDW ->
h1t1phh10c [ 2 ] ; _rtB -> cdbq1czgha [ 3 ] = _rtDW -> h1t1phh10c [ 3 ] ; if
( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 7 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtDW -> h1t1phh10c [ 0 ] = _rtB -> jxafbknk4u [ 0 ]
; _rtDW -> h1t1phh10c [ 1 ] = _rtB -> jxafbknk4u [ 1 ] ; _rtDW -> h1t1phh10c
[ 2 ] = _rtB -> jxafbknk4u [ 2 ] ; _rtDW -> h1t1phh10c [ 3 ] = _rtB ->
jxafbknk4u [ 3 ] ; ssWriteToDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g2/measures/Data Store Write1" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g2/measures/Data Store Read2" , NULL ) ; _rtB -> gv10ms1fmn [ 0 ] =
_rtDW -> foiy3odoz1 [ 0 ] ; _rtB -> gv10ms1fmn [ 1 ] = _rtDW -> foiy3odoz1 [
1 ] ; _rtB -> gv10ms1fmn [ 2 ] = _rtDW -> foiy3odoz1 [ 2 ] ; _rtB ->
gv10ms1fmn [ 3 ] = _rtDW -> foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 8 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
foiy3odoz1 [ 0 ] = _rtB -> p4t24vfxix [ 0 ] ; _rtDW -> foiy3odoz1 [ 1 ] =
_rtB -> p4t24vfxix [ 1 ] ; _rtDW -> foiy3odoz1 [ 2 ] = _rtB -> p4t24vfxix [ 2
] ; _rtDW -> foiy3odoz1 [ 3 ] = _rtB -> p4t24vfxix [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g2/measures/Data Store Write2" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g2/measures/Data Store Read3" , NULL ) ; _rtB -> gkrawtbzr5 [ 0 ] =
_rtDW -> pizmexwruz [ 0 ] ; _rtB -> gkrawtbzr5 [ 1 ] = _rtDW -> pizmexwruz [
1 ] ; _rtB -> gkrawtbzr5 [ 2 ] = _rtDW -> pizmexwruz [ 2 ] ; _rtB ->
gkrawtbzr5 [ 3 ] = _rtDW -> pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 9 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
pizmexwruz [ 0 ] = _rtB -> dfogan1j3k [ 0 ] ; _rtDW -> pizmexwruz [ 1 ] =
_rtB -> dfogan1j3k [ 1 ] ; _rtDW -> pizmexwruz [ 2 ] = _rtB -> dfogan1j3k [ 2
] ; _rtDW -> pizmexwruz [ 3 ] = _rtB -> dfogan1j3k [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g2/measures/Data Store Write3" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g2/measures/Data Store Read4" , NULL ) ; _rtB -> b1irlofrri [ 0 ] =
_rtDW -> k5wmx351m0 [ 0 ] ; _rtB -> b1irlofrri [ 1 ] = _rtDW -> k5wmx351m0 [
1 ] ; _rtB -> b1irlofrri [ 2 ] = _rtDW -> k5wmx351m0 [ 2 ] ; _rtB ->
b1irlofrri [ 3 ] = _rtDW -> k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 10 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
k5wmx351m0 [ 0 ] = _rtB -> okluxtv1i4 [ 0 ] ; _rtDW -> k5wmx351m0 [ 1 ] =
_rtB -> okluxtv1i4 [ 1 ] ; _rtDW -> k5wmx351m0 [ 2 ] = _rtB -> okluxtv1i4 [ 2
] ; _rtDW -> k5wmx351m0 [ 3 ] = _rtB -> okluxtv1i4 [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g2/measures/Data Store Write4" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g2/measures/Data Store Read5" , NULL ) ; _rtB -> jk0xeuwd44 [ 0 ] =
_rtDW -> fmmswgsion [ 0 ] ; _rtB -> jk0xeuwd44 [ 1 ] = _rtDW -> fmmswgsion [
1 ] ; _rtB -> jk0xeuwd44 [ 2 ] = _rtDW -> fmmswgsion [ 2 ] ; _rtB ->
jk0xeuwd44 [ 3 ] = _rtDW -> fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 11 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
fmmswgsion [ 0 ] = _rtB -> oynoqshukd [ 0 ] ; _rtDW -> fmmswgsion [ 1 ] =
_rtB -> oynoqshukd [ 1 ] ; _rtDW -> fmmswgsion [ 2 ] = _rtB -> oynoqshukd [ 2
] ; _rtDW -> fmmswgsion [ 3 ] = _rtB -> oynoqshukd [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g2/measures/Data Store Write5" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g2/measures/Data Store Read6" , NULL ) ; _rtB -> b3czhjge52 [ 0 ] =
_rtDW -> aboia0klkk [ 0 ] ; _rtB -> b3czhjge52 [ 1 ] = _rtDW -> aboia0klkk [
1 ] ; _rtB -> b3czhjge52 [ 2 ] = _rtDW -> aboia0klkk [ 2 ] ; _rtB ->
b3czhjge52 [ 3 ] = _rtDW -> aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 12 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
aboia0klkk [ 0 ] = _rtB -> b1naayhgsl [ 0 ] ; _rtDW -> aboia0klkk [ 1 ] =
_rtB -> b1naayhgsl [ 1 ] ; _rtDW -> aboia0klkk [ 2 ] = _rtB -> b1naayhgsl [ 2
] ; _rtDW -> aboia0klkk [ 3 ] = _rtB -> b1naayhgsl [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g2/measures/Data Store Write6" , NULL ) ; } if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> npte5qyhoy = _rtP -> P_117 ; } _rtB -> mqe4dcpakt = _rtP
-> P_118 * eeslnumswv [ 7 ] ; _rtB -> l0ky4rydp4 = _rtP -> P_119 * eeslnumswv
[ 6 ] ; ssReadFromDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g3/measures/Data Store Read1" , NULL ) ; _rtB -> khfhtpjgmf [ 0 ] =
_rtDW -> h1t1phh10c [ 0 ] ; _rtB -> khfhtpjgmf [ 1 ] = _rtDW -> h1t1phh10c [
1 ] ; _rtB -> khfhtpjgmf [ 2 ] = _rtDW -> h1t1phh10c [ 2 ] ; _rtB ->
khfhtpjgmf [ 3 ] = _rtDW -> h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 13 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
h1t1phh10c [ 0 ] = _rtB -> boqfp5i1te [ 0 ] ; _rtDW -> h1t1phh10c [ 1 ] =
_rtB -> boqfp5i1te [ 1 ] ; _rtDW -> h1t1phh10c [ 2 ] = _rtB -> boqfp5i1te [ 2
] ; _rtDW -> h1t1phh10c [ 3 ] = _rtB -> boqfp5i1te [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g3/measures/Data Store Write1" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g3/measures/Data Store Read2" , NULL ) ; _rtB -> gtl0hvntnu [ 0 ] =
_rtDW -> foiy3odoz1 [ 0 ] ; _rtB -> gtl0hvntnu [ 1 ] = _rtDW -> foiy3odoz1 [
1 ] ; _rtB -> gtl0hvntnu [ 2 ] = _rtDW -> foiy3odoz1 [ 2 ] ; _rtB ->
gtl0hvntnu [ 3 ] = _rtDW -> foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
foiy3odoz1 [ 0 ] = _rtB -> bmtspm1s3a [ 0 ] ; _rtDW -> foiy3odoz1 [ 1 ] =
_rtB -> bmtspm1s3a [ 1 ] ; _rtDW -> foiy3odoz1 [ 2 ] = _rtB -> bmtspm1s3a [ 2
] ; _rtDW -> foiy3odoz1 [ 3 ] = _rtB -> bmtspm1s3a [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g3/measures/Data Store Write2" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g3/measures/Data Store Read3" , NULL ) ; _rtB -> jx0gx0qhe5 [ 0 ] =
_rtDW -> pizmexwruz [ 0 ] ; _rtB -> jx0gx0qhe5 [ 1 ] = _rtDW -> pizmexwruz [
1 ] ; _rtB -> jx0gx0qhe5 [ 2 ] = _rtDW -> pizmexwruz [ 2 ] ; _rtB ->
jx0gx0qhe5 [ 3 ] = _rtDW -> pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 15 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
pizmexwruz [ 0 ] = _rtB -> ppr41bovud [ 0 ] ; _rtDW -> pizmexwruz [ 1 ] =
_rtB -> ppr41bovud [ 1 ] ; _rtDW -> pizmexwruz [ 2 ] = _rtB -> ppr41bovud [ 2
] ; _rtDW -> pizmexwruz [ 3 ] = _rtB -> ppr41bovud [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g3/measures/Data Store Write3" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g3/measures/Data Store Read4" , NULL ) ; _rtB -> haiuc3brf2 [ 0 ] =
_rtDW -> k5wmx351m0 [ 0 ] ; _rtB -> haiuc3brf2 [ 1 ] = _rtDW -> k5wmx351m0 [
1 ] ; _rtB -> haiuc3brf2 [ 2 ] = _rtDW -> k5wmx351m0 [ 2 ] ; _rtB ->
haiuc3brf2 [ 3 ] = _rtDW -> k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 16 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
k5wmx351m0 [ 0 ] = _rtB -> jwjpsd5pgq [ 0 ] ; _rtDW -> k5wmx351m0 [ 1 ] =
_rtB -> jwjpsd5pgq [ 1 ] ; _rtDW -> k5wmx351m0 [ 2 ] = _rtB -> jwjpsd5pgq [ 2
] ; _rtDW -> k5wmx351m0 [ 3 ] = _rtB -> jwjpsd5pgq [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g3/measures/Data Store Write4" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g3/measures/Data Store Read5" , NULL ) ; _rtB -> h1qme3j2bw [ 0 ] =
_rtDW -> fmmswgsion [ 0 ] ; _rtB -> h1qme3j2bw [ 1 ] = _rtDW -> fmmswgsion [
1 ] ; _rtB -> h1qme3j2bw [ 2 ] = _rtDW -> fmmswgsion [ 2 ] ; _rtB ->
h1qme3j2bw [ 3 ] = _rtDW -> fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 17 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
fmmswgsion [ 0 ] = _rtB -> aav5xvc02p [ 0 ] ; _rtDW -> fmmswgsion [ 1 ] =
_rtB -> aav5xvc02p [ 1 ] ; _rtDW -> fmmswgsion [ 2 ] = _rtB -> aav5xvc02p [ 2
] ; _rtDW -> fmmswgsion [ 3 ] = _rtB -> aav5xvc02p [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g3/measures/Data Store Write5" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g3/measures/Data Store Read6" , NULL ) ; _rtB -> oev434ob1e [ 0 ] =
_rtDW -> aboia0klkk [ 0 ] ; _rtB -> oev434ob1e [ 1 ] = _rtDW -> aboia0klkk [
1 ] ; _rtB -> oev434ob1e [ 2 ] = _rtDW -> aboia0klkk [ 2 ] ; _rtB ->
oev434ob1e [ 3 ] = _rtDW -> aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 18 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
aboia0klkk [ 0 ] = _rtB -> a03zwks0cw [ 0 ] ; _rtDW -> aboia0klkk [ 1 ] =
_rtB -> a03zwks0cw [ 1 ] ; _rtDW -> aboia0klkk [ 2 ] = _rtB -> a03zwks0cw [ 2
] ; _rtDW -> aboia0klkk [ 3 ] = _rtB -> a03zwks0cw [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g3/measures/Data Store Write6" , NULL ) ; } if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> j24lgpzhfj = _rtP -> P_120 ; } _rtB -> fdvxhynxnj = _rtP
-> P_121 * eeslnumswv [ 5 ] ; _rtB -> g0b1s2f2bl = _rtP -> P_122 * eeslnumswv
[ 4 ] ; ssReadFromDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g4/measures/Data Store Read1" , NULL ) ; _rtB -> fk1yhgp3r1 [ 0 ] =
_rtDW -> h1t1phh10c [ 0 ] ; _rtB -> fk1yhgp3r1 [ 1 ] = _rtDW -> h1t1phh10c [
1 ] ; _rtB -> fk1yhgp3r1 [ 2 ] = _rtDW -> h1t1phh10c [ 2 ] ; _rtB ->
fk1yhgp3r1 [ 3 ] = _rtDW -> h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 19 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
h1t1phh10c [ 0 ] = _rtB -> pnsbl4ip1n [ 0 ] ; _rtDW -> h1t1phh10c [ 1 ] =
_rtB -> pnsbl4ip1n [ 1 ] ; _rtDW -> h1t1phh10c [ 2 ] = _rtB -> pnsbl4ip1n [ 2
] ; _rtDW -> h1t1phh10c [ 3 ] = _rtB -> pnsbl4ip1n [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> gakv1pwvvm ,
"nodes4/g4/measures/Data Store Write1" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g4/measures/Data Store Read2" , NULL ) ; _rtB -> jkbnt22sil [ 0 ] =
_rtDW -> foiy3odoz1 [ 0 ] ; _rtB -> jkbnt22sil [ 1 ] = _rtDW -> foiy3odoz1 [
1 ] ; _rtB -> jkbnt22sil [ 2 ] = _rtDW -> foiy3odoz1 [ 2 ] ; _rtB ->
jkbnt22sil [ 3 ] = _rtDW -> foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 20 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
foiy3odoz1 [ 0 ] = _rtB -> baao5skwly [ 0 ] ; _rtDW -> foiy3odoz1 [ 1 ] =
_rtB -> baao5skwly [ 1 ] ; _rtDW -> foiy3odoz1 [ 2 ] = _rtB -> baao5skwly [ 2
] ; _rtDW -> foiy3odoz1 [ 3 ] = _rtB -> baao5skwly [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/g4/measures/Data Store Write2" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g4/measures/Data Store Read3" , NULL ) ; _rtB -> n3pe4qnw14 [ 0 ] =
_rtDW -> pizmexwruz [ 0 ] ; _rtB -> n3pe4qnw14 [ 1 ] = _rtDW -> pizmexwruz [
1 ] ; _rtB -> n3pe4qnw14 [ 2 ] = _rtDW -> pizmexwruz [ 2 ] ; _rtB ->
n3pe4qnw14 [ 3 ] = _rtDW -> pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 21 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
pizmexwruz [ 0 ] = _rtB -> kjoc2nr33r [ 0 ] ; _rtDW -> pizmexwruz [ 1 ] =
_rtB -> kjoc2nr33r [ 1 ] ; _rtDW -> pizmexwruz [ 2 ] = _rtB -> kjoc2nr33r [ 2
] ; _rtDW -> pizmexwruz [ 3 ] = _rtB -> kjoc2nr33r [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/g4/measures/Data Store Write3" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g4/measures/Data Store Read4" , NULL ) ; _rtB -> ceul5xqybi [ 0 ] =
_rtDW -> k5wmx351m0 [ 0 ] ; _rtB -> ceul5xqybi [ 1 ] = _rtDW -> k5wmx351m0 [
1 ] ; _rtB -> ceul5xqybi [ 2 ] = _rtDW -> k5wmx351m0 [ 2 ] ; _rtB ->
ceul5xqybi [ 3 ] = _rtDW -> k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 22 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
k5wmx351m0 [ 0 ] = _rtB -> jmqlsaseoi [ 0 ] ; _rtDW -> k5wmx351m0 [ 1 ] =
_rtB -> jmqlsaseoi [ 1 ] ; _rtDW -> k5wmx351m0 [ 2 ] = _rtB -> jmqlsaseoi [ 2
] ; _rtDW -> k5wmx351m0 [ 3 ] = _rtB -> jmqlsaseoi [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/g4/measures/Data Store Write4" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g4/measures/Data Store Read5" , NULL ) ; _rtB -> mc5t0dlran [ 0 ] =
_rtDW -> fmmswgsion [ 0 ] ; _rtB -> mc5t0dlran [ 1 ] = _rtDW -> fmmswgsion [
1 ] ; _rtB -> mc5t0dlran [ 2 ] = _rtDW -> fmmswgsion [ 2 ] ; _rtB ->
mc5t0dlran [ 3 ] = _rtDW -> fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 23 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
fmmswgsion [ 0 ] = _rtB -> m32je5lcxu [ 0 ] ; _rtDW -> fmmswgsion [ 1 ] =
_rtB -> m32je5lcxu [ 1 ] ; _rtDW -> fmmswgsion [ 2 ] = _rtB -> m32je5lcxu [ 2
] ; _rtDW -> fmmswgsion [ 3 ] = _rtB -> m32je5lcxu [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/g4/measures/Data Store Write5" , NULL ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g4/measures/Data Store Read6" , NULL ) ; _rtB -> nf5zcxo1wl [ 0 ] =
_rtDW -> aboia0klkk [ 0 ] ; _rtB -> nf5zcxo1wl [ 1 ] = _rtDW -> aboia0klkk [
1 ] ; _rtB -> nf5zcxo1wl [ 2 ] = _rtDW -> aboia0klkk [ 2 ] ; _rtB ->
nf5zcxo1wl [ 3 ] = _rtDW -> aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0
) ) { ssCallAccelRunBlock ( S , 24 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtDW ->
aboia0klkk [ 0 ] = _rtB -> dzhzdqycu2 [ 0 ] ; _rtDW -> aboia0klkk [ 1 ] =
_rtB -> dzhzdqycu2 [ 1 ] ; _rtDW -> aboia0klkk [ 2 ] = _rtB -> dzhzdqycu2 [ 2
] ; _rtDW -> aboia0klkk [ 3 ] = _rtB -> dzhzdqycu2 [ 3 ] ;
ssWriteToDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/g4/measures/Data Store Write6" , NULL ) ; } if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> anztngqa0w = _rtP -> P_123 ; } _rtB -> i2kexejxss = _rtP
-> P_124 * eeslnumswv [ 3 ] ; _rtB -> b02whwk3ac = _rtP -> P_125 * eeslnumswv
[ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 25 ,
171 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 25 , 172 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 25 , 173 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> emge4lcvxn = ssGetT ( S ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 25 , 175 ,
SS_CALL_MDL_OUTPUTS ) ; } ssReadFromDataStoreWithPath ( S , _rtDW ->
gakv1pwvvm , "nodes4/Control/Data Store Read" , NULL ) ; _rtB -> cnj0f32dky [
0 ] = _rtDW -> h1t1phh10c [ 0 ] ; _rtB -> cnj0f32dky [ 1 ] = _rtDW ->
h1t1phh10c [ 1 ] ; _rtB -> cnj0f32dky [ 2 ] = _rtDW -> h1t1phh10c [ 2 ] ;
_rtB -> cnj0f32dky [ 3 ] = _rtDW -> h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( S
, 2 , 0 ) ) { ssCallAccelRunBlock ( S , 25 , 177 , SS_CALL_MDL_OUTPUTS ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> ivmk2fwp5x ,
"nodes4/Control/Data Store Read1" , NULL ) ; _rtB -> bnlgets0ne [ 0 ] = _rtDW
-> foiy3odoz1 [ 0 ] ; _rtB -> bnlgets0ne [ 1 ] = _rtDW -> foiy3odoz1 [ 1 ] ;
_rtB -> bnlgets0ne [ 2 ] = _rtDW -> foiy3odoz1 [ 2 ] ; _rtB -> bnlgets0ne [ 3
] = _rtDW -> foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 25 , 179 , SS_CALL_MDL_OUTPUTS ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> dgn0vobid0 ,
"nodes4/Control/Data Store Read2" , NULL ) ; _rtB -> l0rpfkcsqg [ 0 ] = _rtDW
-> pizmexwruz [ 0 ] ; _rtB -> l0rpfkcsqg [ 1 ] = _rtDW -> pizmexwruz [ 1 ] ;
_rtB -> l0rpfkcsqg [ 2 ] = _rtDW -> pizmexwruz [ 2 ] ; _rtB -> l0rpfkcsqg [ 3
] = _rtDW -> pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 25 , 181 , SS_CALL_MDL_OUTPUTS ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jjmar5x2j0 ,
"nodes4/Control/Data Store Read3" , NULL ) ; _rtB -> prs3bc3ijk [ 0 ] = _rtDW
-> k5wmx351m0 [ 0 ] ; _rtB -> prs3bc3ijk [ 1 ] = _rtDW -> k5wmx351m0 [ 1 ] ;
_rtB -> prs3bc3ijk [ 2 ] = _rtDW -> k5wmx351m0 [ 2 ] ; _rtB -> prs3bc3ijk [ 3
] = _rtDW -> k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 25 , 183 , SS_CALL_MDL_OUTPUTS ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> jquzg2wztj ,
"nodes4/Control/Data Store Read4" , NULL ) ; _rtB -> lbdzxmtpb2 [ 0 ] = _rtDW
-> aboia0klkk [ 0 ] ; _rtB -> lbdzxmtpb2 [ 1 ] = _rtDW -> aboia0klkk [ 1 ] ;
_rtB -> lbdzxmtpb2 [ 2 ] = _rtDW -> aboia0klkk [ 2 ] ; _rtB -> lbdzxmtpb2 [ 3
] = _rtDW -> aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 25 , 185 , SS_CALL_MDL_OUTPUTS ) ; }
ssReadFromDataStoreWithPath ( S , _rtDW -> m1d1zu5yxt ,
"nodes4/Control/Data Store Read5" , NULL ) ; _rtB -> k5mo4qhls2 [ 0 ] = _rtDW
-> fmmswgsion [ 0 ] ; _rtB -> k5mo4qhls2 [ 1 ] = _rtDW -> fmmswgsion [ 1 ] ;
_rtB -> k5mo4qhls2 [ 2 ] = _rtDW -> fmmswgsion [ 2 ] ; _rtB -> k5mo4qhls2 [ 3
] = _rtDW -> fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
ssCallAccelRunBlock ( S , 25 , 187 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
befdke5zbo = _rtP -> P_168 * eeslnumswv [ 0 ] ; _rtB -> ghknbzw00l = _rtP ->
P_169 * eeslnumswv [ 1 ] ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { n3qi1whofz * _rtB ;
ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> h31mfjlljs = _rtB -> befdke5zbo ; _rtDW -> efdih4dveq = _rtB ->
ghknbzw00l ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { int_T is ; int_T ci ; static
const int8_T ir [ 15 ] = { 0 , 2 , 4 , 6 , 8 , 10 , 12 , 13 , 14 , 15 , 16 ,
17 , 18 , 19 , 20 } ; static const int8_T jc [ 20 ] = { 4 , 6 , 5 , 7 , 0 , 6
, 1 , 7 , 2 , 4 , 3 , 5 , 2 , 3 , 4 , 5 , 6 , 7 , 0 , 1 } ; n3qi1whofz * _rtB
; loikxjbxjg * _rtP ; f1xhd02yjc * _rtX ; pqmvzr1kvu * _rtXdot ; _rtXdot = (
( pqmvzr1kvu * ) ssGetdX ( S ) ) ; _rtX = ( ( f1xhd02yjc * ) ssGetContStates
( S ) ) ; _rtP = ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
n3qi1whofz * ) _ssGetBlockIO ( S ) ) ; for ( is = 0 ; is < 14 ; is ++ ) {
_rtXdot -> jqdufexgzv [ is ] = 0.0 ; } for ( is = 0 ; is < 14 ; is ++ ) { for
( ci = is ; ci < is + 1 ; ci ++ ) { _rtXdot -> jqdufexgzv [ is ] += _rtP ->
P_110 [ ci ] * _rtX -> jqdufexgzv [ ci ] ; } } for ( is = 0 ; is < 14 ; is ++
) { for ( ci = ir [ is ] ; ci < ir [ is + 1 ] ; ci ++ ) { _rtXdot ->
jqdufexgzv [ is ] += _rtP -> P_111 [ ci ] * _rtB -> izx2kxgh3s [ jc [ ci ] ]
; } } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { n3qi1whofz * _rtB ;
loikxjbxjg * _rtP ; _rtP = ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ;
_rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S ,
25 , 1 , SS_CALL_MDL_ZERO_CROSSINGS ) ; ssCallAccelRunBlock ( S , 25 , 20 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; ssCallAccelRunBlock ( S , 25 , 21 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; ssCallAccelRunBlock ( S , 25 , 22 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; ssCallAccelRunBlock ( S , 25 , 171 ,
SS_CALL_MDL_ZERO_CROSSINGS ) ; } static void mdlInitializeSizes ( SimStruct *
S ) { ssSetChecksumVal ( S , 0 , 1779081552U ) ; ssSetChecksumVal ( S , 1 ,
2928319526U ) ; ssSetChecksumVal ( S , 2 , 1727516628U ) ; ssSetChecksumVal (
S , 3 , 55598806U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
= mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.3" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
ew10rzwqr2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( n3qi1whofz ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
loikxjbxjg ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & o2iu0a2jke ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 5 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 6 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 7 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 8 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 9 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 10 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 11 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 12 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 13 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 14 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 15 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 16 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 17 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 18 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 19 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 20 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 21 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 22 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 23 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 24 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
