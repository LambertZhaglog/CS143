#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"


extern int semant_debug;
extern char *curr_filename;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
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



ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {

    /* Fill this in */


  buffer=NULL;

  myscope = new SymbolTable<Symbol,Entry>();
  myscope->enterscope();
  myscope->addid(self,SELF_TYPE);
  currentNode=NULL;
  install_basic_classes();
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
   // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
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
	       filename);  

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
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
	       filename);
    mytree=new inheritTreeNode;

    mytree->name=Object;

    mytree->attr=NULL;

    mytree->child=NULL;

    mytree->parent=NULL;

    methodType *tmp=new methodType;
    tmp->name=cool_abort;
    tmp->argType=NULL;
    tmp->returnType=Object;
    mytree->method=new List<methodType>(tmp);

    tmp=new methodType;
    tmp->name=type_name;
    tmp->argType=NULL;
    tmp->returnType=Str;
    mytree->method=new List<methodType>(tmp,mytree->method);

    tmp=new methodType;
    tmp->name=copy;
    tmp->argType=NULL;
    tmp->returnType=SELF_TYPE;
    mytree->method=new List<methodType>(tmp,mytree->method);

    IO_class->inheritInit(this);
    Int_class->inheritInit(this);
    Bool_class->inheritInit(this);
    Str_class->inheritInit(this);

}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 



/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();

    /* ClassTable constructor may do some semantic analysis */
    ClassTable *classtable = new ClassTable(classes);
    inheritPass(classtable);
    scopePass(classtable);//everything done!
    /* some semantic analysis code may go here */
    if (classtable->errors()) {
	cerr << "Compilation halted due to static semantic errors." << endl;
	exit(1);
    }
}
void program_class::inheritPass(ClassTableP env){
  for(int i=classes->first();classes->more(i);i=classes->next(i)){
    classes->nth(i)->inheritPass(env);
  }
  while(env->buffer!=NULL){
    List<class__class>* oldBuffer=env->buffer;
    env->buffer=NULL;
    bool flag=false;
    for(List<class__class>* tmp=oldBuffer;tmp!=NULL;tmp=tmp->tl()){
      flag=flag||tmp->hd()->inheritPass(env);
    }
    if(flag==false){
      //report error
       env->semant_error(env->buffer->hd())<<"ill-formed class hierachy."<<endl;

      //exit(1);
      break;
    }
  }
  /*
   * need a function to check all the type in method and attr exist in the 
   * inherit tree
   * to accomplish this goal, despose the function as follows
   * inheritTreeNode* typeExist(Symbol type)
   * bool checkMethod(inheritTreeNode *node)
   * bool checkAttr(inheritTreeNode *node)
   * bool checkInheritTreeTypes(inheritTreeNode *root)
   */
  if(env->checkInheritTreeTypes(env->mytree)==false){
    //report error
    //not handle
    //some type used but not declared
     env->semant_error() << "some type used but not declared"<<endl;

  }
  
  if(env->searchClass(env->mytree,Main)==NULL){
    //report error
    env->semant_error()<<"Class Main is not defined"<<endl;
  }
  

}
inheritTreeNode* ClassTable::typeExist(Symbol type,inheritTreeNode *node){
  if(node==NULL){
    return NULL;
  }
  if(node->name==type){
    return node;
  }
  inheritTreeNode *result=NULL;
  for(List<inheritTreeNode>* tmp=node->child;tmp!=NULL;tmp=tmp->tl()){
    result=typeExist(type,tmp->hd());
    if(result!=NULL){
      return result;
    }
  }
  return NULL;
}

