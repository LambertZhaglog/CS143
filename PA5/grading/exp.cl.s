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
	.word	3
_bool_tag:
	.word	4
_string_tag:
	.word	5
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
	.word	5
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	5
	.word	6
	.word	String_dispTab
	.word	int_const7
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	5
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	5
	.word	6
	.word	String_dispTab
	.word	int_const7
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	5
	.word	5
	.word	String_dispTab
	.word	int_const4
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	5
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	5
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	5
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	5
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	5
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	5
	.word	8
	.word	String_dispTab
	.word	int_const10
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	5
	.word	5
	.word	String_dispTab
	.word	int_const1
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	5
	.word	7
	.word	String_dispTab
	.word	int_const6
	.ascii	"./exp.cl"
	.byte	0	
	.align	2
	.word	-1
int_const10:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const9:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const8:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const7:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const6:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const5:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const4:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const3:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const2:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const1:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const0:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
bool_const0:
	.word	4
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	4
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
Main_protObj:
	.word	2
	.word	3
	.word	Main_dispTab
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Main.exp
	.word	Main.main
	.word	-1
Int_protObj:
	.word	3
	.word	4
	.word	Int_dispTab
	.word	0
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
Bool_protObj:
	.word	4
	.word	4
	.word	Bool_dispTab
	.word	0
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	-1
String_protObj:
	.word	5
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0
	.align	2
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
class_nameTab:
	.word	str_const6
	.word	str_const7
	.word	str_const11
	.word	str_const8
	.word	str_const9
	.word	str_const10
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Main_protObj
	.word	Main_init
	.word	Int_protObj
	.word	Int_init
	.word	Bool_protObj
	.word	Bool_init
	.word	String_protObj
	.word	String_init
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
Main_init:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	jal	IO_init
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
Main.exp:
	sw	$fp 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	sw	$ra 0($sp)
	addiu	$sp $sp -4
	addiu	$fp $sp 4
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch0
false_branch0:
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	div	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	mul	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch1
false_branch1:
	lw	$a0 12($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -8
	lw	$a0 12($fp)
	sw	$a0 4($sp)
	lw	$a0 16($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sub	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 28($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	mul	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	b	end_if1
true_branch1:
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -8
	lw	$a0 12($fp)
	sw	$a0 4($sp)
	lw	$a0 16($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	div	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 28($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -4($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -4($fp)
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	mul	$a0 $t1 $a0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0	Int_protObj
	jal	Object.copy
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 4
end_if1:
	b	end_if0
true_branch0:
	la	$a0 int_const1
end_if0:
	addiu	$sp $sp 4
	lw	$ra 0($sp)
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	addiu	$sp $sp 4
	lw	$fp 0($sp)
	addiu	$sp $sp 8
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
	la	$a0 int_const2
	sw	$a0 4($sp)
	la	$a0 int_const3
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 28($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 4($sp)
	move	$a0 $s0
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
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 12($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -8
	la	$a0 int_const4
	sw	$a0 4($sp)
	la	$a0 int_const5
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 28($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 4($sp)
	move	$a0 $s0
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
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 12($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -4
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp -8
	la	$a0 int_const6
	sw	$a0 4($sp)
	la	$a0 int_const4
	sw	$a0 8($sp)
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 28($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
	sw	$a0 4($sp)
	move	$a0 $s0
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
	move	$a0 $s0
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
