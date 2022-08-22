.data 

original_list: .space 100 
sorted_list: .space 100

space: .asciiz " "
nextLine: .asciiz "\n"

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: \n"
str2: .asciiz "Content of original list: "
str3: .asciiz "Enter a key to search for: "
str4: .asciiz "Content of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"

nozero: .asciiz "\nThe list size should be greater than 0! \n"
nonegative: .asciiz "\nThe list size should not be negative! \n"
error_msg: .asciiz "\nThe list size cannot be greater than 25! \n "

.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main: 
	#overwrites $ra
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4 	#prints first prompt
	la $a0, str0 
	syscall 
	li $v0, 5	#read size of list from user
	syscall
	move $s0, $v0
	move $t0, $0
	la $s1, original_list
loop_in:
	move $t9, $0
	addi $t9,$zero,25
	beqz $s0, NoZero
	bltz $s0, negative	#error checking; lets user know values entered are invalid
  	bgtu $s0, $t9, invalid_size
  	
	li $v0, 4 
	la $a0, str1 		#prints second prompt
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5		#read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	move $a0, $s1		#moves arguments from memory to argument registers
	move $a1, $s0
	
	jal inSort		#Call inSort to perform insertion sort in original list
	
	sw $v0, 4($sp)
	li $v0, 4 		#prints third prompt
	la $a0, str2 
	syscall 
	
	la $a0, original_list
	move $a1, $s0
	
	jal printList		#Print original list
	
	li $v0, 4 
	la $a0, str4 		#prints fifth prompt
	syscall 
	
	lw $a0, 4($sp)
	
	jal printList		#Print sorted list
	
	li $v0, 4 
	la $a0, str3 		#prints fourth prompt
	syscall 
	
	li $v0, 5
	syscall			#read search key from user
	
	move $a3, $v0
	lw $a0, 4($sp)
	
	jal bSearch		#call bSearch to perform binary search
	
	beq $v0, $0, notFound
	
	li $v0, 4 
	la $a0, strYes 		#prints found if key is found
	syscall 
	
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 		#prints not found if key is not found
	syscall 
end:
	lw $ra, 0($sp)		#restores $ra
	addi $sp, $sp 8		
	
	li $v0, 10 		#ends program
	syscall

Exit:   
   li $v0, 10	 #exits program
   syscall
	
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
	#Your implementation of printList here	
	addi $sp, $sp, -4	#overwrites $ra
	sw $ra, 0($sp)
	
	move $t0, $a0		#load arguements to temporary registers
	move $t1, $a1
	
loopPrintList:
	lw $a0, 0($t0)
	li $v0, 1	#loads element from list arguement and prints it out
	syscall
	
	li $v0, 4
	la $a0, space	#loads space and prints it out
	syscall
	
	addi $t0, $t0, 4	#iterates pointers and iterator
	addi $t1, $t1, -1
	
	beq $t1, $zero, exitPrintList #if size iterator = 0 exit print list else, j to loopPrintList
	
	j loopPrintList
	
exitPrintList:
	li $v0, 4
	la $a0, nextLine	#loads a new line and prints it out
	syscall
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4	#restores $ra
	
	jr $ra
	
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	
	addi $sp, $sp, -32	#overwrites $ra
	sw $ra, 8($sp)
	sw $s0, 12($sp)
	sw $s1, 16($sp)
	sw $s2, 20($sp)
	sw $s3, 24($sp)
	sw $s4, 28($sp)
	
	move $s0, $a0		#move arguments into respective temp registers
	move $s1, $a1
	
	addi $s2, $zero, 1	#initialize i = 1
	
arraycp:
	la $t0, original_list	#load original list
	la $t1, sorted_list	#loads empty sorted list
	addi $t6, $t6, 0	#iterator
	
arraycploop:
	beq $s1, $t6, arraycpend	#iterator is done when one less than size($s1)
	lw $t2, ($t0)			#grabs element from original list
	sw $t2, ($t1)			#stores element into sorted list
		
	addi $t0, $t0, 4 
	addi $t1, $t1, 4		#iterates pointers and iterator
	addi $t6, $t6, 1
	
	j arraycploop

arraycpend:
	#now using sorted list to perform insertion sort
	la $t1, sorted_list	#loading sorted list into $t1
	move $s0, $t1		#sorted list is stored inside $s0

