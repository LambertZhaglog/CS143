
//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully. Make sure to
//    initialize the base class tags in
//       `CgenClassTable::CgenClassTable'
//
//    Add the label for the dispatch tables to
//       `IntEntry::code_def'
//       `StringEntry::code_def'
//       `BoolConst::code_def'
//
//    Add code to emit everyting else that is needed
//       in `CgenClassTable::code'
//
//
// The files as provided will produce code to begin the code
// segments, declare globals, and emit constants.  You must
// fill in the rest.
//
//**************************************************************

#include "cgen.h"
#include "cgen_gc.h"
//self add
#include <cstring>
#include <stdlib.h>
#include <cstdio>

extern void emit_string_constant(ostream& str, char *s);
extern int cgen_debug;

//
// Three symbols from the semantic analyzer (semant.cc) are used.
// If e : No_type, then no code is generated for e.
// Special code is generated for new SELF_TYPE.
// The name "self" also generates code different from other references.
//
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
Symbol 
       arg,
       arg2,
       Bool,
       concat,
       cool_abort,
       copy,
       Int,
       in_int,
       in_string,
       IO,
       length,
       Main,
       main_meth,
       No_class,
       No_type,
       Object,
       out_int,
       out_string,
       prim_slot,
       self,
       SELF_TYPE,
       Str,
       str_field,
       substr,
       type_name,
       val;
//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
  arg         = idtable.add_string("arg");
  arg2        = idtable.add_string("arg2");
  Bool        = idtable.add_string("Bool");
  concat      = idtable.add_string("concat");
  cool_abort  = idtable.add_string("abort");
  copy        = idtable.add_string("copy");
  Int         = idtable.add_string("Int");
  in_int      = idtable.add_string("in_int");
  in_string   = idtable.add_string("in_string");
  IO          = idtable.add_string("IO");
  length      = idtable.add_string("length");
  Main        = idtable.add_string("Main");
  main_meth   = idtable.add_string("main");
//   _no_class is a symbol that can't be the name of any 
//   user-defined class.
  No_class    = idtable.add_string("_no_class");
  No_type     = idtable.add_string("_no_type");
  Object      = idtable.add_string("Object");
  out_int     = idtable.add_string("out_int");
  out_string  = idtable.add_string("out_string");
  prim_slot   = idtable.add_string("_prim_slot");
  self        = idtable.add_string("self");
  SELF_TYPE   = idtable.add_string("SELF_TYPE");
  Str         = idtable.add_string("String");
  str_field   = idtable.add_string("_str_field");
  substr      = idtable.add_string("substr");
  type_name   = idtable.add_string("type_name");
  val         = idtable.add_string("_val");
}

static char *gc_init_names[] =
  { "_NoGC_Init", "_GenGC_Init", "_ScnGC_Init" };
static char *gc_collect_names[] =
  { "_NoGC_Collect", "_GenGC_Collect", "_ScnGC_Collect" };


//  BoolConst is a class that implements code generation for operations
//  on the two booleans, which are given global names here.
BoolConst falsebool(FALSE);
BoolConst truebool(TRUE);

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emmitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************

void program_class::cgen(ostream &os) 
{
  // spim wants comments to start with '#'
  os << "# start of generated code\n";

  initialize_constants();
  CgenClassTable *codegen_classtable = new CgenClassTable(classes,os);

  os << "\n# end of generated code\n";
}


//////////////////////////////////////////////////////////////////////////////
//
//  emit_* procedures
//
//  emit_X  writes code for operation "X" to the output stream.
//  There is an emit_X for each opcode X, as well as emit_ functions
//  for generating names according to the naming conventions (see emit.h)
//  and calls to support functions defined in the trap handler.
//
//  Register names and addresses are passed as strings.  See `emit.h'
//  for symbolic names you can use to refer to the strings.
//
//////////////////////////////////////////////////////////////////////////////

static void emit_load(char *dest_reg, int offset, char *source_reg, ostream& s)
{
  s << LW << dest_reg << " " << offset * WORD_SIZE << "(" << source_reg << ")" 
    << endl;
}

static void emit_store(char *source_reg, int offset, char *dest_reg, ostream& s)
{
  s << SW << source_reg << " " << offset * WORD_SIZE << "(" << dest_reg << ")"
      << endl;
}

static void emit_load_imm(char *dest_reg, int val, ostream& s)
{ s << LI << dest_reg << " " << val << endl; }

static void emit_load_address(char *dest_reg, char *address, ostream& s)
{ s << LA << dest_reg << " " << address << endl; }

static void emit_partial_load_address(char *dest_reg, ostream& s)
{ s << LA << dest_reg << " "; }

static void emit_load_bool(char *dest, const BoolConst& b, ostream& s)
{
  emit_partial_load_address(dest,s);
  b.code_ref(s);
  s << endl;
}

static void emit_load_string(char *dest, StringEntry *str, ostream& s)
{
  emit_partial_load_address(dest,s);
  str->code_ref(s);
  s << endl;
}

static void emit_load_int(char *dest, IntEntry *i, ostream& s)
{
  emit_partial_load_address(dest,s);
  i->code_ref(s);
  s << endl;
}

static void emit_move(char *dest_reg, char *source_reg, ostream& s)
{ s << MOVE << dest_reg << " " << source_reg << endl; }

static void emit_neg(char *dest, char *src1, ostream& s)
{ s << NEG << dest << " " << src1 << endl; }

static void emit_add(char *dest, char *src1, char *src2, ostream& s)
{ s << ADD << dest << " " << src1 << " " << src2 << endl; }

static void emit_addu(char *dest, char *src1, char *src2, ostream& s)
{ s << ADDU << dest << " " << src1 << " " << src2 << endl; }

static void emit_addiu(char *dest, char *src1, int imm, ostream& s)
{ s << ADDIU << dest << " " << src1 << " " << imm << endl; }

static void emit_div(char *dest, char *src1, char *src2, ostream& s)
{ s << DIV << dest << " " << src1 << " " << src2 << endl; }

static void emit_mul(char *dest, char *src1, char *src2, ostream& s)
{ s << MUL << dest << " " << src1 << " " << src2 << endl; }

