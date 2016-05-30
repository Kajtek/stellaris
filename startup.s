.cpu cortex-m4
.thumb

.word   0x20008000
.word   _start
.word   hang
.word   hang

.thumb_func
hang:   b .

.thumb_func
.globl _start
_start:
    bl main
    b hang
