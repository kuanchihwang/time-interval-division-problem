program ftn_div_test
    implicit none

    print *, 'Euclidean division'
    print *, ' 23 /  7 = ',   floor(( 23.) / ( 7.)), ' ... ',  23 - abs( 7) * floor(( 23.) / abs( 7.))
    print *, '-23 /  7 = ',   floor((-23.) / ( 7.)), ' ... ', -23 - abs( 7) * floor((-23.) / abs( 7.))
    print *, ' 23 / -7 = ', ceiling(( 23.) / (-7.)), ' ... ',  23 - abs(-7) * floor(( 23.) / abs(-7.))
    print *, '-23 / -7 = ', ceiling((-23.) / (-7.)), ' ... ', -23 - abs(-7) * floor((-23.) / abs(-7.))

    print *, 'Floored division'
    print *, ' 23 /  7 = ',   floor(( 23.) / ( 7.)), ' ... ', modulo( 23,  7)
    print *, '-23 /  7 = ',   floor((-23.) / ( 7.)), ' ... ', modulo(-23,  7)
    print *, ' 23 / -7 = ',   floor(( 23.) / (-7.)), ' ... ', modulo( 23, -7)
    print *, '-23 / -7 = ',   floor((-23.) / (-7.)), ' ... ', modulo(-23, -7)

    print *, 'Truncated division'
    print *, ' 23 /  7 = ', ( 23) / ( 7), ' ... ', mod( 23,  7)
    print *, '-23 /  7 = ', (-23) / ( 7), ' ... ', mod(-23,  7)
    print *, ' 23 / -7 = ', ( 23) / (-7), ' ... ', mod( 23, -7)
    print *, '-23 / -7 = ', (-23) / (-7), ' ... ', mod(-23, -7)
end program ftn_div_test
