.data
array:  .word   5, 3, 8, 6, 2, 7, 4, 1, 9, 0

.text
        .globl  main
main:
    # Generate i and max = 0
    li      $s0,    0
    li      $s1,    0

    j       max

max:
    # Loop condition
    bge     $s0,    10,         exit

    # Load the integer from an array
    sll     $t1,    $s0,        2               # Multiply index by 4 to get byte offset
    lw      $t0,    array($t1)

    # Compare the number
    blt     $s1,    $t0,        update_max      # if max < array[i], update
    addi    $s0,    $s0,        1               # increment index
    j       max

update_max:
    move    $s1,    $t0
    j       max

exit:
    li      $v0,    1
    move    $a0,    $s1
    syscall