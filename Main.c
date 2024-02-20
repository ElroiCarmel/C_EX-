#include "StrList.h"
#include <stdio.h>
#include <string.h>
#define MAX 200

int main()
{
    int option = -1;
    StrList* list = StrList_alloc();
    char word[MAX];
    do {   
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int wc, i;
            scanf("%d", &wc);
            for (i = 0; i < wc; i++) {
                scanf(" %s", word);
                StrList_insertLast(list, word);
            }
            break;
        case 2:
            int index;
            scanf("%d", &index);
            scanf(" %s", word);
            StrList_insertAt(list, word, index);
            break;
        case 3:
            StrList_print(list);
            printf("\n");
            break;
        case 4:
            printf("%ld\n", StrList_size(list));
            break;
        case 5:
            // int index;
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;
        case 6:
            printf("%d\n", StrList_printLen(list));
            break;
        case 7:
            int ans;
            scanf(" %s", word);
            ans = StrList_count(list, word);
            printf("%d\n", ans);
            break;
        case 8:
            scanf(" %s", word);
            StrList_remove(list, word);
            break;
        case 9:
            // int index;
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            StrList_free(list);
            list = StrList_alloc();
            break;
        case 12:
            StrList_sort(list);
            break;
        case 13:
            ans = StrList_isSorted(list);
            if (ans) {
                printf("true\n");
            } else {
                printf("false\n");
            }
            break;
        }
    } while (option != 0);
    StrList_free(list);
    return 0;
}