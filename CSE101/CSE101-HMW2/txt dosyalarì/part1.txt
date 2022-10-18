load R0,00000001b
load R1,10000000b
load R5,0xFF
xor R6,R0,R5
xor R7,R1,R5
load R2,0x01
addi R7,R7,R2
halt