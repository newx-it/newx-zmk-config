//----------------------------------------
#include <behaviors.dtsi>
#include <behaviors/socd.dtsi>
#include <behaviors/unicode.dtsi>
#include <behaviors/num_word.dtsi>
#include <behaviors/battery_percentage_printer.dtsi>
//----------------------------------------
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/pointing.h>
//----------------------------------------
#define ZMK_POINTING_DEFAULT_MOVE_VAL 2000
//----------------------------------------

/ {
macros { 
//---paramaterized macros------------------------------------------------------------------------------------------
		uX: uX 					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; 
   									#binding-cells = <1>; bindings = 
   										<&macro_tap &kp U>, 
										<&macro_param_1to1>, <&macro_tap &kp 0>; 							 	 };
		shiftXdel: shiftXdel 	{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; 
									#binding-cells = <1>; bindings = 
										<&macro_press &kp LSHIFT>,
										<&macro_param_1to1>, <&macro_tap &kp 0>,
										<&macro_release &kp LSHIFT>,
										<&macro_tap &kp DEL>; 	 												 };
		Xspace: Xspace 			{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; 
									#binding-cells = <1>; bindings = 
										<&macro_param_1to1>, <&macro_tap &kp 0 &kp SPACE>;	 					 };
		XXleft: XXleft 			{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; 
									#binding-cells = <1>; bindings = 
										<&macro_param_1to1>, <&macro_tap &kp 0>,
										<&macro_param_1to1>, <&macro_tap &kp 0 &kp LEFT>; 	 	 				 };

//---text insertion------------------------------------------------------------------------------------------------
		mail: mail 				{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp G &kp M &kp A &kp I &kp L &kp DOT &kp C &kp O &kp M>;	 };
		edu: edu 				{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp I &kp S &kp U &kp DOT &kp E &kp D &kp U>;	 			 };
		oa: oa 					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp O &kp A>;												 };
		ue: ue					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp U &kp E>;												 };
		ueu: ueu					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp U &kp E &kp U>;												};
		ao: ao 					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp A &kp O>;												 };
		eu: eu					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp E &kp U>;												 };
		yi: yi					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp Y &kp I>;												 };
		pp: pp					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp P &kp P>;												 };
		fs: fs					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp F &kp S>;												 };
		sf: sf					{ wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp S &kp F>;												 };
//---game stuff----------------------------------------------------------------------------------------------------
		gameX: gameX 			{ wait-ms = <5>; tap-ms = <20>; compatible = "zmk,behavior-macro-one-param"; 
									#binding-cells = <1>; bindings = 
										<&macro_param_1to1>, <&macro_tap &kp 0>;	 						      };
		gamespaceshift: gamespaceshift 	{ wait-ms = <3>; tap-ms = <1>; compatible = "zmk,behavior-macro"; 
									#binding-cells = <0>; bindings = 
										<&macro_tap &kp SPACE &kp LSHIFT>;	 						   		   }; };
		
//-----------------------------------------------------------------------------------------------------------------

