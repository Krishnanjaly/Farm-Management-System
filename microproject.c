#include<stdio.h>
#include<string.h>

struct Crop
{
    char name[100];
    char type[100];
    char planting_date[10];
    char harvesting_date[10];
    float area;
};
struct Livestock
{
    char name[100];
    char breed[100];
    int age;
    float weight;
    char health_status[200];
};
struct Farmexpenses
{
    char description[200];
    float amount;
    char date[10];
};
void manage_crop();
void harvest_schedules();
void livestock_records();
void farm_expenses();

int main()
{
    int choice;
    do
    {
        printf("\nFarm Manangement System\n");
        printf("1.Manage Crop Planting\n");
        printf("2.Harvest Schedule\n");
        printf("3.Livestock Records\n");
        printf("4.Farm Expenses\n");
        printf("5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                manage_crop();
                break;
            case 2:
                harvest_schedules();
                break;
            case 3:
                livestock_records();
                break;
            case 4:
                farm_expenses();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while(choice!=5);
    return 0;
}
void manage_crop()
{
    struct Crop crop;
    printf("Enter the crop name:");
    scanf(" %s",crop.name);
    printf("Enter the type of crop:");
    scanf("%s",crop.type);
    printf("Enter the area of the crop to be planted:");
    scanf("%f",&crop.area);

    FILE  *fp=fopen("crop.txt","a");
    if(fp==NULL)
    {
        printf("Could not open!\n");
        return;
    }
    fprintf(fp,"%s\t %s\t %f\n",crop.name,crop.type,crop.area);
    fclose(fp);
}

void harvest_schedules()
{
    struct Crop schedules;
    printf("Enter the crop name:");
    scanf("%s",schedules.name);
    printf("Enter the planting date of the crop:");
    scanf("%s",schedules.planting_date);
    printf("Enter the date of the plant to be harvested:");
    scanf("%s",schedules.harvesting_date);

    FILE *fp=fopen("schedule.txt","a");
    if(fp==NULL)
    {
        printf("Could not open!");
        return;
    }
    fprintf(fp,"%s\t%s\t %s\n",schedules.name,schedules.planting_date,schedules.harvesting_date);
    fclose(fp);
}

void livestock_records()
{
    struct Livestock records;
    printf("Enter the name:");
    scanf("%s",records.name);
    printf("Enter the breed:");
    scanf("%s",records.breed);
    printf("Enter the age:");
    scanf("%d",&records.age);
    printf("Enter the weight:");
    scanf("%f",&records.weight);
    printf("Enter the health status:");
    scanf("%s",records.health_status);

    FILE *fp=fopen("livestock_records.txt","a");
    if(fp==NULL)
    {
        printf("Could not open file!");
        return;
    }
    fprintf(fp,"%s\t %s\t %d\t %f\t %s\n",records.name,records.breed,records.age,records.weight,records.health_status);
    fclose(fp);
}

void farm_expenses()
{
    struct Farmexpenses expenses;
    printf("Enter the expense description:");
    scanf("%s",expenses.description);
    printf("Enter the date(DD/MM/YYYY):");
    scanf(" %[^\n]",expenses.date);
    printf("Enter the amount:");
    scanf(" %f",&expenses.amount);

    FILE *fp=fopen("farm_expenses.txt","a");
    if(fp==NULL)
    {
        printf("Could not open file!");
        return;
    }
    fprintf(fp,"%s\t %s\t %f\n",expenses.description,expenses.date,expenses.amount);
    fclose(fp);
}