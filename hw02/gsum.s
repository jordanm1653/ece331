	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"gsum.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Usage: %s \"<glob>\"\012\000"
	.text
	.align	2
	.global	print_usage
	.type	print_usage, %function
print_usage:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r2, .L2
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #0]
	mov	r0, r2
	mov	r1, r3
	bl	printf
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
	.size	print_usage, .-print_usage
	.section	.rodata
	.align	2
.LC1:
	.ascii	"glob\000"
	.align	2
.LC2:
	.ascii	"stat\000"
	.align	2
.LC3:
	.ascii	"Error: \"%s\" is not an acceptable filetype\012\000"
	.align	2
.LC4:
	.ascii	"%lld\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 144
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #144
	str	r0, [fp, #-144]
	str	r1, [fp, #-148]
	mov	r2, #0
	mov	r3, #0
	strd	r2, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-144]
	cmp	r3, #2
	beq	.L5
	ldr	r0, [fp, #-148]
	bl	print_usage
	mov	r0, #1
	bl	exit
.L5:
	ldr	r3, [fp, #-148]
	add	r3, r3, #4
	ldr	r3, [r3, #0]
	mov	r2, r3
	sub	r3, fp, #52
	mov	r0, r2
	mov	r1, #0
	mov	r2, #0
	bl	glob
	mov	r3, r0
	cmp	r3, #0
	beq	.L6
	ldr	r0, .L11
	bl	perror
	mov	r0, #1
	bl	exit
.L6:
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L7
.L10:
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-16]
	mov	r3, r3, asl #2
	add	r3, r2, r3
	ldr	r3, [r3, #0]
	mov	r2, r3
	sub	r3, fp, #140
	mov	r0, r2
	mov	r1, r3
	bl	stat
	mov	r3, r0
	cmn	r3, #1
	bne	.L8
	ldr	r0, .L11+4
	bl	perror
	mov	r0, #1
	bl	exit
.L8:
	ldr	r3, [fp, #-124]
	and	r3, r3, #61440
	cmp	r3, #32768
	beq	.L9
	ldr	r2, .L11+8
	ldr	r1, [fp, #-48]
	ldr	r3, [fp, #-16]
	mov	r3, r3, asl #2
	add	r3, r1, r3
	ldr	r3, [r3, #0]
	mov	r0, r2
	mov	r1, r3
	bl	printf
	ldr	r0, [fp, #-148]
	bl	print_usage
	mov	r0, #1
	bl	exit
.L9:
	ldr	r1, [fp, #-96]
	mov	r2, r1
	mov	r3, r2, asr #31
	ldrd	r0, [fp, #-12]
	adds	r2, r2, r0
	adc	r3, r3, r1
	strd	r2, [fp, #-12]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L7:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	bcc	.L10
	ldr	r3, .L11+12
	mov	r0, r3
	ldrd	r2, [fp, #-12]
	bl	printf
	sub	r3, fp, #52
	mov	r0, r3
	bl	globfree
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L12:
	.align	2
.L11:
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14+rpi1) 4.6.3"
	.section	.note.GNU-stack,"",%progbits