behaviors { 
//---simple config--------------------------------------------------------------------------------------------------------------------
		socd2: socd2 		{ compatible = "zmk,behavior-socd"; #binding-cells = <1>; bindings = <&kp>; 							};
		uc: unicode 		{ default-mode = <UC_MODE_WIN_COMPOSE>;																	};
		sl: sticky_layer 	{ release-after-ms = <750>; quick-release; 																};
		sk: sticky_key 		{ release-after-ms = <750>; quick-release; 																};
		mt: mod_tap 		{ tapping-term-ms = <200>; 																				};

//---homerow mods---------------------------------------------------------------------------------------------------------------------
		hml: home_row_mod_l { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; 
								require-prior-idle-ms = <300>; tapping-term-ms = <300>; quick-tap-ms = <200>; 
								hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; 											};
        hmr: home_row_mod_r { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; 
								require-prior-idle-ms = <300>; tapping-term-ms = <300>; quick-tap-ms = <200>; 
								hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; 											};

//---layer/state manipulation---------------------------------------------------------------------------------------------------------
        num_word: num_word 	{ compatible = "zmk,behavior-auto-layer"; #binding-cells = <1>;  
								continue-list = < BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL >; ignore-numbers;					};
		cmt: caps_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&kp>, <&caps_word>; display-name = "Caps-Tap"; 				};
//---generic modtaps------------------------------------------------------------------------------------------------------------------
		amt: a_mod_tap 				{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <150>; bindings = <&kp>, <&kp>; display-name = "a-mod-Tap"; 				};
		bmt: b_mod_tap 				{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <225>; bindings = <&kp>, <&kp>; display-name = "b-mod-Tap"; 				};
		XXleftmt: XXleft_mod_tap 	{ compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <150>; bindings = <&XXleft>, <&kp>; display-name = "XXleft mod-Tap"; 		};
		Xspacemt: Xspace_mod_tap 	{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <150>; bindings = <&Xspace>, <&kp>; display-name = "Xspace mod-Tap"; 		};
		tabmt: tabmt 				{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <150>; bindings = <&ezalttab>, <&kp>; display-name = "ezalttab modtap"; 	};
//---magic----------------------------------------------------------------------------------------------------------------------------
		mage_tap: mage_tap 	{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&mage_rev>, <&mage_rep>; display-name = "mage-mod-Tap";		};
		y_tap: y_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&yi>, <&kp>; display-name = "y-mod-Tap";						};
		p_tap: p_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&pp>, <&kp>; display-name = "p-mod-Tap";						};
		f_tap: f_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&fs>, <&kp>; display-name = "f-mod-Tap";						};
		s_tap: s_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&sf>, <&kp>; display-name = "s-mod-Tap";						};
		mage_a_tap: mage_a_tap 	{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&ao>, <&mage_a>; display-name = "mage-a-mod-Tap";				};
		mage_e_tap: mage_e_tap 	{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&mage_eu>, <&mage_e>; display-name = "mage-e-mod-Tap";				};
		mage_o_tap: mage_o_tap 	{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&oa>, <&mage_o>; display-name = "mage-o-mod-Tap";				};
		u_tap: u_tap 		{ compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
								tapping-term-ms = <150>; bindings = <&ue>, <&kp>; display-name = "u-mod-Tap";						};
		mage_rev: mage_rev 	{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;
								akt_que	 { trigger-keys = <Q>; bindings = <&mage_eu>; 												};
								akt_shift_home_del { trigger-keys = <BSPC>; bindings = < &shiftXdel HOME >; 						};
								akt_shift_end_del { trigger-keys = <DEL>; bindings = < &shiftXdel END >; 							};
								akt_ctlx { trigger-keys = <LC(A)>; bindings = < &kp LC(X) >; 										};
								akt_ctl_tw { trigger-keys = < LC(T) >; bindings = < &kp LC(W) >; 									};
								akt_ctl_wt { trigger-keys = < LC(W) >; bindings = < &kp LC(T) >; 									};	
								akt_ctl_zy { trigger-keys = < LC(Z) >; bindings = < &kp LC(Y) >; 									};
								akt_ctl_yz { trigger-keys = < LC(Y) >; bindings = < &kp LC(Z) >; 									};
								akt_edu { trigger-keys = <AT>; bindings = <&edu>; 												 }; };
		mage_rep: mage_rep 	{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;
								akt_que	 { trigger-keys = <Q>; bindings = <&mage_e>; 												};
								akt_ctlc { trigger-keys = <LC(A)>; bindings = <&kp LC(C)>; 											};
								akt_ctlv { trigger-keys = <LC(C) LC(X) PSCRN>; bindings = <&kp LC(V)>; 								};
								akt_mail { trigger-keys = <AT>; bindings = <&mail>; 												};
								akt_yi { trigger-keys = <Y>; max-prior-idle-ms = <300>; bindings = <&kp I>;						 }; };
		mage_w: mage_w 		{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp W>;
								akt_gs { trigger-keys = <G>; max-prior-idle-ms = <300>; bindings = <&kp S>; }; 						};
		mage_e: mage_e 		{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp E>;
								akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX E>; }; 						};
		mage_eu: mage_eu 	{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&eu>;
								akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&ueu>; }; 						};
		mage_a: mage_a 		{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp A>;
								akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX A>; }; 						};
		mage_i: mage_i 		{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp I>;
								akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX I>; }; 						};
		mage_o: mage_o 		{ compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp O>;
								akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX O>; }; 						};
		ezalttab: ezalttab 	{ compatible = "zmk,behavior-tri-state"; label = "SWAPPER"; #binding-cells = <0>;
            					bindings = <&kt LALT>, <&kp TAB>, <&kt LALT>; ignored-key-positions = <0 2 5 7>;					};
		deadenter: deadenter { compatible = "zmk,behavior-mod-morph"; #binding-cells = <0>; 
								bindings = <&kp ENTER>, <&kp F24>; mods = <(MOD_LALT)>;												};
