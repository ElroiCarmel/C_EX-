#include "StrList.h"
#include <stdio.h>
#include <string.h>

int main()
{
    StrList* myList = StrList_alloc();
    StrList_insertLast(myList, "hello");
    StrList_insertLast(myList, "elroi");
    StrList_print(myList);
    StrList_insertAt(myList, "insetedStrart", 0);
    StrList_print(myList);
    StrList_insertAt(myList, "insetedBetween", 1);
    StrList_print(myList);
    StrList_removeAt(myList, 4);
    StrList_print(myList);

    return 0;
}