static void emit_sub(char *dest, char *src1, char *src2, ostream& s)
{ s << SUB << dest << " " << src1 << " " << src2 << endl; }

static void emit_sll(char *dest, char *src1, int num, ostream& s)
{ s << SLL << dest << " " << src1 << " " << num << endl; }

static void emit_jalr(char *dest, ostream& s)
{ s << JALR << "\t" << dest << endl; }

static void emit_jal(char *address,ostream &s)
{ s << JAL << address << endl; }

static void emit_return(ostream& s)
{ s << RET << endl; }

static void emit_gc_assign(ostream& s)
{ s << JAL << "_GenGC_Assign" << endl; }

static void emit_disptable_ref(Symbol sym, ostream& s)
{  s << sym << DISPTAB_SUFFIX; }

static void emit_init_ref(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX; }

static void emit_label_ref(int l, ostream &s)
{ s << "label" << l; }

static void emit_protobj_ref(Symbol sym, ostream& s)
{ s << sym << PROTOBJ_SUFFIX; }

static void emit_method_ref(Symbol classname, Symbol methodname, ostream& s)
{ s << classname << METHOD_SEP << methodname; }

static void emit_label_def(int l, ostream &s)
{
  emit_label_ref(l,s);
  s << ":" << endl;
}

static void emit_beqz(char *source, int label, ostream &s)
{
  s << BEQZ << source << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_beq(char *src1, char *src2, int label, ostream &s)
{
  s << BEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bne(char *src1, char *src2, int label, ostream &s)
{
  s << BNE << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bleq(char *src1, char *src2, int label, ostream &s)
{
  s << BLEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blt(char *src1, char *src2, int label, ostream &s)
{
  s << BLT << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, int label, ostream &s)
{
  s << BLT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bgti(char *src1, int imm, int label, ostream &s)
{
  s << BGT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_branch(int l, ostream& s)
{
  s << BRANCH;
  emit_label_ref(l,s);
  s << endl;
}

//
// Push a register on the stack. The stack grows towards smaller addresses.
//
static void emit_push(char *reg, ostream& str)
{
  emit_store(reg,0,SP,str);
  emit_addiu(SP,SP,-4,str);
}

static void emit_pop(char *reg,ostream& str){
  emit_addiu(SP,SP,4,str);
  emit_load(reg,0,SP,str);
}
//
// Fetch the integer value in an Int object.
// Emits code to fetch the integer value of the Integer object pointed
// to by register source into the register dest
//
static void emit_fetch_int(char *dest, char *source, ostream& s)
{ emit_load(dest, DEFAULT_OBJFIELDS, source, s); }


//
// Emits code to store the integer value contained in register source
// into the Integer object pointed to by dest.
//
static void emit_store_int(char *source, char *dest, ostream& s)
{ emit_store(source, DEFAULT_OBJFIELDS, dest, s); }


static void emit_test_collector(ostream &s)
{
  emit_push(ACC, s);
  emit_move(ACC, SP, s); // stack end
  emit_move(A1, ZERO, s); // allocate nothing
  s << JAL << gc_collect_names[cgen_Memmgr] << endl;
  emit_addiu(SP,SP,4,s);
  emit_load(ACC,0,SP,s);
}

static void emit_gc_check(char *source, ostream &s)
{
  if (source != (char*)A1) emit_move(A1, source, s);
  s << JAL << "_gc_check" << endl;
}


///////////////////////////////////////////////////////////////////////////////
//
// coding strings, ints, and booleans
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type StringEntry.  StringEntry methods are defined both for String
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Strings
//
void StringEntry::code_ref(ostream& s)
{
  s << STRCONST_PREFIX << index;
  /*
   * str_const5:
   */
}

//
// Emit code for a constant String.
// You should fill in the code naming the dispatch table.
//

void StringEntry::code_def(ostream& s, int stringclasstag)
{
  /*
    .word    -1
str_const5
    .word    stringclasstag=3678
    .word    3+1+1+len/4
    .word    String_method
    .word    int_const17
    .ascii   lambert zhaglog
    .byte    0  
    .align   2


   */
  IntEntryP lensym = inttable.add_int(len);

  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s  << LABEL                                             // label
      << WORD << stringclasstag << endl                                 // tag
      << WORD << (DEFAULT_OBJFIELDS + STRING_SLOTS + (len+4)/4) << endl // size
      << WORD;


 /***** Add dispatch information for class String ******/
  s<<"String_dispTab";// self define
      s << endl;                                              // dispatch table
      s << WORD;  lensym->code_ref(s);  s << endl;            // string length
  emit_string_constant(s,str);                                // ascii string
  s << ALIGN;                                                 // align to word
}

//
// StrTable::code_string
// Generate a string object definition for every string constant in the 
// stringtable.
//
void StrTable::code_string_table(ostream& s, int stringclasstag)
{  
  for (List<StringEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,stringclasstag);
}

//
// Ints
//
void IntEntry::code_ref(ostream &s)
{
  s << INTCONST_PREFIX << index;
}

//
// Emit code for a constant Integer.
// You should fill in the code naming the dispatch table.
//

void IntEntry::code_def(ostream &s, int intclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                // label
      << WORD << intclasstag << endl                      // class tag
      << WORD << (DEFAULT_OBJFIELDS + INT_SLOTS) << endl  // object size
      << WORD; 

 /***** Add dispatch information for class Int ******/
  s <<"Int_dispTab";//self define
      s << endl;                                          // dispatch table
      s << WORD << str << endl;                           // integer value
}


//
// IntTable::code_string_table
// Generate an Int object definition for every Int constant in the
// inttable.
//
void IntTable::code_string_table(ostream &s, int intclasstag)
{
  for (List<IntEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,intclasstag);
}


//
// Bools
//
BoolConst::BoolConst(int i) : val(i) { assert(i == 0 || i == 1); }

void BoolConst::code_ref(ostream& s) const
{
  s << BOOLCONST_PREFIX << val;
}
  
//
// Emit code for a constant Bool.
// You should fill in the code naming the dispatch table.
//

void BoolConst::code_def(ostream& s, int boolclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                  // label
      << WORD << boolclasstag << endl                       // class tag
      << WORD << (DEFAULT_OBJFIELDS + BOOL_SLOTS) << endl   // object size
      << WORD;

 /***** Add dispatch information for class Bool ******/
  s<<"Bool_dispTab";//self define
      s << endl;                                            // dispatch table
      s << WORD << val << endl;                             // value (0 or 1)
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//***************************************************
//
//  Emit code to start the .data segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_data()
{
  Symbol main    = idtable.lookup_string(MAINNAME);
  Symbol string  = idtable.lookup_string(STRINGNAME);
  Symbol integer = idtable.lookup_string(INTNAME);
  Symbol boolc   = idtable.lookup_string(BOOLNAME);

  str << "\t.data\n" << ALIGN;
  //
  // The following global names must be defined first.
  //
  str << GLOBAL << CLASSNAMETAB << endl;
  str << GLOBAL; emit_protobj_ref(main,str);    str << endl;
  str << GLOBAL; emit_protobj_ref(integer,str); str << endl;
  str << GLOBAL; emit_protobj_ref(string,str);  str << endl;
  str << GLOBAL; falsebool.code_ref(str);  str << endl;
  str << GLOBAL; truebool.code_ref(str);   str << endl;
  str << GLOBAL << INTTAG << endl;
  str << GLOBAL << BOOLTAG << endl;
  str << GLOBAL << STRINGTAG << endl;

  //
  // We also need to know the tag of the Int, String, and Bool classes
  // during code generation.
  //
  str << INTTAG << LABEL
      << WORD << intclasstag << endl;
  str << BOOLTAG << LABEL 
      << WORD << boolclasstag << endl;
  str << STRINGTAG << LABEL 
      << WORD << stringclasstag << endl;  
  /*
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
	.word	0
_bool_tag:
	.word	0
_string_tag:
	.word	0

   */
  
}


//***************************************************
//
//  Emit code to start the .text segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_text()
{
  str << GLOBAL << HEAP_START << endl
      << HEAP_START << LABEL 
      << WORD << 0 << endl
      << "\t.text" << endl
      << GLOBAL;
  emit_init_ref(idtable.add_string("Main"), str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Int"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("String"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Bool"),str);
  str << endl << GLOBAL;
  emit_method_ref(idtable.add_string("Main"), idtable.add_string("main"), str);
  str << endl;
  /*
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main

   */

}

void CgenClassTable::code_bools(int boolclasstag)
{
  falsebool.code_def(str,boolclasstag);
  truebool.code_def(str,boolclasstag);
}

void CgenClassTable::code_select_gc()
{
  //
  // Generate GC choice constants (pointers to GC functions)
  //
  str << GLOBAL << "_MemMgr_INITIALIZER" << endl;
  str << "_MemMgr_INITIALIZER:" << endl;
  str << WORD << gc_init_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_COLLECTOR" << endl;
  str << "_MemMgr_COLLECTOR:" << endl;
  str << WORD << gc_collect_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_TEST" << endl;
  str << "_MemMgr_TEST:" << endl;
  str << WORD << (cgen_Memmgr_Test == GC_TEST) << endl;
  /*
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

   */
}


//********************************************************
//
// Emit code to reserve space for and initialize all of
// the constants.  Class names should have been added to
// the string table (in the supplied code, is is done
// during the construction of the inheritance graph), and
// code for emitting string constants as a side effect adds
// the string's length to the integer table.  The constants
// are emmitted by running through the stringtable and inttable
// and producing code for each entry.
//
//********************************************************

void CgenClassTable::code_constants()
{
  //
  // Add constants that are required by the code generator.
  //
  stringtable.add_string("");
  inttable.add_string("0");

  stringtable.code_string_table(str,stringclasstag);
  inttable.code_string_table(str,intclasstag);
  code_bools(boolclasstag);
}


CgenClassTable::CgenClassTable(Classes classes, ostream& s) : nds(NULL) , str(s)
{
   enterscope();
   if (cgen_debug) cout << "Building CgenClassTable" << endl;
   install_basic_classes();
   install_classes(classes);
   build_inheritance_tree();
   //self add
   cntClassTag=0;
   branchLabel=0;
   offsetFP=1;
   buildPass();
   stringclasstag = probe(Str)->classTag; /* Change to your String class tag here */
   intclasstag =    probe(Int)->classTag; /* Change to your Int class tag here */
   boolclasstag =   probe(Bool)->classTag; /* Change to your Bool class tag here */

   //original
   code();
   exitscope();
}

void CgenClassTable::install_basic_classes()
{

// The tree package uses these globals to annotate the classes built below.
  //curr_lineno  = 0;
  Symbol filename = stringtable.add_string("<basic class>");

//
// A few special class names are installed in the lookup table but not
// the class list.  Thus, these classes exist, but are not part of the
// inheritance hierarchy.
// No_class serves as the parent of Object and the other special classes.
// SELF_TYPE is the self class; it cannot be redefined or inherited.
// prim_slot is a class known to the code generator.
//
  addid(No_class,
	new CgenNode(class_(No_class,No_class,nil_Features(),filename),
			    Basic,this));
  addid(SELF_TYPE,
	new CgenNode(class_(SELF_TYPE,No_class,nil_Features(),filename),
			    Basic,this));
  addid(prim_slot,
	new CgenNode(class_(prim_slot,No_class,nil_Features(),filename),
			    Basic,this));

// 
// The Object class has no parent class. Its methods are
//        cool_abort() : Object    aborts the program
//        type_name() : Str        returns a string representation of class name
//        copy() : SELF_TYPE       returns a copy of the object
//
// There is no need for method bodies in the basic classes---these
// are already built in to the runtime system.
//
  install_class(
   new CgenNode(
    class_(Object, 
	   No_class,
	   append_Features(
           append_Features(
           single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
           single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
           single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	   filename),
    Basic,this));

// 
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
   install_class(
    new CgenNode(
     class_(IO, 
            Object,
            append_Features(
            append_Features(
            append_Features(
            single_Features(method(out_string, single_Formals(formal(arg, Str)),
                        SELF_TYPE, no_expr())),
            single_Features(method(out_int, single_Formals(formal(arg, Int)),
                        SELF_TYPE, no_expr()))),
            single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
            single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	   filename),	    
    Basic,this));

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer. 
//
   install_class(
    new CgenNode(
     class_(Int, 
	    Object,
            single_Features(attr(val, prim_slot, no_expr())),
	    filename),
     Basic,this));

//
// Bool also has only the "val" slot.
//
    install_class(
     new CgenNode(
      class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename),
      Basic,this));

//
// The class Str has a number of slots and operations:
//       val                                  ???
//       str_field                            the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//       
   install_class(
    new CgenNode(
      class_(Str, 
	     Object,
             append_Features(
             append_Features(
             append_Features(
             append_Features(
             single_Features(attr(val, Int, no_expr())),
            single_Features(attr(str_field, prim_slot, no_expr()))),
            single_Features(method(length, nil_Formals(), Int, no_expr()))),
            single_Features(method(concat, 
				   single_Formals(formal(arg, Str)),
				   Str, 
				   no_expr()))),
	    single_Features(method(substr, 
				   append_Formals(single_Formals(formal(arg, Int)), 
						  single_Formals(formal(arg2, Int))),
				   Str, 
				   no_expr()))),
	     filename),
        Basic,this));

}

// CgenClassTable::install_class
// CgenClassTable::install_classes
//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_class(CgenNodeP nd)
{
  Symbol name = nd->get_name();

  if (probe(name))
    {
      return;
    }

  // The class name is legal, so add it to the list of classes
  // and the symbol table.
  nds = new List<CgenNode>(nd,nds);
  addid(name,nd);
}

void CgenClassTable::install_classes(Classes cs)
{
  for(int i = cs->first(); cs->more(i); i = cs->next(i))
    install_class(new CgenNode(cs->nth(i),NotBasic,this));
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
  for(List<CgenNode> *l = nds; l; l = l->tl())
      set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNodeP nd)
{
  CgenNode *parent_node = probe(nd->get_parent());
  nd->set_parentnd(parent_node);
  parent_node->add_child(nd);
}

void CgenNode::add_child(CgenNodeP n)
{
  children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNodeP p)
{
  assert(parentnd == NULL);
  assert(p != NULL);
  parentnd = p;
}



void CgenClassTable::code()
{
  if (cgen_debug) cout << "coding global data" << endl;
  code_global_data();

  if (cgen_debug) cout << "choosing gc" << endl;
  code_select_gc();

  if (cgen_debug) cout << "coding constants" << endl;
  code_constants();

//                 Add your code to emit
//                   - prototype objects
//                   - class_nameTab
//                   - dispatch tables
//
  generatePrototype();
  generateClassNameTable();

  if (cgen_debug) cout << "coding global text" << endl;
  code_global_text();

//                 Add your code to emit
//                   - object initializer
//                   - the class methods
//                   - etc...
  generateInit();
  generateMethod();


  str<<"case_abort_void"<<LABEL;
  str<<LI<<ACC<<",1"<<endl;
  emit_load_address(ACC,"str_const0",str);
  str<<JAL<<"_case_abort2"<<endl;

  str<<"dispatch_abort_void"<<LABEL;
  str<<LI<<ACC<<",1"<<endl;
  emit_load_address(ACC,"str_const0",str);
  str<<JAL<<"_dispatch_abort"<<endl;

  str<<"my_equal"<<LABEL;
  emit_push(RA,str);
  str<<BEQ<<T1<<","<<T2<<",my_equal_end"<<endl;
  str<<JAL<<"equality_test"<<endl;
  str<<"my_equal_end"<<LABEL;
  emit_pop(RA,str);
  str<<RET;
  //  s<<BNE<<T1<<","<<T2<<",equality_test"<<endl;
  //   s<<JAL<<"equality_test"<<endl;
}


CgenNodeP CgenClassTable::root()
{
   return probe(Object);
}


///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTableP ct) :
   class__class((const class__class &) *nd),
   parentnd(NULL),
   children(NULL),
   basic_status(bstatus)
{ 
   stringtable.add_string(name->get_string());          // Add class name to string table
   classTag=-1;
}


//******************************************************************
//
//   Fill in the following methods to produce code for the
//   appropriate expression.  You may add or remove parameters
//   as you wish, but if you do, remember to change the parameters
//   of the declarations in `cool-tree.h'  Sample code for
//   constant integers, strings, and booleans are provided.
//
//*****************************************************************

void assign_class::code(ostream &s,CgenClassTableP env) {
  expr->code(s,env);
  s<<SW<<ACC<<" "<<env->searchScope(name)->locate<<endl;
}

void static_dispatch_class::code(ostream &s,CgenClassTableP env) {
  emit_push(SELF,s);
  // expr->code(s,env);
  // emit_push(ACC,s);
  emit_addiu(SP,SP,-4*(actual->len()),s);
  for(int i=0;i<actual->len();i++){
    actual->nth(i)->code(s,env);
    // s<<JAL<<"Object.copy"<<endl;
    emit_store(ACC,(i+1),SP,s);
  }
  /*
  Symbol realName=expr->get_type();
  if(realName==SELF_TYPE){
    realName=env->currentNode->name;
  }
  */
  // s<<JAL<<env->probe(realName)->searchAncestor(type_name)->searchMethod(name)->label<<endl;
  // emit_load(SELF,actual->len()+1,SP,s);
  // emit_move(ACC,SELF,s);
  expr->code(s,env);

    s<<BEQZ<<ACC<<",dispatch_abort_void"<<endl;

  emit_move(SELF,ACC,s);
  s<<JAL<<env->probe(type_name)->searchMethod(name)->label<<endl;
  // emit_pop(T1,s);
  emit_pop(SELF,s);
}
void dispatch_class::code(ostream &s,CgenClassTableP env) {
  emit_push(SELF,s);
  // expr->code(s,env);
  // emit_push(ACC,s);
  emit_addiu(SP,SP,-4*(actual->len()),s);
  for(int i=0;i<actual->len();i++){
    actual->nth(i)->code(s,env);
    // s<<JAL<<"Object.copy"<<endl;//should not copy the parameter?
    emit_store(ACC,(i+1),SP,s);
  }
  Symbol realName=expr->get_type();
   if(realName==SELF_TYPE){
     realName=env->currentNode->name;
   }
  // s<<JAL<<env->probe(realName)->searchMethod(name)->label<<endl;
   // emit_load(SELF,actual->len()+1,SP,s);
  // emit_move(ACC,SELF,s);//for string case
   expr->code(s,env);

    s<<BEQZ<<ACC<<",dispatch_abort_void"<<endl;

   emit_move(SELF,ACC,s);
  int offset=env->probe(realName)->searchMethod(name)->offset;
  emit_load(T3,2,SELF,s);
  emit_load(T3,offset,T3,s);
  emit_jalr(T3,s);
  // emit_pop(T1,s);
  emit_pop(SELF,s);
}

void cond_class::code(ostream &s,CgenClassTableP env) {
  pred->code(s,env);
  emit_load(T1,3,ACC,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BNE<<T1<<","<<ZERO<<","<<"true_branch"<<cntLabel<<endl;
  s<<"false_branch"<<cntLabel<<LABEL;
  else_exp->code(s,env);
  s<<BRANCH<<"end_if"<<cntLabel<<endl;
  s<<"true_branch"<<cntLabel<<LABEL;
  then_exp->code(s,env);
  s<<"end_if"<<cntLabel<<LABEL;
}

void loop_class::code(ostream &s,CgenClassTableP env) {
  pred->code(s,env);
  emit_load(T1,3,ACC,s);
  emit_move(ACC,ZERO,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BEQ<<T1<<","<<ZERO<<","<<"end_loop"<<cntLabel<<endl;
  body->code(s,env);
  s<<"end_loop"<<cntLabel<<LABEL;
}

void typcase_class::code(ostream &s,CgenClassTableP env) {
  Symbol realType=expr->get_type();
  if(realType==SELF_TYPE){
    realType=env->currentNode->name;
  }
  int record=-1;
  CgenNodeP child=env->probe(realType);
  CgenNodeP father;
  CgenNodeP tmp;
  for(int i=0;i<cases->len();i++){
    tmp=env->probe(cases->nth(i)->get_type_decl());
    if(isAncestor(child,tmp)){
      if(record==-1){
	record=i;
	father=tmp;
      }else if(isAncestor(tmp,father)){
	record=i;
	father=tmp;
      }
    }
  }
  expr->code(s,env);
  emit_push(ACC,s);
  // emit_beqz(ACC,"case_abort_void",s);
    s<<BEQZ<<ACC<<",case_abort_void"<<endl;
  if(record==-1){
    //error report
    s<<JAL<<"_case_abort"<<endl;
  }else{
    char *buffer=new char[100];
    sprintf(buffer,"%d($fp)",-env->offsetFP*4);
    env->offsetFP=env->offsetFP+1;
    attributeNode *tmp=new attributeNode;
    tmp->name=cases->nth(record)->get_name();
    tmp->locate=buffer;
    tmp->type_decl=cases->nth(record)->get_type_decl();
    env->scope=new List<attributeNode>(tmp,env->scope);
    cases->nth(record)->get_expr()->code(s,env);
    env->scope=env->scope->tl();
    env->offsetFP=env->offsetFP-1;
    emit_addiu(SP,SP,4,s);
  }
}
Symbol branch_class::get_name(){
  return name;
}
Symbol branch_class::get_type_decl(){
  return type_decl;
}
Expression branch_class::get_expr(){
  return expr;
}
bool isAncestor(CgenNodeP child,CgenNodeP father){
  for(CgenNodeP tmp=child;tmp->name!=No_class;tmp=tmp->get_parentnd()){
    if(tmp->name==father->name){
      return true;
    }
  }
  return false;
}

void block_class::code(ostream &s,CgenClassTableP env) {
  for(int i=0;i<body->len();i++){
    body->nth(i)->code(s,env);
  }
}

void let_class::code(ostream &s,CgenClassTableP env) {
   env->voidtag=false;
  init->code(s,env);
  if(env->voidtag==true&&(type_decl==Str||type_decl==Bool||type_decl==Int)){
    s<<LA<<ACC<<" "<<type_decl->get_string()<<"_protObj"<<endl;
    s<<JAL<<"Object.copy"<<endl;
  }
  emit_push(ACC,s);
  char *buffer=new char[100];
  sprintf(buffer,"%d($fp)",-env->offsetFP*4);
  env->offsetFP=env->offsetFP+1;
  attributeNode *tmp=new attributeNode;
  tmp->name=identifier;
  tmp->locate=buffer;
  tmp->type_decl=type_decl;
  env->scope=new List<attributeNode>(tmp,env->scope);
  body->code(s,env);
  env->scope=env->scope->tl();
  env->offsetFP=env->offsetFP-1;
  emit_addiu(SP,SP,4,s);
}

void plus_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T1,s);
  emit_add(ACC,T1,ACC,s);
  emit_push(ACC,s);
  s<<LA<<ACC<<"\t"<<"Int_protObj"<<endl;
  s<<JAL<<"Object.copy"<<endl;
  emit_pop(T1,s);
  emit_store(T1,3,ACC,s);
}

void sub_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T1,s);
  emit_sub(ACC,T1,ACC,s);
  emit_push(ACC,s);
  s<<LA<<ACC<<"\t"<<"Int_protObj"<<endl;
  s<<JAL<<"Object.copy"<<endl;
  emit_pop(T1,s);
  emit_store(T1,3,ACC,s);
}

void mul_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T1,s);
  emit_mul(ACC,T1,ACC,s);
  emit_push(ACC,s);
  s<<LA<<ACC<<"\t"<<"Int_protObj"<<endl;
  s<<JAL<<"Object.copy"<<endl;
  emit_pop(T1,s);
  emit_store(T1,3,ACC,s);
}

void divide_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T1,s);
  emit_div(ACC,T1,ACC,s);
  emit_push(ACC,s);
  s<<LA<<ACC<<"\t"<<"Int_protObj"<<endl;
  s<<JAL<<"Object.copy"<<endl;
  emit_pop(T1,s);
  emit_store(T1,3,ACC,s);
}

void neg_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_neg(ACC,ACC,s);
  emit_push(ACC,s);
  s<<LA<<ACC<<"\t"<<"Int_protObj"<<endl;
  s<<JAL<<"Object.copy"<<endl;
  emit_pop(T1,s);
  emit_store(T1,3,ACC,s);
}

void lt_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T3,s);
  emit_load_bool(T1,truebool,s);
  emit_load_bool(T2,falsebool,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BLT<<T3<<","<<ACC<<","<<"lt_true"<<cntLabel<<endl;
  emit_move(ACC,T2,s);
  s<<BRANCH<<"end_lt"<<cntLabel<<endl;
  s<<"lt_true"<<cntLabel<<LABEL;
  emit_move(ACC,T1,s);
  s<<"end_lt"<<cntLabel<<LABEL;
}

void eq_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_push(ACC,s);
  emit_load_bool(ACC,truebool,s);
  emit_load_bool(A1,falsebool,s);
  emit_pop(T1,s);
  emit_pop(T2,s);
  //  s<<BNE<<T1<<","<<T2<<",equality_test"<<endl;
  //   s<<JAL<<"equality_test"<<endl;
  s<<JAL<<"my_equal"<<endl;
}