//---game stuff-----------------------------------------------------------------------------------------------------------------------
		gameXmt: gameX_mod_tap 	{ compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; 
									tapping-term-ms = <150>; bindings = <&kp>, <&gameX>; display-name = "gameX mod-Tap"; 	  }; }; };
//------------------------------------------------------------------------------------------------------------------------------------

//
// t0  t1  t2  t3  t4  t5  t6  t7  t8  t9  t10  t11
// h0 *h1**h2**h3**h4* h5  h6 *h7**h8**h9**h10* h11
// b0  b1  b2  b3  b4  b5  b6  b7  b8  b9  b10  b11
//       thlN *thlH* thlF  thrF *thrH* thrL
//

// layer 0 - default
	// left hand
		// top row
			#define _0t0 	&kp TAB
			#define _0t1 	&none
			#define _0t2 	&kp X
			#define _0t3 	&kp Q
			#define _0t4 	&kp G
			#define _0t5 	&kp W
		// home row
			#define _0h0 	&bmt LC(DEL) DEL
			#define _0h1 	&mage_i
			#define _0h2 	&mage_a
			#define _0h3 	&mage_e
			#define _0h4 	&kp C
			#define _0h5 	&y_tap 0 Y
		// bottom row
			#define _0b0 	&bmt LC(BSPC) BSPC
			#define _0b1 	&kp LSHIFT
			#define _0b2 	&mage_o_tap 0 0
			#define _0b3 	&u_tap 0 U
			#define _0b4 	&mage_tap 0 0
			#define _0b5 	&none
	
	// right hand
		// top row
			#define _0t6 	&kp K
			#define _0t7 	&kp Z
			#define _0t8 	&kp J
			#define _0t9 	&kp B
			#define _0t10 	&none
			#define _0t11 	&kp ESC
		// home row
			#define _0h6 	&kp M
			#define _0h7 	&kp T
			#define _0h8 	&kp H
			#define _0h9 	&kp S
			#define _0h10	&kp N
			#define _0h11	&amt RC(BSPC) BSPC
		// bottom row
			#define _0b6 	&none
			#define _0b7 	&kp D
			#define _0b8 	&kp L
			#define _0b9 	&kp F
			#define _0b10	&none
			#define _0b11	&amt RC(DEL) DEL

	// thumbfan
		// 
			#define _0thlN 	&none
			#define _0thlH 	&lt 2 SPACE
			#define _0thlF	&none
			
			#define _0thrF 	&none
			#define	_0thrH	&lt 1 R
			#define _0thrN	&none

// layer 1 - symbols
	// left hand
		// top row
			#define _1t0 	&kp TAB
			#define _1t1 	&none
			#define _1t2 	&amt LS(N3) 	LS(N5)
			#define _1t3 	&amt LS(N6) 	LS(N2)
			#define _1t4 	&amt LS(EQUAL) 	MINUS
			#define _1t5 	&amt PIPE 		GRAVE
		// home row
			#define _1h0 	&amt LC(DEL) 	DEL
			#define _1h1 	&amt LS(MINUS)	N4
			#define _1h2 	&amt LS(N7) 	N3
			#define _1h3 	&amt EQUAL 		N2
			#define _1h4 	&amt SEMI 		N1
			#define _1h5 	&amt LS(GRAVE) 	SPACE
		// bottom row
			#define _1b0 	&amt LC(BSPC) 	BSPC
			#define _1b1 	&kp LSHIFT
			#define _1b2 	&kp LS(COMMA)
			#define _1b3 	&XXleftmt DQT DQT
			#define _1b4 	&Xspacemt COMMA COMMA
			#define _1b5 	&none
	
	// right hand
		// top row
			#define _1t6 	&amt BSLH 		FSLH
			#define _1t7 	&amt RPAR LPAR
			#define _1t8 	&amt RBRC LBRC 
			#define _1t9 	&amt RBKT LBKT
			#define _1t10 	&none
			#define _1t11 	&kp ESC
		// home row
			#define _1h6 	&amt LS(N4) 	N9
			#define _1h7 	&amt COLON 		N5
			#define _1h8 	&amt LS(N8) 	N6
			#define _1h9 	&amt LS(N1) 	N7
			#define _1h10	&amt LS(FSLH) 	N8
			#define _1h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _1b6 	&none
			#define _1b7 	&Xspacemt DOT DOT
			#define _1b8 	&XXleftmt APOS APOS
			#define _1b9 	&kp LS(DOT)
			#define _1b10	&kp RSHIFT
			#define _1b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _1thlN 	&none
			#define _1thlH 	&kp N0
			#define _1thlF	&none
			
			#define _1thrF 	&none
			#define	_1thrH	&none
			#define _1thrN	&none