bool ClassTable::checkMethod(inheritTreeNode *node){
  for(List<methodType>* tmp=node->method;tmp!=NULL;tmp=tmp->tl()){
    if(typeExist(tmp->hd()->returnType,mytree)==NULL&&tmp->hd()->returnType!=SELF_TYPE){
      //report error
      semant_error(cc)<<"this node this method 's return type doesn't exist"<<endl;

      return false;
    }
    for(List<Entry>* tt=tmp->hd()->argType;tt!=NULL;tt=tt->tl()){
      if(typeExist(tt->hd(),mytree)==NULL){//args can not be type SELF_TYPE
	//report error
	semant_error(cc)<<"this node this method this arg's type doesn't exist"<<endl;

	return false;
      }
    }
  }
  return true;
}

bool ClassTable::checkAttr(inheritTreeNode *node){
  for(List<attrType>* tmp=node->attr;tmp!=NULL;tmp=tmp->tl()){
    if(typeExist(tmp->hd()->type,mytree)==NULL&&tmp->hd()->type!=SELF_TYPE){
      //report error
      semant_error(cc)<<"this node this attr's type doesn't exist"<<endl;

      return false;
    }
  }
  return true;
}

bool ClassTable::checkInheritTreeTypes(inheritTreeNode *root){
  if(root==NULL){
    return true;
  }
  if(checkAttr(root)==false){
    //report error
    semant_error(cc)<<"something wrong type in this treeNode in attribute"<<endl;

    return false;
  }
  if(checkMethod(root)==false){
    //report error
    semant_error(cc)<<"something wrong type in this treeNode in method"<<endl;

    return false;
  }
  bool flag=true;
  for(List<inheritTreeNode>* tmp=root->child;tmp!=NULL;tmp=tmp->tl()){
    flag=flag||checkInheritTreeTypes(tmp->hd());
  }
  if(flag==false){
    //report error
    semant_error(cc)<<"something wrong type in this treeNode in child"<<endl;

    return false;
  }else{
    return true;
  }
}

bool class__class::inheritPass(ClassTableP env){
  env->cc=this;
  //search in mytree for className =name ,if exist ,report error
  //search in mytree for classNmae = parent, if not exist, add to buffer
  // if exist return the parent's pointer i.e a inheritTreeNode*
  // after the process, this should done in program inheritPass,
  //the program_class::inheritPass should clean buffer, to find a class without
  //its parent, this case, should report error. use an flag ,to traverse the 
  //buffer list many times, if at the last, the buffer is empty, then nothing is
  //wrong, else if one pass with the flag no change, then it's time to report 
  //error

  //in order to search either name or parent, I must implement a search function
  if(name==SELF_TYPE||name==Object||name==Str||name==Bool||name==Int||parent==Str||parent==Bool){
    //report error
    //wrong usage of reserved keyword SELF_TYPE
    env->semant_error(env->cc)<<"ill-formed class hierachies"<<endl;
    //never care this problem again

    return false;
  }
  if(parent==SELF_TYPE){
    env->semant_error(env->cc)<<"inherit from SELF_TYPE"<<endl;
    parent=Object;
  }
  inheritTree tmp=env->searchClass(env->mytree,name);
  if(tmp!=NULL){
    //report error
    env->semant_error(env->cc)<<"how to deal with this error, not add this class to inherit tree?"<<endl;

    //todo

    return false;
  }
  tmp=env->searchClass(env->mytree,parent);
  if(tmp==NULL){
    env->buffer=new List<class__class>(this,env->buffer);
    return false;
  }else{
    /*
     * inheritTreeNode *newNode=new inheritTreeNode;
     * newNode->name=name;
     * ////handle the method and attr
     * tmp->child=new List(newNode,tmp->child)
     */
    inheritTreeNode *newNode=new inheritTreeNode;
    newNode->name=name;
    newNode->parent=tmp;
    newNode->attr=NULL;
    newNode->method=NULL;
    newNode->child=NULL;
    env->currentNode=newNode;
    //handle newNode's method and attribute
    //class->feature_list->feature->attr and method
    //on the attr+method level, we can use the virture run time feature to do
    //personized handle
    //should know the list structure
    for(int i=features->first();features->more(i);i=features->next(i)){
      features->nth(i)->inheritPass(env);
      //recall the feature's inheritPass
    }
    tmp->child=new List<inheritTreeNode>(newNode,tmp->child);
    return true;
  }

}
bool class__class::inheritInit(ClassTableP env){
  inheritTree tmp=env->searchClass(env->mytree,name);
  tmp=env->searchClass(env->mytree,parent);
  if(tmp==NULL){
    env->buffer=new List<class__class>(this,env->buffer);
    return false;
  }else{
    inheritTreeNode *newNode=new inheritTreeNode;
    newNode->name=name;
    newNode->parent=tmp;
    newNode->attr=NULL;
    newNode->method=NULL;
    newNode->child=NULL;
    env->currentNode=newNode;
    for(int i=features->first();features->more(i);i=features->next(i)){
      features->nth(i)->inheritPass(env);
      //recall the feature's inheritPass
    }
    tmp->child=new List<inheritTreeNode>(newNode,tmp->child);
    return true;
  }

}

