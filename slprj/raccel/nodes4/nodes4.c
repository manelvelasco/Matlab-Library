#include "__cf_nodes4.h"
#include "rt_logging_mmi.h"
#include "nodes4_capi.h"
#include <math.h>
#include "nodes4.h"
#include "nodes4_private.h"
#include "nodes4_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 10 ;
const char_T * gbl_raccel_Version = "8.6 (R2014a) 27-Dec-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//nodes4//nodes4_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const real_T nodes4_RGND = 0.0 ; B rtB ; X rtX ; DW rtDW ; static SimStruct
model_S ; SimStruct * const rtS = & model_S ; real_T look1_binlxpw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) {
real_T frac ; uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <=
bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [
0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft
= 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [
bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0
[ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex -
1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } return ( table [
iLeft + 1U ] - table [ iLeft ] ) * frac + table [ iLeft ] ; } void e1ux3zzmti
( nd455pykna * localDW ) { localDW -> pk5yc5rzah = false ; localDW ->
j4oaer2coe = 0.0 ; localDW -> diheapmar0 = 0.0 ; localDW -> lpucd5ozhl = 0.0
; } void onerdwipjp ( real_T ftvqqnmjes , real_T movojndwwy , cq33sumodo *
localB , nd455pykna * localDW , n1y0minqnv * localP ) { real_T e_w ; if ( !
localDW -> pk5yc5rzah ) { localDW -> h2qukl2a2z = localP ->
integratorcontrol_dr [ ( int32_T ) localP -> integratorcontrol_a - 1 ] ;
localDW -> pk5yc5rzah = true ; } localDW -> diheapmar0 = ( localDW ->
diheapmar0 + localP -> integratorcontrol_ts ) + localDW -> h2qukl2a2z ;
localDW -> j4oaer2coe = ( localDW -> j4oaer2coe + localP ->
integratorcontrol_ts ) + localDW -> h2qukl2a2z ; e_w = ( localP ->
integratorcontrol_wo - 6.2831853071795862 * ftvqqnmjes ) * movojndwwy ;
localDW -> lpucd5ozhl += ( localP -> integratorcontrol_ts + localDW ->
h2qukl2a2z ) * e_w ; localB -> ioo1a4zpmx [ 0 ] = localP ->
integratorcontrol_kif * localDW -> lpucd5ozhl + localP ->
integratorcontrol_kpf * e_w ; localB -> ioo1a4zpmx [ 1 ] = 0.0 ; } void
kpi03nmwlh ( const real_T ia53et2zmy [ 4 ] , real_T cnqnja1cvu , mjvusmhnt4 *
localB , drnct5ly2o * localP ) { localB -> ovjujdzpjt [ 0 ] = ia53et2zmy [ 0
] ; localB -> ovjujdzpjt [ 1 ] = ia53et2zmy [ 1 ] ; localB -> ovjujdzpjt [ 2
] = ia53et2zmy [ 2 ] ; localB -> ovjujdzpjt [ 3 ] = ia53et2zmy [ 3 ] ; localB
-> ovjujdzpjt [ ( int32_T ) localP -> replacer1_a - 1 ] = cnqnja1cvu ; } void
kjaxztqeed ( const real_T mh1dxhbrfm [ 4 ] , real_T kr3sjenk15 , lxgqip2r3j *
localB , ewvp3cxhdz * localP ) { localB -> bbcbwrpqmg [ 0 ] = mh1dxhbrfm [ 0
] ; localB -> bbcbwrpqmg [ 1 ] = mh1dxhbrfm [ 1 ] ; localB -> bbcbwrpqmg [ 2
] = mh1dxhbrfm [ 2 ] ; localB -> bbcbwrpqmg [ 3 ] = mh1dxhbrfm [ 3 ] ; localB
-> bbcbwrpqmg [ ( int32_T ) localP -> replacer2_a - 1 ] = kr3sjenk15 ; } void
h4j3c4exvj ( const real_T che20jmnsq [ 4 ] , real_T dhq1cyd0eq , ai0etet4ec *
localB , ndkw5mnz3z * localP ) { localB -> c03pdi1rvc [ 0 ] = che20jmnsq [ 0
] ; localB -> c03pdi1rvc [ 1 ] = che20jmnsq [ 1 ] ; localB -> c03pdi1rvc [ 2
] = che20jmnsq [ 2 ] ; localB -> c03pdi1rvc [ 3 ] = che20jmnsq [ 3 ] ; localB
-> c03pdi1rvc [ ( int32_T ) localP -> replacer3_a - 1 ] = dhq1cyd0eq ; } void
akzc515hdq ( const real_T j5dvrlnda0 [ 4 ] , real_T iniuk4qaft , m0q1lbf303 *
localB , nbb0zpvvhm * localP ) { localB -> mesgqmrxmy [ 0 ] = j5dvrlnda0 [ 0
] ; localB -> mesgqmrxmy [ 1 ] = j5dvrlnda0 [ 1 ] ; localB -> mesgqmrxmy [ 2
] = j5dvrlnda0 [ 2 ] ; localB -> mesgqmrxmy [ 3 ] = j5dvrlnda0 [ 3 ] ; localB
-> mesgqmrxmy [ ( int32_T ) localP -> replacer4_a - 1 ] = iniuk4qaft ; } void
jtbhfmltwq ( const real_T b114fmir4d [ 4 ] , real_T hytbtazndq , jojddljsvc *
localB , ozv2axw2sw * localP ) { localB -> hgxfgflt2m [ 0 ] = b114fmir4d [ 0
] ; localB -> hgxfgflt2m [ 1 ] = b114fmir4d [ 1 ] ; localB -> hgxfgflt2m [ 2
] = b114fmir4d [ 2 ] ; localB -> hgxfgflt2m [ 3 ] = b114fmir4d [ 3 ] ; localB
-> hgxfgflt2m [ ( int32_T ) localP -> replacer5_a - 1 ] = hytbtazndq ; } void
ait2csy21y ( freptvnt4s * localDW ) { localDW -> ka4hfanbtx = 0.0 ; localDW
-> padb2uwtk3 = 0.0 ; localDW -> jdyes1duqb = 0.0 ; } void o3zilu53kc (
real_T bwxjuvtnnx , real_T dpg4kt2y5y , real_T kxdfg2miwh , real_T kc0wy2r5y5
, real_T gb1cduktq3 , real_T f3otagz1zj , real_T amncivy1n5 , kfdidjbyrv *
localB , freptvnt4s * localDW , m5tur4wi4k * localP ) { real_T va ; real_T ph
; localDW -> padb2uwtk3 = ( localDW -> padb2uwtk3 + localP ->
primarycontroldroopZv_ts ) + localDW -> jdyes1duqb ; localDW -> ka4hfanbtx =
( localDW -> ka4hfanbtx + localP -> primarycontroldroopZv_ts ) + localDW ->
jdyes1duqb ; ph = ( ( localP -> primarycontroldroopZv_wo + gb1cduktq3 ) -
localP -> primarycontroldroopZv_m * bwxjuvtnnx ) * localDW -> ka4hfanbtx -
localP -> primarycontroldroopZv_mp * bwxjuvtnnx ; if ( ph >
6.2831853071795862 ) { localDW -> ka4hfanbtx = ( ( ph - 6.2831853071795862 )
+ localP -> primarycontroldroopZv_mp * bwxjuvtnnx ) / ( ( localP ->
primarycontroldroopZv_wo + gb1cduktq3 ) - localP -> primarycontroldroopZv_m *
bwxjuvtnnx ) ; } va = ( ( localP -> primarycontroldroopZv_Vn + f3otagz1zj ) -
localP -> primarycontroldroopZv_n * dpg4kt2y5y ) * muDoubleScalarSin ( ph ) +
localP -> primarycontroldroopZv_Lv * localP -> primarycontroldroopZv_wo *
kc0wy2r5y5 ; ph = - ( ( localP -> primarycontroldroopZv_Vn + f3otagz1zj ) -
localP -> primarycontroldroopZv_n * dpg4kt2y5y ) * muDoubleScalarCos ( ph ) -
localP -> primarycontroldroopZv_Lv * localP -> primarycontroldroopZv_wo *
kxdfg2miwh ; if ( localDW -> padb2uwtk3 > 2.0 ) { localDW -> jdyes1duqb =
localP -> primarycontroldroopZv_dr [ ( int32_T ) amncivy1n5 - 1 ] ; } localB
-> n0fuel1bnn = ( va * kxdfg2miwh + ph * kc0wy2r5y5 ) * 1.5 ; localB ->
dberndtk2w = ( - va * kc0wy2r5y5 + ph * kxdfg2miwh ) * 1.5 ; localB ->
on2dguwvvl = muDoubleScalarSqrt ( va * va + ph * ph ) ; } void MdlInitialize
( void ) { int32_T i ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtDW . mjqxgo2das = rtP . Memory1_X0 ; rtDW . lstr5kczd4 = rtP .
Memory2_X0 ; rtDW . ex3o4uqzc2 = rtP . Memory6_X0 ; rtDW . mcbh12k100 = rtP .
Memory7_X0 ; rtDW . ahv3cotbw2 = rtP . Memory3_X0 ; rtDW . p5sygl0ymh = rtP .
Memory4_X0 ; ait2csy21y ( & rtDW . ozftnlfeg3 ) ; rtDW . f5c0nsumji = rtP .
LPFq_InitialStates ; e1ux3zzmti ( & rtDW . j20pq3r21f ) ; rtX . myddfjqwmy =
rtP . Integrator_IC ; rtX . idks32lhev = rtP . Integrator1_IC ; rtX .
hnfrxgtkqe = rtP . Integrator2_IC ; rtDW . oktxx1jm30 [ 0 ] = rtP .
Memory5_X0 ; rtDW . oktxx1jm30 [ 1 ] = rtP . Memory5_X0 ; rtDW . dli3x1zfp1 =
false ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . fvdlnsmpbl [ i ] = 0.0 ; rtDW
. hgisorl0lv [ i ] = 0.0 ; } rtDW . bc1tq0iten = 0.0 ; rtDW . ggpdvqbik4 =
0.0 ; rtDW . cd5a0neolm = 7.9577471545947667 ; { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . a5w40p1bws = rtP .
LPFp_InitialStates ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . blweiavnmj [ i ]
= 0.0 ; rtDW . cxib0dsdcq [ i ] = 0.0 ; rtDW . fs03kermta [ i ] = 0.0 ; } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; sfcnInitializeConditions ( rts
) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts
= ssGetSFunction ( rtS , 3 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . h31mfjlljs = rtP .
Memory1_X0_jv5njtitnu ; rtDW . efdih4dveq = rtP . Memory2_X0_oubqdo0i4e ;
memcpy ( & rtX . jqdufexgzv [ 0 ] , & rtP . StateSpace_X0 [ 0 ] , 14U *
sizeof ( real_T ) ) ; rtDW . n31fjbosih = rtP . Memory1_X0_acajsjsekz ; rtDW
. bj3nvzbqqv = rtP . Memory2_X0_ajbdfeu2uy ; rtDW . pftedxldcl = rtP .
Memory6_X0_ofdizjjuud ; rtDW . ffb5al3bwy = rtP . Memory7_X0_gwiovv5pgj ;
rtDW . l2sbaaoqpn = rtP . Memory3_X0_eu1l45nsjm ; rtDW . nha400jjfg = rtP .
Memory4_X0_g1gmrklcwr ; ait2csy21y ( & rtDW . a21clfzxwp ) ; rtDW .
eanwkjl2vy = rtP . LPFq_InitialStates_lv2gugfrn2 ; e1ux3zzmti ( & rtDW .
pxlv2lf0yq ) ; rtX . cvbao2hes3 = rtP . Integrator_IC_itmwux0uj4 ; rtX .
nce055ezz1 = rtP . Integrator1_IC_jmop5m2mq2 ; rtX . cenhjcoeh3 = rtP .
Integrator2_IC_m1ypge3jrf ; rtDW . bugcdre0xq [ 0 ] = rtP .
Memory5_X0_iqjkcc41vs ; rtDW . bugcdre0xq [ 1 ] = rtP . Memory5_X0_iqjkcc41vs
; rtDW . nb5pthjmwg = false ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW .
e23cqdlwby [ i ] = 0.0 ; rtDW . og10ihhnhf [ i ] = 0.0 ; } rtDW . oimg4prx1p
= 0.0 ; rtDW . goy3rwgvfy = 0.0 ; rtDW . eopudmnicm = 7.9577471545947667 ; {
SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; sfcnInitializeConditions ( rts
) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . d5bnnktx4e
= rtP . LPFp_InitialStates_cjbhvcuzaf ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW
. beo5lordfv [ i ] = 0.0 ; rtDW . f0slooz0kt [ i ] = 0.0 ; rtDW . fi5ombzs0c
[ i ] = 0.0 ; } rtDW . hccpqibboh = rtP . Memory1_X0_ihd3ji5ptm ; rtDW .
mmm2iqducw = rtP . Memory2_X0_chrzl0gq2u ; rtDW . caoih1mnoc = rtP .
Memory6_X0_cpc5jg0si1 ; rtDW . ni0pxjjk34 = rtP . Memory7_X0_ofzzxrdwtc ;
rtDW . hlgbmv2r55 = rtP . Memory3_X0_jrojbqbxiv ; rtDW . p2lhgag51t = rtP .
Memory4_X0_ammobeqm0v ; ait2csy21y ( & rtDW . cwkcdvwsyb ) ; rtDW .
lnetbv1cgv = rtP . LPFq_InitialStates_mct4zv33r2 ; e1ux3zzmti ( & rtDW .
jwxitznkuq ) ; rtX . b1xdzpc02l = rtP . Integrator_IC_ce2toqsgfm ; rtX .
iyto1k1kzw = rtP . Integrator1_IC_pyqrlbgsst ; rtX . pkxrt4qo4z = rtP .
Integrator2_IC_buumrjnrb4 ; rtDW . guwv0f3uot [ 0 ] = rtP .
Memory5_X0_ly2u5imul2 ; rtDW . guwv0f3uot [ 1 ] = rtP . Memory5_X0_ly2u5imul2
; rtDW . jc3c25clri = false ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW .
azcmulp3j0 [ i ] = 0.0 ; rtDW . jbzxiyzok1 [ i ] = 0.0 ; } rtDW . hrj53k3isf
= 0.0 ; rtDW . f0qbsmk4ex = 0.0 ; rtDW . pfrwigqbzn = 7.9577471545947667 ; {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; sfcnInitializeConditions ( rts
) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . orkc55dufk
= rtP . LPFp_InitialStates_ellhhmyoul ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW
. auvkbyqkxd [ i ] = 0.0 ; rtDW . f3k0bkdqnd [ i ] = 0.0 ; rtDW . h0qgaci0at
[ i ] = 0.0 ; } rtDW . ggorbvxv0b = rtP . Memory1_X0_lhnyvl10ey ; rtDW .
ilfjamszda = rtP . Memory2_X0_fhlqqz2zyl ; rtDW . ewze1iozrz = rtP .
Memory6_X0_mszfa5opgb ; rtDW . bkwxpr2rpy = rtP . Memory7_X0_n0v1puhk2a ;
rtDW . l0gdo0gwee = rtP . Memory3_X0_poxy2k1s5q ; rtDW . jy5gknzcfu = rtP .
Memory4_X0_jv1vcihuqt ; ait2csy21y ( & rtDW . avezulewcn ) ; rtDW .
nkbjhdynsp = rtP . LPFq_InitialStates_jxyjjfazjv ; e1ux3zzmti ( & rtDW .
dvrqjotubu ) ; rtX . pvsidq4mg0 = rtP . Integrator_IC_dgb0cuklt3 ; rtX .
hemro31n34 = rtP . Integrator1_IC_etwibdpf3l ; rtX . p5jpc4ehox = rtP .
Integrator2_IC_i4bblare5u ; rtDW . nom2ms4idi [ 0 ] = rtP .
Memory5_X0_mzdqwrsacr ; rtDW . nom2ms4idi [ 1 ] = rtP . Memory5_X0_mzdqwrsacr
; rtDW . inwfij3epu = false ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW .
gaht5h2guw [ i ] = 0.0 ; rtDW . czc2sb2jwa [ i ] = 0.0 ; } rtDW . anaa2i2evl
= 0.0 ; rtDW . k0nz2julpt = 0.0 ; rtDW . lnjgkjkghh = 7.9577471545947667 ; {
SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; sfcnInitializeConditions ( rts
) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . ldb4vi0ha4
= rtP . LPFp_InitialStates_awo4cpuing ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW
. k2lslkrofb [ i ] = 0.0 ; rtDW . o2kydmp2r4 [ i ] = 0.0 ; rtDW . i2tar503fo
[ i ] = 0.0 ; } rtX . ihfpfs5hha = rtP . Integrator_IC_hhogk15lld ; rtX .
mejopo4his = rtP . Integrator1_IC_jdydknk1ci ; } void MdlStart ( void ) { {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 5 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 7 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
static int_T rt_ToWksWidths [ ] = { 5 } ; static int_T rt_ToWksNumDimensions
[ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 5 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static const char_T * rt_ToWksLabels [ ] = { "" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) ,
( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ;
static const char_T rt_ToWksBlockName [ ] = "nodes4/Schedule" ; rtDW .
njuiuoq00q . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "schedule" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName
) ; if ( rtDW . njuiuoq00q . LoggedData == ( NULL ) ) return ; } { int_T
dimensions [ 1 ] = { 1 } ; rtDW . l4tlfv342r . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "t" , SS_DOUBLE , 0 , 0 , 0 , 1 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . l4tlfv342r . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . l5yezso4td . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "P" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . l5yezso4td . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . hembuefnfy . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Q" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . hembuefnfy . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . jhyvglnaqs . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "V" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . jhyvglnaqs . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . fqpl3agz2v . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "f" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . fqpl3agz2v . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . fw0ubz1mel . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Data2Rx" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . fw0ubz1mel . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . frfdkzrjsf . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "Data1Rx" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 1.0 , 1 ) ; if (
rtDW . frfdkzrjsf . LoggedData == ( NULL ) ) return ; } rtDW . h1t1phh10c [ 0
] = rtP . DataStoreMemory_InitialValue [ 0 ] ; rtDW . h1t1phh10c [ 1 ] = rtP
. DataStoreMemory_InitialValue [ 1 ] ; rtDW . h1t1phh10c [ 2 ] = rtP .
DataStoreMemory_InitialValue [ 2 ] ; rtDW . h1t1phh10c [ 3 ] = rtP .
DataStoreMemory_InitialValue [ 3 ] ; rtDW . foiy3odoz1 [ 0 ] = rtP .
DataStoreMemory1_InitialValue [ 0 ] ; rtDW . foiy3odoz1 [ 1 ] = rtP .
DataStoreMemory1_InitialValue [ 1 ] ; rtDW . foiy3odoz1 [ 2 ] = rtP .
DataStoreMemory1_InitialValue [ 2 ] ; rtDW . foiy3odoz1 [ 3 ] = rtP .
DataStoreMemory1_InitialValue [ 3 ] ; rtDW . pizmexwruz [ 0 ] = rtP .
DataStoreMemory2_InitialValue [ 0 ] ; rtDW . pizmexwruz [ 1 ] = rtP .
DataStoreMemory2_InitialValue [ 1 ] ; rtDW . pizmexwruz [ 2 ] = rtP .
DataStoreMemory2_InitialValue [ 2 ] ; rtDW . pizmexwruz [ 3 ] = rtP .
DataStoreMemory2_InitialValue [ 3 ] ; rtDW . k5wmx351m0 [ 0 ] = rtP .
DataStoreMemory3_InitialValue [ 0 ] ; rtDW . k5wmx351m0 [ 1 ] = rtP .
DataStoreMemory3_InitialValue [ 1 ] ; rtDW . k5wmx351m0 [ 2 ] = rtP .
DataStoreMemory3_InitialValue [ 2 ] ; rtDW . k5wmx351m0 [ 3 ] = rtP .
DataStoreMemory3_InitialValue [ 3 ] ; rtDW . fmmswgsion [ 0 ] = rtP .
DataStoreMemory4_InitialValue [ 0 ] ; rtDW . fmmswgsion [ 1 ] = rtP .
DataStoreMemory4_InitialValue [ 1 ] ; rtDW . fmmswgsion [ 2 ] = rtP .
DataStoreMemory4_InitialValue [ 2 ] ; rtDW . fmmswgsion [ 3 ] = rtP .
DataStoreMemory4_InitialValue [ 3 ] ; rtDW . aboia0klkk [ 0 ] = rtP .
DataStoreMemory5_InitialValue [ 0 ] ; rtDW . aboia0klkk [ 1 ] = rtP .
DataStoreMemory5_InitialValue [ 1 ] ; rtDW . aboia0klkk [ 2 ] = rtP .
DataStoreMemory5_InitialValue [ 2 ] ; rtDW . aboia0klkk [ 3 ] = rtP .
DataStoreMemory5_InitialValue [ 3 ] ; MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T eybee5p0jv ; real_T nj4hdikini ; real_T po3ui3vu2a ;
real_T k0czgknnch ; real_T jktgfmsgij ; int32_T k ; real_T nk5sxhfvay ;
real_T igsk2g4zdx ; real_T igypfqosqo ; real_T mq222t1tfk [ 10 ] ; real_T
czozaga1lk [ 5 ] ; real_T ezbcrqnwp0 ; int32_T i ; static const int8_T ir [
11 ] = { 0 , 0 , 0 , 2 , 4 , 6 , 8 , 11 , 14 , 17 , 20 } ; static const
int8_T ir_p [ 11 ] = { 0 , 1 , 2 , 2 , 2 , 3 , 4 , 4 , 4 , 4 , 4 } ; static
const int8_T jc [ 20 ] = { 2 , 12 , 3 , 13 , 4 , 6 , 5 , 7 , 0 , 4 , 8 , 1 ,
5 , 9 , 0 , 2 , 10 , 1 , 3 , 11 } ; static const int8_T jc_p [ 4 ] = { 4 , 5
, 8 , 9 } ; real_T fur25gpj4d_idx_0 ; real_T fur25gpj4d_idx_1 ; rtB .
ek3a1451ay [ 0 ] = rtDW . h1t1phh10c [ 0 ] ; rtB . ek3a1451ay [ 1 ] = rtDW .
h1t1phh10c [ 1 ] ; rtB . ek3a1451ay [ 2 ] = rtDW . h1t1phh10c [ 2 ] ; rtB .
ek3a1451ay [ 3 ] = rtDW . h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0
) ; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { kpi03nmwlh ( rtB . ek3a1451ay
, rtB . dpgwwjc2rz [ 0 ] , & rtB . nlrcxogbog , ( drnct5ly2o * ) & rtP .
nlrcxogbog ) ; rtDW . h1t1phh10c [ 0 ] = rtB . nlrcxogbog . ovjujdzpjt [ 0 ]
; rtDW . h1t1phh10c [ 1 ] = rtB . nlrcxogbog . ovjujdzpjt [ 1 ] ; rtDW .
h1t1phh10c [ 2 ] = rtB . nlrcxogbog . ovjujdzpjt [ 2 ] ; rtDW . h1t1phh10c [
3 ] = rtB . nlrcxogbog . ovjujdzpjt [ 3 ] ; } rtB . hoq5gatyaq [ 0 ] = rtDW .
foiy3odoz1 [ 0 ] ; rtB . hoq5gatyaq [ 1 ] = rtDW . foiy3odoz1 [ 1 ] ; rtB .
hoq5gatyaq [ 2 ] = rtDW . foiy3odoz1 [ 2 ] ; rtB . hoq5gatyaq [ 3 ] = rtDW .
foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fntkhkkhap =
rtDW . mjqxgo2das ; rtB . biin3vhjc0 = rtDW . lstr5kczd4 ; rtB . kkx4ezyhkw =
rtDW . ex3o4uqzc2 ; rtB . mpyof2qigx = rtDW . mcbh12k100 ; rtB . fypbjuyz3n =
rtDW . ahv3cotbw2 ; rtB . mco3v3iige = rtDW . p5sygl0ymh ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { o3zilu53kc ( rtB . fntkhkkhap , rtB .
biin3vhjc0 , rtB . kkx4ezyhkw , rtB . mpyof2qigx , rtB . fypbjuyz3n , rtB .
mco3v3iige , rtP . Constant_Value , & rtB . ozftnlfeg3 , & rtDW . ozftnlfeg3
, ( m5tur4wi4k * ) & rtP . ozftnlfeg3 ) ; ezbcrqnwp0 = rtB . ozftnlfeg3 .
dberndtk2w ; ezbcrqnwp0 -= rtP . LPFq_DenCoef [ 1 ] * rtDW . f5c0nsumji ;
rtDW . gidygjlsh2 = ezbcrqnwp0 / rtP . LPFq_DenCoef [ 0 ] ; ezbcrqnwp0 = rtP
. LPFq_NumCoef [ 0 ] * rtDW . gidygjlsh2 ; ezbcrqnwp0 += rtP . LPFq_NumCoef [
1 ] * rtDW . f5c0nsumji ; rtB . hbtkhijkte = ezbcrqnwp0 ; } if (
ssIsSampleHit ( rtS , 4 , 0 ) ) { kjaxztqeed ( rtB . hoq5gatyaq , rtB .
hbtkhijkte , & rtB . pz2stfwruz , ( ewvp3cxhdz * ) & rtP . pz2stfwruz ) ;
rtDW . foiy3odoz1 [ 0 ] = rtB . pz2stfwruz . bbcbwrpqmg [ 0 ] ; rtDW .
foiy3odoz1 [ 1 ] = rtB . pz2stfwruz . bbcbwrpqmg [ 1 ] ; rtDW . foiy3odoz1 [
2 ] = rtB . pz2stfwruz . bbcbwrpqmg [ 2 ] ; rtDW . foiy3odoz1 [ 3 ] = rtB .
pz2stfwruz . bbcbwrpqmg [ 3 ] ; } rtB . ljwqffhvl4 [ 0 ] = rtDW . pizmexwruz
[ 0 ] ; rtB . ljwqffhvl4 [ 1 ] = rtDW . pizmexwruz [ 1 ] ; rtB . ljwqffhvl4 [
2 ] = rtDW . pizmexwruz [ 2 ] ; rtB . ljwqffhvl4 [ 3 ] = rtDW . pizmexwruz [
3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { h4j3c4exvj ( rtB . ljwqffhvl4 ,
rtB . ozftnlfeg3 . on2dguwvvl , & rtB . b4zolxyidp , ( ndkw5mnz3z * ) & rtP .
b4zolxyidp ) ; rtDW . pizmexwruz [ 0 ] = rtB . b4zolxyidp . c03pdi1rvc [ 0 ]
; rtDW . pizmexwruz [ 1 ] = rtB . b4zolxyidp . c03pdi1rvc [ 1 ] ; rtDW .
pizmexwruz [ 2 ] = rtB . b4zolxyidp . c03pdi1rvc [ 2 ] ; rtDW . pizmexwruz [
3 ] = rtB . b4zolxyidp . c03pdi1rvc [ 3 ] ; } rtB . h4k23zmq31 [ 0 ] = rtDW .
k5wmx351m0 [ 0 ] ; rtB . h4k23zmq31 [ 1 ] = rtDW . k5wmx351m0 [ 1 ] ; rtB .
h4k23zmq31 [ 2 ] = rtDW . k5wmx351m0 [ 2 ] ; rtB . h4k23zmq31 [ 3 ] = rtDW .
k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { akzc515hdq ( rtB .
h4k23zmq31 , rtB . dpgwwjc2rz [ 3 ] , & rtB . nybhsuuh1p , ( nbb0zpvvhm * ) &
rtP . nybhsuuh1p ) ; rtDW . k5wmx351m0 [ 0 ] = rtB . nybhsuuh1p . mesgqmrxmy
[ 0 ] ; rtDW . k5wmx351m0 [ 1 ] = rtB . nybhsuuh1p . mesgqmrxmy [ 1 ] ; rtDW
. k5wmx351m0 [ 2 ] = rtB . nybhsuuh1p . mesgqmrxmy [ 2 ] ; rtDW . k5wmx351m0
[ 3 ] = rtB . nybhsuuh1p . mesgqmrxmy [ 3 ] ; } rtB . jsillufvig [ 0 ] = rtDW
. fmmswgsion [ 0 ] ; rtB . jsillufvig [ 1 ] = rtDW . fmmswgsion [ 1 ] ; rtB .
jsillufvig [ 2 ] = rtDW . fmmswgsion [ 2 ] ; rtB . jsillufvig [ 3 ] = rtDW .
fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . d2kvmgvdht [
0 ] = rtP . Central_Integral_Gain * 0.0 ; rtB . d2kvmgvdht [ 1 ] = rtP .
Central_Integral_Gain * 0.0 ; ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . c5eu0ckh53 = ( ezbcrqnwp0 >= rtP .
Step_Time ) ; } if ( rtDW . c5eu0ckh53 == 1 ) { rtB . okzfmxk5yy = rtP .
Step_YFinal ; } else { rtB . okzfmxk5yy = rtP . Step_Y0 ; } } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { onerdwipjp ( 0.0 , rtB . okzfmxk5yy , & rtB
. j20pq3r21f , & rtDW . j20pq3r21f , ( n1y0minqnv * ) & rtP . j20pq3r21f ) ;
rtB . m1vu1obgik [ 0 ] = rtP . Distributed_integral_Gain * rtB . j20pq3r21f .
ioo1a4zpmx [ 0 ] ; rtB . m1vu1obgik [ 1 ] = rtP . Distributed_integral_Gain *
rtB . j20pq3r21f . ioo1a4zpmx [ 1 ] ; } po3ui3vu2a = rtX . myddfjqwmy ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . al0bnq55uc = ( ezbcrqnwp0 >= rtP .
Step_Time_lmjjonohpb ) ; } if ( rtDW . al0bnq55uc == 1 ) { nk5sxhfvay = rtP .
Step_YFinal_eq3o4yb5hk ; } else { nk5sxhfvay = rtP . Step_Y0_c2n03dykfo ; }
igsk2g4zdx = ( rtP . Constant_Value_pjdbxn5jaj - rtP . upi_Gain * 0.0 ) *
nk5sxhfvay ; rtB . kcbmknce0k = rtP . Gain_Gain * igsk2g4zdx ; } po3ui3vu2a
+= rtB . kcbmknce0k ; k0czgknnch = rtX . idks32lhev ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { igypfqosqo = ( rtP . Constant1_Value - 0.0 ) * nk5sxhfvay ;
rtB . lq5dbqfp25 = rtP . Gain2_Gain * igypfqosqo ; } jktgfmsgij = rtX .
hnfrxgtkqe ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { nk5sxhfvay = ( 0.0 - 0.0
) * nk5sxhfvay ; rtB . ld4l31qhaw = rtP . Gain4_Gain * nk5sxhfvay ; }
k0czgknnch = ( k0czgknnch + rtB . lq5dbqfp25 ) + ( jktgfmsgij + rtB .
ld4l31qhaw ) ; fur25gpj4d_idx_0 = rtP . Warrior_Gain * po3ui3vu2a ;
fur25gpj4d_idx_1 = rtP . Warrior_Gain * k0czgknnch ; if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { rtB . fchnjsvgwh [ 0 ] = rtDW . oktxx1jm30 [ 0 ] ; rtB .
fchnjsvgwh [ 1 ] = rtDW . oktxx1jm30 [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 ,
0 ) ) { for ( i = 0 ; i < 5 ; i ++ ) { czozaga1lk [ i ] = 0.0 ; } if ( ! rtDW
. dli3x1zfp1 ) { rtDW . eraemmnzoz = rtP . consensus_dr_d4i4gfbgeo [ (
int32_T ) rtP . Constant_Value - 1 ] ; rtDW . dli3x1zfp1 = true ; } if (
czozaga1lk [ 0 ] > 0.0 ) { rtDW . fvdlnsmpbl [ ( int32_T ) czozaga1lk [ 0 ] -
1 ] = czozaga1lk [ 1 ] ; rtDW . hgisorl0lv [ ( int32_T ) czozaga1lk [ 0 ] - 1
] = czozaga1lk [ 4 ] ; } rtDW . fvdlnsmpbl [ ( int32_T ) rtP . Constant_Value
- 1 ] = rtB . dpgwwjc2rz [ 3 ] ; rtDW . hgisorl0lv [ ( int32_T ) rtP .
Constant_Value - 1 ] = rtB . fchnjsvgwh [ 0 ] ; ezbcrqnwp0 = rtDW .
hgisorl0lv [ 0 ] - rtB . fchnjsvgwh [ 0 ] ; ezbcrqnwp0 += rtDW . hgisorl0lv [
1 ] - rtB . fchnjsvgwh [ 0 ] ; ezbcrqnwp0 += rtDW . hgisorl0lv [ 2 ] - rtB .
fchnjsvgwh [ 0 ] ; ezbcrqnwp0 += rtDW . hgisorl0lv [ 3 ] - rtB . fchnjsvgwh [
0 ] ; rtDW . ggpdvqbik4 = ( rtDW . ggpdvqbik4 + rtP . consensus_ts_buyezdbmmn
) + rtDW . eraemmnzoz ; rtDW . bc1tq0iten = ( rtDW . bc1tq0iten + rtP .
consensus_ts_buyezdbmmn ) + rtDW . eraemmnzoz ; rtDW . cd5a0neolm += ( ( ( (
( ( rtB . dpgwwjc2rz [ 3 ] - rtDW . fvdlnsmpbl [ 0 ] ) + ( rtB . dpgwwjc2rz [
3 ] - rtDW . fvdlnsmpbl [ 1 ] ) ) + ( rtB . dpgwwjc2rz [ 3 ] - rtDW .
fvdlnsmpbl [ 2 ] ) ) + ( rtB . dpgwwjc2rz [ 3 ] - rtDW . fvdlnsmpbl [ 3 ] ) )
* 0.01 + ( 50.0 - rtB . dpgwwjc2rz [ 3 ] ) * 2.0 ) + 0.1 * ezbcrqnwp0 ) * (
rtP . consensus_ts_buyezdbmmn + rtDW . eraemmnzoz ) ; rtB . ibl2erstls [ 0 ]
= ( rtDW . cd5a0neolm - rtB . dpgwwjc2rz [ 3 ] ) * rtP . Degenerated_Gain ;
rtB . ibl2erstls [ 1 ] = rtP . Degenerated_Gain * 0.0 ; } if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnOutputs ( rts , 0 ) ; } rtB . dti2carlq5 = rtP .
Distributed_integral_w_Gain * rtB . bxyd4fbh0g ; } rtB . mguxqfcdvk [ 0 ] = (
( ( ( ( real_T ) rtP . KSencondaryless_Value + rtB . d2kvmgvdht [ 0 ] ) + rtB
. m1vu1obgik [ 0 ] ) + fur25gpj4d_idx_0 ) + rtB . ibl2erstls [ 0 ] ) + rtB .
dti2carlq5 ; rtB . mguxqfcdvk [ 1 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value + rtB . d2kvmgvdht [ 1 ] ) + rtB . m1vu1obgik [ 1 ] ) +
fur25gpj4d_idx_1 ) + rtB . ibl2erstls [ 1 ] ) + rtP . KSencondaryless1_Value
; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { jtbhfmltwq ( rtB . jsillufvig , rtB
. mguxqfcdvk [ 0 ] , & rtB . jlne01gbu0 , ( ozv2axw2sw * ) & rtP . jlne01gbu0
) ; rtDW . fmmswgsion [ 0 ] = rtB . jlne01gbu0 . hgxfgflt2m [ 0 ] ; rtDW .
fmmswgsion [ 1 ] = rtB . jlne01gbu0 . hgxfgflt2m [ 1 ] ; rtDW . fmmswgsion [
2 ] = rtB . jlne01gbu0 . hgxfgflt2m [ 2 ] ; rtDW . fmmswgsion [ 3 ] = rtB .
jlne01gbu0 . hgxfgflt2m [ 3 ] ; } rtB . nebhkpb5ai [ 0 ] = rtDW . aboia0klkk
[ 0 ] ; rtB . nebhkpb5ai [ 1 ] = rtDW . aboia0klkk [ 1 ] ; rtB . nebhkpb5ai [
2 ] = rtDW . aboia0klkk [ 2 ] ; rtB . nebhkpb5ai [ 3 ] = rtDW . aboia0klkk [
3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { jtbhfmltwq ( rtB . nebhkpb5ai ,
rtB . mguxqfcdvk [ 1 ] , & rtB . jrosma4ai4 , ( ozv2axw2sw * ) & rtP .
jrosma4ai4 ) ; rtDW . aboia0klkk [ 0 ] = rtB . jrosma4ai4 . hgxfgflt2m [ 0 ]
; rtDW . aboia0klkk [ 1 ] = rtB . jrosma4ai4 . hgxfgflt2m [ 1 ] ; rtDW .
aboia0klkk [ 2 ] = rtB . jrosma4ai4 . hgxfgflt2m [ 2 ] ; rtDW . aboia0klkk [
3 ] = rtB . jrosma4ai4 . hgxfgflt2m [ 3 ] ; } if ( ssIsSampleHit ( rtS , 2 ,
0 ) ) { ezbcrqnwp0 = rtB . ozftnlfeg3 . n0fuel1bnn ; ezbcrqnwp0 -= rtP .
LPFp_DenCoef [ 1 ] * rtDW . a5w40p1bws ; rtDW . jxsk15cftx = ezbcrqnwp0 / rtP
. LPFp_DenCoef [ 0 ] ; ezbcrqnwp0 = rtP . LPFp_NumCoef [ 0 ] * rtDW .
jxsk15cftx ; ezbcrqnwp0 += rtP . LPFp_NumCoef [ 1 ] * rtDW . a5w40p1bws ; rtB
. iewvn51hd3 = ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { for ( i
= 0 ; i < 5 ; i ++ ) { czozaga1lk [ i ] = 0.0 ; } if ( czozaga1lk [ 0 ] > 0.0
) { rtDW . blweiavnmj [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ]
; rtDW . cxib0dsdcq [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 2 ] ;
rtDW . fs03kermta [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 3 ] ; }
rtDW . blweiavnmj [ ( int32_T ) rtP . Constant_Value - 1 ] = rtB . dpgwwjc2rz
[ 3 ] ; rtDW . cxib0dsdcq [ ( int32_T ) rtP . Constant_Value - 1 ] = rtB .
ozftnlfeg3 . on2dguwvvl ; rtDW . fs03kermta [ ( int32_T ) rtP .
Constant_Value - 1 ] = rtB . hbtkhijkte ; } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . h1tgqdz5v2 = rtP . Gain1_Gain * igsk2g4zdx ; rtB . gq1khgfhm2 =
rtP . Gain3_Gain * igypfqosqo ; rtB . n0mg2py0tt = rtP . Gain5_Gain *
nk5sxhfvay ; { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; sfcnOutputs (
rts , 0 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; sfcnOutputs (
rts , 0 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; sfcnOutputs (
rts , 0 ) ; } rtB . ec4ppad44q = rtDW . h31mfjlljs ; rtB . awk2wo0fe2 = rtDW
. efdih4dveq ; } jktgfmsgij = ssGetT ( rtS ) ; jktgfmsgij -= 0.0 ; jktgfmsgij
= muDoubleScalarRem ( jktgfmsgij , rtP . Constant_Value_pjliw2x4cg ) ;
ezbcrqnwp0 = look1_binlxpw ( jktgfmsgij , rtP . LookUpTable1_bp01Data , rtP .
LookUpTable1_tableData , 3U ) ; rtB . icb23pk4yt [ 0 ] = rtB . n2zlvavzvj [ 4
] ; rtB . icb23pk4yt [ 1 ] = rtB . n2zlvavzvj [ 5 ] ; rtB . icb23pk4yt [ 2 ]
= rtB . iodvmyfik4 [ 4 ] ; rtB . icb23pk4yt [ 3 ] = rtB . iodvmyfik4 [ 5 ] ;
rtB . icb23pk4yt [ 4 ] = rtB . dnqnzblmbp [ 4 ] ; rtB . icb23pk4yt [ 5 ] =
rtB . dnqnzblmbp [ 5 ] ; rtB . icb23pk4yt [ 6 ] = rtB . dpgwwjc2rz [ 4 ] ;
rtB . icb23pk4yt [ 7 ] = rtB . dpgwwjc2rz [ 5 ] ; rtB . icb23pk4yt [ 8 ] =
rtB . ec4ppad44q / ezbcrqnwp0 ; rtB . icb23pk4yt [ 9 ] = rtB . awk2wo0fe2 /
ezbcrqnwp0 ; for ( i = 0 ; i < 10 ; i ++ ) { mq222t1tfk [ i ] = 0.0 ; } for (
i = 0 ; i < 10 ; i ++ ) { for ( k = ir [ i ] ; k < ir [ i + 1 ] ; k ++ ) {
mq222t1tfk [ i ] += rtP . StateSpace_C [ k ] * rtX . jqdufexgzv [ jc [ k ] ]
; } } for ( i = 0 ; i < 10 ; i ++ ) { for ( k = ir_p [ i ] ; k < ir_p [ i + 1
] ; k ++ ) { mq222t1tfk [ i ] += rtP . StateSpace_D [ k ] * rtB . icb23pk4yt
[ jc_p [ k ] ] ; } } rtB . poglkcfqy3 = rtP . donotdeletethisgain_Gain *
mq222t1tfk [ 3 ] ; rtB . f5kuq3shj4 = rtP .
donotdeletethisgain_Gain_lzvr4drqwu * mq222t1tfk [ 2 ] ; rtB . aczh1lvgar [ 0
] = rtDW . h1t1phh10c [ 0 ] ; rtB . aczh1lvgar [ 1 ] = rtDW . h1t1phh10c [ 1
] ; rtB . aczh1lvgar [ 2 ] = rtDW . h1t1phh10c [ 2 ] ; rtB . aczh1lvgar [ 3 ]
= rtDW . h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { kpi03nmwlh
( rtB . aczh1lvgar , rtB . n2zlvavzvj [ 0 ] , & rtB . i0nb5cbdli , (
drnct5ly2o * ) & rtP . i0nb5cbdli ) ; rtDW . h1t1phh10c [ 0 ] = rtB .
i0nb5cbdli . ovjujdzpjt [ 0 ] ; rtDW . h1t1phh10c [ 1 ] = rtB . i0nb5cbdli .
ovjujdzpjt [ 1 ] ; rtDW . h1t1phh10c [ 2 ] = rtB . i0nb5cbdli . ovjujdzpjt [
2 ] ; rtDW . h1t1phh10c [ 3 ] = rtB . i0nb5cbdli . ovjujdzpjt [ 3 ] ; } rtB .
dzuta0dnpn [ 0 ] = rtDW . foiy3odoz1 [ 0 ] ; rtB . dzuta0dnpn [ 1 ] = rtDW .
foiy3odoz1 [ 1 ] ; rtB . dzuta0dnpn [ 2 ] = rtDW . foiy3odoz1 [ 2 ] ; rtB .
dzuta0dnpn [ 3 ] = rtDW . foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . hx0wj5yo2m = rtDW . n31fjbosih ; rtB . kcng2h2ox5 = rtDW .
bj3nvzbqqv ; rtB . d4jrh0gj3t = rtDW . pftedxldcl ; rtB . nhbi4wyipn = rtDW .
ffb5al3bwy ; rtB . pdvnbdhjm2 = rtDW . l2sbaaoqpn ; rtB . mj22h2mmx5 = rtDW .
nha400jjfg ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { o3zilu53kc ( rtB .
hx0wj5yo2m , rtB . kcng2h2ox5 , rtB . d4jrh0gj3t , rtB . nhbi4wyipn , rtB .
pdvnbdhjm2 , rtB . mj22h2mmx5 , rtP . Constant_Value_azz3yrvlmm , & rtB .
a21clfzxwp , & rtDW . a21clfzxwp , ( m5tur4wi4k * ) & rtP . a21clfzxwp ) ;
ezbcrqnwp0 = rtB . a21clfzxwp . dberndtk2w ; ezbcrqnwp0 -= rtP .
LPFq_DenCoef_jqztpz5qrm [ 1 ] * rtDW . eanwkjl2vy ; rtDW . lv3zjk5f1k =
ezbcrqnwp0 / rtP . LPFq_DenCoef_jqztpz5qrm [ 0 ] ; ezbcrqnwp0 = rtP .
LPFq_NumCoef_dol51wazt2 [ 0 ] * rtDW . lv3zjk5f1k ; ezbcrqnwp0 += rtP .
LPFq_NumCoef_dol51wazt2 [ 1 ] * rtDW . eanwkjl2vy ; rtB . mfwsny1flw =
ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { kjaxztqeed ( rtB .
dzuta0dnpn , rtB . mfwsny1flw , & rtB . mfw2ixjjzd , ( ewvp3cxhdz * ) & rtP .
mfw2ixjjzd ) ; rtDW . foiy3odoz1 [ 0 ] = rtB . mfw2ixjjzd . bbcbwrpqmg [ 0 ]
; rtDW . foiy3odoz1 [ 1 ] = rtB . mfw2ixjjzd . bbcbwrpqmg [ 1 ] ; rtDW .
foiy3odoz1 [ 2 ] = rtB . mfw2ixjjzd . bbcbwrpqmg [ 2 ] ; rtDW . foiy3odoz1 [
3 ] = rtB . mfw2ixjjzd . bbcbwrpqmg [ 3 ] ; } rtB . cbfpuf2or0 [ 0 ] = rtDW .
pizmexwruz [ 0 ] ; rtB . cbfpuf2or0 [ 1 ] = rtDW . pizmexwruz [ 1 ] ; rtB .
cbfpuf2or0 [ 2 ] = rtDW . pizmexwruz [ 2 ] ; rtB . cbfpuf2or0 [ 3 ] = rtDW .
pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { h4j3c4exvj ( rtB .
cbfpuf2or0 , rtB . a21clfzxwp . on2dguwvvl , & rtB . n3la5yge0s , (
ndkw5mnz3z * ) & rtP . n3la5yge0s ) ; rtDW . pizmexwruz [ 0 ] = rtB .
n3la5yge0s . c03pdi1rvc [ 0 ] ; rtDW . pizmexwruz [ 1 ] = rtB . n3la5yge0s .
c03pdi1rvc [ 1 ] ; rtDW . pizmexwruz [ 2 ] = rtB . n3la5yge0s . c03pdi1rvc [
2 ] ; rtDW . pizmexwruz [ 3 ] = rtB . n3la5yge0s . c03pdi1rvc [ 3 ] ; } rtB .
abwh33q232 [ 0 ] = rtDW . k5wmx351m0 [ 0 ] ; rtB . abwh33q232 [ 1 ] = rtDW .
k5wmx351m0 [ 1 ] ; rtB . abwh33q232 [ 2 ] = rtDW . k5wmx351m0 [ 2 ] ; rtB .
abwh33q232 [ 3 ] = rtDW . k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { akzc515hdq ( rtB . abwh33q232 , rtB . n2zlvavzvj [ 3 ] , & rtB .
lkguggosm5 , ( nbb0zpvvhm * ) & rtP . lkguggosm5 ) ; rtDW . k5wmx351m0 [ 0 ]
= rtB . lkguggosm5 . mesgqmrxmy [ 0 ] ; rtDW . k5wmx351m0 [ 1 ] = rtB .
lkguggosm5 . mesgqmrxmy [ 1 ] ; rtDW . k5wmx351m0 [ 2 ] = rtB . lkguggosm5 .
mesgqmrxmy [ 2 ] ; rtDW . k5wmx351m0 [ 3 ] = rtB . lkguggosm5 . mesgqmrxmy [
3 ] ; } rtB . b4slefd2sz [ 0 ] = rtDW . fmmswgsion [ 0 ] ; rtB . b4slefd2sz [
1 ] = rtDW . fmmswgsion [ 1 ] ; rtB . b4slefd2sz [ 2 ] = rtDW . fmmswgsion [
2 ] ; rtB . b4slefd2sz [ 3 ] = rtDW . fmmswgsion [ 3 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . ctf1kxqmdo [ 0 ] = rtP .
Central_Integral_Gain_goqzg23ob0 * 0.0 ; rtB . ctf1kxqmdo [ 1 ] = rtP .
Central_Integral_Gain_goqzg23ob0 * 0.0 ; ezbcrqnwp0 = ssGetTaskTime ( rtS , 1
) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . icvisi4y50 = ( ezbcrqnwp0 >=
rtP . Step_Time_dq4ffjhuug ) ; } if ( rtDW . icvisi4y50 == 1 ) { rtB .
pgkimqavpk = rtP . Step_YFinal_dwtygfsqzb ; } else { rtB . pgkimqavpk = rtP .
Step_Y0_cang05wkqp ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { onerdwipjp (
0.0 , rtB . pgkimqavpk , & rtB . pxlv2lf0yq , & rtDW . pxlv2lf0yq , (
n1y0minqnv * ) & rtP . pxlv2lf0yq ) ; rtB . f5aj101k3a [ 0 ] = rtP .
Distributed_integral_Gain_lyaatikasw * rtB . pxlv2lf0yq . ioo1a4zpmx [ 0 ] ;
rtB . f5aj101k3a [ 1 ] = rtP . Distributed_integral_Gain_lyaatikasw * rtB .
pxlv2lf0yq . ioo1a4zpmx [ 1 ] ; } jktgfmsgij = rtX . cvbao2hes3 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . pjaxqqimom = ( ezbcrqnwp0 >= rtP .
Step_Time_mv0kh4fqoa ) ; } if ( rtDW . pjaxqqimom == 1 ) { igypfqosqo = rtP .
Step_YFinal_nghuf4omva ; } else { igypfqosqo = rtP . Step_Y0_f5gzha2dmu ; }
igsk2g4zdx = ( rtP . Constant_Value_dj154fox1x - rtP . upi_Gain_fugo0zwoc2 *
0.0 ) * igypfqosqo ; rtB . kkm103ywxt = rtP . Gain_Gain_hehylgfino *
igsk2g4zdx ; } jktgfmsgij += rtB . kkm103ywxt ; k0czgknnch = rtX . nce055ezz1
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { nk5sxhfvay = ( rtP .
Constant1_Value_jsqksnanjl - 0.0 ) * igypfqosqo ; rtB . e1nfog11ri = rtP .
Gain2_Gain_a1i5r3i1pq * nk5sxhfvay ; } po3ui3vu2a = rtX . cenhjcoeh3 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { igypfqosqo = ( 0.0 - 0.0 ) * igypfqosqo ;
rtB . d535qgtjbe = rtP . Gain4_Gain_dk05bit35d * igypfqosqo ; } k0czgknnch =
( k0czgknnch + rtB . e1nfog11ri ) + ( po3ui3vu2a + rtB . d535qgtjbe ) ;
fur25gpj4d_idx_0 = rtP . Warrior_Gain_l1vhyoa1db * jktgfmsgij ;
fur25gpj4d_idx_1 = rtP . Warrior_Gain_l1vhyoa1db * k0czgknnch ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . kdglpydeda [ 0 ] = rtDW . bugcdre0xq
[ 0 ] ; rtB . kdglpydeda [ 1 ] = rtDW . bugcdre0xq [ 1 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { for ( i = 0 ; i < 5 ; i ++ ) { czozaga1lk [
i ] = 0.0 ; } if ( ! rtDW . nb5pthjmwg ) { rtDW . lyohx44v2w = rtP .
consensus_dr [ ( int32_T ) rtP . Constant_Value_azz3yrvlmm - 1 ] ; rtDW .
nb5pthjmwg = true ; } if ( czozaga1lk [ 0 ] > 0.0 ) { rtDW . e23cqdlwby [ (
int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ; rtDW . og10ihhnhf [ (
int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 4 ] ; } rtDW . e23cqdlwby [ (
int32_T ) rtP . Constant_Value_azz3yrvlmm - 1 ] = rtB . n2zlvavzvj [ 3 ] ;
rtDW . og10ihhnhf [ ( int32_T ) rtP . Constant_Value_azz3yrvlmm - 1 ] = rtB .
kdglpydeda [ 0 ] ; ezbcrqnwp0 = rtDW . og10ihhnhf [ 0 ] - rtB . kdglpydeda [
0 ] ; ezbcrqnwp0 += rtDW . og10ihhnhf [ 1 ] - rtB . kdglpydeda [ 0 ] ;
ezbcrqnwp0 += rtDW . og10ihhnhf [ 2 ] - rtB . kdglpydeda [ 0 ] ; ezbcrqnwp0
+= rtDW . og10ihhnhf [ 3 ] - rtB . kdglpydeda [ 0 ] ; rtDW . goy3rwgvfy = (
rtDW . goy3rwgvfy + rtP . consensus_ts ) + rtDW . lyohx44v2w ; rtDW .
oimg4prx1p = ( rtDW . oimg4prx1p + rtP . consensus_ts ) + rtDW . lyohx44v2w ;
rtDW . eopudmnicm += ( ( ( ( ( ( rtB . n2zlvavzvj [ 3 ] - rtDW . e23cqdlwby [
0 ] ) + ( rtB . n2zlvavzvj [ 3 ] - rtDW . e23cqdlwby [ 1 ] ) ) + ( rtB .
n2zlvavzvj [ 3 ] - rtDW . e23cqdlwby [ 2 ] ) ) + ( rtB . n2zlvavzvj [ 3 ] -
rtDW . e23cqdlwby [ 3 ] ) ) * 0.01 + ( 50.0 - rtB . n2zlvavzvj [ 3 ] ) * 2.0
) + 0.1 * ezbcrqnwp0 ) * ( rtP . consensus_ts + rtDW . lyohx44v2w ) ; rtB .
l523yuyruu [ 0 ] = ( rtDW . eopudmnicm - rtB . n2zlvavzvj [ 3 ] ) * rtP .
Degenerated_Gain_jajdw1laqg ; rtB . l523yuyruu [ 1 ] = rtP .
Degenerated_Gain_jajdw1laqg * 0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
{ SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; sfcnOutputs ( rts , 0 ) ; }
rtB . krez0hg5v1 = rtP . Distributed_integral_w_Gain_byjpmxfo1z * rtB .
ellko3pdhd ; } rtB . lgfjmq2ecm [ 0 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_bmosygzxe0 + rtB . ctf1kxqmdo [ 0 ] ) + rtB .
f5aj101k3a [ 0 ] ) + fur25gpj4d_idx_0 ) + rtB . l523yuyruu [ 0 ] ) + rtB .
krez0hg5v1 ; rtB . lgfjmq2ecm [ 1 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_bmosygzxe0 + rtB . ctf1kxqmdo [ 1 ] ) + rtB .
f5aj101k3a [ 1 ] ) + fur25gpj4d_idx_1 ) + rtB . l523yuyruu [ 1 ] ) + rtP .
KSencondaryless1_Value_meu1czdosl ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
jtbhfmltwq ( rtB . b4slefd2sz , rtB . lgfjmq2ecm [ 0 ] , & rtB . ae0vvuvpaf ,
( ozv2axw2sw * ) & rtP . ae0vvuvpaf ) ; rtDW . fmmswgsion [ 0 ] = rtB .
ae0vvuvpaf . hgxfgflt2m [ 0 ] ; rtDW . fmmswgsion [ 1 ] = rtB . ae0vvuvpaf .
hgxfgflt2m [ 1 ] ; rtDW . fmmswgsion [ 2 ] = rtB . ae0vvuvpaf . hgxfgflt2m [
2 ] ; rtDW . fmmswgsion [ 3 ] = rtB . ae0vvuvpaf . hgxfgflt2m [ 3 ] ; } rtB .
i52hyrlq2j [ 0 ] = rtDW . aboia0klkk [ 0 ] ; rtB . i52hyrlq2j [ 1 ] = rtDW .
aboia0klkk [ 1 ] ; rtB . i52hyrlq2j [ 2 ] = rtDW . aboia0klkk [ 2 ] ; rtB .
i52hyrlq2j [ 3 ] = rtDW . aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { jtbhfmltwq ( rtB . i52hyrlq2j , rtB . lgfjmq2ecm [ 1 ] , & rtB .
loojatj1b3 , ( ozv2axw2sw * ) & rtP . loojatj1b3 ) ; rtDW . aboia0klkk [ 0 ]
= rtB . loojatj1b3 . hgxfgflt2m [ 0 ] ; rtDW . aboia0klkk [ 1 ] = rtB .
loojatj1b3 . hgxfgflt2m [ 1 ] ; rtDW . aboia0klkk [ 2 ] = rtB . loojatj1b3 .
hgxfgflt2m [ 2 ] ; rtDW . aboia0klkk [ 3 ] = rtB . loojatj1b3 . hgxfgflt2m [
3 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { ezbcrqnwp0 = rtB . a21clfzxwp
. n0fuel1bnn ; ezbcrqnwp0 -= rtP . LPFp_DenCoef_nqtxjebx4f [ 1 ] * rtDW .
d5bnnktx4e ; rtDW . ghsofqsrqn = ezbcrqnwp0 / rtP . LPFp_DenCoef_nqtxjebx4f [
0 ] ; ezbcrqnwp0 = rtP . LPFp_NumCoef_ata2rzced3 [ 0 ] * rtDW . ghsofqsrqn ;
ezbcrqnwp0 += rtP . LPFp_NumCoef_ata2rzced3 [ 1 ] * rtDW . d5bnnktx4e ; rtB .
hen0mtsi3a = ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { for ( i =
0 ; i < 5 ; i ++ ) { czozaga1lk [ i ] = 0.0 ; } if ( czozaga1lk [ 0 ] > 0.0 )
{ rtDW . beo5lordfv [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ;
rtDW . f0slooz0kt [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 2 ] ;
rtDW . fi5ombzs0c [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 3 ] ; }
rtDW . beo5lordfv [ ( int32_T ) rtP . Constant_Value_azz3yrvlmm - 1 ] = rtB .
n2zlvavzvj [ 3 ] ; rtDW . f0slooz0kt [ ( int32_T ) rtP .
Constant_Value_azz3yrvlmm - 1 ] = rtB . a21clfzxwp . on2dguwvvl ; rtDW .
fi5ombzs0c [ ( int32_T ) rtP . Constant_Value_azz3yrvlmm - 1 ] = rtB .
mfwsny1flw ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . lxk0xwc3vx = rtP
. Gain1_Gain_eeq10lnvsz * igsk2g4zdx ; rtB . hkkbhcvcxm = rtP .
Gain3_Gain_nhcozfsh55 * nk5sxhfvay ; rtB . lmpvvsgbzc = rtP .
Gain5_Gain_jvhdnoddlf * igypfqosqo ; } rtB . adhev5qmdl = rtP .
donotdeletethisgain_Gain_pzf05cu4bk * mq222t1tfk [ 9 ] ; rtB . jkgsoin4ud =
rtP . donotdeletethisgain_Gain_iiylrrlcdf * mq222t1tfk [ 8 ] ; rtB .
fg3wll3qdz [ 0 ] = rtDW . h1t1phh10c [ 0 ] ; rtB . fg3wll3qdz [ 1 ] = rtDW .
h1t1phh10c [ 1 ] ; rtB . fg3wll3qdz [ 2 ] = rtDW . h1t1phh10c [ 2 ] ; rtB .
fg3wll3qdz [ 3 ] = rtDW . h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { kpi03nmwlh ( rtB . fg3wll3qdz , rtB . iodvmyfik4 [ 0 ] , & rtB .
mrc3jz2kzs , ( drnct5ly2o * ) & rtP . mrc3jz2kzs ) ; rtDW . h1t1phh10c [ 0 ]
= rtB . mrc3jz2kzs . ovjujdzpjt [ 0 ] ; rtDW . h1t1phh10c [ 1 ] = rtB .
mrc3jz2kzs . ovjujdzpjt [ 1 ] ; rtDW . h1t1phh10c [ 2 ] = rtB . mrc3jz2kzs .
ovjujdzpjt [ 2 ] ; rtDW . h1t1phh10c [ 3 ] = rtB . mrc3jz2kzs . ovjujdzpjt [
3 ] ; } rtB . keuugvf2im [ 0 ] = rtDW . foiy3odoz1 [ 0 ] ; rtB . keuugvf2im [
1 ] = rtDW . foiy3odoz1 [ 1 ] ; rtB . keuugvf2im [ 2 ] = rtDW . foiy3odoz1 [
2 ] ; rtB . keuugvf2im [ 3 ] = rtDW . foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . pazkwcssox = rtDW . hccpqibboh ; rtB . brmhwzxuee =
rtDW . mmm2iqducw ; rtB . g4tkowhewi = rtDW . caoih1mnoc ; rtB . j52dskeymb =
rtDW . ni0pxjjk34 ; rtB . fpqii21x5i = rtDW . hlgbmv2r55 ; rtB . ek0x1ax1lz =
rtDW . p2lhgag51t ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { o3zilu53kc ( rtB
. pazkwcssox , rtB . brmhwzxuee , rtB . g4tkowhewi , rtB . j52dskeymb , rtB .
fpqii21x5i , rtB . ek0x1ax1lz , rtP . Constant_Value_h1zp5rsdg2 , & rtB .
cwkcdvwsyb , & rtDW . cwkcdvwsyb , ( m5tur4wi4k * ) & rtP . cwkcdvwsyb ) ;
ezbcrqnwp0 = rtB . cwkcdvwsyb . dberndtk2w ; ezbcrqnwp0 -= rtP .
LPFq_DenCoef_h5sk4b0cdt [ 1 ] * rtDW . lnetbv1cgv ; rtDW . nknewvnn53 =
ezbcrqnwp0 / rtP . LPFq_DenCoef_h5sk4b0cdt [ 0 ] ; ezbcrqnwp0 = rtP .
LPFq_NumCoef_khkfqbsy5v [ 0 ] * rtDW . nknewvnn53 ; ezbcrqnwp0 += rtP .
LPFq_NumCoef_khkfqbsy5v [ 1 ] * rtDW . lnetbv1cgv ; rtB . n2mcguhbur =
ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { kjaxztqeed ( rtB .
keuugvf2im , rtB . n2mcguhbur , & rtB . pxgmr2o0yw , ( ewvp3cxhdz * ) & rtP .
pxgmr2o0yw ) ; rtDW . foiy3odoz1 [ 0 ] = rtB . pxgmr2o0yw . bbcbwrpqmg [ 0 ]
; rtDW . foiy3odoz1 [ 1 ] = rtB . pxgmr2o0yw . bbcbwrpqmg [ 1 ] ; rtDW .
foiy3odoz1 [ 2 ] = rtB . pxgmr2o0yw . bbcbwrpqmg [ 2 ] ; rtDW . foiy3odoz1 [
3 ] = rtB . pxgmr2o0yw . bbcbwrpqmg [ 3 ] ; } rtB . as33t0f0ow [ 0 ] = rtDW .
pizmexwruz [ 0 ] ; rtB . as33t0f0ow [ 1 ] = rtDW . pizmexwruz [ 1 ] ; rtB .
as33t0f0ow [ 2 ] = rtDW . pizmexwruz [ 2 ] ; rtB . as33t0f0ow [ 3 ] = rtDW .
pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { h4j3c4exvj ( rtB .
as33t0f0ow , rtB . cwkcdvwsyb . on2dguwvvl , & rtB . ejkqkpkoqg , (
ndkw5mnz3z * ) & rtP . ejkqkpkoqg ) ; rtDW . pizmexwruz [ 0 ] = rtB .
ejkqkpkoqg . c03pdi1rvc [ 0 ] ; rtDW . pizmexwruz [ 1 ] = rtB . ejkqkpkoqg .
c03pdi1rvc [ 1 ] ; rtDW . pizmexwruz [ 2 ] = rtB . ejkqkpkoqg . c03pdi1rvc [
2 ] ; rtDW . pizmexwruz [ 3 ] = rtB . ejkqkpkoqg . c03pdi1rvc [ 3 ] ; } rtB .
meko05j0sc [ 0 ] = rtDW . k5wmx351m0 [ 0 ] ; rtB . meko05j0sc [ 1 ] = rtDW .
k5wmx351m0 [ 1 ] ; rtB . meko05j0sc [ 2 ] = rtDW . k5wmx351m0 [ 2 ] ; rtB .
meko05j0sc [ 3 ] = rtDW . k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { akzc515hdq ( rtB . meko05j0sc , rtB . iodvmyfik4 [ 3 ] , & rtB .
omwjydko3j , ( nbb0zpvvhm * ) & rtP . omwjydko3j ) ; rtDW . k5wmx351m0 [ 0 ]
= rtB . omwjydko3j . mesgqmrxmy [ 0 ] ; rtDW . k5wmx351m0 [ 1 ] = rtB .
omwjydko3j . mesgqmrxmy [ 1 ] ; rtDW . k5wmx351m0 [ 2 ] = rtB . omwjydko3j .
mesgqmrxmy [ 2 ] ; rtDW . k5wmx351m0 [ 3 ] = rtB . omwjydko3j . mesgqmrxmy [
3 ] ; } rtB . lhj2ghm2f4 [ 0 ] = rtDW . fmmswgsion [ 0 ] ; rtB . lhj2ghm2f4 [
1 ] = rtDW . fmmswgsion [ 1 ] ; rtB . lhj2ghm2f4 [ 2 ] = rtDW . fmmswgsion [
2 ] ; rtB . lhj2ghm2f4 [ 3 ] = rtDW . fmmswgsion [ 3 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . dbqcdqyhwy [ 0 ] = rtP .
Central_Integral_Gain_oh2afxaxnl * 0.0 ; rtB . dbqcdqyhwy [ 1 ] = rtP .
Central_Integral_Gain_oh2afxaxnl * 0.0 ; ezbcrqnwp0 = ssGetTaskTime ( rtS , 1
) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . cl0xew40qh = ( ezbcrqnwp0 >=
rtP . Step_Time_fjiuqwecd2 ) ; } if ( rtDW . cl0xew40qh == 1 ) { rtB .
c02zl0czxs = rtP . Step_YFinal_mtlp5wwhqo ; } else { rtB . c02zl0czxs = rtP .
Step_Y0_flbxmwe3gl ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { onerdwipjp (
0.0 , rtB . c02zl0czxs , & rtB . jwxitznkuq , & rtDW . jwxitznkuq , (
n1y0minqnv * ) & rtP . jwxitznkuq ) ; rtB . pugsu0nevr [ 0 ] = rtP .
Distributed_integral_Gain_enwo1afavs * rtB . jwxitznkuq . ioo1a4zpmx [ 0 ] ;
rtB . pugsu0nevr [ 1 ] = rtP . Distributed_integral_Gain_enwo1afavs * rtB .
jwxitznkuq . ioo1a4zpmx [ 1 ] ; } jktgfmsgij = rtX . b1xdzpc02l ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . ewgbd1zlci = ( ezbcrqnwp0 >= rtP .
Step_Time_lgtvrypfrs ) ; } if ( rtDW . ewgbd1zlci == 1 ) { igypfqosqo = rtP .
Step_YFinal_ebnn1geyqd ; } else { igypfqosqo = rtP . Step_Y0_ejizp1gvg5 ; }
igsk2g4zdx = ( rtP . Constant_Value_fmoydh5knb - rtP . upi_Gain_mdo2blrdce *
0.0 ) * igypfqosqo ; rtB . bw14bin5hh = rtP . Gain_Gain_ktg4znma1i *
igsk2g4zdx ; } jktgfmsgij += rtB . bw14bin5hh ; k0czgknnch = rtX . iyto1k1kzw
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { nk5sxhfvay = ( rtP .
Constant1_Value_oexbx2rf3m - 0.0 ) * igypfqosqo ; rtB . ldw4br50ng = rtP .
Gain2_Gain_ftj3e0ljkf * nk5sxhfvay ; } po3ui3vu2a = rtX . pkxrt4qo4z ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { igypfqosqo = ( 0.0 - 0.0 ) * igypfqosqo ;
rtB . gsofcjddvn = rtP . Gain4_Gain_bati34bkvl * igypfqosqo ; } k0czgknnch =
( k0czgknnch + rtB . ldw4br50ng ) + ( po3ui3vu2a + rtB . gsofcjddvn ) ;
fur25gpj4d_idx_0 = rtP . Warrior_Gain_ndqbsjel4w * jktgfmsgij ;
fur25gpj4d_idx_1 = rtP . Warrior_Gain_ndqbsjel4w * k0czgknnch ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . lzsvpxojnz [ 0 ] = rtDW . guwv0f3uot
[ 0 ] ; rtB . lzsvpxojnz [ 1 ] = rtDW . guwv0f3uot [ 1 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { for ( i = 0 ; i < 5 ; i ++ ) { czozaga1lk [
i ] = 0.0 ; } if ( ! rtDW . jc3c25clri ) { rtDW . jsd0ujpvhr = rtP .
consensus_dr_cs4dlsi3sq [ ( int32_T ) rtP . Constant_Value_h1zp5rsdg2 - 1 ] ;
rtDW . jc3c25clri = true ; } if ( czozaga1lk [ 0 ] > 0.0 ) { rtDW .
azcmulp3j0 [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ; rtDW .
jbzxiyzok1 [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 4 ] ; } rtDW .
azcmulp3j0 [ ( int32_T ) rtP . Constant_Value_h1zp5rsdg2 - 1 ] = rtB .
iodvmyfik4 [ 3 ] ; rtDW . jbzxiyzok1 [ ( int32_T ) rtP .
Constant_Value_h1zp5rsdg2 - 1 ] = rtB . lzsvpxojnz [ 0 ] ; ezbcrqnwp0 = rtDW
. jbzxiyzok1 [ 0 ] - rtB . lzsvpxojnz [ 0 ] ; ezbcrqnwp0 += rtDW . jbzxiyzok1
[ 1 ] - rtB . lzsvpxojnz [ 0 ] ; ezbcrqnwp0 += rtDW . jbzxiyzok1 [ 2 ] - rtB
. lzsvpxojnz [ 0 ] ; ezbcrqnwp0 += rtDW . jbzxiyzok1 [ 3 ] - rtB . lzsvpxojnz
[ 0 ] ; rtDW . f0qbsmk4ex = ( rtDW . f0qbsmk4ex + rtP .
consensus_ts_c12jwpunuc ) + rtDW . jsd0ujpvhr ; rtDW . hrj53k3isf = ( rtDW .
hrj53k3isf + rtP . consensus_ts_c12jwpunuc ) + rtDW . jsd0ujpvhr ; rtDW .
pfrwigqbzn += ( ( ( ( ( ( rtB . iodvmyfik4 [ 3 ] - rtDW . azcmulp3j0 [ 0 ] )
+ ( rtB . iodvmyfik4 [ 3 ] - rtDW . azcmulp3j0 [ 1 ] ) ) + ( rtB . iodvmyfik4
[ 3 ] - rtDW . azcmulp3j0 [ 2 ] ) ) + ( rtB . iodvmyfik4 [ 3 ] - rtDW .
azcmulp3j0 [ 3 ] ) ) * 0.01 + ( 50.0 - rtB . iodvmyfik4 [ 3 ] ) * 2.0 ) + 0.1
* ezbcrqnwp0 ) * ( rtP . consensus_ts_c12jwpunuc + rtDW . jsd0ujpvhr ) ; rtB
. n10inqqacb [ 0 ] = ( rtDW . pfrwigqbzn - rtB . iodvmyfik4 [ 3 ] ) * rtP .
Degenerated_Gain_bm5tyqy0ip ; rtB . n10inqqacb [ 1 ] = rtP .
Degenerated_Gain_bm5tyqy0ip * 0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
{ SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; sfcnOutputs ( rts , 0 ) ; }
rtB . enmfzw4wn5 = rtP . Distributed_integral_w_Gain_lpnz215ziz * rtB .
nastbsm32g ; } rtB . na2ttkkmwd [ 0 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_optmbdsthn + rtB . dbqcdqyhwy [ 0 ] ) + rtB .
pugsu0nevr [ 0 ] ) + fur25gpj4d_idx_0 ) + rtB . n10inqqacb [ 0 ] ) + rtB .
enmfzw4wn5 ; rtB . na2ttkkmwd [ 1 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_optmbdsthn + rtB . dbqcdqyhwy [ 1 ] ) + rtB .
pugsu0nevr [ 1 ] ) + fur25gpj4d_idx_1 ) + rtB . n10inqqacb [ 1 ] ) + rtP .
KSencondaryless1_Value_lregag3fon ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
jtbhfmltwq ( rtB . lhj2ghm2f4 , rtB . na2ttkkmwd [ 0 ] , & rtB . pmll2wrcy3 ,
( ozv2axw2sw * ) & rtP . pmll2wrcy3 ) ; rtDW . fmmswgsion [ 0 ] = rtB .
pmll2wrcy3 . hgxfgflt2m [ 0 ] ; rtDW . fmmswgsion [ 1 ] = rtB . pmll2wrcy3 .
hgxfgflt2m [ 1 ] ; rtDW . fmmswgsion [ 2 ] = rtB . pmll2wrcy3 . hgxfgflt2m [
2 ] ; rtDW . fmmswgsion [ 3 ] = rtB . pmll2wrcy3 . hgxfgflt2m [ 3 ] ; } rtB .
eux2brobbv [ 0 ] = rtDW . aboia0klkk [ 0 ] ; rtB . eux2brobbv [ 1 ] = rtDW .
aboia0klkk [ 1 ] ; rtB . eux2brobbv [ 2 ] = rtDW . aboia0klkk [ 2 ] ; rtB .
eux2brobbv [ 3 ] = rtDW . aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { jtbhfmltwq ( rtB . eux2brobbv , rtB . na2ttkkmwd [ 1 ] , & rtB .
gpr5ewbwvu , ( ozv2axw2sw * ) & rtP . gpr5ewbwvu ) ; rtDW . aboia0klkk [ 0 ]
= rtB . gpr5ewbwvu . hgxfgflt2m [ 0 ] ; rtDW . aboia0klkk [ 1 ] = rtB .
gpr5ewbwvu . hgxfgflt2m [ 1 ] ; rtDW . aboia0klkk [ 2 ] = rtB . gpr5ewbwvu .
hgxfgflt2m [ 2 ] ; rtDW . aboia0klkk [ 3 ] = rtB . gpr5ewbwvu . hgxfgflt2m [
3 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { ezbcrqnwp0 = rtB . cwkcdvwsyb
. n0fuel1bnn ; ezbcrqnwp0 -= rtP . LPFp_DenCoef_g1xt3dr3a3 [ 1 ] * rtDW .
orkc55dufk ; rtDW . hzmcfcyu1n = ezbcrqnwp0 / rtP . LPFp_DenCoef_g1xt3dr3a3 [
0 ] ; ezbcrqnwp0 = rtP . LPFp_NumCoef_boqi1ajn5n [ 0 ] * rtDW . hzmcfcyu1n ;
ezbcrqnwp0 += rtP . LPFp_NumCoef_boqi1ajn5n [ 1 ] * rtDW . orkc55dufk ; rtB .
eoyd4uc25o = ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { for ( i =
0 ; i < 5 ; i ++ ) { czozaga1lk [ i ] = 0.0 ; } if ( czozaga1lk [ 0 ] > 0.0 )
{ rtDW . auvkbyqkxd [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ;
rtDW . f3k0bkdqnd [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 2 ] ;
rtDW . h0qgaci0at [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 3 ] ; }
rtDW . auvkbyqkxd [ ( int32_T ) rtP . Constant_Value_h1zp5rsdg2 - 1 ] = rtB .
iodvmyfik4 [ 3 ] ; rtDW . f3k0bkdqnd [ ( int32_T ) rtP .
Constant_Value_h1zp5rsdg2 - 1 ] = rtB . cwkcdvwsyb . on2dguwvvl ; rtDW .
h0qgaci0at [ ( int32_T ) rtP . Constant_Value_h1zp5rsdg2 - 1 ] = rtB .
n2mcguhbur ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . cawwajqazb = rtP
. Gain1_Gain_fcz13es3uk * igsk2g4zdx ; rtB . d1h14ldyu4 = rtP .
Gain3_Gain_fapmoodk0o * nk5sxhfvay ; rtB . cs2wisepbp = rtP .
Gain5_Gain_niovj2naej * igypfqosqo ; } rtB . d4qvlfmvmy = rtP .
donotdeletethisgain_Gain_pjg3gyl4gj * mq222t1tfk [ 7 ] ; rtB . kurks2zcva =
rtP . donotdeletethisgain_Gain_ek1zbpt0hi * mq222t1tfk [ 6 ] ; rtB .
p0z5ebkftq [ 0 ] = rtDW . h1t1phh10c [ 0 ] ; rtB . p0z5ebkftq [ 1 ] = rtDW .
h1t1phh10c [ 1 ] ; rtB . p0z5ebkftq [ 2 ] = rtDW . h1t1phh10c [ 2 ] ; rtB .
p0z5ebkftq [ 3 ] = rtDW . h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { kpi03nmwlh ( rtB . p0z5ebkftq , rtB . dnqnzblmbp [ 0 ] , & rtB .
ipvzgutla1 , ( drnct5ly2o * ) & rtP . ipvzgutla1 ) ; rtDW . h1t1phh10c [ 0 ]
= rtB . ipvzgutla1 . ovjujdzpjt [ 0 ] ; rtDW . h1t1phh10c [ 1 ] = rtB .
ipvzgutla1 . ovjujdzpjt [ 1 ] ; rtDW . h1t1phh10c [ 2 ] = rtB . ipvzgutla1 .
ovjujdzpjt [ 2 ] ; rtDW . h1t1phh10c [ 3 ] = rtB . ipvzgutla1 . ovjujdzpjt [
3 ] ; } rtB . fsr4klu2iw [ 0 ] = rtDW . foiy3odoz1 [ 0 ] ; rtB . fsr4klu2iw [
1 ] = rtDW . foiy3odoz1 [ 1 ] ; rtB . fsr4klu2iw [ 2 ] = rtDW . foiy3odoz1 [
2 ] ; rtB . fsr4klu2iw [ 3 ] = rtDW . foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . b3buxfo0jq = rtDW . ggorbvxv0b ; rtB . m4ofszhbm4 =
rtDW . ilfjamszda ; rtB . b30gw04tpb = rtDW . ewze1iozrz ; rtB . irpgyparai =
rtDW . bkwxpr2rpy ; rtB . gdvqwx5p4u = rtDW . l0gdo0gwee ; rtB . g03umd0jya =
rtDW . jy5gknzcfu ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { o3zilu53kc ( rtB
. b3buxfo0jq , rtB . m4ofszhbm4 , rtB . b30gw04tpb , rtB . irpgyparai , rtB .
gdvqwx5p4u , rtB . g03umd0jya , rtP . Constant_Value_hsvbbgfkro , & rtB .
avezulewcn , & rtDW . avezulewcn , ( m5tur4wi4k * ) & rtP . avezulewcn ) ;
ezbcrqnwp0 = rtB . avezulewcn . dberndtk2w ; ezbcrqnwp0 -= rtP .
LPFq_DenCoef_lsvgf4rl1a [ 1 ] * rtDW . nkbjhdynsp ; rtDW . mkmpmcvnsy =
ezbcrqnwp0 / rtP . LPFq_DenCoef_lsvgf4rl1a [ 0 ] ; ezbcrqnwp0 = rtP .
LPFq_NumCoef_cngm2kilnh [ 0 ] * rtDW . mkmpmcvnsy ; ezbcrqnwp0 += rtP .
LPFq_NumCoef_cngm2kilnh [ 1 ] * rtDW . nkbjhdynsp ; rtB . do20asbnvu =
ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { kjaxztqeed ( rtB .
fsr4klu2iw , rtB . do20asbnvu , & rtB . mmnlogmmqe , ( ewvp3cxhdz * ) & rtP .
mmnlogmmqe ) ; rtDW . foiy3odoz1 [ 0 ] = rtB . mmnlogmmqe . bbcbwrpqmg [ 0 ]
; rtDW . foiy3odoz1 [ 1 ] = rtB . mmnlogmmqe . bbcbwrpqmg [ 1 ] ; rtDW .
foiy3odoz1 [ 2 ] = rtB . mmnlogmmqe . bbcbwrpqmg [ 2 ] ; rtDW . foiy3odoz1 [
3 ] = rtB . mmnlogmmqe . bbcbwrpqmg [ 3 ] ; } rtB . nyh5uqpipi [ 0 ] = rtDW .
pizmexwruz [ 0 ] ; rtB . nyh5uqpipi [ 1 ] = rtDW . pizmexwruz [ 1 ] ; rtB .
nyh5uqpipi [ 2 ] = rtDW . pizmexwruz [ 2 ] ; rtB . nyh5uqpipi [ 3 ] = rtDW .
pizmexwruz [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { h4j3c4exvj ( rtB .
nyh5uqpipi , rtB . avezulewcn . on2dguwvvl , & rtB . pcljl3fmii , (
ndkw5mnz3z * ) & rtP . pcljl3fmii ) ; rtDW . pizmexwruz [ 0 ] = rtB .
pcljl3fmii . c03pdi1rvc [ 0 ] ; rtDW . pizmexwruz [ 1 ] = rtB . pcljl3fmii .
c03pdi1rvc [ 1 ] ; rtDW . pizmexwruz [ 2 ] = rtB . pcljl3fmii . c03pdi1rvc [
2 ] ; rtDW . pizmexwruz [ 3 ] = rtB . pcljl3fmii . c03pdi1rvc [ 3 ] ; } rtB .
p1j2mjcnmh [ 0 ] = rtDW . k5wmx351m0 [ 0 ] ; rtB . p1j2mjcnmh [ 1 ] = rtDW .
k5wmx351m0 [ 1 ] ; rtB . p1j2mjcnmh [ 2 ] = rtDW . k5wmx351m0 [ 2 ] ; rtB .
p1j2mjcnmh [ 3 ] = rtDW . k5wmx351m0 [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { akzc515hdq ( rtB . p1j2mjcnmh , rtB . dnqnzblmbp [ 3 ] , & rtB .
l1cumv5mxc , ( nbb0zpvvhm * ) & rtP . l1cumv5mxc ) ; rtDW . k5wmx351m0 [ 0 ]
= rtB . l1cumv5mxc . mesgqmrxmy [ 0 ] ; rtDW . k5wmx351m0 [ 1 ] = rtB .
l1cumv5mxc . mesgqmrxmy [ 1 ] ; rtDW . k5wmx351m0 [ 2 ] = rtB . l1cumv5mxc .
mesgqmrxmy [ 2 ] ; rtDW . k5wmx351m0 [ 3 ] = rtB . l1cumv5mxc . mesgqmrxmy [
3 ] ; } rtB . a2j3heg5ll [ 0 ] = rtDW . fmmswgsion [ 0 ] ; rtB . a2j3heg5ll [
1 ] = rtDW . fmmswgsion [ 1 ] ; rtB . a2j3heg5ll [ 2 ] = rtDW . fmmswgsion [
2 ] ; rtB . a2j3heg5ll [ 3 ] = rtDW . fmmswgsion [ 3 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . aee3tydqqe [ 0 ] = rtP .
Central_Integral_Gain_bwkrokbusa * 0.0 ; rtB . aee3tydqqe [ 1 ] = rtP .
Central_Integral_Gain_bwkrokbusa * 0.0 ; ezbcrqnwp0 = ssGetTaskTime ( rtS , 1
) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . lchl2nrr42 = ( ezbcrqnwp0 >=
rtP . Step_Time_mbvhgvqi3v ) ; } if ( rtDW . lchl2nrr42 == 1 ) { rtB .
l2ny1ho3uf = rtP . Step_YFinal_n4hnvye20z ; } else { rtB . l2ny1ho3uf = rtP .
Step_Y0_k3hm1gr14s ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { onerdwipjp (
0.0 , rtB . l2ny1ho3uf , & rtB . dvrqjotubu , & rtDW . dvrqjotubu , (
n1y0minqnv * ) & rtP . dvrqjotubu ) ; rtB . o4komacgjl [ 0 ] = rtP .
Distributed_integral_Gain_d43k4wl3wl * rtB . dvrqjotubu . ioo1a4zpmx [ 0 ] ;
rtB . o4komacgjl [ 1 ] = rtP . Distributed_integral_Gain_d43k4wl3wl * rtB .
dvrqjotubu . ioo1a4zpmx [ 1 ] ; } jktgfmsgij = rtX . pvsidq4mg0 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . naoiq1nxxi = ( ezbcrqnwp0 >= rtP .
Step_Time_h1zu3joaf1 ) ; } if ( rtDW . naoiq1nxxi == 1 ) { igypfqosqo = rtP .
Step_YFinal_h5xbk4nth0 ; } else { igypfqosqo = rtP . Step_Y0_mvpspxbhia ; }
igsk2g4zdx = ( rtP . Constant_Value_i5bvtvx522 - rtP . upi_Gain_hrt3gnzfl2 *
0.0 ) * igypfqosqo ; rtB . h4tgjphw5q = rtP . Gain_Gain_jty3lhxgcu *
igsk2g4zdx ; } jktgfmsgij += rtB . h4tgjphw5q ; k0czgknnch = rtX . hemro31n34
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { nk5sxhfvay = ( rtP .
Constant1_Value_ovbc5ioqzk - 0.0 ) * igypfqosqo ; rtB . ldmwux2zhx = rtP .
Gain2_Gain_asvcjlvedl * nk5sxhfvay ; } po3ui3vu2a = rtX . p5jpc4ehox ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { igypfqosqo = ( 0.0 - 0.0 ) * igypfqosqo ;
rtB . kms2jmv2td = rtP . Gain4_Gain_jxbixtmknd * igypfqosqo ; } k0czgknnch =
( k0czgknnch + rtB . ldmwux2zhx ) + ( po3ui3vu2a + rtB . kms2jmv2td ) ;
fur25gpj4d_idx_0 = rtP . Warrior_Gain_dguuaxnn54 * jktgfmsgij ;
fur25gpj4d_idx_1 = rtP . Warrior_Gain_dguuaxnn54 * k0czgknnch ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ozch1m2xun [ 0 ] = rtDW . nom2ms4idi
[ 0 ] ; rtB . ozch1m2xun [ 1 ] = rtDW . nom2ms4idi [ 1 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { for ( i = 0 ; i < 5 ; i ++ ) { czozaga1lk [
i ] = 0.0 ; } if ( ! rtDW . inwfij3epu ) { rtDW . pkdkxevryy = rtP .
consensus_dr_hf31gowvrj [ ( int32_T ) rtP . Constant_Value_hsvbbgfkro - 1 ] ;
rtDW . inwfij3epu = true ; } if ( czozaga1lk [ 0 ] > 0.0 ) { rtDW .
gaht5h2guw [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ; rtDW .
czc2sb2jwa [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 4 ] ; } rtDW .
gaht5h2guw [ ( int32_T ) rtP . Constant_Value_hsvbbgfkro - 1 ] = rtB .
dnqnzblmbp [ 3 ] ; rtDW . czc2sb2jwa [ ( int32_T ) rtP .
Constant_Value_hsvbbgfkro - 1 ] = rtB . ozch1m2xun [ 0 ] ; ezbcrqnwp0 = rtDW
. czc2sb2jwa [ 0 ] - rtB . ozch1m2xun [ 0 ] ; ezbcrqnwp0 += rtDW . czc2sb2jwa
[ 1 ] - rtB . ozch1m2xun [ 0 ] ; ezbcrqnwp0 += rtDW . czc2sb2jwa [ 2 ] - rtB
. ozch1m2xun [ 0 ] ; ezbcrqnwp0 += rtDW . czc2sb2jwa [ 3 ] - rtB . ozch1m2xun
[ 0 ] ; rtDW . k0nz2julpt = ( rtDW . k0nz2julpt + rtP .
consensus_ts_phmvpsqftd ) + rtDW . pkdkxevryy ; rtDW . anaa2i2evl = ( rtDW .
anaa2i2evl + rtP . consensus_ts_phmvpsqftd ) + rtDW . pkdkxevryy ; rtDW .
lnjgkjkghh += ( ( ( ( ( ( rtB . dnqnzblmbp [ 3 ] - rtDW . gaht5h2guw [ 0 ] )
+ ( rtB . dnqnzblmbp [ 3 ] - rtDW . gaht5h2guw [ 1 ] ) ) + ( rtB . dnqnzblmbp
[ 3 ] - rtDW . gaht5h2guw [ 2 ] ) ) + ( rtB . dnqnzblmbp [ 3 ] - rtDW .
gaht5h2guw [ 3 ] ) ) * 0.01 + ( 50.0 - rtB . dnqnzblmbp [ 3 ] ) * 2.0 ) + 0.1
* ezbcrqnwp0 ) * ( rtP . consensus_ts_phmvpsqftd + rtDW . pkdkxevryy ) ; rtB
. p4eyqrx5tw [ 0 ] = ( rtDW . lnjgkjkghh - rtB . dnqnzblmbp [ 3 ] ) * rtP .
Degenerated_Gain_p1y3cmfgyv ; rtB . p4eyqrx5tw [ 1 ] = rtP .
Degenerated_Gain_p1y3cmfgyv * 0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
{ SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; sfcnOutputs ( rts , 0 ) ; }
rtB . kknf5smhy4 = rtP . Distributed_integral_w_Gain_jm5ojyhpid * rtB .
dzlnvksxlk ; } rtB . blvbd5kgbi [ 0 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_oyco5fzk4w + rtB . aee3tydqqe [ 0 ] ) + rtB .
o4komacgjl [ 0 ] ) + fur25gpj4d_idx_0 ) + rtB . p4eyqrx5tw [ 0 ] ) + rtB .
kknf5smhy4 ; rtB . blvbd5kgbi [ 1 ] = ( ( ( ( ( real_T ) rtP .
KSencondaryless_Value_oyco5fzk4w + rtB . aee3tydqqe [ 1 ] ) + rtB .
o4komacgjl [ 1 ] ) + fur25gpj4d_idx_1 ) + rtB . p4eyqrx5tw [ 1 ] ) + rtP .
KSencondaryless1_Value_h2aqorl5nb ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
jtbhfmltwq ( rtB . a2j3heg5ll , rtB . blvbd5kgbi [ 0 ] , & rtB . p0jpb31wlq ,
( ozv2axw2sw * ) & rtP . p0jpb31wlq ) ; rtDW . fmmswgsion [ 0 ] = rtB .
p0jpb31wlq . hgxfgflt2m [ 0 ] ; rtDW . fmmswgsion [ 1 ] = rtB . p0jpb31wlq .
hgxfgflt2m [ 1 ] ; rtDW . fmmswgsion [ 2 ] = rtB . p0jpb31wlq . hgxfgflt2m [
2 ] ; rtDW . fmmswgsion [ 3 ] = rtB . p0jpb31wlq . hgxfgflt2m [ 3 ] ; } rtB .
hjgncjfz4l [ 0 ] = rtDW . aboia0klkk [ 0 ] ; rtB . hjgncjfz4l [ 1 ] = rtDW .
aboia0klkk [ 1 ] ; rtB . hjgncjfz4l [ 2 ] = rtDW . aboia0klkk [ 2 ] ; rtB .
hjgncjfz4l [ 3 ] = rtDW . aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { jtbhfmltwq ( rtB . hjgncjfz4l , rtB . blvbd5kgbi [ 1 ] , & rtB .
k04lp2vsfm , ( ozv2axw2sw * ) & rtP . k04lp2vsfm ) ; rtDW . aboia0klkk [ 0 ]
= rtB . k04lp2vsfm . hgxfgflt2m [ 0 ] ; rtDW . aboia0klkk [ 1 ] = rtB .
k04lp2vsfm . hgxfgflt2m [ 1 ] ; rtDW . aboia0klkk [ 2 ] = rtB . k04lp2vsfm .
hgxfgflt2m [ 2 ] ; rtDW . aboia0klkk [ 3 ] = rtB . k04lp2vsfm . hgxfgflt2m [
3 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { ezbcrqnwp0 = rtB . avezulewcn
. n0fuel1bnn ; ezbcrqnwp0 -= rtP . LPFp_DenCoef_oo54vuxlff [ 1 ] * rtDW .
ldb4vi0ha4 ; rtDW . h2vskoxuxe = ezbcrqnwp0 / rtP . LPFp_DenCoef_oo54vuxlff [
0 ] ; ezbcrqnwp0 = rtP . LPFp_NumCoef_oojfmq1khk [ 0 ] * rtDW . h2vskoxuxe ;
ezbcrqnwp0 += rtP . LPFp_NumCoef_oojfmq1khk [ 1 ] * rtDW . ldb4vi0ha4 ; rtB .
oqxkfo2dq5 = ezbcrqnwp0 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { for ( i =
0 ; i < 5 ; i ++ ) { czozaga1lk [ i ] = 0.0 ; } if ( czozaga1lk [ 0 ] > 0.0 )
{ rtDW . k2lslkrofb [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 1 ] ;
rtDW . o2kydmp2r4 [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 2 ] ;
rtDW . i2tar503fo [ ( int32_T ) czozaga1lk [ 0 ] - 1 ] = czozaga1lk [ 3 ] ; }
rtDW . k2lslkrofb [ ( int32_T ) rtP . Constant_Value_hsvbbgfkro - 1 ] = rtB .
dnqnzblmbp [ 3 ] ; rtDW . o2kydmp2r4 [ ( int32_T ) rtP .
Constant_Value_hsvbbgfkro - 1 ] = rtB . avezulewcn . on2dguwvvl ; rtDW .
i2tar503fo [ ( int32_T ) rtP . Constant_Value_hsvbbgfkro - 1 ] = rtB .
do20asbnvu ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . oues2lcti4 = rtP
. Gain1_Gain_cjogxzntno * igsk2g4zdx ; rtB . eelx0pksev = rtP .
Gain3_Gain_fal1cwrksj * nk5sxhfvay ; rtB . lg5rqpaf2e = rtP .
Gain5_Gain_npwynuslmj * igypfqosqo ; } rtB . hm532ngjvw = rtP .
donotdeletethisgain_Gain_pqt51vmxbg * mq222t1tfk [ 5 ] ; rtB . c24lrwyun4 =
rtP . donotdeletethisgain_Gain_iyrfn2wpbu * mq222t1tfk [ 4 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { ezbcrqnwp0 = ssGetTaskTime ( rtS , 1 ) ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . jktkwtec4i = ( ezbcrqnwp0 >= rtP .
Step_Time_cqeoamr4wm ) ; } if ( rtDW . jktkwtec4i == 1 ) { igypfqosqo = rtP .
Step_YFinal_lf2hwitpjk ; } else { igypfqosqo = rtP . Step_Y0_gycl0h21kq ; }
rtB . fo5rqi15o1 = ( rtP . Constant_Value_jsxo0wpglc - rtP .
upi_Gain_gdts1vd3ud * rtB . dpgwwjc2rz [ 3 ] ) * igypfqosqo * rtP .
Gain1_Gain_edmc5opvxj ; rtB . f2q5magsot = ( rtP . Constant1_Value_eht0aia3xv
- rtB . ozftnlfeg3 . on2dguwvvl ) * igypfqosqo * rtP . Gain3_Gain_kcpjx312wz
; } eybee5p0jv = rtX . ihfpfs5hha ; nj4hdikini = rtX . mejopo4his ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { SimStruct * rts = ssGetSFunction ( rtS ,
8 ) ; sfcnOutputs ( rts , 0 ) ; } { double locTime = ssGetTaskTime ( rtS , 1
) ; if ( ssGetLogOutput ( rtS ) ) { rt_UpdateStructLogVar ( ( StructLogVar *
) rtDW . njuiuoq00q . LoggedData , & locTime , & rtB . gcnh1cojbn [ 0 ] ) ; }
} } rtB . lc3tl5isia = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 4 , 0 ) )
{ if ( ssGetLogOutput ( rtS ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * )
( rtDW . l4tlfv342r . LoggedData ) , & rtB . lc3tl5isia , 0 ) ; } } rtB .
clfpixb40s [ 0 ] = rtDW . h1t1phh10c [ 0 ] ; rtB . clfpixb40s [ 1 ] = rtDW .
h1t1phh10c [ 1 ] ; rtB . clfpixb40s [ 2 ] = rtDW . h1t1phh10c [ 2 ] ; rtB .
clfpixb40s [ 3 ] = rtDW . h1t1phh10c [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0
) ) { if ( ssGetLogOutput ( rtS ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar
* ) ( rtDW . l5yezso4td . LoggedData ) , & rtB . clfpixb40s [ 0 ] , 0 ) ; } }
rtB . fl0i4sb4vv [ 0 ] = rtDW . foiy3odoz1 [ 0 ] ; rtB . fl0i4sb4vv [ 1 ] =
rtDW . foiy3odoz1 [ 1 ] ; rtB . fl0i4sb4vv [ 2 ] = rtDW . foiy3odoz1 [ 2 ] ;
rtB . fl0i4sb4vv [ 3 ] = rtDW . foiy3odoz1 [ 3 ] ; if ( ssIsSampleHit ( rtS ,
4 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . hembuefnfy . LoggedData ) , & rtB . fl0i4sb4vv [ 0 ] , 0
) ; } } rtB . gmhqlr0ded [ 0 ] = rtDW . pizmexwruz [ 0 ] ; rtB . gmhqlr0ded [
1 ] = rtDW . pizmexwruz [ 1 ] ; rtB . gmhqlr0ded [ 2 ] = rtDW . pizmexwruz [
2 ] ; rtB . gmhqlr0ded [ 3 ] = rtDW . pizmexwruz [ 3 ] ; if ( ssIsSampleHit (
rtS , 4 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { rt_UpdateLogVar ( ( LogVar
* ) ( LogVar * ) ( rtDW . jhyvglnaqs . LoggedData ) , & rtB . gmhqlr0ded [ 0
] , 0 ) ; } } rtB . carjwykir1 [ 0 ] = rtDW . k5wmx351m0 [ 0 ] ; rtB .
carjwykir1 [ 1 ] = rtDW . k5wmx351m0 [ 1 ] ; rtB . carjwykir1 [ 2 ] = rtDW .
k5wmx351m0 [ 2 ] ; rtB . carjwykir1 [ 3 ] = rtDW . k5wmx351m0 [ 3 ] ; if (
ssIsSampleHit ( rtS , 4 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) {
rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . fqpl3agz2v . LoggedData
) , & rtB . carjwykir1 [ 0 ] , 0 ) ; } } rtB . caywsc2yvv [ 0 ] = rtDW .
aboia0klkk [ 0 ] ; rtB . caywsc2yvv [ 1 ] = rtDW . aboia0klkk [ 1 ] ; rtB .
caywsc2yvv [ 2 ] = rtDW . aboia0klkk [ 2 ] ; rtB . caywsc2yvv [ 3 ] = rtDW .
aboia0klkk [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if ( ssGetLogOutput
( rtS ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . fw0ubz1mel .
LoggedData ) , & rtB . caywsc2yvv [ 0 ] , 0 ) ; } } rtB . eyrg550icf [ 0 ] =
rtDW . fmmswgsion [ 0 ] ; rtB . eyrg550icf [ 1 ] = rtDW . fmmswgsion [ 1 ] ;
rtB . eyrg550icf [ 2 ] = rtDW . fmmswgsion [ 2 ] ; rtB . eyrg550icf [ 3 ] =
rtDW . fmmswgsion [ 3 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { if (
ssGetLogOutput ( rtS ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW
. frfdkzrjsf . LoggedData ) , & rtB . eyrg550icf [ 0 ] , 0 ) ; } } rtB .
pnwecd2kft = rtP . donotdeletethisgain_Gain_h35lkhvbav * mq222t1tfk [ 0 ] ;
rtB . gej5khtvm2 = rtP . donotdeletethisgain_Gain_i04ou4rp5q * mq222t1tfk [ 1
] ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . mjqxgo2das = rtB . iewvn51hd3 ; rtDW
. lstr5kczd4 = rtB . hbtkhijkte ; rtDW . ex3o4uqzc2 = rtB . f5kuq3shj4 ; rtDW
. mcbh12k100 = rtB . poglkcfqy3 ; rtDW . ahv3cotbw2 = rtB . mguxqfcdvk [ 0 ]
; rtDW . p5sygl0ymh = rtB . mguxqfcdvk [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2
, 0 ) ) { rtDW . f5c0nsumji = rtDW . gidygjlsh2 ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { rtDW . oktxx1jm30 [ 0 ] = rtB . mguxqfcdvk [ 0 ] ; rtDW .
oktxx1jm30 [ 1 ] = rtB . mguxqfcdvk [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 ,
0 ) ) { rtDW . a5w40p1bws = rtDW . jxsk15cftx ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . h31mfjlljs = rtB . pnwecd2kft ; rtDW . efdih4dveq = rtB .
gej5khtvm2 ; rtDW . n31fjbosih = rtB . hen0mtsi3a ; rtDW . bj3nvzbqqv = rtB .
mfwsny1flw ; rtDW . pftedxldcl = rtB . jkgsoin4ud ; rtDW . ffb5al3bwy = rtB .
adhev5qmdl ; rtDW . l2sbaaoqpn = rtB . lgfjmq2ecm [ 0 ] ; rtDW . nha400jjfg =
rtB . lgfjmq2ecm [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW .
eanwkjl2vy = rtDW . lv3zjk5f1k ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtDW . bugcdre0xq [ 0 ] = rtB . lgfjmq2ecm [ 0 ] ; rtDW . bugcdre0xq [ 1 ] =
rtB . lgfjmq2ecm [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW .
d5bnnktx4e = rtDW . ghsofqsrqn ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtDW . hccpqibboh = rtB . eoyd4uc25o ; rtDW . mmm2iqducw = rtB . n2mcguhbur ;
rtDW . caoih1mnoc = rtB . kurks2zcva ; rtDW . ni0pxjjk34 = rtB . d4qvlfmvmy ;
rtDW . hlgbmv2r55 = rtB . na2ttkkmwd [ 0 ] ; rtDW . p2lhgag51t = rtB .
na2ttkkmwd [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . lnetbv1cgv
= rtDW . nknewvnn53 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
guwv0f3uot [ 0 ] = rtB . na2ttkkmwd [ 0 ] ; rtDW . guwv0f3uot [ 1 ] = rtB .
na2ttkkmwd [ 1 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . orkc55dufk
= rtDW . hzmcfcyu1n ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
ggorbvxv0b = rtB . oqxkfo2dq5 ; rtDW . ilfjamszda = rtB . do20asbnvu ; rtDW .
ewze1iozrz = rtB . c24lrwyun4 ; rtDW . bkwxpr2rpy = rtB . hm532ngjvw ; rtDW .
l0gdo0gwee = rtB . blvbd5kgbi [ 0 ] ; rtDW . jy5gknzcfu = rtB . blvbd5kgbi [
1 ] ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . nkbjhdynsp = rtDW .
mkmpmcvnsy ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . nom2ms4idi [ 0 ]
= rtB . blvbd5kgbi [ 0 ] ; rtDW . nom2ms4idi [ 1 ] = rtB . blvbd5kgbi [ 1 ] ;
} if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . ldb4vi0ha4 = rtDW .
h2vskoxuxe ; } UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
int_T is ; int_T ci ; static const int8_T ir [ 15 ] = { 0 , 2 , 4 , 6 , 8 ,
10 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 } ; static const int8_T jc [
20 ] = { 0 , 2 , 1 , 3 , 0 , 6 , 1 , 7 , 2 , 4 , 3 , 5 , 4 , 5 , 2 , 3 , 0 ,
1 , 6 , 7 } ; XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; { (
( XDot * ) ssGetdX ( rtS ) ) -> myddfjqwmy = rtB . h1tgqdz5v2 ; } { ( ( XDot
* ) ssGetdX ( rtS ) ) -> idks32lhev = rtB . gq1khgfhm2 ; } { ( ( XDot * )
ssGetdX ( rtS ) ) -> hnfrxgtkqe = rtB . n0mg2py0tt ; } for ( is = 0 ; is < 14
; is ++ ) { _rtXdot -> jqdufexgzv [ is ] = 0.0 ; } for ( is = 0 ; is < 14 ;
is ++ ) { for ( ci = is ; ci < is + 1 ; ci ++ ) { _rtXdot -> jqdufexgzv [ is
] += rtP . StateSpace_A [ ci ] * rtX . jqdufexgzv [ ci ] ; } } for ( is = 0 ;
is < 14 ; is ++ ) { for ( ci = ir [ is ] ; ci < ir [ is + 1 ] ; ci ++ ) {
_rtXdot -> jqdufexgzv [ is ] += rtP . StateSpace_B [ ci ] * rtB . icb23pk4yt
[ jc [ ci ] ] ; } } { ( ( XDot * ) ssGetdX ( rtS ) ) -> cvbao2hes3 = rtB .
lxk0xwc3vx ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> nce055ezz1 = rtB .
hkkbhcvcxm ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> cenhjcoeh3 = rtB .
lmpvvsgbzc ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> b1xdzpc02l = rtB .
cawwajqazb ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> iyto1k1kzw = rtB .
d1h14ldyu4 ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> pkxrt4qo4z = rtB .
cs2wisepbp ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> pvsidq4mg0 = rtB .
oues2lcti4 ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> hemro31n34 = rtB .
eelx0pksev ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> p5jpc4ehox = rtB .
lg5rqpaf2e ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> ihfpfs5hha = rtB .
fo5rqi15o1 ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> mejopo4his = rtB .
f2q5magsot ; } } void MdlProjection ( void ) { } void MdlZeroCrossings ( void
) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) )
; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; ssSetNonsampledZCs ( rts ,
& ( ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> hgfgqjzzw5 ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } _rtZCSV -> dunpysylye = ssGetT ( rtS ) - rtP . Step_Time ; _rtZCSV
-> bhihhxlw01 = ssGetT ( rtS ) - rtP . Step_Time_lmjjonohpb ; { SimStruct *
rts = ssGetSFunction ( rtS , 1 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> llkwhesq35 ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct *
rts = ssGetSFunction ( rtS , 2 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> c25e3sp3to ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct *
rts = ssGetSFunction ( rtS , 3 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> kar0je5wag ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct *
rts = ssGetSFunction ( rtS , 4 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> azu3ihlzds ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } _rtZCSV ->
lt4vi1vs3u = ssGetT ( rtS ) - rtP . Step_Time_dq4ffjhuug ; _rtZCSV ->
btxc00d2lu = ssGetT ( rtS ) - rtP . Step_Time_mv0kh4fqoa ; { SimStruct * rts
= ssGetSFunction ( rtS , 5 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> psnugcw0vd ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } _rtZCSV ->
mh1tsnw2zi = ssGetT ( rtS ) - rtP . Step_Time_fjiuqwecd2 ; _rtZCSV ->
pth2xie120 = ssGetT ( rtS ) - rtP . Step_Time_lgtvrypfrs ; { SimStruct * rts
= ssGetSFunction ( rtS , 6 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> f2t1w3tgsp ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } _rtZCSV ->
i1jyyuvehq = ssGetT ( rtS ) - rtP . Step_Time_mbvhgvqi3v ; _rtZCSV ->
jjny4emxrd = ssGetT ( rtS ) - rtP . Step_Time_h1zu3joaf1 ; { SimStruct * rts
= ssGetSFunction ( rtS , 7 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> lgxljdgddd ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } _rtZCSV ->
gg5u4mtitg = ssGetT ( rtS ) - rtP . Step_Time_cqeoamr4wm ; { SimStruct * rts
= ssGetSFunction ( rtS , 8 ) ; ssSetNonsampledZCs ( rts , & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> k30bppfzpt ) ) ; sfcnZeroCrossings (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void
MdlTerminate ( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 3 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 4 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 5 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 6 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 7 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ;
sfcnTerminate ( rts ) ; } } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 28 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 10 ) ;
ssSetNumBlocks ( rtS , 481 ) ; ssSetNumBlockIO ( rtS , 204 ) ;
ssSetNumBlockParams ( rtS , 795 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.0001 ) ; ssSetSampleTime ( rtS , 3 , 0.01 ) ;
ssSetSampleTime ( rtS , 4 , 1.0 ) ; ssSetSampleTime ( rtS , 5 , - 2.0 ) ;
ssSetSampleTime ( rtS , 6 , - 2.0 ) ; ssSetSampleTime ( rtS , 7 , - 2.0 ) ;
ssSetSampleTime ( rtS , 8 , - 2.0 ) ; ssSetSampleTime ( rtS , 9 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ;
ssSetOffsetTime ( rtS , 4 , 0.0 ) ; ssSetOffsetTime ( rtS , 5 , 0.0 ) ;
ssSetOffsetTime ( rtS , 6 , 1.0 ) ; ssSetOffsetTime ( rtS , 7 , 2.0 ) ;
ssSetOffsetTime ( rtS , 8 , 3.0 ) ; ssSetOffsetTime ( rtS , 9 , 4.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
1063567491U ) ; ssSetChecksumVal ( rtS , 1 , 88383218U ) ; ssSetChecksumVal (
rtS , 2 , 3038457091U ) ; ssSetChecksumVal ( rtS , 3 , 3990997617U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; { int_T i ; for ( i = 0 ; i < 6 ; i ++ ) { rtB .
dpgwwjc2rz [ i ] = 0.0 ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . n2zlvavzvj [
i ] = 0.0 ; } for ( i = 0 ; i < 6 ; i ++ ) { rtB . iodvmyfik4 [ i ] = 0.0 ; }
for ( i = 0 ; i < 6 ; i ++ ) { rtB . dnqnzblmbp [ i ] = 0.0 ; } for ( i = 0 ;
i < 10 ; i ++ ) { rtB . icb23pk4yt [ i ] = 0.0 ; } for ( i = 0 ; i < 5 ; i ++
) { rtB . ktweuvg11j [ i ] = 0.0 ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
gcnh1cojbn [ i ] = 0.0 ; } rtB . ek3a1451ay [ 0 ] = 0.0 ; rtB . ek3a1451ay [
1 ] = 0.0 ; rtB . ek3a1451ay [ 2 ] = 0.0 ; rtB . ek3a1451ay [ 3 ] = 0.0 ; rtB
. kycfwls143 = 0.0 ; rtB . ee5gbg0io5 = 0.0 ; rtB . avlxjfrevq = 0.0 ; rtB .
hoq5gatyaq [ 0 ] = 0.0 ; rtB . hoq5gatyaq [ 1 ] = 0.0 ; rtB . hoq5gatyaq [ 2
] = 0.0 ; rtB . hoq5gatyaq [ 3 ] = 0.0 ; rtB . fntkhkkhap = 0.0 ; rtB .
biin3vhjc0 = 0.0 ; rtB . kkx4ezyhkw = 0.0 ; rtB . mpyof2qigx = 0.0 ; rtB .
fypbjuyz3n = 0.0 ; rtB . mco3v3iige = 0.0 ; rtB . hbtkhijkte = 0.0 ; rtB .
ljwqffhvl4 [ 0 ] = 0.0 ; rtB . ljwqffhvl4 [ 1 ] = 0.0 ; rtB . ljwqffhvl4 [ 2
] = 0.0 ; rtB . ljwqffhvl4 [ 3 ] = 0.0 ; rtB . h4k23zmq31 [ 0 ] = 0.0 ; rtB .
h4k23zmq31 [ 1 ] = 0.0 ; rtB . h4k23zmq31 [ 2 ] = 0.0 ; rtB . h4k23zmq31 [ 3
] = 0.0 ; rtB . jsillufvig [ 0 ] = 0.0 ; rtB . jsillufvig [ 1 ] = 0.0 ; rtB .
jsillufvig [ 2 ] = 0.0 ; rtB . jsillufvig [ 3 ] = 0.0 ; rtB . d2kvmgvdht [ 0
] = 0.0 ; rtB . d2kvmgvdht [ 1 ] = 0.0 ; rtB . okzfmxk5yy = 0.0 ; rtB .
m1vu1obgik [ 0 ] = 0.0 ; rtB . m1vu1obgik [ 1 ] = 0.0 ; rtB . kcbmknce0k =
0.0 ; rtB . lq5dbqfp25 = 0.0 ; rtB . ld4l31qhaw = 0.0 ; rtB . fchnjsvgwh [ 0
] = 0.0 ; rtB . fchnjsvgwh [ 1 ] = 0.0 ; rtB . ibl2erstls [ 0 ] = 0.0 ; rtB .
ibl2erstls [ 1 ] = 0.0 ; rtB . bxyd4fbh0g = 0.0 ; rtB . pijde51qab = 0.0 ;
rtB . gehrrnez0b = 0.0 ; rtB . dwdpwj5pni = 0.0 ; rtB . dti2carlq5 = 0.0 ;
rtB . mguxqfcdvk [ 0 ] = 0.0 ; rtB . mguxqfcdvk [ 1 ] = 0.0 ; rtB .
nebhkpb5ai [ 0 ] = 0.0 ; rtB . nebhkpb5ai [ 1 ] = 0.0 ; rtB . nebhkpb5ai [ 2
] = 0.0 ; rtB . nebhkpb5ai [ 3 ] = 0.0 ; rtB . iewvn51hd3 = 0.0 ; rtB .
h1tgqdz5v2 = 0.0 ; rtB . gq1khgfhm2 = 0.0 ; rtB . n0mg2py0tt = 0.0 ; rtB .
lvxcghiadw = 0.0 ; rtB . iz5ulgunhl = 0.0 ; rtB . falp0kne2f = 0.0 ; rtB .
fobyeqif54 = 0.0 ; rtB . iftyjztmep = 0.0 ; rtB . cyfk1qotlx = 0.0 ; rtB .
cwaxgcfgm2 = 0.0 ; rtB . of4z3nxnpu = 0.0 ; rtB . mpet5fjgog = 0.0 ; rtB .
ec4ppad44q = 0.0 ; rtB . awk2wo0fe2 = 0.0 ; rtB . poglkcfqy3 = 0.0 ; rtB .
f5kuq3shj4 = 0.0 ; rtB . aczh1lvgar [ 0 ] = 0.0 ; rtB . aczh1lvgar [ 1 ] =
0.0 ; rtB . aczh1lvgar [ 2 ] = 0.0 ; rtB . aczh1lvgar [ 3 ] = 0.0 ; rtB .
dzuta0dnpn [ 0 ] = 0.0 ; rtB . dzuta0dnpn [ 1 ] = 0.0 ; rtB . dzuta0dnpn [ 2
] = 0.0 ; rtB . dzuta0dnpn [ 3 ] = 0.0 ; rtB . hx0wj5yo2m = 0.0 ; rtB .
kcng2h2ox5 = 0.0 ; rtB . d4jrh0gj3t = 0.0 ; rtB . nhbi4wyipn = 0.0 ; rtB .
pdvnbdhjm2 = 0.0 ; rtB . mj22h2mmx5 = 0.0 ; rtB . mfwsny1flw = 0.0 ; rtB .
cbfpuf2or0 [ 0 ] = 0.0 ; rtB . cbfpuf2or0 [ 1 ] = 0.0 ; rtB . cbfpuf2or0 [ 2
] = 0.0 ; rtB . cbfpuf2or0 [ 3 ] = 0.0 ; rtB . abwh33q232 [ 0 ] = 0.0 ; rtB .
abwh33q232 [ 1 ] = 0.0 ; rtB . abwh33q232 [ 2 ] = 0.0 ; rtB . abwh33q232 [ 3
] = 0.0 ; rtB . b4slefd2sz [ 0 ] = 0.0 ; rtB . b4slefd2sz [ 1 ] = 0.0 ; rtB .
b4slefd2sz [ 2 ] = 0.0 ; rtB . b4slefd2sz [ 3 ] = 0.0 ; rtB . ctf1kxqmdo [ 0
] = 0.0 ; rtB . ctf1kxqmdo [ 1 ] = 0.0 ; rtB . pgkimqavpk = 0.0 ; rtB .
f5aj101k3a [ 0 ] = 0.0 ; rtB . f5aj101k3a [ 1 ] = 0.0 ; rtB . kkm103ywxt =
0.0 ; rtB . e1nfog11ri = 0.0 ; rtB . d535qgtjbe = 0.0 ; rtB . kdglpydeda [ 0
] = 0.0 ; rtB . kdglpydeda [ 1 ] = 0.0 ; rtB . l523yuyruu [ 0 ] = 0.0 ; rtB .
l523yuyruu [ 1 ] = 0.0 ; rtB . ellko3pdhd = 0.0 ; rtB . e4hzm4gatj = 0.0 ;
rtB . podole3fca = 0.0 ; rtB . lhfof1cyys = 0.0 ; rtB . krez0hg5v1 = 0.0 ;
rtB . lgfjmq2ecm [ 0 ] = 0.0 ; rtB . lgfjmq2ecm [ 1 ] = 0.0 ; rtB .
i52hyrlq2j [ 0 ] = 0.0 ; rtB . i52hyrlq2j [ 1 ] = 0.0 ; rtB . i52hyrlq2j [ 2
] = 0.0 ; rtB . i52hyrlq2j [ 3 ] = 0.0 ; rtB . hen0mtsi3a = 0.0 ; rtB .
lxk0xwc3vx = 0.0 ; rtB . hkkbhcvcxm = 0.0 ; rtB . lmpvvsgbzc = 0.0 ; rtB .
adhev5qmdl = 0.0 ; rtB . jkgsoin4ud = 0.0 ; rtB . fg3wll3qdz [ 0 ] = 0.0 ;
rtB . fg3wll3qdz [ 1 ] = 0.0 ; rtB . fg3wll3qdz [ 2 ] = 0.0 ; rtB .
fg3wll3qdz [ 3 ] = 0.0 ; rtB . keuugvf2im [ 0 ] = 0.0 ; rtB . keuugvf2im [ 1
] = 0.0 ; rtB . keuugvf2im [ 2 ] = 0.0 ; rtB . keuugvf2im [ 3 ] = 0.0 ; rtB .
pazkwcssox = 0.0 ; rtB . brmhwzxuee = 0.0 ; rtB . g4tkowhewi = 0.0 ; rtB .
j52dskeymb = 0.0 ; rtB . fpqii21x5i = 0.0 ; rtB . ek0x1ax1lz = 0.0 ; rtB .
n2mcguhbur = 0.0 ; rtB . as33t0f0ow [ 0 ] = 0.0 ; rtB . as33t0f0ow [ 1 ] =
0.0 ; rtB . as33t0f0ow [ 2 ] = 0.0 ; rtB . as33t0f0ow [ 3 ] = 0.0 ; rtB .
meko05j0sc [ 0 ] = 0.0 ; rtB . meko05j0sc [ 1 ] = 0.0 ; rtB . meko05j0sc [ 2
] = 0.0 ; rtB . meko05j0sc [ 3 ] = 0.0 ; rtB . lhj2ghm2f4 [ 0 ] = 0.0 ; rtB .
lhj2ghm2f4 [ 1 ] = 0.0 ; rtB . lhj2ghm2f4 [ 2 ] = 0.0 ; rtB . lhj2ghm2f4 [ 3
] = 0.0 ; rtB . dbqcdqyhwy [ 0 ] = 0.0 ; rtB . dbqcdqyhwy [ 1 ] = 0.0 ; rtB .
c02zl0czxs = 0.0 ; rtB . pugsu0nevr [ 0 ] = 0.0 ; rtB . pugsu0nevr [ 1 ] =
0.0 ; rtB . bw14bin5hh = 0.0 ; rtB . ldw4br50ng = 0.0 ; rtB . gsofcjddvn =
0.0 ; rtB . lzsvpxojnz [ 0 ] = 0.0 ; rtB . lzsvpxojnz [ 1 ] = 0.0 ; rtB .
n10inqqacb [ 0 ] = 0.0 ; rtB . n10inqqacb [ 1 ] = 0.0 ; rtB . nastbsm32g =
0.0 ; rtB . nxnoiv0pth = 0.0 ; rtB . au5g3iyahf = 0.0 ; rtB . ffbtpjovm2 =
0.0 ; rtB . enmfzw4wn5 = 0.0 ; rtB . na2ttkkmwd [ 0 ] = 0.0 ; rtB .
na2ttkkmwd [ 1 ] = 0.0 ; rtB . eux2brobbv [ 0 ] = 0.0 ; rtB . eux2brobbv [ 1
] = 0.0 ; rtB . eux2brobbv [ 2 ] = 0.0 ; rtB . eux2brobbv [ 3 ] = 0.0 ; rtB .
eoyd4uc25o = 0.0 ; rtB . cawwajqazb = 0.0 ; rtB . d1h14ldyu4 = 0.0 ; rtB .
cs2wisepbp = 0.0 ; rtB . d4qvlfmvmy = 0.0 ; rtB . kurks2zcva = 0.0 ; rtB .
p0z5ebkftq [ 0 ] = 0.0 ; rtB . p0z5ebkftq [ 1 ] = 0.0 ; rtB . p0z5ebkftq [ 2
] = 0.0 ; rtB . p0z5ebkftq [ 3 ] = 0.0 ; rtB . fsr4klu2iw [ 0 ] = 0.0 ; rtB .
fsr4klu2iw [ 1 ] = 0.0 ; rtB . fsr4klu2iw [ 2 ] = 0.0 ; rtB . fsr4klu2iw [ 3
] = 0.0 ; rtB . b3buxfo0jq = 0.0 ; rtB . m4ofszhbm4 = 0.0 ; rtB . b30gw04tpb
= 0.0 ; rtB . irpgyparai = 0.0 ; rtB . gdvqwx5p4u = 0.0 ; rtB . g03umd0jya =
0.0 ; rtB . do20asbnvu = 0.0 ; rtB . nyh5uqpipi [ 0 ] = 0.0 ; rtB .
nyh5uqpipi [ 1 ] = 0.0 ; rtB . nyh5uqpipi [ 2 ] = 0.0 ; rtB . nyh5uqpipi [ 3
] = 0.0 ; rtB . p1j2mjcnmh [ 0 ] = 0.0 ; rtB . p1j2mjcnmh [ 1 ] = 0.0 ; rtB .
p1j2mjcnmh [ 2 ] = 0.0 ; rtB . p1j2mjcnmh [ 3 ] = 0.0 ; rtB . a2j3heg5ll [ 0
] = 0.0 ; rtB . a2j3heg5ll [ 1 ] = 0.0 ; rtB . a2j3heg5ll [ 2 ] = 0.0 ; rtB .
a2j3heg5ll [ 3 ] = 0.0 ; rtB . aee3tydqqe [ 0 ] = 0.0 ; rtB . aee3tydqqe [ 1
] = 0.0 ; rtB . l2ny1ho3uf = 0.0 ; rtB . o4komacgjl [ 0 ] = 0.0 ; rtB .
o4komacgjl [ 1 ] = 0.0 ; rtB . h4tgjphw5q = 0.0 ; rtB . ldmwux2zhx = 0.0 ;
rtB . kms2jmv2td = 0.0 ; rtB . ozch1m2xun [ 0 ] = 0.0 ; rtB . ozch1m2xun [ 1
] = 0.0 ; rtB . p4eyqrx5tw [ 0 ] = 0.0 ; rtB . p4eyqrx5tw [ 1 ] = 0.0 ; rtB .
dzlnvksxlk = 0.0 ; rtB . iy2ry2qx1u = 0.0 ; rtB . jw5211g3vm = 0.0 ; rtB .
ctjaojcbjq = 0.0 ; rtB . kknf5smhy4 = 0.0 ; rtB . blvbd5kgbi [ 0 ] = 0.0 ;
rtB . blvbd5kgbi [ 1 ] = 0.0 ; rtB . hjgncjfz4l [ 0 ] = 0.0 ; rtB .
hjgncjfz4l [ 1 ] = 0.0 ; rtB . hjgncjfz4l [ 2 ] = 0.0 ; rtB . hjgncjfz4l [ 3
] = 0.0 ; rtB . oqxkfo2dq5 = 0.0 ; rtB . oues2lcti4 = 0.0 ; rtB . eelx0pksev
= 0.0 ; rtB . lg5rqpaf2e = 0.0 ; rtB . hm532ngjvw = 0.0 ; rtB . c24lrwyun4 =
0.0 ; rtB . fo5rqi15o1 = 0.0 ; rtB . f2q5magsot = 0.0 ; rtB . lc3tl5isia =
0.0 ; rtB . clfpixb40s [ 0 ] = 0.0 ; rtB . clfpixb40s [ 1 ] = 0.0 ; rtB .
clfpixb40s [ 2 ] = 0.0 ; rtB . clfpixb40s [ 3 ] = 0.0 ; rtB . fl0i4sb4vv [ 0
] = 0.0 ; rtB . fl0i4sb4vv [ 1 ] = 0.0 ; rtB . fl0i4sb4vv [ 2 ] = 0.0 ; rtB .
fl0i4sb4vv [ 3 ] = 0.0 ; rtB . gmhqlr0ded [ 0 ] = 0.0 ; rtB . gmhqlr0ded [ 1
] = 0.0 ; rtB . gmhqlr0ded [ 2 ] = 0.0 ; rtB . gmhqlr0ded [ 3 ] = 0.0 ; rtB .
carjwykir1 [ 0 ] = 0.0 ; rtB . carjwykir1 [ 1 ] = 0.0 ; rtB . carjwykir1 [ 2
] = 0.0 ; rtB . carjwykir1 [ 3 ] = 0.0 ; rtB . caywsc2yvv [ 0 ] = 0.0 ; rtB .
caywsc2yvv [ 1 ] = 0.0 ; rtB . caywsc2yvv [ 2 ] = 0.0 ; rtB . caywsc2yvv [ 3
] = 0.0 ; rtB . eyrg550icf [ 0 ] = 0.0 ; rtB . eyrg550icf [ 1 ] = 0.0 ; rtB .
eyrg550icf [ 2 ] = 0.0 ; rtB . eyrg550icf [ 3 ] = 0.0 ; rtB . pnwecd2kft =
0.0 ; rtB . gej5khtvm2 = 0.0 ; rtB . ozftnlfeg3 . n0fuel1bnn = 0.0 ; rtB .
ozftnlfeg3 . dberndtk2w = 0.0 ; rtB . ozftnlfeg3 . on2dguwvvl = 0.0 ; rtB .
jrosma4ai4 . hgxfgflt2m [ 0 ] = 0.0 ; rtB . jrosma4ai4 . hgxfgflt2m [ 1 ] =
0.0 ; rtB . jrosma4ai4 . hgxfgflt2m [ 2 ] = 0.0 ; rtB . jrosma4ai4 .
hgxfgflt2m [ 3 ] = 0.0 ; rtB . jlne01gbu0 . hgxfgflt2m [ 0 ] = 0.0 ; rtB .
jlne01gbu0 . hgxfgflt2m [ 1 ] = 0.0 ; rtB . jlne01gbu0 . hgxfgflt2m [ 2 ] =
0.0 ; rtB . jlne01gbu0 . hgxfgflt2m [ 3 ] = 0.0 ; rtB . nybhsuuh1p .
mesgqmrxmy [ 0 ] = 0.0 ; rtB . nybhsuuh1p . mesgqmrxmy [ 1 ] = 0.0 ; rtB .
nybhsuuh1p . mesgqmrxmy [ 2 ] = 0.0 ; rtB . nybhsuuh1p . mesgqmrxmy [ 3 ] =
0.0 ; rtB . b4zolxyidp . c03pdi1rvc [ 0 ] = 0.0 ; rtB . b4zolxyidp .
c03pdi1rvc [ 1 ] = 0.0 ; rtB . b4zolxyidp . c03pdi1rvc [ 2 ] = 0.0 ; rtB .
b4zolxyidp . c03pdi1rvc [ 3 ] = 0.0 ; rtB . pz2stfwruz . bbcbwrpqmg [ 0 ] =
0.0 ; rtB . pz2stfwruz . bbcbwrpqmg [ 1 ] = 0.0 ; rtB . pz2stfwruz .
bbcbwrpqmg [ 2 ] = 0.0 ; rtB . pz2stfwruz . bbcbwrpqmg [ 3 ] = 0.0 ; rtB .
nlrcxogbog . ovjujdzpjt [ 0 ] = 0.0 ; rtB . nlrcxogbog . ovjujdzpjt [ 1 ] =
0.0 ; rtB . nlrcxogbog . ovjujdzpjt [ 2 ] = 0.0 ; rtB . nlrcxogbog .
ovjujdzpjt [ 3 ] = 0.0 ; rtB . j20pq3r21f . ioo1a4zpmx [ 0 ] = 0.0 ; rtB .
j20pq3r21f . ioo1a4zpmx [ 1 ] = 0.0 ; rtB . avezulewcn . n0fuel1bnn = 0.0 ;
rtB . avezulewcn . dberndtk2w = 0.0 ; rtB . avezulewcn . on2dguwvvl = 0.0 ;
rtB . k04lp2vsfm . hgxfgflt2m [ 0 ] = 0.0 ; rtB . k04lp2vsfm . hgxfgflt2m [ 1
] = 0.0 ; rtB . k04lp2vsfm . hgxfgflt2m [ 2 ] = 0.0 ; rtB . k04lp2vsfm .
hgxfgflt2m [ 3 ] = 0.0 ; rtB . p0jpb31wlq . hgxfgflt2m [ 0 ] = 0.0 ; rtB .
p0jpb31wlq . hgxfgflt2m [ 1 ] = 0.0 ; rtB . p0jpb31wlq . hgxfgflt2m [ 2 ] =
0.0 ; rtB . p0jpb31wlq . hgxfgflt2m [ 3 ] = 0.0 ; rtB . l1cumv5mxc .
mesgqmrxmy [ 0 ] = 0.0 ; rtB . l1cumv5mxc . mesgqmrxmy [ 1 ] = 0.0 ; rtB .
l1cumv5mxc . mesgqmrxmy [ 2 ] = 0.0 ; rtB . l1cumv5mxc . mesgqmrxmy [ 3 ] =
0.0 ; rtB . pcljl3fmii . c03pdi1rvc [ 0 ] = 0.0 ; rtB . pcljl3fmii .
c03pdi1rvc [ 1 ] = 0.0 ; rtB . pcljl3fmii . c03pdi1rvc [ 2 ] = 0.0 ; rtB .
pcljl3fmii . c03pdi1rvc [ 3 ] = 0.0 ; rtB . mmnlogmmqe . bbcbwrpqmg [ 0 ] =
0.0 ; rtB . mmnlogmmqe . bbcbwrpqmg [ 1 ] = 0.0 ; rtB . mmnlogmmqe .
bbcbwrpqmg [ 2 ] = 0.0 ; rtB . mmnlogmmqe . bbcbwrpqmg [ 3 ] = 0.0 ; rtB .
ipvzgutla1 . ovjujdzpjt [ 0 ] = 0.0 ; rtB . ipvzgutla1 . ovjujdzpjt [ 1 ] =
0.0 ; rtB . ipvzgutla1 . ovjujdzpjt [ 2 ] = 0.0 ; rtB . ipvzgutla1 .
ovjujdzpjt [ 3 ] = 0.0 ; rtB . dvrqjotubu . ioo1a4zpmx [ 0 ] = 0.0 ; rtB .
dvrqjotubu . ioo1a4zpmx [ 1 ] = 0.0 ; rtB . cwkcdvwsyb . n0fuel1bnn = 0.0 ;
rtB . cwkcdvwsyb . dberndtk2w = 0.0 ; rtB . cwkcdvwsyb . on2dguwvvl = 0.0 ;
rtB . gpr5ewbwvu . hgxfgflt2m [ 0 ] = 0.0 ; rtB . gpr5ewbwvu . hgxfgflt2m [ 1
] = 0.0 ; rtB . gpr5ewbwvu . hgxfgflt2m [ 2 ] = 0.0 ; rtB . gpr5ewbwvu .
hgxfgflt2m [ 3 ] = 0.0 ; rtB . pmll2wrcy3 . hgxfgflt2m [ 0 ] = 0.0 ; rtB .
pmll2wrcy3 . hgxfgflt2m [ 1 ] = 0.0 ; rtB . pmll2wrcy3 . hgxfgflt2m [ 2 ] =
0.0 ; rtB . pmll2wrcy3 . hgxfgflt2m [ 3 ] = 0.0 ; rtB . omwjydko3j .
mesgqmrxmy [ 0 ] = 0.0 ; rtB . omwjydko3j . mesgqmrxmy [ 1 ] = 0.0 ; rtB .
omwjydko3j . mesgqmrxmy [ 2 ] = 0.0 ; rtB . omwjydko3j . mesgqmrxmy [ 3 ] =
0.0 ; rtB . ejkqkpkoqg . c03pdi1rvc [ 0 ] = 0.0 ; rtB . ejkqkpkoqg .
c03pdi1rvc [ 1 ] = 0.0 ; rtB . ejkqkpkoqg . c03pdi1rvc [ 2 ] = 0.0 ; rtB .
ejkqkpkoqg . c03pdi1rvc [ 3 ] = 0.0 ; rtB . pxgmr2o0yw . bbcbwrpqmg [ 0 ] =
0.0 ; rtB . pxgmr2o0yw . bbcbwrpqmg [ 1 ] = 0.0 ; rtB . pxgmr2o0yw .
bbcbwrpqmg [ 2 ] = 0.0 ; rtB . pxgmr2o0yw . bbcbwrpqmg [ 3 ] = 0.0 ; rtB .
mrc3jz2kzs . ovjujdzpjt [ 0 ] = 0.0 ; rtB . mrc3jz2kzs . ovjujdzpjt [ 1 ] =
0.0 ; rtB . mrc3jz2kzs . ovjujdzpjt [ 2 ] = 0.0 ; rtB . mrc3jz2kzs .
ovjujdzpjt [ 3 ] = 0.0 ; rtB . jwxitznkuq . ioo1a4zpmx [ 0 ] = 0.0 ; rtB .
jwxitznkuq . ioo1a4zpmx [ 1 ] = 0.0 ; rtB . a21clfzxwp . n0fuel1bnn = 0.0 ;
rtB . a21clfzxwp . dberndtk2w = 0.0 ; rtB . a21clfzxwp . on2dguwvvl = 0.0 ;
rtB . loojatj1b3 . hgxfgflt2m [ 0 ] = 0.0 ; rtB . loojatj1b3 . hgxfgflt2m [ 1
] = 0.0 ; rtB . loojatj1b3 . hgxfgflt2m [ 2 ] = 0.0 ; rtB . loojatj1b3 .
hgxfgflt2m [ 3 ] = 0.0 ; rtB . ae0vvuvpaf . hgxfgflt2m [ 0 ] = 0.0 ; rtB .
ae0vvuvpaf . hgxfgflt2m [ 1 ] = 0.0 ; rtB . ae0vvuvpaf . hgxfgflt2m [ 2 ] =
0.0 ; rtB . ae0vvuvpaf . hgxfgflt2m [ 3 ] = 0.0 ; rtB . lkguggosm5 .
mesgqmrxmy [ 0 ] = 0.0 ; rtB . lkguggosm5 . mesgqmrxmy [ 1 ] = 0.0 ; rtB .
lkguggosm5 . mesgqmrxmy [ 2 ] = 0.0 ; rtB . lkguggosm5 . mesgqmrxmy [ 3 ] =
0.0 ; rtB . n3la5yge0s . c03pdi1rvc [ 0 ] = 0.0 ; rtB . n3la5yge0s .
c03pdi1rvc [ 1 ] = 0.0 ; rtB . n3la5yge0s . c03pdi1rvc [ 2 ] = 0.0 ; rtB .
n3la5yge0s . c03pdi1rvc [ 3 ] = 0.0 ; rtB . mfw2ixjjzd . bbcbwrpqmg [ 0 ] =
0.0 ; rtB . mfw2ixjjzd . bbcbwrpqmg [ 1 ] = 0.0 ; rtB . mfw2ixjjzd .
bbcbwrpqmg [ 2 ] = 0.0 ; rtB . mfw2ixjjzd . bbcbwrpqmg [ 3 ] = 0.0 ; rtB .
i0nb5cbdli . ovjujdzpjt [ 0 ] = 0.0 ; rtB . i0nb5cbdli . ovjujdzpjt [ 1 ] =
0.0 ; rtB . i0nb5cbdli . ovjujdzpjt [ 2 ] = 0.0 ; rtB . i0nb5cbdli .
ovjujdzpjt [ 3 ] = 0.0 ; rtB . pxlv2lf0yq . ioo1a4zpmx [ 0 ] = 0.0 ; rtB .
pxlv2lf0yq . ioo1a4zpmx [ 1 ] = 0.0 ; } } ssSetDefaultParam ( rtS , ( real_T
* ) & rtP ) ; { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x )
; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; rtDW . f5c0nsumji = 0.0 ; rtDW . a5w40p1bws = 0.0 ;
rtDW . eanwkjl2vy = 0.0 ; rtDW . d5bnnktx4e = 0.0 ; rtDW . lnetbv1cgv = 0.0 ;
rtDW . orkc55dufk = 0.0 ; rtDW . nkbjhdynsp = 0.0 ; rtDW . ldb4vi0ha4 = 0.0 ;
rtDW . mjqxgo2das = 0.0 ; rtDW . lstr5kczd4 = 0.0 ; rtDW . ex3o4uqzc2 = 0.0 ;
rtDW . mcbh12k100 = 0.0 ; rtDW . ahv3cotbw2 = 0.0 ; rtDW . p5sygl0ymh = 0.0 ;
rtDW . gidygjlsh2 = 0.0 ; rtDW . oktxx1jm30 [ 0 ] = 0.0 ; rtDW . oktxx1jm30 [
1 ] = 0.0 ; rtDW . jxsk15cftx = 0.0 ; rtDW . h31mfjlljs = 0.0 ; rtDW .
efdih4dveq = 0.0 ; rtDW . n31fjbosih = 0.0 ; rtDW . bj3nvzbqqv = 0.0 ; rtDW .
pftedxldcl = 0.0 ; rtDW . ffb5al3bwy = 0.0 ; rtDW . l2sbaaoqpn = 0.0 ; rtDW .
nha400jjfg = 0.0 ; rtDW . lv3zjk5f1k = 0.0 ; rtDW . bugcdre0xq [ 0 ] = 0.0 ;
rtDW . bugcdre0xq [ 1 ] = 0.0 ; rtDW . ghsofqsrqn = 0.0 ; rtDW . hccpqibboh =
0.0 ; rtDW . mmm2iqducw = 0.0 ; rtDW . caoih1mnoc = 0.0 ; rtDW . ni0pxjjk34 =
0.0 ; rtDW . hlgbmv2r55 = 0.0 ; rtDW . p2lhgag51t = 0.0 ; rtDW . nknewvnn53 =
0.0 ; rtDW . guwv0f3uot [ 0 ] = 0.0 ; rtDW . guwv0f3uot [ 1 ] = 0.0 ; rtDW .
hzmcfcyu1n = 0.0 ; rtDW . ggorbvxv0b = 0.0 ; rtDW . ilfjamszda = 0.0 ; rtDW .
ewze1iozrz = 0.0 ; rtDW . bkwxpr2rpy = 0.0 ; rtDW . l0gdo0gwee = 0.0 ; rtDW .
jy5gknzcfu = 0.0 ; rtDW . mkmpmcvnsy = 0.0 ; rtDW . nom2ms4idi [ 0 ] = 0.0 ;
rtDW . nom2ms4idi [ 1 ] = 0.0 ; rtDW . h2vskoxuxe = 0.0 ; rtDW . h1t1phh10c [
0 ] = 0.0 ; rtDW . h1t1phh10c [ 1 ] = 0.0 ; rtDW . h1t1phh10c [ 2 ] = 0.0 ;
rtDW . h1t1phh10c [ 3 ] = 0.0 ; rtDW . foiy3odoz1 [ 0 ] = 0.0 ; rtDW .
foiy3odoz1 [ 1 ] = 0.0 ; rtDW . foiy3odoz1 [ 2 ] = 0.0 ; rtDW . foiy3odoz1 [
3 ] = 0.0 ; rtDW . pizmexwruz [ 0 ] = 0.0 ; rtDW . pizmexwruz [ 1 ] = 0.0 ;
rtDW . pizmexwruz [ 2 ] = 0.0 ; rtDW . pizmexwruz [ 3 ] = 0.0 ; rtDW .
k5wmx351m0 [ 0 ] = 0.0 ; rtDW . k5wmx351m0 [ 1 ] = 0.0 ; rtDW . k5wmx351m0 [
2 ] = 0.0 ; rtDW . k5wmx351m0 [ 3 ] = 0.0 ; rtDW . fmmswgsion [ 0 ] = 0.0 ;
rtDW . fmmswgsion [ 1 ] = 0.0 ; rtDW . fmmswgsion [ 2 ] = 0.0 ; rtDW .
fmmswgsion [ 3 ] = 0.0 ; rtDW . aboia0klkk [ 0 ] = 0.0 ; rtDW . aboia0klkk [
1 ] = 0.0 ; rtDW . aboia0klkk [ 2 ] = 0.0 ; rtDW . aboia0klkk [ 3 ] = 0.0 ; {
int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . fvdlnsmpbl [ i ] = 0.0 ; }
} { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . hgisorl0lv [ i ] = 0.0
; } } rtDW . bc1tq0iten = 0.0 ; rtDW . ggpdvqbik4 = 0.0 ; rtDW . eraemmnzoz =
0.0 ; rtDW . cd5a0neolm = 0.0 ; { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) {
rtDW . blweiavnmj [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++
) { rtDW . cxib0dsdcq [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i
++ ) { rtDW . fs03kermta [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100
; i ++ ) { rtDW . gaht5h2guw [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i <
100 ; i ++ ) { rtDW . czc2sb2jwa [ i ] = 0.0 ; } } rtDW . anaa2i2evl = 0.0 ;
rtDW . k0nz2julpt = 0.0 ; rtDW . pkdkxevryy = 0.0 ; rtDW . lnjgkjkghh = 0.0 ;
{ int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . k2lslkrofb [ i ] = 0.0 ;
} } { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . o2kydmp2r4 [ i ] =
0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . i2tar503fo [ i
] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . azcmulp3j0
[ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW .
jbzxiyzok1 [ i ] = 0.0 ; } } rtDW . hrj53k3isf = 0.0 ; rtDW . f0qbsmk4ex =
0.0 ; rtDW . jsd0ujpvhr = 0.0 ; rtDW . pfrwigqbzn = 0.0 ; { int_T i ; for ( i
= 0 ; i < 100 ; i ++ ) { rtDW . auvkbyqkxd [ i ] = 0.0 ; } } { int_T i ; for
( i = 0 ; i < 100 ; i ++ ) { rtDW . f3k0bkdqnd [ i ] = 0.0 ; } } { int_T i ;
for ( i = 0 ; i < 100 ; i ++ ) { rtDW . h0qgaci0at [ i ] = 0.0 ; } } { int_T
i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . e23cqdlwby [ i ] = 0.0 ; } } {
int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . og10ihhnhf [ i ] = 0.0 ; }
} rtDW . oimg4prx1p = 0.0 ; rtDW . goy3rwgvfy = 0.0 ; rtDW . lyohx44v2w = 0.0
; rtDW . eopudmnicm = 0.0 ; { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW
. beo5lordfv [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++ ) {
rtDW . f0slooz0kt [ i ] = 0.0 ; } } { int_T i ; for ( i = 0 ; i < 100 ; i ++
) { rtDW . fi5ombzs0c [ i ] = 0.0 ; } } rtDW . ozftnlfeg3 . ka4hfanbtx = 0.0
; rtDW . ozftnlfeg3 . padb2uwtk3 = 0.0 ; rtDW . ozftnlfeg3 . jdyes1duqb = 0.0
; rtDW . j20pq3r21f . j4oaer2coe = 0.0 ; rtDW . j20pq3r21f . diheapmar0 = 0.0
; rtDW . j20pq3r21f . h2qukl2a2z = 0.0 ; rtDW . j20pq3r21f . lpucd5ozhl = 0.0
; rtDW . avezulewcn . ka4hfanbtx = 0.0 ; rtDW . avezulewcn . padb2uwtk3 = 0.0
; rtDW . avezulewcn . jdyes1duqb = 0.0 ; rtDW . dvrqjotubu . j4oaer2coe = 0.0
; rtDW . dvrqjotubu . diheapmar0 = 0.0 ; rtDW . dvrqjotubu . h2qukl2a2z = 0.0
; rtDW . dvrqjotubu . lpucd5ozhl = 0.0 ; rtDW . cwkcdvwsyb . ka4hfanbtx = 0.0
; rtDW . cwkcdvwsyb . padb2uwtk3 = 0.0 ; rtDW . cwkcdvwsyb . jdyes1duqb = 0.0
; rtDW . jwxitznkuq . j4oaer2coe = 0.0 ; rtDW . jwxitznkuq . diheapmar0 = 0.0
; rtDW . jwxitznkuq . h2qukl2a2z = 0.0 ; rtDW . jwxitznkuq . lpucd5ozhl = 0.0
; rtDW . a21clfzxwp . ka4hfanbtx = 0.0 ; rtDW . a21clfzxwp . padb2uwtk3 = 0.0
; rtDW . a21clfzxwp . jdyes1duqb = 0.0 ; rtDW . pxlv2lf0yq . j4oaer2coe = 0.0
; rtDW . pxlv2lf0yq . diheapmar0 = 0.0 ; rtDW . pxlv2lf0yq . h2qukl2a2z = 0.0
; rtDW . pxlv2lf0yq . lpucd5ozhl = 0.0 ; } { static DataTypeTransInfo dtInfo
; ( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 17 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . B = & rtBTransTable ; dtInfo . P = &
rtPTransTable ; } nodes4_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"nodes4" ) ; ssSetPath ( rtS , "nodes4" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 14 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 14 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"states" , "states" , "states" , "states" , "states" , "states" , "states" ,
"states" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"nodes4/g4/control secundario1/Integrator" ,
"nodes4/g4/control secundario1/Integrator1" ,
"nodes4/g4/control secundario1/Integrator2" ,
"nodes4/powergui/EquivalentModel1/State-Space" ,
"nodes4/g1/control secundario1/Integrator" ,
"nodes4/g1/control secundario1/Integrator1" ,
"nodes4/g1/control secundario1/Integrator2" ,
"nodes4/g2/control secundario1/Integrator" ,
"nodes4/g2/control secundario1/Integrator1" ,
"nodes4/g2/control secundario1/Integrator2" ,
"nodes4/g3/control secundario1/Integrator" ,
"nodes4/g3/control secundario1/Integrator1" ,
"nodes4/g3/control secundario1/Integrator2" ,
"nodes4/MCC/control secundario/Integrator" ,
"nodes4/MCC/control secundario/Integrator1" , "nodes4/g4/LPF q" ,
"nodes4/g4/LPF p" , "nodes4/g1/LPF q" , "nodes4/g1/LPF p" , "nodes4/g2/LPF q"
, "nodes4/g2/LPF p" , "nodes4/g3/LPF q" , "nodes4/g3/LPF p" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 23 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 23 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . myddfjqwmy ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . idks32lhev ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . hnfrxgtkqe ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . jqdufexgzv [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . cvbao2hes3 ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . nce055ezz1 ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . cenhjcoeh3 ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . b1xdzpc02l ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . iyto1k1kzw ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . pkxrt4qo4z ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . pvsidq4mg0 ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . hemro31n34 ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . p5jpc4ehox ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . ihfpfs5hha ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . mejopo4his ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtDW . f5c0nsumji ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtDW . a5w40p1bws ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtDW . eanwkjl2vy ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtDW . d5bnnktx4e ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtDW . lnetbv1cgv ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtDW . orkc55dufk ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtDW . nkbjhdynsp ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtDW . ldb4vi0ha4 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssSolverInfo slvrInfo ; static boolean_T
contStatesDisabled [ 28 ] ; static real_T absTol [ 28 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 28 ] = { 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T zcAttributes [
18 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 20 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
f2q5magsot ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fo5rqi15o1 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lg5rqpaf2e ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
eelx0pksev ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
oues2lcti4 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cs2wisepbp ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
d1h14ldyu4 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cawwajqazb ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lmpvvsgbzc ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
hkkbhcvcxm ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lxk0xwc3vx ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
awk2wo0fe2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ec4ppad44q ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
dnqnzblmbp [ 4 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( &
rtB . iodvmyfik4 [ 4 ] ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * )
( & rtB . n2zlvavzvj [ 4 ] ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char
* ) ( & rtB . n0mg2py0tt ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char *
) ( & rtB . gq1khgfhm2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * )
( & rtB . h1tgqdz5v2 ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) (
& rtB . dpgwwjc2rz [ 4 ] ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 )
; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.0001 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
20 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 18 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1000 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid
( rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 18 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1000 ) ; }
ssSetChecksumVal ( rtS , 0 , 1063567491U ) ; ssSetChecksumVal ( rtS , 1 ,
88383218U ) ; ssSetChecksumVal ( rtS , 2 , 3038457091U ) ; ssSetChecksumVal (
rtS , 3 , 3990997617U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 42 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ;
systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = & rtAlwaysEnabled ;
systemRan [ 26 ] = & rtAlwaysEnabled ; systemRan [ 27 ] = & rtAlwaysEnabled ;
systemRan [ 28 ] = & rtAlwaysEnabled ; systemRan [ 29 ] = & rtAlwaysEnabled ;
systemRan [ 30 ] = & rtAlwaysEnabled ; systemRan [ 31 ] = & rtAlwaysEnabled ;
systemRan [ 32 ] = & rtAlwaysEnabled ; systemRan [ 33 ] = & rtAlwaysEnabled ;
systemRan [ 34 ] = & rtAlwaysEnabled ; systemRan [ 35 ] = & rtAlwaysEnabled ;
systemRan [ 36 ] = & rtAlwaysEnabled ; systemRan [ 37 ] = & rtAlwaysEnabled ;
systemRan [ 38 ] = & rtAlwaysEnabled ; systemRan [ 39 ] = & rtAlwaysEnabled ;
systemRan [ 40 ] = & rtAlwaysEnabled ; systemRan [ 41 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } ssSetNumSFunctions ( rtS , 9 ) ; { static SimStruct
childSFunctions [ 9 ] ; static SimStruct * childSFunctionPtrs [ 9 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; { int_T i ; for
( i = 0 ; i < 9 ; i ++ ) { ssSetSFunction ( rtS , i , & childSFunctions [ i ]
) ; } } { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T
sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [
1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ;
( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [
0 ] = & rtB . f5kuq3shj4 ; sfcnUPtrs [ 1 ] = & rtB . poglkcfqy3 ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . ktweuvg11j [ 0 ] ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value_m3cxrwlf3n ; ssSetInputPortSignalPtrs ( rts , 3 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3
, 1 ) ; ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 4 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 6 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . dpgwwjc2rz )
) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth
( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB .
kycfwls143 ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( (
real_T * ) & rtB . ee5gbg0io5 ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
3 , 1 ) ; ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts
, 3 , ( ( real_T * ) & rtB . avlxjfrevq ) ) ; } } ssSetModelName ( rts ,
"ttkernel" ) ; ssSetPath ( rts , "nodes4/g4/TrueTime Kernel1/ttkernel" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttkernel_P1_Size ) ; ssSetSFcnParam ( rts , 1 , ( mxArray
* ) rtP . ttkernel_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP .
ttkernel_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP .
ttkernel_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
ttkernel_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
ttkernel_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
ttkernel_P7_Size ) ; } ttkernelMATLAB ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 0 ) ; _ssSetInputPortConnected ( rts ,
2 , 1 ) ; _ssSetInputPortConnected ( rts , 3 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 0 ) ;
_ssSetOutputPortConnected ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 3 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 3 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [
0 ] = ( real_T * ) & nodes4_RGND ; sfcnUPtrs [ 1 ] = ( real_T * ) &
nodes4_RGND ; sfcnUPtrs [ 2 ] = & rtB . okzfmxk5yy ; ssSetInputPortSignalPtrs
( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 3 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value ; ssSetInputPortSignalPtrs ( rts , 3 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3 , 1 ) ;
ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 4 ) ; { _ssSetOutputPortNumDimensions ( rts
, 0 , 1 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortSignal (
rts , 0 , ( ( real_T * ) & rtB . bxyd4fbh0g ) ) ; } {
_ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth ( rts ,
1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB . pijde51qab
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( (
real_T * ) & rtB . gehrrnez0b ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
3 , 1 ) ; ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts
, 3 , ( ( real_T * ) & rtB . dwdpwj5pni ) ) ; } } ssSetModelName ( rts ,
"ttkernel" ) ; ssSetPath ( rts , "nodes4/g4/TrueTime Kernel/ttkernel" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttkernel_P1_Size_jf5opyvoys ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . ttkernel_P2_Size_izl4uhaorl ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . ttkernel_P3_Size_i21pwe23fu ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . ttkernel_P4_Size_aiefmpkvfj ) ; ssSetSFcnParam (
rts , 4 , ( mxArray * ) rtP . ttkernel_P5_Size_hkxbp1a0ew ) ; ssSetSFcnParam
( rts , 5 , ( mxArray * ) rtP . ttkernel_P6_Size_al254xvutt ) ;
ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP . ttkernel_P7_Size_oxdepfy1qh )
; } ttkernelMATLAB ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 0 ) ; _ssSetInputPortConnected ( rts ,
2 , 1 ) ; _ssSetInputPortConnected ( rts , 3 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 1 ) ;
_ssSetOutputPortConnected ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 3 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 3 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [
0 ] = & rtB . jkgsoin4ud ; sfcnUPtrs [ 1 ] = & rtB . adhev5qmdl ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . ktweuvg11j [ 1 ] ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value_eili3hnu3q ; ssSetInputPortSignalPtrs ( rts , 3 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3
, 1 ) ; ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 4 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 6 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . n2zlvavzvj )
) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth
( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB .
lvxcghiadw ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( (
real_T * ) & rtB . iz5ulgunhl ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
3 , 1 ) ; ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts
, 3 , ( ( real_T * ) & rtB . falp0kne2f ) ) ; } } ssSetModelName ( rts ,
"ttkernel" ) ; ssSetPath ( rts , "nodes4/g1/TrueTime Kernel1/ttkernel" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttkernel_P1_Size_e1rhfzjrya ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . ttkernel_P2_Size_cdmxvlsmto ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . ttkernel_P3_Size_iwd0slb2gf ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . ttkernel_P4_Size_a5ktgh3yh5 ) ; ssSetSFcnParam (
rts , 4 , ( mxArray * ) rtP . ttkernel_P5_Size_jyfummcptc ) ; ssSetSFcnParam
( rts , 5 , ( mxArray * ) rtP . ttkernel_P6_Size_k4rxbnl5wn ) ;
ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP . ttkernel_P7_Size_lbdowzzhsh )
; } ttkernelMATLAB ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 0 ) ; _ssSetInputPortConnected ( rts ,
2 , 1 ) ; _ssSetInputPortConnected ( rts , 3 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 0 ) ;
_ssSetOutputPortConnected ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 3 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 3 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [
0 ] = & rtB . kurks2zcva ; sfcnUPtrs [ 1 ] = & rtB . d4qvlfmvmy ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . ktweuvg11j [ 2 ] ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value_m3e32tg5wn ; ssSetInputPortSignalPtrs ( rts , 3 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3
, 1 ) ; ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 4 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 6 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . iodvmyfik4 )
) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth
( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB .
fobyeqif54 ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( (
real_T * ) & rtB . iftyjztmep ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
3 , 1 ) ; ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts
, 3 , ( ( real_T * ) & rtB . cyfk1qotlx ) ) ; } } ssSetModelName ( rts ,
"ttkernel" ) ; ssSetPath ( rts , "nodes4/g2/TrueTime Kernel1/ttkernel" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttkernel_P1_Size_c3l52okdxq ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . ttkernel_P2_Size_ixx5npjavz ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . ttkernel_P3_Size_ft2nkbdsul ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . ttkernel_P4_Size_cljt4zquq0 ) ; ssSetSFcnParam (
rts , 4 , ( mxArray * ) rtP . ttkernel_P5_Size_cie0k5ev3b ) ; ssSetSFcnParam
( rts , 5 , ( mxArray * ) rtP . ttkernel_P6_Size_alm01kaiim ) ;
ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP . ttkernel_P7_Size_eexnjryd5a )
; } ttkernelMATLAB ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 0 ) ; _ssSetInputPortConnected ( rts ,
2 , 1 ) ; _ssSetInputPortConnected ( rts , 3 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 0 ) ;
_ssSetOutputPortConnected ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 3 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 3 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [
0 ] = & rtB . c24lrwyun4 ; sfcnUPtrs [ 1 ] = & rtB . hm532ngjvw ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . ktweuvg11j [ 3 ] ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value_bn3izespin ; ssSetInputPortSignalPtrs ( rts , 3 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3
, 1 ) ; ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 4 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 6 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . dnqnzblmbp )
) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ; ssSetOutputPortWidth
( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB .
cwaxgcfgm2 ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( (
real_T * ) & rtB . of4z3nxnpu ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
3 , 1 ) ; ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts
, 3 , ( ( real_T * ) & rtB . mpet5fjgog ) ) ; } } ssSetModelName ( rts ,
"ttkernel" ) ; ssSetPath ( rts , "nodes4/g3/TrueTime Kernel1/ttkernel" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttkernel_P1_Size_f2220j5olj ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . ttkernel_P2_Size_h5anevphuv ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . ttkernel_P3_Size_e0ueiun5mg ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . ttkernel_P4_Size_hn4jfjyypr ) ; ssSetSFcnParam (
rts , 4 , ( mxArray * ) rtP . ttkernel_P5_Size_fsnsrejkzu ) ; ssSetSFcnParam
( rts , 5 , ( mxArray * ) rtP . ttkernel_P6_Size_k0z5o1n5im ) ;
ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP . ttkernel_P7_Size_neskas0nfa )
; } ttkernelMATLAB ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetInputPortConnected ( rts , 1 , 0 ) ; _ssSetInputPortConnected ( rts ,
2 , 1 ) ; _ssSetInputPortConnected ( rts , 3 , 1 ) ;
_ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts ,
1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 0 ) ;
_ssSetOutputPortConnected ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged ( rts
, 0 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 3 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 3 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ;
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2
( rts , & statesInfo2 ) ; } { static struct _ssPortInputs inputPortInfo [ 4 ]
; _ssSetNumInputPorts ( rts , 4 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static real_T const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [
0 ] = ( real_T * ) & nodes4_RGND ; sfcnUPtrs [ 1 ] = ( real_T * ) &
nodes4_RGND ; sfcnUPtrs [ 2 ] = & rtB . pgkimqavpk ; ssSetInputPortSignalPtrs
( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 3 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 1 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1
, 1 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ;
ssSetInputPortSignalPtrs ( rts , 2 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 2 , 1 ) ; ssSetInputPortWidth ( rts , 2
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP .
Energy_Value_mbh2pufmpv ; ssSetInputPortSignalPtrs ( rts , 3 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 3
, 1 ) ; ssSetInputPortWidth ( rts , 3 , 1 ) ; } } { static struct
_ssPortOutputs outputPortInfo [ 4 ] ; ssSetPortInfoForOutputs ( rts , &
outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 4 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . ellko3pdhd
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidth ( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( (
real_T * ) & rtB . e4hzm4gatj ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
2 , 1 ) ; ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts
, 2 , ( ( real_T * ) & rtB . podole3fca ) ) ; } {
_ssSetOutputPortNumDimensions ( rts , 3 , 1 ) ; ssSetOutputPortWidth ( rts ,
3 , 1 ) ; ssSetOutputPortSignal ( rts , 3 , ( ( real_T * ) & rtB . lhfof1cyys
) ) ; } } ssSetModelName ( rts , "ttkernel" ) ; ssSetPath ( rts ,
"nodes4/g1/TrueTime Kernel/ttkernel" ) ; if ( ssGetRTModel ( rtS ) == ( NULL
) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) )
; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts
, ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 7 ] ;
ssSetSFcnParamsCount ( rts , 7 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
ttkernel_P1_Size_ffv5o0ejnq ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP
. ttkernel_P2_Size_hnyoknt3zl ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * )
rtP . ttkernel_P3_Size_n2dbq4lzwy ) ; ssSetSFcnParam ( rts , 3 , ( mxArray *
) rtP . ttkernel_P4_Size_bvdbf2laou ) ; ssSetSFcnParam ( rts , 4 , ( mxArray
* ) rtP . ttkernel_P5_Size_dqgaqmlayd ) ; ssSetSFcnParam ( rts , 5 , (
mxArray * ) rtP . ttkernel_P6_Size_eg2k0kqu0y ) ; ssSetSFcnParam ( rts , 6 ,
( mxArray * ) rtP . ttkernel_P7_Size_o4e40mczhh ) ; } ttkernelMATLAB ( rts )
; sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 1.0 ) ;
sfcnTsMap [ 0 ] = 1 ; ssSetNumNonsampledZCs ( rts , 1 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 0 ) ; _ssSetInputPortConnected ( rts , 2 , 1 ) ; _ssSetInputPortConnected (
rts , 3 , 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts ,
2 , 1 ) ; _ssSetOutputPortConnected ( rts , 3 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 3 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 3 , - 1 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; static
time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T
sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof (
time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; {
static struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , &
methods2 ) ; } { static struct _ssSFcnModelMethods3 methods3 ;
ssSetModelMethods3 ( rts , & methods3 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ; } { static struct
_ssPortInputs inputPortInfo [ 4 ] ; _ssSetNumInputPorts ( rts , 4 ) ;
ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static real_T
const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ;
sfcnUPtrs [ 1 ] = ( real_T * ) & nodes4_RGND ; sfcnUPtrs [ 2 ] = & rtB .
c02zl0czxs ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 3 ) ; } { static real_T const * sfcnUPtrs [ 1
] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs (
rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidth ( rts , 1
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 2 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 2
, 1 ) ; ssSetInputPortWidth ( rts , 2 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP . Energy_Value_enxalamlm2 ;
ssSetInputPortSignalPtrs ( rts , 3 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 3 , 1 ) ; ssSetInputPortWidth ( rts , 3
, 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 4 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 4 ) ; { _ssSetOutputPortNumDimensions ( rts , 0
, 1 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts ,
0 , ( ( real_T * ) & rtB . nastbsm32g ) ) ; } { _ssSetOutputPortNumDimensions
( rts , 1 , 1 ) ; ssSetOutputPortWidth ( rts , 1 , 1 ) ;
ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB . nxnoiv0pth ) ) ; } {
_ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ; ssSetOutputPortWidth ( rts ,
2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( ( real_T * ) & rtB . au5g3iyahf
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 3 , 1 ) ;
ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts , 3 , ( (
real_T * ) & rtB . ffbtpjovm2 ) ) ; } } ssSetModelName ( rts , "ttkernel" ) ;
ssSetPath ( rts , "nodes4/g2/TrueTime Kernel/ttkernel" ) ; if ( ssGetRTModel
( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
ttkernel_P1_Size_dwt5io1jt3 ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP
. ttkernel_P2_Size_lzb4fzavv1 ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * )
rtP . ttkernel_P3_Size_a3gr3qw5ix ) ; ssSetSFcnParam ( rts , 3 , ( mxArray *
) rtP . ttkernel_P4_Size_o0ydhdm4qv ) ; ssSetSFcnParam ( rts , 4 , ( mxArray
* ) rtP . ttkernel_P5_Size_mffn13gx0r ) ; ssSetSFcnParam ( rts , 5 , (
mxArray * ) rtP . ttkernel_P6_Size_fbneyaga5q ) ; ssSetSFcnParam ( rts , 6 ,
( mxArray * ) rtP . ttkernel_P7_Size_ekne3o4qcs ) ; } ttkernelMATLAB ( rts )
; sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 1.0 ) ;
sfcnTsMap [ 0 ] = 1 ; ssSetNumNonsampledZCs ( rts , 1 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 0 ) ; _ssSetInputPortConnected ( rts , 2 , 1 ) ; _ssSetInputPortConnected (
rts , 3 , 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts ,
2 , 1 ) ; _ssSetOutputPortConnected ( rts , 3 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 3 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 3 , - 1 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; static
time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T
sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof (
time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; {
static struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , &
methods2 ) ; } { static struct _ssSFcnModelMethods3 methods3 ;
ssSetModelMethods3 ( rts , & methods3 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ; } { static struct
_ssPortInputs inputPortInfo [ 4 ] ; _ssSetNumInputPorts ( rts , 4 ) ;
ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static real_T
const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ;
sfcnUPtrs [ 1 ] = ( real_T * ) & nodes4_RGND ; sfcnUPtrs [ 2 ] = & rtB .
l2ny1ho3uf ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 3 ) ; } { static real_T const * sfcnUPtrs [ 1
] ; sfcnUPtrs [ 0 ] = ( real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs (
rts , 1 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidth ( rts , 1
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = (
real_T * ) & nodes4_RGND ; ssSetInputPortSignalPtrs ( rts , 2 , (
InputPtrsType ) & sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 2
, 1 ) ; ssSetInputPortWidth ( rts , 2 , 1 ) ; } { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtP . Energy_Value_hjsumqx5yk ;
ssSetInputPortSignalPtrs ( rts , 3 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 3 , 1 ) ; ssSetInputPortWidth ( rts , 3
, 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 4 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 4 ) ; { _ssSetOutputPortNumDimensions ( rts , 0
, 1 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts ,
0 , ( ( real_T * ) & rtB . dzlnvksxlk ) ) ; } { _ssSetOutputPortNumDimensions
( rts , 1 , 1 ) ; ssSetOutputPortWidth ( rts , 1 , 1 ) ;
ssSetOutputPortSignal ( rts , 1 , ( ( real_T * ) & rtB . iy2ry2qx1u ) ) ; } {
_ssSetOutputPortNumDimensions ( rts , 2 , 1 ) ; ssSetOutputPortWidth ( rts ,
2 , 1 ) ; ssSetOutputPortSignal ( rts , 2 , ( ( real_T * ) & rtB . jw5211g3vm
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 3 , 1 ) ;
ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortSignal ( rts , 3 , ( (
real_T * ) & rtB . ctjaojcbjq ) ) ; } } ssSetModelName ( rts , "ttkernel" ) ;
ssSetPath ( rts , "nodes4/g3/TrueTime Kernel/ttkernel" ) ; if ( ssGetRTModel
( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 7 ] ; ssSetSFcnParamsCount ( rts , 7 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
ttkernel_P1_Size_p20pgflkve ) ; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP
. ttkernel_P2_Size_gzkp3kxg33 ) ; ssSetSFcnParam ( rts , 2 , ( mxArray * )
rtP . ttkernel_P3_Size_l2jji5uq1j ) ; ssSetSFcnParam ( rts , 3 , ( mxArray *
) rtP . ttkernel_P4_Size_hnklzt0jw3 ) ; ssSetSFcnParam ( rts , 4 , ( mxArray
* ) rtP . ttkernel_P5_Size_fa3fkgeu1l ) ; ssSetSFcnParam ( rts , 5 , (
mxArray * ) rtP . ttkernel_P6_Size_p3pprs52yg ) ; ssSetSFcnParam ( rts , 6 ,
( mxArray * ) rtP . ttkernel_P7_Size_frsmcrmh0u ) ; } ttkernelMATLAB ( rts )
; sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 1.0 ) ;
sfcnTsMap [ 0 ] = 1 ; ssSetNumNonsampledZCs ( rts , 1 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 0 ) ; _ssSetInputPortConnected ( rts , 2 , 1 ) ; _ssSetInputPortConnected (
rts , 3 , 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected ( rts ,
2 , 1 ) ; _ssSetOutputPortConnected ( rts , 3 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 3 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 2 , - 1 ) ; ssSetInputPortBufferDstPort (
rts , 3 , - 1 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ; static
time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T
sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof (
time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; {
static struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , &
methods2 ) ; } { static struct _ssSFcnModelMethods3 methods3 ;
ssSetModelMethods3 ( rts , & methods3 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ; } { static struct
_ssPortInputs inputPortInfo [ 1 ] ; _ssSetNumInputPorts ( rts , 1 ) ;
ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static real_T
const * sfcnUPtrs [ 5 ] ; sfcnUPtrs [ 0 ] = & rtB . kycfwls143 ; sfcnUPtrs [
1 ] = & rtB . lvxcghiadw ; sfcnUPtrs [ 2 ] = & rtB . fobyeqif54 ; sfcnUPtrs [
3 ] = & rtB . cwaxgcfgm2 ; sfcnUPtrs [ 4 ] = ( real_T * ) & nodes4_RGND ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 5 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 2 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 2 ) ; { _ssSetOutputPortNumDimensions ( rts , 0
, 1 ) ; ssSetOutputPortWidth ( rts , 0 , 5 ) ; ssSetOutputPortSignal ( rts ,
0 , ( ( real_T * ) rtB . ktweuvg11j ) ) ; } { _ssSetOutputPortNumDimensions (
rts , 1 , 1 ) ; ssSetOutputPortWidth ( rts , 1 , 5 ) ; ssSetOutputPortSignal
( rts , 1 , ( ( real_T * ) rtB . gcnh1cojbn ) ) ; } } ssSetModelName ( rts ,
"ttnetwork" ) ; ssSetPath ( rts , "nodes4/TrueTime Network1/ttnetwork" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 21 ] ; ssSetSFcnParamsCount ( rts , 21 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . ttnetwork_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . ttnetwork_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . ttnetwork_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP
. ttnetwork_P4_Size ) ; ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP .
ttnetwork_P5_Size ) ; ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP .
ttnetwork_P6_Size ) ; ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP .
ttnetwork_P7_Size ) ; ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP .
ttnetwork_P8_Size ) ; ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP .
ttnetwork_P9_Size ) ; ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP .
ttnetwork_P10_Size ) ; ssSetSFcnParam ( rts , 10 , ( mxArray * ) rtP .
ttnetwork_P11_Size ) ; ssSetSFcnParam ( rts , 11 , ( mxArray * ) rtP .
ttnetwork_P12_Size ) ; ssSetSFcnParam ( rts , 12 , ( mxArray * ) rtP .
ttnetwork_P13_Size ) ; ssSetSFcnParam ( rts , 13 , ( mxArray * ) rtP .
ttnetwork_P14_Size ) ; ssSetSFcnParam ( rts , 14 , ( mxArray * ) rtP .
ttnetwork_P15_Size ) ; ssSetSFcnParam ( rts , 15 , ( mxArray * ) rtP .
ttnetwork_P16_Size ) ; ssSetSFcnParam ( rts , 16 , ( mxArray * ) rtP .
ttnetwork_P17_Size ) ; ssSetSFcnParam ( rts , 17 , ( mxArray * ) rtP .
ttnetwork_P18_Size ) ; ssSetSFcnParam ( rts , 18 , ( mxArray * ) rtP .
ttnetwork_P19_Size ) ; ssSetSFcnParam ( rts , 19 , ( mxArray * ) rtP .
ttnetwork_P20_Size ) ; ssSetSFcnParam ( rts , 20 , ( mxArray * ) rtP .
ttnetwork_P21_Size ) ; } ttnetwork ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 1.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCs ( rts , 1 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts
, 1 , 1 ) ; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; } } return rtS ; }
