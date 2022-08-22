.data
    Enter: .asciiz "\nPlease enter a number: "
    posSum: .asciiz "\nSum of positive numbers is: "
    negSum: .asciiz "\nSum of negative numbers is: "

.text
    
     li $s0,0 #positive number sum
     li $s1,0 #negative number sum

loop:

     li $v0,4
     la $a0,Enter #prints, "Please enter a number"
     syscall

     li $v0,5
     syscall #Allows for user input
     move $t0,$v0

     beqz $t0,done #if value is equal to zero, branch to done procedure

     
     bltz $t0, negativeNum #if t0 is less than zero, branch to negativeNum procedure
     
    
    add $s0,$s0,$t0 #else, update pos sum
    j skip
     
negativeNum:

     add $s1,$s1,$t0 #add to neg sum
     
skip: #this function will keep executing the loop procedure until user enters 0

     j loop
     
done:

li $v0,4
la $a0,posSum #prints posSum prompt
syscall
move $a0,$s0 #updates s0 register with the sum of positive numbers
li $v0,1
syscall #prints sum of positive values

li $v0, 4
la $a0, negSum #prints negSum prompt
syscall
move $a0, $s1 #updates s1 register with the sum of negative numbers
li $v0, 1 
syscall #prints sum of negative values
