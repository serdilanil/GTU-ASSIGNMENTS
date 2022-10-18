;you can enter up to 63 in value as input since i stored 2 numbers in 1 register
;I did division as a loop first checking if number is equal and lower than 15 then substiting -16 from number then adding 1 to the result register 



load R5,[192]	;Please enter the numbers from address C0h(192) to address CFh(207) in main memory
load R0,[193]
addi R5,R5,R0 	;storing 2 numbers in 1 register since I dont have enough registers
load R6,[194]
load R0,[195]
addi R6,R6,R0
load R7,[196]
load R0,[197]
addi R7,R7,R0
load R8,[198]
load R0,[199]
addi R8,R8,R0
load R9,[200]
load R0,[201]
addi R9,R9,R0
load RA,[202]
load R0,[203]
addi RA,RA,R0
load RB,[204]
load R0,[205]
addi RB,RB,R0
load RC,[206]
load R0,[207]
addi RC,RC,R0

load R0,15    ;I use 15 for remainder control 
load R1,-16   ;I use -16 for division operation(by substiting -16 from number)
load R2,0     ;I store the result of division in this register
load R3,1     ;for adding 1 to the result after each substition

loop0:jmpLE R5 <= R0,loop1	;division loop for numbers
	addi R5,R5,R1
	addi R2,R2,R3
	jmp loop0

loop1:jmpLE R6 <= R0,loop2
	addi R6,R6,R1
	addi R2,R2,R3
	jmp loop1	

loop2:jmpLE R7 <= R0,loop3
	addi R7,R7,R1
	addi R2,R2,R3
	jmp loop2	

loop3:jmpLE R8 <= R0,loop4
	addi R8,R8,R1
	addi R2,R2,R3
	jmp loop3	
loop4:jmpLE R9 <= R0,loop5
	addi R9,R9,R1
	addi R2,R2,R3
	jmp loop4
loop5:jmpLE RA <= R0,loop6
	addi RA,RA,R1
	addi R2,R2,R3
	jmp loop5
loop6:jmpLE RB <= R0,loop7
	addi RB,RB,R1
	addi R2,R2,R3
	jmp loop6
loop7:jmpLE RC <= R0,next
	addi RC,RC,R1
	addi R2,R2,R3
	jmp loop7
					
next:		load RE,0 	;adding up remainders after divisions
		addi RE,RE,R5
	   	addi RE,RE,R6
	   	addi RE,RE,R7
	   	addi RE,RE,R8
	   	addi RE,RE,R9
		addi RE,RE,RA
		addi RE,RE,RB
		addi RE,RE,RC
		jmp loop8


loop8:jmpLE RE <= R0,end	;dividing remainders by 16
	 addi RE,RE,R1
	 addi R2,R2,R3
	 jmp loop8	
	
end:move R0,R2			;moving the result to R0
    halt