void attr_class::inheritPass(ClassTableP env){
  /* 
   * check whether this attribute ocurr only once, in this class or parent class
   * the search function begin with current class more precisely speaking,
   * the inheritTree. to search it's list attr, and search his father
   * this function return attrType*
   */
  if(env->searchAttr(env->currentNode,name)!=NULL){
    //report error
    env->semant_error(env->cc)<<"this attribute has declared once"<<endl;
    return;
  }
  if(name==self){
    //report error
    env->semant_error(env->cc)<<"an attribute named self"<<endl;
  }
  attrType *newAttr=new attrType;
  newAttr->name=name;
  newAttr->type=type_decl;
  env->currentNode->attr=new List<attrType>(newAttr,env->currentNode->attr);
}

attrType* ClassTable::searchAttr(inheritTree son,Symbol target){
  if(son==NULL){
    return NULL;
  }
  for(List<attrType>* tmp=son->attr;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==target){
      return tmp->hd();
    }
  }
  return searchAttr(son->parent,target);
}

void method_class::inheritPass(ClassTableP env){
  /* 
   * to make sure that a method only occur one times in current class
   * or occur in father class with the same argType and return_type
   */
  methodType *oldMethod=NULL;
  for(List<methodType>* tmp=env->currentNode->method;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==name){
      oldMethod=tmp->hd();
      break;
    }
  }
  if(oldMethod!=NULL){
    //report error
    env->semant_error(env->cc)<<"the same name method define twice in a single class"<<endl;


    return;
  }
  
  methodType *newMethod=new methodType;
  newMethod->name=name;
  newMethod->returnType=return_type;
  newMethod->argType=NULL;
  bool ff=false;
  for(int i=0;i<formals->len()-1;i++){
    for(int j=i+1;j<formals->len();j++){
      if(formals->nth(i)->getName()==formals->nth(j)->getName()){
	ff=true;
      }
    }
  }
  if(ff==true){
    //report error
    env->semant_error(env->cc)<<"Duplicate name in formal param list"<<endl;
  }
  for(int i=0;i<formals->len();i++){
    if(formals->nth(i)->getName()==self){
      //report error
      env->semant_error(env->cc)<<"self as name of a formal parameter"<<endl;
    }
    if(formals->nth(i)->getType()==SELF_TYPE){
      //report error
      env->semant_error(env->cc)<<"SELF_TYPE given as a parameter type"<<endl;
    }
  }
  //handle the argType with formals
  for(int i=formals->len()-1;i>=0;i--){
    newMethod->argType=new List<Entry>(formals->nth(i)->getType(),newMethod->argType);
  }

  oldMethod=env->searchMethod(env->currentNode->parent,name);
  if(oldMethod!=NULL){
    bool flag=false;
    List<Entry>* oldArg=oldMethod->argType;
    List<Entry>* newArg=newMethod->argType;
    while(oldArg!=NULL&&newArg!=NULL){
      if(oldArg->hd()!=newArg->hd()){
	flag=true;
	break;
      }
      oldArg=oldArg->tl();
      newArg=newArg->tl();
    }
    if(oldArg!=NULL||newArg!=NULL){
      flag=flag||true;
    }
    if(oldMethod->returnType!=newMethod->returnType){
      flag=flag||true;
    }
    if(flag==true){
      //report error 
      env->semant_error(env->cc)<<"the overriden method have the different arg or return type"<<endl;
      return;
    }
  }
  //at last add this method_class to env->currentNode->method
  env->currentNode->method=new List<methodType>(newMethod,env->currentNode->method);
}
Symbol formal_class::getName(){
  return name;
}

