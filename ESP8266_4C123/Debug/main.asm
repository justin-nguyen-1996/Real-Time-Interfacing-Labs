;******************************************************************************
;* TI ARM C/C++ Codegen                                             PC v5.2.4 *
;* Date/Time created: Sat Feb 06 22:51:21 2016                                *
;******************************************************************************
	.compiler_opts --abi=eabi --arm_vmrs_si_workaround=off --code_state=16 --diag_wrap=off --disable_dual_state --embedded_constants=on --endian=little --float_support=FPv4SPD16 --hll_source=on --object_format=elf --silicon_version=7M4 --symdebug:dwarf --symdebug:dwarf_version=3 --unaligned_access=on 
	.thumb

$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("../main.c")
	.dwattr $C$DW$CU, DW_AT_producer("TI TI ARM C/C++ Codegen PC v5.2.4 Copyright (c) 1996-2015 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\Dropbox\ArmBook\LaunchPad\ValvanoWareTM4C123\ESP8266_4C123\Debug")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("printf")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("printf")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0xf5)
	.dwattr $C$DW$1, DW_AT_decl_column(0x19)
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$58)
$C$DW$3	.dwtag  DW_TAG_unspecified_parameters
	.dwendtag $C$DW$1


$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("PLL_Init")
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("PLL_Init")
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_external
	.dwattr $C$DW$4, DW_AT_decl_file("..\pll.h")
	.dwattr $C$DW$4, DW_AT_decl_line(0x1f)
	.dwattr $C$DW$4, DW_AT_decl_column(0x06)
$C$DW$5	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$29)
	.dwendtag $C$DW$4


$C$DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InChar")
	.dwattr $C$DW$6, DW_AT_TI_symbol_name("UART_InChar")
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$6, DW_AT_declaration
	.dwattr $C$DW$6, DW_AT_external
	.dwattr $C$DW$6, DW_AT_decl_file("..\UART.h")
	.dwattr $C$DW$6, DW_AT_decl_line(0x31)
	.dwattr $C$DW$6, DW_AT_decl_column(0x06)

$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InCharNonBlock")
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("UART_InCharNonBlock")
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_external
	.dwattr $C$DW$7, DW_AT_decl_file("..\UART.h")
	.dwattr $C$DW$7, DW_AT_decl_line(0x37)
	.dwattr $C$DW$7, DW_AT_decl_column(0x06)

$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("Output_Init")
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("Output_Init")
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_external
	.dwattr $C$DW$8, DW_AT_decl_file("..\UART.h")
	.dwattr $C$DW$8, DW_AT_decl_line(0x83)
	.dwattr $C$DW$8, DW_AT_decl_column(0x06)

$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_Init")
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("ESP8266_Init")
	.dwattr $C$DW$9, DW_AT_declaration
	.dwattr $C$DW$9, DW_AT_external
	.dwattr $C$DW$9, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$9, DW_AT_decl_line(0x20)
	.dwattr $C$DW$9, DW_AT_decl_column(0x06)
$C$DW$10	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$10, DW_AT_type(*$C$DW$T$29)
	.dwendtag $C$DW$9


$C$DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_InitUART")
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("ESP8266_InitUART")
	.dwattr $C$DW$11, DW_AT_declaration
	.dwattr $C$DW$11, DW_AT_external
	.dwattr $C$DW$11, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$11, DW_AT_decl_line(0x28)
	.dwattr $C$DW$11, DW_AT_decl_column(0x06)
$C$DW$12	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$12, DW_AT_type(*$C$DW$T$29)
$C$DW$13	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$11


$C$DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_GetVersionNumber")
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("ESP8266_GetVersionNumber")
	.dwattr $C$DW$14, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$14, DW_AT_declaration
	.dwattr $C$DW$14, DW_AT_external
	.dwattr $C$DW$14, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$14, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$14, DW_AT_decl_column(0x05)

$C$DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_CloseTCPConnection")
	.dwattr $C$DW$15, DW_AT_TI_symbol_name("ESP8266_CloseTCPConnection")
	.dwattr $C$DW$15, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$15, DW_AT_declaration
	.dwattr $C$DW$15, DW_AT_external
	.dwattr $C$DW$15, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$15, DW_AT_decl_line(0x46)
	.dwattr $C$DW$15, DW_AT_decl_column(0x05)

$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_MakeTCPConnection")
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("ESP8266_MakeTCPConnection")
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$16, DW_AT_declaration
	.dwattr $C$DW$16, DW_AT_external
	.dwattr $C$DW$16, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$16, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$16, DW_AT_decl_column(0x05)
$C$DW$17	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$40)
	.dwendtag $C$DW$16


$C$DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_SendTCP")
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("ESP8266_SendTCP")
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$18, DW_AT_declaration
	.dwattr $C$DW$18, DW_AT_external
	.dwattr $C$DW$18, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$18, DW_AT_decl_line(0x70)
	.dwattr $C$DW$18, DW_AT_decl_column(0x05)
$C$DW$19	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$19, DW_AT_type(*$C$DW$T$40)
	.dwendtag $C$DW$18


$C$DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_GetStatus")
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("ESP8266_GetStatus")
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$20, DW_AT_declaration
	.dwattr $C$DW$20, DW_AT_external
	.dwattr $C$DW$20, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$20, DW_AT_decl_line(0x7c)
	.dwattr $C$DW$20, DW_AT_decl_column(0x05)

$C$DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_EnableRXInterrupt")
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("ESP8266_EnableRXInterrupt")
	.dwattr $C$DW$21, DW_AT_declaration
	.dwattr $C$DW$21, DW_AT_external
	.dwattr $C$DW$21, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$21, DW_AT_decl_line(0x82)
	.dwattr $C$DW$21, DW_AT_decl_column(0x06)

$C$DW$22	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266_PrintChar")
	.dwattr $C$DW$22, DW_AT_TI_symbol_name("ESP8266_PrintChar")
	.dwattr $C$DW$22, DW_AT_declaration
	.dwattr $C$DW$22, DW_AT_external
	.dwattr $C$DW$22, DW_AT_decl_file("..\esp8266.h")
	.dwattr $C$DW$22, DW_AT_decl_line(0x8f)
	.dwattr $C$DW$22, DW_AT_decl_column(0x06)
$C$DW$23	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$23, DW_AT_type(*$C$DW$T$6)
	.dwendtag $C$DW$22


$C$DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("LED_Init")
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("LED_Init")
	.dwattr $C$DW$24, DW_AT_declaration
	.dwattr $C$DW$24, DW_AT_external
	.dwattr $C$DW$24, DW_AT_decl_file("..\LED.h")
	.dwattr $C$DW$24, DW_AT_decl_line(0x2a)
	.dwattr $C$DW$24, DW_AT_decl_column(0x06)

$C$DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("Board_Input")
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("Board_Input")
	.dwattr $C$DW$25, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$25, DW_AT_declaration
	.dwattr $C$DW$25, DW_AT_external
	.dwattr $C$DW$25, DW_AT_decl_file("..\LED.h")
	.dwattr $C$DW$25, DW_AT_decl_line(0x34)
	.dwattr $C$DW$25, DW_AT_decl_column(0x0a)

$C$DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("LED_RedToggle")
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("LED_RedToggle")
	.dwattr $C$DW$26, DW_AT_declaration
	.dwattr $C$DW$26, DW_AT_external
	.dwattr $C$DW$26, DW_AT_decl_file("..\LED.h")
	.dwattr $C$DW$26, DW_AT_decl_line(0x47)
	.dwattr $C$DW$26, DW_AT_decl_column(0x06)

$C$DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("LED_GreenOn")
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("LED_GreenOn")
	.dwattr $C$DW$27, DW_AT_declaration
	.dwattr $C$DW$27, DW_AT_external
	.dwattr $C$DW$27, DW_AT_decl_file("..\LED.h")
	.dwattr $C$DW$27, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$27, DW_AT_decl_column(0x06)

$C$DW$28	.dwtag  DW_TAG_subprogram, DW_AT_name("LED_GreenOff")
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("LED_GreenOff")
	.dwattr $C$DW$28, DW_AT_declaration
	.dwattr $C$DW$28, DW_AT_external
	.dwattr $C$DW$28, DW_AT_decl_file("..\LED.h")
	.dwattr $C$DW$28, DW_AT_decl_line(0x60)
	.dwattr $C$DW$28, DW_AT_decl_column(0x06)

$C$DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("DisableInterrupts")
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("DisableInterrupts")
	.dwattr $C$DW$29, DW_AT_declaration
	.dwattr $C$DW$29, DW_AT_external
	.dwattr $C$DW$29, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$29, DW_AT_decl_line(0x21)
	.dwattr $C$DW$29, DW_AT_decl_column(0x06)

$C$DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("EnableInterrupts")
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("EnableInterrupts")
	.dwattr $C$DW$30, DW_AT_declaration
	.dwattr $C$DW$30, DW_AT_external
	.dwattr $C$DW$30, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$30, DW_AT_decl_line(0x22)
	.dwattr $C$DW$30, DW_AT_decl_column(0x06)

$C$DW$31	.dwtag  DW_TAG_subprogram, DW_AT_name("ESP8266SendCommand")
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("ESP8266SendCommand")
	.dwattr $C$DW$31, DW_AT_declaration
	.dwattr $C$DW$31, DW_AT_external
	.dwattr $C$DW$31, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$31, DW_AT_decl_line(0x43)
	.dwattr $C$DW$31, DW_AT_decl_column(0x06)
$C$DW$32	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$32, DW_AT_type(*$C$DW$T$40)
	.dwendtag $C$DW$31

	.global	Fetch
	.sect	".data:Fetch", RW
	.clink
	.align	1
	.elfsym	Fetch,SYM_SIZE(120)
Fetch:
	.bits	71,8			; Fetch[0] @ 0
	.bits	69,8			; Fetch[1] @ 8
	.bits	84,8			; Fetch[2] @ 16
	.bits	32,8			; Fetch[3] @ 24
	.bits	47,8			; Fetch[4] @ 32
	.bits	100,8			; Fetch[5] @ 40
	.bits	97,8			; Fetch[6] @ 48
	.bits	116,8			; Fetch[7] @ 56
	.bits	97,8			; Fetch[8] @ 64
	.bits	47,8			; Fetch[9] @ 72
	.bits	50,8			; Fetch[10] @ 80
	.bits	46,8			; Fetch[11] @ 88
	.bits	53,8			; Fetch[12] @ 96
	.bits	47,8			; Fetch[13] @ 104
	.bits	119,8			; Fetch[14] @ 112
	.bits	101,8			; Fetch[15] @ 120
	.bits	97,8			; Fetch[16] @ 128
	.bits	116,8			; Fetch[17] @ 136
	.bits	104,8			; Fetch[18] @ 144
	.bits	101,8			; Fetch[19] @ 152
	.bits	114,8			; Fetch[20] @ 160
	.bits	63,8			; Fetch[21] @ 168
	.bits	113,8			; Fetch[22] @ 176
	.bits	61,8			; Fetch[23] @ 184
	.bits	65,8			; Fetch[24] @ 192
	.bits	117,8			; Fetch[25] @ 200
	.bits	115,8			; Fetch[26] @ 208
	.bits	116,8			; Fetch[27] @ 216
	.bits	105,8			; Fetch[28] @ 224
	.bits	110,8			; Fetch[29] @ 232
	.bits	37,8			; Fetch[30] @ 240
	.bits	50,8			; Fetch[31] @ 248
	.bits	48,8			; Fetch[32] @ 256
	.bits	84,8			; Fetch[33] @ 264
	.bits	101,8			; Fetch[34] @ 272
	.bits	120,8			; Fetch[35] @ 280
	.bits	97,8			; Fetch[36] @ 288
	.bits	115,8			; Fetch[37] @ 296
	.bits	38,8			; Fetch[38] @ 304
	.bits	65,8			; Fetch[39] @ 312
	.bits	80,8			; Fetch[40] @ 320
	.bits	80,8			; Fetch[41] @ 328
	.bits	73,8			; Fetch[42] @ 336
	.bits	68,8			; Fetch[43] @ 344
	.bits	61,8			; Fetch[44] @ 352
	.bits	49,8			; Fetch[45] @ 360
	.bits	50,8			; Fetch[46] @ 368
	.bits	51,8			; Fetch[47] @ 376
	.bits	52,8			; Fetch[48] @ 384
	.bits	53,8			; Fetch[49] @ 392
	.bits	54,8			; Fetch[50] @ 400
	.bits	55,8			; Fetch[51] @ 408
	.bits	56,8			; Fetch[52] @ 416
	.bits	57,8			; Fetch[53] @ 424
	.bits	48,8			; Fetch[54] @ 432
	.bits	97,8			; Fetch[55] @ 440
	.bits	98,8			; Fetch[56] @ 448
	.bits	99,8			; Fetch[57] @ 456
	.bits	100,8			; Fetch[58] @ 464
	.bits	101,8			; Fetch[59] @ 472
	.bits	102,8			; Fetch[60] @ 480
	.bits	49,8			; Fetch[61] @ 488
	.bits	50,8			; Fetch[62] @ 496
	.bits	51,8			; Fetch[63] @ 504
	.bits	52,8			; Fetch[64] @ 512
	.bits	53,8			; Fetch[65] @ 520
	.bits	54,8			; Fetch[66] @ 528
	.bits	55,8			; Fetch[67] @ 536
	.bits	56,8			; Fetch[68] @ 544
	.bits	57,8			; Fetch[69] @ 552
	.bits	48,8			; Fetch[70] @ 560
	.bits	97,8			; Fetch[71] @ 568
	.bits	98,8			; Fetch[72] @ 576
	.bits	99,8			; Fetch[73] @ 584
	.bits	100,8			; Fetch[74] @ 592
	.bits	101,8			; Fetch[75] @ 600
	.bits	102,8			; Fetch[76] @ 608
	.bits	32,8			; Fetch[77] @ 616
	.bits	72,8			; Fetch[78] @ 624
	.bits	84,8			; Fetch[79] @ 632
	.bits	84,8			; Fetch[80] @ 640
	.bits	80,8			; Fetch[81] @ 648
	.bits	47,8			; Fetch[82] @ 656
	.bits	49,8			; Fetch[83] @ 664
	.bits	46,8			; Fetch[84] @ 672
	.bits	49,8			; Fetch[85] @ 680
	.bits	13,8			; Fetch[86] @ 688
	.bits	10,8			; Fetch[87] @ 696
	.bits	72,8			; Fetch[88] @ 704
	.bits	111,8			; Fetch[89] @ 712
	.bits	115,8			; Fetch[90] @ 720
	.bits	116,8			; Fetch[91] @ 728
	.bits	58,8			; Fetch[92] @ 736
	.bits	97,8			; Fetch[93] @ 744
	.bits	112,8			; Fetch[94] @ 752
	.bits	105,8			; Fetch[95] @ 760
	.bits	46,8			; Fetch[96] @ 768
	.bits	111,8			; Fetch[97] @ 776
	.bits	112,8			; Fetch[98] @ 784
	.bits	101,8			; Fetch[99] @ 792
	.bits	110,8			; Fetch[100] @ 800
	.bits	119,8			; Fetch[101] @ 808
	.bits	101,8			; Fetch[102] @ 816
	.bits	97,8			; Fetch[103] @ 824
	.bits	116,8			; Fetch[104] @ 832
	.bits	104,8			; Fetch[105] @ 840
	.bits	101,8			; Fetch[106] @ 848
	.bits	114,8			; Fetch[107] @ 856
	.bits	109,8			; Fetch[108] @ 864
	.bits	97,8			; Fetch[109] @ 872
	.bits	112,8			; Fetch[110] @ 880
	.bits	46,8			; Fetch[111] @ 888
	.bits	111,8			; Fetch[112] @ 896
	.bits	114,8			; Fetch[113] @ 904
	.bits	103,8			; Fetch[114] @ 912
	.bits	13,8			; Fetch[115] @ 920
	.bits	10,8			; Fetch[116] @ 928
	.bits	13,8			; Fetch[117] @ 936
	.bits	10,8			; Fetch[118] @ 944
	.bits	0,8			; Fetch[119] @ 952

