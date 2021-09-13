	.file	"p2.c"
	.text
	.globl	find_range
	.def	find_range;	.scl	2;	.type	32;	.endef
	.seh_proc	find_range
find_range:
	.seh_endprologue
	vxorps	%xmm1, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm0
	jp	.L5
	ja	.L2
	je	.L3
	jb	.L4
	ret
.L5:
	movl $3,%eax
	jmp .Done
.L4:
	movl $0,%eax
	jmp .Done
.L3:
	movl $1,%eax
	jmp .Done
.L2:
	movl $2,%eax
	jmp .Done
.Done:
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC0:
	.long	0
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