iloop:
	beq $s2, $s1, iend	#if i = arraySize, then end
	sll $t2, $s2, 2		#$t2 = offset(muliplies i by 4)
	add $t3, $s0, $t2	#t3 = address of array + offset
	lw $s3, ($t3)		#s3 = array[i]
	addi $s4, $s2, -1	#j = i - 1
jloop:
	bltz $s4, jend		#break if j < 0
	move $a0, $s3		#a0 = s3 = key = array[i]
	la $t0, ($s0) 
	sll $t2, $s4, 2
	add $t3, $t0, $t2	#t3 = array[j]
	lw $a1, ($t3)		#value of array[j] as argument 

	jal strlt 
		
	move $t0, $v0
	beq $t0, $zero, jend	#if true, end
		
		
#nested loops starts here
	
	la $t0, ($s0)
	sll $t2, $s4, 2 
	add $t3, $t0, $t2
	lw $t4, 0($t3)		#t4 = array[j]

	addi $t2, $s4, 1 	#t2 = j + 1
	sll $t3, $t2, 2
	add $t1, $t3, $s0 	#address of array[j+1]
	sw $t4, 0($t1) 		#array[j+1] = array[j]
	addi $s4, $s4, -1 
		
	j jloop
		
jend:	
	move $t0, $s4		#array[j+1] = key
	addi $t0, $t0, 1
	sll $t2, $t0, 2
	add $t1, $s0, $t2
		
	sw $s3, ($t1)
	
	addi $s2, $s2, 1
	j iloop

iend:
	move $a1, $s1		#restores a1
	
	lw $ra, 8($sp)
	lw $s0, 12($sp)
	lw $s1, 16($sp)		#restores $ra
	lw $s2, 20($sp)
	lw $s3, 24($sp)
	lw $s4, 28($sp)
	addi $sp, $sp, 32
	
	la $v0, sorted_list	#returns the address of sorted array
	
	jr $ra
	
#string less than function: returns true if less than, false if greater than
strlt: 

	move $t0, $a0 	#t0 = a0 = s3 = key = array[i]
	move $t1, $a1 #array [j]


	sltloop:
	blt $t0, $t1, iflt #jumps to iflt if t0 < t1
	bge $t0, $t1, ifgt #jumps to ifgt if t0 > t1
	
	j sltloop
	
	stringend:
	beq $t2, $zero, iflt	# checks if x = 0
	j ifgt			# returns false
	
	 #returns true
	iflt:
	li $v0, 1
	j sltend	
	
	#returns false
	ifgt:
	li $v0, 0
	j sltend

	sltend:
	jr $ra
	
	
#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
	move $s0, $a0	#address sorted list
	move $s1, $a1	#size/right
	move $s2, $a3 	#search key
	move $s3, $a2 	#left
	li $s5, 0 	#mid

	addi $s1, $s1, -1 # size/right
	
	bgt $s3, $s1, rightcheck #checks if left > right
	
goback:
	blt $s1, $s3, bfalse	#checks if right > left
	
	sub $t0, $s1, $s3	#mid = l + (r - l)/2
	div $t0, $t0, 2
	add $s5, $s3, $t0
	
	sll $t1, $s5, 2		#t1 = array[mid]
	add $t2, $s0, $t1
	lw $t1, ($t2)
	
	beq $t1, $s2, btrue	#checks if array[mid] == search key
	
	li $t4, 0		#if l = 0 & r = 0, return false
	li $t5, 0
	
	slti $t4, $a3, 1
	slti $t5, $a1, 1
	
	add $t4, $t4, $t5
	li $t5, 2
	beq $t4, $t5, bfalse
	
	bgt $t1, $s2, bsgt	#jumps to bsgt if t0 > t1
	blt $t1, $s2, bslt	#jumps to bslt if t0 < t1 
	
bsgt:
	sub $a1, $s5, $s3
	j bSearch
bslt:
	addi $a2, $s5, 1
	j bSearch
btrue:
	li $v0, 1
	jr $ra
bfalse:
	li $v0, 0
	jr $ra
	
rightcheck:
	sll $t6, $s1, 2
	add $t6, $s0, $t6
	lw $t7, ($t6)
	beq $s2, $t7, btrue
		
	j goback

NoZero:
	la $a0, nozero
  	li $v0, 4
  	syscall
	j Exit
negative:
	la $a0, nonegative
  	li $v0, 4
  	syscall
	j Exit
invalid_size:
  	la $a0, error_msg
  	li $v0, 4
  	syscall
	j Exit

