program print_tut
    implicit none
    character (len = 5) :: i_char

    print *, "A number ", 10 ! right justified
    print "(3i5)", 7, 6, 8 ! (RiW): R = num of cols, i = integer, 5 = spaces bw cols (width)
    print "(i5)", 7, 6, 8
    print "(2f8.5)", 3.1415, 1.234 ! (RfW.D): f = float, D = num of decimals
    print "(/, 2a8)", "Name", "Age" ! "/" means next line
    print "(e10.3)", 123.456 ! exponential notation to 3 sig. figs (decimal places)
    print "(a5,i2)", "I am ", 43

    write (i_char, "(i5)") 10
    print "(a,a,a)", "A number ", adjustl(i_char), " lol"
    
end program print_tut