methodType* ClassTable::searchMethod(inheritTree root,Symbol target){
  if(root==NULL){
    return NULL;
  }
  for(List<methodType>* tmp=root->method;tmp!=NULL;tmp=tmp->tl()){
    if(tmp->hd()->name==target){
      return tmp->hd();
    }
  }
  return searchMethod(root->parent,target);
}


Symbol formal_class::getType(){
  return type_decl;
}

inheritTree ClassTable::searchClass(inheritTree root,Symbol target){
  /*
   * a recursive function
   * first check the root
   * how to handle the list children
   */
  if(root==NULL){
    return NULL;
  }
  if(root->name==target){
    return root;
  }else{
    List<inheritTreeNode>* tmp=root->child;
    while(tmp!=NULL){
      inheritTree result;
      result=searchClass(tmp->hd(),target);
      if(result!=NULL){
	return result;
      }else{
	tmp=tmp->tl();
      }
    }
    return NULL;
  }
}
void program_class::scopePass(ClassTableP env){
  /*
   * mainly use the Symtab class,set initial and recall the class__class::scopePass
   * for every class
   * in class__class::scope,first enter a scope,then process,last exit
   */
  for(int i=classes->first();classes->more(i);i=classes->next(i)){
    classes->nth(i)->scopePass(env);
  }
}

void class__class::scopePass(ClassTableP env){
  env->cc=this;
  env->currentNode=env->searchClass(env->mytree,name);
  if(env->currentNode==NULL){
    return;
    //for wrong defined class case
  }
  env->myscope->enterscope();
  for(List<attrType>* tmp=env->currentNode->attr;tmp!=NULL;tmp=tmp->tl()){
    env->myscope->addid(tmp->hd()->name,tmp->hd()->type);
  }
  for(int i=features->first();features->more(i);i=features->next(i)){
    features->nth(i)->scopePass(env);
    /*
     * for method feature do
     * for attr feature return
     */
  }
  env->myscope->exitscope();
}

void method_class::scopePass(ClassTableP env){
  /*
   * add the method arg's formal to scope
   * and then check the expression
   */
  env->myscope->enterscope();
  for(int i=formals->first();formals->more(i);i=formals->next(i)){
    formals->nth(i)->scopePass(env);
  }
  if(env->isSubTypeOf(expr->scopePass(env),return_type)==false){
    //report error
    env->semant_error(env->cc)<<"in this method, expression type doesn't match return value"<<endl;

  }
  env->myscope->exitscope();
}
void formal_class::scopePass(ClassTableP env){
  env->myscope->addid(name,type_decl);
}


void attr_class::scopePass(ClassTableP env){
  if(env->isSubTypeOf(init->scopePass(env),type_decl)==false){
    //report error
    env->semant_error(env->cc)<<" this attribute, the init expression type doesn't match the delared type"<<endl;

  }
}
bool ClassTable::isSubTypeOf(Symbol sub,Symbol obj){
  /*
   * handle no type for no expression
   * handle self type
   */
  if(sub==obj||sub==No_type){
    return true;
  }
  if(obj==SELF_TYPE||obj==No_type){
    return false;
  }
  if(sub==SELF_TYPE){
    return isSubTypeOf(currentNode->name,obj);
  }
  inheritTreeNode* Sub=searchClass(mytree,sub);
  if(Sub==NULL){
    //report error
    semant_error(cc)<<"this case can not occur"<<endl;
  }
  while(Sub!=NULL){
    if(Sub->name==obj){
      return true;
    }
    Sub=Sub->parent;
  }
  return false;
}

