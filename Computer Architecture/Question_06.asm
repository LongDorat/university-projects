    # Assuming a, b, c, and d are associated with $s0, $s1, $s2, and $s3 respectively
    # Mock up data
    li      $s0,        10          # a = 10
    li      $s1,        20          # b = 20
    li      $s2,        30          # c = 30
    li      $s3,        40          # d = 40

    # Calling the procedure proc_exa
    la      $a0,        ($s0)
    la      $a1,        ($s1)
    la      $a2,        ($s2)
    la      $a3,        ($s3)

    jal     proc_exa

    li      $v0,        1
    la      $a0,        ($s4)
    syscall

    li      $v0,        10
    syscall

proc_exa:
    # $t0 = (a + b)
    add     $t0,        $a0,    $a1

    # $t1 = (c + d)
    add     $t1,        $a2,    $a3

    # $s6 = (a + b) - (c + d)
    sub     $s4,        $t0,    $t1

    jr      $ra