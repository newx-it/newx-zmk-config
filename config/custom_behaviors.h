/*┌──────────────────────────────────────────────────────────┐*/
/*│*/ #include <behaviors.dtsi> 						   /*│*/
/*│*/ #include <behaviors/socd.dtsi> 					   /*│*/
/*│*/ #include <behaviors/unicode.dtsi> 				   /*│*/
/*│*/ #include <behaviors/num_word.dtsi> 				   /*│*/
/*│*/ #include <behaviors/battery_percentage_printer.dtsi> /*│*/
/*│*/ #include <dt-bindings/zmk/bt.h> 					   /*│*/
/*│*/ #include <dt-bindings/zmk/keys.h> 				   /*│*/
/*│*/ #include <dt-bindings/zmk/outputs.h> 				   /*│*/
/*│*/ #include <dt-bindings/zmk/pointing.h> 			   /*│*/
/*│*/ #define ZMK_POINTING_DEFAULT_MOVE_VAL 2000 		   /*│*/
/*└ ─────────────────────────────────────────────────────────┘*/
/ { macros { 
/*┌─── paramaterized macros ─────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ uX: uX { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param";  	 		   /*│*/
/*│*/    		#binding-cells = <1>; bindings =  													   /*│*/
/*│*/    			<&macro_tap &kp U>,  															   /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0>; }; 									   /*│*/
/*│*/ shiftXdel: shiftXdel { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; /*│*/
/*│*/ 			#binding-cells = <1>; bindings = 	 												   /*│*/
/*│*/ 				<&macro_press &kp LSHIFT>, 														   /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0>, 										   /*│*/
/*│*/ 				<&macro_release &kp LSHIFT>, 													   /*│*/
/*│*/ 				<&macro_tap &kp DEL>; };														   /*│*/
/*│*/ Xspace: Xspace { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; 	   /*│*/
/*│*/ 			#binding-cells = <1>; bindings =  													   /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0 &kp SPACE>; }; 							   /*│*/
/*│*/ 		XXleft: XXleft { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro-one-param"; /*│*/
/*│*/ 			#binding-cells = <1>; bindings =  													   /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0>, 										   /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0 &kp LEFT>; }; 							   /*│*/
/*└──────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── text insertion ─────────────────────────────────────────────────────────────────────────┐*/
/*│*/ mail: mail { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro";  		 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp G &kp M &kp A &kp I &kp L &kp DOT &kp C &kp O &kp M>; }; /*│*/
/*│*/ edu: edu { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro";  			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings =  											 /*│*/
/*│*/ 				<&macro_tap &kp I &kp S &kp U &kp DOT &kp E &kp D &kp U>; }; 			 /*│*/
/*│*/ oa: oa { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro";  			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings =  											 /*│*/
/*│*/ 				<&macro_tap &kp O &kp A>; };											 /*│*/
/*│*/ ue: ue { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp U &kp E>; };											 /*│*/
/*│*/ ueue: ueue { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp U &kp E &kp U &kp E>; };								 /*│*/
/*│*/ ust: ust { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp U &kp S &kp T>; };										 /*│*/
/*│*/ ao: ao { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 	#binding-cells = <0>; bindings = 													 /*│*/
/*│*/ 				<&macro_tap &kp A &kp O>; };											 /*│*/
/*│*/ eu: eu { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 			<&macro_tap &kp E &kp U>; };												 /*│*/
/*│*/ yi: yi { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 		#binding-cells = <0>; bindings = 												 /*│*/
/*│*/ 				<&macro_tap &kp Y &kp I>; };											 /*│*/
/*│*/ pp: pp { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp P &kp P>; };											 /*│*/
/*│*/ mm: mm { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 				 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp M &kp M>; };											 /*│*/
/*│*/ n90: n90 { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp N9 &kp N0>; };											 /*│*/
/*│*/ n09: n09 { wait-ms = <5>; tap-ms = <5>; compatible = "zmk,behavior-macro"; 			 /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 											 /*│*/
/*│*/ 				<&macro_tap &kp N0 &kp N9>; };											 /*│*/
/*└ ───────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── game ───────────────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ gameX: gameX { wait-ms = <5>; tap-ms = <30>; compatible = "zmk,behavior-macro-one-param";  			 /*│*/
/*│*/ 			#binding-cells = <1>; bindings = 															 /*│*/
/*│*/ 				<&macro_param_1to1>, <&macro_tap &kp 0>; }; 											 /*│*/
/*│*/ 		gamespaceshift: gamespaceshift { wait-ms = <3>; tap-ms = <1>; compatible = "zmk,behavior-macro"; /*│*/
/*│*/ 			#binding-cells = <0>; bindings = 															 /*│*/
/*│*/ 				<&macro_tap &kp SPACE &kp LSHIFT>; };												     /*│*/	
/*└ ───────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
}; behaviors { 
/*┌─── simple config ───────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ socd2: socd2 { compatible = "zmk,behavior-socd"; #binding-cells = <1>; bindings = <&kp>; }; /*│*/
/*│*/ uc: unicode { default-mode = <UC_MODE_WIN_COMPOSE>;	}; 									  /*│*/
/*│*/ sl: sticky_layer { release-after-ms = <550>; quick-release; };							  /*│*/
/*│*/ sk: sticky_key { release-after-ms = <750>; quick-release; };							   	  /*│*/
/*│*/ mt: mod_tap { tapping-term-ms = <200>; };												  	  /*│*/
/*└ ────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── home row mods ───────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ hml: home_row_mod_l { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced";  /*│*/
/*│*/ 		require-prior-idle-ms = <300>; tapping-term-ms = <300>; quick-tap-ms = <200>; 					  /*│*/
/*│*/		hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; };									  /*│*/
/*│*/ hmr: home_row_mod_r { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced";  /*│*/
/*│*/		require-prior-idle-ms = <300>; tapping-term-ms = <300>; quick-tap-ms = <200>; 					  /*│*/
/*│*/		hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; };									  /*│*/
/*└ ────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── layer / state manipulation ────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ num_word: num_word { compatible = "zmk,behavior-auto-layer"; #binding-cells = <1>;   					/*│*/
/*│*/		continue-list = < BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL >; ignore-numbers; };		    /*│*/
/*│*/ cmt: caps_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&kp>, <&caps_word>; display-name = "Caps-Tap"; }; 			/*│*/
/*└ ──────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── modtaps ───────────────────────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ amt: a_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 		    /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&kp>, <&kp>; display-name = "a-mod-Tap"; }; 						    /*│*/
/*│*/ bmt: b_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";		    /*│*/
/*│*/		tapping-term-ms = <225>; bindings = <&kp>, <&kp>; display-name = "b-mod-Tap"; }; 						    /*│*/
/*│*/ XXleftmt: XXleft_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&XXleft>, <&kp>; display-name = "XXleft mod-Tap"; }; 				   	/*│*/
/*│*/ Xspacemt: Xspace_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";  /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&Xspace>, <&kp>; display-name = "Xspace mod-Tap"; };				   	/*│*/
/*│*/ tabmt_r: tabmt_r { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";  	    /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&ezalttab_r>, <&kp>; display-name = "ezalttab_r modtap"; }; 			/*│*/
/*│*/ tabmt_l: tabmt_l { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";  	    /*│*/
/*│*/		tapping-term-ms = <150>; bindings = <&ezalttab_l>, <&kp>; display-name = "ezalttab_l modtap"; }; 			/*│*/
/*│*/ slt: slt { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";					/*│*/
/*│*/		tapping-term-ms = <200>; bindings = <&sl>, <&kp>; display-name = "sticky layer modtap"; };		 		    /*│*/			
/*└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── magic ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ mage_tap: mage_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";			 /*│*/
/*│*/ 		tapping-term-ms = <150>; bindings = <&mage_rev>, <&mage_rep>; display-name = "mage-mod-Tap"; };					 /*│*/
/*│*/ y_tap: y_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 					 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&yi>, <&kp>; display-name = "y-mod-Tap"; };								 /*│*/
/*│*/ p_tap: p_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 					 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&pp>, <&kp>; display-name = "p-mod-Tap"; };								 /*│*/
/*│*/ m_tap: m_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 					 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&mm>, <&kp>; display-name = "m-mod-Tap"; };								 /*│*/
/*│*/ n90_tap: n90_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 				 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&n90>, <&kp>; display-name = "n90-mod-Tap"; };								 /*│*/
/*│*/ n09_tap: n09_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 				 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&n09>, <&kp>; display-name = "m-mod-Tap"; };								 /*│*/
/*│*/ mage_a_tap: mage_a_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 		 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&ao>, <&mage_a>; display-name = "mage-a-mod-Tap"; };						 /*│*/
/*│*/ mage_e_tap: mage_e_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 		 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&mage_eu>, <&mage_e>; display-name = "mage-e-mod-Tap"; };					 /*│*/
/*│*/ mage_o_tap: mage_o_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 		 /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&oa>, <&mage_o>; display-name = "mage-o-mod-Tap"; };						 /*│*/
/*│*/ mage_u_tap: mage_u_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred";         /*│*/
/*│*/ 		tapping-term-ms = <175>; bindings = <&ue>, <&mage_u>; display-name = "mage-u-mod-Tap"; };						 /*│*/
/*│*/ mage_rev: mage_rev { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;		 /*│*/
/*│*/ 		akt_must { trigger-keys = <M>; bindings = <&ust>; };															 /*│*/
/*│*/ 		akt_que { trigger-keys = <Q>; bindings = <&mage_eu>; };															 /*│*/
/*│*/ 		akt_shift_home_del { trigger-keys = <BSPC>; bindings = < &shiftXdel HOME >; };									 /*│*/
/*│*/ 		akt_shift_end_del { trigger-keys = <DEL>; bindings = < &shiftXdel END >; };										 /*│*/
/*│*/ 		akt_ctlx { trigger-keys = <LC(A)>; bindings = < &kp LC(X) >; };													 /*│*/
/*│*/ 		akt_ctl_tw { trigger-keys = < LC(T) >; bindings = < &kp LC(W) >; };												 /*│*/
/*│*/ 		akt_ctl_wt { trigger-keys = < LC(W) >; bindings = < &kp LC(T) >; };												 /*│*/
/*│*/ 		akt_ctl_zy { trigger-keys = < LC(Z) >; bindings = < &kp LC(Y) >; };												 /*│*/
/*│*/ 		akt_ctl_yz { trigger-keys = < LC(Y) >; bindings = < &kp LC(Z) >; };												 /*│*/
/*│*/ 		akt_edu { trigger-keys = <AT>; bindings = <&edu>; }; };															 /*│*/
/*│*/ mage_rep: mage_rep { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;		 /*│*/
/*│*/ 		akt_right { trigger-keys = <RIGHT>; max-prior-idle-ms = <300>; bindings = <&kp RIGHT>; };						 /*│*/
/*│*/ 		akt_spsft { trigger-keys = <SPACE>; bindings = <&sk LSHIFT>; };													 /*│*/
/*│*/ 		akt_pt { trigger-keys = <P>; bindings = <&kp T>; };																 /*│*/
/*│*/ 		akt_mp { trigger-keys = <M>; bindings = <&kp P>; };																 /*│*/
/*│*/ 		akt_just { trigger-keys = <J>; bindings = <&ust>; };															 /*│*/
/*│*/ 		akt_que	 { trigger-keys = <Q>; bindings = <&mage_e>; };															 /*│*/
/*│*/ 		akt_ctlc { trigger-keys = <LC(A)>; bindings = <&kp LC(C)>; };													 /*│*/
/*│*/ 		akt_ctlv { trigger-keys = <LC(C) LC(X) PSCRN>; bindings = <&kp LC(V)>; };										 /*│*/
/*│*/ 		akt_mail { trigger-keys = <AT>; bindings = <&mail>; };															 /*│*/
/*│*/ 		akt_yi { trigger-keys = <Y>; max-prior-idle-ms = <300>; bindings = <&kp I>; }; };								 /*│*/
/*│*/	    akt_dt_right { trigger-keys = <LC(LG(RIGHT)) LC(LG(LEFT))>; max-prior-idle-ms = <300>; bindings = <&kp LC(LG(RIGHT))>; }; }; /*│*/
/*│*/ mage_skip: mage_skip { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&none>; skip-magic; /*│*/
/*│*/ 		akt_e_u { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <E>; bindings = <&mage_u_tap 0 0>; }; 															 /*│*/
/*│*/ 		akt_u_e { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <U>; bindings = <&mage_e_tap 0 0>; }; 															 /*│*/
/*│*/ 		akt_a_o { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <A>; bindings = <&mage_o_tap 0 0>; }; 															 /*│*/
/*│*/ 		akt_o_a { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <O>; bindings = <&mage_a_tap 0 0>; };                                                                     /*│*/
/*│*/ 		akt_s_f { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >;  		 			 	 /*│*/
/*│*/ 			prior-keys = <S>; bindings = <&kp F>; };                                                                               /*│*/
/*│*/ 		akt_f_s { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <F>; bindings = <&kp S>; };                                                                               /*│*/
/*│*/ 		akt_m_t { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 						 /*│*/
/*│*/ 			prior-keys = <M>; bindings = <&kp T>; };                                                                               /*│*/
/*│*/ 		akt_t_d { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >; 					 	 /*│*/
/*│*/ 			prior-keys = <T>; bindings = <&kp D>; };                                                                               /*│*/
/*│*/ 		akt_h_l { trigger-keys = < A B C D E F G H I J K L M N O P Q R S T U V W X Y Z SPACE >;                                  /*│*/
/*│*/ 			prior-keys = <H>; bindings = <&kp L>; }; };                                                                            /*│*/
/*│*/ mage_t: mage_t { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp T>;                         /*│*/
/*│*/		akt_left { trigger-keys = <LEFT>; max-prior-idle-ms = <300>; bindings = <&kp LEFT>; }; };                                  /*│*/
/*│*/		akt_dt_left { trigger-keys = <LC(LG(RIGHT)) LC(LG(LEFT))>; max-prior-idle-ms = <300>; bindings = <&kp LC(LG(LEFT))>; }; }; /*│*/
/*│*/ mage_u: mage_u { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp U>;					 /*│*/
/*│*/		akt_left { trigger-keys = <LC(TAB)>; max-prior-idle-ms = <300>; bindings = <&kp LC(LS(TAB))>; }; };			     /*│*/
/*│*/ mage_c: mage_c { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp C>;					 /*│*/
/*│*/		akt_left { trigger-keys = <LC(TAB)>; max-prior-idle-ms = <300>; bindings = <&kp LC(TAB)>; }; };					 /*│*/
/*│*/ mage_d: mage_d { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp D>;					 /*│*/
/*│*/		akt_left { trigger-keys = <LC(TAB)>; max-prior-idle-ms = <300>; bindings = <&kp LC(LS(TAB))>; }; };			     /*│*/
/*│*/ mage_l: mage_l { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp L>;					 /*│*/
/*│*/		akt_left { trigger-keys = <LC(TAB)>; max-prior-idle-ms = <300>; bindings = <&kp LC(TAB)>; }; };					 /*│*/
/*│*/ mage_h: mage_h { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp H>;					 /*│*/
/*│*/		akt_up { trigger-keys = <UP>; max-prior-idle-ms = <300>; bindings = <&kp UP>; }; };								 /*│*/ 
/*│*/		akt_dt_right { trigger-keys = <LC(LG(RIGHT)) LC(LG(LEFT))>; max-prior-idle-ms = <300>; bindings = <&kp LC(LG(RIGHT))>; }; }; /*│*/
/*│ mage_s: mage_s { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&amt Z S>;				 │*/
/*│		akt_down { trigger-keys = <DOWN>; max-prior-idle-ms = <300>; bindings = <&kp DOWN>; }; };						 │*/
/*│*/ mage_n: mage_n { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp N>;					 /*│*/
/*│*/		akt_right { trigger-keys = <RIGHT>; max-prior-idle-ms = <300>; bindings = <&kp RIGHT>; }; };					 /*│*/
/*│*/ mage_w: mage_w { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp W>;					 /*│*/
/*│*/		akt_gs { trigger-keys = <G>; max-prior-idle-ms = <300>; bindings = <&kp S>; }; }; 								 /*│*/
/*│*/ mage_e: mage_e { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp E>;					 /*│*/
/*│*/		akt_up { trigger-keys = <UP>; max-prior-idle-ms = <300>; bindings = <&kp UP>; };								 /*│*/
/*│*/		akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX E>; }; };								 /*│*/
/*│*/		akt_dt_left { trigger-keys = <LC(LG(RIGHT)) LC(LG(LEFT))>; max-prior-idle-ms = <300>; bindings = <&kp LC(LG(LEFT))>; }; }; /*│*/
/*│*/ mage_eu: mage_eu { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&eu>;					 /*│*/
/*│*/		akt_up { trigger-keys = <UP>; max-prior-idle-ms = <300>; bindings = <&kp UP>; };								 /*│*/
/*│*/		akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&ueue>; }; };								 /*│*/
/*│*/ mage_a: mage_a { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp A>;					 /*│*/
/*│*/		akt_down { trigger-keys = <DOWN>; max-prior-idle-ms = <300>; bindings = <&kp DOWN>; };							 /*│*/
/*│*/		akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX A>; }; };								 /*│*/ 
/*│*/ mage_i: mage_i { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp I>;					 /*│*/
/*│*/		akt_left { trigger-keys = <LEFT>; max-prior-idle-ms = <300>; bindings = <&kp LEFT>; };							 /*│*/
/*│*/		akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX I>; }; };								 /*│*/
/*│*/ mage_o: mage_o { compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp O>;					 /*│*/
/*│*/		akt_ue { trigger-keys = <Q>; max-prior-idle-ms = <300>; bindings = <&uX O>; }; };								 /*│*/
/*└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── fun stuff ───────────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ ezalttab_r: ezalttab_r { compatible = "zmk,behavior-tri-state"; label = "ezat_r"; #binding-cells = <0>; /*│*/
/*│*/ 		bindings = <&kt LALT>, <&kp TAB>, <&kt LALT>; timeout-ms = <750>; };                              /*│*/
/*│*/ ezalttab_l: ezalttab_l { compatible = "zmk,behavior-tri-state"; label = "ezat_l"; #binding-cells = <0>; /*│*/
/*│*/ 		bindings = <&kt LALT>, <&kp LS(TAB)>, <&kt LALT>; timeout-ms = <750>; };                          /*│*/
/*│*/ deadenter: deadenter { compatible = "zmk,behavior-mod-morph"; #binding-cells = <0>;                     /*│*/
/*│*/ 		bindings = <&kp ENTER>, <&kp F24>; mods = <(MOD_LALT)>; };                                        /*│*/
/*└─────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
/*┌─── game stuff ──────────────────────────────────────────────────────────────────────────────────────────────────────┐*/
/*│*/ gameXmt: gameX_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; /*│*/
/*│*/ 		tapping-term-ms = <150>; bindings = <&kp>, <&gameX>; display-name = "gameX mod-Tap"; }; };   			  /*│*/
/*└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘*/
}; 
