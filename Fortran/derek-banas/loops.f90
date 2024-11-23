program loops
    implicit none
    integer :: n, m = 1, k = 1, j = 0
    integer :: secret_num = 7

    do n = 1, 10, 2 ! start=1, end=10, increment=2
        print "(i1)", n
    end do

    do while (m < 20) ! print only even numbers
        if (mod(m,2) == 0) then
            print "(i2)", m
            m = m + 1
        else
            m = m + 1
        end if
    end do

    do while (k < 20) ! print only even numbers, but exit do loop
        if (mod(k,2) == 0) then
            print "(i2)", k
            k = k + 1
        else
            k = k + 1
        end if
        if (k >= 10) then
            exit
        end if
    end do

    do while (j /= secret_num)
        print *, "What is your guess? "
        read *, j
    end do
    print *, "Correct!"

end program loops