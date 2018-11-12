#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size;

typedef struct{
    char name[200];
    char address[200];
}person;

person *contacts;

void add(char *name, char *address){
    ++size;
    contacts = realloc(contacts, size*sizeof(person));
    strcpy(contacts[size - 1].name, name);
    strcpy(contacts[size - 1].address, address);
}

int find(char *name){
    for(int i = 0; i < size; ++i)
        if(strcmp(name, contacts[i].name) == 0) return i;
    return -1;    
}

int is_in(char *name){
    if(find(name) > -1) return 1;
    return 0;
}

char* find_address(char *name){
    int pos = find(name);
    if(pos == -1)   return "error\n";
    return contacts[pos].address;
}

int remove_name(char *name){
    int pos = find(name);
    if(pos == -1)   return 1;
    strcpy(contacts[pos].name ,"empty");
    return 0;
}

void destroy(){
    free(contacts);
}

int main(){
    return 0;
}