/*
 * handle all expression case
 */

Symbol object_class::scopePass(ClassTableP env){
  Symbol type=env->myscope->lookup(name);
  if(type==NULL){
    attrType* tmp=env->searchAttr(env->currentNode,name);
    if(tmp==NULL){
      //report error
      env->semant_error(env->cc)<<"this object used but not declared"<<endl;

      return Object;
    }else{
      type=tmp->type;
    }
  }
  // if(type==SELF_TYPE){
  // set_type(env->currentNode->name);
  // }else{
    set_type(type);
    // }
  return type;
}

Symbol assign_class::scopePass(ClassTableP env){
  if(name==self){
    //report error
    env->semant_error(env->cc)<<"assignment to self"<<endl;
    return Object;
  }
  Symbol nameType=env->myscope->lookup(name);
  Symbol exprType=expr->scopePass(env);
  if(nameType==NULL){
    attrType* tmp=env->searchAttr(env->currentNode,name);
    if(tmp==NULL){
      //report error
      env->semant_error(env->cc)<<"this object used but not declared"<<endl;

      return Object;
    }else{
      nameType=tmp->type;
    }
  }
  // if expr is no_expr case
  // no_expr only occur in attribute initial case or let expression inital case
  if(env->isSubTypeOf(exprType,nameType)==false){
    //report error
    env->semant_error(env->cc)<<"wrong assignment statement, expression type doesn't match variable tue"<<endl;

    return Object;
  }else{
    //set_type(expr->get_type());
    //tag
    set_type(exprType);
    return exprType;
  }
}
Symbol int_const_class::scopePass(ClassTableP env){
  set_type(Int);
  return Int;
}
Symbol bool_const_class::scopePass(ClassTableP env){
  set_type(Bool);
  return Bool;
}

Symbol string_const_class::scopePass(ClassTableP env){
  set_type(Str);
  return Str;
}

Symbol new__class::scopePass(ClassTableP env){
  if(type_name!=SELF_TYPE&&env->searchClass(env->mytree,type_name)==NULL){
    //report error
    env->semant_error(env->cc)<<"new a Type that doesn't exist"<<endl;

    return Object;
  } 
  if(type_name==SELF_TYPE){
    //set_type(env->currentNode->name);
    set_type(SELF_TYPE);
  }else{
    set_type(type_name);
  }
  return type_name;
}

Symbol dispatch_class::scopePass(ClassTableP env){
  Symbol e0=expr->scopePass(env);
  Symbol ee=e0;
  if(e0==SELF_TYPE){
    ee=env->currentNode->name;
  }
  /*
   * check whether the recalled method exist
   * check the actual has the true types
   * other issue
   */
  methodType* method=env->searchMethod(env->searchClass(env->mytree,ee),name);
  if(method==NULL){
    //report error
    env->semant_error(env->cc)<<"the dispathed method doesn't exist"<<endl;

    return Object;
  }
  List<Entry>* formal=method->argType;
  for(int i=actual->first();actual->more(i);i=actual->next(i)){
    if(formal==NULL){
      //report error
      env->semant_error(env->cc)<<"the number of the actual and formal parameter doesn't match"<<endl;

      return Object;
    }
    if(env->isSubTypeOf(actual->nth(i)->scopePass(env),formal->hd())==false){
      //report error
      env->semant_error(env->cc)<<"the actual parameter's type doesn't match the formal's"<<endl;

      return Object;
    }
    formal=formal->tl();
  }
  if(formal!=NULL){
    //report error
    env->semant_error(env->cc)<<"the number of the actual and formal parameter doesn't match"<<endl;
    
    return Object;
  }
  if(method->returnType==SELF_TYPE){
   set_type(e0);
    return e0;
    }else{
    set_type(method->returnType);
    return method->returnType;
   }
}

