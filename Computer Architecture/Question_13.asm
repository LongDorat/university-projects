# The same as question 10

.data
mock_up_data:   .word   10

.text
                .globl  main
main:
    lw      $a0,        mock_up_data
    jal     factorial
    move    $a0,        $v0
    li      $v0,        1
    syscall

    j exit

factorial:
    addi    $sp,        $sp,            -8  # allocate stack space
    sw      $ra,        4($sp)              # save return address
    sw      $a0,        0($sp)              # save argument

    blez    $a0,        fact_base           # if n <= 0, return 1

    addi    $a0,        $a0,            -1  # n-1
    jal     factorial                       # recursive call
    lw      $a0,        0($sp)              # restore argument
    mul     $v0,        $a0,            $v0 # n * factorial(n-1)
    j       fact_end

fact_base:
    li      $v0,        1                   # base case: factorial(0) = 1

fact_end:
    lw      $ra,        4($sp)              # restore return address
    addi    $sp,        $sp,            8   # deallocate stack space
    jr      $ra                             # return

exit: