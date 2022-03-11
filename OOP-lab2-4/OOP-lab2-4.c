#include <stdio.h>
#include "cheltuiala.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "validator.h"

void tests() {
    /*
    Run tests
    */
    test_get_cheltuieli();
    test_get_lungime();
    test_add_cheltuiala();
    test_validate();
    test_get_cheltuieli_srv();
    test_get_lungime_srv();
    test_add_cheltuiala_srv();
    test_find_cheltuieli();
    test_mod();
}

void buget() {
    generate();
    while (1) {
        print_menu();
        int cmd = 0;
        printf("\nGive command: ");
        scanf_s("%d", &cmd);
        if (cmd == 1) {
            add_ui();
        }
        else if (cmd == 2) {
            mod_ui();
        }
        else if (cmd == 3) {
            filtrare_prop();
        }
        else if (cmd == 4) {
            print_list();
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