void leq_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_push(ACC,s);
  e2->code(s,env);
  emit_load(ACC,3,ACC,s);
  emit_pop(T3,s);
  emit_load_bool(T1,truebool,s);
  emit_load_bool(T2,falsebool,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BLEQ<<T3<<","<<ACC<<","<<"leq_true"<<cntLabel<<endl;
  emit_move(ACC,T2,s);
  s<<BRANCH<<"end_leq"<<cntLabel<<endl;
  s<<"leq_true"<<cntLabel<<LABEL;
  emit_move(ACC,T1,s);
  s<<"end_leq"<<cntLabel<<LABEL;
}

void comp_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  s<<JAL<<"Object.copy"<<endl;
  emit_load(T1,3,ACC,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BNE<<T1<<","<<ZERO<<","<<"true_branch"<<cntLabel<<endl;
  emit_move(T1,ZERO,s);
  emit_addiu(T1,T1,1,s);
  emit_store(T1,3,ACC,s);
  s<<BRANCH<<"end_if"<<cntLabel<<endl;
  s<<"true_branch"<<cntLabel<<LABEL;
  emit_store(ZERO,3,ACC,s);
  s<<"end_if"<<cntLabel<<LABEL;
}

void int_const_class::code(ostream& s,CgenClassTableP env)  
{
  //
  // Need to be sure we have an IntEntry *, not an arbitrary Symbol
  //
  //assignment complete
  emit_load_int(ACC,inttable.lookup_string(token->get_string()),s);
}

