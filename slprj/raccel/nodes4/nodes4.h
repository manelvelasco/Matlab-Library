#include "__cf_nodes4.h"
#ifndef RTW_HEADER_nodes4_h_
#define RTW_HEADER_nodes4_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef nodes4_COMMON_INCLUDES_
#define nodes4_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "nodes4_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME nodes4
#define NSAMPLE_TIMES (10) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (204) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (28)   
#elif NCSTATES != 28
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
typedef struct { real_T ioo1a4zpmx [ 2 ] ; } cq33sumodo ; typedef struct {
real_T j4oaer2coe ; real_T diheapmar0 ; real_T h2qukl2a2z ; real_T lpucd5ozhl
; boolean_T pk5yc5rzah ; } nd455pykna ; typedef struct { real_T ovjujdzpjt [
4 ] ; } mjvusmhnt4 ; typedef struct { real_T bbcbwrpqmg [ 4 ] ; } lxgqip2r3j
; typedef struct { real_T c03pdi1rvc [ 4 ] ; } ai0etet4ec ; typedef struct {
real_T mesgqmrxmy [ 4 ] ; } m0q1lbf303 ; typedef struct { real_T hgxfgflt2m [
4 ] ; } jojddljsvc ; typedef struct { real_T n0fuel1bnn ; real_T dberndtk2w ;
real_T on2dguwvvl ; } kfdidjbyrv ; typedef struct { real_T ka4hfanbtx ;
real_T padb2uwtk3 ; real_T jdyes1duqb ; } freptvnt4s ; typedef struct {
real_T ek3a1451ay [ 4 ] ; real_T dpgwwjc2rz [ 6 ] ; real_T kycfwls143 ;
real_T ee5gbg0io5 ; real_T avlxjfrevq ; real_T hoq5gatyaq [ 4 ] ; real_T
fntkhkkhap ; real_T biin3vhjc0 ; real_T kkx4ezyhkw ; real_T mpyof2qigx ;
real_T fypbjuyz3n ; real_T mco3v3iige ; real_T hbtkhijkte ; real_T ljwqffhvl4
[ 4 ] ; real_T h4k23zmq31 [ 4 ] ; real_T jsillufvig [ 4 ] ; real_T d2kvmgvdht
[ 2 ] ; real_T okzfmxk5yy ; real_T m1vu1obgik [ 2 ] ; real_T kcbmknce0k ;
real_T lq5dbqfp25 ; real_T ld4l31qhaw ; real_T fchnjsvgwh [ 2 ] ; real_T
ibl2erstls [ 2 ] ; real_T bxyd4fbh0g ; real_T pijde51qab ; real_T gehrrnez0b
; real_T dwdpwj5pni ; real_T dti2carlq5 ; real_T mguxqfcdvk [ 2 ] ; real_T
nebhkpb5ai [ 4 ] ; real_T iewvn51hd3 ; real_T h1tgqdz5v2 ; real_T gq1khgfhm2
; real_T n0mg2py0tt ; real_T n2zlvavzvj [ 6 ] ; real_T lvxcghiadw ; real_T
iz5ulgunhl ; real_T falp0kne2f ; real_T iodvmyfik4 [ 6 ] ; real_T fobyeqif54
; real_T iftyjztmep ; real_T cyfk1qotlx ; real_T dnqnzblmbp [ 6 ] ; real_T
cwaxgcfgm2 ; real_T of4z3nxnpu ; real_T mpet5fjgog ; real_T ec4ppad44q ;
real_T awk2wo0fe2 ; real_T icb23pk4yt [ 10 ] ; real_T poglkcfqy3 ; real_T
f5kuq3shj4 ; real_T aczh1lvgar [ 4 ] ; real_T dzuta0dnpn [ 4 ] ; real_T
hx0wj5yo2m ; real_T kcng2h2ox5 ; real_T d4jrh0gj3t ; real_T nhbi4wyipn ;
real_T pdvnbdhjm2 ; real_T mj22h2mmx5 ; real_T mfwsny1flw ; real_T cbfpuf2or0
[ 4 ] ; real_T abwh33q232 [ 4 ] ; real_T b4slefd2sz [ 4 ] ; real_T ctf1kxqmdo
[ 2 ] ; real_T pgkimqavpk ; real_T f5aj101k3a [ 2 ] ; real_T kkm103ywxt ;
real_T e1nfog11ri ; real_T d535qgtjbe ; real_T kdglpydeda [ 2 ] ; real_T
l523yuyruu [ 2 ] ; real_T ellko3pdhd ; real_T e4hzm4gatj ; real_T podole3fca
; real_T lhfof1cyys ; real_T krez0hg5v1 ; real_T lgfjmq2ecm [ 2 ] ; real_T
i52hyrlq2j [ 4 ] ; real_T hen0mtsi3a ; real_T lxk0xwc3vx ; real_T hkkbhcvcxm
; real_T lmpvvsgbzc ; real_T adhev5qmdl ; real_T jkgsoin4ud ; real_T
fg3wll3qdz [ 4 ] ; real_T keuugvf2im [ 4 ] ; real_T pazkwcssox ; real_T
brmhwzxuee ; real_T g4tkowhewi ; real_T j52dskeymb ; real_T fpqii21x5i ;
real_T ek0x1ax1lz ; real_T n2mcguhbur ; real_T as33t0f0ow [ 4 ] ; real_T
meko05j0sc [ 4 ] ; real_T lhj2ghm2f4 [ 4 ] ; real_T dbqcdqyhwy [ 2 ] ; real_T
c02zl0czxs ; real_T pugsu0nevr [ 2 ] ; real_T bw14bin5hh ; real_T ldw4br50ng
; real_T gsofcjddvn ; real_T lzsvpxojnz [ 2 ] ; real_T n10inqqacb [ 2 ] ;
real_T nastbsm32g ; real_T nxnoiv0pth ; real_T au5g3iyahf ; real_T ffbtpjovm2
; real_T enmfzw4wn5 ; real_T na2ttkkmwd [ 2 ] ; real_T eux2brobbv [ 4 ] ;
real_T eoyd4uc25o ; real_T cawwajqazb ; real_T d1h14ldyu4 ; real_T cs2wisepbp
; real_T d4qvlfmvmy ; real_T kurks2zcva ; real_T p0z5ebkftq [ 4 ] ; real_T
fsr4klu2iw [ 4 ] ; real_T b3buxfo0jq ; real_T m4ofszhbm4 ; real_T b30gw04tpb
; real_T irpgyparai ; real_T gdvqwx5p4u ; real_T g03umd0jya ; real_T
do20asbnvu ; real_T nyh5uqpipi [ 4 ] ; real_T p1j2mjcnmh [ 4 ] ; real_T
a2j3heg5ll [ 4 ] ; real_T aee3tydqqe [ 2 ] ; real_T l2ny1ho3uf ; real_T
o4komacgjl [ 2 ] ; real_T h4tgjphw5q ; real_T ldmwux2zhx ; real_T kms2jmv2td
; real_T ozch1m2xun [ 2 ] ; real_T p4eyqrx5tw [ 2 ] ; real_T dzlnvksxlk ;
real_T iy2ry2qx1u ; real_T jw5211g3vm ; real_T ctjaojcbjq ; real_T kknf5smhy4
; real_T blvbd5kgbi [ 2 ] ; real_T hjgncjfz4l [ 4 ] ; real_T oqxkfo2dq5 ;
real_T oues2lcti4 ; real_T eelx0pksev ; real_T lg5rqpaf2e ; real_T hm532ngjvw
; real_T c24lrwyun4 ; real_T fo5rqi15o1 ; real_T f2q5magsot ; real_T
ktweuvg11j [ 5 ] ; real_T gcnh1cojbn [ 5 ] ; real_T lc3tl5isia ; real_T
clfpixb40s [ 4 ] ; real_T fl0i4sb4vv [ 4 ] ; real_T gmhqlr0ded [ 4 ] ; real_T
carjwykir1 [ 4 ] ; real_T caywsc2yvv [ 4 ] ; real_T eyrg550icf [ 4 ] ; real_T
pnwecd2kft ; real_T gej5khtvm2 ; kfdidjbyrv ozftnlfeg3 ; jojddljsvc
jrosma4ai4 ; jojddljsvc jlne01gbu0 ; m0q1lbf303 nybhsuuh1p ; ai0etet4ec
b4zolxyidp ; lxgqip2r3j pz2stfwruz ; mjvusmhnt4 nlrcxogbog ; cq33sumodo
j20pq3r21f ; kfdidjbyrv avezulewcn ; jojddljsvc k04lp2vsfm ; jojddljsvc
p0jpb31wlq ; m0q1lbf303 l1cumv5mxc ; ai0etet4ec pcljl3fmii ; lxgqip2r3j
mmnlogmmqe ; mjvusmhnt4 ipvzgutla1 ; cq33sumodo dvrqjotubu ; kfdidjbyrv
cwkcdvwsyb ; jojddljsvc gpr5ewbwvu ; jojddljsvc pmll2wrcy3 ; m0q1lbf303
omwjydko3j ; ai0etet4ec ejkqkpkoqg ; lxgqip2r3j pxgmr2o0yw ; mjvusmhnt4
mrc3jz2kzs ; cq33sumodo jwxitznkuq ; kfdidjbyrv a21clfzxwp ; jojddljsvc
loojatj1b3 ; jojddljsvc ae0vvuvpaf ; m0q1lbf303 lkguggosm5 ; ai0etet4ec
n3la5yge0s ; lxgqip2r3j mfw2ixjjzd ; mjvusmhnt4 i0nb5cbdli ; cq33sumodo
pxlv2lf0yq ; } B ; typedef struct { real_T f5c0nsumji ; real_T a5w40p1bws ;
real_T eanwkjl2vy ; real_T d5bnnktx4e ; real_T lnetbv1cgv ; real_T orkc55dufk
; real_T nkbjhdynsp ; real_T ldb4vi0ha4 ; real_T mjqxgo2das ; real_T
lstr5kczd4 ; real_T ex3o4uqzc2 ; real_T mcbh12k100 ; real_T ahv3cotbw2 ;
real_T p5sygl0ymh ; real_T gidygjlsh2 ; real_T oktxx1jm30 [ 2 ] ; real_T
jxsk15cftx ; real_T h31mfjlljs ; real_T efdih4dveq ; real_T n31fjbosih ;
real_T bj3nvzbqqv ; real_T pftedxldcl ; real_T ffb5al3bwy ; real_T l2sbaaoqpn
; real_T nha400jjfg ; real_T lv3zjk5f1k ; real_T bugcdre0xq [ 2 ] ; real_T
ghsofqsrqn ; real_T hccpqibboh ; real_T mmm2iqducw ; real_T caoih1mnoc ;
real_T ni0pxjjk34 ; real_T hlgbmv2r55 ; real_T p2lhgag51t ; real_T nknewvnn53
; real_T guwv0f3uot [ 2 ] ; real_T hzmcfcyu1n ; real_T ggorbvxv0b ; real_T
ilfjamszda ; real_T ewze1iozrz ; real_T bkwxpr2rpy ; real_T l0gdo0gwee ;
real_T jy5gknzcfu ; real_T mkmpmcvnsy ; real_T nom2ms4idi [ 2 ] ; real_T
h2vskoxuxe ; real_T h1t1phh10c [ 4 ] ; real_T foiy3odoz1 [ 4 ] ; real_T
pizmexwruz [ 4 ] ; real_T k5wmx351m0 [ 4 ] ; real_T fmmswgsion [ 4 ] ; real_T
aboia0klkk [ 4 ] ; real_T fvdlnsmpbl [ 100 ] ; real_T hgisorl0lv [ 100 ] ;
real_T bc1tq0iten ; real_T ggpdvqbik4 ; real_T eraemmnzoz ; real_T cd5a0neolm
; real_T blweiavnmj [ 100 ] ; real_T cxib0dsdcq [ 100 ] ; real_T fs03kermta [
100 ] ; real_T gaht5h2guw [ 100 ] ; real_T czc2sb2jwa [ 100 ] ; real_T
anaa2i2evl ; real_T k0nz2julpt ; real_T pkdkxevryy ; real_T lnjgkjkghh ;
real_T k2lslkrofb [ 100 ] ; real_T o2kydmp2r4 [ 100 ] ; real_T i2tar503fo [
100 ] ; real_T azcmulp3j0 [ 100 ] ; real_T jbzxiyzok1 [ 100 ] ; real_T
hrj53k3isf ; real_T f0qbsmk4ex ; real_T jsd0ujpvhr ; real_T pfrwigqbzn ;
real_T auvkbyqkxd [ 100 ] ; real_T f3k0bkdqnd [ 100 ] ; real_T h0qgaci0at [
100 ] ; real_T e23cqdlwby [ 100 ] ; real_T og10ihhnhf [ 100 ] ; real_T
oimg4prx1p ; real_T goy3rwgvfy ; real_T lyohx44v2w ; real_T eopudmnicm ;
real_T beo5lordfv [ 100 ] ; real_T f0slooz0kt [ 100 ] ; real_T fi5ombzs0c [
100 ] ; struct { void * LoggedData ; } izfteet4gt ; struct { void *
LoggedData ; } njuiuoq00q ; struct { void * LoggedData ; } l4tlfv342r ;
struct { void * LoggedData ; } l5yezso4td ; struct { void * LoggedData ; }
hembuefnfy ; struct { void * LoggedData ; } jhyvglnaqs ; struct { void *
LoggedData ; } fqpl3agz2v ; struct { void * LoggedData ; } fw0ubz1mel ;
struct { void * LoggedData ; } frfdkzrjsf ; int_T c5eu0ckh53 ; int_T
al0bnq55uc ; int_T icvisi4y50 ; int_T pjaxqqimom ; int_T cl0xew40qh ; int_T
ewgbd1zlci ; int_T lchl2nrr42 ; int_T naoiq1nxxi ; int_T jktkwtec4i ;
boolean_T dli3x1zfp1 ; boolean_T inwfij3epu ; boolean_T jc3c25clri ;
boolean_T nb5pthjmwg ; freptvnt4s ozftnlfeg3 ; nd455pykna j20pq3r21f ;
freptvnt4s avezulewcn ; nd455pykna dvrqjotubu ; freptvnt4s cwkcdvwsyb ;
nd455pykna jwxitznkuq ; freptvnt4s a21clfzxwp ; nd455pykna pxlv2lf0yq ; } DW
; typedef struct { real_T myddfjqwmy ; real_T idks32lhev ; real_T hnfrxgtkqe
; real_T jqdufexgzv [ 14 ] ; real_T cvbao2hes3 ; real_T nce055ezz1 ; real_T
cenhjcoeh3 ; real_T b1xdzpc02l ; real_T iyto1k1kzw ; real_T pkxrt4qo4z ;
real_T pvsidq4mg0 ; real_T hemro31n34 ; real_T p5jpc4ehox ; real_T ihfpfs5hha
; real_T mejopo4his ; } X ; typedef struct { real_T myddfjqwmy ; real_T
idks32lhev ; real_T hnfrxgtkqe ; real_T jqdufexgzv [ 14 ] ; real_T cvbao2hes3
; real_T nce055ezz1 ; real_T cenhjcoeh3 ; real_T b1xdzpc02l ; real_T
iyto1k1kzw ; real_T pkxrt4qo4z ; real_T pvsidq4mg0 ; real_T hemro31n34 ;
real_T p5jpc4ehox ; real_T ihfpfs5hha ; real_T mejopo4his ; } XDot ; typedef
struct { boolean_T myddfjqwmy ; boolean_T idks32lhev ; boolean_T hnfrxgtkqe ;
boolean_T jqdufexgzv [ 14 ] ; boolean_T cvbao2hes3 ; boolean_T nce055ezz1 ;
boolean_T cenhjcoeh3 ; boolean_T b1xdzpc02l ; boolean_T iyto1k1kzw ;
boolean_T pkxrt4qo4z ; boolean_T pvsidq4mg0 ; boolean_T hemro31n34 ;
boolean_T p5jpc4ehox ; boolean_T ihfpfs5hha ; boolean_T mejopo4his ; } XDis ;
typedef struct { real_T myddfjqwmy ; real_T idks32lhev ; real_T hnfrxgtkqe ;
real_T jqdufexgzv [ 14 ] ; real_T cvbao2hes3 ; real_T nce055ezz1 ; real_T
cenhjcoeh3 ; real_T b1xdzpc02l ; real_T iyto1k1kzw ; real_T pkxrt4qo4z ;
real_T pvsidq4mg0 ; real_T hemro31n34 ; real_T p5jpc4ehox ; real_T ihfpfs5hha
; real_T mejopo4his ; } CStateAbsTol ; typedef struct { real_T hgfgqjzzw5 ;
real_T dunpysylye ; real_T bhihhxlw01 ; real_T llkwhesq35 ; real_T c25e3sp3to
; real_T kar0je5wag ; real_T azu3ihlzds ; real_T lt4vi1vs3u ; real_T
btxc00d2lu ; real_T psnugcw0vd ; real_T mh1tsnw2zi ; real_T pth2xie120 ;
real_T f2t1w3tgsp ; real_T i1jyyuvehq ; real_T jjny4emxrd ; real_T lgxljdgddd
; real_T gg5u4mtitg ; real_T k30bppfzpt ; } ZCV ; typedef struct { ZCSigState
deukvexlkd ; ZCSigState dv2bmzeh5o ; ZCSigState jsvilxeykq ; ZCSigState
pjbedso4wd ; ZCSigState naey3lniq3 ; ZCSigState daxio2vbyh ; ZCSigState
pimoqxgzm1 ; ZCSigState ou203oyw5f ; ZCSigState nnhdwyrgbk ; ZCSigState
okcr4r4pci ; ZCSigState car50xg00x ; ZCSigState mk04jaupx5 ; ZCSigState
evnf5x1aao ; ZCSigState gplh35xowd ; ZCSigState n1bwvmo435 ; ZCSigState
ipayfrkhcf ; ZCSigState pxcgg0zv2m ; ZCSigState esuilc4wnx ; } PrevZCX ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
n1y0minqnv_ { real_T integratorcontrol_a ; real_T integratorcontrol_dr [ 4 ]
; real_T integratorcontrol_kiV ; real_T integratorcontrol_kif ; real_T
integratorcontrol_kpV ; real_T integratorcontrol_kpf ; real_T
integratorcontrol_ts ; real_T integratorcontrol_wo ; } ; struct drnct5ly2o_ {
real_T replacer1_a ; } ; struct ewvp3cxhdz_ { real_T replacer2_a ; } ; struct
ndkw5mnz3z_ { real_T replacer3_a ; } ; struct nbb0zpvvhm_ { real_T
replacer4_a ; } ; struct ozv2axw2sw_ { real_T replacer5_a ; } ; struct
m5tur4wi4k_ { real_T primarycontroldroopZv_Lv ; real_T
primarycontroldroopZv_Vn ; real_T primarycontroldroopZv_dr [ 4 ] ; real_T
primarycontroldroopZv_m ; real_T primarycontroldroopZv_mp ; real_T
primarycontroldroopZv_n ; real_T primarycontroldroopZv_ts ; real_T
primarycontroldroopZv_wo ; } ; struct P_ { real_T array_num_generators ;
real_T consensus_dr [ 4 ] ; real_T consensus_num_generators ; real_T
consensus_ts ; real_T array_num_generators_gcbmamo1qo ; real_T
consensus_dr_cs4dlsi3sq [ 4 ] ; real_T consensus_num_generators_peuoomip1v ;
real_T consensus_ts_c12jwpunuc ; real_T array_num_generators_kut4qav5bm ;
real_T consensus_dr_hf31gowvrj [ 4 ] ; real_T
consensus_num_generators_pcvzfkxjm4 ; real_T consensus_ts_phmvpsqftd ; real_T
array_num_generators_fcv42ncmr5 ; real_T consensus_dr_d4i4gfbgeo [ 4 ] ;
real_T consensus_num_generators_kutqmopsp2 ; real_T consensus_ts_buyezdbmmn ;
real_T ttkernel_P1_Size [ 2 ] ; real_T ttkernel_P1 [ 11 ] ; real_T
ttkernel_P2_Size [ 2 ] ; real_T ttkernel_P2 ; real_T ttkernel_P3_Size [ 2 ] ;
real_T ttkernel_P3 [ 2 ] ; real_T ttkernel_P4_Size [ 2 ] ; real_T ttkernel_P4
; real_T ttkernel_P5_Size [ 2 ] ; real_T ttkernel_P5 ; real_T
ttkernel_P6_Size [ 2 ] ; real_T ttkernel_P6 [ 2 ] ; real_T ttkernel_P7_Size [
2 ] ; real_T ttkernel_P7 [ 2 ] ; real_T Memory1_X0 ; real_T Memory2_X0 ;
real_T Memory6_X0 ; real_T Memory7_X0 ; real_T Memory3_X0 ; real_T Memory4_X0
; real_T Constant_Value ; real_T LPFq_NumCoef [ 2 ] ; real_T LPFq_DenCoef [ 2
] ; real_T LPFq_InitialStates ; real_T Central_Integral_Gain ; real_T
Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T
Distributed_integral_Gain ; real_T Integrator_IC ; real_T
Step_Time_lmjjonohpb ; real_T Step_Y0_c2n03dykfo ; real_T
Step_YFinal_eq3o4yb5hk ; real_T Constant_Value_pjdbxn5jaj ; real_T upi_Gain ;
real_T Gain_Gain ; real_T Integrator1_IC ; real_T Constant1_Value ; real_T
Gain2_Gain ; real_T Integrator2_IC ; real_T Gain4_Gain ; real_T Warrior_Gain
; real_T Memory5_X0 ; real_T Degenerated_Gain ; real_T
ttkernel_P1_Size_jf5opyvoys [ 2 ] ; real_T ttkernel_P1_hgc2x11pxe [ 16 ] ;
real_T ttkernel_P2_Size_izl4uhaorl [ 2 ] ; real_T ttkernel_P3_Size_i21pwe23fu
[ 2 ] ; real_T ttkernel_P3_gyvrxwxdcc [ 2 ] ; real_T
ttkernel_P4_Size_aiefmpkvfj [ 2 ] ; real_T ttkernel_P4_b1fsxhgcmm ; real_T
ttkernel_P5_Size_hkxbp1a0ew [ 2 ] ; real_T ttkernel_P5_atz4vzucgf ; real_T
ttkernel_P6_Size_al254xvutt [ 2 ] ; real_T ttkernel_P7_Size_oxdepfy1qh [ 2 ]
; real_T ttkernel_P7_mgfzte5zog [ 2 ] ; real_T Distributed_integral_w_Gain ;
real_T KSencondaryless1_Value ; real_T LPFp_NumCoef [ 2 ] ; real_T
LPFp_DenCoef [ 2 ] ; real_T LPFp_InitialStates ; real_T Energy_Value ; real_T
Energy_Value_m3cxrwlf3n ; real_T Gain1_Gain ; real_T Gain3_Gain ; real_T
Gain5_Gain ; real_T ttkernel_P1_Size_e1rhfzjrya [ 2 ] ; real_T
ttkernel_P1_nf24y5ukpk [ 11 ] ; real_T ttkernel_P2_Size_cdmxvlsmto [ 2 ] ;
real_T ttkernel_P2_iowo4vtmgf ; real_T ttkernel_P3_Size_iwd0slb2gf [ 2 ] ;
real_T ttkernel_P3_pofquplqop [ 2 ] ; real_T ttkernel_P4_Size_a5ktgh3yh5 [ 2
] ; real_T ttkernel_P4_o0rzzyjgke ; real_T ttkernel_P5_Size_jyfummcptc [ 2 ]
; real_T ttkernel_P5_cxsyobu4uc ; real_T ttkernel_P6_Size_k4rxbnl5wn [ 2 ] ;
real_T ttkernel_P6_g2k0wn1550 [ 2 ] ; real_T ttkernel_P7_Size_lbdowzzhsh [ 2
] ; real_T ttkernel_P7_m2hf5g32nl [ 2 ] ; real_T ttkernel_P1_Size_c3l52okdxq
[ 2 ] ; real_T ttkernel_P1_mhkdjijlpu [ 11 ] ; real_T
ttkernel_P2_Size_ixx5npjavz [ 2 ] ; real_T ttkernel_P2_d43ykjzw1c ; real_T
ttkernel_P3_Size_ft2nkbdsul [ 2 ] ; real_T ttkernel_P3_g3nhzkwume [ 2 ] ;
real_T ttkernel_P4_Size_cljt4zquq0 [ 2 ] ; real_T ttkernel_P4_gvxowrtqny ;
real_T ttkernel_P5_Size_cie0k5ev3b [ 2 ] ; real_T ttkernel_P5_ls3a3h0bic ;
real_T ttkernel_P6_Size_alm01kaiim [ 2 ] ; real_T ttkernel_P6_jhrdtikeht [ 2
] ; real_T ttkernel_P7_Size_eexnjryd5a [ 2 ] ; real_T ttkernel_P7_mw3xlp1bx5
[ 2 ] ; real_T ttkernel_P1_Size_f2220j5olj [ 2 ] ; real_T
ttkernel_P1_kt0v1ufv5r [ 11 ] ; real_T ttkernel_P2_Size_h5anevphuv [ 2 ] ;
real_T ttkernel_P2_kj2hzcd301 ; real_T ttkernel_P3_Size_e0ueiun5mg [ 2 ] ;
real_T ttkernel_P3_ngdcb3tjpv [ 2 ] ; real_T ttkernel_P4_Size_hn4jfjyypr [ 2
] ; real_T ttkernel_P4_e4ahzdw2kj ; real_T ttkernel_P5_Size_fsnsrejkzu [ 2 ]
; real_T ttkernel_P5_dpbgortnze ; real_T ttkernel_P6_Size_k0z5o1n5im [ 2 ] ;
real_T ttkernel_P6_bzayho3244 [ 2 ] ; real_T ttkernel_P7_Size_neskas0nfa [ 2
] ; real_T ttkernel_P7_ex30abk3ll [ 2 ] ; real_T Memory1_X0_jv5njtitnu ;
real_T Memory2_X0_oubqdo0i4e ; real_T Constant_Value_pjliw2x4cg ; real_T
LookUpTable1_tableData [ 4 ] ; real_T LookUpTable1_bp01Data [ 4 ] ; real_T
StateSpace_A [ 14 ] ; real_T StateSpace_B [ 20 ] ; real_T StateSpace_C [ 20 ]
; real_T StateSpace_D [ 4 ] ; real_T StateSpace_X0 [ 14 ] ; real_T
donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_lzvr4drqwu ;
real_T Memory1_X0_acajsjsekz ; real_T Memory2_X0_ajbdfeu2uy ; real_T
Memory6_X0_ofdizjjuud ; real_T Memory7_X0_gwiovv5pgj ; real_T
Memory3_X0_eu1l45nsjm ; real_T Memory4_X0_g1gmrklcwr ; real_T
Constant_Value_azz3yrvlmm ; real_T LPFq_NumCoef_dol51wazt2 [ 2 ] ; real_T
LPFq_DenCoef_jqztpz5qrm [ 2 ] ; real_T LPFq_InitialStates_lv2gugfrn2 ; real_T
Central_Integral_Gain_goqzg23ob0 ; real_T Step_Time_dq4ffjhuug ; real_T
Step_Y0_cang05wkqp ; real_T Step_YFinal_dwtygfsqzb ; real_T
Distributed_integral_Gain_lyaatikasw ; real_T Integrator_IC_itmwux0uj4 ;
real_T Step_Time_mv0kh4fqoa ; real_T Step_Y0_f5gzha2dmu ; real_T
Step_YFinal_nghuf4omva ; real_T Constant_Value_dj154fox1x ; real_T
upi_Gain_fugo0zwoc2 ; real_T Gain_Gain_hehylgfino ; real_T
Integrator1_IC_jmop5m2mq2 ; real_T Constant1_Value_jsqksnanjl ; real_T
Gain2_Gain_a1i5r3i1pq ; real_T Integrator2_IC_m1ypge3jrf ; real_T
Gain4_Gain_dk05bit35d ; real_T Warrior_Gain_l1vhyoa1db ; real_T
Memory5_X0_iqjkcc41vs ; real_T Degenerated_Gain_jajdw1laqg ; real_T
ttkernel_P1_Size_ffv5o0ejnq [ 2 ] ; real_T ttkernel_P1_kfgcryr1d3 [ 16 ] ;
real_T ttkernel_P2_Size_hnyoknt3zl [ 2 ] ; real_T ttkernel_P3_Size_n2dbq4lzwy
[ 2 ] ; real_T ttkernel_P3_pkdlfnv5aw [ 2 ] ; real_T
ttkernel_P4_Size_bvdbf2laou [ 2 ] ; real_T ttkernel_P4_kmp3ys5xhg ; real_T
ttkernel_P5_Size_dqgaqmlayd [ 2 ] ; real_T ttkernel_P5_hxtvczuseb ; real_T
ttkernel_P6_Size_eg2k0kqu0y [ 2 ] ; real_T ttkernel_P7_Size_o4e40mczhh [ 2 ]
; real_T ttkernel_P7_jijnurlig4 [ 2 ] ; real_T
Distributed_integral_w_Gain_byjpmxfo1z ; real_T
KSencondaryless1_Value_meu1czdosl ; real_T LPFp_NumCoef_ata2rzced3 [ 2 ] ;
real_T LPFp_DenCoef_nqtxjebx4f [ 2 ] ; real_T LPFp_InitialStates_cjbhvcuzaf ;
real_T Energy_Value_mbh2pufmpv ; real_T Energy_Value_eili3hnu3q ; real_T
Gain1_Gain_eeq10lnvsz ; real_T Gain3_Gain_nhcozfsh55 ; real_T
Gain5_Gain_jvhdnoddlf ; real_T donotdeletethisgain_Gain_pzf05cu4bk ; real_T
donotdeletethisgain_Gain_iiylrrlcdf ; real_T Memory1_X0_ihd3ji5ptm ; real_T
Memory2_X0_chrzl0gq2u ; real_T Memory6_X0_cpc5jg0si1 ; real_T
Memory7_X0_ofzzxrdwtc ; real_T Memory3_X0_jrojbqbxiv ; real_T
Memory4_X0_ammobeqm0v ; real_T Constant_Value_h1zp5rsdg2 ; real_T
LPFq_NumCoef_khkfqbsy5v [ 2 ] ; real_T LPFq_DenCoef_h5sk4b0cdt [ 2 ] ; real_T
LPFq_InitialStates_mct4zv33r2 ; real_T Central_Integral_Gain_oh2afxaxnl ;
real_T Step_Time_fjiuqwecd2 ; real_T Step_Y0_flbxmwe3gl ; real_T
Step_YFinal_mtlp5wwhqo ; real_T Distributed_integral_Gain_enwo1afavs ; real_T
Integrator_IC_ce2toqsgfm ; real_T Step_Time_lgtvrypfrs ; real_T
Step_Y0_ejizp1gvg5 ; real_T Step_YFinal_ebnn1geyqd ; real_T
Constant_Value_fmoydh5knb ; real_T upi_Gain_mdo2blrdce ; real_T
Gain_Gain_ktg4znma1i ; real_T Integrator1_IC_pyqrlbgsst ; real_T
Constant1_Value_oexbx2rf3m ; real_T Gain2_Gain_ftj3e0ljkf ; real_T
Integrator2_IC_buumrjnrb4 ; real_T Gain4_Gain_bati34bkvl ; real_T
Warrior_Gain_ndqbsjel4w ; real_T Memory5_X0_ly2u5imul2 ; real_T
Degenerated_Gain_bm5tyqy0ip ; real_T ttkernel_P1_Size_dwt5io1jt3 [ 2 ] ;
real_T ttkernel_P1_f05pazth3j [ 16 ] ; real_T ttkernel_P2_Size_lzb4fzavv1 [ 2
] ; real_T ttkernel_P3_Size_a3gr3qw5ix [ 2 ] ; real_T ttkernel_P3_fzfrnb3tsv
[ 2 ] ; real_T ttkernel_P4_Size_o0ydhdm4qv [ 2 ] ; real_T
ttkernel_P4_l40ha45sga ; real_T ttkernel_P5_Size_mffn13gx0r [ 2 ] ; real_T
ttkernel_P5_dy1kowyu20 ; real_T ttkernel_P6_Size_fbneyaga5q [ 2 ] ; real_T
ttkernel_P7_Size_ekne3o4qcs [ 2 ] ; real_T ttkernel_P7_dhbjkns50l [ 2 ] ;
real_T Distributed_integral_w_Gain_lpnz215ziz ; real_T
KSencondaryless1_Value_lregag3fon ; real_T LPFp_NumCoef_boqi1ajn5n [ 2 ] ;
real_T LPFp_DenCoef_g1xt3dr3a3 [ 2 ] ; real_T LPFp_InitialStates_ellhhmyoul ;
real_T Energy_Value_enxalamlm2 ; real_T Energy_Value_m3e32tg5wn ; real_T
Gain1_Gain_fcz13es3uk ; real_T Gain3_Gain_fapmoodk0o ; real_T
Gain5_Gain_niovj2naej ; real_T donotdeletethisgain_Gain_pjg3gyl4gj ; real_T
donotdeletethisgain_Gain_ek1zbpt0hi ; real_T Memory1_X0_lhnyvl10ey ; real_T
Memory2_X0_fhlqqz2zyl ; real_T Memory6_X0_mszfa5opgb ; real_T
Memory7_X0_n0v1puhk2a ; real_T Memory3_X0_poxy2k1s5q ; real_T
Memory4_X0_jv1vcihuqt ; real_T Constant_Value_hsvbbgfkro ; real_T
LPFq_NumCoef_cngm2kilnh [ 2 ] ; real_T LPFq_DenCoef_lsvgf4rl1a [ 2 ] ; real_T
LPFq_InitialStates_jxyjjfazjv ; real_T Central_Integral_Gain_bwkrokbusa ;
real_T Step_Time_mbvhgvqi3v ; real_T Step_Y0_k3hm1gr14s ; real_T
Step_YFinal_n4hnvye20z ; real_T Distributed_integral_Gain_d43k4wl3wl ; real_T
Integrator_IC_dgb0cuklt3 ; real_T Step_Time_h1zu3joaf1 ; real_T
Step_Y0_mvpspxbhia ; real_T Step_YFinal_h5xbk4nth0 ; real_T
Constant_Value_i5bvtvx522 ; real_T upi_Gain_hrt3gnzfl2 ; real_T
Gain_Gain_jty3lhxgcu ; real_T Integrator1_IC_etwibdpf3l ; real_T
Constant1_Value_ovbc5ioqzk ; real_T Gain2_Gain_asvcjlvedl ; real_T
Integrator2_IC_i4bblare5u ; real_T Gain4_Gain_jxbixtmknd ; real_T
Warrior_Gain_dguuaxnn54 ; real_T Memory5_X0_mzdqwrsacr ; real_T
Degenerated_Gain_p1y3cmfgyv ; real_T ttkernel_P1_Size_p20pgflkve [ 2 ] ;
real_T ttkernel_P1_jm2c0svanl [ 16 ] ; real_T ttkernel_P2_Size_gzkp3kxg33 [ 2
] ; real_T ttkernel_P3_Size_l2jji5uq1j [ 2 ] ; real_T ttkernel_P3_hhfssj3tq1
[ 2 ] ; real_T ttkernel_P4_Size_hnklzt0jw3 [ 2 ] ; real_T
ttkernel_P4_jsrxy3jgjq ; real_T ttkernel_P5_Size_fa3fkgeu1l [ 2 ] ; real_T
ttkernel_P5_c3yxs5yxnd ; real_T ttkernel_P6_Size_p3pprs52yg [ 2 ] ; real_T
ttkernel_P7_Size_frsmcrmh0u [ 2 ] ; real_T ttkernel_P7_bffw5cmzwn [ 2 ] ;
real_T Distributed_integral_w_Gain_jm5ojyhpid ; real_T
KSencondaryless1_Value_h2aqorl5nb ; real_T LPFp_NumCoef_oojfmq1khk [ 2 ] ;
real_T LPFp_DenCoef_oo54vuxlff [ 2 ] ; real_T LPFp_InitialStates_awo4cpuing ;
real_T Energy_Value_hjsumqx5yk ; real_T Energy_Value_bn3izespin ; real_T
Gain1_Gain_cjogxzntno ; real_T Gain3_Gain_fal1cwrksj ; real_T
Gain5_Gain_npwynuslmj ; real_T donotdeletethisgain_Gain_pqt51vmxbg ; real_T
donotdeletethisgain_Gain_iyrfn2wpbu ; real_T upi_Gain_gdts1vd3ud ; real_T
Constant_Value_jsxo0wpglc ; real_T Constant1_Value_eht0aia3xv ; real_T
Step_Time_cqeoamr4wm ; real_T Step_Y0_gycl0h21kq ; real_T
Step_YFinal_lf2hwitpjk ; real_T Gain1_Gain_edmc5opvxj ; real_T
Gain3_Gain_kcpjx312wz ; real_T Integrator_IC_hhogk15lld ; real_T
Integrator1_IC_jdydknk1ci ; real_T ttnetwork_P1_Size [ 2 ] ; real_T
ttnetwork_P1 ; real_T ttnetwork_P2_Size [ 2 ] ; real_T ttnetwork_P2 ; real_T
ttnetwork_P3_Size [ 2 ] ; real_T ttnetwork_P3 ; real_T ttnetwork_P4_Size [ 2
] ; real_T ttnetwork_P4 ; real_T ttnetwork_P5_Size [ 2 ] ; real_T
ttnetwork_P5 ; real_T ttnetwork_P6_Size [ 2 ] ; real_T ttnetwork_P6 ; real_T
ttnetwork_P7_Size [ 2 ] ; real_T ttnetwork_P7 [ 3 ] ; real_T
ttnetwork_P8_Size [ 2 ] ; real_T ttnetwork_P8 ; real_T ttnetwork_P9_Size [ 2
] ; real_T ttnetwork_P9 [ 4 ] ; real_T ttnetwork_P10_Size [ 2 ] ; real_T
ttnetwork_P10 ; real_T ttnetwork_P11_Size [ 2 ] ; real_T ttnetwork_P11 ;
real_T ttnetwork_P12_Size [ 2 ] ; real_T ttnetwork_P12 ; real_T
ttnetwork_P13_Size [ 2 ] ; real_T ttnetwork_P13 ; real_T ttnetwork_P14_Size [
2 ] ; real_T ttnetwork_P14 ; real_T ttnetwork_P15_Size [ 2 ] ; real_T
ttnetwork_P15 ; real_T ttnetwork_P16_Size [ 2 ] ; real_T ttnetwork_P16 ;
real_T ttnetwork_P17_Size [ 2 ] ; real_T ttnetwork_P17 ; real_T
ttnetwork_P18_Size [ 2 ] ; real_T ttnetwork_P18 ; real_T ttnetwork_P19_Size [
2 ] ; real_T ttnetwork_P19 ; real_T ttnetwork_P20_Size [ 2 ] ; real_T
ttnetwork_P20 ; real_T ttnetwork_P21_Size [ 2 ] ; real_T ttnetwork_P21 ;
real_T donotdeletethisgain_Gain_h35lkhvbav ; real_T
donotdeletethisgain_Gain_i04ou4rp5q ; real_T DataStoreMemory_InitialValue [ 4
] ; real_T DataStoreMemory1_InitialValue [ 4 ] ; real_T
DataStoreMemory2_InitialValue [ 4 ] ; real_T DataStoreMemory3_InitialValue [
4 ] ; real_T DataStoreMemory4_InitialValue [ 4 ] ; real_T
DataStoreMemory5_InitialValue [ 4 ] ; boolean_T KSencondaryless_Value ;
boolean_T KSencondaryless_Value_bmosygzxe0 ; boolean_T
KSencondaryless_Value_optmbdsthn ; boolean_T KSencondaryless_Value_oyco5fzk4w
; m5tur4wi4k ozftnlfeg3 ; ozv2axw2sw jrosma4ai4 ; ozv2axw2sw jlne01gbu0 ;
nbb0zpvvhm nybhsuuh1p ; ndkw5mnz3z b4zolxyidp ; ewvp3cxhdz pz2stfwruz ;
drnct5ly2o nlrcxogbog ; n1y0minqnv j20pq3r21f ; m5tur4wi4k avezulewcn ;
ozv2axw2sw k04lp2vsfm ; ozv2axw2sw p0jpb31wlq ; nbb0zpvvhm l1cumv5mxc ;
ndkw5mnz3z pcljl3fmii ; ewvp3cxhdz mmnlogmmqe ; drnct5ly2o ipvzgutla1 ;
n1y0minqnv dvrqjotubu ; m5tur4wi4k cwkcdvwsyb ; ozv2axw2sw gpr5ewbwvu ;
ozv2axw2sw pmll2wrcy3 ; nbb0zpvvhm omwjydko3j ; ndkw5mnz3z ejkqkpkoqg ;
ewvp3cxhdz pxgmr2o0yw ; drnct5ly2o mrc3jz2kzs ; n1y0minqnv jwxitznkuq ;
m5tur4wi4k a21clfzxwp ; ozv2axw2sw loojatj1b3 ; ozv2axw2sw ae0vvuvpaf ;
nbb0zpvvhm lkguggosm5 ; ndkw5mnz3z n3la5yge0s ; ewvp3cxhdz mfw2ixjjzd ;
drnct5ly2o i0nb5cbdli ; n1y0minqnv pxlv2lf0yq ; } ; extern P rtP ; extern
const real_T nodes4_RGND ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ;
extern const rtwCAPI_ModelMappingStaticInfo * nodes4_GetCAPIStaticMap ( void
) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
#endif
