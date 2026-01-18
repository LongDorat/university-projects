    # Assuming a, b, c, and d are associated with $s0, $s1, $s2, and $s3 respectively
    # Mock up data
    li      $s0, 10      # a = 10
    li      $s1, 20      # b = 20
    li      $s2, 30      # c = 30
    li      $s3, 40      # d = 40

    # Calling the procedure proc_exa
    jal     proc_exa

proc_exa:
    # $t0 = (a + b)
    add     $t0,    $s0,    $s1

    # $t1 = (c + d)
    add     $t1,    $s2,    $s3

    # $s6 = (a + b) - (c + d)
    sub     $s6,    $t0,    $t1