$C$DW$33	.dwtag  DW_TAG_variable, DW_AT_name("Fetch")
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("Fetch")
	.dwattr $C$DW$33, DW_AT_location[DW_OP_addr Fetch]
	.dwattr $C$DW$33, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$33, DW_AT_external
	.dwattr $C$DW$33, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$33, DW_AT_decl_line(0x27)
	.dwattr $C$DW$33, DW_AT_decl_column(0x06)
;	C:\ti\ccsv6\tools\compiler\ti-cgt-arm_5.2.4\bin\armacpia.exe -@C:\\Users\\VALVAN~1\\AppData\\Local\\Temp\\2038812 
	.sect	".text"
	.clink
	.thumbfunc main
	.thumb
	.global	main

$C$DW$34	.dwtag  DW_TAG_subprogram, DW_AT_name("main")
	.dwattr $C$DW$34, DW_AT_low_pc(main)
	.dwattr $C$DW$34, DW_AT_high_pc(0x00)
	.dwattr $C$DW$34, DW_AT_TI_symbol_name("main")
	.dwattr $C$DW$34, DW_AT_external
	.dwattr $C$DW$34, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$34, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$34, DW_AT_TI_begin_line(0x2c)
	.dwattr $C$DW$34, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$34, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$34, DW_AT_decl_line(0x2c)
	.dwattr $C$DW$34, DW_AT_decl_column(0x05)
	.dwattr $C$DW$34, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../main.c",line 44,column 15,is_stmt,address main,isa 1

	.dwfde $C$DW$CIE, main
