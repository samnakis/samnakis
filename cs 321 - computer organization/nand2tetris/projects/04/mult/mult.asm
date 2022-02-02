// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@R2 // load R2
M=0 // set R2 (sum) value to 0

(LOOP)
	@R0 // load R0
	D=M // sets D = to memory of R0
	@END //loads END
	D;JEQ // if D=0, jump to END
	@R1 // load R1
	D=M // sets memory of R1 to D
	@R2 // load R2
	M=D+M // adds memory of R1 to memory of R2 (sum)
	@R0 // load R0
	M=M-1 // subtracts 1 from the R0 (counter) to update count
	@LOOP // loads LOOP
	0;JMP // jumps back to start of loop
	
(END)
	@END
	0;JMP //infinite loop