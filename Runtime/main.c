#include "main.h"

void test_directory_and_file_operations() {
    Directory *root = createDirectory("root", NULL);
    Directory *subdir = createDirectory("subdir", root);
    addSubdirectory(root, subdir);

    Data *data = createData("file1.txt", "{\"content\": \"Hello, World!\"}", 19);
    addDataToDirectory(subdir, data);

    Directory *fetched_dir = (Directory *)fetch(root, "subdir");
    assert(fetched_dir != NULL && strcmp(fetched_dir->name, "subdir") == 0);

    Data *fetched_data = (Data *)fetch(root, "subdir/file1.txt");
    assert(fetched_data != NULL && strcmp(fetched_data->name, "file1.txt") == 0);
    assert(fetched_data->size == 19);

}

void test_access_privileges() {
    AccessPrivilege *priv = initialiedAccessPrivilege();
    assert(priv != NULL);

    setOverwritable(priv);
    assert(isOverwritable(priv) == true);

    setConstant(priv);
    assert(isConstant(priv) == true);

    setFunctionRead(priv);
    assert(isFunctionRead(priv) == true);

    setFunctionWrite(priv);
    assert(isFunctionWrite(priv) == true);

    setNamespaceRead(priv);
    assert(isNamespaceRead(priv) == true);

    setNamespaceWrite(priv);
    assert(isNamespaceWrite(priv) == true);

    setNestedNamespaceRead(priv);
    assert(isNestedNamespaceRead(priv) == true);

    setNestedNamespaceWrite(priv);
    assert(isNestedNamespaceWrite(priv) == true);

    setClassRead(priv);
    assert(isClassRead(priv) == true);

    setClassWrite(priv);
    assert(isClassWrite(priv) == true);

    setNestedClassRead(priv);
    assert(isNestedClassRead(priv) == true);

    setNestedClassWrite(priv);
    assert(isNestedClassWrite(priv) == true);

    setDerivingClassRead(priv);
    assert(isDerivingClassRead(priv) == true);

    setDerivingClassWrite(priv);
    assert(isDerivingClassWrite(priv) == true);

    free(priv);
}

int main() {
    test_directory_and_file_operations();
    test_access_privileges();
    printf("All tests passed.\n");
    return 0;
}
