#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define MAX_CONTACTS 100
#define MAX_STRING_LEN 50

typedef struct{
    char *name;
    char *telephone_number;
    char *email;
}Contact;

void addContact();
void editContact();
void deleteContact();
void displayContacts();
void searchContact();

bool checktracker();
void clearBuffer();
void displayContact(Contact contact);
void freeContacts();

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
        printf("5. search contact.\n");
        printf("6. EXIT.\n");
        printf("type an option: ");
        while(scanf("%d",&choice)!=1 || choice<1 || choice>6){
            printf("\ninvalid input,from 1 to 6: ");
            clearBuffer();
        }
        switch(choice){
            case 1:
                addContact();
                break;
            case 2:
                editContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                searchContact();
                break;
            case 6:
                freeContacts();
                printf("\nExiting ....");
                Sleep(2000);
                exit(0);
        }
    }while(choice!=6);

}

bool isEmpty(){
    if(tracker==0){
        printf("\nRepertoire is empty.\n");
        return true;
    }else return false;
}
bool isFull(int nb){
    if(nb>MAX_CONTACTS){
        printf("\nRepertoire is at maximum limit.\n");
        return true;
    }else return false;
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void displayContact(Contact contact){
    printf("\n\tContact's name: %s",contact.name);
    printf("\n\tContact's phone number: %s",contact.telephone_number);
    printf("\n\tContact's email: %s",contact.email);
}
void addContact(){
    int nb;
    printf("\nHow many contacts do you wanna add in the repertoire: ");
    scanf(" %d",&nb);
    clearBuffer();
    if(isFull(nb+tracker)) return;
    for(int i=tracker;i<tracker+nb;i++){
        Repertoire[i].name = (char *)malloc(MAX_STRING_LEN * sizeof(char));
        Repertoire[i].telephone_number = (char *)malloc(MAX_STRING_LEN * sizeof(char));
        Repertoire[i].email = (char *)malloc(MAX_STRING_LEN * sizeof(char));
        printf("\n\tContact number %d",i+1);
        printf("\n\tType the Contact's name : ");
        scanf(" %[^\n]",Repertoire[i].name);
        printf("\n\ttype the Contact's phone number : ");
        scanf(" %[^\n]",Repertoire[i].telephone_number);
        printf("\n\ttype the Contact's email : ");
        scanf(" %[^\n]",Repertoire[i].email);
    }
    tracker+=nb;
    printf("\n\t \t%d contact(s) added !",nb);
    Sleep(2000);
}

void displayContacts(){
    if(isEmpty()) return;
    for(int i=0;i<tracker;i++){
        printf("\n   Contact number %d : ",i+1);
        displayContact(Repertoire[i]);
    }
    Sleep(2000);
}

void editContact(){
    if(isEmpty()) return;
    int nb;
    displayContacts();
    printf("\ntype which contact you want to edit (number): ");
    while (scanf("%d", &nb) != 1 || nb < 1 || nb > tracker) {
        printf("\nPlease enter a valid contact number (1 to %d): ", tracker);
        clearBuffer();
    }
    clearBuffer();
    printf("\n\tType the Contact's name : ");
    scanf(" %[^\n]",Repertoire[nb-1].name);
    printf("\n\ttype the Contact's phone number : ");
    scanf(" %[^\n]",Repertoire[nb-1].telephone_number);
    printf("\n\ttype the Contact's email : ");
    scanf(" %[^\n]",Repertoire[nb-1].email);
    printf("\n\t \tcontact %d edited successfully !",nb);
    Sleep(2000);
}

void deleteContact(){
    int nb;
    char ans;

    if(isEmpty()) return;

    displayContacts();

    printf("\ntype which contact you want to delete (number): ");
    while (scanf("%d", &nb) != 1 || nb < 1 || nb > tracker) {
        printf("\nPlease enter a valid contact number (1 to %d): ", tracker);
        clearBuffer();
    }
    clearBuffer();

    displayContact(Repertoire[nb-1]);

    printf("\nare you sure you want to delete this contact?(y/n)");
    while (scanf(" %c", &ans) != 1 || (tolower(ans) != 'y' && tolower(ans) !='n')) {
        printf("\nPlease enter a valid answer Y OR N: ");
        clearBuffer();
    }
    clearBuffer();

    if(tolower(ans)=='y'){
        free(Repertoire[nb-1].name);
        free(Repertoire[nb-1].telephone_number);
        free(Repertoire[nb-1].email);

        for(int i=nb-1;i<tracker-1;i++){
            strcpy(Repertoire[i].name,Repertoire[i+1].name);
            strcpy(Repertoire[i].telephone_number,Repertoire[i+1].telephone_number);
            strcpy(Repertoire[i].email,Repertoire[i+1].email);
        }
        tracker--;
        Repertoire[tracker].name = NULL;
        Repertoire[tracker].telephone_number = NULL;
        Repertoire[tracker].email = NULL;
        printf("\n\t \tcontact %d deleted successfully !",nb);

    }else printf("\n\tDeletion canceled.");
    Sleep(2000);
}

void searchContact(){
    int hit=0;
    char name[MAX_STRING_LEN];  
    if(isEmpty()) return;


    printf("\ntype the name of the contact you want to search: ");
    scanf(" %[^\n]",name);

    for(int i=0;i<tracker;i++){
        if(strcmp(Repertoire[i].name,name)==0){
            printf("\n\tContact number %d :",i+1);
            displayContact(Repertoire[i]);
            hit++;
        }
    }
    printf("\n%d contact(s) found !",hit);
    Sleep(2000);
}
void freeContacts(){
    for(int i=0;i<tracker;i++){
        free(Repertoire[i].name);
        free(Repertoire[i].telephone_number);
        free(Repertoire[i].email);
    }
}
