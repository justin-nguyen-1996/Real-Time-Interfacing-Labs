;******************************************************************************
;* TI ARM C/C++ Codegen                                             PC v5.2.4 *
;* Date/Time created: Sat Feb 06 22:51:20 2016                                *
;******************************************************************************
	.compiler_opts --abi=eabi --arm_vmrs_si_workaround=off --code_state=16 --diag_wrap=off --disable_dual_state --embedded_constants=on --endian=little --float_support=FPv4SPD16 --hll_source=on --object_format=elf --silicon_version=7M4 --symdebug:dwarf --symdebug:dwarf_version=3 --unaligned_access=on 
	.thumb

$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("../UART.c")
	.dwattr $C$DW$CU, DW_AT_producer("TI TI ARM C/C++ Codegen PC v5.2.4 Copyright (c) 1996-2015 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\Dropbox\ArmBook\LaunchPad\ValvanoWareTM4C123\ESP8266_4C123\Debug")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("fopen")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("fopen")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0xe6)
	.dwattr $C$DW$1, DW_AT_decl_column(0x1d)
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$26)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$26)
	.dwendtag $C$DW$1


$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("freopen")
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("freopen")
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_external
	.dwattr $C$DW$4, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$4, DW_AT_decl_line(0xe7)
	.dwattr $C$DW$4, DW_AT_decl_column(0x1d)
$C$DW$5	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$26)
$C$DW$6	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$26)
$C$DW$7	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$23)
	.dwendtag $C$DW$4


$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("setvbuf")
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("setvbuf")
	.dwattr $C$DW$8, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_external
	.dwattr $C$DW$8, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$8, DW_AT_decl_line(0xea)
	.dwattr $C$DW$8, DW_AT_decl_column(0x1d)
$C$DW$9	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$23)
$C$DW$10	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$10, DW_AT_type(*$C$DW$T$38)
$C$DW$11	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$11, DW_AT_type(*$C$DW$T$10)
$C$DW$12	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$12, DW_AT_type(*$C$DW$T$54)
	.dwendtag $C$DW$8


$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("StartCritical")
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("StartCritical")
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$13, DW_AT_declaration
	.dwattr $C$DW$13, DW_AT_external
	.dwattr $C$DW$13, DW_AT_decl_file("..\FIFO.h")
	.dwattr $C$DW$13, DW_AT_decl_line(0x1f)
	.dwattr $C$DW$13, DW_AT_decl_column(0x06)

$C$DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("EndCritical")
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("EndCritical")
	.dwattr $C$DW$14, DW_AT_declaration
	.dwattr $C$DW$14, DW_AT_external
	.dwattr $C$DW$14, DW_AT_decl_file("..\FIFO.h")
	.dwattr $C$DW$14, DW_AT_decl_line(0x20)
	.dwattr $C$DW$14, DW_AT_decl_column(0x06)
$C$DW$15	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$15, DW_AT_type(*$C$DW$T$12)
	.dwendtag $C$DW$14


$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("add_device")
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("add_device")
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$16, DW_AT_declaration
	.dwattr $C$DW$16, DW_AT_external
	.dwattr $C$DW$16, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/file.h")
	.dwattr $C$DW$16, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$16, DW_AT_decl_column(0x18)
$C$DW$17	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$38)
$C$DW$18	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$11)
$C$DW$19	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$19, DW_AT_type(*$C$DW$T$63)
$C$DW$20	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$65)
$C$DW$21	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$21, DW_AT_type(*$C$DW$T$67)
$C$DW$22	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$22, DW_AT_type(*$C$DW$T$69)
$C$DW$23	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$23, DW_AT_type(*$C$DW$T$76)
$C$DW$24	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$24, DW_AT_type(*$C$DW$T$71)
$C$DW$25	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$25, DW_AT_type(*$C$DW$T$73)
	.dwendtag $C$DW$16

$C$DW$26	.dwtag  DW_TAG_variable, DW_AT_name("_ftable")
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("_ftable")
	.dwattr $C$DW$26, DW_AT_type(*$C$DW$T$31)
	.dwattr $C$DW$26, DW_AT_declaration
	.dwattr $C$DW$26, DW_AT_external
	.dwattr $C$DW$26, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$26, DW_AT_decl_line(0xd4)
	.dwattr $C$DW$26, DW_AT_decl_column(0x1a)
	.global	RxPutI
	.common	RxPutI,4,4
$C$DW$27	.dwtag  DW_TAG_variable, DW_AT_name("RxPutI")
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("RxPutI")
	.dwattr $C$DW$27, DW_AT_location[DW_OP_addr RxPutI]
	.dwattr $C$DW$27, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$27, DW_AT_external
	.dwattr $C$DW$27, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$27, DW_AT_decl_line(0x47)
	.dwattr $C$DW$27, DW_AT_decl_column(0x01)
	.global	RxGetI
	.common	RxGetI,4,4
$C$DW$28	.dwtag  DW_TAG_variable, DW_AT_name("RxGetI")
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("RxGetI")
	.dwattr $C$DW$28, DW_AT_location[DW_OP_addr RxGetI]
	.dwattr $C$DW$28, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$28, DW_AT_external
	.dwattr $C$DW$28, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$28, DW_AT_decl_line(0x47)
	.dwattr $C$DW$28, DW_AT_decl_column(0x01)
RxFifo:	.usect	".bss:RxFifo",1024,1
$C$DW$29	.dwtag  DW_TAG_variable, DW_AT_name("RxFifo")
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("RxFifo")
	.dwattr $C$DW$29, DW_AT_type(*$C$DW$T$107)
	.dwattr $C$DW$29, DW_AT_location[DW_OP_addr RxFifo]
	.dwattr $C$DW$29, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$29, DW_AT_decl_line(0x47)
	.dwattr $C$DW$29, DW_AT_decl_column(0x01)
	.global	TxPutI
	.common	TxPutI,4,4
$C$DW$30	.dwtag  DW_TAG_variable, DW_AT_name("TxPutI")
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("TxPutI")
	.dwattr $C$DW$30, DW_AT_location[DW_OP_addr TxPutI]
	.dwattr $C$DW$30, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$30, DW_AT_external
	.dwattr $C$DW$30, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$30, DW_AT_decl_line(0x48)
	.dwattr $C$DW$30, DW_AT_decl_column(0x01)
	.global	TxGetI
	.common	TxGetI,4,4
$C$DW$31	.dwtag  DW_TAG_variable, DW_AT_name("TxGetI")
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("TxGetI")
	.dwattr $C$DW$31, DW_AT_location[DW_OP_addr TxGetI]
	.dwattr $C$DW$31, DW_AT_type(*$C$DW$T$86)
	.dwattr $C$DW$31, DW_AT_external
	.dwattr $C$DW$31, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$31, DW_AT_decl_line(0x48)
	.dwattr $C$DW$31, DW_AT_decl_column(0x01)
TxFifo:	.usect	".bss:TxFifo",1024,1
$C$DW$32	.dwtag  DW_TAG_variable, DW_AT_name("TxFifo")
	.dwattr $C$DW$32, DW_AT_TI_symbol_name("TxFifo")
	.dwattr $C$DW$32, DW_AT_type(*$C$DW$T$107)
	.dwattr $C$DW$32, DW_AT_location[DW_OP_addr TxFifo]
	.dwattr $C$DW$32, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$32, DW_AT_decl_line(0x48)
	.dwattr $C$DW$32, DW_AT_decl_column(0x01)
;	C:\ti\ccsv6\tools\compiler\ti-cgt-arm_5.2.4\bin\armacpia.exe -@C:\\Users\\VALVAN~1\\AppData\\Local\\Temp\\1659612 
	.sect	".text"
	.clink
	.thumbfunc RxFifo_Init
	.thumb
	.global	RxFifo_Init

$C$DW$33	.dwtag  DW_TAG_subprogram, DW_AT_name("RxFifo_Init")
	.dwattr $C$DW$33, DW_AT_low_pc(RxFifo_Init)
	.dwattr $C$DW$33, DW_AT_high_pc(0x00)
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("RxFifo_Init")
	.dwattr $C$DW$33, DW_AT_external
	.dwattr $C$DW$33, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$33, DW_AT_TI_begin_line(0x47)
	.dwattr $C$DW$33, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$33, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$33, DW_AT_decl_line(0x47)
	.dwattr $C$DW$33, DW_AT_decl_column(0x01)
	.dwattr $C$DW$33, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 71,column 1,is_stmt,address RxFifo_Init,isa 1

	.dwfde $C$DW$CIE, RxFifo_Init

;*****************************************************************************
;* FUNCTION NAME: RxFifo_Init                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
RxFifo_Init:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$34	.dwtag  DW_TAG_variable, DW_AT_name("sr")
	.dwattr $C$DW$34, DW_AT_TI_symbol_name("sr")
	.dwattr $C$DW$34, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$34, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  71 | AddIndexFifo(Rx, FIFOSIZE, char, FIFOSUCCESS, FIFOFAIL)                
;----------------------------------------------------------------------
$C$DW$35	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$35, DW_AT_low_pc(0x00)
	.dwattr $C$DW$35, DW_AT_name("StartCritical")
	.dwattr $C$DW$35, DW_AT_TI_call
        BL        StartCritical         ; [DPU_3_PIPE] |71| 
        ; CALL OCCURS {StartCritical }   ; [] |71| 
        LDR       A3, $C$CON2           ; [DPU_3_PIPE] |71| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |71| 
        MOVS      A2, #0                ; [DPU_3_PIPE] |71| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A1, $C$CON1           ; [DPU_3_PIPE] |71| 
        STR       A2, [A1, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |71| 
$C$DW$36	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$36, DW_AT_low_pc(0x00)
	.dwattr $C$DW$36, DW_AT_name("EndCritical")
	.dwattr $C$DW$36, DW_AT_TI_call
        BL        EndCritical           ; [DPU_3_PIPE] |71| 
        ; CALL OCCURS {EndCritical }     ; [] |71| 
$C$DW$37	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$37, DW_AT_low_pc(0x00)
	.dwattr $C$DW$37, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$33, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$33, DW_AT_TI_end_line(0x47)
	.dwattr $C$DW$33, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$33

	.sect	".text"
	.clink
	.thumbfunc RxFifo_Put
	.thumb
	.global	RxFifo_Put

$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("RxFifo_Put")
	.dwattr $C$DW$38, DW_AT_low_pc(RxFifo_Put)
	.dwattr $C$DW$38, DW_AT_high_pc(0x00)
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("RxFifo_Put")
	.dwattr $C$DW$38, DW_AT_external
	.dwattr $C$DW$38, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$38, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$38, DW_AT_TI_begin_line(0x47)
	.dwattr $C$DW$38, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$38, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$38, DW_AT_decl_line(0x47)
	.dwattr $C$DW$38, DW_AT_decl_column(0x01)
	.dwattr $C$DW$38, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 71,column 1,is_stmt,address RxFifo_Put,isa 1

	.dwfde $C$DW$CIE, RxFifo_Put
$C$DW$39	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$39, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$39, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$39, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: RxFifo_Put                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,SP,SR                                *
;*   Regs Used         : A1,A2,A3,A4,V1,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 4 Auto + 8 Save = 12 byte                  *
;*****************************************************************************
RxFifo_Put:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A3, A4, V1, LR}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 4, -8
	.dwcfi	save_reg_to_mem, 3, -12
	.dwcfi	save_reg_to_mem, 2, -16
