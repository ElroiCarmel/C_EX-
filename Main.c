#include "StrList.h"
#include <stdio.h>
#include <string.h>

int main()
{
    StrList* myList = StrList_alloc();
    char *w[] = {"hello", "story", "hello", "school", "hello"};
    for (int i =0; i<sizeof(w)/sizeof(w[0]) ;i++) {
        StrList_insertLast(myList, w[i]);
    }
    // StrList_insertLast(myList, "hello");
    // StrList_insertLast(myList, "elroi");
    StrList_print(myList);
    // printf("%d\n", StrList_isSorted(myList));
    // StrList_insertAt(myList, "insetedStrart", 0);
    // StrList_print(myList);
    // StrList_insertAt(myList, "insetedBetween", 1);
    // StrList_print(myList);
    // printf("%d\n", StrList_isSorted(myList));
    // StrList_sort(myList);
    // printf("%d\n", StrList_isSorted(myList));
    StrList_remove(myList, "hello");
    StrList_print(myList);
    StrList_printAt(myList, 1);

    return 0;
}