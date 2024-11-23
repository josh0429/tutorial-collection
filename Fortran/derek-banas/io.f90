program io ! in any program, the variable declarations always are typed first
    implicit none ! means all variables you will define will have their data types explicitly stated by you
    character*20 :: name
    character (len = 20) :: f_name, l_name

    print *, "What's your name "

    read *, f_name, l_name
    print *, "Hello ", trim(f_name), " ", trim(l_name)

end program io