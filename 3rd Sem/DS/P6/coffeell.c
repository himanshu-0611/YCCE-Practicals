#include<stdio.h>
#include<stdlib.h>

typedef struct coffee {
    int id;
    char name[30];
    char c_brand[30];
    int bill;
    int n_ord;
    struct coffee *next;
}*CS;

CS getnode() {
    CS new1;
    new1 = (struct coffee*)malloc(sizeof(struct coffee));
    new1->next = NULL;
    return new1;
}

int main()
{
    int ch, res, c, new, prev, num = 0, s, f=0, try = 0, i = 0, j = 0, cnt = 0;
    CS head = NULL, temp, new1, t1, t2, t3;
    do {
        printf("\n1.Add Customer (will be added in Alphabetical Order of names)\n2.Display\n3.Search\n4.Delete Customers with duplicate id");
        printf("\nChoose any one : ");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
        //add
            if(head == NULL) {
                head = getnode();
                printf("\nEnter Customer id, name, coffee brand ordered, number of coffee ordered, total bill : ");
                scanf("%d %s %s %d %d", &head->id, head->name, head->c_brand, &head->n_ord, &head->bill);
                temp = head;
                num++;
            }
            else {
                new1 = getnode();
                printf("\nEnter Customer id, name, coffee brand ordered, number of coffee ordered, total bill : ");
                scanf("%d %s %s %d %d", &new1->id, new1->name, new1->c_brand, &new1->n_ord, &new1->bill);
                num++;

                if(num == 2 || new1->name[0] < head->name[0]) {
                    new = new1->name[0];
                    if(head->name[0] > new) {
                        t1 = head;
                        head = new1;
                        head->next = t1;
                    }
                    else {
                        t1 = head;
                        t2 = head->next;
                        head->next = new1;
                        new1->next = t2;
                    }
                }
                if(num > 2) {
                    cnt = 0;
                    t1 = head;
                    new = new1->name[0];
                    while(t1->next != NULL) {
                        if(t1->name[0] < new && new < t1->next->name[0]) {
                        t2 = t1->next;
                        t1->next = new1;
                        new1->next = t2;
                        cnt++;
                        break;
                    }
                    t1 = t1->next;
                    }
                    if(cnt == 0) {
                        t1 = head;
                        while(t1->next != NULL) {
                            t1 = t1->next;
                        }
                        t1->next = new1;
                    }
                }
            }
        break;
        case 2:
        //display
            temp = head;
            c = 1;
            while(temp != NULL) {
                printf("\nCustomer %d\nCustomer id: %d\nCustomer Name: %s\nCoffee brand: %s\nNo of Coffee ordered: %d\nTotal bill: %d\n\n", c, temp->id, temp->name, temp->c_brand, temp->n_ord, temp->bill);
                temp = temp->next;
                c++;
            }
        break;
        case 3:
        //search
            temp = head;
            printf("\nEnter customer id : ");
            scanf("%d", &s);
            while(temp != NULL) {
                if(s == temp->id) {
                    printf("\nCustomer %d\nCustomer id: %d\nCustomer Name: %s\nCoffee brand: %s\nNo of Coffee ordered: %d\nTotal bill: %d\n\n", c, temp->id, temp->name, temp->c_brand, temp->n_ord, temp->bill);
                    f++;
                }
                temp = temp->next;
                if(temp == NULL && f == 0) {
                    printf("\nEnter correct id\n");
                }
            }
        break;
        case 4:
        //delete duplicate
            temp = head;
			while(temp->next != NULL) {
				t1 = temp;
				while(t1 != NULL) {
					if(t1->next != NULL && temp->id == t1->next->id) {
						t2 = t1->next;
						t1->next = t2->next;
						free(t2);
					}
					t1 = t1->next;
				}
				temp = temp->next;
			}
            printf("\nDuplicated id customers successfully deleted, you can display\n");
        break;
        default:
            exit(0);
    }
    printf("\nDo you want to continue : ");
    scanf("%d", &res);
    }while(res == 1);
    return 0;
}
    