Symbol static_dispatch_class::scopePass(ClassTableP env){
  Symbol e0=expr->scopePass(env);
  Symbol ee=e0;
  if(e0==SELF_TYPE){
    ee=env->currentNode->name;
  }
  if(env->isSubTypeOf(ee,type_name)==false){
    //report error
    env->semant_error(env->cc)<<"wrong static dispatch about type and subType"<<endl;

    return Object;
  }
  methodType* method=env->searchMethod(env->searchClass(env->mytree,type_name),name);
  if(method==NULL){
    //report error
    env->semant_error(env->cc)<<"the dispathed method doesn't exist"<<endl;

    return Object;
  }
  List<Entry>* formal=method->argType;
  for(int i=actual->first();actual->more(i);i=actual->next(i)){
    if(formal==NULL){
      //report error
      env->semant_error(env->cc)<<"the number of the actual and formal parameter doesn't match"<<endl;

      return Object;
    }
    if(env->isSubTypeOf(actual->nth(i)->scopePass(env),formal->hd())==false){
      //report error
      env->semant_error(env->cc)<<"the actual parameter's type doesn't match the formal's"<<endl;

      return Object;
    }
    formal=formal->tl();
  }
  if(formal!=NULL){
    //report error
    env->semant_error(env->cc)<<"the number of the actual and formal parameter doesn't match"<<endl;
    
    return Object;
  }
  if(method->returnType==SELF_TYPE){
  set_type(e0);
   return e0;
   }else{
    set_type(method->returnType);
    return method->returnType;
     }
}

Symbol cond_class::scopePass(ClassTableP env){
  if(pred->scopePass(env)!=Bool){
    //report error
    env->semant_error(env->cc)<<"the pred expression's type should be Bool"<<endl;

    return Object;
  }
  Symbol tmp=then_exp->scopePass(env);
  tmp=env->lub(tmp,else_exp->scopePass(env));
  if(tmp==SELF_TYPE){
    //set_type(env->currentNode->name);
    set_type(SELF_TYPE);
  }else{
    set_type(tmp);
  }
  return tmp;
}

Symbol ClassTable::lub(Symbol a,Symbol b){
  if(a==b){
    return a;
  }
  if(a==No_type){
    return b;
  }
  if(b==No_type){
    return a;
  }
  if(a==SELF_TYPE){
    a=currentNode->name;
  }
  if(b==SELF_TYPE){
    b=currentNode->name;
  }
  inheritTree tmp=searchClass(mytree,a);
  while(tmp!=NULL){
    if(isSubTypeOf(b,tmp->name)){
      return tmp->name;
    }else{
      tmp=tmp->parent;
    }
  }
  return Object;
}

Symbol block_class::scopePass(ClassTableP env){
  Symbol tmp=No_type;
  for(int i=body->first();body->more(i);i=body->next(i)){
    tmp=body->nth(i)->scopePass(env);
  }
  if(tmp==SELF_TYPE){
    //set_type(env->currentNode->name);
    set_type(SELF_TYPE);
  }else{
    set_type(tmp);
  }
  return tmp;
}

Symbol let_class::scopePass(ClassTableP env){
  if(identifier==self){
    //report error
    env->semant_error(env->cc)<<" let expression use self as id"<<endl;
    return Object;
  }
  Symbol initType=init->scopePass(env);
  Symbol idType=type_decl;
  if(idType==SELF_TYPE){
    idType==env->currentNode->name;
  }
  if(env->isSubTypeOf(initType,idType)==false){
    //report error
    env->semant_error(env->cc)<<"let expression with wrong initial expression"<<endl;

    return Object;
  }
  env->myscope->enterscope();
  env->myscope->addid(identifier,idType);
  Symbol tmp=body->scopePass(env);
  env->myscope->exitscope();
  if(tmp==SELF_TYPE){
    //set_type(env->currentNode->name);
    set_type(SELF_TYPE);
  }else{
    set_type(tmp);
  }
  return tmp;
}

