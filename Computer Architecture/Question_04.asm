    # Load an integer into x
    li      $t0,    42

    bge     $t0,    $zero,  setToX  # if x >= 0, set h = x
    li      $t1,    0               # else h = 0
    j       exit

setToX:
    move    $t1,    $t0             # h = x

exit: