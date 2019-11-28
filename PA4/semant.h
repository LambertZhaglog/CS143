#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

struct methodType{
  Symbol name;
  List<Entry>* argType;//the first arg of method at head of list
  //*Symbol=Entry
  Symbol returnType;
};

struct attrType{
  Symbol name;
  Symbol type;
};

struct inheritTreeNode{
  Symbol name;
  List<attrType>* attr;
  List<methodType>* method;
  List<inheritTreeNode>* child;
  inheritTreeNode *parent;
};

typedef inheritTreeNode *inheritTree;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;

public:
  ClassTable(Classes);
  Class_ cc;// currentErrorNode;
  inheritTree mytree;
  inheritTree currentNode;//as the Class in O,M,C
  List<class__class>* buffer;
  inheritTree searchClass(inheritTree root,Symbol target);
  attrType* searchAttr(inheritTree son,Symbol target);
  methodType* searchMethod(inheritTree son,Symbol target);
  bool checkInheritTreeTypes(inheritTreeNode *root);
  bool checkAttr(inheritTreeNode *node);
  bool checkMethod(inheritTreeNode *node);
  inheritTreeNode* typeExist(Symbol type,inheritTreeNode *node);
  bool isSubTypeOf(Symbol sub,Symbol obj);
  Symbol lub(Symbol a,Symbol b);
  SymbolTable<Symbol,Entry> *myscope;
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};


#endif

