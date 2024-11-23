program arrays
    implicit none
    integer, dimension(1:5) :: a1, a2, a3
    real, dimension(1:50) :: aR1
    integer, dimension(5,5) :: a4
    integer :: n, m, x, y
    integer, dimension(:), allocatable :: a5 ! array size determined at runtime
    integer :: num_vals
    integer, dimension(1:9) :: a6 = (/1, 2, 3, 4, 5, 6, 7, 8, 9/) ! syntax for defining arrays
    integer, dimension(1:3, 1:3) :: a7

    a1(1) = 5 ! fortran arrays start indexing at 1 by default. can index at 0 by dimension(0:end)
    print "(i1)", a1(1)

    do n = 1, 5
        a1(n) = n
    end do

    do n = 1, 5
        print "(i1)", a1(n)
    end do

    print "(3i2)", a1(1:3) ! access array elements 1, 2, 3
    print "(2i2)", a1(1:3:2) ! access array elements 1 and 3

    do n = 1, 5
        do m = 1, 5
            a4(n,m) = n*m
        end do
    end do

    do n = 1, 5
        do m = 1, 5
            print "(i1, a1, i1, a3, i2)", n, " ", m, " : ", a4(n,m)
        end do
    end do

    do n = 1, 5
        do m = 1, 5
            a4(n,m) = n
        end do
    end do

    do n = 1, 5
        print "(5i1)", (a4(n,m), m = 1,5) ! implicit do loop
    end do

    print "(i2)", size(a1) ! prints number of elements
    print "(i2)", size(a4)

    print "(i2)", rank(a4) ! dimension of array
    print "(2i2)", shape(a4) ! shape of array

    ! defining array size at runtime
    print *, "Input size of array "
    read *, num_vals
    allocate(a5(1:num_vals))

    do n = 1, num_vals
        a5(n) = n
    end do

    do n = 1, num_vals
        print "(i1)", a5(n)
    end do

    a2 = (/1,2,4,6,3/)
    print "(5i1)", (a2(n), n= 1, 5)

    a7 = reshape(a6, (/3, 3/)) ! transpose of what i thought it would be
    do n = 1, 3
        print "(3i1)", (a7(n,m), m = 1,3)
    end do

    print "(l1)", all(a1 ==  a2, 1) ! all elements are equal? 1 is the axis
    print "(l1)", any(a1 ==  a2, 1) ! any elements are equal?
    print "(i1)", count(a1 ==  a2, 1)

    print "(i1)", maxval(a1)
    print "(i1)", minval(a1)

    print "(i3)", product(a1)
    print "(i2)", sum(a1)

end program arrays