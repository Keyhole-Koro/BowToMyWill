#include "accessPrivilege.h"

AccessPrivilege *initialiedAccessPrivilege(AccessPrivilege *bitmap) {
    AccessPrivilege *bitmap = calloc(sizeof(AccessPrivilege));
    return bitmap;
}

void setOverwritable(AccessPrivilege *bitmap) { bitmap->overwrite = true; }
void setConstant(AccessPrivilege *bitmap) { bitmap->constant = true; }
void setFunctionRead(AccessPrivilege *bitmap) { bitmap->function_read = true; }
void setFunctionWrite(AccessPrivilege *bitmap) { bitmap->function_write = true; }
void setNamespaceRead(AccessPrivilege *bitmap) { bitmap->namespace_read = true; }
void setNamespaceWrite(AccessPrivilege *bitmap) { bitmap->namespace_write = true; }
void setNestedNamespaceRead(AccessPrivilege *bitmap) { bitmap->nested_namespace_read = true; }
void setNestedNamespaceWrite(AccessPrivilege *bitmap) { bitmap->nested_namespace_write = true; }
void setClassRead(AccessPrivilege *bitmap) { bitmap->class_read = true; }
void setClassWrite(AccessPrivilege *bitmap) { bitmap->class_write = true; }
void setNestedClassRead(AccessPrivilege *bitmap) { bitmap->nested_class_read = true; }
void setNestedClassWrite(AccessPrivilege *bitmap) { bitmap->nested_class_write = true; }
void setDerivingClassRead(AccessPrivilege *bitmap) { bitmap->deriving_class_read = true; }
void setDerivingClassWrite(AccessPrivilege *bitmap) { bitmap->deriving_class_write = true; }

bool isOverwritable(AccessPrivilege *bitmap) { return bitmap->overwrite; }
bool isConstant(AccessPrivilege *bitmap) { return bitmap->constant; }
bool isFunctionRead(AccessPrivilege *bitmap) { return bitmap->function_read; }
bool isFunctionWrite(AccessPrivilege *bitmap) { return bitmap->function_write; }
bool isNamespaceRead(AccessPrivilege *bitmap) { return bitmap->namespace_read; }
bool isNamespaceWrite(AccessPrivilege *bitmap) { return bitmap->namespace_write; }
bool isNestedNamespaceRead(AccessPrivilege *bitmap) { return bitmap->nested_namespace_read; }
bool isNestedNamespaceWrite(AccessPrivilege *bitmap) { return bitmap->nested_namespace_write; }
bool isClassRead(AccessPrivilege *bitmap) { return bitmap->class_read; }
bool isClassWrite(AccessPrivilege *bitmap) { return bitmap->class_write; }
bool isNestedClassRead(AccessPrivilege *bitmap) { return bitmap->nested_class_read; }
bool isNestedClassWrite(AccessPrivilege *bitmap) { return bitmap->nested_class_write; }
bool isDerivingClassRead(AccessPrivilege *bitmap) { return bitmap->deriving_class_read; }
bool isDerivingClassWrite(AccessPrivilege *bitmap) { return bitmap->deriving_class_write; }