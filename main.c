#include <stdio.h>
#include <string.h> // String functions
#include <ctype.h> // Testing and Mapping characters

char decision[5]; // Not in structure as it does not have properties related to personalInfo, global just because

struct personalInfo {
    float unitsUsePerMonth, price;
    char area[10], houseNumber[5], email[50], phoneNumber[15], meterNumber[15], name[50];
};

void createFiles(struct personalInfo s1);

int main() {
    struct personalInfo s1;
    printf("Enter your full name: ");
    scanf("%[^\n]s", s1.name); // [^\n] stops scanf from terminating upon a space, newline, whitespace
//    fgets(s1.name, sizeof(s1.name), stdin);
    printf("Enter your phone number: ");
//    fgets( s1.phoneNumber, sizeof(s1.phoneNumber), stdin); // The space before the % is for scanf to ignore any number of
    scanf(" %[^\n]s", s1.phoneNumber);                                   // whitespace chars, so it ignores left over newlines
    printf("Enter your email address: ");
    scanf("%s", s1.email);
//    printf("%s", s1.email);
    printf("Enter your house number: ");
    scanf("%s", s1.houseNumber);
    printf("Enter your meter number: ");
    scanf("%s", s1.meterNumber);
//    printf("%s", s1.meterNumber);
    printf("Enter your units use per month: ");
    scanf("%f", &s1.unitsUsePerMonth);
//    printf("%f", s1.unitsUsePerMonth);
    printf("Enter your area location, Rural or Urban: ");
    scanf("%s", s1.area);
//    printf("%s", s1.area);


    for (int i = 0; i < strlen(s1.area); i++) {
        s1.area[i] = tolower(s1.area[i]);
    }

    while (strcmp(s1.area, "urban") != 0 && strcmp(s1.area, "rural") != 0) {
        printf("Incorrect Area, please enter 'Rural' or 'Urban': ");
        scanf("%s", s1.area);
    }

    if (strcmp(s1.area, "urban") == 0) {

        if (s1.unitsUsePerMonth >= 0 && s1.unitsUsePerMonth < 50.5) {
            s1.price = 3.00 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        } else if (s1.unitsUsePerMonth >= 50.5 && s1.unitsUsePerMonth < 100.5) {
            s1.price = 3.75 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        } else if (s1.unitsUsePerMonth >= 100.5) {
            s1.price = 4.50 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        }
    }

    else if (strcmp(s1.area, "rural") == 0) {

        if (s1.unitsUsePerMonth >= 0 && s1.unitsUsePerMonth < 50.5) {
            s1.price = 2.00 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        } else if (s1.unitsUsePerMonth >= 50.5 && s1.unitsUsePerMonth < 100.5) {
            s1.price = 2.75 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        } else if (s1.unitsUsePerMonth >= 100.5) {
            s1.price = 4.15 * s1.unitsUsePerMonth;
//            printf("Price paid this month: £%.2f", s1.price);
        }
    }
    /*else {
        printf("Incorrect Area");
        return 0;
    }*/



    /*
    if (strcmp(s1.area, "urban") == 0 || strcmp(s1.area, "Urban") == 0 ||
        strcmp(s1.area, "URBAN") == 0) //Compares strings
    {
        if (s1.unitsUsePerMonth >= 0 && s1.unitsUsePerMonth < 50.5) {
            s1.price = 3.00 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

        else if (s1.unitsUsePerMonth >= 50.5 && s1.unitsUsePerMonth < 100.5) {
            s1.price = 3.75 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

        else if (s1.unitsUsePerMonth >= 100.5) {
            s1.price = 4.50 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

    }

    else if (strcmp(s1.area, "rural") == 0 || strcmp(s1.area, "Rural") == 0 ||
             strcmp(s1.area, "RURAL") == 0) {

        if (s1.unitsUsePerMonth >= 0 && s1.unitsUsePerMonth < 50.5) {
            s1.price = 2.00 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

        else if (s1.unitsUsePerMonth >= 50.5 && s1.unitsUsePerMonth < 100.5) {
            s1.price = 2.75 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

        else if (s1.unitsUsePerMonth >= 100.5) {
            s1.price = 4.15 * s1.unitsUsePerMonth;
            printf("Price paid this month: £%.2f", s1.price);
        }

    }*/
    printf("\n\n");
    for (int j = 0; j <= 40; j++) {
        printf("-");
    }
    printf("\n");
    printf("Electric Bill: \n\n");
    printf("Name: %s\n", s1.name);
    printf("Phone Number: %s\n", s1.phoneNumber);
    printf("Email: %s\n", s1.email);
    printf("House Number: %s\n", s1.houseNumber);
    printf("Meter Number: %s\n", s1.meterNumber);
    printf("Units consumed: %.2f kW\n", s1.unitsUsePerMonth);
//    printf("Area: %s\n", s1.area);
    s1.area[0] = toupper(s1.area[0]);
    printf("Area: %s\n", s1.area);
    printf("Price to be paid this month: £%.2f\n", s1.price);
    for (int j = 0; j <= 40; j++) {
        printf("-");
    }
    printf("\n\n\n");

    printf("Would you like to save your electric bill as a .txt file? ");
    scanf("%s", decision);

    for (int i = 0; i < strlen(decision); i++) {
        decision[i] = tolower(decision[i]);
    }

    if (strcmp(decision, "yes") == 0 || strcmp(decision, "y") == 0) {
        createFiles(s1);
        printf("Energy_Bill.txt was successfully created");
    }

    return 0;
}

void createFiles(struct personalInfo s1) {

    FILE *pFile;
    pFile = fopen("Energy_Bill.txt", "w");
    if (pFile != NULL) {
//    s1.name, s1.phoneNumber, s1.email, s1.houseNumber, s1.meterNumber, s1.unitsUsePerMonth, s1.area, s1.price
        fprintf(pFile, "Electric Bill: \n\n");
        fprintf(pFile, "Name: %s\n", s1.name);
        fprintf(pFile, "Phone Number: %s\n", s1.phoneNumber);
        fprintf(pFile, "Email: %s\n", s1.email);
        fprintf(pFile, "House Number: %s\n", s1.houseNumber);
        fprintf(pFile, "Meter Number: %s\n", s1.meterNumber);
        fprintf(pFile, "Units consumed: %.2f kW\n", s1.unitsUsePerMonth);
        fprintf(pFile, "Area: %s\n", s1.area);
        fprintf(pFile, "Price to be paid this month: £%.2f", s1.price);
        fclose(pFile);
//    return;
    }
    else {
        printf("Error Accessing Energy_Bill.txt\n");
    }

}