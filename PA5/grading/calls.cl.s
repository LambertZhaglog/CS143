# start of generated code
	.data
	.align	2
	.globl	class_nameTab
	.globl	Main_protObj
	.globl	Int_protObj
	.globl	String_protObj
	.globl	bool_const0
	.globl	bool_const1
	.globl	_int_tag
	.globl	_bool_tag
	.globl	_string_tag
_int_tag:
	.word	2
_bool_tag:
	.word	3
_string_tag:
	.word	4
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
	.word	-1
str_const12:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const4
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const7
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const1
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const10
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"./calls.cl"
	.byte	0	
	.align	2
	.word	-1
int_const10:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const9:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const8:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const7:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const6:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const5:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const4:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
int_const3:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const2:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	5
	.word	-1
int_const1:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const0:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
bool_const0:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	1
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
IO_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	-1
Int_protObj:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
Bool_protObj:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	0
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
String_protObj:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const4
	.byte	0
	.align	2
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
	.word	-1
Main_protObj:
	.word	5
	.word	4
	.word	Main_dispTab
	.word	0
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	Main.main
	.word	Main.f
	.word	Main.g
	.word	Main.h
class_nameTab:
	.word	str_const6
	.word	str_const7
	.word	str_const8
	.word	str_const9
	.word	str_const10
	.word	str_const11
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Int_protObj
	.word	Int_init
	.word	Bool_protObj
	.word	Bool_init
	.word	String_protObj
	.word	String_init
	.word	Main_protObj
	.word	Main_init
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
Object_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
IO_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	Object_init
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
Int_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	Object_init
	move	$a0 $zero
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
Bool_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	Object_init
	move	$a0 $zero
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
String_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	Object_init
	move	$a0 $zero
	move	$a0 $zero
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
Main_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	Object_init
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	la	$a0	IO_protObj
	jal	Object.copy
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 12($s0)
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	jr	$ra	
Main.main:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -8
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 4($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 20($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 4($sp)
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	la	$a0 int_const1
	sw	$a0 4($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 24($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 16($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 4($sp)
	lw	$a0 12($s0)
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 16($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	la	$a0 str_const1
	sw	$a0 4($sp)
	lw	$a0 12($s0)
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 12($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	addiu	$sp $sp 0
	jr	$ra	
Main.f:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	lw	$a0 12($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	add	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	addiu	$sp $sp 8
	jr	$ra	
Main.g:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	lw	$a0 12($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	add	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	addiu	$sp $sp 4
	jr	$ra	
Main.h:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	lw	$a0 12($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const3
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	add	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	addiu	$sp $sp 4
	jr	$ra	
case_abort_void:
	li	$a0,1
	la	$a0 str_const0
	jal	_case_abort2
dispatch_abort_void:
	li	$a0,1
	la	$a0 str_const0
	jal	_dispatch_abort
my_equal:
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	beq	$t1,$t2,my_equal_end
	jal	equality_test
my_equal_end:
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	jr	$ra	
# end of generated code