;----------------------------------------------------------------------
;  44 | int main(void){                                                        
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: main                                                       *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************
main:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwpsn	file "../main.c",line 45,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  45 | DisableInterrupts();                                                   
;----------------------------------------------------------------------
$C$DW$35	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$35, DW_AT_low_pc(0x00)
	.dwattr $C$DW$35, DW_AT_name("DisableInterrupts")
	.dwattr $C$DW$35, DW_AT_TI_call
        BL        DisableInterrupts     ; [DPU_3_PIPE] |45| 
        ; CALL OCCURS {DisableInterrupts }  ; [] |45| 
	.dwpsn	file "../main.c",line 46,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  46 | PLL_Init(Bus80MHz);                                                    
;----------------------------------------------------------------------
        MOVS      A1, #4                ; [DPU_3_PIPE] |46| 
$C$DW$36	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$36, DW_AT_low_pc(0x00)
	.dwattr $C$DW$36, DW_AT_name("PLL_Init")
	.dwattr $C$DW$36, DW_AT_TI_call
        BL        PLL_Init              ; [DPU_3_PIPE] |46| 
        ; CALL OCCURS {PLL_Init }        ; [] |46| 
	.dwpsn	file "../main.c",line 47,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  47 | LED_Init();                                                            
;----------------------------------------------------------------------
$C$DW$37	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$37, DW_AT_low_pc(0x00)
	.dwattr $C$DW$37, DW_AT_name("LED_Init")
	.dwattr $C$DW$37, DW_AT_TI_call
        BL        LED_Init              ; [DPU_3_PIPE] |47| 
        ; CALL OCCURS {LED_Init }        ; [] |47| 
	.dwpsn	file "../main.c",line 48,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  48 | Output_Init();       // UART0 only used for debugging                  
;----------------------------------------------------------------------
$C$DW$38	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$38, DW_AT_low_pc(0x00)
	.dwattr $C$DW$38, DW_AT_name("Output_Init")
	.dwattr $C$DW$38, DW_AT_TI_call
        BL        Output_Init           ; [DPU_3_PIPE] |48| 
        ; CALL OCCURS {Output_Init }     ; [] |48| 
	.dwpsn	file "../main.c",line 49,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  49 | printf("\n\r-----------\n\rSystem starting...\n\r");                   
;----------------------------------------------------------------------
        ADR       A1, $C$SL1            ; [DPU_3_PIPE] |49| 
$C$DW$39	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$39, DW_AT_low_pc(0x00)
	.dwattr $C$DW$39, DW_AT_name("printf")
	.dwattr $C$DW$39, DW_AT_TI_call
        BL        printf                ; [DPU_3_PIPE] |49| 
        ; CALL OCCURS {printf }          ; [] |49| 
	.dwpsn	file "../main.c",line 50,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  50 | ESP8266_Init(115200);      // connect to access point, set up as client
;----------------------------------------------------------------------
        MOV       A1, #115200           ; [DPU_3_PIPE] |50| 
$C$DW$40	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$40, DW_AT_low_pc(0x00)
	.dwattr $C$DW$40, DW_AT_name("ESP8266_Init")
	.dwattr $C$DW$40, DW_AT_TI_call
        BL        ESP8266_Init          ; [DPU_3_PIPE] |50| 
        ; CALL OCCURS {ESP8266_Init }    ; [] |50| 
	.dwpsn	file "../main.c",line 51,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  51 | ESP8266_GetVersionNumber();                                            
;----------------------------------------------------------------------
$C$DW$41	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$41, DW_AT_low_pc(0x00)
	.dwattr $C$DW$41, DW_AT_name("ESP8266_GetVersionNumber")
	.dwattr $C$DW$41, DW_AT_TI_call
        BL        ESP8266_GetVersionNumber ; [DPU_3_PIPE] |51| 
        ; CALL OCCURS {ESP8266_GetVersionNumber }  ; [] |51| 
	.dwpsn	file "../main.c",line 52,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
;  52 | while(1){                                                              
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L1||
;*
;*   Loop source line                : 52
;*   Loop closing brace source line  : 63
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L1||:    
	.dwpsn	file "../main.c",line 53,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  53 | ESP8266_GetStatus();                                                   
;----------------------------------------------------------------------
$C$DW$42	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$42, DW_AT_low_pc(0x00)
	.dwattr $C$DW$42, DW_AT_name("ESP8266_GetStatus")
	.dwattr $C$DW$42, DW_AT_TI_call
        BL        ESP8266_GetStatus     ; [DPU_3_PIPE] |53| 
        ; CALL OCCURS {ESP8266_GetStatus }  ; [] |53| 
	.dwpsn	file "../main.c",line 54,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  54 | if(ESP8266_MakeTCPConnection("openweathermap.org")){ // open socket in
;     | server                                                                 
;----------------------------------------------------------------------
        ADR       A1, $C$SL2            ; [DPU_3_PIPE] |54| 
$C$DW$43	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$43, DW_AT_low_pc(0x00)
	.dwattr $C$DW$43, DW_AT_name("ESP8266_MakeTCPConnection")
	.dwattr $C$DW$43, DW_AT_TI_call
        BL        ESP8266_MakeTCPConnection ; [DPU_3_PIPE] |54| 
        ; CALL OCCURS {ESP8266_MakeTCPConnection }  ; [] |54| 
        CBZ       A1, ||$C$L2||         ; [] 
        ; BRANCHCC OCCURS {||$C$L2||}    ; [] |54| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../main.c",line 55,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
;  55 | LED_GreenOn();                                                         
;----------------------------------------------------------------------
$C$DW$44	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$44, DW_AT_low_pc(0x00)
	.dwattr $C$DW$44, DW_AT_name("LED_GreenOn")
	.dwattr $C$DW$44, DW_AT_TI_call
        BL        LED_GreenOn           ; [DPU_3_PIPE] |55| 
        ; CALL OCCURS {LED_GreenOn }     ; [] |55| 
	.dwpsn	file "../main.c",line 56,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
;  56 | ESP8266_SendTCP(Fetch);                                                
;----------------------------------------------------------------------
        LDR       A1, $C$CON1           ; [DPU_3_PIPE] |56| 
$C$DW$45	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$45, DW_AT_low_pc(0x00)
	.dwattr $C$DW$45, DW_AT_name("ESP8266_SendTCP")
	.dwattr $C$DW$45, DW_AT_TI_call
        BL        ESP8266_SendTCP       ; [DPU_3_PIPE] |56| 
        ; CALL OCCURS {ESP8266_SendTCP }  ; [] |56| 
;* --------------------------------------------------------------------------*
||$C$L2||:    
	.dwpsn	file "../main.c",line 58,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  58 | ESP8266_CloseTCPConnection();                                          
;----------------------------------------------------------------------
$C$DW$46	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$46, DW_AT_low_pc(0x00)
	.dwattr $C$DW$46, DW_AT_name("ESP8266_CloseTCPConnection")
	.dwattr $C$DW$46, DW_AT_TI_call
        BL        ESP8266_CloseTCPConnection ; [DPU_3_PIPE] |58| 
        ; CALL OCCURS {ESP8266_CloseTCPConnection }  ; [] |58| 
	.dwpsn	file "../main.c",line 59,column 11,is_stmt,isa 1
;----------------------------------------------------------------------
;  59 | while(Board_Input()==0){// wait for touch                              
;  60 | };                                                                     
;----------------------------------------------------------------------
$C$DW$47	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$47, DW_AT_low_pc(0x00)
	.dwattr $C$DW$47, DW_AT_name("Board_Input")
	.dwattr $C$DW$47, DW_AT_TI_call
        BL        Board_Input           ; [DPU_3_PIPE] |59| 
        ; CALL OCCURS {Board_Input }     ; [] |59| 
        CBNZ      A1, ||$C$L4||         ; [] 
        ; BRANCHCC OCCURS {||$C$L4||}    ; [] |59| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L3||
;*
;*   Loop source line                : 59
;*   Loop closing brace source line  : 60
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L3||:    
$C$DW$48	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$48, DW_AT_low_pc(0x00)
	.dwattr $C$DW$48, DW_AT_name("Board_Input")
	.dwattr $C$DW$48, DW_AT_TI_call
        BL        Board_Input           ; [DPU_3_PIPE] |59| 
        ; CALL OCCURS {Board_Input }     ; [] |59| 
        CMP       A1, #0                ; [DPU_3_PIPE] |59| 
        BEQ       ||$C$L3||             ; [DPU_3_PIPE] |59| 
        ; BRANCHCC OCCURS {||$C$L3||}    ; [] |59| 
;* --------------------------------------------------------------------------*
||$C$L4||:    
	.dwpsn	file "../main.c",line 61,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  61 | LED_GreenOff();                                                        
;----------------------------------------------------------------------
$C$DW$49	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$49, DW_AT_low_pc(0x00)
	.dwattr $C$DW$49, DW_AT_name("LED_GreenOff")
	.dwattr $C$DW$49, DW_AT_TI_call
        BL        LED_GreenOff          ; [DPU_3_PIPE] |61| 
        ; CALL OCCURS {LED_GreenOff }    ; [] |61| 
	.dwpsn	file "../main.c",line 62,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  62 | LED_RedToggle();                                                       
;----------------------------------------------------------------------
$C$DW$50	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$50, DW_AT_low_pc(0x00)
	.dwattr $C$DW$50, DW_AT_name("LED_RedToggle")
	.dwattr $C$DW$50, DW_AT_TI_call
        BL        LED_RedToggle         ; [DPU_3_PIPE] |62| 
        ; CALL OCCURS {LED_RedToggle }   ; [] |62| 
	.dwpsn	file "../main.c",line 52,column 9,is_stmt,isa 1
        B         ||$C$L1||             ; [DPU_3_PIPE] |52| 
        ; BRANCH OCCURS {||$C$L1||}      ; [] |52| 
;* --------------------------------------------------------------------------*
	.dwattr $C$DW$34, DW_AT_TI_end_file("../main.c")
	.dwattr $C$DW$34, DW_AT_TI_end_line(0x40)
	.dwattr $C$DW$34, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$34

	.sect	".text"
	.clink
	.thumbfunc main2
	.thumb
	.global	main2

$C$DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("main2")
	.dwattr $C$DW$51, DW_AT_low_pc(main2)
	.dwattr $C$DW$51, DW_AT_high_pc(0x00)
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("main2")
	.dwattr $C$DW$51, DW_AT_external
	.dwattr $C$DW$51, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$51, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$51, DW_AT_TI_begin_line(0x44)
	.dwattr $C$DW$51, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$51, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$51, DW_AT_decl_line(0x44)
	.dwattr $C$DW$51, DW_AT_decl_column(0x05)
	.dwattr $C$DW$51, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../main.c",line 68,column 16,is_stmt,address main2,isa 1

	.dwfde $C$DW$CIE, main2
;----------------------------------------------------------------------
;  68 | int main2(void){  char data;                                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: main2                                                      *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
main2:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$52	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$52, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$52, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$52, DW_AT_location[DW_OP_breg13 0]
	.dwpsn	file "../main.c",line 69,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  69 | DisableInterrupts();                                                   
;----------------------------------------------------------------------
$C$DW$53	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$53, DW_AT_low_pc(0x00)
	.dwattr $C$DW$53, DW_AT_name("DisableInterrupts")
	.dwattr $C$DW$53, DW_AT_TI_call
        BL        DisableInterrupts     ; [DPU_3_PIPE] |69| 
        ; CALL OCCURS {DisableInterrupts }  ; [] |69| 
	.dwpsn	file "../main.c",line 70,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  70 | PLL_Init(Bus80MHz);                                                    
;----------------------------------------------------------------------
        MOVS      A1, #4                ; [DPU_3_PIPE] |70| 
$C$DW$54	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$54, DW_AT_low_pc(0x00)
	.dwattr $C$DW$54, DW_AT_name("PLL_Init")
	.dwattr $C$DW$54, DW_AT_TI_call
        BL        PLL_Init              ; [DPU_3_PIPE] |70| 
        ; CALL OCCURS {PLL_Init }        ; [] |70| 
	.dwpsn	file "../main.c",line 71,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  71 | LED_Init();                                                            
;----------------------------------------------------------------------
$C$DW$55	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$55, DW_AT_low_pc(0x00)
	.dwattr $C$DW$55, DW_AT_name("LED_Init")
	.dwattr $C$DW$55, DW_AT_TI_call
        BL        LED_Init              ; [DPU_3_PIPE] |71| 
        ; CALL OCCURS {LED_Init }        ; [] |71| 
	.dwpsn	file "../main.c",line 72,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  72 | Output_Init();       // UART0 as a terminal                            
;----------------------------------------------------------------------
$C$DW$56	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$56, DW_AT_low_pc(0x00)
	.dwattr $C$DW$56, DW_AT_name("Output_Init")
	.dwattr $C$DW$56, DW_AT_TI_call
        BL        Output_Init           ; [DPU_3_PIPE] |72| 
        ; CALL OCCURS {Output_Init }     ; [] |72| 
	.dwpsn	file "../main.c",line 73,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  73 | printf("\n\r-----------\n\rSystem starting at 9600 baud...\n\r");      
;  74 | //  ESP8266_Init(38400);                                               
;----------------------------------------------------------------------
        ADR       A1, $C$SL3            ; [DPU_3_PIPE] |73| 
$C$DW$57	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$57, DW_AT_low_pc(0x00)
	.dwattr $C$DW$57, DW_AT_name("printf")
	.dwattr $C$DW$57, DW_AT_TI_call
        BL        printf                ; [DPU_3_PIPE] |73| 
        ; CALL OCCURS {printf }          ; [] |73| 
	.dwpsn	file "../main.c",line 75,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  75 | ESP8266_InitUART(9600,true);                                           
;----------------------------------------------------------------------
        MOV       A1, #9600             ; [DPU_3_PIPE] |75| 
        MOVS      A2, #1                ; [DPU_3_PIPE] |75| 
$C$DW$58	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$58, DW_AT_low_pc(0x00)
	.dwattr $C$DW$58, DW_AT_name("ESP8266_InitUART")
	.dwattr $C$DW$58, DW_AT_TI_call
        BL        ESP8266_InitUART      ; [DPU_3_PIPE] |75| 
        ; CALL OCCURS {ESP8266_InitUART }  ; [] |75| 
	.dwpsn	file "../main.c",line 76,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  76 | ESP8266_EnableRXInterrupt();                                           
;----------------------------------------------------------------------
$C$DW$59	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$59, DW_AT_low_pc(0x00)
	.dwattr $C$DW$59, DW_AT_name("ESP8266_EnableRXInterrupt")
	.dwattr $C$DW$59, DW_AT_TI_call
        BL        ESP8266_EnableRXInterrupt ; [DPU_3_PIPE] |76| 
        ; CALL OCCURS {ESP8266_EnableRXInterrupt }  ; [] |76| 
	.dwpsn	file "../main.c",line 77,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  77 | EnableInterrupts();                                                    
;----------------------------------------------------------------------
$C$DW$60	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$60, DW_AT_low_pc(0x00)
	.dwattr $C$DW$60, DW_AT_name("EnableInterrupts")
	.dwattr $C$DW$60, DW_AT_TI_call
        BL        EnableInterrupts      ; [DPU_3_PIPE] |77| 
        ; CALL OCCURS {EnableInterrupts }  ; [] |77| 
	.dwpsn	file "../main.c",line 78,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  78 | ESP8266SendCommand("AT+RST\r\n");                                      
;----------------------------------------------------------------------
        ADR       A1, $C$SL4            ; [DPU_3_PIPE] |78| 
$C$DW$61	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$61, DW_AT_low_pc(0x00)
	.dwattr $C$DW$61, DW_AT_name("ESP8266SendCommand")
	.dwattr $C$DW$61, DW_AT_TI_call
        BL        ESP8266SendCommand    ; [DPU_3_PIPE] |78| 
        ; CALL OCCURS {ESP8266SendCommand }  ; [] |78| 
	.dwpsn	file "../main.c",line 79,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  79 | data = UART_InChar();                                                  
;  80 | //  ESP8266SendCommand("AT+UART=115200,8,1,0,3\r\n");                  
;  81 | //  data = UART_InChar();                                              
;  82 | //  ESP8266_InitUART(115200,true);                                     
;  83 | //  data = UART_InChar();                                              
;----------------------------------------------------------------------
$C$DW$62	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$62, DW_AT_low_pc(0x00)
	.dwattr $C$DW$62, DW_AT_name("UART_InChar")
	.dwattr $C$DW$62, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |79| 
        ; CALL OCCURS {UART_InChar }     ; [] |79| 
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |79| 
	.dwpsn	file "../main.c",line 85,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
;  85 | while(1){                                                              
;  86 | // echo data back and forth                                            
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L5||
;*
;*   Loop source line                : 85
;*   Loop closing brace source line  : 91
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L5||:    
	.dwpsn	file "../main.c",line 87,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  87 | data = UART_InCharNonBlock();                                          
;----------------------------------------------------------------------
$C$DW$63	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$63, DW_AT_low_pc(0x00)
	.dwattr $C$DW$63, DW_AT_name("UART_InCharNonBlock")
	.dwattr $C$DW$63, DW_AT_TI_call
        BL        UART_InCharNonBlock   ; [DPU_3_PIPE] |87| 
        ; CALL OCCURS {UART_InCharNonBlock }  ; [] |87| 
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |87| 
	.dwpsn	file "../main.c",line 88,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
;  88 | if(data){                                                              
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |88| 
        CMP       A1, #0                ; [DPU_3_PIPE] |88| 
        BEQ       ||$C$L5||             ; [DPU_3_PIPE] |88| 
        ; BRANCHCC OCCURS {||$C$L5||}    ; [] |88| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../main.c",line 89,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
;  89 | ESP8266_PrintChar(data);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |89| 
$C$DW$64	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$64, DW_AT_low_pc(0x00)
	.dwattr $C$DW$64, DW_AT_name("ESP8266_PrintChar")
	.dwattr $C$DW$64, DW_AT_TI_call
        BL        ESP8266_PrintChar     ; [DPU_3_PIPE] |89| 
        ; CALL OCCURS {ESP8266_PrintChar }  ; [] |89| 
	.dwpsn	file "../main.c",line 85,column 9,is_stmt,isa 1
        B         ||$C$L5||             ; [DPU_3_PIPE] |85| 
        ; BRANCH OCCURS {||$C$L5||}      ; [] |85| 
;* --------------------------------------------------------------------------*
	.dwattr $C$DW$51, DW_AT_TI_end_file("../main.c")
	.dwattr $C$DW$51, DW_AT_TI_end_line(0x5c)
	.dwattr $C$DW$51, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$51

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$SL1||:	.string	10,13,"-----------",10,13,"System starting...",10,13,0
	.align	4
||$C$SL2||:	.string	"openweathermap.org",0
	.align	4
||$C$SL3||:	.string	10,13,"-----------",10,13,"System starting at 9600 baud...",10
	.string	13,0
	.align	4
||$C$SL4||:	.string	"AT+RST",13,10,0
;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON1||:	.bits	Fetch,32
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	printf
	.global	PLL_Init
	.global	UART_InChar
	.global	UART_InCharNonBlock
	.global	Output_Init
	.global	ESP8266_Init
	.global	ESP8266_InitUART
	.global	ESP8266_GetVersionNumber
	.global	ESP8266_CloseTCPConnection
	.global	ESP8266_MakeTCPConnection
	.global	ESP8266_SendTCP
	.global	ESP8266_GetStatus
	.global	ESP8266_EnableRXInterrupt
	.global	ESP8266_PrintChar
	.global	LED_Init
	.global	Board_Input
	.global	LED_RedToggle
	.global	LED_GreenOn
	.global	LED_GreenOff
	.global	DisableInterrupts
	.global	EnableInterrupts
	.global	ESP8266SendCommand

;******************************************************************************
;* BUILD ATTRIBUTES                                                           *
;******************************************************************************
	.battr "aeabi", Tag_File, 1, Tag_ABI_PCS_wchar_t(2)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_rounding(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_denormal(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_exceptions(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_number_model(1)
	.battr "aeabi", Tag_File, 1, Tag_ABI_enum_size(0)
	.battr "aeabi", Tag_File, 1, Tag_ABI_optimization_goals(5)
	.battr "aeabi", Tag_File, 1, Tag_ABI_FP_optimization_goals(0)
	.battr "TI", Tag_File, 1, Tag_Bitfield_layout(2)
	.battr "TI", Tag_File, 1, Tag_FP_interface(1)

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

$C$DW$T$20	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$20, DW_AT_byte_size(0x18)
$C$DW$65	.dwtag  DW_TAG_member
	.dwattr $C$DW$65, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$65, DW_AT_name("fd")
	.dwattr $C$DW$65, DW_AT_TI_symbol_name("fd")
	.dwattr $C$DW$65, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$65, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$65, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$65, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$65, DW_AT_decl_column(0x0b)
$C$DW$66	.dwtag  DW_TAG_member
	.dwattr $C$DW$66, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$66, DW_AT_name("buf")
	.dwattr $C$DW$66, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$66, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$66, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$66, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$66, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$66, DW_AT_decl_column(0x16)
$C$DW$67	.dwtag  DW_TAG_member
	.dwattr $C$DW$67, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$67, DW_AT_name("pos")
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("pos")
	.dwattr $C$DW$67, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$67, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$67, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$67, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$67, DW_AT_decl_column(0x16)
$C$DW$68	.dwtag  DW_TAG_member
	.dwattr $C$DW$68, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$68, DW_AT_name("bufend")
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("bufend")
	.dwattr $C$DW$68, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$68, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$68, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$68, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$68, DW_AT_decl_column(0x16)
$C$DW$69	.dwtag  DW_TAG_member
	.dwattr $C$DW$69, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$69, DW_AT_name("buff_stop")
	.dwattr $C$DW$69, DW_AT_TI_symbol_name("buff_stop")
	.dwattr $C$DW$69, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$69, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$69, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$69, DW_AT_decl_line(0x60)
	.dwattr $C$DW$69, DW_AT_decl_column(0x16)
$C$DW$70	.dwtag  DW_TAG_member
	.dwattr $C$DW$70, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$70, DW_AT_name("flags")
	.dwattr $C$DW$70, DW_AT_TI_symbol_name("flags")
	.dwattr $C$DW$70, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$70, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$70, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$70, DW_AT_decl_line(0x61)
	.dwattr $C$DW$70, DW_AT_decl_column(0x16)
	.dwendtag $C$DW$T$20

	.dwattr $C$DW$T$20, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$20, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$T$20, DW_AT_decl_column(0x10)
$C$DW$T$25	.dwtag  DW_TAG_typedef, DW_AT_name("FILE")
	.dwattr $C$DW$T$25, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$25, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$25, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$25, DW_AT_decl_column(0x03)

$C$DW$T$21	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$21, DW_AT_byte_size(0x08)
$C$DW$71	.dwtag  DW_TAG_member
	.dwattr $C$DW$71, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$71, DW_AT_name("quot")
	.dwattr $C$DW$71, DW_AT_TI_symbol_name("quot")
	.dwattr $C$DW$71, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$71, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$71, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$71, DW_AT_decl_line(0x59)
	.dwattr $C$DW$71, DW_AT_decl_column(0x16)
$C$DW$72	.dwtag  DW_TAG_member
	.dwattr $C$DW$72, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$72, DW_AT_name("rem")
	.dwattr $C$DW$72, DW_AT_TI_symbol_name("rem")
	.dwattr $C$DW$72, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$72, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$72, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$72, DW_AT_decl_line(0x59)
	.dwattr $C$DW$72, DW_AT_decl_column(0x1c)
	.dwendtag $C$DW$T$21

	.dwattr $C$DW$T$21, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$21, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$21, DW_AT_decl_column(0x10)
$C$DW$T$26	.dwtag  DW_TAG_typedef, DW_AT_name("div_t")
	.dwattr $C$DW$T$26, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$26, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$26, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$26, DW_AT_decl_line(0x59)
	.dwattr $C$DW$T$26, DW_AT_decl_column(0x23)

$C$DW$T$22	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$22, DW_AT_byte_size(0x08)
$C$DW$73	.dwtag  DW_TAG_member
	.dwattr $C$DW$73, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$73, DW_AT_name("quot")
	.dwattr $C$DW$73, DW_AT_TI_symbol_name("quot")
	.dwattr $C$DW$73, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$73, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$73, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$73, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$73, DW_AT_decl_column(0x16)
$C$DW$74	.dwtag  DW_TAG_member
	.dwattr $C$DW$74, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$74, DW_AT_name("rem")
	.dwattr $C$DW$74, DW_AT_TI_symbol_name("rem")
	.dwattr $C$DW$74, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$74, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$74, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$74, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$74, DW_AT_decl_column(0x1c)
	.dwendtag $C$DW$T$22

	.dwattr $C$DW$T$22, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$22, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$T$22, DW_AT_decl_column(0x10)
$C$DW$T$27	.dwtag  DW_TAG_typedef, DW_AT_name("ldiv_t")
	.dwattr $C$DW$T$27, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$T$27, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$27, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$27, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$T$27, DW_AT_decl_column(0x23)

$C$DW$T$23	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$23, DW_AT_byte_size(0x10)
$C$DW$75	.dwtag  DW_TAG_member
	.dwattr $C$DW$75, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$75, DW_AT_name("quot")
	.dwattr $C$DW$75, DW_AT_TI_symbol_name("quot")
	.dwattr $C$DW$75, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$75, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$75, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$75, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$75, DW_AT_decl_column(0x1c)
$C$DW$76	.dwtag  DW_TAG_member
	.dwattr $C$DW$76, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$76, DW_AT_name("rem")
	.dwattr $C$DW$76, DW_AT_TI_symbol_name("rem")
	.dwattr $C$DW$76, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$76, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$76, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$76, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$76, DW_AT_decl_column(0x22)
	.dwendtag $C$DW$T$23

	.dwattr $C$DW$T$23, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$23, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$23, DW_AT_decl_column(0x10)
$C$DW$T$28	.dwtag  DW_TAG_typedef, DW_AT_name("lldiv_t")
	.dwattr $C$DW$T$28, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$T$28, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$28, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$28, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$T$28, DW_AT_decl_column(0x29)
$C$DW$T$2	.dwtag  DW_TAG_unspecified_type
	.dwattr $C$DW$T$2, DW_AT_name("void")
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_type(*$C$DW$T$2)
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)

$C$DW$T$32	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$32, DW_AT_language(DW_LANG_C)
$C$DW$T$33	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$33, DW_AT_type(*$C$DW$T$32)
	.dwattr $C$DW$T$33, DW_AT_address_class(0x20)
$C$DW$T$34	.dwtag  DW_TAG_typedef, DW_AT_name("__TI_atexit_fn")
	.dwattr $C$DW$T$34, DW_AT_type(*$C$DW$T$33)
	.dwattr $C$DW$T$34, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$34, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$34, DW_AT_decl_line(0xb2)
	.dwattr $C$DW$T$34, DW_AT_decl_column(0x14)
$C$DW$T$43	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$2)
$C$DW$T$44	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$44, DW_AT_type(*$C$DW$T$43)
	.dwattr $C$DW$T$44, DW_AT_address_class(0x20)
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$45	.dwtag  DW_TAG_typedef, DW_AT_name("int8_t")
	.dwattr $C$DW$T$45, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$45, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$45, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$45, DW_AT_decl_line(0x2a)
	.dwattr $C$DW$T$45, DW_AT_decl_column(0x1d)
$C$DW$T$46	.dwtag  DW_TAG_typedef, DW_AT_name("int_least8_t")
	.dwattr $C$DW$T$46, DW_AT_type(*$C$DW$T$45)
	.dwattr $C$DW$T$46, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$46, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$46, DW_AT_decl_line(0x37)
	.dwattr $C$DW$T$46, DW_AT_decl_column(0x17)
$C$DW$T$6	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr $C$DW$T$6, DW_AT_name("unsigned char")
	.dwattr $C$DW$T$6, DW_AT_byte_size(0x01)
$C$DW$T$19	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$19, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$19, DW_AT_address_class(0x20)
$C$DW$T$47	.dwtag  DW_TAG_typedef, DW_AT_name("uint8_t")
	.dwattr $C$DW$T$47, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$47, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$47, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$47, DW_AT_decl_line(0x2b)
	.dwattr $C$DW$T$47, DW_AT_decl_column(0x1c)
$C$DW$T$48	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least8_t")
	.dwattr $C$DW$T$48, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$48, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$48, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$48, DW_AT_decl_line(0x38)
	.dwattr $C$DW$T$48, DW_AT_decl_column(0x16)
$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x02)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x02)
$C$DW$T$49	.dwtag  DW_TAG_typedef, DW_AT_name("int16_t")
	.dwattr $C$DW$T$49, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$49, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$49, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$49, DW_AT_decl_line(0x2c)
	.dwattr $C$DW$T$49, DW_AT_decl_column(0x1d)
$C$DW$T$50	.dwtag  DW_TAG_typedef, DW_AT_name("int_least16_t")
	.dwattr $C$DW$T$50, DW_AT_type(*$C$DW$T$49)
	.dwattr $C$DW$T$50, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$50, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$50, DW_AT_decl_line(0x3a)
	.dwattr $C$DW$T$50, DW_AT_decl_column(0x17)
$C$DW$T$9	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$9, DW_AT_name("unsigned short")
	.dwattr $C$DW$T$9, DW_AT_byte_size(0x02)
$C$DW$T$51	.dwtag  DW_TAG_typedef, DW_AT_name("_Wchart")
	.dwattr $C$DW$T$51, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$51, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$51, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$51, DW_AT_decl_line(0x1e5)
	.dwattr $C$DW$T$51, DW_AT_decl_column(0x21)
$C$DW$T$52	.dwtag  DW_TAG_typedef, DW_AT_name("_Wintt")
	.dwattr $C$DW$T$52, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$52, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$52, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$52, DW_AT_decl_line(0x1e6)
	.dwattr $C$DW$T$52, DW_AT_decl_column(0x21)
$C$DW$T$53	.dwtag  DW_TAG_typedef, DW_AT_name("uint16_t")
	.dwattr $C$DW$T$53, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$53, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$53, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$53, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$53, DW_AT_decl_column(0x1c)
$C$DW$T$54	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least16_t")
	.dwattr $C$DW$T$54, DW_AT_type(*$C$DW$T$53)
	.dwattr $C$DW$T$54, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$54, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$54, DW_AT_decl_line(0x3b)
	.dwattr $C$DW$T$54, DW_AT_decl_column(0x16)
$C$DW$T$55	.dwtag  DW_TAG_typedef, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$55, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$55, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$55, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$55, DW_AT_decl_line(0x75)
	.dwattr $C$DW$T$55, DW_AT_decl_column(0x1a)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x04)
$C$DW$T$56	.dwtag  DW_TAG_typedef, DW_AT_name("_Ptrdifft")
	.dwattr $C$DW$T$56, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$56, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$56, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$56, DW_AT_decl_line(0xa9)
	.dwattr $C$DW$T$56, DW_AT_decl_column(0x1e)

$C$DW$T$65	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$65, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$65, DW_AT_language(DW_LANG_C)
$C$DW$77	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$44)
$C$DW$78	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$44)
	.dwendtag $C$DW$T$65

$C$DW$T$66	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$66, DW_AT_type(*$C$DW$T$65)
	.dwattr $C$DW$T$66, DW_AT_address_class(0x20)
$C$DW$T$67	.dwtag  DW_TAG_typedef, DW_AT_name("__TI_compar_fn")
	.dwattr $C$DW$T$67, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$T$67, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$67, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdlib.h")
	.dwattr $C$DW$T$67, DW_AT_decl_line(0xb5)
	.dwattr $C$DW$T$67, DW_AT_decl_column(0x13)
$C$DW$T$68	.dwtag  DW_TAG_typedef, DW_AT_name("int32_t")
	.dwattr $C$DW$T$68, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$68, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$68, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$68, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$68, DW_AT_decl_column(0x1d)
$C$DW$T$69	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast16_t")
	.dwattr $C$DW$T$69, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$69, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$69, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$69, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$69, DW_AT_decl_column(0x17)
$C$DW$T$70	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast32_t")
	.dwattr $C$DW$T$70, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$70, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$70, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$70, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$T$70, DW_AT_decl_column(0x17)
$C$DW$T$71	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast8_t")
	.dwattr $C$DW$T$71, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$71, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$71, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$71, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$71, DW_AT_decl_column(0x17)
$C$DW$T$72	.dwtag  DW_TAG_typedef, DW_AT_name("int_least32_t")
	.dwattr $C$DW$T$72, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$72, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$72, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$72, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$72, DW_AT_decl_column(0x17)
$C$DW$T$73	.dwtag  DW_TAG_typedef, DW_AT_name("intptr_t")
	.dwattr $C$DW$T$73, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$73, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$73, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$73, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$73, DW_AT_decl_column(0x1a)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x04)
$C$DW$T$74	.dwtag  DW_TAG_typedef, DW_AT_name("_Sizet")
	.dwattr $C$DW$T$74, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$74, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$74, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$74, DW_AT_decl_line(0xab)
	.dwattr $C$DW$T$74, DW_AT_decl_column(0x1a)
$C$DW$T$75	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$75, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$75, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$75, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$75, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$75, DW_AT_decl_column(0x19)
$C$DW$T$29	.dwtag  DW_TAG_typedef, DW_AT_name("uint32_t")
	.dwattr $C$DW$T$29, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$29, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$29, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$29, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$29, DW_AT_decl_column(0x1c)
$C$DW$T$78	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast16_t")
	.dwattr $C$DW$T$78, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$78, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$78, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$78, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$78, DW_AT_decl_column(0x16)
$C$DW$T$79	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast32_t")
	.dwattr $C$DW$T$79, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$79, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$79, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$79, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$79, DW_AT_decl_column(0x16)
$C$DW$T$80	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast8_t")
	.dwattr $C$DW$T$80, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$80, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$80, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$80, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$80, DW_AT_decl_column(0x16)
$C$DW$T$81	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least32_t")
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$29)
	.dwattr $C$DW$T$81, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$81, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$81, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$81, DW_AT_decl_column(0x16)