void string_const_class::code(ostream& s,CgenClassTableP env)
{//assignment complete
  emit_load_string(ACC,stringtable.lookup_string(token->get_string()),s);
}

void bool_const_class::code(ostream& s,CgenClassTableP env)
{//assignment complete
  emit_load_bool(ACC, BoolConst(val), s);
}

void new__class::code(ostream &s,CgenClassTableP env) {
  Symbol realName=type_name;
  if(type_name==SELF_TYPE){
    /*
     emit_move(ACC,SELF,s);
     s<<JAL<<"Object.copy"<<endl;
    */
    /*
	move	$s0 $a0
	la	$t1 class_objTab
	lw	$t2 0($s0)
	sll	$t2 $t2 3
	addu	$t1 $t1 $t2
	move	$s1 $t1
	lw	$a0 0($t1)
	jal	Object.copy
	lw	$t1 4($s1)
	jalr		$t1
    */
    emit_push(SELF,s);
    s<<LA<<T1<<" class_objTab"<<endl;
    emit_load(T2,0,SELF,s);
    emit_sll(T2,T2,3,s);
    emit_addu(T1,T1,T2,s);
    emit_move("$s1",T1,s);
    emit_load(ACC,0,T1,s);
    s<<JAL<<"Object.copy"<<endl;
    emit_move(SELF,ACC,s);
    emit_load(T1,1,"$s1",s);
    s<<JALR<<T1<<endl;
    emit_move(ACC,SELF,s);
    emit_pop(SELF,s);
    /*
    //down according from the standard cool compiler
    s<<LA<<T1<<" class_objTab"<<endl;
    emit_load(T2,0,SELF,s);
    emit_sll(T2,T2,3,s);
    emit_addu(T1,T1,T2,s);
    emit_move("$s1",T1,s);
    emit_load(ACC,0,T1,s);
    s<<JAL<<"Object.copy"<<endl;
    emit_load(T1,1,"$s1",s);
    s<<JALR<<T1<<endl;
    //up according to the standard cool compiler
    */
    
  }else{
    emit_push(SELF,s);
    s<<LA<<ACC<<"\t"<<realName->get_string()<<"_protObj"<<endl;
    s<<JAL<<"Object.copy"<<endl;
    if(realName!=Str&&realName!=Bool&&realName!=Int){
    emit_move(SELF,ACC,s);//because in class_Init method, the self as input parameter
    s<<JAL<<realName->get_string()<<"_init"<<endl;//in class_Init method,the self is also the output parameter
    emit_move(ACC,SELF,s);//because we see every method include class_Init, the a0 is the output parameter. 
    }
    emit_pop(SELF,s);
  }
}

