#include <stdio.h>
#include <string.h>

#define MAX_CROPS 100
#define MAX_SCHEDULES 100
#define MAX_LIVESTOCK 100
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char type[50];
    float area; // in acres
} Crop;

typedef struct {
    char cropName[50];
    char harvestDate[20]; // in YYYY-MM-DD format
} HarvestSchedule;

typedef struct {
    char type[50];
    int count;
    char healthStatus[50];
} Livestock;

typedef struct {
    char description[100];
    float amount; // in dollars
    char date[20]; // in YYYY-MM-DD format
} Expense;
void manageCropPlanting(Crop crops[], int *cropCount);
void addCrop(Crop crops[], int *cropCount);
void viewCrops(Crop crops[], int cropCount);
void deleteCrop(Crop crops[], int *cropCount);
void saveCropsToFile(Crop crops[], int cropCount);
void loadCropsFromFile(Crop crops[], int *cropCount);

void manageHarvestSchedules(HarvestSchedule schedules[], int *scheduleCount);
void addHarvestSchedule(HarvestSchedule schedules[], int *scheduleCount);
void viewHarvestSchedules(HarvestSchedule schedules[], int scheduleCount);
void deleteHarvestSchedule(HarvestSchedule schedules[], int *scheduleCount);
void saveHarvestSchedulesToFile(HarvestSchedule schedules[], int scheduleCount);
void loadHarvestSchedulesFromFile(HarvestSchedule schedules[], int *scheduleCount);

void manageLivestockRecords(Livestock livestock[], int *livestockCount);
void addLivestock(Livestock livestock[], int *livestockCount);
void viewLivestock(Livestock livestock[], int livestockCount);
void deleteLivestock(Livestock livestock[], int *livestockCount);
void saveLivestockToFile(Livestock livestock[], int livestockCount);
void loadLivestockFromFile(Livestock livestock[], int *livestockCount);

