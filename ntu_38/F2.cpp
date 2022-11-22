#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct 
{
int roomID;     /*1-5*/
int status;     /*available or taken*/
char customerName[20];
   } Room;

void roomstatus(Room *ro,int size);
void readin(Room *ro);
void removeRoom(Room *ro);
void search(Room *ro, int size, char *target);
int size =0;

int main(){
    
    Room s[MAX];
    char t[20], *p;
    int choice, i;
    char dummychar;

    for (i=0;i<MAX;i++){
        s[i].status = 0;
    }

    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
    
    do{
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    
    switch (choice) {

        case 1:         /*listOccupiedRooms()*/
        roomstatus(s,size);         
        break;

        case 2:
        printf("assignRoom():\n");
        scanf("%c", &dummychar);
        readin(s);
        break;

        case 3:
        printf("removeRoom():\n");
        removeRoom(s);
        break;

        case 4:         /*findCustomer()*/
        printf("findCustomer():\n");
        scanf("%c", &dummychar);
        printf("Enter customer name:\n");
        fgets(t, 20, stdin);
        if(p=strchr(t, '\n')) *p = '\0';
        search(s,size,t);
        break;

        }
    } while (choice < 5);
    return 0;
}

void roomstatus(Room *ro, int size){

    int i;

    printf("listOccupiedRooms():\n");
    if(size==0)
        printf("The hotel is empty\n");

    else{
        for(i=0; i<MAX; i++){

            if (ro[i].status == 1){
            printf("roomID: %d\n", i+1);
            printf("customer name: %s\n", ro[i].customerName);
            }

            else{
            continue;
            }
        }
    }
}

void readin(Room *ro){
    int test = 1, i=0, roomID, id;
    char customerName[20], dummy[80], *p;
    if (size == 5){
        printf("The hotel is full \n");
        test = 0;
        return;
    }

    while (test){
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &id);
        scanf("%c", dummy);

        if (id<=0 || id >5)
        continue;
        
        else if (ro[id-1].status == 0) {
        break; }

        else if (ro[id-1].status == 1){
        printf("Occupied! Enter another roomID\n"); 
        continue; 
        }
    }

    printf("Enter customer name: \n");
    fgets(customerName, 20, stdin);
    if (p=strchr(customerName, '\n')) *p ='\0';
    if (ro[id-1].status == 0){
        ro[id-1].status = 1;
        printf("The room has been assigned successfully\n");
        size +=1;
        strcpy(ro[id-1].customerName, customerName);
        }
    }

void removeRoom(Room *ro){
int no, id;
char dummy[80];

    if (size == 0){
        printf("All the rooms are empty\n");
        return;
    }

    while (1){
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &id);
        scanf("%c", dummy);

    if (id<=0 || id >5)
        continue;

    else if (ro[id-1].status == 0){
        printf("Empty! Enter another roomID for removal\n");
        continue;
    }
        
    else if (ro[id-1].status == 1){
        ro[id-1].status = 0;
        printf("Removal is successful\n");
        size -=1;

        break;
            }            
        }
    }

void search(Room *ro, int size, char *target){

    int i;
    for (i=0; i<MAX; i++){
        if(strcasecmp(ro[i].customerName,target)==0){
            printf("The target customer name is found\n");
            printf("roomID: %d/n", ro[i].roomID);
            printf("customer name: %s\n", ro[i].customerName);
            return;
        }
    }
        printf("The target customer name is not found\n");
}