void isvoid_class::code(ostream &s,CgenClassTableP env) {
  e1->code(s,env);
  emit_load_bool(T1,truebool,s);
  emit_load_bool(T2,falsebool,s);
  int cntLabel=env->branchLabel;
  env->branchLabel=env->branchLabel+1;
  s<<BEQ<<ACC<<" "<<ZERO<<" "<<"isvoid_true"<<cntLabel<<endl;
  emit_move(ACC,T2,s);
  s<<BRANCH<<"end_isvoid"<<cntLabel<<endl;
  s<<"isvoid_true"<<cntLabel<<LABEL;
  emit_move(ACC,T1,s);
  s<<"end_isvoid"<<cntLabel<<LABEL;
}

void no_expr_class::code(ostream &s,CgenClassTableP env) {
  env->voidtag=true;
  s<<MOVE<<ACC<<" "<<ZERO<<endl;
}

void object_class::code(ostream &s,CgenClassTableP env) {
  if(name==self){
    s<<MOVE<<ACC<<" "<<SELF<<endl;
  }else{
    s<<LW<<ACC<<" "<<env->searchScope(name)->locate<<endl;
  }
}
void CgenClassTable::buildPass(){
  root()->attribute=NULL;
  root()->classTag=cntClassTag;
  cntClassTag=cntClassTag+1;
  methodNode *tmp=new methodNode;
  tmp->name=cool_abort;
  tmp->label="Object.abort";
  tmp->offset=0;
  tmp->overrider=false;
  root()->method=new List<methodNode>(tmp);
  tmp=new methodNode;
  tmp->name=type_name;
  tmp->label="Object.type_name";
  tmp->offset=1;
  tmp->overrider=false;
  root()->method=new List<methodNode>(tmp,root()->method);
  tmp=new methodNode;
  tmp->name=copy;
  tmp->label="Object.copy";
  tmp->offset=2;
  tmp->overrider=false;
  root()->method=new List<methodNode>(tmp,root()->method);
  root()-> cntAttribute=0;
  root()->cntMethod=3;
  for(List<CgenNode> *tt=root()->get_children();tt!=NULL;tt=tt->tl()){
    currentNode=tt->hd();
    tt->hd()->buildPass(this);
  }
}

