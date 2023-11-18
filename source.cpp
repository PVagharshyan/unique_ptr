#include <iostream>
#include "unique_ptr.h"

int main() {
    unique_ptr<int> ptr (new int(10));
    unique_ptr<int> ptr_1 = ptr;
    return 0;
}