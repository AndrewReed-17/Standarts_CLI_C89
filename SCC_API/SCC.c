#include <stdio.h>
#include <stdlib.h>
#include "SCC.h"

/* Insert in Head */
SLN StringList_Insert_InHead(char element, SLN L) {
    SLC* new_content = (SLC*) malloc(sizeof(SLC));
    if (new_content == NULL) return NULL;
    new_content->content = element;
    new_content->next = L;
    return new_content;
}

/* Procedural Insert in Head */
void StringList_Procedural_Insert_InHead(char element, SLN* L) {
    SLN old = *L;
    *L = IIH(element, *L);
    if (*L == NULL) *L = old;
}

/* Insert in Tail */
SLN StringList_Insert_InTails(char element, SLN L) {
    SLC* new_content = (SLC*) malloc(sizeof(SLC));
    SLN tmp;
    if (new_content == NULL) return NULL;
    new_content->content = element;
    new_content->next = NULL;

    if (L == NULL) return new_content;

    tmp = L;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = new_content;
    return L;
}

/* Procedural Insert in Tail */
void StringList_Procedural_Insert_InTails(char element, SLN* L) {
    SLN old = *L;
    *L = IIT(element, *L);
    if (*L == NULL) *L = old;
}

/* Delete Head */
SLN StringList_Delet_InHead(SLN L) {
    SLN res;
    if (L == NULL) return NULL;
    res = L->next;
    free(L);
    return res;
}

/* Procedural Delete Head */
void StringList_Procedural_DeletInHead(SLN* L) {
    *L = DIH(*L);
}

/* Delete Tail */
SLN StringList_Delet_InTails(SLN L) {
    SLN tmp, prec;

    if (L == NULL) return NULL;
    if (L->next == NULL) {
        free(L);
        return NULL;
    }

    tmp = L;
    prec = NULL;

    while (tmp->next != NULL) {
        prec = tmp;
        tmp = tmp->next;
    }

    if (prec != NULL) prec->next = NULL;
    free(tmp);
    return L;
}

/* Procedural Delete Tail */
void StringList_Procedural_Delet_InTails(SLN* L) {
    *L = DIT(*L);
}

/* Delete Whole List */
void StringList_Delet(SLN* L) {
    while (*L != NULL) {
        PDIH(L);
    }
}

/* Insert a C string into list */
SLN StringList_Converte_StringArrayToList(const char* chaine, SLN L) {
    int i = 0;
    while (chaine[i] != '\0') {
        L = IIT(chaine[i], L);
        if (L == NULL) break;
        i++;
    }
    return L;
}

/* Procedural insert string */
void StringList_Procedural_Converte_StringArrayToList(const char* chaine, SLN* L) {
    SLN old = *L;
    *L = ISTR(chaine, *L);
    if (*L == NULL) *L = old;
}

/* Compare list to string */
int StringList_Compare(SLN list, const char* ref) {
    int i = 0;
    while (list != NULL && ref[i] != '\0') {
        if (list->content != ref[i]) return 0;
        list = list->next;
        i++;
    }
    return (list == NULL && ref[i] == '\0');
}

/* Display list content */
void StringList_Display(SLN l) {
    while (l != NULL) {
        putchar(l->content);
        l = l->next;
    }
}

/* Get string list length */
unsigned int StringList_Len(SLN l) {
    unsigned int count = 0;
    while (l != NULL) {
        ++count;
        l = l->next;
    }
    return count;
}
