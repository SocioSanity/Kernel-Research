// boot.S - Bootstrap the Kernel
// first we give some definitions,
// to make our code more readable later

#define ASM		1

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002 // magic no. for multiboot header
#define MULTIBOOT_HEADER_FLAGS 0x00000003 // flags for multiboot header
#define STACK_SIZE 0x4000                 // size of our stack (16KB)

/*On some systems we have to jump from assembly to C by refering to
  the C name prefixed by an underscore. This is all defined during
  configuration. We do not worry about it here and make sure we can 
  handle either (HAVE_ASM_USCORE is defined by configur).*/
  
#ifdef HAVE_ASM_USCORE
# define EXT_C(sym)
#else
# Define EXT_C(sym)
#endif

/* this text segment will contain code, the data segment
   and bss segment zero-filled static variables */

   
	.txt
	.globl start //start is the global entry point into kernel
start:
	jmp		multiboot_entry
	align 4
multiboot_header:
	.long MULTIBOOT_HEADER_MAGIC
	.long MULTIBOOT_HEADER_FLAGS
	.long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
multiboot_entry:
	movl $(stack + STACK_SIZE), %esp
	call EXT_C(cmain)
loop:	hlt
		jmp 	loop
.section ".bss"
// we define our stack area. the .comm psuedo op declares a common symbol
// if the loader (ld) does not find an existing definition , 
// it will allocate STACK_SIZE bytes of uninitialised memory
	.comm stack, STACK_SIZE
		