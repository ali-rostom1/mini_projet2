#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CONTACTS 100


typedef struct{
    char *name;
    char *telephone_number;
    char *email;
}Contact;

void addContact();
void editContact(Contact contact1);
void deleteContact(Contact contact1);
void displayContacts();
void searchContact();

bool checktracker();
void clearBuffer();

Contact Repertoire[MAX_CONTACTS];
int tracker=0;

int main(){
    int choice;
    do{
        printf("\n************ Menu ************\n");
        printf("1. Add a contact to the repertoire.\n");
        printf("2. edit a contact.\n");
        printf("3. delete a contact.\n");
        printf("4. display all contacts.\n");
        printf("6. search contact.\n");
        printf("7. EXIT.\n");
        printf("type an option: ");
        while(scanf("%d",&choice)!=1 || choice<1 || choice>7){
            printf("\nfrom 1 to 7: ");
            clearBuffer();
        }
        switch(choice){
            
        }
    }while(choice!=7);

}

bool isEmpty(int nb){
    if(nb==0){
        printf("\nRepertoire is empty.\n");
        return true;
    }else return false;
}
bool isFull(int nb){
    if(nb>MAX_CONTACTS-1){
        printf("\nRepertoire is at maximum limit.\n");
        return true;
    }else return false;
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void addContact(){
    if()
    int nb;
    printf("\nHow many contacts do you wanna add in the repertoire: ");
    scanf(" %d",&nb);
    clearBuffer();
    for(int i=tracker;i<tracker+nb;i++){
        printf("\n\tContact number %d",i+1);
        printf("\n\tType the Contact's name : ");
        scanf(" %[^\n]",repertoire[i].name);
        printf("\n\ttype the Contact's phone number : ");
        scanf(" %[^\n]",repertoire[i].telephone_number);
        printf("\n\ttype the Contact's email : ");
        scanf(" %[^\n]",repertoire[i].email);
    }
    tracker+=nb;
    printf("\n\t \t%d contact(s) added !");
}