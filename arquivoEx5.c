#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the file for reading
    FILE *file = fopen("shopping_list.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char name[100];
    int quantity;
    float unit_price;
    float total_value = 0.0;
    int line = 1;

    printf("Shopping List:\n");
    // Read each line of the file and extract the item details
    while (fscanf(file, "%s %d %f", name, &quantity, &unit_price) != EOF /* End Of File */) {
        // Calculate the subtotal for each item
        float subtotal = quantity * unit_price;
        // Print item details and subtotal for the current line
        printf("%d) %s: %d * %.2f = %.2f\n", line, name, quantity, unit_price, subtotal);
        // Add the current item's subtotal to the total value
        total_value += subtotal;
        // Move to the next line
        line++;
    }

    // Close the file
    fclose(file);

    // Print the total value of the shopping
    printf("The total value of the shopping is $%.2f\n", total_value);

    return 0;
}