#include <stdio.h>
#include "cheltuiala.h"
#include "service.h"
#include "ui.h"
#include "validator.h"
#include "Lista.h"

void tests() {
    /*
    Run tests
    */
    testCreateDestroy();
    testCreateList();
    test_validate();
    test_delete_cheltuiala();


    //test_add_cheltuiala_srv();
    //test_find_cheltuieli();
    //test_mod();
}

void buget() {
    Buget b = createBuget();
    //generate();
    while (1) {
        print_menu(&b);
        int cmd = 0;
        printf("\nGive command: ");
        scanf_s("%d", &cmd);
        if (cmd == 1) {
            add_ui(&b);
        }
        else if (cmd == 2) {
            mod_ui(&b);
        }
        else if (cmd == 3) {
            delete_ui(&b);
        }
        else if (cmd == 4) {
            print_list(&b);
        }
        /*
        else if (cmd == 3) {
            filtrare_prop(&b);
        }*/
        /*
        else if (cmd == 0) {
            return;
        }*/
        printf("\n");
    }
}

int main()
{
    tests();
    buget();
}


