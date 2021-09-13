	.file	"p2.c"
	.text
	.globl	find_range
	.def	find_range;	.scl	2;	.type	32;	.endef
	.seh_proc	find_range
find_range:
	.seh_endprologue
	vxorps	%xmm1, %xmm1, %xmm1
	movq $1,%rax
	movq $2,%r8
	movq $0,%r9
	movq $3,%r10
	vucomiss	%xmm1, %xmm0
	cmovaq %r8,%rax
	cmovbq %r9,%rax
	cmovpq %r10,%rax
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC0:
	.long	0
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