Symbol typcase_class::scopePass(ClassTableP env){
  expr->scopePass(env);
  Symbol tmp=No_type;
  bool flag=false;
  for(int i=0;i<cases->len()-1;i++){
    for(int j=i+1;j<cases->len();j++){
      if(cases->nth(i)->getType()==cases->nth(j)->getType()){
	//std::cout<<"a\t";
	//env->semant_error(env->cc)<<"Duplicate branch in a case expr"<<endl;
	 flag=true;
      }
    }
  }

  if(flag==true){
    //report error
    env->semant_error(env->cc)<<"Duplicate branch in a case expr"<<endl;
  }
 

  for(int i=cases->first();cases->more(i);i=cases->next(i)){
    tmp=env->lub(tmp,cases->nth(i)->scopePass(env));
  }
  if(tmp==SELF_TYPE){
    // set_type(env->currentNode->name);
    set_type(SELF_TYPE);
  }else{
    set_type(tmp);
  }
  return tmp;
}
Symbol branch_class::getType(){
  return type_decl;
}
Symbol branch_class::scopePass(ClassTableP env){
  env->myscope->enterscope();
  env->myscope->addid(name,type_decl);
  Symbol tmp=expr->scopePass(env);
  env->myscope->exitscope();
  return tmp;
}

Symbol loop_class::scopePass(ClassTableP env){
  if(pred->scopePass(env)!=Bool){
    //report error
    env->semant_error(env->cc)<<"in if expression, the pred 's type is not bool"<<endl;

    return Object;
  }
  body->scopePass(env);
  return Object;
}

Symbol isvoid_class::scopePass(ClassTableP env){
  e1->scopePass(env);
  set_type(Bool);
  return Bool;
}

Symbol no_expr_class::scopePass(ClassTableP env){
  set_type(No_type);
  return No_type;
}

Symbol neg_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"neg_class the expression's type is not int"<<endl;

    return Object;
  }
  set_type(Int);
  return Int;
}

Symbol comp_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Bool){
    //report error
    env->semant_error(env->cc)<<"comp_class the expression's type is not int"<<endl;

    return Object;
  }
  set_type(Bool);
  return Bool;
}

Symbol lt_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"lt expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"Elt expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Bool);
  return Bool;
}

Symbol leq_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"leq expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"leq expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Bool);
  return Bool;
}

Symbol eq_class::scopePass(ClassTableP env){
  Symbol t1=e1->scopePass(env);
  Symbol t2=e2->scopePass(env);
  if(t1!=Int&&t1!=Str&&t1!=Bool){
    //report error
    // env->semant_error(env->cc)<<"eq expression, the e1' type is not int,str or bool"<<endl;

    // return Object;
  }else{
    if(t1!=t2){
      //report error
      env->semant_error(env->cc)<<"eq expression, the two expression have different types"<<endl;

      return Object;
    }
  }
  set_type(Bool);
  return Bool;
}

Symbol plus_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"plus expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"plus expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Int);
  return Int;
}

Symbol sub_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"sub expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"sub expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Int);
  return Int;
}

Symbol mul_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"mul expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"mul expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Int);
  return Int;
}

Symbol divide_class::scopePass(ClassTableP env){
  if(e1->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"divide expression e1's type is not int"<<endl;

    return Object;
  }
  if(e2->scopePass(env)!=Int){
    //report error
    env->semant_error(env->cc)<<"divide expression e1's type is not int"<<endl;

    return Object;
  }
  set_type(Int);
  return Int;
}
