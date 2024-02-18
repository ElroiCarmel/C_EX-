#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
    char* string;
    struct _node* _next;
} Node;

struct _StrList {
    Node* _head;
    Node* _tail;
    size_t _size;
};

// Node

Node* Node_alloc(const char* string, Node* next) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->string = (char*)malloc(sizeof(char)*strlen(string)+1);
    strcpy(p->string, string);
    p->_next = next;
    return p;
}

void Node_free(Node* node) {
    if (node == NULL) return;
    if (node->string != NULL) 
    {
        free(node->string);
    }
    free(node);
}

// List ---------------------------------------------

StrList* StrList_alloc() {
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head = p->_tail = NULL;
    p->_size = 0;
    return p;
}

void StrList_free(StrList* StrList) {
    if (StrList == NULL) return;
    Node* p1 = StrList->_head;
    Node* p2;
    while (p1)
    {
        /* p2 is the prevous node, first free him than continue
           forward in the list */
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

// Methods -------------------------------------

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
    
}

void StrList_insertLast(StrList* StrList, const char* data) {
    Node* p = Node_alloc(data, NULL);
    Node* t = StrList->_tail;
    StrList->_tail = p;
    if (t == NULL)
    {
        StrList->_head = p;
    } else {
        t->_next = p;
    }
    StrList->_size = StrList->_size + 1;
}

void StrList_insertAt(StrList* StrList, const char* data,int index) {
    size_t lst_size = StrList->_size;
    if (index == lst_size)
    {
        StrList_insertLast(StrList, data);
        return;
    }
    Node* new_node = NULL;
    if (index == 0)
    {
        new_node = Node_alloc(data, StrList->_head);
        StrList->_head = new_node;
    } else {
    Node* nptr = StrList->_head;
    while (--index)
    {
        nptr = nptr->_next;
    }
    new_node = Node_alloc(data, nptr->_next);
    nptr->_next = new_node;
    }
    StrList->_size = StrList->_size + 1;
}


char* StrList_firstData(const StrList* StrList) {
    return StrList->_head->string;
}

void StrList_print(const StrList* StrList) {
    Node* nptr = StrList->_head;
    while (nptr) {
        printf("%s ", nptr->string);
        nptr = nptr->_next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index) {
    size_t size = StrList_size(Strlist);
    if (index < 0 || index >= size)
    {
        printf("Error! index is not valid\n");
        return;
    }
    Node* np = Strlist->_head;
    while (--index > 0)
    {
        np = np->_next;
    }
    char* ans = np->string;
    printf("%s\n", ans);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist) {
    size_t ans = 0;
    Node* np = Strlist->_head;
    while (np)
    {
        ans += strlen(np->string);
        np = np->_next;
    }
    return ans;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data) {
    size_t ans = 0;
    Node* np = StrList->_head;
    while (np)
    {
        char* current_string = np->string;
        if (strcmp(current_string, data) == 0) ans++;
    }
    return ans;
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data);

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index) {
    size_t size = StrList_size(StrList);
    if (index < 0 || index >= size)
    {
        printf("Error! index is not valid\n");
        return;
    }
    Node *to_remove = NULL, *prev = NULL;
    if (index == 0)
    {
        to_remove = StrList->_head;
        StrList->_head = StrList->_head->_next;
        if (StrList->_tail == to_remove) {
            StrList->_tail = StrList->_head;
        }
    } else {
        prev = StrList->_head;
        while (--index) {
            prev = prev->_next;
        }   
        to_remove = prev->_next;
        prev->_next = to_remove->_next;
        if (StrList->_tail == to_remove) {
            StrList->_tail = prev;
        }
    }
    Node_free(to_remove);
    StrList->_size = size - 1;
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList);

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList);

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList) {
    Node* np = StrList->_head;
    while (np->_next)
    {
        char* current_string = np->string;
        char* next_string = np->_next->string;
        if (strcmp(current_string, next_string) > 0)
        {
            return 0;
        }
    }
    return 1;
}