$C$DW$T$82	.dwtag  DW_TAG_typedef, DW_AT_name("uintptr_t")
	.dwattr $C$DW$T$82, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$82, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$82, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$82, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$82, DW_AT_decl_column(0x1a)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x04)
$C$DW$T$83	.dwtag  DW_TAG_typedef, DW_AT_name("_Int32t")
	.dwattr $C$DW$T$83, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$83, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$83, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$83, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$T$83, DW_AT_decl_column(0x0e)
$C$DW$T$84	.dwtag  DW_TAG_typedef, DW_AT_name("fpos_t")
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$84, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$84, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$84, DW_AT_decl_column(0x0e)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned long")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x04)
$C$DW$T$85	.dwtag  DW_TAG_typedef, DW_AT_name("_Uint32t")
	.dwattr $C$DW$T$85, DW_AT_type(*$C$DW$T$13)
	.dwattr $C$DW$T$85, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$85, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$85, DW_AT_decl_line(0xa7)
	.dwattr $C$DW$T$85, DW_AT_decl_column(0x17)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x08)
$C$DW$T$86	.dwtag  DW_TAG_typedef, DW_AT_name("_Longlong")
	.dwattr $C$DW$T$86, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$86, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$86, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$86, DW_AT_decl_line(0x1b5)
	.dwattr $C$DW$T$86, DW_AT_decl_column(0x13)
