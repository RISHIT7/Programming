.global _start
_start:
	mov r0, #2
	mov r1, #1
	
	@ comparison between two values
	cmp r0, r1 // does... r0-r1 and checks the cpsr register
	
	@ check to see if r0 is greater than r1
	bgt greater // branch greater than
	bal default // branch always ( similar to if true or default in switch )
	@ some other branches
	// bge, blt, ble, beq, bne
	// greater+equal, less, less+equal, equal, not equal
	// find more in the documentations, there are many!
	
	mov r2, #2 // if not for default we will anyways later go to greater branch
	
greater:
	mov r2, #1 // but now we will reach the default branch always regardless of greater
	bal continue // to solve the above problem
	
default:
	mov r2, #2
	
continue:
	mov r7, #1
	swi 0