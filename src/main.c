#include "def.h"

int main(void) {
    // Variable Declarations
    int cents;
    int rtv;

    // Get inputs
    printf("Enter the number of cents -> ");
    rtv = scanf("%d", &cents);

    if (!rtv) {
        return EXIT_FAILURE;
    }

    get_combination(cents);
    return EXIT_SUCCESS;
}

void get_combination(int cents) {
    // Variable Declarations
    int money_arr[4];
    int temp_cents_1 = cents;
    int temp_cents_2;
    int temp_cents_3;

    // Get number of quarters
    while (temp_cents_1 > 0) {
        money_arr[0] = temp_cents_1 / QUARTER;
        temp_cents_1 -= QUARTER * money_arr[0];

        // Get number of dimes
        while (temp_cents_1 > 0) {
            money_arr[1] = temp_cents_1 / DIME;
            temp_cents_2 = temp_cents_1 - DIME * money_arr[1];

            // Get number of nickels
            while (temp_cents_2 > 0) {
                money_arr[2] = temp_cents_2 / NICKEL;
                temp_cents_3 = temp_cents_2 - NICKEL * money_arr[2];

                // Get number of pennies
                while (temp_cents_3 > 0) {
                    money_arr[3] = temp_cents_3 / PENNY;
                    printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennies(s)\n", money_arr[0], money_arr[1], money_arr[2], money_arr[3]);
                }
            }
        }
    }
}