$C$DW$T$87	.dwtag  DW_TAG_typedef, DW_AT_name("int64_t")
	.dwattr $C$DW$T$87, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$87, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$87, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$87, DW_AT_decl_line(0x32)
	.dwattr $C$DW$T$87, DW_AT_decl_column(0x21)
$C$DW$T$88	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast64_t")
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$88, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$88, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$88, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$88, DW_AT_decl_column(0x17)
$C$DW$T$89	.dwtag  DW_TAG_typedef, DW_AT_name("int_least64_t")
	.dwattr $C$DW$T$89, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$89, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$89, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$89, DW_AT_decl_line(0x40)
	.dwattr $C$DW$T$89, DW_AT_decl_column(0x17)
$C$DW$T$90	.dwtag  DW_TAG_typedef, DW_AT_name("intmax_t")
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$90, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$90, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$90, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$90, DW_AT_decl_column(0x20)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x08)
$C$DW$T$91	.dwtag  DW_TAG_typedef, DW_AT_name("_ULonglong")
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$91, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$91, DW_AT_decl_line(0x1b6)
	.dwattr $C$DW$T$91, DW_AT_decl_column(0x14)
$C$DW$T$92	.dwtag  DW_TAG_typedef, DW_AT_name("uint64_t")
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$92, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$92, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$92, DW_AT_decl_line(0x33)
	.dwattr $C$DW$T$92, DW_AT_decl_column(0x20)
