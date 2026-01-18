    # Hello World in MIPS
.data
msg:    .asciiz "Hello World\n"


.text
        .globl  main
main:
    li      $v0,    4           # syscall for print string
    la      $a0,    msg         # load address of msg
    syscall                     # make syscall

    li      $v0,    10          # syscall for exit
    syscall                     # make syscall