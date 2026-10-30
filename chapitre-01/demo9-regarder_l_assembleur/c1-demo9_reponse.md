//mon programme 
#include <cstdio>
int main() {
    printf("Bonjour !\n");
    return 0;
}

//code assembleur après ma commande pour compiler clang++ -S main.cpp -o main.s
```
.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Bonjour !\n"

.subsections_via_symbols
```
 Le fichier assembleur contient l’étiquette `_main`
 l’appel à `_printf` avec `callq`
 et l’instruction `xorl %eax, %eax` qui correspond au retour de la valeur 0 