// layer 2 - shortcuts
	// left hand
		// top row
			#define _2t0 	&kp TAB
			#define _2t1 	&none
			#define _2t2 	&none
			#define _2t3 	&none
			#define _2t4 	&none
			#define _2t5 	&none
		// home row
			#define _2h0 	&none
			#define _2h1 	&kp PGUP
			#define _2h2 	&kp HOME
			#define _2h3 	&amt LC(LEFT) LEFT
			#define _2h4 	&amt LC(RIGHT) RIGHT
			#define _2h5 	&none
		// bottom row
			#define _2b0 	&amt LC(BSPC) 	BSPC
			#define _2b1 	&kp LSHIFT
			#define _2b2 	&none
			#define _2b3 	&none
			#define _2b4 	&none
			#define _2b5 	&none
	
	// right hand
		// top row
			#define _2t6 	&kp C_PP
			#define _2t7 	&kp C_PREV
			#define _2t8 	&kp C_NEXT
			#define _2t9 	&kp C_MUTE
			#define _2t10 	&none
			#define _2t11 	&kp ESC
		// home row
			#define _2h6 	&none
			#define _2h7 	&amt LC(DOWN) 	DOWN	
			#define _2h8 	&amt LC(UP) 	UP
			#define _2h9 	&kp END		
			#define _2h10	&kp PGDN
			#define _2h11	&amt RC(BSPC) 	BSPC 
		// bottom row
			#define _2b6 	&none
			#define _2b7 	&none   		
			#define _2b8 	&none 	 		
			#define _2b9 	&none
			#define _2b10	&kp RSHIFT
			#define _2b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _2thlN 	&none
			#define _2thlH 	&none
			#define _2thlF	&none
			
			#define _2thrF 	&none
			#define	_2thrH	&kp PSCRN
			#define _2thrN	&none

// layer 3 - f keys
	// left hand
		// top row
			#define _3t0 	&kp TAB
			#define _3t1 	&none
			#define _3t2 	&bt BT_SEL 0
			#define _3t3 	&bapp
			#define _3t4 	&out OUT_BLE
			#define _3t5 	&none
		// home row
			#define _3h0 	&amt LC(DEL) 	DEL
			#define _3h1 	&kp F3
			#define _3h2 	&kp F2
			#define _3h3 	&kp F1
			#define _3h4 	&kp F4
			#define _3h5 	&kp F10
		// bottom row
			#define _3b0 	&amt LC(BSPC) 	BSPC
			#define _3b1 	&kp LSHIFT
			#define _3b2 	&none
			#define _3b3 	&none
			#define _3b4 	&none
			#define _3b5 	&none
	
	// right hand
		// top row
			#define _3t6 	&none
			#define _3t7 	&out OUT_USB
			#define _3t8 	&bapp
			#define _3t9 	&bt BT_SEL 1
			#define _3t10 	&none
			#define _3t11 	&kp ESC
		// home row
			#define _3h6 	&kp F9
			#define _3h7 	&kp F5
			#define _3h8 	&kp F6
			#define _3h9 	&kp F7
			#define _3h10	&kp F8
			#define _3h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _3b6 	&none
			#define _3b7 	&none
			#define _3b8 	&none
			#define _3b9 	&none
			#define _3b10	&kp RSHIFT
			#define _3b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _3thlN 	&none
			#define _3thlH 	&kp F11
			#define _3thlF	&none
			
			#define _3thrF 	&none
			#define	_3thrH	&kp F12
			#define _3thrN	&none

