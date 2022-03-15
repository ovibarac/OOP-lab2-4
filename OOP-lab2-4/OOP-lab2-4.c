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
    testAddCh();
    test_mod();
    test_sort();


    //test_add_cheltuiala_srv();
    //test_find_cheltuieli();
    
}

void buget() {
    Buget b = createBuget();
    generate(&b);
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
        else if (cmd == 5) {
            filtrare_prop(&b);
        }
        else if (cmd == 6) {
            sortare_ui(&b);
        }
        else if (cmd == 0) {
            return;
        }
        printf("\n");
    }
}

int main()
{
    tests();
    buget();
}


