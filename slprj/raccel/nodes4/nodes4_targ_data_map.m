  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 34;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 358;
      section.data(358)  = dumData; %prealloc
      
	  ;% rtP.array_num_generators
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.consensus_dr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.consensus_num_generators
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtP.consensus_ts
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.array_num_generators_gcbmamo1qo
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.consensus_dr_cs4dlsi3sq
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.consensus_num_generators_peuoomip1v
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtP.consensus_ts_c12jwpunuc
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% rtP.array_num_generators_kut4qav5bm
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% rtP.consensus_dr_hf31gowvrj
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% rtP.consensus_num_generators_pcvzfkxjm4
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% rtP.consensus_ts_phmvpsqftd
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% rtP.array_num_generators_fcv42ncmr5
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 21;
	
	  ;% rtP.consensus_dr_d4i4gfbgeo
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 22;
	
	  ;% rtP.consensus_num_generators_kutqmopsp2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% rtP.consensus_ts_buyezdbmmn
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% rtP.ttkernel_P1_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% rtP.ttkernel_P1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 30;
	
	  ;% rtP.ttkernel_P2_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 41;
	
	  ;% rtP.ttkernel_P2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 43;
	
	  ;% rtP.ttkernel_P3_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% rtP.ttkernel_P3
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 46;
	
	  ;% rtP.ttkernel_P4_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 48;
	
	  ;% rtP.ttkernel_P4
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 50;
	
	  ;% rtP.ttkernel_P5_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 51;
	
	  ;% rtP.ttkernel_P5
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 53;
	
	  ;% rtP.ttkernel_P6_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 54;
	
	  ;% rtP.ttkernel_P6
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 56;
	
	  ;% rtP.ttkernel_P7_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 58;
	
	  ;% rtP.ttkernel_P7
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 60;
	
	  ;% rtP.Memory1_X0
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 62;
	
	  ;% rtP.Memory2_X0
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 63;
	
	  ;% rtP.Memory6_X0
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 64;
	
	  ;% rtP.Memory7_X0
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 65;
	
	  ;% rtP.Memory3_X0
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 66;
	
	  ;% rtP.Memory4_X0
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 67;
	
	  ;% rtP.Constant_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 68;
	
	  ;% rtP.LPFq_NumCoef
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 69;
	
	  ;% rtP.LPFq_DenCoef
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 71;
	
	  ;% rtP.LPFq_InitialStates
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 73;
	
	  ;% rtP.Central_Integral_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 74;
	
	  ;% rtP.Step_Time
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 75;
	
	  ;% rtP.Step_Y0
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 76;
	
	  ;% rtP.Step_YFinal
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 77;
	
	  ;% rtP.Distributed_integral_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 78;
	
	  ;% rtP.Integrator_IC
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 79;
	
	  ;% rtP.Step_Time_lmjjonohpb
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 80;
	
	  ;% rtP.Step_Y0_c2n03dykfo
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 81;
	
	  ;% rtP.Step_YFinal_eq3o4yb5hk
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 82;
	
	  ;% rtP.Constant_Value_pjdbxn5jaj
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 83;
	
	  ;% rtP.upi_Gain
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 84;
	
	  ;% rtP.Gain_Gain
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 85;
	
	  ;% rtP.Integrator1_IC
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 86;
	
	  ;% rtP.Constant1_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 87;
	
	  ;% rtP.Gain2_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 88;
	
	  ;% rtP.Integrator2_IC
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 89;
	
	  ;% rtP.Gain4_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 90;
	
	  ;% rtP.Warrior_Gain
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 91;
	
	  ;% rtP.Memory5_X0
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 92;
	
	  ;% rtP.Degenerated_Gain
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 93;
	
	  ;% rtP.ttkernel_P1_Size_jf5opyvoys
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 94;
	
	  ;% rtP.ttkernel_P1_hgc2x11pxe
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 96;
	
	  ;% rtP.ttkernel_P2_Size_izl4uhaorl
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 112;
	
	  ;% rtP.ttkernel_P3_Size_i21pwe23fu
	  section.data(64).logicalSrcIdx = 64;
	  section.data(64).dtTransOffset = 114;
	
	  ;% rtP.ttkernel_P3_gyvrxwxdcc
	  section.data(65).logicalSrcIdx = 65;
	  section.data(65).dtTransOffset = 116;
	
	  ;% rtP.ttkernel_P4_Size_aiefmpkvfj
	  section.data(66).logicalSrcIdx = 66;
	  section.data(66).dtTransOffset = 118;
	
	  ;% rtP.ttkernel_P4_b1fsxhgcmm
	  section.data(67).logicalSrcIdx = 67;
	  section.data(67).dtTransOffset = 120;
	
	  ;% rtP.ttkernel_P5_Size_hkxbp1a0ew
	  section.data(68).logicalSrcIdx = 68;
	  section.data(68).dtTransOffset = 121;
	
	  ;% rtP.ttkernel_P5_atz4vzucgf
	  section.data(69).logicalSrcIdx = 69;
	  section.data(69).dtTransOffset = 123;
	
	  ;% rtP.ttkernel_P6_Size_al254xvutt
	  section.data(70).logicalSrcIdx = 70;
	  section.data(70).dtTransOffset = 124;
	
	  ;% rtP.ttkernel_P7_Size_oxdepfy1qh
	  section.data(71).logicalSrcIdx = 72;
	  section.data(71).dtTransOffset = 126;
	
	  ;% rtP.ttkernel_P7_mgfzte5zog
	  section.data(72).logicalSrcIdx = 73;
	  section.data(72).dtTransOffset = 128;
	
	  ;% rtP.Distributed_integral_w_Gain
	  section.data(73).logicalSrcIdx = 74;
	  section.data(73).dtTransOffset = 130;
	
	  ;% rtP.KSencondaryless1_Value
	  section.data(74).logicalSrcIdx = 75;
	  section.data(74).dtTransOffset = 131;
	
	  ;% rtP.LPFp_NumCoef
	  section.data(75).logicalSrcIdx = 76;
	  section.data(75).dtTransOffset = 132;
	
	  ;% rtP.LPFp_DenCoef
	  section.data(76).logicalSrcIdx = 77;
	  section.data(76).dtTransOffset = 134;
	
	  ;% rtP.LPFp_InitialStates
	  section.data(77).logicalSrcIdx = 78;
	  section.data(77).dtTransOffset = 136;
	
	  ;% rtP.Energy_Value
	  section.data(78).logicalSrcIdx = 79;
	  section.data(78).dtTransOffset = 137;
	
	  ;% rtP.Energy_Value_m3cxrwlf3n
	  section.data(79).logicalSrcIdx = 80;
	  section.data(79).dtTransOffset = 138;
	
	  ;% rtP.Gain1_Gain
	  section.data(80).logicalSrcIdx = 81;
	  section.data(80).dtTransOffset = 139;
	
	  ;% rtP.Gain3_Gain
	  section.data(81).logicalSrcIdx = 82;
	  section.data(81).dtTransOffset = 140;
	
	  ;% rtP.Gain5_Gain
	  section.data(82).logicalSrcIdx = 83;
	  section.data(82).dtTransOffset = 141;
	
	  ;% rtP.ttkernel_P1_Size_e1rhfzjrya
	  section.data(83).logicalSrcIdx = 84;
	  section.data(83).dtTransOffset = 142;
	
	  ;% rtP.ttkernel_P1_nf24y5ukpk
	  section.data(84).logicalSrcIdx = 85;
	  section.data(84).dtTransOffset = 144;
	
	  ;% rtP.ttkernel_P2_Size_cdmxvlsmto
	  section.data(85).logicalSrcIdx = 86;
	  section.data(85).dtTransOffset = 155;
	
	  ;% rtP.ttkernel_P2_iowo4vtmgf
	  section.data(86).logicalSrcIdx = 87;
	  section.data(86).dtTransOffset = 157;
	
	  ;% rtP.ttkernel_P3_Size_iwd0slb2gf
	  section.data(87).logicalSrcIdx = 88;
	  section.data(87).dtTransOffset = 158;
	
	  ;% rtP.ttkernel_P3_pofquplqop
	  section.data(88).logicalSrcIdx = 89;
	  section.data(88).dtTransOffset = 160;
	
	  ;% rtP.ttkernel_P4_Size_a5ktgh3yh5
	  section.data(89).logicalSrcIdx = 90;
	  section.data(89).dtTransOffset = 162;
	
	  ;% rtP.ttkernel_P4_o0rzzyjgke
	  section.data(90).logicalSrcIdx = 91;
	  section.data(90).dtTransOffset = 164;
	
	  ;% rtP.ttkernel_P5_Size_jyfummcptc
	  section.data(91).logicalSrcIdx = 92;
	  section.data(91).dtTransOffset = 165;
	
	  ;% rtP.ttkernel_P5_cxsyobu4uc
	  section.data(92).logicalSrcIdx = 93;
	  section.data(92).dtTransOffset = 167;
	
	  ;% rtP.ttkernel_P6_Size_k4rxbnl5wn
	  section.data(93).logicalSrcIdx = 94;
	  section.data(93).dtTransOffset = 168;
	
	  ;% rtP.ttkernel_P6_g2k0wn1550
	  section.data(94).logicalSrcIdx = 95;
	  section.data(94).dtTransOffset = 170;
	
	  ;% rtP.ttkernel_P7_Size_lbdowzzhsh
	  section.data(95).logicalSrcIdx = 96;
	  section.data(95).dtTransOffset = 172;
	
	  ;% rtP.ttkernel_P7_m2hf5g32nl
	  section.data(96).logicalSrcIdx = 97;
	  section.data(96).dtTransOffset = 174;
	
	  ;% rtP.ttkernel_P1_Size_c3l52okdxq
	  section.data(97).logicalSrcIdx = 98;
	  section.data(97).dtTransOffset = 176;
	
	  ;% rtP.ttkernel_P1_mhkdjijlpu
	  section.data(98).logicalSrcIdx = 99;
	  section.data(98).dtTransOffset = 178;
	
	  ;% rtP.ttkernel_P2_Size_ixx5npjavz
	  section.data(99).logicalSrcIdx = 100;
	  section.data(99).dtTransOffset = 189;
	
	  ;% rtP.ttkernel_P2_d43ykjzw1c
	  section.data(100).logicalSrcIdx = 101;
	  section.data(100).dtTransOffset = 191;
	
	  ;% rtP.ttkernel_P3_Size_ft2nkbdsul
	  section.data(101).logicalSrcIdx = 102;
	  section.data(101).dtTransOffset = 192;
	
	  ;% rtP.ttkernel_P3_g3nhzkwume
	  section.data(102).logicalSrcIdx = 103;
	  section.data(102).dtTransOffset = 194;
	
	  ;% rtP.ttkernel_P4_Size_cljt4zquq0
	  section.data(103).logicalSrcIdx = 104;
	  section.data(103).dtTransOffset = 196;
	
	  ;% rtP.ttkernel_P4_gvxowrtqny
	  section.data(104).logicalSrcIdx = 105;
	  section.data(104).dtTransOffset = 198;
	
	  ;% rtP.ttkernel_P5_Size_cie0k5ev3b
	  section.data(105).logicalSrcIdx = 106;
	  section.data(105).dtTransOffset = 199;
	
	  ;% rtP.ttkernel_P5_ls3a3h0bic
	  section.data(106).logicalSrcIdx = 107;
	  section.data(106).dtTransOffset = 201;
	
	  ;% rtP.ttkernel_P6_Size_alm01kaiim
	  section.data(107).logicalSrcIdx = 108;
	  section.data(107).dtTransOffset = 202;
	
	  ;% rtP.ttkernel_P6_jhrdtikeht
	  section.data(108).logicalSrcIdx = 109;
	  section.data(108).dtTransOffset = 204;
	
	  ;% rtP.ttkernel_P7_Size_eexnjryd5a
	  section.data(109).logicalSrcIdx = 110;
	  section.data(109).dtTransOffset = 206;
	
	  ;% rtP.ttkernel_P7_mw3xlp1bx5
	  section.data(110).logicalSrcIdx = 111;
	  section.data(110).dtTransOffset = 208;
	
	  ;% rtP.ttkernel_P1_Size_f2220j5olj
	  section.data(111).logicalSrcIdx = 112;
	  section.data(111).dtTransOffset = 210;
	
	  ;% rtP.ttkernel_P1_kt0v1ufv5r
	  section.data(112).logicalSrcIdx = 113;
	  section.data(112).dtTransOffset = 212;
	
	  ;% rtP.ttkernel_P2_Size_h5anevphuv
	  section.data(113).logicalSrcIdx = 114;
	  section.data(113).dtTransOffset = 223;
	
	  ;% rtP.ttkernel_P2_kj2hzcd301
	  section.data(114).logicalSrcIdx = 115;
	  section.data(114).dtTransOffset = 225;
	
	  ;% rtP.ttkernel_P3_Size_e0ueiun5mg
	  section.data(115).logicalSrcIdx = 116;
	  section.data(115).dtTransOffset = 226;
	
	  ;% rtP.ttkernel_P3_ngdcb3tjpv
	  section.data(116).logicalSrcIdx = 117;
	  section.data(116).dtTransOffset = 228;
	
	  ;% rtP.ttkernel_P4_Size_hn4jfjyypr
	  section.data(117).logicalSrcIdx = 118;
	  section.data(117).dtTransOffset = 230;
	
	  ;% rtP.ttkernel_P4_e4ahzdw2kj
	  section.data(118).logicalSrcIdx = 119;
	  section.data(118).dtTransOffset = 232;
	
	  ;% rtP.ttkernel_P5_Size_fsnsrejkzu
	  section.data(119).logicalSrcIdx = 120;
	  section.data(119).dtTransOffset = 233;
	
	  ;% rtP.ttkernel_P5_dpbgortnze
	  section.data(120).logicalSrcIdx = 121;
	  section.data(120).dtTransOffset = 235;
	
	  ;% rtP.ttkernel_P6_Size_k0z5o1n5im
	  section.data(121).logicalSrcIdx = 122;
	  section.data(121).dtTransOffset = 236;
	
	  ;% rtP.ttkernel_P6_bzayho3244
	  section.data(122).logicalSrcIdx = 123;
	  section.data(122).dtTransOffset = 238;
	
	  ;% rtP.ttkernel_P7_Size_neskas0nfa
	  section.data(123).logicalSrcIdx = 124;
	  section.data(123).dtTransOffset = 240;
	
	  ;% rtP.ttkernel_P7_ex30abk3ll
	  section.data(124).logicalSrcIdx = 125;
	  section.data(124).dtTransOffset = 242;
	
	  ;% rtP.Memory1_X0_jv5njtitnu
	  section.data(125).logicalSrcIdx = 126;
	  section.data(125).dtTransOffset = 244;
	
	  ;% rtP.Memory2_X0_oubqdo0i4e
	  section.data(126).logicalSrcIdx = 127;
	  section.data(126).dtTransOffset = 245;
	
	  ;% rtP.Constant_Value_pjliw2x4cg
	  section.data(127).logicalSrcIdx = 128;
	  section.data(127).dtTransOffset = 246;
	
	  ;% rtP.LookUpTable1_tableData
	  section.data(128).logicalSrcIdx = 129;
	  section.data(128).dtTransOffset = 247;
	
	  ;% rtP.LookUpTable1_bp01Data
	  section.data(129).logicalSrcIdx = 130;
	  section.data(129).dtTransOffset = 251;
	
	  ;% rtP.StateSpace_A
	  section.data(130).logicalSrcIdx = 131;
	  section.data(130).dtTransOffset = 255;
	
	  ;% rtP.StateSpace_B
	  section.data(131).logicalSrcIdx = 132;
	  section.data(131).dtTransOffset = 269;
	
	  ;% rtP.StateSpace_C
	  section.data(132).logicalSrcIdx = 133;
	  section.data(132).dtTransOffset = 289;
	
	  ;% rtP.StateSpace_D
	  section.data(133).logicalSrcIdx = 134;
	  section.data(133).dtTransOffset = 309;
	
	  ;% rtP.StateSpace_X0
	  section.data(134).logicalSrcIdx = 135;
	  section.data(134).dtTransOffset = 313;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(135).logicalSrcIdx = 136;
	  section.data(135).dtTransOffset = 327;
	
	  ;% rtP.donotdeletethisgain_Gain_lzvr4drqwu
	  section.data(136).logicalSrcIdx = 137;
	  section.data(136).dtTransOffset = 328;
	
	  ;% rtP.Memory1_X0_acajsjsekz
	  section.data(137).logicalSrcIdx = 138;
	  section.data(137).dtTransOffset = 329;
	
	  ;% rtP.Memory2_X0_ajbdfeu2uy
	  section.data(138).logicalSrcIdx = 139;
	  section.data(138).dtTransOffset = 330;
	
	  ;% rtP.Memory6_X0_ofdizjjuud
	  section.data(139).logicalSrcIdx = 140;
	  section.data(139).dtTransOffset = 331;
	
	  ;% rtP.Memory7_X0_gwiovv5pgj
	  section.data(140).logicalSrcIdx = 141;
	  section.data(140).dtTransOffset = 332;
	
	  ;% rtP.Memory3_X0_eu1l45nsjm
	  section.data(141).logicalSrcIdx = 142;
	  section.data(141).dtTransOffset = 333;
	
	  ;% rtP.Memory4_X0_g1gmrklcwr
	  section.data(142).logicalSrcIdx = 143;
	  section.data(142).dtTransOffset = 334;
	
	  ;% rtP.Constant_Value_azz3yrvlmm
	  section.data(143).logicalSrcIdx = 144;
	  section.data(143).dtTransOffset = 335;
	
	  ;% rtP.LPFq_NumCoef_dol51wazt2
	  section.data(144).logicalSrcIdx = 145;
	  section.data(144).dtTransOffset = 336;
	
	  ;% rtP.LPFq_DenCoef_jqztpz5qrm
	  section.data(145).logicalSrcIdx = 146;
	  section.data(145).dtTransOffset = 338;
	
	  ;% rtP.LPFq_InitialStates_lv2gugfrn2
	  section.data(146).logicalSrcIdx = 147;
	  section.data(146).dtTransOffset = 340;
	
	  ;% rtP.Central_Integral_Gain_goqzg23ob0
	  section.data(147).logicalSrcIdx = 148;
	  section.data(147).dtTransOffset = 341;
	
	  ;% rtP.Step_Time_dq4ffjhuug
	  section.data(148).logicalSrcIdx = 149;
	  section.data(148).dtTransOffset = 342;
	
	  ;% rtP.Step_Y0_cang05wkqp
	  section.data(149).logicalSrcIdx = 150;
	  section.data(149).dtTransOffset = 343;
	
	  ;% rtP.Step_YFinal_dwtygfsqzb
	  section.data(150).logicalSrcIdx = 151;
	  section.data(150).dtTransOffset = 344;
	
	  ;% rtP.Distributed_integral_Gain_lyaatikasw
	  section.data(151).logicalSrcIdx = 152;
	  section.data(151).dtTransOffset = 345;
	
	  ;% rtP.Integrator_IC_itmwux0uj4
	  section.data(152).logicalSrcIdx = 153;
	  section.data(152).dtTransOffset = 346;
	
	  ;% rtP.Step_Time_mv0kh4fqoa
	  section.data(153).logicalSrcIdx = 154;
	  section.data(153).dtTransOffset = 347;
	
	  ;% rtP.Step_Y0_f5gzha2dmu
	  section.data(154).logicalSrcIdx = 155;
	  section.data(154).dtTransOffset = 348;
	
	  ;% rtP.Step_YFinal_nghuf4omva
	  section.data(155).logicalSrcIdx = 156;
	  section.data(155).dtTransOffset = 349;
	
	  ;% rtP.Constant_Value_dj154fox1x
	  section.data(156).logicalSrcIdx = 157;
	  section.data(156).dtTransOffset = 350;
	
	  ;% rtP.upi_Gain_fugo0zwoc2
	  section.data(157).logicalSrcIdx = 158;
	  section.data(157).dtTransOffset = 351;
	
	  ;% rtP.Gain_Gain_hehylgfino
	  section.data(158).logicalSrcIdx = 159;
	  section.data(158).dtTransOffset = 352;
	
	  ;% rtP.Integrator1_IC_jmop5m2mq2
	  section.data(159).logicalSrcIdx = 160;
	  section.data(159).dtTransOffset = 353;
	
	  ;% rtP.Constant1_Value_jsqksnanjl
	  section.data(160).logicalSrcIdx = 161;
	  section.data(160).dtTransOffset = 354;
	
	  ;% rtP.Gain2_Gain_a1i5r3i1pq
	  section.data(161).logicalSrcIdx = 162;
	  section.data(161).dtTransOffset = 355;
	
	  ;% rtP.Integrator2_IC_m1ypge3jrf
	  section.data(162).logicalSrcIdx = 163;
	  section.data(162).dtTransOffset = 356;
	
	  ;% rtP.Gain4_Gain_dk05bit35d
	  section.data(163).logicalSrcIdx = 164;
	  section.data(163).dtTransOffset = 357;
	
	  ;% rtP.Warrior_Gain_l1vhyoa1db
	  section.data(164).logicalSrcIdx = 165;
	  section.data(164).dtTransOffset = 358;
	
	  ;% rtP.Memory5_X0_iqjkcc41vs
	  section.data(165).logicalSrcIdx = 166;
	  section.data(165).dtTransOffset = 359;
	
	  ;% rtP.Degenerated_Gain_jajdw1laqg
	  section.data(166).logicalSrcIdx = 167;
	  section.data(166).dtTransOffset = 360;
	
	  ;% rtP.ttkernel_P1_Size_ffv5o0ejnq
	  section.data(167).logicalSrcIdx = 168;
	  section.data(167).dtTransOffset = 361;
	
	  ;% rtP.ttkernel_P1_kfgcryr1d3
	  section.data(168).logicalSrcIdx = 169;
	  section.data(168).dtTransOffset = 363;
	
	  ;% rtP.ttkernel_P2_Size_hnyoknt3zl
	  section.data(169).logicalSrcIdx = 170;
	  section.data(169).dtTransOffset = 379;
	
	  ;% rtP.ttkernel_P3_Size_n2dbq4lzwy
	  section.data(170).logicalSrcIdx = 172;
	  section.data(170).dtTransOffset = 381;
	
	  ;% rtP.ttkernel_P3_pkdlfnv5aw
	  section.data(171).logicalSrcIdx = 173;
	  section.data(171).dtTransOffset = 383;
	
	  ;% rtP.ttkernel_P4_Size_bvdbf2laou
	  section.data(172).logicalSrcIdx = 174;
	  section.data(172).dtTransOffset = 385;
	
	  ;% rtP.ttkernel_P4_kmp3ys5xhg
	  section.data(173).logicalSrcIdx = 175;
	  section.data(173).dtTransOffset = 387;
	
	  ;% rtP.ttkernel_P5_Size_dqgaqmlayd
	  section.data(174).logicalSrcIdx = 176;
	  section.data(174).dtTransOffset = 388;
	
	  ;% rtP.ttkernel_P5_hxtvczuseb
	  section.data(175).logicalSrcIdx = 177;
	  section.data(175).dtTransOffset = 390;
	
	  ;% rtP.ttkernel_P6_Size_eg2k0kqu0y
	  section.data(176).logicalSrcIdx = 178;
	  section.data(176).dtTransOffset = 391;
	
	  ;% rtP.ttkernel_P7_Size_o4e40mczhh
	  section.data(177).logicalSrcIdx = 180;
	  section.data(177).dtTransOffset = 393;
	
	  ;% rtP.ttkernel_P7_jijnurlig4
	  section.data(178).logicalSrcIdx = 181;
	  section.data(178).dtTransOffset = 395;
	
	  ;% rtP.Distributed_integral_w_Gain_byjpmxfo1z
	  section.data(179).logicalSrcIdx = 182;
	  section.data(179).dtTransOffset = 397;
	
	  ;% rtP.KSencondaryless1_Value_meu1czdosl
	  section.data(180).logicalSrcIdx = 183;
	  section.data(180).dtTransOffset = 398;
	
	  ;% rtP.LPFp_NumCoef_ata2rzced3
	  section.data(181).logicalSrcIdx = 184;
	  section.data(181).dtTransOffset = 399;
	
	  ;% rtP.LPFp_DenCoef_nqtxjebx4f
	  section.data(182).logicalSrcIdx = 185;
	  section.data(182).dtTransOffset = 401;
	
	  ;% rtP.LPFp_InitialStates_cjbhvcuzaf
	  section.data(183).logicalSrcIdx = 186;
	  section.data(183).dtTransOffset = 403;
	
	  ;% rtP.Energy_Value_mbh2pufmpv
	  section.data(184).logicalSrcIdx = 187;
	  section.data(184).dtTransOffset = 404;
	
	  ;% rtP.Energy_Value_eili3hnu3q
	  section.data(185).logicalSrcIdx = 188;
	  section.data(185).dtTransOffset = 405;
	
	  ;% rtP.Gain1_Gain_eeq10lnvsz
	  section.data(186).logicalSrcIdx = 189;
	  section.data(186).dtTransOffset = 406;
	
	  ;% rtP.Gain3_Gain_nhcozfsh55
	  section.data(187).logicalSrcIdx = 190;
	  section.data(187).dtTransOffset = 407;
	
	  ;% rtP.Gain5_Gain_jvhdnoddlf
	  section.data(188).logicalSrcIdx = 191;
	  section.data(188).dtTransOffset = 408;
	
	  ;% rtP.donotdeletethisgain_Gain_pzf05cu4bk
	  section.data(189).logicalSrcIdx = 192;
	  section.data(189).dtTransOffset = 409;
	
	  ;% rtP.donotdeletethisgain_Gain_iiylrrlcdf
	  section.data(190).logicalSrcIdx = 193;
	  section.data(190).dtTransOffset = 410;
	
	  ;% rtP.Memory1_X0_ihd3ji5ptm
	  section.data(191).logicalSrcIdx = 194;
	  section.data(191).dtTransOffset = 411;
	
	  ;% rtP.Memory2_X0_chrzl0gq2u
	  section.data(192).logicalSrcIdx = 195;
	  section.data(192).dtTransOffset = 412;
	
	  ;% rtP.Memory6_X0_cpc5jg0si1
	  section.data(193).logicalSrcIdx = 196;
	  section.data(193).dtTransOffset = 413;
	
	  ;% rtP.Memory7_X0_ofzzxrdwtc
	  section.data(194).logicalSrcIdx = 197;
	  section.data(194).dtTransOffset = 414;
	
	  ;% rtP.Memory3_X0_jrojbqbxiv
	  section.data(195).logicalSrcIdx = 198;
	  section.data(195).dtTransOffset = 415;
	
	  ;% rtP.Memory4_X0_ammobeqm0v
	  section.data(196).logicalSrcIdx = 199;
	  section.data(196).dtTransOffset = 416;
	
	  ;% rtP.Constant_Value_h1zp5rsdg2
	  section.data(197).logicalSrcIdx = 200;
	  section.data(197).dtTransOffset = 417;
	
	  ;% rtP.LPFq_NumCoef_khkfqbsy5v
	  section.data(198).logicalSrcIdx = 201;
	  section.data(198).dtTransOffset = 418;
	
	  ;% rtP.LPFq_DenCoef_h5sk4b0cdt
	  section.data(199).logicalSrcIdx = 202;
	  section.data(199).dtTransOffset = 420;
	
	  ;% rtP.LPFq_InitialStates_mct4zv33r2
	  section.data(200).logicalSrcIdx = 203;
	  section.data(200).dtTransOffset = 422;
	
	  ;% rtP.Central_Integral_Gain_oh2afxaxnl
	  section.data(201).logicalSrcIdx = 204;
	  section.data(201).dtTransOffset = 423;
	
	  ;% rtP.Step_Time_fjiuqwecd2
	  section.data(202).logicalSrcIdx = 205;
	  section.data(202).dtTransOffset = 424;
	
	  ;% rtP.Step_Y0_flbxmwe3gl
	  section.data(203).logicalSrcIdx = 206;
	  section.data(203).dtTransOffset = 425;
	
	  ;% rtP.Step_YFinal_mtlp5wwhqo
	  section.data(204).logicalSrcIdx = 207;
	  section.data(204).dtTransOffset = 426;
	
	  ;% rtP.Distributed_integral_Gain_enwo1afavs
	  section.data(205).logicalSrcIdx = 208;
	  section.data(205).dtTransOffset = 427;
	
	  ;% rtP.Integrator_IC_ce2toqsgfm
	  section.data(206).logicalSrcIdx = 209;
	  section.data(206).dtTransOffset = 428;
	
	  ;% rtP.Step_Time_lgtvrypfrs
	  section.data(207).logicalSrcIdx = 210;
	  section.data(207).dtTransOffset = 429;
	
	  ;% rtP.Step_Y0_ejizp1gvg5
	  section.data(208).logicalSrcIdx = 211;
	  section.data(208).dtTransOffset = 430;
	
	  ;% rtP.Step_YFinal_ebnn1geyqd
	  section.data(209).logicalSrcIdx = 212;
	  section.data(209).dtTransOffset = 431;
	
	  ;% rtP.Constant_Value_fmoydh5knb
	  section.data(210).logicalSrcIdx = 213;
	  section.data(210).dtTransOffset = 432;
	
	  ;% rtP.upi_Gain_mdo2blrdce
	  section.data(211).logicalSrcIdx = 214;
	  section.data(211).dtTransOffset = 433;
	
	  ;% rtP.Gain_Gain_ktg4znma1i
	  section.data(212).logicalSrcIdx = 215;
	  section.data(212).dtTransOffset = 434;
	
	  ;% rtP.Integrator1_IC_pyqrlbgsst
	  section.data(213).logicalSrcIdx = 216;
	  section.data(213).dtTransOffset = 435;
	
	  ;% rtP.Constant1_Value_oexbx2rf3m
	  section.data(214).logicalSrcIdx = 217;
	  section.data(214).dtTransOffset = 436;
	
	  ;% rtP.Gain2_Gain_ftj3e0ljkf
	  section.data(215).logicalSrcIdx = 218;
	  section.data(215).dtTransOffset = 437;
	
	  ;% rtP.Integrator2_IC_buumrjnrb4
	  section.data(216).logicalSrcIdx = 219;
	  section.data(216).dtTransOffset = 438;
	
	  ;% rtP.Gain4_Gain_bati34bkvl
	  section.data(217).logicalSrcIdx = 220;
	  section.data(217).dtTransOffset = 439;
	
	  ;% rtP.Warrior_Gain_ndqbsjel4w
	  section.data(218).logicalSrcIdx = 221;
	  section.data(218).dtTransOffset = 440;
	
	  ;% rtP.Memory5_X0_ly2u5imul2
	  section.data(219).logicalSrcIdx = 222;
	  section.data(219).dtTransOffset = 441;
	
	  ;% rtP.Degenerated_Gain_bm5tyqy0ip
	  section.data(220).logicalSrcIdx = 223;
	  section.data(220).dtTransOffset = 442;
	
	  ;% rtP.ttkernel_P1_Size_dwt5io1jt3
	  section.data(221).logicalSrcIdx = 224;
	  section.data(221).dtTransOffset = 443;
	
	  ;% rtP.ttkernel_P1_f05pazth3j
	  section.data(222).logicalSrcIdx = 225;
	  section.data(222).dtTransOffset = 445;
	
	  ;% rtP.ttkernel_P2_Size_lzb4fzavv1
	  section.data(223).logicalSrcIdx = 226;
	  section.data(223).dtTransOffset = 461;
	
	  ;% rtP.ttkernel_P3_Size_a3gr3qw5ix
	  section.data(224).logicalSrcIdx = 228;
	  section.data(224).dtTransOffset = 463;
	
	  ;% rtP.ttkernel_P3_fzfrnb3tsv
	  section.data(225).logicalSrcIdx = 229;
	  section.data(225).dtTransOffset = 465;
	
	  ;% rtP.ttkernel_P4_Size_o0ydhdm4qv
	  section.data(226).logicalSrcIdx = 230;
	  section.data(226).dtTransOffset = 467;
	
	  ;% rtP.ttkernel_P4_l40ha45sga
	  section.data(227).logicalSrcIdx = 231;
	  section.data(227).dtTransOffset = 469;
	
	  ;% rtP.ttkernel_P5_Size_mffn13gx0r
	  section.data(228).logicalSrcIdx = 232;
	  section.data(228).dtTransOffset = 470;
	
	  ;% rtP.ttkernel_P5_dy1kowyu20
	  section.data(229).logicalSrcIdx = 233;
	  section.data(229).dtTransOffset = 472;
	
	  ;% rtP.ttkernel_P6_Size_fbneyaga5q
	  section.data(230).logicalSrcIdx = 234;
	  section.data(230).dtTransOffset = 473;
	
	  ;% rtP.ttkernel_P7_Size_ekne3o4qcs
	  section.data(231).logicalSrcIdx = 236;
	  section.data(231).dtTransOffset = 475;
	
	  ;% rtP.ttkernel_P7_dhbjkns50l
	  section.data(232).logicalSrcIdx = 237;
	  section.data(232).dtTransOffset = 477;
	
	  ;% rtP.Distributed_integral_w_Gain_lpnz215ziz
	  section.data(233).logicalSrcIdx = 238;
	  section.data(233).dtTransOffset = 479;
	
	  ;% rtP.KSencondaryless1_Value_lregag3fon
	  section.data(234).logicalSrcIdx = 239;
	  section.data(234).dtTransOffset = 480;
	
	  ;% rtP.LPFp_NumCoef_boqi1ajn5n
	  section.data(235).logicalSrcIdx = 240;
	  section.data(235).dtTransOffset = 481;
	
	  ;% rtP.LPFp_DenCoef_g1xt3dr3a3
	  section.data(236).logicalSrcIdx = 241;
	  section.data(236).dtTransOffset = 483;
	
	  ;% rtP.LPFp_InitialStates_ellhhmyoul
	  section.data(237).logicalSrcIdx = 242;
	  section.data(237).dtTransOffset = 485;
	
	  ;% rtP.Energy_Value_enxalamlm2
	  section.data(238).logicalSrcIdx = 243;
	  section.data(238).dtTransOffset = 486;
	
	  ;% rtP.Energy_Value_m3e32tg5wn
	  section.data(239).logicalSrcIdx = 244;
	  section.data(239).dtTransOffset = 487;
	
	  ;% rtP.Gain1_Gain_fcz13es3uk
	  section.data(240).logicalSrcIdx = 245;
	  section.data(240).dtTransOffset = 488;
	
	  ;% rtP.Gain3_Gain_fapmoodk0o
	  section.data(241).logicalSrcIdx = 246;
	  section.data(241).dtTransOffset = 489;
	
	  ;% rtP.Gain5_Gain_niovj2naej
	  section.data(242).logicalSrcIdx = 247;
	  section.data(242).dtTransOffset = 490;
	
	  ;% rtP.donotdeletethisgain_Gain_pjg3gyl4gj
	  section.data(243).logicalSrcIdx = 248;
	  section.data(243).dtTransOffset = 491;
	
	  ;% rtP.donotdeletethisgain_Gain_ek1zbpt0hi
	  section.data(244).logicalSrcIdx = 249;
	  section.data(244).dtTransOffset = 492;
	
	  ;% rtP.Memory1_X0_lhnyvl10ey
	  section.data(245).logicalSrcIdx = 250;
	  section.data(245).dtTransOffset = 493;
	
	  ;% rtP.Memory2_X0_fhlqqz2zyl
	  section.data(246).logicalSrcIdx = 251;
	  section.data(246).dtTransOffset = 494;
	
	  ;% rtP.Memory6_X0_mszfa5opgb
	  section.data(247).logicalSrcIdx = 252;
	  section.data(247).dtTransOffset = 495;
	
	  ;% rtP.Memory7_X0_n0v1puhk2a
	  section.data(248).logicalSrcIdx = 253;
	  section.data(248).dtTransOffset = 496;
	
	  ;% rtP.Memory3_X0_poxy2k1s5q
	  section.data(249).logicalSrcIdx = 254;
	  section.data(249).dtTransOffset = 497;
	
	  ;% rtP.Memory4_X0_jv1vcihuqt
	  section.data(250).logicalSrcIdx = 255;
	  section.data(250).dtTransOffset = 498;
	
	  ;% rtP.Constant_Value_hsvbbgfkro
	  section.data(251).logicalSrcIdx = 256;
	  section.data(251).dtTransOffset = 499;
	
	  ;% rtP.LPFq_NumCoef_cngm2kilnh
	  section.data(252).logicalSrcIdx = 257;
	  section.data(252).dtTransOffset = 500;
	
	  ;% rtP.LPFq_DenCoef_lsvgf4rl1a
	  section.data(253).logicalSrcIdx = 258;
	  section.data(253).dtTransOffset = 502;
	
	  ;% rtP.LPFq_InitialStates_jxyjjfazjv
	  section.data(254).logicalSrcIdx = 259;
	  section.data(254).dtTransOffset = 504;
	
	  ;% rtP.Central_Integral_Gain_bwkrokbusa
	  section.data(255).logicalSrcIdx = 260;
	  section.data(255).dtTransOffset = 505;
	
	  ;% rtP.Step_Time_mbvhgvqi3v
	  section.data(256).logicalSrcIdx = 261;
	  section.data(256).dtTransOffset = 506;
	
	  ;% rtP.Step_Y0_k3hm1gr14s
	  section.data(257).logicalSrcIdx = 262;
	  section.data(257).dtTransOffset = 507;
	
	  ;% rtP.Step_YFinal_n4hnvye20z
	  section.data(258).logicalSrcIdx = 263;
	  section.data(258).dtTransOffset = 508;
	
	  ;% rtP.Distributed_integral_Gain_d43k4wl3wl
	  section.data(259).logicalSrcIdx = 264;
	  section.data(259).dtTransOffset = 509;
	
	  ;% rtP.Integrator_IC_dgb0cuklt3
	  section.data(260).logicalSrcIdx = 265;
	  section.data(260).dtTransOffset = 510;
	
	  ;% rtP.Step_Time_h1zu3joaf1
	  section.data(261).logicalSrcIdx = 266;
	  section.data(261).dtTransOffset = 511;
	
	  ;% rtP.Step_Y0_mvpspxbhia
	  section.data(262).logicalSrcIdx = 267;
	  section.data(262).dtTransOffset = 512;
	
	  ;% rtP.Step_YFinal_h5xbk4nth0
	  section.data(263).logicalSrcIdx = 268;
	  section.data(263).dtTransOffset = 513;
	
	  ;% rtP.Constant_Value_i5bvtvx522
	  section.data(264).logicalSrcIdx = 269;
	  section.data(264).dtTransOffset = 514;
	
	  ;% rtP.upi_Gain_hrt3gnzfl2
	  section.data(265).logicalSrcIdx = 270;
	  section.data(265).dtTransOffset = 515;
	
	  ;% rtP.Gain_Gain_jty3lhxgcu
	  section.data(266).logicalSrcIdx = 271;
	  section.data(266).dtTransOffset = 516;
	
	  ;% rtP.Integrator1_IC_etwibdpf3l
	  section.data(267).logicalSrcIdx = 272;
	  section.data(267).dtTransOffset = 517;
	
	  ;% rtP.Constant1_Value_ovbc5ioqzk
	  section.data(268).logicalSrcIdx = 273;
	  section.data(268).dtTransOffset = 518;
	
	  ;% rtP.Gain2_Gain_asvcjlvedl
	  section.data(269).logicalSrcIdx = 274;
	  section.data(269).dtTransOffset = 519;
	
	  ;% rtP.Integrator2_IC_i4bblare5u
	  section.data(270).logicalSrcIdx = 275;
	  section.data(270).dtTransOffset = 520;
	
	  ;% rtP.Gain4_Gain_jxbixtmknd
	  section.data(271).logicalSrcIdx = 276;
	  section.data(271).dtTransOffset = 521;
	
	  ;% rtP.Warrior_Gain_dguuaxnn54
	  section.data(272).logicalSrcIdx = 277;
	  section.data(272).dtTransOffset = 522;
	
	  ;% rtP.Memory5_X0_mzdqwrsacr
	  section.data(273).logicalSrcIdx = 278;
	  section.data(273).dtTransOffset = 523;
	
	  ;% rtP.Degenerated_Gain_p1y3cmfgyv
	  section.data(274).logicalSrcIdx = 279;
	  section.data(274).dtTransOffset = 524;
	
	  ;% rtP.ttkernel_P1_Size_p20pgflkve
	  section.data(275).logicalSrcIdx = 280;
	  section.data(275).dtTransOffset = 525;
	
	  ;% rtP.ttkernel_P1_jm2c0svanl
	  section.data(276).logicalSrcIdx = 281;
	  section.data(276).dtTransOffset = 527;
	
	  ;% rtP.ttkernel_P2_Size_gzkp3kxg33
	  section.data(277).logicalSrcIdx = 282;
	  section.data(277).dtTransOffset = 543;
	
	  ;% rtP.ttkernel_P3_Size_l2jji5uq1j
	  section.data(278).logicalSrcIdx = 284;
	  section.data(278).dtTransOffset = 545;
	
	  ;% rtP.ttkernel_P3_hhfssj3tq1
	  section.data(279).logicalSrcIdx = 285;
	  section.data(279).dtTransOffset = 547;
	
	  ;% rtP.ttkernel_P4_Size_hnklzt0jw3
	  section.data(280).logicalSrcIdx = 286;
	  section.data(280).dtTransOffset = 549;
	
	  ;% rtP.ttkernel_P4_jsrxy3jgjq
	  section.data(281).logicalSrcIdx = 287;
	  section.data(281).dtTransOffset = 551;
	
	  ;% rtP.ttkernel_P5_Size_fa3fkgeu1l
	  section.data(282).logicalSrcIdx = 288;
	  section.data(282).dtTransOffset = 552;
	
	  ;% rtP.ttkernel_P5_c3yxs5yxnd
	  section.data(283).logicalSrcIdx = 289;
	  section.data(283).dtTransOffset = 554;
	
	  ;% rtP.ttkernel_P6_Size_p3pprs52yg
	  section.data(284).logicalSrcIdx = 290;
	  section.data(284).dtTransOffset = 555;
	
	  ;% rtP.ttkernel_P7_Size_frsmcrmh0u
	  section.data(285).logicalSrcIdx = 292;
	  section.data(285).dtTransOffset = 557;
	
	  ;% rtP.ttkernel_P7_bffw5cmzwn
	  section.data(286).logicalSrcIdx = 293;
	  section.data(286).dtTransOffset = 559;
	
	  ;% rtP.Distributed_integral_w_Gain_jm5ojyhpid
	  section.data(287).logicalSrcIdx = 294;
	  section.data(287).dtTransOffset = 561;
	
	  ;% rtP.KSencondaryless1_Value_h2aqorl5nb
	  section.data(288).logicalSrcIdx = 295;
	  section.data(288).dtTransOffset = 562;
	
	  ;% rtP.LPFp_NumCoef_oojfmq1khk
	  section.data(289).logicalSrcIdx = 296;
	  section.data(289).dtTransOffset = 563;
	
	  ;% rtP.LPFp_DenCoef_oo54vuxlff
	  section.data(290).logicalSrcIdx = 297;
	  section.data(290).dtTransOffset = 565;
	
	  ;% rtP.LPFp_InitialStates_awo4cpuing
	  section.data(291).logicalSrcIdx = 298;
	  section.data(291).dtTransOffset = 567;
	
	  ;% rtP.Energy_Value_hjsumqx5yk
	  section.data(292).logicalSrcIdx = 299;
	  section.data(292).dtTransOffset = 568;
	
	  ;% rtP.Energy_Value_bn3izespin
	  section.data(293).logicalSrcIdx = 300;
	  section.data(293).dtTransOffset = 569;
	
	  ;% rtP.Gain1_Gain_cjogxzntno
	  section.data(294).logicalSrcIdx = 301;
	  section.data(294).dtTransOffset = 570;
	
	  ;% rtP.Gain3_Gain_fal1cwrksj
	  section.data(295).logicalSrcIdx = 302;
	  section.data(295).dtTransOffset = 571;
	
	  ;% rtP.Gain5_Gain_npwynuslmj
	  section.data(296).logicalSrcIdx = 303;
	  section.data(296).dtTransOffset = 572;
	
	  ;% rtP.donotdeletethisgain_Gain_pqt51vmxbg
	  section.data(297).logicalSrcIdx = 304;
	  section.data(297).dtTransOffset = 573;
	
	  ;% rtP.donotdeletethisgain_Gain_iyrfn2wpbu
	  section.data(298).logicalSrcIdx = 305;
	  section.data(298).dtTransOffset = 574;
	
	  ;% rtP.upi_Gain_gdts1vd3ud
	  section.data(299).logicalSrcIdx = 306;
	  section.data(299).dtTransOffset = 575;
	
	  ;% rtP.Constant_Value_jsxo0wpglc
	  section.data(300).logicalSrcIdx = 307;
	  section.data(300).dtTransOffset = 576;
	
	  ;% rtP.Constant1_Value_eht0aia3xv
	  section.data(301).logicalSrcIdx = 308;
	  section.data(301).dtTransOffset = 577;
	
	  ;% rtP.Step_Time_cqeoamr4wm
	  section.data(302).logicalSrcIdx = 309;
	  section.data(302).dtTransOffset = 578;
	
	  ;% rtP.Step_Y0_gycl0h21kq
	  section.data(303).logicalSrcIdx = 310;
	  section.data(303).dtTransOffset = 579;
	
	  ;% rtP.Step_YFinal_lf2hwitpjk
	  section.data(304).logicalSrcIdx = 311;
	  section.data(304).dtTransOffset = 580;
	
	  ;% rtP.Gain1_Gain_edmc5opvxj
	  section.data(305).logicalSrcIdx = 312;
	  section.data(305).dtTransOffset = 581;
	
	  ;% rtP.Gain3_Gain_kcpjx312wz
	  section.data(306).logicalSrcIdx = 313;
	  section.data(306).dtTransOffset = 582;
	
	  ;% rtP.Integrator_IC_hhogk15lld
	  section.data(307).logicalSrcIdx = 314;
	  section.data(307).dtTransOffset = 583;
	
	  ;% rtP.Integrator1_IC_jdydknk1ci
	  section.data(308).logicalSrcIdx = 315;
	  section.data(308).dtTransOffset = 584;
	
	  ;% rtP.ttnetwork_P1_Size
	  section.data(309).logicalSrcIdx = 316;
	  section.data(309).dtTransOffset = 585;
	
	  ;% rtP.ttnetwork_P1
	  section.data(310).logicalSrcIdx = 317;
	  section.data(310).dtTransOffset = 587;
	
	  ;% rtP.ttnetwork_P2_Size
	  section.data(311).logicalSrcIdx = 318;
	  section.data(311).dtTransOffset = 588;
	
	  ;% rtP.ttnetwork_P2
	  section.data(312).logicalSrcIdx = 319;
	  section.data(312).dtTransOffset = 590;
	
	  ;% rtP.ttnetwork_P3_Size
	  section.data(313).logicalSrcIdx = 320;
	  section.data(313).dtTransOffset = 591;
	
	  ;% rtP.ttnetwork_P3
	  section.data(314).logicalSrcIdx = 321;
	  section.data(314).dtTransOffset = 593;
	
	  ;% rtP.ttnetwork_P4_Size
	  section.data(315).logicalSrcIdx = 322;
	  section.data(315).dtTransOffset = 594;
	
	  ;% rtP.ttnetwork_P4
	  section.data(316).logicalSrcIdx = 323;
	  section.data(316).dtTransOffset = 596;
	
	  ;% rtP.ttnetwork_P5_Size
	  section.data(317).logicalSrcIdx = 324;
	  section.data(317).dtTransOffset = 597;
	
	  ;% rtP.ttnetwork_P5
	  section.data(318).logicalSrcIdx = 325;
	  section.data(318).dtTransOffset = 599;
	
	  ;% rtP.ttnetwork_P6_Size
	  section.data(319).logicalSrcIdx = 326;
	  section.data(319).dtTransOffset = 600;
	
	  ;% rtP.ttnetwork_P6
	  section.data(320).logicalSrcIdx = 327;
	  section.data(320).dtTransOffset = 602;
	
	  ;% rtP.ttnetwork_P7_Size
	  section.data(321).logicalSrcIdx = 328;
	  section.data(321).dtTransOffset = 603;
	
	  ;% rtP.ttnetwork_P7
	  section.data(322).logicalSrcIdx = 329;
	  section.data(322).dtTransOffset = 605;
	
	  ;% rtP.ttnetwork_P8_Size
	  section.data(323).logicalSrcIdx = 330;
	  section.data(323).dtTransOffset = 608;
	
	  ;% rtP.ttnetwork_P8
	  section.data(324).logicalSrcIdx = 331;
	  section.data(324).dtTransOffset = 610;
	
	  ;% rtP.ttnetwork_P9_Size
	  section.data(325).logicalSrcIdx = 332;
	  section.data(325).dtTransOffset = 611;
	
	  ;% rtP.ttnetwork_P9
	  section.data(326).logicalSrcIdx = 333;
	  section.data(326).dtTransOffset = 613;
	
	  ;% rtP.ttnetwork_P10_Size
	  section.data(327).logicalSrcIdx = 334;
	  section.data(327).dtTransOffset = 617;
	
	  ;% rtP.ttnetwork_P10
	  section.data(328).logicalSrcIdx = 335;
	  section.data(328).dtTransOffset = 619;
	
	  ;% rtP.ttnetwork_P11_Size
	  section.data(329).logicalSrcIdx = 336;
	  section.data(329).dtTransOffset = 620;
	
	  ;% rtP.ttnetwork_P11
	  section.data(330).logicalSrcIdx = 337;
	  section.data(330).dtTransOffset = 622;
	
	  ;% rtP.ttnetwork_P12_Size
	  section.data(331).logicalSrcIdx = 338;
	  section.data(331).dtTransOffset = 623;
	
	  ;% rtP.ttnetwork_P12
	  section.data(332).logicalSrcIdx = 339;
	  section.data(332).dtTransOffset = 625;
	
	  ;% rtP.ttnetwork_P13_Size
	  section.data(333).logicalSrcIdx = 340;
	  section.data(333).dtTransOffset = 626;
	
	  ;% rtP.ttnetwork_P13
	  section.data(334).logicalSrcIdx = 341;
	  section.data(334).dtTransOffset = 628;
	
	  ;% rtP.ttnetwork_P14_Size
	  section.data(335).logicalSrcIdx = 342;
	  section.data(335).dtTransOffset = 629;
	
	  ;% rtP.ttnetwork_P14
	  section.data(336).logicalSrcIdx = 343;
	  section.data(336).dtTransOffset = 631;
	
	  ;% rtP.ttnetwork_P15_Size
	  section.data(337).logicalSrcIdx = 344;
	  section.data(337).dtTransOffset = 632;
	
	  ;% rtP.ttnetwork_P15
	  section.data(338).logicalSrcIdx = 345;
	  section.data(338).dtTransOffset = 634;
	
	  ;% rtP.ttnetwork_P16_Size
	  section.data(339).logicalSrcIdx = 346;
	  section.data(339).dtTransOffset = 635;
	
	  ;% rtP.ttnetwork_P16
	  section.data(340).logicalSrcIdx = 347;
	  section.data(340).dtTransOffset = 637;
	
	  ;% rtP.ttnetwork_P17_Size
	  section.data(341).logicalSrcIdx = 348;
	  section.data(341).dtTransOffset = 638;
	
	  ;% rtP.ttnetwork_P17
	  section.data(342).logicalSrcIdx = 349;
	  section.data(342).dtTransOffset = 640;
	
	  ;% rtP.ttnetwork_P18_Size
	  section.data(343).logicalSrcIdx = 350;
	  section.data(343).dtTransOffset = 641;
	
	  ;% rtP.ttnetwork_P18
	  section.data(344).logicalSrcIdx = 351;
	  section.data(344).dtTransOffset = 643;
	
	  ;% rtP.ttnetwork_P19_Size
	  section.data(345).logicalSrcIdx = 352;
	  section.data(345).dtTransOffset = 644;
	
	  ;% rtP.ttnetwork_P19
	  section.data(346).logicalSrcIdx = 353;
	  section.data(346).dtTransOffset = 646;
	
	  ;% rtP.ttnetwork_P20_Size
	  section.data(347).logicalSrcIdx = 354;
	  section.data(347).dtTransOffset = 647;
	
	  ;% rtP.ttnetwork_P20
	  section.data(348).logicalSrcIdx = 355;
	  section.data(348).dtTransOffset = 649;
	
	  ;% rtP.ttnetwork_P21_Size
	  section.data(349).logicalSrcIdx = 356;
	  section.data(349).dtTransOffset = 650;
	
	  ;% rtP.ttnetwork_P21
	  section.data(350).logicalSrcIdx = 357;
	  section.data(350).dtTransOffset = 652;
	
	  ;% rtP.donotdeletethisgain_Gain_h35lkhvbav
	  section.data(351).logicalSrcIdx = 358;
	  section.data(351).dtTransOffset = 653;
	
	  ;% rtP.donotdeletethisgain_Gain_i04ou4rp5q
	  section.data(352).logicalSrcIdx = 359;
	  section.data(352).dtTransOffset = 654;
	
	  ;% rtP.DataStoreMemory_InitialValue
	  section.data(353).logicalSrcIdx = 360;
	  section.data(353).dtTransOffset = 655;
	
	  ;% rtP.DataStoreMemory1_InitialValue
	  section.data(354).logicalSrcIdx = 361;
	  section.data(354).dtTransOffset = 659;
	
	  ;% rtP.DataStoreMemory2_InitialValue
	  section.data(355).logicalSrcIdx = 362;
	  section.data(355).dtTransOffset = 663;
	
	  ;% rtP.DataStoreMemory3_InitialValue
	  section.data(356).logicalSrcIdx = 363;
	  section.data(356).dtTransOffset = 667;
	
	  ;% rtP.DataStoreMemory4_InitialValue
	  section.data(357).logicalSrcIdx = 364;
	  section.data(357).dtTransOffset = 671;
	
	  ;% rtP.DataStoreMemory5_InitialValue
	  section.data(358).logicalSrcIdx = 365;
	  section.data(358).dtTransOffset = 675;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtP.KSencondaryless_Value
	  section.data(1).logicalSrcIdx = 366;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.KSencondaryless_Value_bmosygzxe0
	  section.data(2).logicalSrcIdx = 367;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.KSencondaryless_Value_optmbdsthn
	  section.data(3).logicalSrcIdx = 368;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.KSencondaryless_Value_oyco5fzk4w
	  section.data(4).logicalSrcIdx = 369;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_Lv
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_Vn
	  section.data(2).logicalSrcIdx = 371;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_dr
	  section.data(3).logicalSrcIdx = 372;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_m
	  section.data(4).logicalSrcIdx = 373;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_mp
	  section.data(5).logicalSrcIdx = 374;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_n
	  section.data(6).logicalSrcIdx = 375;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_ts
	  section.data(7).logicalSrcIdx = 376;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.ozftnlfeg3.primarycontroldroopZv_wo
	  section.data(8).logicalSrcIdx = 377;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.jrosma4ai4.replacer5_a
	  section.data(1).logicalSrcIdx = 378;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.jlne01gbu0.replacer5_a
	  section.data(1).logicalSrcIdx = 379;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.nybhsuuh1p.replacer4_a
	  section.data(1).logicalSrcIdx = 380;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.b4zolxyidp.replacer3_a
	  section.data(1).logicalSrcIdx = 381;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.pz2stfwruz.replacer2_a
	  section.data(1).logicalSrcIdx = 382;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.nlrcxogbog.replacer1_a
	  section.data(1).logicalSrcIdx = 383;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.j20pq3r21f.integratorcontrol_a
	  section.data(1).logicalSrcIdx = 384;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_dr
	  section.data(2).logicalSrcIdx = 385;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_kiV
	  section.data(3).logicalSrcIdx = 386;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_kif
	  section.data(4).logicalSrcIdx = 387;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_kpV
	  section.data(5).logicalSrcIdx = 388;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_kpf
	  section.data(6).logicalSrcIdx = 389;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_ts
	  section.data(7).logicalSrcIdx = 390;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.j20pq3r21f.integratorcontrol_wo
	  section.data(8).logicalSrcIdx = 391;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.avezulewcn.primarycontroldroopZv_Lv
	  section.data(1).logicalSrcIdx = 392;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_Vn
	  section.data(2).logicalSrcIdx = 393;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_dr
	  section.data(3).logicalSrcIdx = 394;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_m
	  section.data(4).logicalSrcIdx = 395;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_mp
	  section.data(5).logicalSrcIdx = 396;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_n
	  section.data(6).logicalSrcIdx = 397;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_ts
	  section.data(7).logicalSrcIdx = 398;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.avezulewcn.primarycontroldroopZv_wo
	  section.data(8).logicalSrcIdx = 399;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.k04lp2vsfm.replacer5_a
	  section.data(1).logicalSrcIdx = 400;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.p0jpb31wlq.replacer5_a
	  section.data(1).logicalSrcIdx = 401;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.l1cumv5mxc.replacer4_a
	  section.data(1).logicalSrcIdx = 402;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.pcljl3fmii.replacer3_a
	  section.data(1).logicalSrcIdx = 403;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.mmnlogmmqe.replacer2_a
	  section.data(1).logicalSrcIdx = 404;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ipvzgutla1.replacer1_a
	  section.data(1).logicalSrcIdx = 405;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.dvrqjotubu.integratorcontrol_a
	  section.data(1).logicalSrcIdx = 406;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_dr
	  section.data(2).logicalSrcIdx = 407;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_kiV
	  section.data(3).logicalSrcIdx = 408;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_kif
	  section.data(4).logicalSrcIdx = 409;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_kpV
	  section.data(5).logicalSrcIdx = 410;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_kpf
	  section.data(6).logicalSrcIdx = 411;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_ts
	  section.data(7).logicalSrcIdx = 412;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.dvrqjotubu.integratorcontrol_wo
	  section.data(8).logicalSrcIdx = 413;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_Lv
	  section.data(1).logicalSrcIdx = 414;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_Vn
	  section.data(2).logicalSrcIdx = 415;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_dr
	  section.data(3).logicalSrcIdx = 416;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_m
	  section.data(4).logicalSrcIdx = 417;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_mp
	  section.data(5).logicalSrcIdx = 418;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_n
	  section.data(6).logicalSrcIdx = 419;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_ts
	  section.data(7).logicalSrcIdx = 420;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.cwkcdvwsyb.primarycontroldroopZv_wo
	  section.data(8).logicalSrcIdx = 421;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.gpr5ewbwvu.replacer5_a
	  section.data(1).logicalSrcIdx = 422;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.pmll2wrcy3.replacer5_a
	  section.data(1).logicalSrcIdx = 423;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.omwjydko3j.replacer4_a
	  section.data(1).logicalSrcIdx = 424;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ejkqkpkoqg.replacer3_a
	  section.data(1).logicalSrcIdx = 425;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.pxgmr2o0yw.replacer2_a
	  section.data(1).logicalSrcIdx = 426;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.mrc3jz2kzs.replacer1_a
	  section.data(1).logicalSrcIdx = 427;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(25) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.jwxitznkuq.integratorcontrol_a
	  section.data(1).logicalSrcIdx = 428;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_dr
	  section.data(2).logicalSrcIdx = 429;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_kiV
	  section.data(3).logicalSrcIdx = 430;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_kif
	  section.data(4).logicalSrcIdx = 431;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_kpV
	  section.data(5).logicalSrcIdx = 432;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_kpf
	  section.data(6).logicalSrcIdx = 433;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_ts
	  section.data(7).logicalSrcIdx = 434;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.jwxitznkuq.integratorcontrol_wo
	  section.data(8).logicalSrcIdx = 435;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(26) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_Lv
	  section.data(1).logicalSrcIdx = 436;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_Vn
	  section.data(2).logicalSrcIdx = 437;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_dr
	  section.data(3).logicalSrcIdx = 438;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_m
	  section.data(4).logicalSrcIdx = 439;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_mp
	  section.data(5).logicalSrcIdx = 440;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_n
	  section.data(6).logicalSrcIdx = 441;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_ts
	  section.data(7).logicalSrcIdx = 442;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.a21clfzxwp.primarycontroldroopZv_wo
	  section.data(8).logicalSrcIdx = 443;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.loojatj1b3.replacer5_a
	  section.data(1).logicalSrcIdx = 444;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ae0vvuvpaf.replacer5_a
	  section.data(1).logicalSrcIdx = 445;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.lkguggosm5.replacer4_a
	  section.data(1).logicalSrcIdx = 446;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.n3la5yge0s.replacer3_a
	  section.data(1).logicalSrcIdx = 447;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.mfw2ixjjzd.replacer2_a
	  section.data(1).logicalSrcIdx = 448;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.i0nb5cbdli.replacer1_a
	  section.data(1).logicalSrcIdx = 449;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(33) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.pxlv2lf0yq.integratorcontrol_a
	  section.data(1).logicalSrcIdx = 450;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_dr
	  section.data(2).logicalSrcIdx = 451;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_kiV
	  section.data(3).logicalSrcIdx = 452;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_kif
	  section.data(4).logicalSrcIdx = 453;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_kpV
	  section.data(5).logicalSrcIdx = 454;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_kpf
	  section.data(6).logicalSrcIdx = 455;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_ts
	  section.data(7).logicalSrcIdx = 456;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtP.pxlv2lf0yq.integratorcontrol_wo
	  section.data(8).logicalSrcIdx = 457;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(34) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 33;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 164;
      section.data(164)  = dumData; %prealloc
      
	  ;% rtB.ek3a1451ay
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.dpgwwjc2rz
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtB.kycfwls143
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% rtB.ee5gbg0io5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 11;
	
	  ;% rtB.avlxjfrevq
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% rtB.hoq5gatyaq
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtB.fntkhkkhap
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 17;
	
	  ;% rtB.biin3vhjc0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 18;
	
	  ;% rtB.kkx4ezyhkw
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 19;
	
	  ;% rtB.mpyof2qigx
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 20;
	
	  ;% rtB.fypbjuyz3n
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 21;
	
	  ;% rtB.mco3v3iige
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 22;
	
	  ;% rtB.hbtkhijkte
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 23;
	
	  ;% rtB.ljwqffhvl4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% rtB.h4k23zmq31
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 28;
	
	  ;% rtB.jsillufvig
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% rtB.d2kvmgvdht
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 36;
	
	  ;% rtB.okzfmxk5yy
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 38;
	
	  ;% rtB.m1vu1obgik
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 39;
	
	  ;% rtB.kcbmknce0k
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 41;
	
	  ;% rtB.lq5dbqfp25
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 42;
	
	  ;% rtB.ld4l31qhaw
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 43;
	
	  ;% rtB.fchnjsvgwh
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 44;
	
	  ;% rtB.ibl2erstls
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 46;
	
	  ;% rtB.bxyd4fbh0g
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% rtB.pijde51qab
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% rtB.gehrrnez0b
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% rtB.dwdpwj5pni
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% rtB.dti2carlq5
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% rtB.mguxqfcdvk
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% rtB.nebhkpb5ai
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 55;
	
	  ;% rtB.iewvn51hd3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 59;
	
	  ;% rtB.h1tgqdz5v2
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 60;
	
	  ;% rtB.gq1khgfhm2
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 61;
	
	  ;% rtB.n0mg2py0tt
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 62;
	
	  ;% rtB.n2zlvavzvj
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 63;
	
	  ;% rtB.lvxcghiadw
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 69;
	
	  ;% rtB.iz5ulgunhl
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 70;
	
	  ;% rtB.falp0kne2f
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 71;
	
	  ;% rtB.iodvmyfik4
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 72;
	
	  ;% rtB.fobyeqif54
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 78;
	
	  ;% rtB.iftyjztmep
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 79;
	
	  ;% rtB.cyfk1qotlx
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 80;
	
	  ;% rtB.dnqnzblmbp
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 81;
	
	  ;% rtB.cwaxgcfgm2
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 87;
	
	  ;% rtB.of4z3nxnpu
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 88;
	
	  ;% rtB.mpet5fjgog
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 89;
	
	  ;% rtB.ec4ppad44q
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 90;
	
	  ;% rtB.awk2wo0fe2
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 91;
	
	  ;% rtB.icb23pk4yt
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 92;
	
	  ;% rtB.poglkcfqy3
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 102;
	
	  ;% rtB.f5kuq3shj4
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 103;
	
	  ;% rtB.aczh1lvgar
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 104;
	
	  ;% rtB.dzuta0dnpn
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 108;
	
	  ;% rtB.hx0wj5yo2m
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 112;
	
	  ;% rtB.kcng2h2ox5
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 113;
	
	  ;% rtB.d4jrh0gj3t
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 114;
	
	  ;% rtB.nhbi4wyipn
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 115;
	
	  ;% rtB.pdvnbdhjm2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 116;
	
	  ;% rtB.mj22h2mmx5
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 117;
	
	  ;% rtB.mfwsny1flw
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 118;
	
	  ;% rtB.cbfpuf2or0
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 119;
	
	  ;% rtB.abwh33q232
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 123;
	
	  ;% rtB.b4slefd2sz
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 127;
	
	  ;% rtB.ctf1kxqmdo
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 131;
	
	  ;% rtB.pgkimqavpk
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 133;
	
	  ;% rtB.f5aj101k3a
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 134;
	
	  ;% rtB.kkm103ywxt
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 136;
	
	  ;% rtB.e1nfog11ri
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 137;
	
	  ;% rtB.d535qgtjbe
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 138;
	
	  ;% rtB.kdglpydeda
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 139;
	
	  ;% rtB.l523yuyruu
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 141;
	
	  ;% rtB.ellko3pdhd
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 143;
	
	  ;% rtB.e4hzm4gatj
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 144;
	
	  ;% rtB.podole3fca
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 145;
	
	  ;% rtB.lhfof1cyys
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 146;
	
	  ;% rtB.krez0hg5v1
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 147;
	
	  ;% rtB.lgfjmq2ecm
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 148;
	
	  ;% rtB.i52hyrlq2j
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 150;
	
	  ;% rtB.hen0mtsi3a
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 154;
	
	  ;% rtB.lxk0xwc3vx
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 155;
	
	  ;% rtB.hkkbhcvcxm
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 156;
	
	  ;% rtB.lmpvvsgbzc
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 157;
	
	  ;% rtB.adhev5qmdl
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 158;
	
	  ;% rtB.jkgsoin4ud
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 159;
	
	  ;% rtB.fg3wll3qdz
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 160;
	
	  ;% rtB.keuugvf2im
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 164;
	
	  ;% rtB.pazkwcssox
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 168;
	
	  ;% rtB.brmhwzxuee
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 169;
	
	  ;% rtB.g4tkowhewi
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 170;
	
	  ;% rtB.j52dskeymb
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 171;
	
	  ;% rtB.fpqii21x5i
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 172;
	
	  ;% rtB.ek0x1ax1lz
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 173;
	
	  ;% rtB.n2mcguhbur
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 174;
	
	  ;% rtB.as33t0f0ow
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 175;
	
	  ;% rtB.meko05j0sc
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 179;
	
	  ;% rtB.lhj2ghm2f4
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 183;
	
	  ;% rtB.dbqcdqyhwy
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 187;
	
	  ;% rtB.c02zl0czxs
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 189;
	
	  ;% rtB.pugsu0nevr
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 190;
	
	  ;% rtB.bw14bin5hh
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 192;
	
	  ;% rtB.ldw4br50ng
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 193;
	
	  ;% rtB.gsofcjddvn
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 194;
	
	  ;% rtB.lzsvpxojnz
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 195;
	
	  ;% rtB.n10inqqacb
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 197;
	
	  ;% rtB.nastbsm32g
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 199;
	
	  ;% rtB.nxnoiv0pth
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 200;
	
	  ;% rtB.au5g3iyahf
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 201;
	
	  ;% rtB.ffbtpjovm2
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 202;
	
	  ;% rtB.enmfzw4wn5
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 203;
	
	  ;% rtB.na2ttkkmwd
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 204;
	
	  ;% rtB.eux2brobbv
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 206;
	
	  ;% rtB.eoyd4uc25o
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 210;
	
	  ;% rtB.cawwajqazb
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 211;
	
	  ;% rtB.d1h14ldyu4
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 212;
	
	  ;% rtB.cs2wisepbp
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 213;
	
	  ;% rtB.d4qvlfmvmy
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 214;
	
	  ;% rtB.kurks2zcva
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 215;
	
	  ;% rtB.p0z5ebkftq
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 216;
	
	  ;% rtB.fsr4klu2iw
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 220;
	
	  ;% rtB.b3buxfo0jq
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 224;
	
	  ;% rtB.m4ofszhbm4
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 225;
	
	  ;% rtB.b30gw04tpb
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 226;
	
	  ;% rtB.irpgyparai
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 227;
	
	  ;% rtB.gdvqwx5p4u
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 228;
	
	  ;% rtB.g03umd0jya
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 229;
	
	  ;% rtB.do20asbnvu
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 230;
	
	  ;% rtB.nyh5uqpipi
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 231;
	
	  ;% rtB.p1j2mjcnmh
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 235;
	
	  ;% rtB.a2j3heg5ll
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 239;
	
	  ;% rtB.aee3tydqqe
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 243;
	
	  ;% rtB.l2ny1ho3uf
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 245;
	
	  ;% rtB.o4komacgjl
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 246;
	
	  ;% rtB.h4tgjphw5q
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 248;
	
	  ;% rtB.ldmwux2zhx
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 249;
	
	  ;% rtB.kms2jmv2td
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 250;
	
	  ;% rtB.ozch1m2xun
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 251;
	
	  ;% rtB.p4eyqrx5tw
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 253;
	
	  ;% rtB.dzlnvksxlk
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 255;
	
	  ;% rtB.iy2ry2qx1u
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 256;
	
	  ;% rtB.jw5211g3vm
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 257;
	
	  ;% rtB.ctjaojcbjq
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 258;
	
	  ;% rtB.kknf5smhy4
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 259;
	
	  ;% rtB.blvbd5kgbi
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 260;
	
	  ;% rtB.hjgncjfz4l
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 262;
	
	  ;% rtB.oqxkfo2dq5
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 266;
	
	  ;% rtB.oues2lcti4
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 267;
	
	  ;% rtB.eelx0pksev
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 268;
	
	  ;% rtB.lg5rqpaf2e
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 269;
	
	  ;% rtB.hm532ngjvw
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 270;
	
	  ;% rtB.c24lrwyun4
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 271;
	
	  ;% rtB.fo5rqi15o1
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 272;
	
	  ;% rtB.f2q5magsot
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 273;
	
	  ;% rtB.ktweuvg11j
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 274;
	
	  ;% rtB.gcnh1cojbn
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 279;
	
	  ;% rtB.lc3tl5isia
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 284;
	
	  ;% rtB.clfpixb40s
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 285;
	
	  ;% rtB.fl0i4sb4vv
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 289;
	
	  ;% rtB.gmhqlr0ded
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 293;
	
	  ;% rtB.carjwykir1
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 297;
	
	  ;% rtB.caywsc2yvv
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 301;
	
	  ;% rtB.eyrg550icf
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 305;
	
	  ;% rtB.pnwecd2kft
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 309;
	
	  ;% rtB.gej5khtvm2
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 310;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.ozftnlfeg3.n0fuel1bnn
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ozftnlfeg3.dberndtk2w
	  section.data(2).logicalSrcIdx = 165;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.ozftnlfeg3.on2dguwvvl
	  section.data(3).logicalSrcIdx = 166;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jrosma4ai4.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 167;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jlne01gbu0.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 168;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nybhsuuh1p.mesgqmrxmy
	  section.data(1).logicalSrcIdx = 169;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.b4zolxyidp.c03pdi1rvc
	  section.data(1).logicalSrcIdx = 170;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pz2stfwruz.bbcbwrpqmg
	  section.data(1).logicalSrcIdx = 171;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nlrcxogbog.ovjujdzpjt
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.j20pq3r21f.ioo1a4zpmx
	  section.data(1).logicalSrcIdx = 173;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.avezulewcn.n0fuel1bnn
	  section.data(1).logicalSrcIdx = 174;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.avezulewcn.dberndtk2w
	  section.data(2).logicalSrcIdx = 175;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.avezulewcn.on2dguwvvl
	  section.data(3).logicalSrcIdx = 176;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.k04lp2vsfm.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 177;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.p0jpb31wlq.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 178;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.l1cumv5mxc.mesgqmrxmy
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pcljl3fmii.c03pdi1rvc
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mmnlogmmqe.bbcbwrpqmg
	  section.data(1).logicalSrcIdx = 181;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ipvzgutla1.ovjujdzpjt
	  section.data(1).logicalSrcIdx = 182;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dvrqjotubu.ioo1a4zpmx
	  section.data(1).logicalSrcIdx = 183;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.cwkcdvwsyb.n0fuel1bnn
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.cwkcdvwsyb.dberndtk2w
	  section.data(2).logicalSrcIdx = 185;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.cwkcdvwsyb.on2dguwvvl
	  section.data(3).logicalSrcIdx = 186;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.gpr5ewbwvu.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pmll2wrcy3.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 188;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.omwjydko3j.mesgqmrxmy
	  section.data(1).logicalSrcIdx = 189;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ejkqkpkoqg.c03pdi1rvc
	  section.data(1).logicalSrcIdx = 190;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pxgmr2o0yw.bbcbwrpqmg
	  section.data(1).logicalSrcIdx = 191;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mrc3jz2kzs.ovjujdzpjt
	  section.data(1).logicalSrcIdx = 192;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jwxitznkuq.ioo1a4zpmx
	  section.data(1).logicalSrcIdx = 193;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(25) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.a21clfzxwp.n0fuel1bnn
	  section.data(1).logicalSrcIdx = 194;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.a21clfzxwp.dberndtk2w
	  section.data(2).logicalSrcIdx = 195;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.a21clfzxwp.on2dguwvvl
	  section.data(3).logicalSrcIdx = 196;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.loojatj1b3.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 197;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ae0vvuvpaf.hgxfgflt2m
	  section.data(1).logicalSrcIdx = 198;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lkguggosm5.mesgqmrxmy
	  section.data(1).logicalSrcIdx = 199;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.n3la5yge0s.c03pdi1rvc
	  section.data(1).logicalSrcIdx = 200;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.mfw2ixjjzd.bbcbwrpqmg
	  section.data(1).logicalSrcIdx = 201;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.i0nb5cbdli.ovjujdzpjt
	  section.data(1).logicalSrcIdx = 202;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pxlv2lf0yq.ioo1a4zpmx
	  section.data(1).logicalSrcIdx = 203;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(33) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 16;
    sectIdxOffset = 33;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 88;
      section.data(88)  = dumData; %prealloc
      
	  ;% rtDW.f5c0nsumji
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.a5w40p1bws
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.eanwkjl2vy
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.d5bnnktx4e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.lnetbv1cgv
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.orkc55dufk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.nkbjhdynsp
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.ldb4vi0ha4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.mjqxgo2das
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.lstr5kczd4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.ex3o4uqzc2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.mcbh12k100
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ahv3cotbw2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.p5sygl0ymh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.gidygjlsh2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.oktxx1jm30
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.jxsk15cftx
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% rtDW.h31mfjlljs
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% rtDW.efdih4dveq
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% rtDW.n31fjbosih
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 20;
	
	  ;% rtDW.bj3nvzbqqv
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 21;
	
	  ;% rtDW.pftedxldcl
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 22;
	
	  ;% rtDW.ffb5al3bwy
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 23;
	
	  ;% rtDW.l2sbaaoqpn
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 24;
	
	  ;% rtDW.nha400jjfg
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 25;
	
	  ;% rtDW.lv3zjk5f1k
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 26;
	
	  ;% rtDW.bugcdre0xq
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 27;
	
	  ;% rtDW.ghsofqsrqn
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 29;
	
	  ;% rtDW.hccpqibboh
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 30;
	
	  ;% rtDW.mmm2iqducw
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 31;
	
	  ;% rtDW.caoih1mnoc
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 32;
	
	  ;% rtDW.ni0pxjjk34
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 33;
	
	  ;% rtDW.hlgbmv2r55
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 34;
	
	  ;% rtDW.p2lhgag51t
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 35;
	
	  ;% rtDW.nknewvnn53
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 36;
	
	  ;% rtDW.guwv0f3uot
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 37;
	
	  ;% rtDW.hzmcfcyu1n
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% rtDW.ggorbvxv0b
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% rtDW.ilfjamszda
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 41;
	
	  ;% rtDW.ewze1iozrz
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 42;
	
	  ;% rtDW.bkwxpr2rpy
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 43;
	
	  ;% rtDW.l0gdo0gwee
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 44;
	
	  ;% rtDW.jy5gknzcfu
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 45;
	
	  ;% rtDW.mkmpmcvnsy
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 46;
	
	  ;% rtDW.nom2ms4idi
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 47;
	
	  ;% rtDW.h2vskoxuxe
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% rtDW.h1t1phh10c
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% rtDW.foiy3odoz1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 54;
	
	  ;% rtDW.pizmexwruz
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 58;
	
	  ;% rtDW.k5wmx351m0
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 62;
	
	  ;% rtDW.fmmswgsion
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% rtDW.aboia0klkk
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 70;
	
	  ;% rtDW.fvdlnsmpbl
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% rtDW.hgisorl0lv
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 174;
	
	  ;% rtDW.bc1tq0iten
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 274;
	
	  ;% rtDW.ggpdvqbik4
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 275;
	
	  ;% rtDW.eraemmnzoz
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 276;
	
	  ;% rtDW.cd5a0neolm
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 277;
	
	  ;% rtDW.blweiavnmj
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 278;
	
	  ;% rtDW.cxib0dsdcq
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 378;
	
	  ;% rtDW.fs03kermta
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 478;
	
	  ;% rtDW.gaht5h2guw
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 578;
	
	  ;% rtDW.czc2sb2jwa
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 678;
	
	  ;% rtDW.anaa2i2evl
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 778;
	
	  ;% rtDW.k0nz2julpt
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 779;
	
	  ;% rtDW.pkdkxevryy
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 780;
	
	  ;% rtDW.lnjgkjkghh
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 781;
	
	  ;% rtDW.k2lslkrofb
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 782;
	
	  ;% rtDW.o2kydmp2r4
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 882;
	
	  ;% rtDW.i2tar503fo
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 982;
	
	  ;% rtDW.azcmulp3j0
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 1082;
	
	  ;% rtDW.jbzxiyzok1
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 1182;
	
	  ;% rtDW.hrj53k3isf
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 1282;
	
	  ;% rtDW.f0qbsmk4ex
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 1283;
	
	  ;% rtDW.jsd0ujpvhr
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 1284;
	
	  ;% rtDW.pfrwigqbzn
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 1285;
	
	  ;% rtDW.auvkbyqkxd
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 1286;
	
	  ;% rtDW.f3k0bkdqnd
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 1386;
	
	  ;% rtDW.h0qgaci0at
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 1486;
	
	  ;% rtDW.e23cqdlwby
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 1586;
	
	  ;% rtDW.og10ihhnhf
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 1686;
	
	  ;% rtDW.oimg4prx1p
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 1786;
	
	  ;% rtDW.goy3rwgvfy
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 1787;
	
	  ;% rtDW.lyohx44v2w
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 1788;
	
	  ;% rtDW.eopudmnicm
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 1789;
	
	  ;% rtDW.beo5lordfv
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 1790;
	
	  ;% rtDW.f0slooz0kt
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 1890;
	
	  ;% rtDW.fi5ombzs0c
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 1990;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.izfteet4gt.LoggedData
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.njuiuoq00q.LoggedData
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.l4tlfv342r.LoggedData
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.l5yezso4td.LoggedData
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.hembuefnfy.LoggedData
	  section.data(5).logicalSrcIdx = 92;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.jhyvglnaqs.LoggedData
	  section.data(6).logicalSrcIdx = 93;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.fqpl3agz2v.LoggedData
	  section.data(7).logicalSrcIdx = 94;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.fw0ubz1mel.LoggedData
	  section.data(8).logicalSrcIdx = 95;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.frfdkzrjsf.LoggedData
	  section.data(9).logicalSrcIdx = 96;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.c5eu0ckh53
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.al0bnq55uc
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.icvisi4y50
	  section.data(3).logicalSrcIdx = 99;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.pjaxqqimom
	  section.data(4).logicalSrcIdx = 100;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.cl0xew40qh
	  section.data(5).logicalSrcIdx = 101;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ewgbd1zlci
	  section.data(6).logicalSrcIdx = 102;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.lchl2nrr42
	  section.data(7).logicalSrcIdx = 103;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.naoiq1nxxi
	  section.data(8).logicalSrcIdx = 104;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.jktkwtec4i
	  section.data(9).logicalSrcIdx = 105;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.dli3x1zfp1
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.inwfij3epu
	  section.data(2).logicalSrcIdx = 107;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jc3c25clri
	  section.data(3).logicalSrcIdx = 108;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.nb5pthjmwg
	  section.data(4).logicalSrcIdx = 109;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.ozftnlfeg3.ka4hfanbtx
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ozftnlfeg3.padb2uwtk3
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ozftnlfeg3.jdyes1duqb
	  section.data(3).logicalSrcIdx = 112;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.j20pq3r21f.j4oaer2coe
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.j20pq3r21f.diheapmar0
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j20pq3r21f.h2qukl2a2z
	  section.data(3).logicalSrcIdx = 115;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.j20pq3r21f.lpucd5ozhl
	  section.data(4).logicalSrcIdx = 116;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.j20pq3r21f.pk5yc5rzah
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.avezulewcn.ka4hfanbtx
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.avezulewcn.padb2uwtk3
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.avezulewcn.jdyes1duqb
	  section.data(3).logicalSrcIdx = 120;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.dvrqjotubu.j4oaer2coe
	  section.data(1).logicalSrcIdx = 121;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dvrqjotubu.diheapmar0
	  section.data(2).logicalSrcIdx = 122;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dvrqjotubu.h2qukl2a2z
	  section.data(3).logicalSrcIdx = 123;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.dvrqjotubu.lpucd5ozhl
	  section.data(4).logicalSrcIdx = 124;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.dvrqjotubu.pk5yc5rzah
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.cwkcdvwsyb.ka4hfanbtx
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.cwkcdvwsyb.padb2uwtk3
	  section.data(2).logicalSrcIdx = 127;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.cwkcdvwsyb.jdyes1duqb
	  section.data(3).logicalSrcIdx = 128;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.jwxitznkuq.j4oaer2coe
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jwxitznkuq.diheapmar0
	  section.data(2).logicalSrcIdx = 130;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jwxitznkuq.h2qukl2a2z
	  section.data(3).logicalSrcIdx = 131;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.jwxitznkuq.lpucd5ozhl
	  section.data(4).logicalSrcIdx = 132;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jwxitznkuq.pk5yc5rzah
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.a21clfzxwp.ka4hfanbtx
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.a21clfzxwp.padb2uwtk3
	  section.data(2).logicalSrcIdx = 135;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.a21clfzxwp.jdyes1duqb
	  section.data(3).logicalSrcIdx = 136;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.pxlv2lf0yq.j4oaer2coe
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pxlv2lf0yq.diheapmar0
	  section.data(2).logicalSrcIdx = 138;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.pxlv2lf0yq.h2qukl2a2z
	  section.data(3).logicalSrcIdx = 139;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.pxlv2lf0yq.lpucd5ozhl
	  section.data(4).logicalSrcIdx = 140;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.pxlv2lf0yq.pk5yc5rzah
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1063567491;
  targMap.checksum1 = 88383218;
  targMap.checksum2 = 3038457091;
  targMap.checksum3 = 3990997617;

