program variables
    implicit none
    real, parameter :: PI = 3.1415 ! real = float (6 digits of precision), parameter means constant
    real :: r_num1 = 0.0, r_num2 = 0.0
    double precision :: dbl_num = 1.1111111111111111d+0 ! 15 decimals, with d+0 to get more precision
    integer :: i_num1 = 0, i_num2 = 0
    logical :: can_vote = .true. ! or .false.
    character (len = 10) :: month ! strings
    complex :: com_num = (2.0, 4.0) ! complex number

    print *, "Biggest Real ", huge(r_num1) ! prints out the biggest real number you can put in
    print *, "Smallest Real ", tiny(r_num1) ! prints out the smallest real number you can put in
    print *, "Biggest Int ", huge(i_num1) ! Same idea but for ints (no tiny for ints)
    print *, "Biggest Double ", huge(dbl_num)
    print *, "Smallest Double ", tiny(dbl_num)

    print "(a4, i1)", "Int ", kind(i_num1) ! (a4, i1) means print two things. a for string, i for int, 4 for 4 spaces, etc.
    print "(a5, i1)", "Real ", kind(r_num1) ! kind prints out number of bytes taken up by data type
    print "(a7, i1)", "Double ", kind(dbl_num)
    print "(a8, i1)", "Logical ", kind(can_vote)

end program variables