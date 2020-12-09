	.file	"test.c"
	.text
	.globl	switch_func
	.type	switch_func, @function
switch_func:
.LFB11:
	.cfi_startproc
	cmpl	$2, %edi
	je	.L4
	jg	.L3
	cmpl	$1, %edi
	jne	.L5
	movl	$16, %eax
	ret
.L3:
	subl	$3, %edi
	cmpl	$1, %edi
	ja	.L7
	movl	$4, %eax
	ret
.L7:
	movl	$10, %eax
	ret
.L4:
	movl	%edi, %eax
	ret
.L5:
	movl	$10, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	switch_func, .-switch_func
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