void manageFarmExpenses(Expense expenses[], int *expenseCount);
void addExpense(Expense expenses[], int *expenseCount);
void viewExpenses(Expense expenses[], int expenseCount);
void deleteExpense(Expense expenses[], int *expenseCount);
void saveExpensesToFile(Expense expenses[], int expenseCount);
void loadExpensesFromFile(Expense expenses[], int *expenseCount);
int main() {
    Crop crops[MAX_CROPS];
    int cropCount = 0;

    HarvestSchedule schedules[MAX_SCHEDULES];
    int scheduleCount = 0;

    Livestock livestock[MAX_LIVESTOCK];
    int livestockCount = 0;

    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;

    int choice;

    do {
        printf("\nFarm Management System\n");
        printf("1. Manage Crop Planting\n");
        printf("2. Manage Harvest Schedules\n");
        printf("3. Manage Livestock Records\n");
        printf("4. Manage Farm Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageCropPlanting(crops, &cropCount);
                break;
            case 2:
                manageHarvestSchedules(schedules, &scheduleCount);
                break;
            case 3:
                manageLivestockRecords(livestock, &livestockCount);
                break;
            case 4:
                manageFarmExpenses(expenses, &expenseCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
void manageCropPlanting(Crop crops[], int *cropCount) {
    int choice;
    do {
        printf("\nManage Crop Planting\n");
        printf("1. Add Crop\n");
        printf("2. View Crops\n");
        printf("3. Delete Crop\n");
        printf("4. Save Crops to File\n");
        printf("5. Load Crops from File\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCrop(crops, cropCount);
                break;
            case 2:
                viewCrops(crops, *cropCount);
                break;
            case 3:
                deleteCrop(crops, cropCount);
                break;
            case 4:
                saveCropsToFile(crops, *cropCount);
                break;
            case 5:
                loadCropsFromFile(crops, cropCount);
                break;
            case 6:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
void addCrop(Crop crops[], int *cropCount) {
    if (*cropCount >= MAX_CROPS) {
        printf("Maximum crop limit reached.\n");
        return;
    }

    printf("Enter crop name: ");
    scanf("%s", crops[*cropCount].name);
    printf("Enter crop type: ");
    scanf("%s", crops[*cropCount].type);
    printf("Enter crop area (in acres): ");
    scanf("%f", &crops[*cropCount].area);

    (*cropCount)++;
    printf("Crop added successfully.\n");
}

void viewCrops(Crop crops[], int cropCount) {
    if (cropCount == 0) {
        printf("No crops available.\n");
        return;
    }

    printf("Crop List:\n");
    for (int i = 0; i < cropCount; i++) {
        printf("Crop %d:\n", i + 1);
        printf("Name: %s\n", crops[i].name);
        printf("Type: %s\n", crops[i].type);
        printf("Area: %.2f acres\n", crops[i].area);
    }
}

void deleteCrop(Crop crops[], int *cropCount) {
    if (*cropCount == 0) {
        printf("No crops to delete.\n");
        return;
    }

    int index;
    printf("Enter the crop number to delete (1 to %d): ", *cropCount);
    scanf("%d", &index);

    if (index < 1 || index > *cropCount) {
        printf("Invalid crop number.\n");
        return;
    }

    for (int i = index - 1; i < *cropCount - 1; i++) {
        crops[i] = crops[i + 1];
    }
    (*cropCount)--;
    printf("Crop deleted successfully.\n");
}

void saveCropsToFile(Crop crops[], int cropCount) {
    FILE *file = fopen("crops.dat", "wb");
    if (!file) {
        printf("Could not open file to save crops.\n");
        return;
    }

    fwrite(&cropCount, sizeof(int), 1, file);
    fwrite(crops, sizeof(Crop), cropCount, file);
    fclose(file);

    printf("Crops saved to file successfully.\n");
}

void loadCropsFromFile(Crop crops[], int *cropCount) {
    FILE *file = fopen("crops.dat", "rb");
    if (!file) {
        printf("Could not open file to load crops.\n");
        return;
    }

    fread(cropCount, sizeof(int), 1, file);
    fread(crops, sizeof(Crop), *cropCount, file);
    fclose(file);

    printf("Crops loaded from file successfully.\n");
}
void manageHarvestSchedules(HarvestSchedule schedules[], int *scheduleCount) {
    int choice;
    do {
        printf("\nManage Harvest Schedules\n");
        printf("1. Add Harvest Schedule\n");
        printf("2. View Harvest Schedules\n");
        printf("3. Delete Harvest Schedule\n");
        printf("4. Save Harvest Schedules to File\n");
        printf("5. Load Harvest Schedules from File\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addHarvestSchedule(schedules, scheduleCount);
                break;
            case 2:
                viewHarvestSchedules(schedules, *scheduleCount);
                break;
            case 3:
                deleteHarvestSchedule(schedules, scheduleCount);
                break;
            case 4:
                saveHarvestSchedulesToFile(schedules, *scheduleCount);
                break;
            case 5:
                loadHarvestSchedulesFromFile(schedules, scheduleCount);
                break;
            case 6:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
void addHarvestSchedule(HarvestSchedule schedules[], int *scheduleCount) {
    if (*scheduleCount >= MAX_SCHEDULES) {
        printf("Maximum harvest schedule limit reached.\n");
        return;
    }

    printf("Enter crop name: ");
    scanf("%s", schedules[*scheduleCount].cropName);
    printf("Enter harvest date (YYYY-MM-DD): ");
    scanf("%s", schedules[*scheduleCount].harvestDate);

    (*scheduleCount)++;
    printf("Harvest schedule added successfully.\n");
}

void viewHarvestSchedules(HarvestSchedule schedules[], int scheduleCount) {
    if (scheduleCount == 0) {
        printf("No harvest schedules available.\n");
        return;
    }

    printf("Harvest Schedule List:\n");
    for (int i = 0; i < scheduleCount; i++) {
        printf("Schedule %d:\n", i + 1);
        printf("Crop Name: %s\n", schedules[i].cropName);
        printf("Harvest Date: %s\n", schedules[i].harvestDate);
    }
}

void deleteHarvestSchedule(HarvestSchedule schedules[], int *scheduleCount) {
    if (*scheduleCount == 0) {
        printf("No harvest schedules to delete.\n");
        return;
    }

    int index;
    printf("Enter the harvest schedule number to delete (1 to %d): ", *scheduleCount);
    scanf("%d", &index);

    if (index < 1 || index > *scheduleCount) {
        printf("Invalid harvest schedule number.\n");
        return;
    }

    for (int i = index - 1; i < *scheduleCount - 1; i++) {
        schedules[i] = schedules[i + 1];
    }
    (*scheduleCount)--;
    printf("Harvest schedule deleted successfully.\n");
}

void saveHarvestSchedulesToFile(HarvestSchedule schedules[], int scheduleCount) {
    FILE *file = fopen("schedules.dat", "wb");
    if (!file) {
        printf("Could not open file to save harvest schedules.\n");
        return;
    }

    fwrite(&scheduleCount, sizeof(int), 1, file);
    fwrite(schedules, sizeof(HarvestSchedule), scheduleCount, file);
    fclose(file);

    printf("Harvest schedules saved to file successfully.\n");
}

void loadHarvestSchedulesFromFile(HarvestSchedule schedules[], int *scheduleCount) {
    FILE *file = fopen("schedules.dat", "rb");
    if (!file) {
        printf("Could not open file to load harvest schedules.\n");
        return;
    }

    fread(scheduleCount, sizeof(int), 1, file);
    fread(schedules, sizeof(HarvestSchedule), *scheduleCount, file);
    fclose(file);

    printf("Harvest schedules loaded from file successfully.\n");
}
void manageLivestockRecords(Livestock livestock[], int *livestockCount) {
    int choice;
    do {
        printf("\nManage Livestock Records\n");
        printf("1. Add Livestock\n");
        printf("2. View Livestock\n");
        printf("3. Delete Livestock\n");
        printf("4. Save Livestock to File\n");
        printf("5. Load Livestock from File\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLivestock(livestock, livestockCount);
                break;
            case 2:
                viewLivestock(livestock, *livestockCount);
                break;
            case 3:
                deleteLivestock(livestock, livestockCount);
                break;
            case 4:
                saveLivestockToFile(livestock, *livestockCount);
                break;
            case 5:
                loadLivestockFromFile(livestock, livestockCount);
                break;
            case 6:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
void addLivestock(Livestock livestock[], int *livestockCount) {
    if (*livestockCount >= MAX_LIVESTOCK) {
        printf("Maximum livestock limit reached.\n");
        return;
    }

    printf("Enter livestock type: ");
    scanf("%s", livestock[*livestockCount].type);
    printf("Enter livestock count: ");
    scanf("%d", &livestock[*livestockCount].count);
    printf("Enter health status: ");
    scanf("%s", livestock[*livestockCount].healthStatus);

    (*livestockCount)++;
    printf("Livestock added successfully.\n");
}

void viewLivestock(Livestock livestock[], int livestockCount) {
    if (livestockCount == 0) {
        printf("No livestock records available.\n");
        return;
    }

    printf("Livestock List:\n");
    for (int i = 0; i < livestockCount; i++) {
        printf("Livestock %d:\n", i + 1);
        printf("Type: %s\n", livestock[i].type);
        printf("Count: %d\n", livestock[i].count);
        printf("Health Status: %s\n", livestock[i].healthStatus);
    }
}

void deleteLivestock(Livestock livestock[], int *livestockCount) {
    if (*livestockCount == 0) {
        printf("No livestock records to delete.\n");
        return;
    }

    int index;
    printf("Enter the livestock number to delete (1 to %d): ", *livestockCount);
    scanf("%d", &index);

    if (index < 1 || index > *livestockCount) {
        printf("Invalid livestock number.\n");
        return;
    }

    for (int i = index - 1; i < *livestockCount - 1; i++) {
        livestock[i] = livestock[i + 1];
    }
    (*livestockCount)--;
    printf("Livestock deleted successfully.\n");
}

void saveLivestockToFile(Livestock livestock[], int livestockCount) {
    FILE *file = fopen("livestock.dat", "wb");
    if (!file) {
        printf("Could not open file to save livestock records.\n");
        return;
    }

    fwrite(&livestockCount, sizeof(int), 1, file);
    fwrite(livestock, sizeof(Livestock), livestockCount, file);
    fclose(file);

    printf("Livestock records saved to file successfully.\n");
}

void loadLivestockFromFile(Livestock livestock[], int *livestockCount) {
    FILE *file = fopen("livestock.dat", "rb");
    if (!file) {
        printf("Could not open file to load livestock records.\n");
        return;
    }

    fread(livestockCount, sizeof(int), 1, file);
    fread(livestock, sizeof(Livestock), *livestockCount, file);
    fclose(file);

    printf("Livestock records loaded from file successfully.\n");
}
void manageFarmExpenses(Expense expenses[], int *expenseCount) {
    int choice;
    do {
        printf("\nManage Farm Expenses\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, expenseCount);
                break;
            case 2:
                viewExpenses(expenses, *expenseCount);
                break;
            case 3:
                deleteExpense(expenses, expenseCount);
                break;
            case 4:
                saveExpensesToFile(expenses, *expenseCount);
                break;
            case 5:
                loadExpensesFromFile(expenses, expenseCount);
                break;
            case 6:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
void addExpense(Expense expenses[], int *expenseCount) {
    if (*expenseCount >= MAX_EXPENSES) {
        printf("Maximum expense limit reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*expenseCount].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[*expenseCount].date);

    (*expenseCount)++;
    printf("Expense added successfully.\n");
}

void viewExpenses(Expense expenses[], int expenseCount) {
    if (expenseCount == 0) {
        printf("No expenses available.\n");
        return;
    }

    printf("Expense List:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense %d:\n", i + 1);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
    }
}

void deleteExpense(Expense expenses[], int *expenseCount) {
    if (*expenseCount == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the expense number to delete (1 to %d): ", *expenseCount);
    scanf("%d", &index);

    if (index < 1 || index > *expenseCount) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < *expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*expenseCount)--;
    printf("Expense deleted successfully.\n");
}

void saveExpensesToFile(Expense expenses[], int expenseCount) {
    FILE *file = fopen("expenses.dat", "wb");
    if (!file) {
        printf("Could not open file to save expenses.\n");
        return;
    }

    fwrite(&expenseCount, sizeof(int), 1, file);
    fwrite(expenses, sizeof(Expense), expenseCount, file);
    fclose(file);

    printf("Expenses saved to file successfully.\n");
}

void loadExpensesFromFile(Expense expenses[], int *expenseCount) {
    FILE *file = fopen("expenses.dat", "rb");
    if (!file) {
        printf("Could not open file to load expenses.\n");
        return;
    }

    fread(expenseCount, sizeof(int), 1, file);
    fread(expenses, sizeof(Expense), *expenseCount, file);
    fclose(file);

    printf("Expenses loaded from file successfully.\n");
}
