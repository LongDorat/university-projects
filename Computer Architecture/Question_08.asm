.data
buffer:     .space  100
greeting:   .asciiz "Hello, "

.text
            .globl  main

main:
    # Read a string from the user
    li      $v0,    8           # syscall for read string
    la      $a0,    buffer      # load address of buffer
    li      $a1,    100         # maximum number of characters to read
    syscall                     # make syscall

    # Displaying the string
    li      $v0,    4           # syscall for print string
    la      $a0,    greeting    # load address of greeting
    syscall                     # make syscall

    li      $v0,    4           # syscall for print string
    la      $a0,    buffer      # load address of buffer
    syscall                     # make syscall