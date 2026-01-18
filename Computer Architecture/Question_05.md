# Basic Steps when a procedure is executed

1. **Save the return address** - Store the address of the instruction following the procedure call so the program knows where to return.

2. **Pass arguments** - Transfer input parameters to the procedure (typically via registers or stack).

3. **Allocate stack space** - Reserve memory on the stack for local variables and save registers that need to be preserved.

4. **Save caller's registers** - Store the values of registers that the caller expects to remain unchanged.

5. **Execute procedure body** - Run the actual instructions that make up the procedure.

6. **Prepare return value** - Place the result (if any) in the designated register or memory location.

7. **Restore registers** - Restore the caller's register values that were saved earlier.

8. **Deallocate stack space** - Release the stack memory used for local variables.

9. **Return to caller** - Jump back to the return address saved in step 1.

10. **Resume execution** - The caller continues executing from where it left off, potentially using the returned value.