$C$DW$40	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$40, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$40, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$40, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  71 | AddIndexFifo(Rx, FIFOSIZE, char, FIFOSUCCESS, FIFOFAIL)                
;----------------------------------------------------------------------
        LDR       A3, $C$CON2           ; [DPU_3_PIPE] |71| 
        LDR       A2, $C$CON1           ; [DPU_3_PIPE] |71| 
        LDR       A3, [A3, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |71| 
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |71| 
        SUBS      A2, A2, A3            ; [DPU_3_PIPE] |71| 
        BFC       A2, #0, #10           ; [DPU_3_PIPE] |71| 
        CBZ       A2, ||$C$L1||         ; [] 
        ; BRANCHCC OCCURS {||$C$L1||}    ; [] |71| 
;* --------------------------------------------------------------------------*
        MOVS      A1, #0                ; [DPU_3_PIPE] |71| 
        B         ||$C$L2||             ; [DPU_3_PIPE] |71| 
        ; BRANCH OCCURS {||$C$L2||}      ; [] |71| 
;* --------------------------------------------------------------------------*
||$C$L1||:    
        LDR       A1, $C$CON1           ; [DPU_3_PIPE] |71| 
        LDR       A3, $C$CON1           ; [DPU_3_PIPE] |71| 
        LDR       V1, $C$CON3           ; [DPU_3_PIPE] |71| 
        LDRB      A4, [SP, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A2, [A3, #0]          ; [DPU_3_PIPE] |71| 
        BFC       A1, #10, #22          ; [DPU_3_PIPE] |71| 
        ADDS      A2, A2, #1            ; [DPU_3_PIPE] |71| 
        STRB      A4, [V1, +A1]         ; [DPU_3_PIPE] |71| 
        MOVS      A1, #1                ; [DPU_3_PIPE] |71| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |71| 
;* --------------------------------------------------------------------------*
||$C$L2||:    
$C$DW$41	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$41, DW_AT_low_pc(0x00)
	.dwattr $C$DW$41, DW_AT_TI_return
        POP       {A3, A4, V1, PC}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$38, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$38, DW_AT_TI_end_line(0x47)
	.dwattr $C$DW$38, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$38

	.sect	".text"
	.clink
	.thumbfunc RxFifo_Get
	.thumb
	.global	RxFifo_Get

$C$DW$42	.dwtag  DW_TAG_subprogram, DW_AT_name("RxFifo_Get")
	.dwattr $C$DW$42, DW_AT_low_pc(RxFifo_Get)
	.dwattr $C$DW$42, DW_AT_high_pc(0x00)
	.dwattr $C$DW$42, DW_AT_TI_symbol_name("RxFifo_Get")
	.dwattr $C$DW$42, DW_AT_external
	.dwattr $C$DW$42, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$42, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$42, DW_AT_TI_begin_line(0x47)
	.dwattr $C$DW$42, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$42, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$42, DW_AT_decl_line(0x47)
	.dwattr $C$DW$42, DW_AT_decl_column(0x01)
	.dwattr $C$DW$42, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 71,column 1,is_stmt,address RxFifo_Get,isa 1

	.dwfde $C$DW$CIE, RxFifo_Get
$C$DW$43	.dwtag  DW_TAG_formal_parameter, DW_AT_name("datapt")
	.dwattr $C$DW$43, DW_AT_TI_symbol_name("datapt")
	.dwattr $C$DW$43, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$43, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: RxFifo_Get                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,SP,SR                                      *
;*   Regs Used         : A1,A2,A3,SP,LR,SR                                   *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                   *
;*****************************************************************************
RxFifo_Get:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
$C$DW$44	.dwtag  DW_TAG_variable, DW_AT_name("datapt")
	.dwattr $C$DW$44, DW_AT_TI_symbol_name("datapt")
	.dwattr $C$DW$44, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$44, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  71 | AddIndexFifo(Rx, FIFOSIZE, char, FIFOSUCCESS, FIFOFAIL)                
;----------------------------------------------------------------------
        LDR       A2, $C$CON2           ; [DPU_3_PIPE] |71| 
        LDR       A3, $C$CON1           ; [DPU_3_PIPE] |71| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A3, [A3, #0]          ; [DPU_3_PIPE] |71| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |71| 
        CMP       A2, A3                ; [DPU_3_PIPE] |71| 
        BNE       ||$C$L3||             ; [DPU_3_PIPE] |71| 
        ; BRANCHCC OCCURS {||$C$L3||}    ; [] |71| 
;* --------------------------------------------------------------------------*
        MOVS      A1, #0                ; [DPU_3_PIPE] |71| 
        B         ||$C$L4||             ; [DPU_3_PIPE] |71| 
        ; BRANCH OCCURS {||$C$L4||}      ; [] |71| 
;* --------------------------------------------------------------------------*
||$C$L3||:    
        LDR       A1, $C$CON2           ; [DPU_3_PIPE] |71| 
        LDR       A3, $C$CON3           ; [DPU_3_PIPE] |71| 
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |71| 
        BFC       A1, #10, #22          ; [DPU_3_PIPE] |71| 
        LDRB      A1, [A3, +A1]         ; [DPU_3_PIPE] |71| 
        LDR       A3, $C$CON2           ; [DPU_3_PIPE] |71| 
        STRB      A1, [A2, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A2, [A3, #0]          ; [DPU_3_PIPE] |71| 
        MOVS      A1, #1                ; [DPU_3_PIPE] |71| 
        ADDS      A2, A2, #1            ; [DPU_3_PIPE] |71| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |71| 
;* --------------------------------------------------------------------------*
||$C$L4||:    
        ADD       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$45	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$45, DW_AT_low_pc(0x00)
	.dwattr $C$DW$45, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$42, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$42, DW_AT_TI_end_line(0x47)
	.dwattr $C$DW$42, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$42

	.sect	".text"
	.clink
	.thumbfunc RxFifo_Size
	.thumb
	.global	RxFifo_Size

$C$DW$46	.dwtag  DW_TAG_subprogram, DW_AT_name("RxFifo_Size")
	.dwattr $C$DW$46, DW_AT_low_pc(RxFifo_Size)
	.dwattr $C$DW$46, DW_AT_high_pc(0x00)
	.dwattr $C$DW$46, DW_AT_TI_symbol_name("RxFifo_Size")
	.dwattr $C$DW$46, DW_AT_external
	.dwattr $C$DW$46, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$46, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$46, DW_AT_TI_begin_line(0x47)
	.dwattr $C$DW$46, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$46, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$46, DW_AT_decl_line(0x47)
	.dwattr $C$DW$46, DW_AT_decl_column(0x01)
	.dwattr $C$DW$46, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../UART.c",line 71,column 1,is_stmt,address RxFifo_Size,isa 1

	.dwfde $C$DW$CIE, RxFifo_Size

;*****************************************************************************
;* FUNCTION NAME: RxFifo_Size                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,LR,SR                                         *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
RxFifo_Size:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
;----------------------------------------------------------------------
;  71 | AddIndexFifo(Rx, FIFOSIZE, char, FIFOSUCCESS, FIFOFAIL)                
;----------------------------------------------------------------------
        LDR       A2, $C$CON2           ; [DPU_3_PIPE] |71| 
        LDR       A1, $C$CON1           ; [DPU_3_PIPE] |71| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |71| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |71| 
        SUBS      A1, A1, A2            ; [DPU_3_PIPE] |71| 
        UXTH      A1, A1                ; [DPU_3_PIPE] |71| 
$C$DW$47	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$47, DW_AT_low_pc(0x00)
	.dwattr $C$DW$47, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$46, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$46, DW_AT_TI_end_line(0x47)
	.dwattr $C$DW$46, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$46

	.sect	".text"
	.clink
	.thumbfunc TxFifo_Init
	.thumb
	.global	TxFifo_Init

$C$DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("TxFifo_Init")
	.dwattr $C$DW$48, DW_AT_low_pc(TxFifo_Init)
	.dwattr $C$DW$48, DW_AT_high_pc(0x00)
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("TxFifo_Init")
	.dwattr $C$DW$48, DW_AT_external
	.dwattr $C$DW$48, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$48, DW_AT_TI_begin_line(0x48)
	.dwattr $C$DW$48, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$48, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$48, DW_AT_decl_line(0x48)
	.dwattr $C$DW$48, DW_AT_decl_column(0x01)
	.dwattr $C$DW$48, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 72,column 1,is_stmt,address TxFifo_Init,isa 1

	.dwfde $C$DW$CIE, TxFifo_Init

;*****************************************************************************
;* FUNCTION NAME: TxFifo_Init                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
TxFifo_Init:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$49	.dwtag  DW_TAG_variable, DW_AT_name("sr")
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("sr")
	.dwattr $C$DW$49, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$49, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  72 | AddIndexFifo(Tx, 1024, char, FIFOSUCCESS, FIFOFAIL)                    
;----------------------------------------------------------------------
$C$DW$50	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$50, DW_AT_low_pc(0x00)
	.dwattr $C$DW$50, DW_AT_name("StartCritical")
	.dwattr $C$DW$50, DW_AT_TI_call
        BL        StartCritical         ; [DPU_3_PIPE] |72| 
        ; CALL OCCURS {StartCritical }   ; [] |72| 
        LDR       A3, $C$CON5           ; [DPU_3_PIPE] |72| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |72| 
        MOVS      A2, #0                ; [DPU_3_PIPE] |72| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A1, $C$CON4           ; [DPU_3_PIPE] |72| 
        STR       A2, [A1, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |72| 
$C$DW$51	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$51, DW_AT_low_pc(0x00)
	.dwattr $C$DW$51, DW_AT_name("EndCritical")
	.dwattr $C$DW$51, DW_AT_TI_call
        BL        EndCritical           ; [DPU_3_PIPE] |72| 
        ; CALL OCCURS {EndCritical }     ; [] |72| 
$C$DW$52	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$52, DW_AT_low_pc(0x00)
	.dwattr $C$DW$52, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$48, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$48, DW_AT_TI_end_line(0x48)
	.dwattr $C$DW$48, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$48

	.sect	".text"
	.clink
	.thumbfunc TxFifo_Put
	.thumb
	.global	TxFifo_Put

$C$DW$53	.dwtag  DW_TAG_subprogram, DW_AT_name("TxFifo_Put")
	.dwattr $C$DW$53, DW_AT_low_pc(TxFifo_Put)
	.dwattr $C$DW$53, DW_AT_high_pc(0x00)
	.dwattr $C$DW$53, DW_AT_TI_symbol_name("TxFifo_Put")
	.dwattr $C$DW$53, DW_AT_external
	.dwattr $C$DW$53, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$53, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$53, DW_AT_TI_begin_line(0x48)
	.dwattr $C$DW$53, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$53, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$53, DW_AT_decl_line(0x48)
	.dwattr $C$DW$53, DW_AT_decl_column(0x01)
	.dwattr $C$DW$53, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 72,column 1,is_stmt,address TxFifo_Put,isa 1

	.dwfde $C$DW$CIE, TxFifo_Put
$C$DW$54	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$54, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$54, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$54, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: TxFifo_Put                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,SP,SR                                *
;*   Regs Used         : A1,A2,A3,A4,V1,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 4 Auto + 8 Save = 12 byte                  *
;*****************************************************************************
TxFifo_Put:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A3, A4, V1, LR}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 4, -8
	.dwcfi	save_reg_to_mem, 3, -12
	.dwcfi	save_reg_to_mem, 2, -16
$C$DW$55	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$55, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$55, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$55, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  72 | AddIndexFifo(Tx, 1024, char, FIFOSUCCESS, FIFOFAIL)                    
;----------------------------------------------------------------------
        LDR       A3, $C$CON5           ; [DPU_3_PIPE] |72| 
        LDR       A2, $C$CON4           ; [DPU_3_PIPE] |72| 
        LDR       A3, [A3, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |72| 
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |72| 
        SUBS      A2, A2, A3            ; [DPU_3_PIPE] |72| 
        BFC       A2, #0, #10           ; [DPU_3_PIPE] |72| 
        CBZ       A2, ||$C$L5||         ; [] 
        ; BRANCHCC OCCURS {||$C$L5||}    ; [] |72| 
;* --------------------------------------------------------------------------*
        MOVS      A1, #0                ; [DPU_3_PIPE] |72| 
        B         ||$C$L6||             ; [DPU_3_PIPE] |72| 
        ; BRANCH OCCURS {||$C$L6||}      ; [] |72| 
;* --------------------------------------------------------------------------*
||$C$L5||:    
        LDR       A1, $C$CON4           ; [DPU_3_PIPE] |72| 
        LDR       A3, $C$CON4           ; [DPU_3_PIPE] |72| 
        LDR       V1, $C$CON6           ; [DPU_3_PIPE] |72| 
        LDRB      A4, [SP, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A2, [A3, #0]          ; [DPU_3_PIPE] |72| 
        BFC       A1, #10, #22          ; [DPU_3_PIPE] |72| 
        ADDS      A2, A2, #1            ; [DPU_3_PIPE] |72| 
        STRB      A4, [V1, +A1]         ; [DPU_3_PIPE] |72| 
        MOVS      A1, #1                ; [DPU_3_PIPE] |72| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |72| 
;* --------------------------------------------------------------------------*
||$C$L6||:    
$C$DW$56	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$56, DW_AT_low_pc(0x00)
	.dwattr $C$DW$56, DW_AT_TI_return
        POP       {A3, A4, V1, PC}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$53, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$53, DW_AT_TI_end_line(0x48)
	.dwattr $C$DW$53, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$53

	.sect	".text"
	.clink
	.thumbfunc TxFifo_Get
	.thumb
	.global	TxFifo_Get

$C$DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("TxFifo_Get")
	.dwattr $C$DW$57, DW_AT_low_pc(TxFifo_Get)
	.dwattr $C$DW$57, DW_AT_high_pc(0x00)
	.dwattr $C$DW$57, DW_AT_TI_symbol_name("TxFifo_Get")
	.dwattr $C$DW$57, DW_AT_external
	.dwattr $C$DW$57, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$57, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$57, DW_AT_TI_begin_line(0x48)
	.dwattr $C$DW$57, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$57, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$57, DW_AT_decl_line(0x48)
	.dwattr $C$DW$57, DW_AT_decl_column(0x01)
	.dwattr $C$DW$57, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 72,column 1,is_stmt,address TxFifo_Get,isa 1

	.dwfde $C$DW$CIE, TxFifo_Get
$C$DW$58	.dwtag  DW_TAG_formal_parameter, DW_AT_name("datapt")
	.dwattr $C$DW$58, DW_AT_TI_symbol_name("datapt")
	.dwattr $C$DW$58, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$58, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: TxFifo_Get                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,SP,SR                                      *
;*   Regs Used         : A1,A2,A3,SP,LR,SR                                   *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                   *
;*****************************************************************************
TxFifo_Get:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
$C$DW$59	.dwtag  DW_TAG_variable, DW_AT_name("datapt")
	.dwattr $C$DW$59, DW_AT_TI_symbol_name("datapt")
	.dwattr $C$DW$59, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$59, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
;  72 | AddIndexFifo(Tx, 1024, char, FIFOSUCCESS, FIFOFAIL)                    
;----------------------------------------------------------------------
        LDR       A2, $C$CON5           ; [DPU_3_PIPE] |72| 
        LDR       A3, $C$CON4           ; [DPU_3_PIPE] |72| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A3, [A3, #0]          ; [DPU_3_PIPE] |72| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |72| 
        CMP       A2, A3                ; [DPU_3_PIPE] |72| 
        BNE       ||$C$L7||             ; [DPU_3_PIPE] |72| 
        ; BRANCHCC OCCURS {||$C$L7||}    ; [] |72| 
;* --------------------------------------------------------------------------*
        MOVS      A1, #0                ; [DPU_3_PIPE] |72| 
        B         ||$C$L8||             ; [DPU_3_PIPE] |72| 
        ; BRANCH OCCURS {||$C$L8||}      ; [] |72| 
;* --------------------------------------------------------------------------*
||$C$L7||:    
        LDR       A1, $C$CON5           ; [DPU_3_PIPE] |72| 
        LDR       A3, $C$CON6           ; [DPU_3_PIPE] |72| 
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |72| 
        BFC       A1, #10, #22          ; [DPU_3_PIPE] |72| 
        LDRB      A1, [A3, +A1]         ; [DPU_3_PIPE] |72| 
        LDR       A3, $C$CON5           ; [DPU_3_PIPE] |72| 
        STRB      A1, [A2, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A2, [A3, #0]          ; [DPU_3_PIPE] |72| 
        MOVS      A1, #1                ; [DPU_3_PIPE] |72| 
        ADDS      A2, A2, #1            ; [DPU_3_PIPE] |72| 
        STR       A2, [A3, #0]          ; [DPU_3_PIPE] |72| 
;* --------------------------------------------------------------------------*
||$C$L8||:    
        ADD       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$60	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$60, DW_AT_low_pc(0x00)
	.dwattr $C$DW$60, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$57, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$57, DW_AT_TI_end_line(0x48)
	.dwattr $C$DW$57, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$57

	.sect	".text"
	.clink
	.thumbfunc TxFifo_Size
	.thumb
	.global	TxFifo_Size

$C$DW$61	.dwtag  DW_TAG_subprogram, DW_AT_name("TxFifo_Size")
	.dwattr $C$DW$61, DW_AT_low_pc(TxFifo_Size)
	.dwattr $C$DW$61, DW_AT_high_pc(0x00)
	.dwattr $C$DW$61, DW_AT_TI_symbol_name("TxFifo_Size")
	.dwattr $C$DW$61, DW_AT_external
	.dwattr $C$DW$61, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$61, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$61, DW_AT_TI_begin_line(0x48)
	.dwattr $C$DW$61, DW_AT_TI_begin_column(0x01)
	.dwattr $C$DW$61, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$61, DW_AT_decl_line(0x48)
	.dwattr $C$DW$61, DW_AT_decl_column(0x01)
	.dwattr $C$DW$61, DW_AT_TI_max_frame_size(0x00)
	.dwpsn	file "../UART.c",line 72,column 1,is_stmt,address TxFifo_Size,isa 1

	.dwfde $C$DW$CIE, TxFifo_Size

;*****************************************************************************
;* FUNCTION NAME: TxFifo_Size                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,LR,SR                                         *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************
TxFifo_Size:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
;----------------------------------------------------------------------
;  72 | AddIndexFifo(Tx, 1024, char, FIFOSUCCESS, FIFOFAIL)                    
;----------------------------------------------------------------------
        LDR       A2, $C$CON5           ; [DPU_3_PIPE] |72| 
        LDR       A1, $C$CON4           ; [DPU_3_PIPE] |72| 
        LDR       A2, [A2, #0]          ; [DPU_3_PIPE] |72| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |72| 
        SUBS      A1, A1, A2            ; [DPU_3_PIPE] |72| 
        UXTH      A1, A1                ; [DPU_3_PIPE] |72| 
$C$DW$62	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$62, DW_AT_low_pc(0x00)
	.dwattr $C$DW$62, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$61, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$61, DW_AT_TI_end_line(0x48)
	.dwattr $C$DW$61, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$61

	.sect	".text"
	.clink
	.thumbfunc UART_Init
	.thumb
	.global	UART_Init

$C$DW$63	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_Init")
	.dwattr $C$DW$63, DW_AT_low_pc(UART_Init)
	.dwattr $C$DW$63, DW_AT_high_pc(0x00)
	.dwattr $C$DW$63, DW_AT_TI_symbol_name("UART_Init")
	.dwattr $C$DW$63, DW_AT_external
	.dwattr $C$DW$63, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$63, DW_AT_TI_begin_line(0x4c)
	.dwattr $C$DW$63, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$63, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$63, DW_AT_decl_line(0x4c)
	.dwattr $C$DW$63, DW_AT_decl_column(0x06)
	.dwattr $C$DW$63, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 76,column 21,is_stmt,address UART_Init,isa 1

	.dwfde $C$DW$CIE, UART_Init
;----------------------------------------------------------------------
;  76 | void UART_Init(void){                                                  
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART_Init                                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************
UART_Init:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwpsn	file "../UART.c",line 77,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  77 | SYSCTL_RCGCUART_R |= 0x01;            // activate UART0                
;----------------------------------------------------------------------
        LDR       A2, $C$CON7           ; [DPU_3_PIPE] |77| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |77| 
        ORR       A1, A1, #1            ; [DPU_3_PIPE] |77| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |77| 
	.dwpsn	file "../UART.c",line 78,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  78 | SYSCTL_RCGCGPIO_R |= 0x01;            // activate port A               
;----------------------------------------------------------------------
        LDR       A2, $C$CON8           ; [DPU_3_PIPE] |78| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |78| 
        ORR       A1, A1, #1            ; [DPU_3_PIPE] |78| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |78| 
	.dwpsn	file "../UART.c",line 79,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  79 | RxFifo_Init();                        // initialize empty FIFOs        
;----------------------------------------------------------------------
$C$DW$64	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$64, DW_AT_low_pc(0x00)
	.dwattr $C$DW$64, DW_AT_name("RxFifo_Init")
	.dwattr $C$DW$64, DW_AT_TI_call
        BL        RxFifo_Init           ; [DPU_3_PIPE] |79| 
        ; CALL OCCURS {RxFifo_Init }     ; [] |79| 
	.dwpsn	file "../UART.c",line 80,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  80 | TxFifo_Init();                                                         
;----------------------------------------------------------------------
$C$DW$65	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$65, DW_AT_low_pc(0x00)
	.dwattr $C$DW$65, DW_AT_name("TxFifo_Init")
	.dwattr $C$DW$65, DW_AT_TI_call
        BL        TxFifo_Init           ; [DPU_3_PIPE] |80| 
        ; CALL OCCURS {TxFifo_Init }     ; [] |80| 
	.dwpsn	file "../UART.c",line 81,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  81 | UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART                  
;----------------------------------------------------------------------
        LDR       A2, $C$CON9           ; [DPU_3_PIPE] |81| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |81| 
        BIC       A1, A1, #1            ; [DPU_3_PIPE] |81| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |81| 
	.dwpsn	file "../UART.c",line 82,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  82 | UART0_IBRD_R = 43;                    // IBRD = int(80,000,000 / (16 *
;     | 115,200)) = int(43.403)                                                
;----------------------------------------------------------------------
        LDR       A2, $C$CON10          ; [DPU_3_PIPE] |82| 
        MOVS      A1, #43               ; [DPU_3_PIPE] |82| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |82| 
	.dwpsn	file "../UART.c",line 83,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  83 | UART0_FBRD_R = 26;                    // FBRD = round(0.4028 * 64 ) = 2
;     | 6                                                                      
;  84 |                                       // 8 bit word length (no parity b
;     | its, one stop bit, FIFOs)                                              
;----------------------------------------------------------------------
        LDR       A2, $C$CON11          ; [DPU_3_PIPE] |83| 
        MOVS      A1, #26               ; [DPU_3_PIPE] |83| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |83| 
	.dwpsn	file "../UART.c",line 85,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  85 | UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);                       
;----------------------------------------------------------------------
        LDR       A2, $C$CON12          ; [DPU_3_PIPE] |85| 
        MOVS      A1, #112              ; [DPU_3_PIPE] |85| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |85| 
	.dwpsn	file "../UART.c",line 86,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  86 | UART0_IFLS_R &= ~0x3F;                // clear TX and RX interrupt FIFO
;     |  level fields                                                          
;  87 |                                       // configure interrupt for TX FIF
;     | O <= 1/8 full                                                          
;  88 |                                       // configure interrupt for RX FIF
;     | O >= 1/8 full                                                          
;----------------------------------------------------------------------
        LDR       A2, $C$CON13          ; [DPU_3_PIPE] |86| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |86| 
        BIC       A1, A1, #63           ; [DPU_3_PIPE] |86| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |86| 
	.dwpsn	file "../UART.c",line 89,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  89 | UART0_IFLS_R += (UART_IFLS_TX1_8|UART_IFLS_RX1_8);                     
;  90 |                                       // enable TX and RX FIFO interrup
;     | ts and RX time-out interrupt                                           
;----------------------------------------------------------------------
        LDR       A2, $C$CON13          ; [DPU_3_PIPE] |89| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |89| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |89| 
	.dwpsn	file "../UART.c",line 91,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  91 | UART0_IM_R |= (UART_IM_RXIM|UART_IM_TXIM|UART_IM_RTIM);                
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |91| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |91| 
        ORR       A1, A1, #112          ; [DPU_3_PIPE] |91| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |91| 
	.dwpsn	file "../UART.c",line 92,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  92 | UART0_CTL_R |= 0x301;                 // enable UART                   
;----------------------------------------------------------------------
        LDR       A2, $C$CON9           ; [DPU_3_PIPE] |92| 
        LDR       A3, [A2, #0]          ; [DPU_3_PIPE] |92| 
        MOV       A1, #769              ; [DPU_3_PIPE] |92| 
        ORRS      A1, A1, A3            ; [DPU_3_PIPE] |92| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |92| 
	.dwpsn	file "../UART.c",line 93,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  93 | GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0     
;----------------------------------------------------------------------
        LDR       A2, $C$CON15          ; [DPU_3_PIPE] |93| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |93| 
        ORR       A1, A1, #3            ; [DPU_3_PIPE] |93| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |93| 
	.dwpsn	file "../UART.c",line 94,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  94 | GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0   
;  95 |                                       // configure PA1-0 as UART       
;----------------------------------------------------------------------
        LDR       A2, $C$CON16          ; [DPU_3_PIPE] |94| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |94| 
        ORR       A1, A1, #3            ; [DPU_3_PIPE] |94| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |94| 
	.dwpsn	file "../UART.c",line 96,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  96 | GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;         
;----------------------------------------------------------------------
        LDR       A1, $C$CON17          ; [DPU_3_PIPE] |96| 
        LDR       A2, $C$CON17          ; [DPU_3_PIPE] |96| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |96| 
        BIC       A1, A1, #255          ; [DPU_3_PIPE] |96| 
        ADDS      A1, A1, #17           ; [DPU_3_PIPE] |96| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |96| 
	.dwpsn	file "../UART.c",line 97,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  97 | GPIO_PORTA_AMSEL_R = 0;               // disable analog functionality o
;     | n PA                                                                   
;  98 |                                       // UART0=priority 2              
;----------------------------------------------------------------------
        LDR       A2, $C$CON18          ; [DPU_3_PIPE] |97| 
        MOVS      A1, #0                ; [DPU_3_PIPE] |97| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |97| 
	.dwpsn	file "../UART.c",line 99,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
;  99 | NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFF00FF)|0x00004000; // bits 13-15       
;----------------------------------------------------------------------
        LDR       A1, $C$CON19          ; [DPU_3_PIPE] |99| 
        LDR       A2, $C$CON19          ; [DPU_3_PIPE] |99| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |99| 
        BIC       A1, A1, #65280        ; [DPU_3_PIPE] |99| 
        ORR       A1, A1, #16384        ; [DPU_3_PIPE] |99| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |99| 
	.dwpsn	file "../UART.c",line 100,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 100 | NVIC_EN0_R = NVIC_EN0_INT5;           // enable interrupt 5 in NVIC    
;----------------------------------------------------------------------
        LDR       A2, $C$CON20          ; [DPU_3_PIPE] |100| 
        MOVS      A1, #32               ; [DPU_3_PIPE] |100| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |100| 
	.dwpsn	file "../UART.c",line 101,column 1,is_stmt,isa 1
$C$DW$66	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$66, DW_AT_low_pc(0x00)
	.dwattr $C$DW$66, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$63, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$63, DW_AT_TI_end_line(0x65)
	.dwattr $C$DW$63, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$63

	.sect	".text"
	.clink
	.thumbfunc copyHardwareToSoftware
	.thumb

$C$DW$67	.dwtag  DW_TAG_subprogram, DW_AT_name("copyHardwareToSoftware")
	.dwattr $C$DW$67, DW_AT_low_pc(copyHardwareToSoftware)
	.dwattr $C$DW$67, DW_AT_high_pc(0x00)
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("copyHardwareToSoftware")
	.dwattr $C$DW$67, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$67, DW_AT_TI_begin_line(0x68)
	.dwattr $C$DW$67, DW_AT_TI_begin_column(0x0d)
	.dwattr $C$DW$67, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$67, DW_AT_decl_line(0x68)
	.dwattr $C$DW$67, DW_AT_decl_column(0x0d)
	.dwattr $C$DW$67, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 104,column 41,is_stmt,address copyHardwareToSoftware,isa 1

	.dwfde $C$DW$CIE, copyHardwareToSoftware
;----------------------------------------------------------------------
; 104 | void static copyHardwareToSoftware(void){                              
; 105 | char letter;                                                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: copyHardwareToSoftware                                     *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
copyHardwareToSoftware:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$68	.dwtag  DW_TAG_variable, DW_AT_name("letter")
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("letter")
	.dwattr $C$DW$68, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$68, DW_AT_location[DW_OP_breg13 0]
	.dwpsn	file "../UART.c",line 106,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 106 | while(((UART0_FR_R&UART_FR_RXFE) == 0) && (RxFifo_Size() < (FIFOSIZE -
;     | 1))){                                                                  
;----------------------------------------------------------------------
        B         ||$C$L10||            ; [DPU_3_PIPE] |106| 
        ; BRANCH OCCURS {||$C$L10||}     ; [] |106| 
;* --------------------------------------------------------------------------*
||$C$L9||:    
	.dwpsn	file "../UART.c",line 107,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 107 | letter = UART0_DR_R;                                                   
;----------------------------------------------------------------------
        LDR       A1, $C$CON21          ; [DPU_3_PIPE] |107| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |107| 
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |107| 
	.dwpsn	file "../UART.c",line 108,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 108 | RxFifo_Put(letter);                                                    
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |108| 
$C$DW$69	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$69, DW_AT_low_pc(0x00)
	.dwattr $C$DW$69, DW_AT_name("RxFifo_Put")
	.dwattr $C$DW$69, DW_AT_TI_call
        BL        RxFifo_Put            ; [DPU_3_PIPE] |108| 
        ; CALL OCCURS {RxFifo_Put }      ; [] |108| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L10||
;* --------------------------------------------------------------------------*
||$C$L10||:    
	.dwpsn	file "../UART.c",line 106,column 9,is_stmt,isa 1
        LDR       A1, $C$CON22          ; [DPU_3_PIPE] |106| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |106| 
        LSRS      A1, A1, #5            ; [DPU_3_PIPE] |106| 
        BCS       ||$C$L11||            ; [DPU_3_PIPE] |106| 
        ; BRANCHCC OCCURS {||$C$L11||}   ; [] |106| 
;* --------------------------------------------------------------------------*
$C$DW$70	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$70, DW_AT_low_pc(0x00)
	.dwattr $C$DW$70, DW_AT_name("RxFifo_Size")
	.dwattr $C$DW$70, DW_AT_TI_call
        BL        RxFifo_Size           ; [DPU_3_PIPE] |106| 
        ; CALL OCCURS {RxFifo_Size }     ; [] |106| 
        MOV       A2, #1023             ; [DPU_3_PIPE] |106| 
        CMP       A2, A1                ; [DPU_3_PIPE] |106| 
        BGT       ||$C$L9||             ; [DPU_3_PIPE] |106| 
        ; BRANCHCC OCCURS {||$C$L9||}    ; [] |106| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 110,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L11||:    
$C$DW$71	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$71, DW_AT_low_pc(0x00)
	.dwattr $C$DW$71, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$67, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$67, DW_AT_TI_end_line(0x6e)
	.dwattr $C$DW$67, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$67

	.sect	".text"
	.clink
	.thumbfunc copySoftwareToHardware
	.thumb

$C$DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("copySoftwareToHardware")
	.dwattr $C$DW$72, DW_AT_low_pc(copySoftwareToHardware)
	.dwattr $C$DW$72, DW_AT_high_pc(0x00)
	.dwattr $C$DW$72, DW_AT_TI_symbol_name("copySoftwareToHardware")
	.dwattr $C$DW$72, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$72, DW_AT_TI_begin_line(0x71)
	.dwattr $C$DW$72, DW_AT_TI_begin_column(0x0d)
	.dwattr $C$DW$72, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$72, DW_AT_decl_line(0x71)
	.dwattr $C$DW$72, DW_AT_decl_column(0x0d)
	.dwattr $C$DW$72, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 113,column 41,is_stmt,address copySoftwareToHardware,isa 1

	.dwfde $C$DW$CIE, copySoftwareToHardware
;----------------------------------------------------------------------
; 113 | void static copySoftwareToHardware(void){                              
; 114 | char letter;                                                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: copySoftwareToHardware                                     *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
copySoftwareToHardware:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$73	.dwtag  DW_TAG_variable, DW_AT_name("letter")
	.dwattr $C$DW$73, DW_AT_TI_symbol_name("letter")
	.dwattr $C$DW$73, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$73, DW_AT_location[DW_OP_breg13 0]
	.dwpsn	file "../UART.c",line 115,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 115 | while(((UART0_FR_R&UART_FR_TXFF) == 0) && (TxFifo_Size() > 0)){        
;----------------------------------------------------------------------
        B         ||$C$L13||            ; [DPU_3_PIPE] |115| 
        ; BRANCH OCCURS {||$C$L13||}     ; [] |115| 
;* --------------------------------------------------------------------------*
||$C$L12||:    
	.dwpsn	file "../UART.c",line 116,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 116 | TxFifo_Get(&letter);                                                   
;----------------------------------------------------------------------
        MOV       A1, SP                ; [DPU_3_PIPE] |116| 
$C$DW$74	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$74, DW_AT_low_pc(0x00)
	.dwattr $C$DW$74, DW_AT_name("TxFifo_Get")
	.dwattr $C$DW$74, DW_AT_TI_call
        BL        TxFifo_Get            ; [DPU_3_PIPE] |116| 
        ; CALL OCCURS {TxFifo_Get }      ; [] |116| 
	.dwpsn	file "../UART.c",line 117,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 117 | UART0_DR_R = letter;                                                   
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |117| 
        LDR       A2, $C$CON21          ; [DPU_3_PIPE] |117| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |117| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L13||
;* --------------------------------------------------------------------------*
||$C$L13||:    
	.dwpsn	file "../UART.c",line 115,column 9,is_stmt,isa 1
        LDR       A1, $C$CON22          ; [DPU_3_PIPE] |115| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |115| 
        LSRS      A1, A1, #6            ; [DPU_3_PIPE] |115| 
        BCS       ||$C$L14||            ; [DPU_3_PIPE] |115| 
        ; BRANCHCC OCCURS {||$C$L14||}   ; [] |115| 
;* --------------------------------------------------------------------------*
$C$DW$75	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$75, DW_AT_low_pc(0x00)
	.dwattr $C$DW$75, DW_AT_name("TxFifo_Size")
	.dwattr $C$DW$75, DW_AT_TI_call
        BL        TxFifo_Size           ; [DPU_3_PIPE] |115| 
        ; CALL OCCURS {TxFifo_Size }     ; [] |115| 
        CMP       A1, #0                ; [DPU_3_PIPE] |115| 
        BGT       ||$C$L12||            ; [DPU_3_PIPE] |115| 
        ; BRANCHCC OCCURS {||$C$L12||}   ; [] |115| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 119,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L14||:    
$C$DW$76	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$76, DW_AT_low_pc(0x00)
	.dwattr $C$DW$76, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$72, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$72, DW_AT_TI_end_line(0x77)
	.dwattr $C$DW$72, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$72

	.sect	".text"
	.clink
	.thumbfunc UART_InChar
	.thumb
	.global	UART_InChar

$C$DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InChar")
	.dwattr $C$DW$77, DW_AT_low_pc(UART_InChar)
	.dwattr $C$DW$77, DW_AT_high_pc(0x00)
	.dwattr $C$DW$77, DW_AT_TI_symbol_name("UART_InChar")
	.dwattr $C$DW$77, DW_AT_external
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$77, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$77, DW_AT_TI_begin_line(0x7a)
	.dwattr $C$DW$77, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$77, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$77, DW_AT_decl_line(0x7a)
	.dwattr $C$DW$77, DW_AT_decl_column(0x06)
	.dwattr $C$DW$77, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 122,column 23,is_stmt,address UART_InChar,isa 1

	.dwfde $C$DW$CIE, UART_InChar
;----------------------------------------------------------------------
; 122 | char UART_InChar(void){                                                
; 123 | char letter;                                                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART_InChar                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_InChar:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$78	.dwtag  DW_TAG_variable, DW_AT_name("letter")
	.dwattr $C$DW$78, DW_AT_TI_symbol_name("letter")
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$78, DW_AT_location[DW_OP_breg13 0]
	.dwpsn	file "../UART.c",line 124,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 124 | while(RxFifo_Get(&letter) == FIFOFAIL){};                              
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L15||
;*
;*   Loop source line                : 124
;*   Loop closing brace source line  : 124
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L15||:    
	.dwpsn	file "../UART.c",line 124,column 9,is_stmt,isa 1
        MOV       A1, SP                ; [DPU_3_PIPE] |124| 
$C$DW$79	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$79, DW_AT_low_pc(0x00)
	.dwattr $C$DW$79, DW_AT_name("RxFifo_Get")
	.dwattr $C$DW$79, DW_AT_TI_call
        BL        RxFifo_Get            ; [DPU_3_PIPE] |124| 
        ; CALL OCCURS {RxFifo_Get }      ; [] |124| 
        CMP       A1, #0                ; [DPU_3_PIPE] |124| 
        BEQ       ||$C$L15||            ; [DPU_3_PIPE] |124| 
        ; BRANCHCC OCCURS {||$C$L15||}   ; [] |124| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 125,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 125 | return(letter);                                                        
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |125| 
	.dwpsn	file "../UART.c",line 126,column 1,is_stmt,isa 1
$C$DW$80	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$80, DW_AT_low_pc(0x00)
	.dwattr $C$DW$80, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$77, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$77, DW_AT_TI_end_line(0x7e)
	.dwattr $C$DW$77, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$77

	.sect	".text"
	.clink
	.thumbfunc UART_InCharNonBlock
	.thumb
	.global	UART_InCharNonBlock

$C$DW$81	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InCharNonBlock")
	.dwattr $C$DW$81, DW_AT_low_pc(UART_InCharNonBlock)
	.dwattr $C$DW$81, DW_AT_high_pc(0x00)
	.dwattr $C$DW$81, DW_AT_TI_symbol_name("UART_InCharNonBlock")
	.dwattr $C$DW$81, DW_AT_external
	.dwattr $C$DW$81, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$81, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$81, DW_AT_TI_begin_line(0x84)
	.dwattr $C$DW$81, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$81, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$81, DW_AT_decl_line(0x84)
	.dwattr $C$DW$81, DW_AT_decl_column(0x06)
	.dwattr $C$DW$81, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 132,column 31,is_stmt,address UART_InCharNonBlock,isa 1

	.dwfde $C$DW$CIE, UART_InCharNonBlock
;----------------------------------------------------------------------
; 132 | char UART_InCharNonBlock(void){                                        
; 133 | char letter;                                                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART_InCharNonBlock                                        *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_InCharNonBlock:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$82	.dwtag  DW_TAG_variable, DW_AT_name("letter")
	.dwattr $C$DW$82, DW_AT_TI_symbol_name("letter")
	.dwattr $C$DW$82, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$82, DW_AT_location[DW_OP_breg13 0]
	.dwpsn	file "../UART.c",line 134,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 134 | if(RxFifo_Get(&letter) == FIFOFAIL){                                   
;----------------------------------------------------------------------
        MOV       A1, SP                ; [DPU_3_PIPE] |134| 
$C$DW$83	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$83, DW_AT_low_pc(0x00)
	.dwattr $C$DW$83, DW_AT_name("RxFifo_Get")
	.dwattr $C$DW$83, DW_AT_TI_call
        BL        RxFifo_Get            ; [DPU_3_PIPE] |134| 
        ; CALL OCCURS {RxFifo_Get }      ; [] |134| 
        CBNZ      A1, ||$C$L16||        ; [] 
        ; BRANCHCC OCCURS {||$C$L16||}   ; [] |134| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 135,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 135 | return 0;  // empty                                                    
; 136 | };                                                                     
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |135| 
        B         ||$C$L17||            ; [DPU_3_PIPE] |135| 
        ; BRANCH OCCURS {||$C$L17||}     ; [] |135| 
;* --------------------------------------------------------------------------*
||$C$L16||:    
	.dwpsn	file "../UART.c",line 137,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 137 | return(letter);                                                        
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |137| 
;* --------------------------------------------------------------------------*
||$C$L17||:    
	.dwpsn	file "../UART.c",line 138,column 1,is_stmt,isa 1
$C$DW$84	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$84, DW_AT_low_pc(0x00)
	.dwattr $C$DW$84, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$81, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$81, DW_AT_TI_end_line(0x8a)
	.dwattr $C$DW$81, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$81

	.sect	".text"
	.clink
	.thumbfunc UART_OutChar
	.thumb
	.global	UART_OutChar

$C$DW$85	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$85, DW_AT_low_pc(UART_OutChar)
	.dwattr $C$DW$85, DW_AT_high_pc(0x00)
	.dwattr $C$DW$85, DW_AT_TI_symbol_name("UART_OutChar")
	.dwattr $C$DW$85, DW_AT_external
	.dwattr $C$DW$85, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$85, DW_AT_TI_begin_line(0x91)
	.dwattr $C$DW$85, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$85, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$85, DW_AT_decl_line(0x91)
	.dwattr $C$DW$85, DW_AT_decl_column(0x06)
	.dwattr $C$DW$85, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 145,column 29,is_stmt,address UART_OutChar,isa 1

	.dwfde $C$DW$CIE, UART_OutChar
$C$DW$86	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$86, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$86, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$86, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: UART_OutChar                                               *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_OutChar:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$87	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$87, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$87, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$87, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 145 | void UART_OutChar(char data){                                          
;----------------------------------------------------------------------
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |145| 
	.dwpsn	file "../UART.c",line 146,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 146 | while(TxFifo_Put(data) == FIFOFAIL){};                                 
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L18||
;*
;*   Loop source line                : 146
;*   Loop closing brace source line  : 146
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L18||:    
	.dwpsn	file "../UART.c",line 146,column 9,is_stmt,isa 1
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |146| 
$C$DW$88	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$88, DW_AT_low_pc(0x00)
	.dwattr $C$DW$88, DW_AT_name("TxFifo_Put")
	.dwattr $C$DW$88, DW_AT_TI_call
        BL        TxFifo_Put            ; [DPU_3_PIPE] |146| 
        ; CALL OCCURS {TxFifo_Put }      ; [] |146| 
        CMP       A1, #0                ; [DPU_3_PIPE] |146| 
        BEQ       ||$C$L18||            ; [DPU_3_PIPE] |146| 
        ; BRANCHCC OCCURS {||$C$L18||}   ; [] |146| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 147,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 147 | UART0_IM_R &= ~UART_IM_TXIM;          // disable TX FIFO interrupt     
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |147| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |147| 
        BIC       A1, A1, #32           ; [DPU_3_PIPE] |147| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |147| 
	.dwpsn	file "../UART.c",line 148,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 148 | copySoftwareToHardware();                                              
;----------------------------------------------------------------------
$C$DW$89	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$89, DW_AT_low_pc(0x00)
	.dwattr $C$DW$89, DW_AT_name("copySoftwareToHardware")
	.dwattr $C$DW$89, DW_AT_TI_call
        BL        copySoftwareToHardware ; [DPU_3_PIPE] |148| 
        ; CALL OCCURS {copySoftwareToHardware }  ; [] |148| 
	.dwpsn	file "../UART.c",line 149,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 149 | UART0_IM_R |= UART_IM_TXIM;           // enable TX FIFO interrupt      
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |149| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |149| 
        ORR       A1, A1, #32           ; [DPU_3_PIPE] |149| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |149| 
	.dwpsn	file "../UART.c",line 150,column 1,is_stmt,isa 1
$C$DW$90	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$90, DW_AT_low_pc(0x00)
	.dwattr $C$DW$90, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$85, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$85, DW_AT_TI_end_line(0x96)
	.dwattr $C$DW$85, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$85

	.sect	".text"
	.clink
	.thumbfunc UART_OutCharNonBlock
	.thumb
	.global	UART_OutCharNonBlock

$C$DW$91	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_OutCharNonBlock")
	.dwattr $C$DW$91, DW_AT_low_pc(UART_OutCharNonBlock)
	.dwattr $C$DW$91, DW_AT_high_pc(0x00)
	.dwattr $C$DW$91, DW_AT_TI_symbol_name("UART_OutCharNonBlock")
	.dwattr $C$DW$91, DW_AT_external
	.dwattr $C$DW$91, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$91, DW_AT_TI_begin_line(0x9c)
	.dwattr $C$DW$91, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$91, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$91, DW_AT_decl_line(0x9c)
	.dwattr $C$DW$91, DW_AT_decl_column(0x06)
	.dwattr $C$DW$91, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 156,column 37,is_stmt,address UART_OutCharNonBlock,isa 1

	.dwfde $C$DW$CIE, UART_OutCharNonBlock
$C$DW$92	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$92, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$92, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$92, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: UART_OutCharNonBlock                                       *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_OutCharNonBlock:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$93	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$93, DW_AT_TI_symbol_name("data")
	.dwattr $C$DW$93, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$93, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 156 | void UART_OutCharNonBlock(char data){                                  
;----------------------------------------------------------------------
        STRB      A1, [SP, #0]          ; [DPU_3_PIPE] |156| 
	.dwpsn	file "../UART.c",line 157,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 157 | if(TxFifo_Put(data) == FIFOFAIL) return; // lost data                  
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |157| 
$C$DW$94	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$94, DW_AT_low_pc(0x00)
	.dwattr $C$DW$94, DW_AT_name("TxFifo_Put")
	.dwattr $C$DW$94, DW_AT_TI_call
        BL        TxFifo_Put            ; [DPU_3_PIPE] |157| 
        ; CALL OCCURS {TxFifo_Put }      ; [] |157| 
        CBZ       A1, ||$C$L19||        ; [] 
        ; BRANCHCC OCCURS {||$C$L19||}   ; [] |157| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 157,column 36,is_stmt,isa 1
	.dwpsn	file "../UART.c",line 158,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 158 | UART0_IM_R &= ~UART_IM_TXIM;          // disable TX FIFO interrupt     
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |158| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |158| 
        BIC       A1, A1, #32           ; [DPU_3_PIPE] |158| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |158| 
	.dwpsn	file "../UART.c",line 159,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 159 | copySoftwareToHardware();                                              
;----------------------------------------------------------------------
$C$DW$95	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$95, DW_AT_low_pc(0x00)
	.dwattr $C$DW$95, DW_AT_name("copySoftwareToHardware")
	.dwattr $C$DW$95, DW_AT_TI_call
        BL        copySoftwareToHardware ; [DPU_3_PIPE] |159| 
        ; CALL OCCURS {copySoftwareToHardware }  ; [] |159| 
	.dwpsn	file "../UART.c",line 160,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 160 | UART0_IM_R |= UART_IM_TXIM;           // enable TX FIFO interrupt      
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |160| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |160| 
        ORR       A1, A1, #32           ; [DPU_3_PIPE] |160| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |160| 
	.dwpsn	file "../UART.c",line 161,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L19||:    
$C$DW$96	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$96, DW_AT_low_pc(0x00)
	.dwattr $C$DW$96, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$91, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$91, DW_AT_TI_end_line(0xa1)
	.dwattr $C$DW$91, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$91

	.sect	".text"
	.clink
	.thumbfunc UART0_Handler
	.thumb
	.global	UART0_Handler

$C$DW$97	.dwtag  DW_TAG_subprogram, DW_AT_name("UART0_Handler")
	.dwattr $C$DW$97, DW_AT_low_pc(UART0_Handler)
	.dwattr $C$DW$97, DW_AT_high_pc(0x00)
	.dwattr $C$DW$97, DW_AT_TI_symbol_name("UART0_Handler")
	.dwattr $C$DW$97, DW_AT_external
	.dwattr $C$DW$97, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$97, DW_AT_TI_begin_line(0xa6)
	.dwattr $C$DW$97, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$97, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$97, DW_AT_decl_line(0xa6)
	.dwattr $C$DW$97, DW_AT_decl_column(0x06)
	.dwattr $C$DW$97, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 166,column 25,is_stmt,address UART0_Handler,isa 1

	.dwfde $C$DW$CIE, UART0_Handler
;----------------------------------------------------------------------
; 166 | void UART0_Handler(void){                                              
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART0_Handler                                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************
UART0_Handler:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwpsn	file "../UART.c",line 167,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 167 | if(UART0_RIS_R&UART_RIS_TXRIS){       // hardware TX FIFO <= 2 items   
;----------------------------------------------------------------------
        LDR       A1, $C$CON23          ; [DPU_3_PIPE] |167| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |167| 
        LSRS      A1, A1, #6            ; [DPU_3_PIPE] |167| 
        BCC       ||$C$L20||            ; [DPU_3_PIPE] |167| 
        ; BRANCHCC OCCURS {||$C$L20||}   ; [] |167| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 168,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 168 | UART0_ICR_R = UART_ICR_TXIC;        // acknowledge TX FIFO             
; 169 | // copy from software TX FIFO to hardware TX FIFO                      
;----------------------------------------------------------------------
        LDR       A2, $C$CON24          ; [DPU_3_PIPE] |168| 
        MOVS      A1, #32               ; [DPU_3_PIPE] |168| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |168| 
	.dwpsn	file "../UART.c",line 170,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 170 | copySoftwareToHardware();                                              
;----------------------------------------------------------------------
$C$DW$98	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$98, DW_AT_low_pc(0x00)
	.dwattr $C$DW$98, DW_AT_name("copySoftwareToHardware")
	.dwattr $C$DW$98, DW_AT_TI_call
        BL        copySoftwareToHardware ; [DPU_3_PIPE] |170| 
        ; CALL OCCURS {copySoftwareToHardware }  ; [] |170| 
	.dwpsn	file "../UART.c",line 171,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 171 | if(TxFifo_Size() == 0){             // software TX FIFO is empty       
;----------------------------------------------------------------------
$C$DW$99	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$99, DW_AT_low_pc(0x00)
	.dwattr $C$DW$99, DW_AT_name("TxFifo_Size")
	.dwattr $C$DW$99, DW_AT_TI_call
        BL        TxFifo_Size           ; [DPU_3_PIPE] |171| 
        ; CALL OCCURS {TxFifo_Size }     ; [] |171| 
        CBNZ      A1, ||$C$L20||        ; [] 
        ; BRANCHCC OCCURS {||$C$L20||}   ; [] |171| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 172,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 172 | UART0_IM_R &= ~UART_IM_TXIM;      // disable TX FIFO interrupt         
;----------------------------------------------------------------------
        LDR       A2, $C$CON14          ; [DPU_3_PIPE] |172| 
        LDR       A1, [A2, #0]          ; [DPU_3_PIPE] |172| 
        BIC       A1, A1, #32           ; [DPU_3_PIPE] |172| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |172| 
;* --------------------------------------------------------------------------*
||$C$L20||:    
	.dwpsn	file "../UART.c",line 175,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 175 | if(UART0_RIS_R&UART_RIS_RXRIS){       // hardware RX FIFO >= 2 items   
;----------------------------------------------------------------------
        LDR       A1, $C$CON23          ; [DPU_3_PIPE] |175| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |175| 
        LSRS      A1, A1, #5            ; [DPU_3_PIPE] |175| 
        BCC       ||$C$L21||            ; [DPU_3_PIPE] |175| 
        ; BRANCHCC OCCURS {||$C$L21||}   ; [] |175| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 176,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 176 | UART0_ICR_R = UART_ICR_RXIC;        // acknowledge RX FIFO             
; 177 | // copy from hardware RX FIFO to software RX FIFO                      
;----------------------------------------------------------------------
        LDR       A2, $C$CON24          ; [DPU_3_PIPE] |176| 
        MOVS      A1, #16               ; [DPU_3_PIPE] |176| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |176| 
	.dwpsn	file "../UART.c",line 178,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 178 | copyHardwareToSoftware();                                              
;----------------------------------------------------------------------
$C$DW$100	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$100, DW_AT_low_pc(0x00)
	.dwattr $C$DW$100, DW_AT_name("copyHardwareToSoftware")
	.dwattr $C$DW$100, DW_AT_TI_call
        BL        copyHardwareToSoftware ; [DPU_3_PIPE] |178| 
        ; CALL OCCURS {copyHardwareToSoftware }  ; [] |178| 
;* --------------------------------------------------------------------------*
||$C$L21||:    
	.dwpsn	file "../UART.c",line 180,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 180 | if(UART0_RIS_R&UART_RIS_RTRIS){       // receiver timed out            
;----------------------------------------------------------------------
        LDR       A1, $C$CON23          ; [DPU_3_PIPE] |180| 
        LDR       A1, [A1, #0]          ; [DPU_3_PIPE] |180| 
        LSRS      A1, A1, #7            ; [DPU_3_PIPE] |180| 
        BCC       ||$C$L22||            ; [DPU_3_PIPE] |180| 
        ; BRANCHCC OCCURS {||$C$L22||}   ; [] |180| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 181,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 181 | UART0_ICR_R = UART_ICR_RTIC;        // acknowledge receiver time out   
; 182 | // copy from hardware RX FIFO to software RX FIFO                      
;----------------------------------------------------------------------
        LDR       A2, $C$CON24          ; [DPU_3_PIPE] |181| 
        MOVS      A1, #64               ; [DPU_3_PIPE] |181| 
        STR       A1, [A2, #0]          ; [DPU_3_PIPE] |181| 
	.dwpsn	file "../UART.c",line 183,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 183 | copyHardwareToSoftware();                                              
;----------------------------------------------------------------------
$C$DW$101	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$101, DW_AT_low_pc(0x00)
	.dwattr $C$DW$101, DW_AT_name("copyHardwareToSoftware")
	.dwattr $C$DW$101, DW_AT_TI_call
        BL        copyHardwareToSoftware ; [DPU_3_PIPE] |183| 
        ; CALL OCCURS {copyHardwareToSoftware }  ; [] |183| 
	.dwpsn	file "../UART.c",line 185,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L22||:    
$C$DW$102	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$102, DW_AT_low_pc(0x00)
	.dwattr $C$DW$102, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$97, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$97, DW_AT_TI_end_line(0xb9)
	.dwattr $C$DW$97, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$97

	.sect	".text"
	.clink
	.thumbfunc UART_OutString
	.thumb
	.global	UART_OutString

$C$DW$103	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_OutString")
	.dwattr $C$DW$103, DW_AT_low_pc(UART_OutString)
	.dwattr $C$DW$103, DW_AT_high_pc(0x00)
	.dwattr $C$DW$103, DW_AT_TI_symbol_name("UART_OutString")
	.dwattr $C$DW$103, DW_AT_external
	.dwattr $C$DW$103, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$103, DW_AT_TI_begin_line(0xbf)
	.dwattr $C$DW$103, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$103, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$103, DW_AT_decl_line(0xbf)
	.dwattr $C$DW$103, DW_AT_decl_column(0x06)
	.dwattr $C$DW$103, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 191,column 30,is_stmt,address UART_OutString,isa 1

	.dwfde $C$DW$CIE, UART_OutString
$C$DW$104	.dwtag  DW_TAG_formal_parameter, DW_AT_name("pt")
	.dwattr $C$DW$104, DW_AT_TI_symbol_name("pt")
	.dwattr $C$DW$104, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$104, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: UART_OutString                                             *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_OutString:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$105	.dwtag  DW_TAG_variable, DW_AT_name("pt")
	.dwattr $C$DW$105, DW_AT_TI_symbol_name("pt")
	.dwattr $C$DW$105, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$105, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 191 | void UART_OutString(char *pt){                                         
;----------------------------------------------------------------------
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |191| 
	.dwpsn	file "../UART.c",line 192,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 192 | while(*pt){                                                            
;----------------------------------------------------------------------
        B         ||$C$L24||            ; [DPU_3_PIPE] |192| 
        ; BRANCH OCCURS {||$C$L24||}     ; [] |192| 
;* --------------------------------------------------------------------------*
||$C$L23||:    
	.dwpsn	file "../UART.c",line 193,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 193 | UART_OutChar(*pt);                                                     
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |193| 
        LDRB      A1, [A1, #0]          ; [DPU_3_PIPE] |193| 
$C$DW$106	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$106, DW_AT_low_pc(0x00)
	.dwattr $C$DW$106, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$106, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |193| 
        ; CALL OCCURS {UART_OutChar }    ; [] |193| 
	.dwpsn	file "../UART.c",line 194,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 194 | pt++;                                                                  
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |194| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |194| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |194| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L24||
;* --------------------------------------------------------------------------*
||$C$L24||:    
	.dwpsn	file "../UART.c",line 192,column 3,is_stmt,isa 1
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |192| 
        LDRB      A1, [A1, #0]          ; [DPU_3_PIPE] |192| 
        CMP       A1, #0                ; [DPU_3_PIPE] |192| 
        BNE       ||$C$L23||            ; [DPU_3_PIPE] |192| 
        ; BRANCHCC OCCURS {||$C$L23||}   ; [] |192| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 196,column 1,is_stmt,isa 1
$C$DW$107	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$107, DW_AT_low_pc(0x00)
	.dwattr $C$DW$107, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$103, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$103, DW_AT_TI_end_line(0xc4)
	.dwattr $C$DW$103, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$103

;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON1||:	.bits	RxPutI,32
	.align	4
||$C$CON2||:	.bits	RxGetI,32
	.align	4
||$C$CON3||:	.bits	RxFifo,32
	.sect	".text"
	.clink
	.thumbfunc UART_InUDec
	.thumb
	.global	UART_InUDec

$C$DW$108	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InUDec")
	.dwattr $C$DW$108, DW_AT_low_pc(UART_InUDec)
	.dwattr $C$DW$108, DW_AT_high_pc(0x00)
	.dwattr $C$DW$108, DW_AT_TI_symbol_name("UART_InUDec")
	.dwattr $C$DW$108, DW_AT_external
	.dwattr $C$DW$108, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$108, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$108, DW_AT_TI_begin_line(0xce)
	.dwattr $C$DW$108, DW_AT_TI_begin_column(0x0a)
	.dwattr $C$DW$108, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$108, DW_AT_decl_line(0xce)
	.dwattr $C$DW$108, DW_AT_decl_column(0x0a)
	.dwattr $C$DW$108, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 206,column 27,is_stmt,address UART_InUDec,isa 1

	.dwfde $C$DW$CIE, UART_InUDec
;----------------------------------------------------------------------
; 206 | uint32_t UART_InUDec(void){                                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART_InUDec                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                 *
;*****************************************************************************
UART_InUDec:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A2, A3, A4, LR}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwcfi	save_reg_to_mem, 2, -12
	.dwcfi	save_reg_to_mem, 1, -16
$C$DW$109	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$109, DW_AT_TI_symbol_name("number")
	.dwattr $C$DW$109, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$109, DW_AT_location[DW_OP_breg13 0]
$C$DW$110	.dwtag  DW_TAG_variable, DW_AT_name("length")
	.dwattr $C$DW$110, DW_AT_TI_symbol_name("length")
	.dwattr $C$DW$110, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$110, DW_AT_location[DW_OP_breg13 4]
$C$DW$111	.dwtag  DW_TAG_variable, DW_AT_name("character")
	.dwattr $C$DW$111, DW_AT_TI_symbol_name("character")
	.dwattr $C$DW$111, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$111, DW_AT_location[DW_OP_breg13 8]
	.dwpsn	file "../UART.c",line 207,column 16,is_stmt,isa 1
;----------------------------------------------------------------------
; 207 | uint32_t number=0, length=0;                                           
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |207| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |207| 
	.dwpsn	file "../UART.c",line 207,column 26,is_stmt,isa 1
;----------------------------------------------------------------------
; 208 | char character;                                                        
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |207| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |207| 
	.dwpsn	file "../UART.c",line 209,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 209 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$112	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$112, DW_AT_low_pc(0x00)
	.dwattr $C$DW$112, DW_AT_name("UART_InChar")
	.dwattr $C$DW$112, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |209| 
        ; CALL OCCURS {UART_InChar }     ; [] |209| 
        STRB      A1, [SP, #8]          ; [DPU_3_PIPE] |209| 
	.dwpsn	file "../UART.c",line 210,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 210 | while(character != CR){ // accepts until <enter> is typed              
; 211 | // The next line checks that the input is a digit, 0-9.                
; 212 | // If the character is not 0-9, it is ignored and not echoed           
;----------------------------------------------------------------------
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |210| 
        CMP       A1, #13               ; [DPU_3_PIPE] |210| 
        BEQ       ||$C$L28||            ; [DPU_3_PIPE] |210| 
        ; BRANCHCC OCCURS {||$C$L28||}   ; [] |210| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L25||
;*
;*   Loop source line                : 210
;*   Loop closing brace source line  : 226
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L25||:    
	.dwpsn	file "../UART.c",line 213,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 213 | if((character>='0') && (character<='9')) {                             
;----------------------------------------------------------------------
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |213| 
        CMP       A1, #48               ; [DPU_3_PIPE] |213| 
        BLT       ||$C$L26||            ; [DPU_3_PIPE] |213| 
        ; BRANCHCC OCCURS {||$C$L26||}   ; [] |213| 
;* --------------------------------------------------------------------------*
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |213| 
        CMP       A1, #57               ; [DPU_3_PIPE] |213| 
        BGT       ||$C$L26||            ; [DPU_3_PIPE] |213| 
        ; BRANCHCC OCCURS {||$C$L26||}   ; [] |213| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 214,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 214 | number = 10*number+(character-'0');   // this line overflows if above 4
;     | 294967295                                                              
;----------------------------------------------------------------------
        LDR       A3, [SP, #0]          ; [DPU_3_PIPE] |214| 
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |214| 
        LSLS      A2, A3, #1            ; [DPU_3_PIPE] |214| 
        SUBS      A1, A1, #48           ; [DPU_3_PIPE] |214| 
        ADD       A2, A2, A3, LSL #3    ; [DPU_3_PIPE] |214| 
        ADDS      A2, A2, A1            ; [DPU_3_PIPE] |214| 
        STR       A2, [SP, #0]          ; [DPU_3_PIPE] |214| 
	.dwpsn	file "../UART.c",line 215,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 215 | length++;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |215| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |215| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |215| 
	.dwpsn	file "../UART.c",line 216,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 216 | UART_OutChar(character);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |216| 
$C$DW$113	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$113, DW_AT_low_pc(0x00)
	.dwattr $C$DW$113, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$113, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |216| 
        ; CALL OCCURS {UART_OutChar }    ; [] |216| 
	.dwpsn	file "../UART.c",line 217,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 218 | // If the input is a backspace, then the return number is              
; 219 | // changed and a backspace is outputted to the screen                  
;----------------------------------------------------------------------
        B         ||$C$L27||            ; [DPU_3_PIPE] |217| 
        ; BRANCH OCCURS {||$C$L27||}     ; [] |217| 
;* --------------------------------------------------------------------------*
||$C$L26||:    
	.dwpsn	file "../UART.c",line 220,column 10,is_stmt,isa 1
;----------------------------------------------------------------------
; 220 | else if((character==BS) && length){                                    
;----------------------------------------------------------------------
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |220| 
        CMP       A1, #8                ; [DPU_3_PIPE] |220| 
        BNE       ||$C$L27||            ; [DPU_3_PIPE] |220| 
        ; BRANCHCC OCCURS {||$C$L27||}   ; [] |220| 
;* --------------------------------------------------------------------------*
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |220| 
        CBZ       A1, ||$C$L27||        ; [] 
        ; BRANCHCC OCCURS {||$C$L27||}   ; [] |220| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 221,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 221 | number /= 10;                                                          
;----------------------------------------------------------------------
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |221| 
        MOVS      A1, #10               ; [DPU_3_PIPE] |221| 
        UDIV      A1, A2, A1            ; [DPU_3_PIPE] |221| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |221| 
	.dwpsn	file "../UART.c",line 222,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 222 | length--;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |222| 
        SUBS      A1, A1, #1            ; [DPU_3_PIPE] |222| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |222| 
	.dwpsn	file "../UART.c",line 223,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 223 | UART_OutChar(character);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |223| 
$C$DW$114	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$114, DW_AT_low_pc(0x00)
	.dwattr $C$DW$114, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$114, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |223| 
        ; CALL OCCURS {UART_OutChar }    ; [] |223| 
;* --------------------------------------------------------------------------*
||$C$L27||:    
	.dwpsn	file "../UART.c",line 225,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 225 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$115	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$115, DW_AT_low_pc(0x00)
	.dwattr $C$DW$115, DW_AT_name("UART_InChar")
	.dwattr $C$DW$115, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |225| 
        ; CALL OCCURS {UART_InChar }     ; [] |225| 
        STRB      A1, [SP, #8]          ; [DPU_3_PIPE] |225| 
	.dwpsn	file "../UART.c",line 210,column 9,is_stmt,isa 1
        LDRB      A1, [SP, #8]          ; [DPU_3_PIPE] |210| 
        CMP       A1, #13               ; [DPU_3_PIPE] |210| 
        BNE       ||$C$L25||            ; [DPU_3_PIPE] |210| 
        ; BRANCHCC OCCURS {||$C$L25||}   ; [] |210| 
;* --------------------------------------------------------------------------*
||$C$L28||:    
	.dwpsn	file "../UART.c",line 227,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 227 | return number;                                                         
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |227| 
	.dwpsn	file "../UART.c",line 228,column 1,is_stmt,isa 1
$C$DW$116	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$116, DW_AT_low_pc(0x00)
	.dwattr $C$DW$116, DW_AT_TI_return
        POP       {A2, A3, A4, PC}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$108, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$108, DW_AT_TI_end_line(0xe4)
	.dwattr $C$DW$108, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$108

;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON4||:	.bits	TxPutI,32
	.align	4
||$C$CON5||:	.bits	TxGetI,32
	.sect	".text"
	.clink
	.thumbfunc UART_OutUDec
	.thumb
	.global	UART_OutUDec

$C$DW$117	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_OutUDec")
	.dwattr $C$DW$117, DW_AT_low_pc(UART_OutUDec)
	.dwattr $C$DW$117, DW_AT_high_pc(0x00)
	.dwattr $C$DW$117, DW_AT_TI_symbol_name("UART_OutUDec")
	.dwattr $C$DW$117, DW_AT_external
	.dwattr $C$DW$117, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$117, DW_AT_TI_begin_line(0xeb)
	.dwattr $C$DW$117, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$117, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$117, DW_AT_decl_line(0xeb)
	.dwattr $C$DW$117, DW_AT_decl_column(0x06)
	.dwattr $C$DW$117, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 235,column 30,is_stmt,address UART_OutUDec,isa 1

	.dwfde $C$DW$CIE, UART_OutUDec
$C$DW$118	.dwtag  DW_TAG_formal_parameter, DW_AT_name("n")
	.dwattr $C$DW$118, DW_AT_TI_symbol_name("n")
	.dwattr $C$DW$118, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$118, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: UART_OutUDec                                               *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_OutUDec:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$119	.dwtag  DW_TAG_variable, DW_AT_name("n")
	.dwattr $C$DW$119, DW_AT_TI_symbol_name("n")
	.dwattr $C$DW$119, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$119, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 235 | void UART_OutUDec(uint32_t n){                                         
; 236 | // This function uses recursion to convert decimal number              
; 237 | //   of unspecified length as an ASCII string                          
;----------------------------------------------------------------------
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |235| 
	.dwpsn	file "../UART.c",line 238,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 238 | if(n >= 10){                                                           
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |238| 
        CMP       A1, #10               ; [DPU_3_PIPE] |238| 
        BCC       ||$C$L29||            ; [DPU_3_PIPE] |238| 
        ; BRANCHCC OCCURS {||$C$L29||}   ; [] |238| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 239,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 239 | UART_OutUDec(n/10);                                                    
;----------------------------------------------------------------------
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |239| 
        MOVS      A1, #10               ; [DPU_3_PIPE] |239| 
        UDIV      A1, A2, A1            ; [DPU_3_PIPE] |239| 
$C$DW$120	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$120, DW_AT_low_pc(0x00)
	.dwattr $C$DW$120, DW_AT_name("UART_OutUDec")
	.dwattr $C$DW$120, DW_AT_TI_call
        BL        UART_OutUDec          ; [DPU_3_PIPE] |239| 
        ; CALL OCCURS {UART_OutUDec }    ; [] |239| 
	.dwpsn	file "../UART.c",line 240,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 240 | n = n%10;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |240| 
        MOVS      A3, #10               ; [DPU_3_PIPE] |240| 
        UDIV      A2, A1, A3            ; [DPU_3_PIPE] |240| 
        MULS      A2, A2, A3            ; [DPU_3_PIPE] |240| 
        SUBS      A1, A1, A2            ; [DPU_3_PIPE] |240| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |240| 
;* --------------------------------------------------------------------------*
||$C$L29||:    
	.dwpsn	file "../UART.c",line 242,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 242 | UART_OutChar(n+'0'); /* n is between 0 and 9 */                        
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |242| 
        ADDS      A1, A1, #48           ; [DPU_3_PIPE] |242| 
        UXTB      A1, A1                ; [DPU_3_PIPE] |242| 
$C$DW$121	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$121, DW_AT_low_pc(0x00)
	.dwattr $C$DW$121, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$121, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |242| 
        ; CALL OCCURS {UART_OutChar }    ; [] |242| 
	.dwpsn	file "../UART.c",line 243,column 1,is_stmt,isa 1
$C$DW$122	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$122, DW_AT_low_pc(0x00)
	.dwattr $C$DW$122, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$117, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$117, DW_AT_TI_end_line(0xf3)
	.dwattr $C$DW$117, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$117

;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON6||:	.bits	TxFifo,32
	.align	4
||$C$CON7||:	.bits	1074783768,32
	.align	4
||$C$CON8||:	.bits	1074783752,32
	.align	4
||$C$CON9||:	.bits	1073791024,32
	.align	4
||$C$CON10||:	.bits	1073791012,32
	.align	4
||$C$CON11||:	.bits	1073791016,32
	.align	4
||$C$CON12||:	.bits	1073791020,32
	.align	4
||$C$CON13||:	.bits	1073791028,32
	.align	4
||$C$CON14||:	.bits	1073791032,32
	.align	4
||$C$CON15||:	.bits	1073759264,32
	.align	4
||$C$CON16||:	.bits	1073759516,32
	.align	4
||$C$CON17||:	.bits	1073759532,32
	.align	4
||$C$CON18||:	.bits	1073759528,32
	.align	4
||$C$CON19||:	.bits	-536812540,32
	.align	4
||$C$CON20||:	.bits	-536813312,32
	.align	4
||$C$CON21||:	.bits	1073790976,32
	.sect	".text"
	.clink
	.thumbfunc UART_InUHex
	.thumb
	.global	UART_InUHex

$C$DW$123	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InUHex")
	.dwattr $C$DW$123, DW_AT_low_pc(UART_InUHex)
	.dwattr $C$DW$123, DW_AT_high_pc(0x00)
	.dwattr $C$DW$123, DW_AT_TI_symbol_name("UART_InUHex")
	.dwattr $C$DW$123, DW_AT_external
	.dwattr $C$DW$123, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$123, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$123, DW_AT_TI_begin_line(0xff)
	.dwattr $C$DW$123, DW_AT_TI_begin_column(0x0a)
	.dwattr $C$DW$123, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$123, DW_AT_decl_line(0xff)
	.dwattr $C$DW$123, DW_AT_decl_column(0x0a)
	.dwattr $C$DW$123, DW_AT_TI_max_frame_size(0x18)
	.dwpsn	file "../UART.c",line 255,column 27,is_stmt,address UART_InUHex,isa 1

	.dwfde $C$DW$CIE, UART_InUHex
;----------------------------------------------------------------------
; 255 | uint32_t UART_InUHex(void){                                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: UART_InUHex                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 16 Auto + 4 Save = 20 byte                 *
;*****************************************************************************
UART_InUHex:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {LR}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
	.dwcfi	save_reg_to_mem, 14, -4
        SUB       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 24
$C$DW$124	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$124, DW_AT_TI_symbol_name("number")
	.dwattr $C$DW$124, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$124, DW_AT_location[DW_OP_breg13 0]
$C$DW$125	.dwtag  DW_TAG_variable, DW_AT_name("digit")
	.dwattr $C$DW$125, DW_AT_TI_symbol_name("digit")
	.dwattr $C$DW$125, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$125, DW_AT_location[DW_OP_breg13 4]
$C$DW$126	.dwtag  DW_TAG_variable, DW_AT_name("length")
	.dwattr $C$DW$126, DW_AT_TI_symbol_name("length")
	.dwattr $C$DW$126, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$126, DW_AT_location[DW_OP_breg13 8]
$C$DW$127	.dwtag  DW_TAG_variable, DW_AT_name("character")
	.dwattr $C$DW$127, DW_AT_TI_symbol_name("character")
	.dwattr $C$DW$127, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$127, DW_AT_location[DW_OP_breg13 12]
	.dwpsn	file "../UART.c",line 256,column 16,is_stmt,isa 1
;----------------------------------------------------------------------
; 256 | uint32_t number=0, digit, length=0;                                    
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |256| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |256| 
	.dwpsn	file "../UART.c",line 256,column 33,is_stmt,isa 1
;----------------------------------------------------------------------
; 257 | char character;                                                        
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |256| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |256| 
	.dwpsn	file "../UART.c",line 258,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 258 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$128	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$128, DW_AT_low_pc(0x00)
	.dwattr $C$DW$128, DW_AT_name("UART_InChar")
	.dwattr $C$DW$128, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |258| 
        ; CALL OCCURS {UART_InChar }     ; [] |258| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |258| 
	.dwpsn	file "../UART.c",line 259,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 259 | while(character != CR){                                                
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |259| 
        CMP       A1, #13               ; [DPU_3_PIPE] |259| 
        BEQ       ||$C$L36||            ; [DPU_3_PIPE] |259| 
        ; BRANCHCC OCCURS {||$C$L36||}   ; [] |259| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L30||
;*
;*   Loop source line                : 259
;*   Loop closing brace source line  : 283
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L30||:    
	.dwpsn	file "../UART.c",line 260,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 260 | digit = 0x10; // assume bad                                            
;----------------------------------------------------------------------
        MOVS      A1, #16               ; [DPU_3_PIPE] |260| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |260| 
	.dwpsn	file "../UART.c",line 261,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 261 | if((character>='0') && (character<='9')){                              
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |261| 
        CMP       A1, #48               ; [DPU_3_PIPE] |261| 
        BLT       ||$C$L31||            ; [DPU_3_PIPE] |261| 
        ; BRANCHCC OCCURS {||$C$L31||}   ; [] |261| 
;* --------------------------------------------------------------------------*
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |261| 
        CMP       A1, #57               ; [DPU_3_PIPE] |261| 
        BGT       ||$C$L31||            ; [DPU_3_PIPE] |261| 
        ; BRANCHCC OCCURS {||$C$L31||}   ; [] |261| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 262,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 262 | digit = character-'0';                                                 
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |262| 
        SUBS      A1, A1, #48           ; [DPU_3_PIPE] |262| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |262| 
	.dwpsn	file "../UART.c",line 263,column 5,is_stmt,isa 1
        B         ||$C$L33||            ; [DPU_3_PIPE] |263| 
        ; BRANCH OCCURS {||$C$L33||}     ; [] |263| 
;* --------------------------------------------------------------------------*
||$C$L31||:    
	.dwpsn	file "../UART.c",line 264,column 10,is_stmt,isa 1
;----------------------------------------------------------------------
; 264 | else if((character>='A') && (character<='F')){                         
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |264| 
        CMP       A1, #65               ; [DPU_3_PIPE] |264| 
        BLT       ||$C$L32||            ; [DPU_3_PIPE] |264| 
        ; BRANCHCC OCCURS {||$C$L32||}   ; [] |264| 
;* --------------------------------------------------------------------------*
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |264| 
        CMP       A1, #70               ; [DPU_3_PIPE] |264| 
        BGT       ||$C$L32||            ; [DPU_3_PIPE] |264| 
        ; BRANCHCC OCCURS {||$C$L32||}   ; [] |264| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 265,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 265 | digit = (character-'A')+0xA;                                           
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |265| 
        SUBS      A1, A1, #55           ; [DPU_3_PIPE] |265| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |265| 
	.dwpsn	file "../UART.c",line 266,column 5,is_stmt,isa 1
        B         ||$C$L33||            ; [DPU_3_PIPE] |266| 
        ; BRANCH OCCURS {||$C$L33||}     ; [] |266| 
;* --------------------------------------------------------------------------*
||$C$L32||:    
	.dwpsn	file "../UART.c",line 267,column 10,is_stmt,isa 1
;----------------------------------------------------------------------
; 267 | else if((character>='a') && (character<='f')){                         
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |267| 
        CMP       A1, #97               ; [DPU_3_PIPE] |267| 
        BLT       ||$C$L33||            ; [DPU_3_PIPE] |267| 
        ; BRANCHCC OCCURS {||$C$L33||}   ; [] |267| 
;* --------------------------------------------------------------------------*
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |267| 
        CMP       A1, #102              ; [DPU_3_PIPE] |267| 
        BGT       ||$C$L33||            ; [DPU_3_PIPE] |267| 
        ; BRANCHCC OCCURS {||$C$L33||}   ; [] |267| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 268,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 268 | digit = (character-'a')+0xA;                                           
; 270 | // If the character is not 0-9 or A-F, it is ignored and not echoed    
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |268| 
        SUBS      A1, A1, #87           ; [DPU_3_PIPE] |268| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |268| 
;* --------------------------------------------------------------------------*
||$C$L33||:    
	.dwpsn	file "../UART.c",line 271,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 271 | if(digit <= 0xF){                                                      
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |271| 
        CMP       A1, #15               ; [DPU_3_PIPE] |271| 
        BHI       ||$C$L34||            ; [DPU_3_PIPE] |271| 
        ; BRANCHCC OCCURS {||$C$L34||}   ; [] |271| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 272,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 272 | number = number*0x10+digit;                                            
;----------------------------------------------------------------------
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |272| 
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |272| 
        ADD       A1, A1, A2, LSL #4    ; [DPU_3_PIPE] |272| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |272| 
	.dwpsn	file "../UART.c",line 273,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 273 | length++;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |273| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |273| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |273| 
	.dwpsn	file "../UART.c",line 274,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 274 | UART_OutChar(character);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |274| 
$C$DW$129	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$129, DW_AT_low_pc(0x00)
	.dwattr $C$DW$129, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$129, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |274| 
        ; CALL OCCURS {UART_OutChar }    ; [] |274| 
	.dwpsn	file "../UART.c",line 275,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 276 | // Backspace outputted and return value changed if a backspace is input
;     | ted                                                                    
;----------------------------------------------------------------------
        B         ||$C$L35||            ; [DPU_3_PIPE] |275| 
        ; BRANCH OCCURS {||$C$L35||}     ; [] |275| 
;* --------------------------------------------------------------------------*
||$C$L34||:    
	.dwpsn	file "../UART.c",line 277,column 10,is_stmt,isa 1
;----------------------------------------------------------------------
; 277 | else if((character==BS) && length){                                    
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |277| 
        CMP       A1, #8                ; [DPU_3_PIPE] |277| 
        BNE       ||$C$L35||            ; [DPU_3_PIPE] |277| 
        ; BRANCHCC OCCURS {||$C$L35||}   ; [] |277| 
;* --------------------------------------------------------------------------*
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |277| 
        CBZ       A1, ||$C$L35||        ; [] 
        ; BRANCHCC OCCURS {||$C$L35||}   ; [] |277| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 278,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 278 | number /= 0x10;                                                        
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |278| 
        LSRS      A1, A1, #4            ; [DPU_3_PIPE] |278| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |278| 
	.dwpsn	file "../UART.c",line 279,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 279 | length--;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |279| 
        SUBS      A1, A1, #1            ; [DPU_3_PIPE] |279| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |279| 
	.dwpsn	file "../UART.c",line 280,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 280 | UART_OutChar(character);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |280| 
$C$DW$130	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$130, DW_AT_low_pc(0x00)
	.dwattr $C$DW$130, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$130, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |280| 
        ; CALL OCCURS {UART_OutChar }    ; [] |280| 
;* --------------------------------------------------------------------------*
||$C$L35||:    
	.dwpsn	file "../UART.c",line 282,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 282 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$131	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$131, DW_AT_low_pc(0x00)
	.dwattr $C$DW$131, DW_AT_name("UART_InChar")
	.dwattr $C$DW$131, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |282| 
        ; CALL OCCURS {UART_InChar }     ; [] |282| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |282| 
	.dwpsn	file "../UART.c",line 259,column 9,is_stmt,isa 1
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |259| 
        CMP       A1, #13               ; [DPU_3_PIPE] |259| 
        BNE       ||$C$L30||            ; [DPU_3_PIPE] |259| 
        ; BRANCHCC OCCURS {||$C$L30||}   ; [] |259| 
;* --------------------------------------------------------------------------*
||$C$L36||:    
	.dwpsn	file "../UART.c",line 284,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 284 | return number;                                                         
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |284| 
	.dwpsn	file "../UART.c",line 285,column 1,is_stmt,isa 1
        ADD       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
$C$DW$132	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$132, DW_AT_low_pc(0x00)
	.dwattr $C$DW$132, DW_AT_TI_return
        POP       {PC}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$123, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$123, DW_AT_TI_end_line(0x11d)
	.dwattr $C$DW$123, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$123

;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON22||:	.bits	1073791000,32
	.sect	".text"
	.clink
	.thumbfunc UART_OutUHex
	.thumb
	.global	UART_OutUHex

$C$DW$133	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_OutUHex")
	.dwattr $C$DW$133, DW_AT_low_pc(UART_OutUHex)
	.dwattr $C$DW$133, DW_AT_high_pc(0x00)
	.dwattr $C$DW$133, DW_AT_TI_symbol_name("UART_OutUHex")
	.dwattr $C$DW$133, DW_AT_external
	.dwattr $C$DW$133, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$133, DW_AT_TI_begin_line(0x124)
	.dwattr $C$DW$133, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$133, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$133, DW_AT_decl_line(0x124)
	.dwattr $C$DW$133, DW_AT_decl_column(0x06)
	.dwattr $C$DW$133, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 292,column 35,is_stmt,address UART_OutUHex,isa 1

	.dwfde $C$DW$CIE, UART_OutUHex
$C$DW$134	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$134, DW_AT_TI_symbol_name("number")
	.dwattr $C$DW$134, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$134, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: UART_OutUHex                                               *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                   *
;*****************************************************************************
UART_OutUHex:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A4, LR}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
$C$DW$135	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$135, DW_AT_TI_symbol_name("number")
	.dwattr $C$DW$135, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$135, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 292 | void UART_OutUHex(uint32_t number){                                    
; 293 | // This function uses recursion to convert the number of               
; 294 | //   unspecified length as an ASCII string                             
;----------------------------------------------------------------------
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |292| 
	.dwpsn	file "../UART.c",line 295,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 295 | if(number >= 0x10){                                                    
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |295| 
        CMP       A1, #16               ; [DPU_3_PIPE] |295| 
        BCC       ||$C$L37||            ; [DPU_3_PIPE] |295| 
        ; BRANCHCC OCCURS {||$C$L37||}   ; [] |295| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 296,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 296 | UART_OutUHex(number/0x10);                                             
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |296| 
        LSRS      A1, A1, #4            ; [DPU_3_PIPE] |296| 
$C$DW$136	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$136, DW_AT_low_pc(0x00)
	.dwattr $C$DW$136, DW_AT_name("UART_OutUHex")
	.dwattr $C$DW$136, DW_AT_TI_call
        BL        UART_OutUHex          ; [DPU_3_PIPE] |296| 
        ; CALL OCCURS {UART_OutUHex }    ; [] |296| 
	.dwpsn	file "../UART.c",line 297,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 297 | UART_OutUHex(number%0x10);                                             
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |297| 
        AND       A1, A1, #15           ; [DPU_3_PIPE] |297| 
$C$DW$137	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$137, DW_AT_low_pc(0x00)
	.dwattr $C$DW$137, DW_AT_name("UART_OutUHex")
	.dwattr $C$DW$137, DW_AT_TI_call
        BL        UART_OutUHex          ; [DPU_3_PIPE] |297| 
        ; CALL OCCURS {UART_OutUHex }    ; [] |297| 
	.dwpsn	file "../UART.c",line 298,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 299 | else{                                                                  
;----------------------------------------------------------------------
        B         ||$C$L39||            ; [DPU_3_PIPE] |298| 
        ; BRANCH OCCURS {||$C$L39||}     ; [] |298| 
;* --------------------------------------------------------------------------*
||$C$L37||:    
	.dwpsn	file "../UART.c",line 300,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 300 | if(number < 0xA){                                                      
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |300| 
        CMP       A1, #10               ; [DPU_3_PIPE] |300| 
        BCS       ||$C$L38||            ; [DPU_3_PIPE] |300| 
        ; BRANCHCC OCCURS {||$C$L38||}   ; [] |300| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 301,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 301 | UART_OutChar(number+'0');                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |301| 
        ADDS      A1, A1, #48           ; [DPU_3_PIPE] |301| 
        UXTB      A1, A1                ; [DPU_3_PIPE] |301| 
$C$DW$138	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$138, DW_AT_low_pc(0x00)
	.dwattr $C$DW$138, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$138, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |301| 
        ; CALL OCCURS {UART_OutChar }    ; [] |301| 
	.dwpsn	file "../UART.c",line 302,column 6,is_stmt,isa 1
;----------------------------------------------------------------------
; 303 | else{                                                                  
;----------------------------------------------------------------------
        B         ||$C$L39||            ; [DPU_3_PIPE] |302| 
        ; BRANCH OCCURS {||$C$L39||}     ; [] |302| 
;* --------------------------------------------------------------------------*
||$C$L38||:    
	.dwpsn	file "../UART.c",line 304,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 304 | UART_OutChar((number-0x0A)+'A');                                       
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |304| 
        ADDS      A1, A1, #55           ; [DPU_3_PIPE] |304| 
        UXTB      A1, A1                ; [DPU_3_PIPE] |304| 
$C$DW$139	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$139, DW_AT_low_pc(0x00)
	.dwattr $C$DW$139, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$139, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |304| 
        ; CALL OCCURS {UART_OutChar }    ; [] |304| 
	.dwpsn	file "../UART.c",line 307,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L39||:    
$C$DW$140	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$140, DW_AT_low_pc(0x00)
	.dwattr $C$DW$140, DW_AT_TI_return
        POP       {A4, PC}              ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$133, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$133, DW_AT_TI_end_line(0x133)
	.dwattr $C$DW$133, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$133

;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON23||:	.bits	1073791036,32
	.align	4
||$C$CON24||:	.bits	1073791044,32
	.sect	".text"
	.clink
	.thumbfunc UART_InString
	.thumb
	.global	UART_InString

$C$DW$141	.dwtag  DW_TAG_subprogram, DW_AT_name("UART_InString")
	.dwattr $C$DW$141, DW_AT_low_pc(UART_InString)
	.dwattr $C$DW$141, DW_AT_high_pc(0x00)
	.dwattr $C$DW$141, DW_AT_TI_symbol_name("UART_InString")
	.dwattr $C$DW$141, DW_AT_external
	.dwattr $C$DW$141, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$141, DW_AT_TI_begin_line(0x141)
	.dwattr $C$DW$141, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$141, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$141, DW_AT_decl_line(0x141)
	.dwattr $C$DW$141, DW_AT_decl_column(0x06)
	.dwattr $C$DW$141, DW_AT_TI_max_frame_size(0x18)
	.dwpsn	file "../UART.c",line 321,column 47,is_stmt,address UART_InString,isa 1

	.dwfde $C$DW$CIE, UART_InString
$C$DW$142	.dwtag  DW_TAG_formal_parameter, DW_AT_name("bufPt")
	.dwattr $C$DW$142, DW_AT_TI_symbol_name("bufPt")
	.dwattr $C$DW$142, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$142, DW_AT_location[DW_OP_reg0]
$C$DW$143	.dwtag  DW_TAG_formal_parameter, DW_AT_name("max")
	.dwattr $C$DW$143, DW_AT_TI_symbol_name("max")
	.dwattr $C$DW$143, DW_AT_type(*$C$DW$T$43)
	.dwattr $C$DW$143, DW_AT_location[DW_OP_reg1]

;*****************************************************************************
;* FUNCTION NAME: UART_InString                                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 16 Auto + 4 Save = 20 byte                 *
;*****************************************************************************
UART_InString:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {LR}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
	.dwcfi	save_reg_to_mem, 14, -4
        SUB       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 24
$C$DW$144	.dwtag  DW_TAG_variable, DW_AT_name("bufPt")
	.dwattr $C$DW$144, DW_AT_TI_symbol_name("bufPt")
	.dwattr $C$DW$144, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$144, DW_AT_location[DW_OP_breg13 0]
$C$DW$145	.dwtag  DW_TAG_variable, DW_AT_name("max")
	.dwattr $C$DW$145, DW_AT_TI_symbol_name("max")
	.dwattr $C$DW$145, DW_AT_type(*$C$DW$T$43)
	.dwattr $C$DW$145, DW_AT_location[DW_OP_breg13 4]
$C$DW$146	.dwtag  DW_TAG_variable, DW_AT_name("length")
	.dwattr $C$DW$146, DW_AT_TI_symbol_name("length")
	.dwattr $C$DW$146, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$146, DW_AT_location[DW_OP_breg13 8]
$C$DW$147	.dwtag  DW_TAG_variable, DW_AT_name("character")
	.dwattr $C$DW$147, DW_AT_TI_symbol_name("character")
	.dwattr $C$DW$147, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$147, DW_AT_location[DW_OP_breg13 12]
;----------------------------------------------------------------------
; 321 | void UART_InString(char *bufPt, uint16_t max) {                        
;----------------------------------------------------------------------
        STRH      A2, [SP, #4]          ; [DPU_3_PIPE] |321| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |321| 
	.dwpsn	file "../UART.c",line 322,column 11,is_stmt,isa 1
;----------------------------------------------------------------------
; 322 | int length=0;                                                          
; 323 | char character;                                                        
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |322| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |322| 
	.dwpsn	file "../UART.c",line 324,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 324 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$148	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$148, DW_AT_low_pc(0x00)
	.dwattr $C$DW$148, DW_AT_name("UART_InChar")
	.dwattr $C$DW$148, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |324| 
        ; CALL OCCURS {UART_InChar }     ; [] |324| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |324| 
	.dwpsn	file "../UART.c",line 325,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 325 | while(character != CR){                                                
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |325| 
        CMP       A1, #13               ; [DPU_3_PIPE] |325| 
        BEQ       ||$C$L43||            ; [DPU_3_PIPE] |325| 
        ; BRANCHCC OCCURS {||$C$L43||}   ; [] |325| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L40||
;*
;*   Loop source line                : 325
;*   Loop closing brace source line  : 340
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L40||:    
	.dwpsn	file "../UART.c",line 326,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 326 | if(character == BS){                                                   
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |326| 
        CMP       A1, #8                ; [DPU_3_PIPE] |326| 
        BNE       ||$C$L41||            ; [DPU_3_PIPE] |326| 
        ; BRANCHCC OCCURS {||$C$L41||}   ; [] |326| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 327,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 327 | if(length){                                                            
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |327| 
        CBZ       A1, ||$C$L42||        ; [] 
        ; BRANCHCC OCCURS {||$C$L42||}   ; [] |327| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 328,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 328 | bufPt--;                                                               
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |328| 
        SUBS      A1, A1, #1            ; [DPU_3_PIPE] |328| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |328| 
	.dwpsn	file "../UART.c",line 329,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 329 | length--;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |329| 
        SUBS      A1, A1, #1            ; [DPU_3_PIPE] |329| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |329| 
	.dwpsn	file "../UART.c",line 330,column 9,is_stmt,isa 1
;----------------------------------------------------------------------
; 330 | UART_OutChar(BS);                                                      
;----------------------------------------------------------------------
        MOVS      A1, #8                ; [DPU_3_PIPE] |330| 
$C$DW$149	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$149, DW_AT_low_pc(0x00)
	.dwattr $C$DW$149, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$149, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |330| 
        ; CALL OCCURS {UART_OutChar }    ; [] |330| 
	.dwpsn	file "../UART.c",line 332,column 5,is_stmt,isa 1
        B         ||$C$L42||            ; [DPU_3_PIPE] |332| 
        ; BRANCH OCCURS {||$C$L42||}     ; [] |332| 
;* --------------------------------------------------------------------------*
||$C$L41||:    
	.dwpsn	file "../UART.c",line 333,column 10,is_stmt,isa 1
;----------------------------------------------------------------------
; 333 | else if(length < max){                                                 
;----------------------------------------------------------------------
        LDRH      A1, [SP, #4]          ; [DPU_3_PIPE] |333| 
        LDR       A2, [SP, #8]          ; [DPU_3_PIPE] |333| 
        CMP       A1, A2                ; [DPU_3_PIPE] |333| 
        BLE       ||$C$L42||            ; [DPU_3_PIPE] |333| 
        ; BRANCHCC OCCURS {||$C$L42||}   ; [] |333| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 334,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 334 | *bufPt = character;                                                    
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |334| 
        LDR       A2, [SP, #0]          ; [DPU_3_PIPE] |334| 
        STRB      A1, [A2, #0]          ; [DPU_3_PIPE] |334| 
	.dwpsn	file "../UART.c",line 335,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 335 | bufPt++;                                                               
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |335| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |335| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |335| 
	.dwpsn	file "../UART.c",line 336,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 336 | length++;                                                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |336| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |336| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |336| 
	.dwpsn	file "../UART.c",line 337,column 7,is_stmt,isa 1
;----------------------------------------------------------------------
; 337 | UART_OutChar(character);                                               
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |337| 
$C$DW$150	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$150, DW_AT_low_pc(0x00)
	.dwattr $C$DW$150, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$150, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |337| 
        ; CALL OCCURS {UART_OutChar }    ; [] |337| 
;* --------------------------------------------------------------------------*
||$C$L42||:    
	.dwpsn	file "../UART.c",line 339,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 339 | character = UART_InChar();                                             
;----------------------------------------------------------------------
$C$DW$151	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$151, DW_AT_low_pc(0x00)
	.dwattr $C$DW$151, DW_AT_name("UART_InChar")
	.dwattr $C$DW$151, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |339| 
        ; CALL OCCURS {UART_InChar }     ; [] |339| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |339| 
	.dwpsn	file "../UART.c",line 325,column 9,is_stmt,isa 1
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |325| 
        CMP       A1, #13               ; [DPU_3_PIPE] |325| 
        BNE       ||$C$L40||            ; [DPU_3_PIPE] |325| 
        ; BRANCHCC OCCURS {||$C$L40||}   ; [] |325| 
;* --------------------------------------------------------------------------*
||$C$L43||:    
	.dwpsn	file "../UART.c",line 341,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 341 | *bufPt = 0;                                                            
;----------------------------------------------------------------------
        LDR       A1, [SP, #0]          ; [DPU_3_PIPE] |341| 
        MOVS      A2, #0                ; [DPU_3_PIPE] |341| 
        STRB      A2, [A1, #0]          ; [DPU_3_PIPE] |341| 
	.dwpsn	file "../UART.c",line 342,column 1,is_stmt,isa 1
        ADD       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
$C$DW$152	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$152, DW_AT_low_pc(0x00)
	.dwattr $C$DW$152, DW_AT_TI_return
        POP       {PC}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$141, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$141, DW_AT_TI_end_line(0x156)
	.dwattr $C$DW$141, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$141

	.sect	".text"
	.clink
	.thumbfunc fputc
	.thumb
	.global	fputc

$C$DW$153	.dwtag  DW_TAG_subprogram, DW_AT_name("fputc")
	.dwattr $C$DW$153, DW_AT_low_pc(fputc)
	.dwattr $C$DW$153, DW_AT_high_pc(0x00)
	.dwattr $C$DW$153, DW_AT_TI_symbol_name("fputc")
	.dwattr $C$DW$153, DW_AT_external
	.dwattr $C$DW$153, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$153, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$153, DW_AT_TI_begin_line(0x15a)
	.dwattr $C$DW$153, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$153, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$153, DW_AT_decl_line(0x15a)
	.dwattr $C$DW$153, DW_AT_decl_column(0x05)
	.dwattr $C$DW$153, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 346,column 27,is_stmt,address fputc,isa 1

	.dwfde $C$DW$CIE, fputc
$C$DW$154	.dwtag  DW_TAG_formal_parameter, DW_AT_name("ch")
	.dwattr $C$DW$154, DW_AT_TI_symbol_name("ch")
	.dwattr $C$DW$154, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$154, DW_AT_location[DW_OP_reg0]
$C$DW$155	.dwtag  DW_TAG_formal_parameter, DW_AT_name("f")
	.dwattr $C$DW$155, DW_AT_TI_symbol_name("f")
	.dwattr $C$DW$155, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$155, DW_AT_location[DW_OP_reg1]

;*****************************************************************************
;* FUNCTION NAME: fputc                                                      *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 8 Auto + 4 Save = 12 byte                  *
;*****************************************************************************
fputc:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A2, A3, A4, LR}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwcfi	save_reg_to_mem, 2, -12
	.dwcfi	save_reg_to_mem, 1, -16
$C$DW$156	.dwtag  DW_TAG_variable, DW_AT_name("ch")
	.dwattr $C$DW$156, DW_AT_TI_symbol_name("ch")
	.dwattr $C$DW$156, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$156, DW_AT_location[DW_OP_breg13 0]
$C$DW$157	.dwtag  DW_TAG_variable, DW_AT_name("f")
	.dwattr $C$DW$157, DW_AT_TI_symbol_name("f")
	.dwattr $C$DW$157, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$157, DW_AT_location[DW_OP_breg13 4]
;----------------------------------------------------------------------
; 346 | int fputc(int ch, FILE *f){                                            
;----------------------------------------------------------------------
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |346| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |346| 
	.dwpsn	file "../UART.c",line 347,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 347 | UART_OutChar(ch);                                                      
;----------------------------------------------------------------------
        LDRB      A1, [SP, #0]          ; [DPU_3_PIPE] |347| 
$C$DW$158	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$158, DW_AT_low_pc(0x00)
	.dwattr $C$DW$158, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$158, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |347| 
        ; CALL OCCURS {UART_OutChar }    ; [] |347| 
	.dwpsn	file "../UART.c",line 348,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 348 | return 1;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #1                ; [DPU_3_PIPE] |348| 
	.dwpsn	file "../UART.c",line 349,column 1,is_stmt,isa 1
$C$DW$159	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$159, DW_AT_low_pc(0x00)
	.dwattr $C$DW$159, DW_AT_TI_return
        POP       {A2, A3, A4, PC}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$153, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$153, DW_AT_TI_end_line(0x15d)
	.dwattr $C$DW$153, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$153

	.sect	".text"
	.clink
	.thumbfunc uart_open
	.thumb
	.global	uart_open

$C$DW$160	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_open")
	.dwattr $C$DW$160, DW_AT_low_pc(uart_open)
	.dwattr $C$DW$160, DW_AT_high_pc(0x00)
	.dwattr $C$DW$160, DW_AT_TI_symbol_name("uart_open")
	.dwattr $C$DW$160, DW_AT_external
	.dwattr $C$DW$160, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$160, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$160, DW_AT_TI_begin_line(0x162)
	.dwattr $C$DW$160, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$160, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$160, DW_AT_decl_line(0x162)
	.dwattr $C$DW$160, DW_AT_decl_column(0x05)
	.dwattr $C$DW$160, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 354,column 60,is_stmt,address uart_open,isa 1

	.dwfde $C$DW$CIE, uart_open
$C$DW$161	.dwtag  DW_TAG_formal_parameter, DW_AT_name("path")
	.dwattr $C$DW$161, DW_AT_TI_symbol_name("path")
	.dwattr $C$DW$161, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$161, DW_AT_location[DW_OP_reg0]
$C$DW$162	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flags")
	.dwattr $C$DW$162, DW_AT_TI_symbol_name("flags")
	.dwattr $C$DW$162, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$162, DW_AT_location[DW_OP_reg1]
$C$DW$163	.dwtag  DW_TAG_formal_parameter, DW_AT_name("llv_fd")
	.dwattr $C$DW$163, DW_AT_TI_symbol_name("llv_fd")
	.dwattr $C$DW$163, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$163, DW_AT_location[DW_OP_reg2]

;*****************************************************************************
;* FUNCTION NAME: uart_open                                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                 *
;*****************************************************************************
uart_open:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {A2, A3, A4, LR}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 14, -4
	.dwcfi	save_reg_to_mem, 3, -8
	.dwcfi	save_reg_to_mem, 2, -12
	.dwcfi	save_reg_to_mem, 1, -16
$C$DW$164	.dwtag  DW_TAG_variable, DW_AT_name("path")
	.dwattr $C$DW$164, DW_AT_TI_symbol_name("path")
	.dwattr $C$DW$164, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$164, DW_AT_location[DW_OP_breg13 0]
$C$DW$165	.dwtag  DW_TAG_variable, DW_AT_name("flags")
	.dwattr $C$DW$165, DW_AT_TI_symbol_name("flags")
	.dwattr $C$DW$165, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$165, DW_AT_location[DW_OP_breg13 4]
$C$DW$166	.dwtag  DW_TAG_variable, DW_AT_name("llv_fd")
	.dwattr $C$DW$166, DW_AT_TI_symbol_name("llv_fd")
	.dwattr $C$DW$166, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$166, DW_AT_location[DW_OP_breg13 8]
;----------------------------------------------------------------------
; 354 | int uart_open(const char *path, unsigned flags, int llv_fd){           
;----------------------------------------------------------------------
        STR       A3, [SP, #8]          ; [DPU_3_PIPE] |354| 
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |354| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |354| 
	.dwpsn	file "../UART.c",line 355,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 355 | UART_Init();                                                           
;----------------------------------------------------------------------
$C$DW$167	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$167, DW_AT_low_pc(0x00)
	.dwattr $C$DW$167, DW_AT_name("UART_Init")
	.dwattr $C$DW$167, DW_AT_TI_call
        BL        UART_Init             ; [DPU_3_PIPE] |355| 
        ; CALL OCCURS {UART_Init }       ; [] |355| 
	.dwpsn	file "../UART.c",line 356,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 356 | return 0;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |356| 
	.dwpsn	file "../UART.c",line 357,column 1,is_stmt,isa 1
$C$DW$168	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$168, DW_AT_low_pc(0x00)
	.dwattr $C$DW$168, DW_AT_TI_return
        POP       {A2, A3, A4, PC}      ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$160, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$160, DW_AT_TI_end_line(0x165)
	.dwattr $C$DW$160, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$160

	.sect	".text"
	.clink
	.thumbfunc uart_close
	.thumb
	.global	uart_close

$C$DW$169	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_close")
	.dwattr $C$DW$169, DW_AT_low_pc(uart_close)
	.dwattr $C$DW$169, DW_AT_high_pc(0x00)
	.dwattr $C$DW$169, DW_AT_TI_symbol_name("uart_close")
	.dwattr $C$DW$169, DW_AT_external
	.dwattr $C$DW$169, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$169, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$169, DW_AT_TI_begin_line(0x166)
	.dwattr $C$DW$169, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$169, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$169, DW_AT_decl_line(0x166)
	.dwattr $C$DW$169, DW_AT_decl_column(0x05)
	.dwattr $C$DW$169, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 358,column 28,is_stmt,address uart_close,isa 1

	.dwfde $C$DW$CIE, uart_close
$C$DW$170	.dwtag  DW_TAG_formal_parameter, DW_AT_name("dev_fd")
	.dwattr $C$DW$170, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$170, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$170, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: uart_close                                                 *
;*                                                                           *
;*   Regs Modified     : A1,SP,SR                                            *
;*   Regs Used         : A1,SP,LR,SR                                         *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                   *
;*****************************************************************************
uart_close:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
$C$DW$171	.dwtag  DW_TAG_variable, DW_AT_name("dev_fd")
	.dwattr $C$DW$171, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$171, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$171, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 358 | int uart_close( int dev_fd){                                           
;----------------------------------------------------------------------
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |358| 
	.dwpsn	file "../UART.c",line 359,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 359 | return 0;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |359| 
	.dwpsn	file "../UART.c",line 360,column 1,is_stmt,isa 1
        ADD       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$172	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$172, DW_AT_low_pc(0x00)
	.dwattr $C$DW$172, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$169, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$169, DW_AT_TI_end_line(0x168)
	.dwattr $C$DW$169, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$169

	.sect	".text"
	.clink
	.thumbfunc uart_read
	.thumb
	.global	uart_read

$C$DW$173	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_read")
	.dwattr $C$DW$173, DW_AT_low_pc(uart_read)
	.dwattr $C$DW$173, DW_AT_high_pc(0x00)
	.dwattr $C$DW$173, DW_AT_TI_symbol_name("uart_read")
	.dwattr $C$DW$173, DW_AT_external
	.dwattr $C$DW$173, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$173, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$173, DW_AT_TI_begin_line(0x169)
	.dwattr $C$DW$173, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$173, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$173, DW_AT_decl_line(0x169)
	.dwattr $C$DW$173, DW_AT_decl_column(0x05)
	.dwattr $C$DW$173, DW_AT_TI_max_frame_size(0x18)
	.dwpsn	file "../UART.c",line 361,column 53,is_stmt,address uart_read,isa 1

	.dwfde $C$DW$CIE, uart_read
$C$DW$174	.dwtag  DW_TAG_formal_parameter, DW_AT_name("dev_fd")
	.dwattr $C$DW$174, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$174, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$174, DW_AT_location[DW_OP_reg0]
$C$DW$175	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$175, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$175, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$175, DW_AT_location[DW_OP_reg1]
$C$DW$176	.dwtag  DW_TAG_formal_parameter, DW_AT_name("count")
	.dwattr $C$DW$176, DW_AT_TI_symbol_name("count")
	.dwattr $C$DW$176, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$176, DW_AT_location[DW_OP_reg2]

;*****************************************************************************
;* FUNCTION NAME: uart_read                                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 16 Auto + 4 Save = 20 byte                 *
;*****************************************************************************
uart_read:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {LR}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
	.dwcfi	save_reg_to_mem, 14, -4
        SUB       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 24
$C$DW$177	.dwtag  DW_TAG_variable, DW_AT_name("dev_fd")
	.dwattr $C$DW$177, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$177, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$177, DW_AT_location[DW_OP_breg13 0]
$C$DW$178	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$178, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$178, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$178, DW_AT_location[DW_OP_breg13 4]
$C$DW$179	.dwtag  DW_TAG_variable, DW_AT_name("count")
	.dwattr $C$DW$179, DW_AT_TI_symbol_name("count")
	.dwattr $C$DW$179, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$179, DW_AT_location[DW_OP_breg13 8]
$C$DW$180	.dwtag  DW_TAG_variable, DW_AT_name("ch")
	.dwattr $C$DW$180, DW_AT_TI_symbol_name("ch")
	.dwattr $C$DW$180, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$180, DW_AT_location[DW_OP_breg13 12]
;----------------------------------------------------------------------
; 361 | int uart_read(int dev_fd, char *buf, unsigned count){char ch;          
;----------------------------------------------------------------------
        STR       A3, [SP, #8]          ; [DPU_3_PIPE] |361| 
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |361| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |361| 
	.dwpsn	file "../UART.c",line 362,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 362 | ch = UART_InChar();    // receive from keyboard                        
;----------------------------------------------------------------------
$C$DW$181	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$181, DW_AT_low_pc(0x00)
	.dwattr $C$DW$181, DW_AT_name("UART_InChar")
	.dwattr $C$DW$181, DW_AT_TI_call
        BL        UART_InChar           ; [DPU_3_PIPE] |362| 
        ; CALL OCCURS {UART_InChar }     ; [] |362| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |362| 
	.dwpsn	file "../UART.c",line 363,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 363 | ch = *buf;         // return by reference                              
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |363| 
        LDRB      A1, [A1, #0]          ; [DPU_3_PIPE] |363| 
        STRB      A1, [SP, #12]         ; [DPU_3_PIPE] |363| 
	.dwpsn	file "../UART.c",line 364,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 364 | UART_OutChar(ch);  // echo                                             
;----------------------------------------------------------------------
        LDRB      A1, [SP, #12]         ; [DPU_3_PIPE] |364| 
$C$DW$182	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$182, DW_AT_low_pc(0x00)
	.dwattr $C$DW$182, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$182, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |364| 
        ; CALL OCCURS {UART_OutChar }    ; [] |364| 
	.dwpsn	file "../UART.c",line 365,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 365 | return 1;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #1                ; [DPU_3_PIPE] |365| 
	.dwpsn	file "../UART.c",line 366,column 1,is_stmt,isa 1
        ADD       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
$C$DW$183	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$183, DW_AT_low_pc(0x00)
	.dwattr $C$DW$183, DW_AT_TI_return
        POP       {PC}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$173, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$173, DW_AT_TI_end_line(0x16e)
	.dwattr $C$DW$173, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$173

	.sect	".text"
	.clink
	.thumbfunc uart_write
	.thumb
	.global	uart_write

$C$DW$184	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_write")
	.dwattr $C$DW$184, DW_AT_low_pc(uart_write)
	.dwattr $C$DW$184, DW_AT_high_pc(0x00)
	.dwattr $C$DW$184, DW_AT_TI_symbol_name("uart_write")
	.dwattr $C$DW$184, DW_AT_external
	.dwattr $C$DW$184, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$184, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$184, DW_AT_TI_begin_line(0x16f)
	.dwattr $C$DW$184, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$184, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$184, DW_AT_decl_line(0x16f)
	.dwattr $C$DW$184, DW_AT_decl_column(0x05)
	.dwattr $C$DW$184, DW_AT_TI_max_frame_size(0x18)
	.dwpsn	file "../UART.c",line 367,column 60,is_stmt,address uart_write,isa 1

	.dwfde $C$DW$CIE, uart_write
$C$DW$185	.dwtag  DW_TAG_formal_parameter, DW_AT_name("dev_fd")
	.dwattr $C$DW$185, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$185, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$185, DW_AT_location[DW_OP_reg0]
$C$DW$186	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$186, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$186, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$186, DW_AT_location[DW_OP_reg1]
$C$DW$187	.dwtag  DW_TAG_formal_parameter, DW_AT_name("count")
	.dwattr $C$DW$187, DW_AT_TI_symbol_name("count")
	.dwattr $C$DW$187, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$187, DW_AT_location[DW_OP_reg2]

;*****************************************************************************
;* FUNCTION NAME: uart_write                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR,FPEXC,FPSCR                    *
;*   Local Frame Size  : 0 Args + 16 Auto + 4 Save = 20 byte                 *
;*****************************************************************************
uart_write:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {LR}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
	.dwcfi	save_reg_to_mem, 14, -4
        SUB       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 24
$C$DW$188	.dwtag  DW_TAG_variable, DW_AT_name("dev_fd")
	.dwattr $C$DW$188, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$188, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$188, DW_AT_location[DW_OP_breg13 0]
$C$DW$189	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$189, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$189, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$189, DW_AT_location[DW_OP_breg13 4]
$C$DW$190	.dwtag  DW_TAG_variable, DW_AT_name("count")
	.dwattr $C$DW$190, DW_AT_TI_symbol_name("count")
	.dwattr $C$DW$190, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$190, DW_AT_location[DW_OP_breg13 8]
$C$DW$191	.dwtag  DW_TAG_variable, DW_AT_name("num")
	.dwattr $C$DW$191, DW_AT_TI_symbol_name("num")
	.dwattr $C$DW$191, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$191, DW_AT_location[DW_OP_breg13 12]
;----------------------------------------------------------------------
; 367 | int uart_write(int dev_fd, const char *buf, unsigned count){ unsigned i
;     | nt num=count;                                                          
;----------------------------------------------------------------------
        STR       A3, [SP, #8]          ; [DPU_3_PIPE] |367| 
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |367| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |367| 
	.dwpsn	file "../UART.c",line 367,column 78,is_stmt,isa 1
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |367| 
        STR       A1, [SP, #12]         ; [DPU_3_PIPE] |367| 
	.dwpsn	file "../UART.c",line 368,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 368 | while(num){                                                            
;----------------------------------------------------------------------
        LDR       A1, [SP, #12]         ; [DPU_3_PIPE] |368| 
        CBZ       A1, ||$C$L45||        ; [] 
        ; BRANCHCC OCCURS {||$C$L45||}   ; [] |368| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP ||$C$L44||
;*
;*   Loop source line                : 368
;*   Loop closing brace source line  : 372
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
||$C$L44||:    
	.dwpsn	file "../UART.c",line 369,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 369 | UART_OutChar(*buf);                                                    
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |369| 
        LDRB      A1, [A1, #0]          ; [DPU_3_PIPE] |369| 
$C$DW$192	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$192, DW_AT_low_pc(0x00)
	.dwattr $C$DW$192, DW_AT_name("UART_OutChar")
	.dwattr $C$DW$192, DW_AT_TI_call
        BL        UART_OutChar          ; [DPU_3_PIPE] |369| 
        ; CALL OCCURS {UART_OutChar }    ; [] |369| 
	.dwpsn	file "../UART.c",line 370,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 370 | buf++;                                                                 
;----------------------------------------------------------------------
        LDR       A1, [SP, #4]          ; [DPU_3_PIPE] |370| 
        ADDS      A1, A1, #1            ; [DPU_3_PIPE] |370| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |370| 
	.dwpsn	file "../UART.c",line 371,column 5,is_stmt,isa 1
;----------------------------------------------------------------------
; 371 | num--;                                                                 
;----------------------------------------------------------------------
        LDR       A1, [SP, #12]         ; [DPU_3_PIPE] |371| 
        SUBS      A1, A1, #1            ; [DPU_3_PIPE] |371| 
        STR       A1, [SP, #12]         ; [DPU_3_PIPE] |371| 
	.dwpsn	file "../UART.c",line 368,column 3,is_stmt,isa 1
        LDR       A1, [SP, #12]         ; [DPU_3_PIPE] |368| 
        CMP       A1, #0                ; [DPU_3_PIPE] |368| 
        BNE       ||$C$L44||            ; [DPU_3_PIPE] |368| 
        ; BRANCHCC OCCURS {||$C$L44||}   ; [] |368| 
;* --------------------------------------------------------------------------*
||$C$L45||:    
	.dwpsn	file "../UART.c",line 373,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 373 | return count;                                                          
;----------------------------------------------------------------------
        LDR       A1, [SP, #8]          ; [DPU_3_PIPE] |373| 
	.dwpsn	file "../UART.c",line 374,column 1,is_stmt,isa 1
        ADD       SP, SP, #20           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
$C$DW$193	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$193, DW_AT_low_pc(0x00)
	.dwattr $C$DW$193, DW_AT_TI_return
        POP       {PC}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$184, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$184, DW_AT_TI_end_line(0x176)
	.dwattr $C$DW$184, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$184

	.sect	".text"
	.clink
	.thumbfunc uart_lseek
	.thumb
	.global	uart_lseek

$C$DW$194	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_lseek")
	.dwattr $C$DW$194, DW_AT_low_pc(uart_lseek)
	.dwattr $C$DW$194, DW_AT_high_pc(0x00)
	.dwattr $C$DW$194, DW_AT_TI_symbol_name("uart_lseek")
	.dwattr $C$DW$194, DW_AT_external
	.dwattr $C$DW$194, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$194, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$194, DW_AT_TI_begin_line(0x177)
	.dwattr $C$DW$194, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$194, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$194, DW_AT_decl_line(0x177)
	.dwattr $C$DW$194, DW_AT_decl_column(0x07)
	.dwattr $C$DW$194, DW_AT_TI_max_frame_size(0x10)
	.dwpsn	file "../UART.c",line 375,column 56,is_stmt,address uart_lseek,isa 1

	.dwfde $C$DW$CIE, uart_lseek
$C$DW$195	.dwtag  DW_TAG_formal_parameter, DW_AT_name("dev_fd")
	.dwattr $C$DW$195, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$195, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$195, DW_AT_location[DW_OP_reg0]
$C$DW$196	.dwtag  DW_TAG_formal_parameter, DW_AT_name("ioffset")
	.dwattr $C$DW$196, DW_AT_TI_symbol_name("ioffset")
	.dwattr $C$DW$196, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$196, DW_AT_location[DW_OP_reg1]
$C$DW$197	.dwtag  DW_TAG_formal_parameter, DW_AT_name("origin")
	.dwattr $C$DW$197, DW_AT_TI_symbol_name("origin")
	.dwattr $C$DW$197, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$197, DW_AT_location[DW_OP_reg2]

;*****************************************************************************
;* FUNCTION NAME: uart_lseek                                                 *
;*                                                                           *
;*   Regs Modified     : A1,SP,SR                                            *
;*   Regs Used         : A1,A2,A3,SP,LR,SR                                   *
;*   Local Frame Size  : 0 Args + 12 Auto + 0 Save = 12 byte                 *
;*****************************************************************************
uart_lseek:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #16           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 16
$C$DW$198	.dwtag  DW_TAG_variable, DW_AT_name("dev_fd")
	.dwattr $C$DW$198, DW_AT_TI_symbol_name("dev_fd")
	.dwattr $C$DW$198, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$198, DW_AT_location[DW_OP_breg13 0]
$C$DW$199	.dwtag  DW_TAG_variable, DW_AT_name("ioffset")
	.dwattr $C$DW$199, DW_AT_TI_symbol_name("ioffset")
	.dwattr $C$DW$199, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$199, DW_AT_location[DW_OP_breg13 4]
$C$DW$200	.dwtag  DW_TAG_variable, DW_AT_name("origin")
	.dwattr $C$DW$200, DW_AT_TI_symbol_name("origin")
	.dwattr $C$DW$200, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$200, DW_AT_location[DW_OP_breg13 8]
;----------------------------------------------------------------------
; 375 | off_t uart_lseek(int dev_fd, off_t ioffset, int origin){               
;----------------------------------------------------------------------
        STR       A3, [SP, #8]          ; [DPU_3_PIPE] |375| 
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |375| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |375| 
	.dwpsn	file "../UART.c",line 376,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 376 | return 0;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |376| 
	.dwpsn	file "../UART.c",line 377,column 1,is_stmt,isa 1
        ADD       SP, SP, #16           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$201	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$201, DW_AT_low_pc(0x00)
	.dwattr $C$DW$201, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$194, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$194, DW_AT_TI_end_line(0x179)
	.dwattr $C$DW$194, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$194

	.sect	".text"
	.clink
	.thumbfunc uart_unlink
	.thumb
	.global	uart_unlink

$C$DW$202	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_unlink")
	.dwattr $C$DW$202, DW_AT_low_pc(uart_unlink)
	.dwattr $C$DW$202, DW_AT_high_pc(0x00)
	.dwattr $C$DW$202, DW_AT_TI_symbol_name("uart_unlink")
	.dwattr $C$DW$202, DW_AT_external
	.dwattr $C$DW$202, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$202, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$202, DW_AT_TI_begin_line(0x17a)
	.dwattr $C$DW$202, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$202, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$202, DW_AT_decl_line(0x17a)
	.dwattr $C$DW$202, DW_AT_decl_column(0x05)
	.dwattr $C$DW$202, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 378,column 35,is_stmt,address uart_unlink,isa 1

	.dwfde $C$DW$CIE, uart_unlink
$C$DW$203	.dwtag  DW_TAG_formal_parameter, DW_AT_name("path")
	.dwattr $C$DW$203, DW_AT_TI_symbol_name("path")
	.dwattr $C$DW$203, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$203, DW_AT_location[DW_OP_reg0]

;*****************************************************************************
;* FUNCTION NAME: uart_unlink                                                *
;*                                                                           *
;*   Regs Modified     : A1,SP,SR                                            *
;*   Regs Used         : A1,SP,LR,SR                                         *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                   *
;*****************************************************************************
uart_unlink:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
$C$DW$204	.dwtag  DW_TAG_variable, DW_AT_name("path")
	.dwattr $C$DW$204, DW_AT_TI_symbol_name("path")
	.dwattr $C$DW$204, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$204, DW_AT_location[DW_OP_breg13 0]
;----------------------------------------------------------------------
; 378 | int uart_unlink(const char * path){                                    
;----------------------------------------------------------------------
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |378| 
	.dwpsn	file "../UART.c",line 379,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 379 | return 0;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |379| 
	.dwpsn	file "../UART.c",line 380,column 1,is_stmt,isa 1
        ADD       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$205	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$205, DW_AT_low_pc(0x00)
	.dwattr $C$DW$205, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$202, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$202, DW_AT_TI_end_line(0x17c)
	.dwattr $C$DW$202, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$202

	.sect	".text"
	.clink
	.thumbfunc uart_rename
	.thumb
	.global	uart_rename

$C$DW$206	.dwtag  DW_TAG_subprogram, DW_AT_name("uart_rename")
	.dwattr $C$DW$206, DW_AT_low_pc(uart_rename)
	.dwattr $C$DW$206, DW_AT_high_pc(0x00)
	.dwattr $C$DW$206, DW_AT_TI_symbol_name("uart_rename")
	.dwattr $C$DW$206, DW_AT_external
	.dwattr $C$DW$206, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$206, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$206, DW_AT_TI_begin_line(0x17d)
	.dwattr $C$DW$206, DW_AT_TI_begin_column(0x05)
	.dwattr $C$DW$206, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$206, DW_AT_decl_line(0x17d)
	.dwattr $C$DW$206, DW_AT_decl_column(0x05)
	.dwattr $C$DW$206, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../UART.c",line 381,column 60,is_stmt,address uart_rename,isa 1

	.dwfde $C$DW$CIE, uart_rename
$C$DW$207	.dwtag  DW_TAG_formal_parameter, DW_AT_name("old_name")
	.dwattr $C$DW$207, DW_AT_TI_symbol_name("old_name")
	.dwattr $C$DW$207, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$207, DW_AT_location[DW_OP_reg0]
$C$DW$208	.dwtag  DW_TAG_formal_parameter, DW_AT_name("new_name")
	.dwattr $C$DW$208, DW_AT_TI_symbol_name("new_name")
	.dwattr $C$DW$208, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$208, DW_AT_location[DW_OP_reg1]

;*****************************************************************************
;* FUNCTION NAME: uart_rename                                                *
;*                                                                           *
;*   Regs Modified     : A1,SP,SR                                            *
;*   Regs Used         : A1,A2,SP,LR,SR                                      *
;*   Local Frame Size  : 0 Args + 8 Auto + 0 Save = 8 byte                   *
;*****************************************************************************
uart_rename:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        SUB       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 8
$C$DW$209	.dwtag  DW_TAG_variable, DW_AT_name("old_name")
	.dwattr $C$DW$209, DW_AT_TI_symbol_name("old_name")
	.dwattr $C$DW$209, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$209, DW_AT_location[DW_OP_breg13 0]
$C$DW$210	.dwtag  DW_TAG_variable, DW_AT_name("new_name")
	.dwattr $C$DW$210, DW_AT_TI_symbol_name("new_name")
	.dwattr $C$DW$210, DW_AT_type(*$C$DW$T$26)
	.dwattr $C$DW$210, DW_AT_location[DW_OP_breg13 4]
;----------------------------------------------------------------------
; 381 | int uart_rename(const char *old_name, const char *new_name){           
;----------------------------------------------------------------------
        STR       A2, [SP, #4]          ; [DPU_3_PIPE] |381| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |381| 
	.dwpsn	file "../UART.c",line 382,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 382 | return 0;                                                              
;----------------------------------------------------------------------
        MOVS      A1, #0                ; [DPU_3_PIPE] |382| 
	.dwpsn	file "../UART.c",line 383,column 1,is_stmt,isa 1
        ADD       SP, SP, #8            ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
$C$DW$211	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$211, DW_AT_low_pc(0x00)
	.dwattr $C$DW$211, DW_AT_TI_return
        BX        LR                    ; [DPU_3_PIPE] 
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$206, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$206, DW_AT_TI_end_line(0x17f)
	.dwattr $C$DW$206, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$206

	.sect	".text"
	.clink
	.thumbfunc Output_Init
	.thumb
	.global	Output_Init

$C$DW$212	.dwtag  DW_TAG_subprogram, DW_AT_name("Output_Init")
	.dwattr $C$DW$212, DW_AT_low_pc(Output_Init)
	.dwattr $C$DW$212, DW_AT_high_pc(0x00)
	.dwattr $C$DW$212, DW_AT_TI_symbol_name("Output_Init")
	.dwattr $C$DW$212, DW_AT_external
	.dwattr $C$DW$212, DW_AT_TI_begin_file("../UART.c")
	.dwattr $C$DW$212, DW_AT_TI_begin_line(0x186)
	.dwattr $C$DW$212, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$212, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$212, DW_AT_decl_line(0x186)
	.dwattr $C$DW$212, DW_AT_decl_column(0x06)
	.dwattr $C$DW$212, DW_AT_TI_max_frame_size(0x20)
	.dwpsn	file "../UART.c",line 390,column 23,is_stmt,address Output_Init,isa 1

	.dwfde $C$DW$CIE, Output_Init
;----------------------------------------------------------------------
; 390 | void Output_Init(void){int ret_val; FILE *fptr;                        
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: Output_Init                                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR,D0,D0_hi,D1,D1_hi,D2,D2_hi, *
;*                           D3,D3_hi,D4,D4_hi,D5,D5_hi,D6,D6_hi,D7,D7_hi,   *
;*                           FPEXC,FPSCR                                     *
;*   Local Frame Size  : 20 Args + 8 Auto + 4 Save = 32 byte                 *
;*****************************************************************************
Output_Init:
;* --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
        PUSH      {LR}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
	.dwcfi	save_reg_to_mem, 14, -4
        SUB       SP, SP, #28           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 32
$C$DW$213	.dwtag  DW_TAG_variable, DW_AT_name("ret_val")
	.dwattr $C$DW$213, DW_AT_TI_symbol_name("ret_val")
	.dwattr $C$DW$213, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$213, DW_AT_location[DW_OP_breg13 20]
$C$DW$214	.dwtag  DW_TAG_variable, DW_AT_name("fptr")
	.dwattr $C$DW$214, DW_AT_TI_symbol_name("fptr")
	.dwattr $C$DW$214, DW_AT_type(*$C$DW$T$23)
	.dwattr $C$DW$214, DW_AT_location[DW_OP_breg13 24]
	.dwpsn	file "../UART.c",line 391,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 391 | UART_Init();                                                           
;----------------------------------------------------------------------
$C$DW$215	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$215, DW_AT_low_pc(0x00)
	.dwattr $C$DW$215, DW_AT_name("UART_Init")
	.dwattr $C$DW$215, DW_AT_TI_call
        BL        UART_Init             ; [DPU_3_PIPE] |391| 
        ; CALL OCCURS {UART_Init }       ; [] |391| 
	.dwpsn	file "../UART.c",line 392,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 392 | ret_val = add_device("uart", _SSA, uart_open, uart_close, uart_read, ua
;     | rt_write, uart_lseek, uart_unlink, uart_rename);                       
;----------------------------------------------------------------------
        LDR       A1, $C$CON25          ; [DPU_3_PIPE] |392| 
        STR       A1, [SP, #0]          ; [DPU_3_PIPE] |392| 
        LDR       A1, $C$CON26          ; [DPU_3_PIPE] |392| 
        STR       A1, [SP, #4]          ; [DPU_3_PIPE] |392| 
        LDR       A1, $C$CON27          ; [DPU_3_PIPE] |392| 
        LDR       A3, $C$CON30          ; [DPU_3_PIPE] |392| 
        STR       A1, [SP, #8]          ; [DPU_3_PIPE] |392| 
        LDR       A1, $C$CON28          ; [DPU_3_PIPE] |392| 
        LDR       A4, $C$CON31          ; [DPU_3_PIPE] |392| 
        STR       A1, [SP, #12]         ; [DPU_3_PIPE] |392| 
        LDR       A1, $C$CON29          ; [DPU_3_PIPE] |392| 
        MOVS      A2, #0                ; [DPU_3_PIPE] |392| 
        STR       A1, [SP, #16]         ; [DPU_3_PIPE] |392| 
        ADR       A1, $C$SL1            ; [DPU_3_PIPE] |392| 
$C$DW$216	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$216, DW_AT_low_pc(0x00)
	.dwattr $C$DW$216, DW_AT_name("add_device")
	.dwattr $C$DW$216, DW_AT_TI_call
        BL        add_device            ; [DPU_3_PIPE] |392| 
        ; CALL OCCURS {add_device }      ; [] |392| 
        STR       A1, [SP, #20]         ; [DPU_3_PIPE] |392| 
	.dwpsn	file "../UART.c",line 393,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 393 | if(ret_val) return; // error                                           
;----------------------------------------------------------------------
        LDR       A1, [SP, #20]         ; [DPU_3_PIPE] |393| 
        CBNZ      A1, ||$C$L46||        ; [] 
        ; BRANCHCC OCCURS {||$C$L46||}   ; [] |393| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 393,column 15,is_stmt,isa 1
	.dwpsn	file "../UART.c",line 394,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 394 | fptr = fopen("uart","w");                                              
;----------------------------------------------------------------------
        ADR       A1, $C$SL1            ; [DPU_3_PIPE] |394| 
        ADR       A2, $C$SL2            ; [DPU_3_PIPE] |394| 
$C$DW$217	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$217, DW_AT_low_pc(0x00)
	.dwattr $C$DW$217, DW_AT_name("fopen")
	.dwattr $C$DW$217, DW_AT_TI_call
        BL        fopen                 ; [DPU_3_PIPE] |394| 
        ; CALL OCCURS {fopen }           ; [] |394| 
        STR       A1, [SP, #24]         ; [DPU_3_PIPE] |394| 
	.dwpsn	file "../UART.c",line 395,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 395 | if(fptr == 0) return; // error                                         
;----------------------------------------------------------------------
        LDR       A1, [SP, #24]         ; [DPU_3_PIPE] |395| 
        CBZ       A1, ||$C$L46||        ; [] 
        ; BRANCHCC OCCURS {||$C$L46||}   ; [] |395| 
;* --------------------------------------------------------------------------*
	.dwpsn	file "../UART.c",line 395,column 17,is_stmt,isa 1
	.dwpsn	file "../UART.c",line 396,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 396 | freopen("uart:", "w", stdout); // redirect stdout to uart              
;----------------------------------------------------------------------
        LDR       A3, $C$CON32          ; [DPU_3_PIPE] |396| 
        ADR       A1, $C$SL3            ; [DPU_3_PIPE] |396| 
        ADR       A2, $C$SL2            ; [DPU_3_PIPE] |396| 
$C$DW$218	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$218, DW_AT_low_pc(0x00)
	.dwattr $C$DW$218, DW_AT_name("freopen")
	.dwattr $C$DW$218, DW_AT_TI_call
        BL        freopen               ; [DPU_3_PIPE] |396| 
        ; CALL OCCURS {freopen }         ; [] |396| 
	.dwpsn	file "../UART.c",line 397,column 3,is_stmt,isa 1
;----------------------------------------------------------------------
; 397 | setvbuf(stdout, NULL, _IONBF, 0); // turn off buffering for stdout     
;----------------------------------------------------------------------
        LDR       A1, $C$CON32          ; [DPU_3_PIPE] |397| 
        MOVS      A2, #0                ; [DPU_3_PIPE] |397| 
        MOVS      A3, #4                ; [DPU_3_PIPE] |397| 
        MOVS      A4, #0                ; [DPU_3_PIPE] |397| 
$C$DW$219	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$219, DW_AT_low_pc(0x00)
	.dwattr $C$DW$219, DW_AT_name("setvbuf")
	.dwattr $C$DW$219, DW_AT_TI_call
        BL        setvbuf               ; [DPU_3_PIPE] |397| 
        ; CALL OCCURS {setvbuf }         ; [] |397| 
	.dwpsn	file "../UART.c",line 399,column 1,is_stmt,isa 1
;* --------------------------------------------------------------------------*
||$C$L46||:    
        ADD       SP, SP, #28           ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 4
$C$DW$220	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$220, DW_AT_low_pc(0x00)
	.dwattr $C$DW$220, DW_AT_TI_return
        POP       {PC}                  ; [DPU_3_PIPE] 
	.dwcfi	cfa_offset, 0
        ; BRANCH OCCURS                  ; [] 
	.dwattr $C$DW$212, DW_AT_TI_end_file("../UART.c")
	.dwattr $C$DW$212, DW_AT_TI_end_line(0x18f)
	.dwattr $C$DW$212, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$212

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$SL1||:	.string	"uart",0
	.align	4
||$C$SL2||:	.string	"w",0
	.align	4
||$C$SL3||:	.string	"uart:",0
;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
||$C$CON25||:	.bits	uart_read,32
	.align	4
||$C$CON26||:	.bits	uart_write,32
	.align	4
||$C$CON27||:	.bits	uart_lseek,32
	.align	4
||$C$CON28||:	.bits	uart_unlink,32
	.align	4
||$C$CON29||:	.bits	uart_rename,32
	.align	4
||$C$CON30||:	.bits	uart_open,32
	.align	4
||$C$CON31||:	.bits	uart_close,32
	.align	4
||$C$CON32||:	.bits	_ftable+24,32
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	fopen
	.global	freopen
	.global	setvbuf
	.global	StartCritical
	.global	EndCritical
	.global	add_device
	.global	_ftable

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
$C$DW$221	.dwtag  DW_TAG_member
	.dwattr $C$DW$221, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$221, DW_AT_name("fd")
	.dwattr $C$DW$221, DW_AT_TI_symbol_name("fd")
	.dwattr $C$DW$221, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$221, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$221, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$221, DW_AT_decl_line(0x5c)
	.dwattr $C$DW$221, DW_AT_decl_column(0x0b)
$C$DW$222	.dwtag  DW_TAG_member
	.dwattr $C$DW$222, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$222, DW_AT_name("buf")
	.dwattr $C$DW$222, DW_AT_TI_symbol_name("buf")
	.dwattr $C$DW$222, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$222, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$222, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$222, DW_AT_decl_line(0x5d)
	.dwattr $C$DW$222, DW_AT_decl_column(0x16)
$C$DW$223	.dwtag  DW_TAG_member
	.dwattr $C$DW$223, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$223, DW_AT_name("pos")
	.dwattr $C$DW$223, DW_AT_TI_symbol_name("pos")
	.dwattr $C$DW$223, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$223, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$223, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$223, DW_AT_decl_line(0x5e)
	.dwattr $C$DW$223, DW_AT_decl_column(0x16)
$C$DW$224	.dwtag  DW_TAG_member
	.dwattr $C$DW$224, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$224, DW_AT_name("bufend")
	.dwattr $C$DW$224, DW_AT_TI_symbol_name("bufend")
	.dwattr $C$DW$224, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$224, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$224, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$224, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$224, DW_AT_decl_column(0x16)
$C$DW$225	.dwtag  DW_TAG_member
	.dwattr $C$DW$225, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$225, DW_AT_name("buff_stop")
	.dwattr $C$DW$225, DW_AT_TI_symbol_name("buff_stop")
	.dwattr $C$DW$225, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$225, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$225, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$225, DW_AT_decl_line(0x60)
	.dwattr $C$DW$225, DW_AT_decl_column(0x16)
$C$DW$226	.dwtag  DW_TAG_member
	.dwattr $C$DW$226, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$226, DW_AT_name("flags")
	.dwattr $C$DW$226, DW_AT_TI_symbol_name("flags")
	.dwattr $C$DW$226, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$226, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$226, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$226, DW_AT_decl_line(0x61)
	.dwattr $C$DW$226, DW_AT_decl_column(0x16)
	.dwendtag $C$DW$T$20

	.dwattr $C$DW$T$20, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$20, DW_AT_decl_line(0x5b)
	.dwattr $C$DW$T$20, DW_AT_decl_column(0x10)
$C$DW$T$22	.dwtag  DW_TAG_typedef, DW_AT_name("FILE")
	.dwattr $C$DW$T$22, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$T$22, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$22, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$22, DW_AT_decl_line(0x62)
	.dwattr $C$DW$T$22, DW_AT_decl_column(0x03)
$C$DW$T$23	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$23, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$T$23, DW_AT_address_class(0x20)

$C$DW$T$31	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$31, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$T$31, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$31, DW_AT_byte_size(0xf0)
$C$DW$227	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$227, DW_AT_upper_bound(0x09)
	.dwendtag $C$DW$T$31

$C$DW$T$2	.dwtag  DW_TAG_unspecified_type
	.dwattr $C$DW$T$2, DW_AT_name("void")
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_type(*$C$DW$T$2)
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)
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
$C$DW$T$43	.dwtag  DW_TAG_typedef, DW_AT_name("uint16_t")
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$43, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$43, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$43, DW_AT_decl_line(0x2d)
	.dwattr $C$DW$T$43, DW_AT_decl_column(0x1c)
$C$DW$T$53	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least16_t")
	.dwattr $C$DW$T$53, DW_AT_type(*$C$DW$T$43)
	.dwattr $C$DW$T$53, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$53, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$53, DW_AT_decl_line(0x3b)
	.dwattr $C$DW$T$53, DW_AT_decl_column(0x16)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x04)

$C$DW$T$62	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$62, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$62, DW_AT_language(DW_LANG_C)
$C$DW$228	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$228, DW_AT_type(*$C$DW$T$26)
$C$DW$229	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$229, DW_AT_type(*$C$DW$T$11)
$C$DW$230	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$230, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$62

$C$DW$T$63	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$63, DW_AT_type(*$C$DW$T$62)
	.dwattr $C$DW$T$63, DW_AT_address_class(0x20)

$C$DW$T$64	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$64, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$64, DW_AT_language(DW_LANG_C)
$C$DW$231	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$231, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$64

$C$DW$T$65	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$65, DW_AT_type(*$C$DW$T$64)
	.dwattr $C$DW$T$65, DW_AT_address_class(0x20)

$C$DW$T$66	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$66, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$66, DW_AT_language(DW_LANG_C)
$C$DW$232	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$232, DW_AT_type(*$C$DW$T$10)
$C$DW$233	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$233, DW_AT_type(*$C$DW$T$38)
$C$DW$234	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$234, DW_AT_type(*$C$DW$T$11)
	.dwendtag $C$DW$T$66

$C$DW$T$67	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$67, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$T$67, DW_AT_address_class(0x20)

$C$DW$T$68	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$68, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$68, DW_AT_language(DW_LANG_C)
$C$DW$235	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$235, DW_AT_type(*$C$DW$T$10)
$C$DW$236	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$236, DW_AT_type(*$C$DW$T$26)
$C$DW$237	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$237, DW_AT_type(*$C$DW$T$11)
	.dwendtag $C$DW$T$68

$C$DW$T$69	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$69, DW_AT_type(*$C$DW$T$68)
	.dwattr $C$DW$T$69, DW_AT_address_class(0x20)

$C$DW$T$70	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$70, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$70, DW_AT_language(DW_LANG_C)
$C$DW$238	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$238, DW_AT_type(*$C$DW$T$26)
	.dwendtag $C$DW$T$70

$C$DW$T$71	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$71, DW_AT_type(*$C$DW$T$70)
	.dwattr $C$DW$T$71, DW_AT_address_class(0x20)

$C$DW$T$72	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$72, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$72, DW_AT_language(DW_LANG_C)
$C$DW$239	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$239, DW_AT_type(*$C$DW$T$26)
$C$DW$240	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$240, DW_AT_type(*$C$DW$T$26)
	.dwendtag $C$DW$T$72

$C$DW$T$73	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$73, DW_AT_type(*$C$DW$T$72)
	.dwattr $C$DW$T$73, DW_AT_address_class(0x20)
$C$DW$T$79	.dwtag  DW_TAG_typedef, DW_AT_name("int32_t")
	.dwattr $C$DW$T$79, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$79, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$79, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$79, DW_AT_decl_line(0x2e)
	.dwattr $C$DW$T$79, DW_AT_decl_column(0x1d)
$C$DW$T$80	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast16_t")
	.dwattr $C$DW$T$80, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$80, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$80, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$80, DW_AT_decl_line(0x47)
	.dwattr $C$DW$T$80, DW_AT_decl_column(0x17)
$C$DW$T$81	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast32_t")
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$81, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$81, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$81, DW_AT_decl_line(0x4a)
	.dwattr $C$DW$T$81, DW_AT_decl_column(0x17)
$C$DW$T$82	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast8_t")
	.dwattr $C$DW$T$82, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$82, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$82, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$82, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$82, DW_AT_decl_column(0x17)
$C$DW$T$83	.dwtag  DW_TAG_typedef, DW_AT_name("int_least32_t")
	.dwattr $C$DW$T$83, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$83, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$83, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$83, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$T$83, DW_AT_decl_column(0x17)
$C$DW$T$84	.dwtag  DW_TAG_typedef, DW_AT_name("intptr_t")
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$84, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$84, DW_AT_decl_line(0x52)
	.dwattr $C$DW$T$84, DW_AT_decl_column(0x1a)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x04)
$C$DW$T$54	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$54, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$54, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$54, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$54, DW_AT_decl_line(0x58)
	.dwattr $C$DW$T$54, DW_AT_decl_column(0x19)
$C$DW$T$40	.dwtag  DW_TAG_typedef, DW_AT_name("uint32_t")
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$40, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$40, DW_AT_decl_line(0x2f)
	.dwattr $C$DW$T$40, DW_AT_decl_column(0x1c)
$C$DW$T$86	.dwtag  DW_TAG_volatile_type
	.dwattr $C$DW$T$86, DW_AT_type(*$C$DW$T$40)
$C$DW$T$88	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast16_t")
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$88, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$88, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$88, DW_AT_decl_line(0x48)
	.dwattr $C$DW$T$88, DW_AT_decl_column(0x16)
$C$DW$T$89	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast32_t")
	.dwattr $C$DW$T$89, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$89, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$89, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$89, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$T$89, DW_AT_decl_column(0x16)
$C$DW$T$90	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast8_t")
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$90, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$90, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$90, DW_AT_decl_line(0x46)
	.dwattr $C$DW$T$90, DW_AT_decl_column(0x16)
$C$DW$T$91	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least32_t")
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$91, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$91, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$T$91, DW_AT_decl_column(0x16)
$C$DW$T$92	.dwtag  DW_TAG_typedef, DW_AT_name("uintptr_t")
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$92, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$92, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$92, DW_AT_decl_line(0x53)
	.dwattr $C$DW$T$92, DW_AT_decl_column(0x1a)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x04)
$C$DW$T$95	.dwtag  DW_TAG_typedef, DW_AT_name("fpos_t")
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$95, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdio.h")
	.dwattr $C$DW$T$95, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$T$95, DW_AT_decl_column(0x0e)
$C$DW$T$74	.dwtag  DW_TAG_typedef, DW_AT_name("off_t")
	.dwattr $C$DW$T$74, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$74, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$74, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/file.h")
	.dwattr $C$DW$T$74, DW_AT_decl_line(0x45)
	.dwattr $C$DW$T$74, DW_AT_decl_column(0x0e)

$C$DW$T$75	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$75, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$T$75, DW_AT_language(DW_LANG_C)
$C$DW$241	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$241, DW_AT_type(*$C$DW$T$10)
$C$DW$242	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$242, DW_AT_type(*$C$DW$T$74)
$C$DW$243	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$243, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$75

$C$DW$T$76	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$76, DW_AT_type(*$C$DW$T$75)
	.dwattr $C$DW$T$76, DW_AT_address_class(0x20)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned long")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x04)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x08)
$C$DW$T$96	.dwtag  DW_TAG_typedef, DW_AT_name("int64_t")
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$96, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$96, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$96, DW_AT_decl_line(0x32)
	.dwattr $C$DW$T$96, DW_AT_decl_column(0x21)
$C$DW$T$97	.dwtag  DW_TAG_typedef, DW_AT_name("int_fast64_t")
	.dwattr $C$DW$T$97, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$T$97, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$97, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$97, DW_AT_decl_line(0x4e)
	.dwattr $C$DW$T$97, DW_AT_decl_column(0x17)
$C$DW$T$98	.dwtag  DW_TAG_typedef, DW_AT_name("int_least64_t")
	.dwattr $C$DW$T$98, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$T$98, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$98, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$98, DW_AT_decl_line(0x40)
	.dwattr $C$DW$T$98, DW_AT_decl_column(0x17)
$C$DW$T$99	.dwtag  DW_TAG_typedef, DW_AT_name("intmax_t")
	.dwattr $C$DW$T$99, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$99, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$99, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$99, DW_AT_decl_line(0x56)
	.dwattr $C$DW$T$99, DW_AT_decl_column(0x20)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x08)
$C$DW$T$100	.dwtag  DW_TAG_typedef, DW_AT_name("uint64_t")
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$100, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$100, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$100, DW_AT_decl_line(0x33)
	.dwattr $C$DW$T$100, DW_AT_decl_column(0x20)
$C$DW$T$101	.dwtag  DW_TAG_typedef, DW_AT_name("uint_fast64_t")
	.dwattr $C$DW$T$101, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$T$101, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$101, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$101, DW_AT_decl_line(0x4f)
	.dwattr $C$DW$T$101, DW_AT_decl_column(0x16)
$C$DW$T$102	.dwtag  DW_TAG_typedef, DW_AT_name("uint_least64_t")
	.dwattr $C$DW$T$102, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$T$102, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$102, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$102, DW_AT_decl_line(0x41)
	.dwattr $C$DW$T$102, DW_AT_decl_column(0x16)
$C$DW$T$103	.dwtag  DW_TAG_typedef, DW_AT_name("uintmax_t")
	.dwattr $C$DW$T$103, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$103, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$103, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdint.h")
	.dwattr $C$DW$T$103, DW_AT_decl_line(0x57)
	.dwattr $C$DW$T$103, DW_AT_decl_column(0x20)
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
$C$DW$T$25	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$25, DW_AT_type(*$C$DW$T$6)
$C$DW$T$26	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$26, DW_AT_type(*$C$DW$T$25)
	.dwattr $C$DW$T$26, DW_AT_address_class(0x20)
$C$DW$T$38	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$38, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$38, DW_AT_address_class(0x20)
$C$DW$T$104	.dwtag  DW_TAG_typedef, DW_AT_name("__builtin_va_list")
	.dwattr $C$DW$T$104, DW_AT_type(*$C$DW$T$38)
	.dwattr $C$DW$T$104, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$104, DW_AT_decl_file("../UART.c")
	.dwattr $C$DW$T$104, DW_AT_decl_line(0x18f)
	.dwattr $C$DW$T$104, DW_AT_decl_column(0x01)

$C$DW$T$107	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$107, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$107, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$107, DW_AT_byte_size(0x400)
$C$DW$244	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$244, DW_AT_upper_bound(0x3ff)
	.dwendtag $C$DW$T$107


$C$DW$T$21	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$21, DW_AT_name("__va_list")
	.dwattr $C$DW$T$21, DW_AT_byte_size(0x04)
$C$DW$245	.dwtag  DW_TAG_member
	.dwattr $C$DW$245, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$245, DW_AT_name("__ap")
	.dwattr $C$DW$245, DW_AT_TI_symbol_name("__ap")
	.dwattr $C$DW$245, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$245, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$245, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$245, DW_AT_decl_line(0x36)
	.dwattr $C$DW$245, DW_AT_decl_column(0x0c)
	.dwendtag $C$DW$T$21

	.dwattr $C$DW$T$21, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$T$21, DW_AT_decl_line(0x35)
	.dwattr $C$DW$T$21, DW_AT_decl_column(0x10)
$C$DW$T$114	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$114, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$114, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$114, DW_AT_decl_file("C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include/stdarg.h")
	.dwattr $C$DW$T$114, DW_AT_decl_line(0x37)
	.dwattr $C$DW$T$114, DW_AT_decl_column(0x03)
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

