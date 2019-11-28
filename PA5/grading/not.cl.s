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
str_const11:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const5
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const6
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const9
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const10
	.ascii	"./not.cl"
	.byte	0	
	.align	2
	.word	-1
int_const10:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const9:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const8:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const7:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const6:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const5:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const4:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const3:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const2:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const1:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	100
	.word	-1
int_const0:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
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
	.word	-1
Main_protObj:
	.word	5
	.word	3
	.word	Main_dispTab
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	Main.main
class_nameTab:
	.word	str_const5
	.word	str_const6
	.word	str_const7
	.word	str_const8
	.word	str_const9
	.word	str_const10
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
	la	$a0 int_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $zero
	la	$a0 Bool_protObj
	jal	Object.copy
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -4($fp)
	lw	$a0 12($a0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	lw	$a0 12($a0)
	addiu	$sp $sp 4
	lw	$t3 0($sp)
	la	$t1 bool_const1
	la	$t2 bool_const0
	blt	$t3,$a0,lt_true0
	move	$a0 $t2
	b	end_lt0
lt_true0:
	move	$a0 $t1
end_lt0:
	lw	$t1 12($a0)
	move	$a0 $zero
	beq	$t1,$zero,end_loop1
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch2
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if2
true_branch2:
	sw	$zero 12($a0)
end_if2:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch3
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if3
true_branch3:
	sw	$zero 12($a0)
end_if3:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch4
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if4
true_branch4:
	sw	$zero 12($a0)
end_if4:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch5
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if5
true_branch5:
	sw	$zero 12($a0)
end_if5:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch6
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if6
true_branch6:
	sw	$zero 12($a0)
end_if6:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch7
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if7
true_branch7:
	sw	$zero 12($a0)
end_if7:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch8
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if8
true_branch8:
	sw	$zero 12($a0)
end_if8:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch9
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if9
true_branch9:
	sw	$zero 12($a0)
end_if9:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch10
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if10
true_branch10:
	sw	$zero 12($a0)
end_if10:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch11
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if11
true_branch11:
	sw	$zero 12($a0)
end_if11:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch12
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if12
true_branch12:
	sw	$zero 12($a0)
end_if12:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch13
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if13
true_branch13:
	sw	$zero 12($a0)
end_if13:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch14
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if14
true_branch14:
	sw	$zero 12($a0)
end_if14:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch15
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if15
true_branch15:
	sw	$zero 12($a0)
end_if15:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch16
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if16
true_branch16:
	sw	$zero 12($a0)
end_if16:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch17
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if17
true_branch17:
	sw	$zero 12($a0)
end_if17:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch18
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if18
true_branch18:
	sw	$zero 12($a0)
end_if18:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch19
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if19
true_branch19:
	sw	$zero 12($a0)
end_if19:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch20
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if20
true_branch20:
	sw	$zero 12($a0)
end_if20:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch21
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if21
true_branch21:
	sw	$zero 12($a0)
end_if21:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch22
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if22
true_branch22:
	sw	$zero 12($a0)
end_if22:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch23
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if23
true_branch23:
	sw	$zero 12($a0)
end_if23:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch24
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if24
true_branch24:
	sw	$zero 12($a0)
end_if24:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch25
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if25
true_branch25:
	sw	$zero 12($a0)
end_if25:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch26
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if26
true_branch26:
	sw	$zero 12($a0)
end_if26:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch27
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if27
true_branch27:
	sw	$zero 12($a0)
end_if27:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch28
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if28
true_branch28:
	sw	$zero 12($a0)
end_if28:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch29
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if29
true_branch29:
	sw	$zero 12($a0)
end_if29:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch30
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if30
true_branch30:
	sw	$zero 12($a0)
end_if30:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch31
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if31
true_branch31:
	sw	$zero 12($a0)
end_if31:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch32
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if32
true_branch32:
	sw	$zero 12($a0)
end_if32:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch33
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if33
true_branch33:
	sw	$zero 12($a0)
end_if33:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch34
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if34
true_branch34:
	sw	$zero 12($a0)
end_if34:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch35
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if35
true_branch35:
	sw	$zero 12($a0)
end_if35:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch36
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if36
true_branch36:
	sw	$zero 12($a0)
end_if36:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch37
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if37
true_branch37:
	sw	$zero 12($a0)
end_if37:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch38
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if38
true_branch38:
	sw	$zero 12($a0)
end_if38:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch39
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if39
true_branch39:
	sw	$zero 12($a0)
end_if39:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch40
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if40
true_branch40:
	sw	$zero 12($a0)
end_if40:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch41
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if41
true_branch41:
	sw	$zero 12($a0)
end_if41:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch42
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if42
true_branch42:
	sw	$zero 12($a0)
end_if42:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch43
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if43
true_branch43:
	sw	$zero 12($a0)
end_if43:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch44
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if44
true_branch44:
	sw	$zero 12($a0)
end_if44:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch45
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if45
true_branch45:
	sw	$zero 12($a0)
end_if45:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch46
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if46
true_branch46:
	sw	$zero 12($a0)
end_if46:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch47
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if47
true_branch47:
	sw	$zero 12($a0)
end_if47:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch48
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if48
true_branch48:
	sw	$zero 12($a0)
end_if48:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch49
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if49
true_branch49:
	sw	$zero 12($a0)
end_if49:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch50
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if50
true_branch50:
	sw	$zero 12($a0)
end_if50:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch51
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if51
true_branch51:
	sw	$zero 12($a0)
end_if51:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch52
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if52
true_branch52:
	sw	$zero 12($a0)
end_if52:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch53
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if53
true_branch53:
	sw	$zero 12($a0)
end_if53:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch54
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if54
true_branch54:
	sw	$zero 12($a0)
end_if54:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch55
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if55
true_branch55:
	sw	$zero 12($a0)
end_if55:
	jal	Object.copy
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch56
	move	$t1 $zero
	addiu	$t1 $t1 1
	sw	$t1 12($a0)
	b	end_if56
true_branch56:
	sw	$zero 12($a0)
end_if56:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 bool_const1
	la	$a1 bool_const0
	addiu	$sp $sp 4
	lw	$t1 0($sp)
	addiu	$sp $sp 4
	lw	$t2 0($sp)
	jal	my_equal
	lw	$a0 -4($fp)
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
	sw	$a0 -4($fp)
end_loop1:
	lw	$a0 -8($fp)
	lw	$t1 12($a0)
	bne	$t1,$zero,true_branch57
false_branch57:
	la	$a0 int_const0
	b	end_if57
true_branch57:
	sw	$s0 0($sp)
	addiu	$sp $sp -4
	addiu	$sp $sp 0
	move	$a0 $s0
	beqz	$a0,dispatch_abort_void
	move	$s0 $a0
	lw	$t3 8($s0)
	lw	$t3 0($t3)
	jalr		$t3
	addiu	$sp $sp 4
	lw	$s0 0($sp)
end_if57:
	addiu	$sp $sp 4
	addiu	$sp $sp 4
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