void CgenNode::buildPass(CgenClassTableP env){
  /*
  if(name==Str){
    classTag=0;
  }else if(name==Int){
    classTag=1;
  }else if(name==Bool){
    classTag=2;
  }else{
  */
  classTag=env->cntClassTag;
  env->cntClassTag=env->cntClassTag+1;
    // }
  cntAttribute=get_parentnd()->cntAttribute;
  cntMethod=get_parentnd()->cntMethod;
  attribute=get_parentnd()->attribute;
  method=get_parentnd()->method;
  for(int i=0;i<features->len();i++){
    features->nth(i)->buildPass(env);
  }
  for(List<CgenNode> *tt=get_children();tt!=NULL;tt=tt->tl()){
    env->currentNode=tt->hd();
    tt->hd()->buildPass(env);
  }
}
void attr_class::buildPass(CgenClassTableP env){
  attributeNode* tmp=new attributeNode;
  tmp->name=name;
  tmp->type_decl=type_decl;
  int offset=(env->currentNode->cntAttribute+3)*4;
  // atoi("30");
  char* locate=new char[100];
  sprintf(locate,"%d($s0)",offset);
  //strcat(locate,"($s0)");
  tmp->locate=locate;
  env->currentNode->cntAttribute=env->currentNode->cntAttribute+1;
  env->currentNode->attribute=new List<attributeNode>(tmp,env->currentNode->attribute);
}
void method_class::buildPass(CgenClassTableP env){
  methodNode* tmp=new methodNode;
  tmp->name=name;
  char* label=new char[100];
  sprintf(label,"%s.%s",env->currentNode->name->get_string(),name->get_string());
  tmp->label=label;
  tmp->overrider=false;
  methodNode* oldOne=env->currentNode->searchMethod(name);
  if(oldOne!=NULL){
    tmp->overrider=true;
    tmp->offset=oldOne->offset;
  }else{
    tmp->offset=env->currentNode->cntMethod;
    env->currentNode->cntMethod=env->currentNode->cntMethod+1;
  }
  env->currentNode->method=new List<methodNode>(tmp,env->currentNode->method);
}

