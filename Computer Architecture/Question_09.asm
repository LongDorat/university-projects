.data
perimeter:  .asciiz "Perimeter: "
area:       .asciiz "Area: "

.text
            .globl  main

main:
    # Read user input length and width
    li      $v0,    5
    syscall
    move    $s1,    $v0

    li      $v0,    5
    syscall
    move    $s2,    $v0

    # Compute the perimeter and area of the rectangle
    add     $t0,    $s1,        $s2
    sll     $t1,    $t0,        1

    mul     $t2,    $s1,        $s2

    # Display the result
    li      $v0,    4
    la      $a0,    perimeter
    syscall

    li      $v0,    1
    move    $a0,    $t1
    syscall

    ## Create a new line
    li      $v0,    11
    li      $a0,    10
    syscall

    li      $v0,    4
    la      $a0,    area
    syscall

    li      $v0,    1
    move    $a0,    $t2
    syscall