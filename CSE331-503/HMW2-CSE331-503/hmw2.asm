.data
	array: .word 3, 10, 7, 9, 4, 11 # Elements of Array
	bracket: .asciiz "["
	bracket2: .asciiz "]"
	newLine: .asciiz "\n"
	comma: .asciiz ","
	temp: .space 1024  #256 integer capacity
	listArr: .space 1024 #256 integer capacity
.text
	.globl main
	
	main:
	li $a1 , 0 # a1 represent temp index
	li $a1 , 4 #temp index(index 4 4 artra)
	sw $zero,temp($a1)
	li $a2 , 0 # array index 
	li $a3 , 0 #max size
	li $s0 , 24 # array.length
	
    	jal findLongest # Call the recursive function
    			
    	la $s7,array 		#I assign to array address and I print the 6 different array like this.
    	li $t0,28    # I record the numbers of array with this way.
    	li $t1,35
    	li $t2,3
    	li $t3,102
    	li $t4,50
    	sw $t0,0($s7)
    	sw $t1,4($s7)
    	sw $t2,8($s7)
    	sw $t3,12($s7)
    	sw $t4,16($s7)
    	li $a1 , 0 #temp index
	li $a1 , 4 #temp index, I increase 4 by 4
	sw $zero,temp($a1)
	li $a2 , 0 # array index 
	li $a3 , 0 #max size
	li $s0 , 20 # array length 
	
    	
    	jal findLongest # Call the recursive function
    	
    	
    	la $s6,array
    	li $t0,7
    	li $t1,9
    	li $t2,12
    	sw $t0,0($s6)
    	sw $t1,4($s6)
    	sw $t2,8($s6)
    	li $a1 , 0 #temp index
	li $a1 , 4 #temp index
	sw $zero,temp($a1)
	li $a2 , 0 # array index 
	li $a3 , 0 #max size
	li $s0 , 12 # array.length
	
    	jal findLongest # Call the recursive function
    	
    	
    	la $s5,array
    	li $t0,44
    	li $t1,55
    	li $t2,36
    	li $t3,72
    	sw $t0,0($s6)
    	sw $t1,4($s6)
    	sw $t2,8($s6)
    	sw $t3,12($s6)
    	li $a1 , 0 #temp index
	li $a1 , 4 #temp index
	sw $zero,temp($a1)
	li $a2 , 0 # array index 
	li $a3 , 0 #max size
	li $s0 , 16 # array.length
	
    	jal findLongest # Call the recursive function
    	
    	
    	la $s4,array
    	li $t0,100
    	li $t1,99
    	li $t2,120
    	sw $t0,0($s6)
    	sw $t1,4($s6)
    	sw $t2,8($s6)
    	li $a1 , 0 #temp index
	li $a1 , 4 #temp index
	sw $zero,temp($a1)
	li $a2 , 0 # array index
	li $a3 , 0 #max size
	li $s0 , 12 # array.length
	
    	jal findLongest # Call the recursive function
    	
    	
    	la $s3,array
    	li $t0,107
    	li $t1,320
    	li $t2,360
    	li $t3,150
    	sw $t0,0($s6)
    	sw $t1,4($s6)
    	sw $t2,8($s6)
    	sw $t3,12($s6)
    	li $a1 , 0 #temp index
	li $a1 , 4 #temp index
	sw $zero,temp($a1)
	li $a2 , 0 # array index 
	li $a3 , 0 #max size
	li $s0 , 16 # array.length
	
    	jal findLongest # Call the recursive function
    	
	li $v0,10
        syscall
        
#findLongest Procedure

findLongest:         #I use recursive for travelling array.

	beq $a2,$s0,terminate # I compare the temp index with 
	
	bgt $s0,$a2,skip
	
	bge $a3,$a1,next  # I compare the max size with array size defined me.
	
	move $a3,$a1
	li $t8,0
	
	loop:               #If there is overflow I terminate the loop.
	 bgt $a1,$t8,cease
	 lw $t2,temp($t8)
	 
	j loop
	
	li $v0,1
	move $a0,$t2
	syscall
	 
	li $v0,4
	la $a0,newLine
	syscall
	
cease:

next: 
	
skip:         #If array length bigger than array index , program continue this way.
	
	addi $sp,$sp,-12 # I keep the 12 space.
	
	sw $ra,0($sp) # I use the stack pointer for I keep the first value.
	sw $a1,4($sp) 
	sw $a2,8($sp) 
	

	lw $t7, array($a2) #I assign current index to the $t7 register 
	
	
	jal check # I call the check procedure
	
	
	addi $a2,$a2,4 # increasing index
	
     	jal findLongest #I go back to findLongest
     	
	lw $ra,0($sp)
	lw $a1,4($sp)
	lw $a2,8($sp)
	addi $a2,$a2,4
	
	jal findLongest
	
	lw $ra,0($sp) # I call back the data I saved up there
	lw $a1,4($sp)
	lw $a2,8($sp)
	
	addi $sp,$sp,12 #stack pointerda da ald???m yeri geri b?rak?p yukar? ç?k?yorum
			# I send back space when I took stack pointer
	jr $ra
	#Syscall to end program
	li $v0,10
	syscall

	lw $t9,array($a2)
	sw $t9,temp($a1)
	
	addi $a1,$a1,-4
	
	addi $a2 , $a2,4 

continue:            #If there is not overflow I keep to process the array.

	jal findLongest
	
	lw $ra,0($sp) #I record again.
	lw $a1,4($sp) # I convert old status.
	lw $a2,8($sp)
	
	addi $sp,$sp,12 
	
	jr $ra
	
	#Syscall to end program
	li $v0,10
	syscall
	
terminate:
  	li $t3,0
  	beq $a1,$zero,exit #zero yerine 0 yaz
  	j printArray


check:              # I compare array index and temp index for subsequence order.
 	sub $a1,$a1,4	
 	lw $t6, temp($a1) # I record the current index of array to register $t6.
 	addi $a1,$a1,4

 	slt $v0,$t6,$t7
 	beq $v0,1,finish

 	jr $ra


printArray:  #print value
		
            lw $t5, temp($t3)
            addi $t3 , $t3 , 4
            
	    li $v0,1
	    move $a0,$t5
	    syscall
	    
	    #nextLine
	    li $v0,4
	    la $a0,comma
	    syscall 
	    
	    bne $t3,$a1,printArray
	   
	    #nextLine
	    li $v0,4
	    la $a0,newLine
	    syscall
	    
	    jr $ra


finish:
	sw $t7,temp($a1)
	addi $a1,$a1,4
	jr $ra

exit:
	li $v0,10
        syscall
        
        
        

	
	
	
        