void CgenClassTable::generatePrototype(){
  root()->generatePrototype(str,this);
}

void CgenNode::generatePrototype(ostream& s,CgenClassTableP env){
  env->currentNode=this;
  s<<WORD<<"-1"<<endl;
  s<<name->get_string()<<"_protObj"<<LABEL
   <<WORD<<classTag<<endl
   <<WORD<<(DEFAULT_OBJFIELDS+list_length(attribute))<<endl
   <<WORD<<name->get_string()<<"_dispTab"<<endl;
  if(name!=Str){
    /*
    for(int i=0;i<list_length(attribute);i++){
      //should modify the code to add type_decl,for Bool,Int,Str default Init method
      // should think about the the attribute list's feature order, is reverse?
      //should change the generateInit
      //maybe the object_proto will be changed at run time 
      s<<WORD<<0<<endl;
    }
*/
    for(int i=list_length(attribute);i>0;i--){
      List<attributeNode> *tmp=attribute;
      for(int j=i-1;j>0;j--){
	tmp=tmp->tl();
      }
      attributeNode* tt=tmp->hd();
      if(tt->type_decl==Str||tt->type_decl==Bool||tt->type_decl==Int){
	s<<WORD<<tt->type_decl->get_string()<<"_protObj"<<endl;
      }else{
	s<<WORD<<0<<endl;
      }
    }
  }else{
    s<<WORD;
    inttable.add_int(0)->code_ref(s);
    s<<endl;
    s<<"\t.byte\t0"<<endl;
    s<<ALIGN;
  }
  methodNode * a[cntMethod];
  for(int i=0;i<cntMethod;i++){
    a[i]=NULL;
  }
  for(List<methodNode> *i=method;i!=NULL;i=i->tl()){
    methodNode* tt=i->hd();
    if(a[tt->offset]==NULL){
      a[tt->offset]=tt;
    }
  }
  s<<name->get_string()<<"_dispTab"<<LABEL;
  for(int i=0;i<cntMethod;i++){
    s<<WORD<<a[i]->label<<endl;
  }
  for(List<CgenNode> *tmp=get_children();tmp!=NULL;tmp=tmp->tl()){
    tmp->hd()->generatePrototype(s,env);
  }
}
void CgenClassTable::generateInit(){
  root()->generateInit(str,this);
}

