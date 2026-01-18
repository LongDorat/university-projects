.data
array:  .word   1, 2, 3, 4, 5, 6, 7, 8, 9, 10

la      $s0,    array
li      $s1,    5

    # Load A[5] into $t0, assuming that the array only consist of integers
lw      $t0,    20($s0)

    # x = y + a[5], assuming that y is associated with $s1
add     $t1,    $t0,        $s1