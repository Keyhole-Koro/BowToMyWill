#ifndef ACCESS_PRIVILEGE_H
#define ACCESS_PRIVILEGE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    /** 
        @brief writable
            ex override in methods
    */
    bool overwrite : 1;

    /** 
        @brief prioritized than read below
            ex const in variables
    */
    bool constant : 1;

    // within a function
    bool function_read : 1;
    bool function_write : 1;

    bool nested_function_read : 1;
    bool nested_function_write : 1;

    bool another_function_read : 1;
    bool another_function_write : 1;

    // inside the namespace
    bool namespace_read : 1;
    bool namespace_write : 1;

    // inside the nested namespace
    bool nested_namespace_read : 1;
    bool nested_namespace_write : 1;

    // exported destination
    bool another_namespace_read : 1;
    bool another_namespace_write : 1;

    bool class_read : 1;
    bool class_write : 1;

    bool nested_class_read : 1;
    bool nested_class_write : 1;

    bool deriving_class_read : 1;
    bool deriving_class_write : 1;

    // ex friend in modern
    bool another_class_read : 1;
    bool another_class_write : 1;

    // within a file
    bool file_read : 1;
    bool file_write : 1;

    // exported destination
    bool another_file_read : 1;
    bool another_file_write : 1;

    // can be acccessed from anywhere in a program
    bool program_read : 1;
    bool program_write : 1;

} AccessPrivilege;

AccessPrivilege *initialiedAccessPrivilege();

void setOverwritable(AccessPrivilege *bitmap);
void setConstant(AccessPrivilege *bitmap);
void setFunctionRead(AccessPrivilege *bitmap);
void setFunctionWrite(AccessPrivilege *bitmap);
void setNamespaceRead(AccessPrivilege *bitmap);
void setNamespaceWrite(AccessPrivilege *bitmap);
void setNestedNamespaceRead(AccessPrivilege *bitmap);
void setNestedNamespaceWrite(AccessPrivilege *bitmap);
void setClassRead(AccessPrivilege *bitmap);
void setClassWrite(AccessPrivilege *bitmap);
void setNestedClassRead(AccessPrivilege *bitmap);
void setNestedClassWrite(AccessPrivilege *bitmap);
void setDerivingClassRead(AccessPrivilege *bitmap);
void setDerivingClassWrite(AccessPrivilege *bitmap);

bool isOverwritable(AccessPrivilege *bitmap);
bool isConstant(AccessPrivilege *bitmap);
bool isFunctionRead(AccessPrivilege *bitmap);
bool isFunctionWrite(AccessPrivilege *bitmap);
bool isNamespaceRead(AccessPrivilege *bitmap);
bool isNamespaceWrite(AccessPrivilege *bitmap);
bool isNestedNamespaceRead(AccessPrivilege *bitmap);
bool isNestedNamespaceWrite(AccessPrivilege *bitmap);
bool isClassRead(AccessPrivilege *bitmap);
bool isClassWrite(AccessPrivilege *bitmap);
bool isNestedClassRead(AccessPrivilege *bitmap);
bool isNestedClassWrite(AccessPrivilege *bitmap);
bool isDerivingClassRead(AccessPrivilege *bitmap);
bool isDerivingClassWrite(AccessPrivilege *bitmap);

#endif