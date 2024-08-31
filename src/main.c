#include "def.h"

int main(int argc, char** argv) {
    // Variable Declarations
    // int cents;
    // int rtv;

    // Get inputs
    // rtv = scanf("%d", &cents);

    // if (!rtv) {
    //     return EXIT_FAILURE;
    // }

    get_combinations(atoi(argv[1]));
    return EXIT_SUCCESS;
}

void get_combinations(int cents) {
    // Variable Declarations
    int money_arr[4] = {1, 1, 1, 1};
    int temp_cents_1;
    int temp_cents_2;
    int temp_cents_3;

    money_arr[0] = cents / QUARTER; // Get number of quarters

    do {
        temp_cents_1 = cents - QUARTER * money_arr[0];
        money_arr[1] = temp_cents_1 / DIME; // Get number of dimes

        while (money_arr[1] >= 0) {
            temp_cents_2 = temp_cents_1 - DIME * money_arr[1];
            money_arr[2] = temp_cents_2 / NICKEL; // Get number of nickels

            while (money_arr[2] >= 0) {
                temp_cents_3 = temp_cents_2 - NICKEL * money_arr[2];
                money_arr[3] = temp_cents_3 / PENNY; // Get number of pennies
                printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", money_arr[0], money_arr[1], money_arr[2], money_arr[3]);
                money_arr[2]--;
            }
            money_arr[1]--;
        }
        money_arr[0]--;
    } while (money_arr[0] >= 0);
}