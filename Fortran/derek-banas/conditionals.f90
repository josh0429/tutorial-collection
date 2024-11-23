program conditionals
    implicit none
    integer :: age = 16
    if ((age >= 5) .and. (age <= 6)) then
        print *, "Kindergarten"
    else if ((age >= 7) .and. (age <= 13)) then
        print *, "Middle School"
    else if ((age >= 14) .and. (age <= 18)) then
        print *, "High School"
    else
        print *, "Stay home"
    end if

    print *, .true. .or. .false.
    print *, .not. .true.
    print *, 5 /= 9
    print *, "a" < "b"
    print *, "e" < "e"

    select case(age)
    case(5)
        print *, "Kindergarten"
    case(6:13)
        print *, "Middle School"
    case(14:18)
        print *, "High School"
    case default
        print *, "Stay home"
    end select
    
end program conditionals