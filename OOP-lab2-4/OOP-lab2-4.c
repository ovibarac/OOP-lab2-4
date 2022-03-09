#include <stdio.h>
#include "cheltuiala.h"
#include "repo.h"
#include "service.h"
#include "ui.h"

int main()
{
    /*cheltuiala* cheltuieli = get_list();
    add(1, 20, "altele");
    printf("%d", (*cheltuieli).zi);
    printf("%d", (*cheltuieli).suma);
    printf("%s", (*cheltuieli).tip);
    add(2, 40, "caca");
    printf("%d", (*(cheltuieli + 1)).zi);
    printf("%d", (*(cheltuieli + 1)).suma);
    printf("%s", (*(cheltuieli+ 1)).tip);
    printf("%d", get_size());*/
    test_get_cheltuieli();
    test_get_lungime();
    test_add_cheltuiala();

    run();
}
