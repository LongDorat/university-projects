.data
array:      .float  5.2, 3.4, 8.1, 6.0, 2.0, 7.0, 4.7, 1.0, 9.8, 0.4
array_size: .word   10
float_size: .float  10.0
float_zero: .float  0.0

.text
            .globl  main
main:
    li      $s0,        0                                               # index i = 0 (integer register)
    l.s     $f0,        float_zero                                      # Floating-point sum register ($f0 = 0.0)
    la      $a0,        array                                           # Load base address of array into $a0
    lw      $t0,        array_size                                      # Load array size (10) into $t0

    jal     sum_array                                                   # Jump and link to sum_array

    l.s     $f1,        float_size                                      # Load 10.0 into $f1 (the divisor)
    div.s   $f12,       $f0,        $f1                                 # Calculate Average ($f12 = $f0 / $f1)

    li      $v0,        2                                               # System call code for print_float
    syscall

    li      $v0,        10
    syscall

sum_array:

    bge     $s0,        $t0,        sum_end                             # Loop condition: if i >= 10, exit

    sll     $t1,        $s0,        2                                   # Multiply index i by 4 (byte offset)
    add     $t2,        $a0,        $t1                                 # Calculate address of array[i] ($t2 = array + offset)

    l.s     $f2,        0($t2)                                          # Load float from memory into $f2 (Load Single)
    add.s   $f0,        $f0,        $f2                                 # Floating-point addition: sum += array[i]

    addi    $s0,        $s0,        1                                   # i++
    j       sum_array

sum_end:
    jr      $ra