$C$DW$T$93	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast64_t")
	.dwattr $C$DW$T$93, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$T$93, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$93, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$93, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$T$93, DW_AT_decl_column(0x16)
$C$DW$T$94	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least64_t")
	.dwattr $C$DW$T$94, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$T$94, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$94, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$94, DW_AT_decl_line(0x41)
	.dwattr $C$DW$T$94, DW_AT_decl_column(0x16)
$C$DW$T$95	.dwtag  DW_TAG_typedef, DW_AT_name("uintmax_t")
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$95, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$95, DW_AT_decl_line(0x57)
	.dwattr $C$DW$T$95, DW_AT_decl_column(0x20)
$C$DW$T$16	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$16, DW_AT_name("float")
	.dwattr $C$DW$T$16, DW_AT_byte_size(0x04)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
$C$DW$T$96	.dwtag  DW_TAG_typedef, DW_AT_name("_Sysch_t")
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$96, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$96, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$96, DW_AT_decl_line(0x218)
	.dwattr $C$DW$T$96, DW_AT_decl_column(0x0e)
$C$DW$T$40	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$40, DW_AT_address_class(0x20)
$C$DW$T$99	.dwtag  DW_TAG_typedef, DW_AT_name("__builtin_va_list")
	.dwattr $C$DW$T$99, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$99, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$99, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$T$99, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$T$99, DW_AT_decl_column(0x01)
$C$DW$T$57	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$57, DW_AT_type(*$C$DW$T$6)
$C$DW$T$58	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$58, DW_AT_type(*$C$DW$T$57)
	.dwattr $C$DW$T$58, DW_AT_address_class(0x20)

$C$DW$T$100	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$100, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$100, DW_AT_byte_size(0x78)
$C$DW$79	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$79, DW_AT_upper_bound(0x77)
	.dwendtag $C$DW$T$100


$C$DW$T$24	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$24, DW_AT_name("__va_list")
	.dwattr $C$DW$T$24, DW_AT_byte_size(0x04)
$C$DW$80	.dwtag  DW_TAG_member
	.dwattr $C$DW$80, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$80, DW_AT_name("__ap")
	.dwattr $C$DW$80, DW_AT_TI_symbol_name("__ap")
	.dwattr $C$DW$80, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$80, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$80, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$80, DW_AT_decl_line(0x36)
	.dwattr $C$DW$80, DW_AT_decl_column(0x0c)
	.dwendtag $C$DW$T$24

	.dwattr $C$DW$T$24, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$T$24, DW_AT_decl_line(0x35)
	.dwattr $C$DW$T$24, DW_AT_decl_column(0x10)
$C$DW$T$105	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$105, DW_AT_type(*$C$DW$T$24)
	.dwattr $C$DW$T$105, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$105, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$T$105, DW_AT_decl_line(0x37)
	.dwattr $C$DW$T$105, DW_AT_decl_column(0x03)
$C$DW$T$106	.dwtag  DW_TAG_typedef, DW_AT_name("_Va_list")
	.dwattr $C$DW$T$106, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$T$106, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$106, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/yvals.h")
	.dwattr $C$DW$T$106, DW_AT_decl_line(0x1f6)
	.dwattr $C$DW$T$106, DW_AT_decl_column(0x17)
	.dwattr $C$DW$CU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

$C$DW$CIE	.dwcie 14
	.dwcfi	cfa_register, 13
	.dwcfi	cfa_offset, 0
	.dwcfi	undefined, 0
	.dwcfi	undefined, 1
	.dwcfi	undefined, 2
	.dwcfi	undefined, 3
	.dwcfi	same_value, 4
	.dwcfi	same_value, 5
	.dwcfi	same_value, 6
	.dwcfi	same_value, 7
	.dwcfi	same_value, 8
	.dwcfi	same_value, 9
	.dwcfi	same_value, 10
	.dwcfi	same_value, 11
	.dwcfi	undefined, 12
	.dwcfi	undefined, 13
	.dwcfi	undefined, 14
	.dwcfi	undefined, 14
	.dwcfi	undefined, 7
	.dwcfi	undefined, 64
	.dwcfi	undefined, 65
	.dwcfi	undefined, 66
	.dwcfi	undefined, 67
	.dwcfi	undefined, 68
	.dwcfi	undefined, 69
	.dwcfi	undefined, 70
	.dwcfi	undefined, 71
	.dwcfi	undefined, 72
	.dwcfi	undefined, 73
	.dwcfi	undefined, 74
	.dwcfi	undefined, 75
	.dwcfi	undefined, 76
	.dwcfi	undefined, 77
	.dwcfi	undefined, 78
	.dwcfi	undefined, 79
	.dwcfi	same_value, 80
	.dwcfi	same_value, 81
	.dwcfi	same_value, 82
	.dwcfi	same_value, 83
	.dwcfi	same_value, 84
	.dwcfi	same_value, 85
	.dwcfi	same_value, 86
	.dwcfi	same_value, 87
	.dwcfi	same_value, 88
	.dwcfi	same_value, 89
	.dwcfi	same_value, 90
	.dwcfi	same_value, 91
	.dwcfi	same_value, 92
	.dwcfi	same_value, 93
	.dwcfi	same_value, 94
	.dwcfi	same_value, 95
	.dwendentry
	.dwendtag $C$DW$CU