// layer 4 - qwer
	// left hand
		// top row
			#define _4t0 	&kp TAB
			#define _4t1 	&none
			#define _4t2 	&amt F1 N1
			#define _4t3 	&amt F2 N2
			#define _4t4 	&amt F3 N3
			#define _4t5 	&amt F4 N4
		// home row
			#define _4h0 	&amt LC(DEL) 	DEL
			#define _4h1 	&kp Q
			#define _4h2 	&kp W
			#define _4h3 	&kp E
			#define _4h4 	&kp R
			#define _4h5 	&mt B G
		// bottom row
			#define _4b0 	&amt LC(BSPC) 	BSPC
			#define _4b1 	&kp LSHIFT
			#define _4b2 	&mt V X
			#define _4b3 	&kp D
			#define _4b4 	&kp F
			#define _4b5 	&none
	
	// right hand
		// top row
			#define _4t6 	&kp C_PP
			#define _4t7 	&kp C_PREV
			#define _4t8 	&kp C_NEXT
			#define _4t9 	&kp F7
			#define _4t10 	&none
			#define _4t11 	&kp ESC
		// home row
			#define _4h6 	&kp C_MUTE
			#define _4h7 	&kp F2
			#define _4h8 	&kp F3
			#define _4h9 	&kp F5
			#define _4h10	&kp F6
			#define _4h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _4b6 	&none
			#define _4b7 	&kp C_VOL_DN
			#define _4b8 	&kp C_VOL_UP
			#define _4b9 	&kp F8
			#define _4b10	&kp RSHIFT
			#define _4b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _4thlN 	&none
			#define _4thlH 	&mt LCTRL SPACE
			#define _4thlF	&none
			
			#define _4thrF 	&none
			#define	_4thrH	&none
			#define _4thrN	&none

// layer 5 - sc2
	// left hand
		// top row
			#define _5t0 	&kp TAB
			#define _5t1 	&none
			#define _5t2 	&kp W
			#define _5t3 	&kp E
			#define _5t4 	&kp R
			#define _5t5 	&kp T
		// home row
			#define _5h0 	&amt LC(DEL) 	DEL
			#define _5h1 	&kp A
			#define _5h2 	&kp S
			#define _5h3 	&kp D
			#define _5h4 	&kp F
			#define _5h5 	&kp G
		// bottom row
			#define _5b0 	&amt LC(BSPC) 	BSPC
			#define _5b1 	&kp LSHIFT
			#define _5b2 	&kp X
			#define _5b3 	&kp C
			#define _5b4 	&kp V
			#define _5b5 	&none
	
	// right hand
		// top row
			#define _5t6 	&kp C_PP
			#define _5t7 	&kp C_PREV
			#define _5t8 	&kp C_NEXT
			#define _5t9 	&kp F7
			#define _5t10 	&none
			#define _5t11 	&kp ESC
		// home row
			#define _5h6 	&kp C_MUTE
			#define _5h7 	&kp F2
			#define _5h8 	&kp F3
			#define _5h9 	&kp F5
			#define _5h10	&kp F6
			#define _5h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _5b6 	&none
			#define _5b7 	&kp C_VOL_DN
			#define _5b8 	&kp C_VOL_UP
			#define _5b9 	&kp F8
			#define _5b10	&kp RSHIFT
			#define _5b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _5thlN 	&none
			#define _5thlH 	&mt LCTRL SPACE
			#define _54thlF	&none
			
			#define _5thrF 	&none
			#define	_5thrH	&none
			#define _5thrN	&none

// layer 6 - fps
	// left hand
		// top row
			#define _6t0 	&kp TAB
			#define _6t1 	&none
			#define _6t2 	&kp Q
			#define _6t3 	&kp F
			#define _6t4 	&kp E
			#define _6t5 	&kp R
		// home row
			#define _6h0 	&amt LC(DEL) 	DEL
			#define _6h1 	&kp LSHIFT
			#define _6h2 	&socd A
			#define _6h3 	&kp W
			#define _6h4 	&socd D
			#define _6h5 	&gameXmt K G
		// bottom row
			#define _6b0 	&amt LC(BSPC) 	BSPC
			#define _6b1 	&kp LSHIFT
			#define _6b2 	&gameXmt Z X
			#define _6b3 	&kp S
			#define _6b4 	&gameXmt V C
			#define _6b5 	&none
	
	// right hand
		// top row
			#define _6t6 	&kp C_PP
			#define _6t7 	&kp C_PREV
			#define _6t8 	&kp C_NEXT
			#define _6t9 	&kp F7
			#define _6t10 	&none
			#define _6t11 	&kp ESC
		// home row
			#define _6h6 	&kp C_MUTE
			#define _6h7 	&kp F2
			#define _6h8 	&kp F3
			#define _6h9 	&kp F5
			#define _6h10	&kp F6
			#define _6h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _6b6 	&none
			#define _6b7 	&kp C_VOL_DN
			#define _6b8 	&kp C_VOL_UP
			#define _6b9 	&kp F8
			#define _6b10	&kp RSHIFT
			#define _6b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _6thlN 	&none
			#define _6thlH 	&kp SPACE
			#define _6thlF	&none
			
			#define _6thrF 	&none
			#define	_6thrH	&none
			#define _6thrN	&none
