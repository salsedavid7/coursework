  .data
intro: .asciiz "Please enter an integer: "


        .text
main: 		addi $sp, $sp, -4	
		li $v0, 4       #ask for user input
		la $a0, intro
		syscall 
		
		li $v0, 5 
		syscall		#reads user input
		move $a0, $v0   
		addi $v0, $zero, 0  
		
		jal recursion	#Call recursion(x)
		
		sw $v0, 0($sp)  #prints final return value
		lw $a0, 0($sp)
		
		li $v0, 1		 
		syscall	
		
		j end


recursion:	addi $sp, $sp, -12
		sw $ra, 8($sp)  #stores return address in stack frame
		
		addi $t0, $zero, 10 #checks if m is 10
		bne $t0, $a0, case1

		addi $v0, $v0, 2 
		j end_recur
			
case1:	addi $t0, $zero, 11 #checks if m is 11 
		bne $t0, $a0, case2
		
		addi $v0, $v0, 1
		
		j end_recur		

case2:	sw $a0, 4($sp) 	
		addi $a0, $a0, 2 #m + 2
		
		jal recursion	#Call recursion m + 2
		lw $a0, 4($sp)   #loads first return value
		
		addi $a0, $a0, 1 #m + 1
		jal recursion	#Call recursion m + 1
		
		lw $a0, 4($sp) 
		add $v0, $v0, $a0  #adds all values up
		j end_recur
		
end_recur:	
		lw $ra, 8($sp) 
		addi $sp, $sp, 12	#Pop stack frame 
		jr $ra

end:		addi $sp, $sp 4		#Pop stack frame
		li $v0, 10 
		syscall