void CgenNode::generateInit(ostream& s,CgenClassTableP env){
  env->currentNode=this;
  env->scope=this->attribute;//for the case of use one attribute to init another
  s<<name->get_string()<<"_init"<<LABEL;
  emit_push(FP,s);
  emit_push(SELF,s);
  emit_push(RA,s);
  emit_addiu(FP,SP,4,s);
  if(name!=Object){
    s<<JAL<<get_parentnd()->name->get_string()<<"_init"<<endl;
  }
 for(int i=0;i<features->len();i++){
    features->nth(i)->generateInit(s,env);
  }
  emit_pop(RA,s);
  emit_pop(SELF,s);
  emit_pop(FP,s);
  emit_return(s);
  for(List<CgenNode> *tmp=get_children();tmp!=NULL;tmp=tmp->tl()){
    tmp->hd()->generateInit(s,env);
  }
}
void attr_class::generateInit(ostream& s,CgenClassTableP env){
  //no expression case
  //the no expression return 0 at $a0
  env->voidtag=false;
  init->code(s,env);
  /*
  if(env->voidtag==true&&(type_decl==Str||type_decl==Bool||type_decl==Int)){
    s<<LA<<ACC<<" "<<type_decl->get_string()<<"_protObj"<<endl;
    s<<JAL<<"Object.copy"<<endl;
  }
  s<<SW<<ACC<<" "<<env->currentNode->getAttribute(name)->locate<<endl;
  */
  if(env->voidtag==false){
    s<<SW<<ACC<<" "<<env->currentNode->getAttribute(name)->locate<<endl;
  }
}

void method_class::generateInit(ostream& s,CgenClassTableP env){
  return;
}
attributeNode* CgenNode::getAttribute(Symbol name){
  for(List<attributeNode>* tmp=attribute;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==name){
      return tmp->hd();
    }
  }
  return NULL;
}

/*
  void CgenNode::generateClassName(ostream& s){
  s<<name->get_string()<<"_ClassName"<<LABEL;
  emit_string_constant(s,name->get_string());           
  s << ALIGN;
  for(List<CgenNode> *tmp=get_children();tmp!=NULL;tmp=tmp->tl()){
    tmp->hd()->generateClassName(s);
  }                       
  }
*/
void CgenClassTable::generateClassNameTable(){
  //str<<ALIGN;
  //root()->generateClassName(str);
  str<<"class_nameTab"<<LABEL;
  int length=list_length(nds);
  for(int i=0;i<length;i++){
    CgenNodeP tmp=searchTag(i);
    if(tmp==NULL){
      str<<"error"<<endl;
    }else{
      //str<<WORD<<tmp->name->get_string()<<"_ClassName"<<endl;
      str<<WORD;
      stringtable.lookup_string(tmp->name->get_string())->code_ref(str);
      str<<endl;
    }
  }
  str<<"class_objTab"<<LABEL;
  for(int i=0;i<length;i++){
    CgenNodeP tmp=searchTag(i);
    if(tmp==NULL){
      str<<"error"<<endl;
    }else{
      str<<WORD<<tmp->name->get_string()<<"_protObj"<<endl;
      str<<WORD<<tmp->name->get_string()<<"_init"<<endl;
    }
  }
}
CgenNodeP CgenClassTable::searchTag(int i){
  List<CgenNode> *tmp=nds;
  while(tmp!=NULL){
    if(tmp->hd()->classTag==i){
      return tmp->hd();
    }
    tmp=tmp->tl();
  }
  return NULL;
}
void CgenClassTable::generateMethod(){
  root()->generateMethod(str,this);
}
void CgenNode::generateMethod(ostream& s,CgenClassTableP env){
  if(basic()==0){
    env->currentNode=this;
    for(int i=0;i<features->len();i++){
      features->nth(i)->generateMethod(s,env);
    }
  }
  for(List<CgenNode> *tmp=get_children();tmp!=NULL;tmp=tmp->tl()){
    tmp->hd()->generateMethod(s,env);
  }  
}
void attr_class::generateMethod(ostream& s,CgenClassTableP env){
  return;
}

Symbol formal_class::getName(){
  return name;
}
void method_class::generateMethod(ostream& s,CgenClassTableP env){
  env->scope=env->currentNode->attribute;
  attributeNode *tmp;
  //prone error
  //the first formal in the first place of formals_class or last place
  for(int i=0;i<formals->len();i++){
    char *str=new char[100];
    sprintf(str,"%d($fp)",4*(i+3));
    tmp=new attributeNode;
    tmp->name=formals->nth(i)->getName();
    tmp->locate=str;
    env->scope=new List<attributeNode>(tmp,env->scope);
  }
  // s<<GLOBL<<env->currentNode->name->get_string()<<"."<<name->get_string()<<endl;
  s<<env->currentNode->name->get_string()<<"."<<name->get_string()<<LABEL;
  emit_push(FP,s);
  emit_push(SELF,s);
  emit_push(RA,s);
  emit_addiu(FP,SP,4,s);
  expr->code(s,env);
  emit_pop(RA,s);
  emit_pop(SELF,s);
  emit_pop(FP,s);
  emit_addiu(SP,SP,4*formals->len(),s);
  emit_return(s);
  /*
  emit_move(FP,SP,s);
  emit_push(RA,s);
  expr->code(s,env);
  emit_load(RA,1,SP,s);
  emit_addiu(SP,SP,4*formals->len()+8,s);
  emit_load(FP,0,SP,s);
  emit_return(s);
  */
}

attributeNode *CgenClassTable::searchScope(Symbol name){
  for(List<attributeNode> *tmp=scope;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==name){
      return tmp->hd();
    }
  }
  return NULL;
}

methodNode *CgenNode::searchMethod(Symbol name){
  for(List<methodNode> *tmp=method;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==name){
      return tmp->hd();
    }
  }
  return NULL;
}

CgenNode *CgenNode::searchAncestor(Symbol name){
  if(name==SELF_TYPE){
    return this;
  }
  for(CgenNode *tmp=this;tmp->name!=No_class;tmp=tmp->get_parentnd()){
    if(tmp->name==name){
      return this;
    }
  }
  return NULL;
}
