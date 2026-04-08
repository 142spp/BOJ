	.text
	.file	"1920.cpp"
                                        // Start of file scope inline assembly
	.globl	_ZSt21ios_base_library_initv

                                        // End of file scope inline assembly
	.globl	main                            // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 156, DW.ref.__gxx_personality_v0
	.cfi_lsda 28, .Lexception0
// %bb.0:
	sub	sp, sp, #80
	.cfi_def_cfa_offset 80
	stp	x29, x30, [sp, #16]             // 16-byte Folded Spill
	stp	x24, x23, [sp, #32]             // 16-byte Folded Spill
	stp	x22, x21, [sp, #48]             // 16-byte Folded Spill
	stp	x20, x19, [sp, #64]             // 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 64
	.cfi_offset w19, -8
	.cfi_offset w20, -16
	.cfi_offset w21, -24
	.cfi_offset w22, -32
	.cfi_offset w23, -40
	.cfi_offset w24, -48
	.cfi_offset w30, -56
	.cfi_offset w29, -64
	.cfi_remember_state
	adrp	x19, :got:_ZSt3cin
	mov	w0, wzr
	ldr	x19, [x19, :got_lo12:_ZSt3cin]
	ldr	x8, [x19]
	ldur	x8, [x8, #-24]
	add	x8, x19, x8
	str	xzr, [x8, #216]
	bl	_ZNSt8ios_base15sync_with_stdioEb
	sub	x1, x29, #4
	mov	x0, x19
	bl	_ZNSirsERi
	ldursw	x20, [x29, #-4]
	tbnz	w20, #31, .LBB0_25
// %bb.1:
	cbz	w20, .LBB0_9
// %bb.2:
	lsl	x21, x20, #2
	mov	x0, x21
	bl	_Znwm
	mov	x19, x0
	cmp	w20, #1
	mov	x20, x0
	add	x24, x0, x21
	str	wzr, [x20], #4
	b.eq	.LBB0_4
// %bb.3:
	sub	x2, x21, #4
	mov	x0, x20
	mov	w1, wzr
	bl	memset
	mov	x20, x24
.LBB0_4:
	adrp	x21, :got:_ZSt3cin
	mov	x22, x19
	ldr	x21, [x21, :got_lo12:_ZSt3cin]
.LBB0_5:                                // =>This Inner Loop Header: Depth=1
.Ltmp0:
	mov	x0, x21
	mov	x1, x22
	bl	_ZNSirsERi
.Ltmp1:
// %bb.6:                               //   in Loop: Header=BB0_5 Depth=1
	add	x22, x22, #4
	cmp	x22, x20
	b.ne	.LBB0_5
// %bb.7:
	sub	x8, x20, x19
	mov	w9, #126                        // =0x7e
	asr	x8, x8, #2
	clz	x8, x8
	sub	x2, x9, x8, lsl #1
.Ltmp3:
	mov	x0, x19
	mov	x1, x20
	bl	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
.Ltmp4:
// %bb.8:
.Ltmp5:
	mov	x0, x19
	mov	x1, x20
	bl	_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
.Ltmp6:
	b	.LBB0_10
.LBB0_9:
	mov	x24, xzr
	mov	x19, xzr
.LBB0_10:
.Ltmp7:
	adrp	x0, :got:_ZSt3cin
	add	x1, sp, #8
	ldr	x0, [x0, :got_lo12:_ZSt3cin]
	bl	_ZNSirsERi
.Ltmp8:
// %bb.11:
	ldr	w8, [sp, #8]
	sub	w9, w8, #1
	str	w9, [sp, #8]
	cbz	w8, .LBB0_22
// %bb.12:
	adrp	x20, :got:_ZSt3cin
	adrp	x21, :got:_ZSt4cout
	adrp	x22, .L.str
	add	x22, x22, :lo12:.L.str
	ldr	x20, [x20, :got_lo12:_ZSt3cin]
	ldr	x21, [x21, :got_lo12:_ZSt4cout]
	adrp	x23, .L.str.1
	add	x23, x23, :lo12:.L.str.1
.LBB0_13:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB0_15 Depth 2
.Ltmp10:
	add	x1, sp, #4
	mov	x0, x20
	bl	_ZNSirsERi
.Ltmp11:
// %bb.14:                              //   in Loop: Header=BB0_13 Depth=1
	ldur	w9, [x29, #-4]
	ldr	w8, [sp, #4]
	mov	w10, wzr
	cmp	w9, #3
	sub	w9, w9, #1
	b.lt	.LBB0_16
.LBB0_15:                               //   Parent Loop BB0_13 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	add	w11, w9, w10
	add	w11, w11, w11, lsr #31
	asr	w11, w11, #1
	ldr	w12, [x19, w11, sxtw #2]
	cmp	w12, w8
	csel	w9, w11, w9, gt
	csel	w10, w10, w11, gt
	sub	w11, w9, #1
	cmp	w10, w11
	b.lt	.LBB0_15
.LBB0_16:                               //   in Loop: Header=BB0_13 Depth=1
	ldr	w10, [x19, w10, sxtw #2]
	cmp	w10, w8
	b.eq	.LBB0_18
// %bb.17:                              //   in Loop: Header=BB0_13 Depth=1
	ldr	w9, [x19, w9, sxtw #2]
	cmp	w9, w8
	b.ne	.LBB0_19
.LBB0_18:                               //   in Loop: Header=BB0_13 Depth=1
.Ltmp15:
	mov	x0, x21
	mov	w1, #1                          // =0x1
	bl	_ZNSolsEi
.Ltmp16:
	b	.LBB0_20
.LBB0_19:                               //   in Loop: Header=BB0_13 Depth=1
.Ltmp13:
	mov	x0, x21
	mov	x1, x23
	mov	w2, #1                          // =0x1
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp14:
	mov	x0, x21
.LBB0_20:                               //   in Loop: Header=BB0_13 Depth=1
.Ltmp17:
	mov	x1, x22
	mov	w2, #1                          // =0x1
	bl	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp18:
// %bb.21:                              //   in Loop: Header=BB0_13 Depth=1
	ldr	w8, [sp, #8]
	sub	w9, w8, #1
	str	w9, [sp, #8]
	cbnz	w8, .LBB0_13
	b	.LBB0_23
.LBB0_22:
	cbz	x19, .LBB0_24
.LBB0_23:
	sub	x1, x24, x19
	mov	x0, x19
	bl	_ZdlPvm
.LBB0_24:
	mov	w0, wzr
	.cfi_def_cfa wsp, 80
	ldp	x20, x19, [sp, #64]             // 16-byte Folded Reload
	ldp	x22, x21, [sp, #48]             // 16-byte Folded Reload
	ldp	x24, x23, [sp, #32]             // 16-byte Folded Reload
	ldp	x29, x30, [sp, #16]             // 16-byte Folded Reload
	add	sp, sp, #80
	.cfi_def_cfa_offset 0
	.cfi_restore w19
	.cfi_restore w20
	.cfi_restore w21
	.cfi_restore w22
	.cfi_restore w23
	.cfi_restore w24
	.cfi_restore w30
	.cfi_restore w29
	ret
.LBB0_25:
	.cfi_restore_state
	adrp	x0, .L.str.2
	add	x0, x0, :lo12:.L.str.2
	bl	_ZSt20__throw_length_errorPKc
.LBB0_26:
.Ltmp9:
	b	.LBB0_30
.LBB0_27:
.Ltmp12:
	b	.LBB0_30
.LBB0_28:
.Ltmp2:
	mov	x20, x0
	b	.LBB0_31
.LBB0_29:
.Ltmp19:
.LBB0_30:
	mov	x20, x0
	cbz	x19, .LBB0_32
.LBB0_31:
	sub	x1, x24, x19
	mov	x0, x19
	bl	_ZdlPvm
.LBB0_32:
	mov	x0, x20
	bl	_Unwind_Resume
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2, 0x0
GCC_except_table0:
.Lexception0:
	.byte	255                             // @LPStart Encoding = omit
	.byte	255                             // @TType Encoding = omit
	.byte	1                               // Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Lfunc_begin0-.Lfunc_begin0    // >> Call Site 1 <<
	.uleb128 .Ltmp0-.Lfunc_begin0           //   Call between .Lfunc_begin0 and .Ltmp0
	.byte	0                               //     has no landing pad
	.byte	0                               //   On action: cleanup
	.uleb128 .Ltmp0-.Lfunc_begin0           // >> Call Site 2 <<
	.uleb128 .Ltmp1-.Ltmp0                  //   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0           //     jumps to .Ltmp2
	.byte	0                               //   On action: cleanup
	.uleb128 .Ltmp3-.Lfunc_begin0           // >> Call Site 3 <<
	.uleb128 .Ltmp8-.Ltmp3                  //   Call between .Ltmp3 and .Ltmp8
	.uleb128 .Ltmp9-.Lfunc_begin0           //     jumps to .Ltmp9
	.byte	0                               //   On action: cleanup
	.uleb128 .Ltmp10-.Lfunc_begin0          // >> Call Site 4 <<
	.uleb128 .Ltmp11-.Ltmp10                //   Call between .Ltmp10 and .Ltmp11
	.uleb128 .Ltmp12-.Lfunc_begin0          //     jumps to .Ltmp12
	.byte	0                               //   On action: cleanup
	.uleb128 .Ltmp15-.Lfunc_begin0          // >> Call Site 5 <<
	.uleb128 .Ltmp18-.Ltmp15                //   Call between .Ltmp15 and .Ltmp18
	.uleb128 .Ltmp19-.Lfunc_begin0          //     jumps to .Ltmp19
	.byte	0                               //   On action: cleanup
	.uleb128 .Ltmp18-.Lfunc_begin0          // >> Call Site 6 <<
	.uleb128 .Lfunc_end0-.Ltmp18            //   Call between .Ltmp18 and .Lfunc_end0
	.byte	0                               //     has no landing pad
	.byte	0                               //   On action: cleanup
.Lcst_end0:
	.p2align	2, 0x0
                                        // -- End function
	.section	.text._ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,"axG",@progbits,_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,comdat
	.weak	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_ // -- Begin function _ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.p2align	2
	.type	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_,@function
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_: // @_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.cfi_startproc
// %bb.0:
	sub	x8, x1, x0
	asr	x8, x8, #2
	cmp	x8, #17
	b.lt	.LBB1_36
// %bb.1:
	stp	x29, x30, [sp, #-64]!           // 16-byte Folded Spill
	.cfi_def_cfa_offset 64
	stp	x24, x23, [sp, #16]             // 16-byte Folded Spill
	stp	x22, x21, [sp, #32]             // 16-byte Folded Spill
	stp	x20, x19, [sp, #48]             // 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 64
	.cfi_offset w19, -8
	.cfi_offset w20, -16
	.cfi_offset w21, -24
	.cfi_offset w22, -32
	.cfi_offset w23, -40
	.cfi_offset w24, -48
	.cfi_offset w30, -56
	.cfi_offset w29, -64
	mov	x9, #-4                         // =0xfffffffffffffffc
	mov	x19, x0
	mov	x20, x2
	add	x22, x0, #4
	sub	x23, x9, x0
	b	.LBB1_3
.LBB1_2:                                //   in Loop: Header=BB1_3 Depth=1
	mov	x0, x21
	mov	x2, x20
	bl	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	asr	x8, x24, #2
	mov	x1, x21
	cmp	x8, #16
	b.le	.LBB1_35
.LBB1_3:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB1_16 Depth 2
                                        //       Child Loop BB1_17 Depth 3
                                        //       Child Loop BB1_19 Depth 3
	cbz	x20, .LBB1_22
// %bb.4:                               //   in Loop: Header=BB1_3 Depth=1
	lsr	x8, x8, #1
	ldr	w9, [x19, #4]
	ldur	w10, [x1, #-4]
	ldr	w11, [x19, x8, lsl #2]
	cmp	w9, w11
	b.ge	.LBB1_7
// %bb.5:                               //   in Loop: Header=BB1_3 Depth=1
	cmp	w11, w10
	b.ge	.LBB1_9
// %bb.6:                               //   in Loop: Header=BB1_3 Depth=1
	ldr	w9, [x19]
	b	.LBB1_14
.LBB1_7:                                //   in Loop: Header=BB1_3 Depth=1
	cmp	w9, w10
	b.ge	.LBB1_12
// %bb.8:                               //   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [x19]
	b	.LBB1_11
.LBB1_9:                                //   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [x19]
	cmp	w9, w10
	b.ge	.LBB1_11
// %bb.10:                              //   in Loop: Header=BB1_3 Depth=1
	str	w10, [x19]
	stur	w8, [x1, #-4]
	b	.LBB1_15
.LBB1_11:                               //   in Loop: Header=BB1_3 Depth=1
	stp	w9, w8, [x19]
	b	.LBB1_15
.LBB1_12:                               //   in Loop: Header=BB1_3 Depth=1
	ldr	w9, [x19]
	cmp	w11, w10
	b.ge	.LBB1_14
// %bb.13:                              //   in Loop: Header=BB1_3 Depth=1
	str	w10, [x19]
	stur	w9, [x1, #-4]
	b	.LBB1_15
.LBB1_14:                               //   in Loop: Header=BB1_3 Depth=1
	str	w11, [x19]
	str	w9, [x19, x8, lsl #2]
.LBB1_15:                               //   in Loop: Header=BB1_3 Depth=1
	sub	x20, x20, #1
	mov	x8, x1
	mov	x9, x22
.LBB1_16:                               //   Parent Loop BB1_3 Depth=1
                                        // =>  This Loop Header: Depth=2
                                        //       Child Loop BB1_17 Depth 3
                                        //       Child Loop BB1_19 Depth 3
	ldr	w10, [x19]
	add	x24, x23, x9
	sub	x21, x9, #4
.LBB1_17:                               //   Parent Loop BB1_3 Depth=1
                                        //     Parent Loop BB1_16 Depth=2
                                        // =>    This Inner Loop Header: Depth=3
	ldr	w11, [x9], #4
	add	x24, x24, #4
	add	x21, x21, #4
	cmp	w11, w10
	b.lt	.LBB1_17
// %bb.18:                              //   in Loop: Header=BB1_16 Depth=2
	sub	x12, x9, #4
.LBB1_19:                               //   Parent Loop BB1_3 Depth=1
                                        //     Parent Loop BB1_16 Depth=2
                                        // =>    This Inner Loop Header: Depth=3
	ldr	w13, [x8, #-4]!
	cmp	w10, w13
	b.lt	.LBB1_19
// %bb.20:                              //   in Loop: Header=BB1_16 Depth=2
	cmp	x12, x8
	b.hs	.LBB1_2
// %bb.21:                              //   in Loop: Header=BB1_16 Depth=2
	str	w13, [x12]
	str	w11, [x8]
	b	.LBB1_16
.LBB1_22:
	mov	x0, x19
	mov	x2, x1
	mov	x20, x1
	bl	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	mov	w8, #1                          // =0x1
	b	.LBB1_25
.LBB1_23:                               //   in Loop: Header=BB1_25 Depth=1
	mov	x11, xzr
.LBB1_24:                               //   in Loop: Header=BB1_25 Depth=1
	cmp	x10, #4
	str	w9, [x19, x11, lsl #2]
	b.le	.LBB1_35
.LBB1_25:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB1_27 Depth 2
                                        //     Child Loop BB1_33 Depth 2
	ldr	w9, [x20, #-4]!
	sub	x10, x20, x19
	asr	x12, x10, #2
	ldr	w11, [x19]
	cmp	x12, #3
	str	w11, [x20]
	b.lt	.LBB1_29
// %bb.26:                              //   in Loop: Header=BB1_25 Depth=1
	sub	x11, x12, #1
	mov	x14, xzr
	add	x11, x11, x11, lsr #63
	asr	x13, x11, #1
.LBB1_27:                               //   Parent Loop BB1_25 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	lsl	x11, x14, #1
	mov	w15, #1                         // =0x1
	bfi	x15, x14, #1, #63
	add	x16, x11, #2
	ldr	w17, [x19, x16, lsl #2]
	ldr	w15, [x19, x15, lsl #2]
	cmp	w17, w15
	csinc	x11, x16, x11, ge
	ldr	w15, [x19, x11, lsl #2]
	cmp	x11, x13
	str	w15, [x19, x14, lsl #2]
	mov	x14, x11
	b.lt	.LBB1_27
// %bb.28:                              //   in Loop: Header=BB1_25 Depth=1
	tbz	w10, #2, .LBB1_30
	b	.LBB1_32
.LBB1_29:                               //   in Loop: Header=BB1_25 Depth=1
	mov	x11, xzr
	tbnz	w10, #2, .LBB1_32
.LBB1_30:                               //   in Loop: Header=BB1_25 Depth=1
	sub	x12, x12, #2
	cmp	x11, x12, asr #1
	b.ne	.LBB1_32
// %bb.31:                              //   in Loop: Header=BB1_25 Depth=1
	orr	x12, x8, x11, lsl #1
	ldr	w13, [x19, x12, lsl #2]
	str	w13, [x19, x11, lsl #2]
	mov	x11, x12
.LBB1_32:                               //   in Loop: Header=BB1_25 Depth=1
	cmp	x11, #1
	b.lt	.LBB1_24
.LBB1_33:                               //   Parent Loop BB1_25 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x13, x11, #1
	lsr	x12, x13, #1
	ldr	w14, [x19, x12, lsl #2]
	cmp	w14, w9
	b.ge	.LBB1_24
// %bb.34:                              //   in Loop: Header=BB1_33 Depth=2
	cmp	x13, #1
	str	w14, [x19, x11, lsl #2]
	mov	x11, x12
	b.hi	.LBB1_33
	b	.LBB1_23
.LBB1_35:
	.cfi_def_cfa wsp, 64
	ldp	x20, x19, [sp, #48]             // 16-byte Folded Reload
	ldp	x22, x21, [sp, #32]             // 16-byte Folded Reload
	ldp	x24, x23, [sp, #16]             // 16-byte Folded Reload
	ldp	x29, x30, [sp], #64             // 16-byte Folded Reload
	.cfi_def_cfa_offset 0
	.cfi_restore w19
	.cfi_restore w20
	.cfi_restore w21
	.cfi_restore w22
	.cfi_restore w23
	.cfi_restore w24
	.cfi_restore w30
	.cfi_restore w29
.LBB1_36:
	ret
.Lfunc_end1:
	.size	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_, .Lfunc_end1-_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEElNS0_5__ops15_Iter_less_iterEEvT_S9_T0_T1_
	.cfi_endproc
                                        // -- End function
	.section	.text._ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,"axG",@progbits,_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,comdat
	.weak	_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_ // -- Begin function _ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	.p2align	2
	.type	_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_,@function
_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_: // @_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	.cfi_startproc
// %bb.0:
	stp	x29, x30, [sp, #-64]!           // 16-byte Folded Spill
	.cfi_def_cfa_offset 64
	stp	x24, x23, [sp, #16]             // 16-byte Folded Spill
	stp	x22, x21, [sp, #32]             // 16-byte Folded Spill
	stp	x20, x19, [sp, #48]             // 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 64
	.cfi_offset w19, -8
	.cfi_offset w20, -16
	.cfi_offset w21, -24
	.cfi_offset w22, -32
	.cfi_offset w23, -40
	.cfi_offset w24, -48
	.cfi_offset w30, -56
	.cfi_offset w29, -64
	.cfi_remember_state
	sub	x8, x1, x0
	mov	x19, x1
	mov	x20, x0
	cmp	x8, #65
	b.lt	.LBB2_12
// %bb.1:
	add	x21, x20, #4
	mov	w22, #4                         // =0x4
	mov	x23, x20
	b	.LBB2_6
.LBB2_2:                                //   in Loop: Header=BB2_6 Depth=1
	sub	x2, x23, x20
	asr	x8, x2, #2
	cmp	x8, #2
	b.lt	.LBB2_10
// %bb.3:                               //   in Loop: Header=BB2_6 Depth=1
	sub	x8, x9, x8, lsl #2
	mov	x1, x20
	add	x0, x8, #8
	bl	memmove
.LBB2_4:                                //   in Loop: Header=BB2_6 Depth=1
	mov	x8, x20
.LBB2_5:                                //   in Loop: Header=BB2_6 Depth=1
	add	x22, x22, #4
	add	x21, x21, #4
	str	w24, [x8]
	cmp	x22, #64
	b.eq	.LBB2_25
.LBB2_6:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB2_9 Depth 2
	mov	x9, x23
	add	x23, x20, x22
	ldr	w10, [x20]
	ldr	w24, [x23]
	cmp	w24, w10
	b.lt	.LBB2_2
// %bb.7:                               //   in Loop: Header=BB2_6 Depth=1
	ldr	w9, [x9]
	mov	x8, x23
	cmp	w24, w9
	b.ge	.LBB2_5
// %bb.8:                               //   in Loop: Header=BB2_6 Depth=1
	mov	x8, x21
.LBB2_9:                                //   Parent Loop BB2_6 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	str	w9, [x8]
	ldur	w9, [x8, #-8]
	sub	x8, x8, #4
	cmp	w24, w9
	b.lt	.LBB2_9
	b	.LBB2_5
.LBB2_10:                               //   in Loop: Header=BB2_6 Depth=1
	cmp	x2, #4
	mov	x8, x20
	b.ne	.LBB2_5
// %bb.11:                              //   in Loop: Header=BB2_6 Depth=1
	str	w10, [x9, #4]
	b	.LBB2_4
.LBB2_12:
	cmp	x20, x19
	b.eq	.LBB2_26
// %bb.13:
	add	x10, x20, #4
	cmp	x10, x19
	b.eq	.LBB2_26
// %bb.14:
	mov	x21, x20
	b	.LBB2_19
.LBB2_15:                               //   in Loop: Header=BB2_19 Depth=1
	sub	x2, x21, x20
	asr	x8, x2, #2
	cmp	x8, #2
	b.lt	.LBB2_23
// %bb.16:                              //   in Loop: Header=BB2_19 Depth=1
	sub	x8, x9, x8, lsl #2
	mov	x1, x20
	add	x0, x8, #8
	bl	memmove
.LBB2_17:                               //   in Loop: Header=BB2_19 Depth=1
	mov	x8, x20
.LBB2_18:                               //   in Loop: Header=BB2_19 Depth=1
	add	x10, x21, #4
	str	w22, [x8]
	cmp	x10, x19
	b.eq	.LBB2_26
.LBB2_19:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB2_22 Depth 2
	mov	x9, x21
	mov	x21, x10
	ldr	w22, [x10]
	ldr	w10, [x20]
	cmp	w22, w10
	b.lt	.LBB2_15
// %bb.20:                              //   in Loop: Header=BB2_19 Depth=1
	ldr	w9, [x9]
	mov	x8, x21
	cmp	w22, w9
	b.ge	.LBB2_18
// %bb.21:                              //   in Loop: Header=BB2_19 Depth=1
	mov	x8, x21
.LBB2_22:                               //   Parent Loop BB2_19 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	str	w9, [x8]
	ldur	w9, [x8, #-8]
	sub	x8, x8, #4
	cmp	w22, w9
	b.lt	.LBB2_22
	b	.LBB2_18
.LBB2_23:                               //   in Loop: Header=BB2_19 Depth=1
	cmp	x2, #4
	mov	x8, x20
	b.ne	.LBB2_18
// %bb.24:                              //   in Loop: Header=BB2_19 Depth=1
	str	w10, [x9, #4]
	b	.LBB2_17
.LBB2_25:
	add	x8, x20, #64
	cmp	x8, x19
	b.ne	.LBB2_28
.LBB2_26:
	.cfi_def_cfa wsp, 64
	ldp	x20, x19, [sp, #48]             // 16-byte Folded Reload
	ldp	x22, x21, [sp, #32]             // 16-byte Folded Reload
	ldp	x24, x23, [sp, #16]             // 16-byte Folded Reload
	ldp	x29, x30, [sp], #64             // 16-byte Folded Reload
	.cfi_def_cfa_offset 0
	.cfi_restore w19
	.cfi_restore w20
	.cfi_restore w21
	.cfi_restore w22
	.cfi_restore w23
	.cfi_restore w24
	.cfi_restore w30
	.cfi_restore w29
	ret
.LBB2_27:                               //   in Loop: Header=BB2_28 Depth=1
	.cfi_restore_state
	add	x8, x8, #4
	str	w9, [x10]
	cmp	x8, x19
	b.eq	.LBB2_26
.LBB2_28:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB2_30 Depth 2
	ldp	w11, w9, [x8, #-4]
	mov	x10, x8
	cmp	w9, w11
	b.ge	.LBB2_27
// %bb.29:                              //   in Loop: Header=BB2_28 Depth=1
	mov	x10, x8
.LBB2_30:                               //   Parent Loop BB2_28 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	str	w11, [x10]
	ldur	w11, [x10, #-8]
	sub	x10, x10, #4
	cmp	w9, w11
	b.lt	.LBB2_30
	b	.LBB2_27
.Lfunc_end2:
	.size	_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_, .Lfunc_end2-_ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_T0_
	.cfi_endproc
                                        // -- End function
	.section	.text._ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,"axG",@progbits,_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,comdat
	.weak	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_ // -- Begin function _ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	.p2align	2
	.type	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_,@function
_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_: // @_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	.cfi_startproc
// %bb.0:
	sub	x8, x1, x0
	asr	x9, x8, #2
	subs	x12, x9, #2
	b.ge	.LBB3_18
.LBB3_1:
	cmp	x1, x2
	b.hs	.LBB3_17
// %bb.2:
	sub	x10, x9, #1
	asr	x12, x12, #1
	add	x11, x10, x10, lsr #63
	asr	x11, x11, #1
	b	.LBB3_6
.LBB3_3:                                //   in Loop: Header=BB3_6 Depth=1
	mov	x14, xzr
.LBB3_4:                                //   in Loop: Header=BB3_6 Depth=1
	str	w13, [x0, x14, lsl #2]
.LBB3_5:                                //   in Loop: Header=BB3_6 Depth=1
	add	x1, x1, #4
	cmp	x1, x2
	b.hs	.LBB3_17
.LBB3_6:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB3_9 Depth 2
                                        //     Child Loop BB3_15 Depth 2
	ldr	w13, [x1]
	ldr	w14, [x0]
	cmp	w13, w14
	b.ge	.LBB3_5
// %bb.7:                               //   in Loop: Header=BB3_6 Depth=1
	cmp	x9, #3
	str	w14, [x1]
	b.lt	.LBB3_11
// %bb.8:                               //   in Loop: Header=BB3_6 Depth=1
	mov	x15, xzr
.LBB3_9:                                //   Parent Loop BB3_6 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	lsl	x14, x15, #1
	mov	w16, #1                         // =0x1
	bfi	x16, x15, #1, #63
	add	x17, x14, #2
	ldr	w18, [x0, x17, lsl #2]
	ldr	w16, [x0, x16, lsl #2]
	cmp	w18, w16
	csinc	x14, x17, x14, ge
	ldr	w16, [x0, x14, lsl #2]
	cmp	x14, x11
	str	w16, [x0, x15, lsl #2]
	mov	x15, x14
	b.lt	.LBB3_9
// %bb.10:                              //   in Loop: Header=BB3_6 Depth=1
	tbz	w8, #2, .LBB3_12
	b	.LBB3_14
.LBB3_11:                               //   in Loop: Header=BB3_6 Depth=1
	mov	x14, xzr
	tbnz	w8, #2, .LBB3_14
.LBB3_12:                               //   in Loop: Header=BB3_6 Depth=1
	cmp	x14, x12
	b.ne	.LBB3_14
// %bb.13:                              //   in Loop: Header=BB3_6 Depth=1
	ldr	w14, [x0, x10, lsl #2]
	str	w14, [x0, x12, lsl #2]
	mov	x14, x10
.LBB3_14:                               //   in Loop: Header=BB3_6 Depth=1
	cmp	x14, #1
	b.lt	.LBB3_4
.LBB3_15:                               //   Parent Loop BB3_6 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x16, x14, #1
	lsr	x15, x16, #1
	ldr	w17, [x0, x15, lsl #2]
	cmp	w17, w13
	b.ge	.LBB3_4
// %bb.16:                              //   in Loop: Header=BB3_15 Depth=2
	cmp	x16, #1
	str	w17, [x0, x14, lsl #2]
	mov	x14, x15
	b.hi	.LBB3_15
	b	.LBB3_3
.LBB3_17:
	ret
.LBB3_18:
	lsr	x10, x12, #1
	sub	x11, x9, #1
	lsr	x13, x11, #1
	mov	x15, x10
	b	.LBB3_21
.LBB3_19:                               //   in Loop: Header=BB3_21 Depth=1
	mov	x17, x16
.LBB3_20:                               //   in Loop: Header=BB3_21 Depth=1
	str	w15, [x0, x17, lsl #2]
	sub	x15, x14, #1
	cbz	x14, .LBB3_1
.LBB3_21:                               // =>This Loop Header: Depth=1
                                        //     Child Loop BB3_23 Depth 2
                                        //     Child Loop BB3_28 Depth 2
	mov	x14, x15
	ldr	w15, [x0, x15, lsl #2]
	cmp	x13, x14
	mov	x16, x14
	b.le	.LBB3_24
// %bb.22:                              //   in Loop: Header=BB3_21 Depth=1
	mov	x17, x14
.LBB3_23:                               //   Parent Loop BB3_21 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	lsl	x16, x17, #1
	mov	w18, #1                         // =0x1
	bfi	x18, x17, #1, #63
	add	x3, x16, #2
	ldr	w4, [x0, x3, lsl #2]
	ldr	w18, [x0, x18, lsl #2]
	cmp	w4, w18
	csinc	x16, x3, x16, ge
	ldr	w18, [x0, x16, lsl #2]
	cmp	x16, x13
	str	w18, [x0, x17, lsl #2]
	mov	x17, x16
	b.lt	.LBB3_23
.LBB3_24:                               //   in Loop: Header=BB3_21 Depth=1
	tbnz	w8, #2, .LBB3_27
// %bb.25:                              //   in Loop: Header=BB3_21 Depth=1
	cmp	x16, x10
	b.ne	.LBB3_27
// %bb.26:                              //   in Loop: Header=BB3_21 Depth=1
	ldr	w16, [x0, x11, lsl #2]
	str	w16, [x0, x10, lsl #2]
	mov	x16, x11
.LBB3_27:                               //   in Loop: Header=BB3_21 Depth=1
	cmp	x16, x14
	b.le	.LBB3_19
.LBB3_28:                               //   Parent Loop BB3_21 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	sub	x17, x16, #1
	add	x17, x17, x17, lsr #63
	asr	x17, x17, #1
	ldr	w18, [x0, x17, lsl #2]
	cmp	w18, w15
	b.ge	.LBB3_19
// %bb.29:                              //   in Loop: Header=BB3_28 Depth=2
	cmp	x17, x14
	str	w18, [x0, x16, lsl #2]
	mov	x16, x17
	b.gt	.LBB3_28
	b	.LBB3_20
.Lfunc_end3:
	.size	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_, .Lfunc_end3-_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEENS0_5__ops15_Iter_less_iterEEvT_S9_S9_T0_
	.cfi_endproc
                                        // -- End function
	.type	.L.str,@object                  // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"\n"
	.size	.L.str, 2

	.type	.L.str.1,@object                // @.str.1
.L.str.1:
	.asciz	"0"
	.size	.L.str.1, 2

	.type	.L.str.2,@object                // @.str.2
.L.str.2:
	.asciz	"cannot create std::vector larger than max_size()"
	.size	.L.str.2, 49

	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.p2align	3, 0x0
	.type	DW.ref.__gxx_personality_v0,@object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.xword	__gxx_personality_v0
	.ident	"Debian clang version 19.1.7 (3+b1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __gxx_personality_v0
	.addrsig_sym _Unwind_Resume
	.addrsig_sym _ZSt3cin
	.addrsig_sym _ZSt4cout
