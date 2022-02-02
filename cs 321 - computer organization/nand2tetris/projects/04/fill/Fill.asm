// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

@pixel
M=0 // selects top left corner

(LOOP)
	@KBD // reads from keyboard
	D=M
	@notpressed // if value is 0
	D;JEQ // jump to notpressed (blank screen)
	@pressed // if value is other than 0
	0;JMP // jump to pressed (black screen)

(notpressed)
	@pixel 
	D=M // set D to current memory of pixel
	@0 // max RAM address?
	D=D-A // keeps it within the correct RAM boundaries
	@LOOP
	D;JLT // once smallest value is reached, go back to LOOP
	@pixel
	D=M // set D to current memory of pixel
	@SCREEN // load screen's address
	A=D+A // selecting RAM address for the correct part of the screen
	M=0 // setting memory of screen to white
	@pixel 
	MD=M-1 // selects previous pixel
	@LOOP
	0;JMP // jump back to LOOP

(pressed)
	@pixel 
	D=M // set D to current memory of pixel
	@8192 // max RAM address?
	D=D-A // keeps it within the correct RAM boundaries
	@LOOP
	D;JGE // once largest value is reached, go back to LOOP
	@pixel 
	D=M // set D to current memory of pixel
	@SCREEN
	A=D+A // selecting RAM address for the correct part of the screen
	M=-1 // setting memory of screen to black
	@pixel
	MD=M+1 // selects the next pixel
	@LOOP
	0;JMP // jump back to LOOP