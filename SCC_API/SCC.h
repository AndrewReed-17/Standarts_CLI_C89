#ifndef SCC_H
#define SCC_H

void Set_File_Info(const char* file_Path);

void Display_Properties_Program(void);



/* Structure de la liste */

struct String_List {
    struct String_List *next;
    char content;
};

typedef struct String_List* SLN;
typedef struct String_List  SLC;

/* Fonctions de manipulation */

SLN StringList_Insert_InHead(char element, SLN L);
void StringList_Procedural_Insert_InHead(char element, SLN* L);

SLN StringList_Insert_InTails(char element, SLN L);
void StringList_Procedural_Insert_InTails(char element, SLN* L);

SLN StringList_Delet_InHead(SLN L);
void StringList_Procedural_DeletInHead(SLN* L);

SLN StringList_Delet_InTails(SLN L);
void StringList_Procedural_Delet_InTails(SLN* L);

void StringList_Delet(SLN* L);

SLN StringList_Converte_StringArrayToList(const char* chaine, SLN L);
void StringList_Procedural_Converte_StringArrayToList(const char* chaine, SLN* L);

int StringList_Compare(SLN list, const char* ref);
void StringList_Display(SLN l);

unsigned int StringList_Len(SLN l);

#endif
