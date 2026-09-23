; boot.asm — Multiboot header + entry point. GRUB reads this to recognize
; and load your kernel, then jumps to _start, which calls into your C++.

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

section .text
global _start
extern kmain

_start:
    call kmain
    cli
.hang:
    hlt
    jmp .hang