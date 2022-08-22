.data
	n: .word 25
	str1: .asciiz"Less than\n"    
	str2: .asciiz "Less than or equal to\n"
	str3: .asciiz"Greater than\n"  
	str4: .asciiz "Greater than or equal to\n" 
	enter: .asciiz "Please enter a number:"
.text

	la $t1, n
	lw $t1, 0($t1)
	
	li $v0, 4
	la $a0, enter #prints contents of enter
	syscall
	
	li $v0, 5 
	syscall #userinput
 	move $t0, $v0 # register $t0 now contains user input value
 	
 	

#   	slt $s0, $t0, $t1 #s0 = 1 if (userinput < 25)
 #    	bne $s0, $zero, lt #if (s0 != 0) branch to less than procedure
  #     beq $s0, $zero, eq #if(s0 = 0) branch to eq procedure
 	
   #    	li $v0, 10 #ends program
    #   	syscall

#Less than	 
     # 	lt:	
      #	li $v0, 4
      #	la $a0, str1  #prints "Less than"
      #	syscall


#greater than or equal to
	#eq:	
       	#beq $t0, $t1, gteq #if (user input = 25) branch to greater than or equal to procedure
       	#bne $t0, $t1, gteq #if (user input != 25), branch to greater than or equal to 
      	 
       #gteq:	
       #slt $s0, $t0, $t1 #if userinput < 25, s0 now equals 1
       #beq $s0, $zero, gte #if s0 = 0, branch to greater than or equal to procedure
	
       #li $v0, 10
       #syscall

       #gte:	
       #li $v0, 4
       #la $a0, str4 #print greater than or equal to
       #syscall
       
       
       
       
        sgt $s0, $t0, $t1 #s0 = 1 if (userinput > 25)
  	bne $s0, $zero, gt #if (s0 != 0) branch to less than procedure
	beq $s0, $zero, eq #if(s0 = 0) branch to eq procedure

#7: greater than
	gt:	
      	li $v0, 4
      	la $a0, str3  #prints "Greater than"
      	syscall
        li $v0, 10 #ends program
       	syscall
      	
	
#8: less than or equal to
	eq:	
       	beq $t0, $t1, lteq #if (user input = 25) branch to less than or equal to procedure
       	bne $t0, $t1, lt #if (user input != 25), branch to less than or equal to 
      	 

       lteq:	
       li $v0, 4
       la $a0, str2 #print less than or equal to
       syscall
              li $v0, 10
       syscall
       
       lt:
       li $v0, 4
       la $a0, str1 #print less than 
       syscall
              li $v0, 10
       syscall
       

	




	
        