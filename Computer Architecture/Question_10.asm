.data

.text
    .globl  main
main:

    # Read user inputs
    li      $v0,        5
    syscall
    move    $t0,        $v0

    li      $v0,        5
    syscall
    move    $t1,        $v0

    # Calculate Combination (n choose k)
    # Factorial of n
    move    $a0,        $t0
    jal     factorial
    move    $t2,        $v0

    # Factorial of k
    move    $a0,        $t1
    jal     factorial
    move    $t3,        $v0

    # Factorial of (n-k)
    sub     $a0,        $t0,        $t1
    jal     factorial
    move    $t4,        $v0

    # Calculate the combination
    mul     $t5,        $t3,        $t4
    div     $t2,        $t5
    mflo    $t6

    # Display the result
    move    $a0,        $t6
    li      $v0,        1
    syscall

    j       exit

factorial:
    addi    $sp,        $sp,        -8  # allocate stack space
    sw      $ra,        4($sp)          # save return address
    sw      $a0,        0($sp)          # save argument

    blez    $a0,        fact_base       # if n <= 0, return 1

    addi    $a0,        $a0,        -1  # n-1
    jal     factorial                   # recursive call
    lw      $a0,        0($sp)          # restore argument
    mul     $v0,        $a0,        $v0 # n * factorial(n-1)
    j       fact_end

fact_base:
    li      $v0,        1               # base case: factorial(0) = 1

fact_end:
    lw      $ra,        4($sp)          # restore return address
    addi    $sp,        $sp,        8   # deallocate stack space
    jr      $ra                         # return

exit:
    li      $v0,        10
    syscall