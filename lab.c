#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "labs.dat"
#define MAX_NAME_LEN 100
#define MAX_EQUIP_LEN 200
#define MAX_TECHNICIAN_LEN 100

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int lab_id;
    char lab_name[MAX_NAME_LEN];
    char equipment[MAX_EQUIP_LEN];
    char technician[MAX_TECHNICIAN_LEN];
    int capacity;
} Lab;

// ------------------ FUNCTION DECLARATIONS ------------------
void addLab();
void viewLabs();
void searchLab();
void updateLab();
void deleteLab();
int labIdExists(int id);
void saveLab(Lab l);
void loadLabs(Lab labs[], int *count);
void writeAllLabs(Lab labs[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n==============================\n");
        printf("      LAB MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add New Lab\n");
        printf("2. View All Labs\n");
        printf("3. Search Lab\n");
        printf("4. Update Lab\n");
        printf("5. Delete Lab\n");
        printf("6. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addLab(); break;
            case 2: viewLabs(); break;
            case 3: searchLab(); break;
            case 4: updateLab(); break;
            case 5: deleteLab(); break;
            case 6: printf("Exiting program... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD LAB ------------------
void addLab() {
    Lab l;

    printf("\n--- Add New Lab ---\n");
    printf("Enter Lab ID: ");
    scanf("%d", &l.lab_id);
    getchar();

    if (labIdExists(l.lab_id)) {
        printf("Error: Lab ID already exists!\n");
        return;
    }

    printf("Enter Lab Name: ");
    fgets(l.lab_name, sizeof(l.lab_name), stdin);
    l.lab_name[strcspn(l.lab_name, "\n")] = '\0';

    printf("Enter Equipment Details: ");
    fgets(l.equipment, sizeof(l.equipment), stdin);
    l.equipment[strcspn(l.equipment, "\n")] = '\0';

    printf("Enter Technician Name: ");
    fgets(l.technician, sizeof(l.technician), stdin);
    l.technician[strcspn(l.technician, "\n")] = '\0';

    printf("Enter Maximum Capacity: ");
    scanf("%d", &l.capacity);

    saveLab(l);
    printf("Lab added successfully!\n");
}

// ------------------ SAVE LAB TO FILE ------------------
void saveLab(Lab l) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&l, sizeof(Lab), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF LAB ID EXISTS ------------------
int labIdExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Lab l;
    while (fread(&l, sizeof(Lab), 1, fp)) {
        if (l.lab_id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL LABS ------------------
void viewLabs() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No lab records found.\n");
        return;
    }

    Lab l;
    printf("\n%-10s %-20s %-25s %-20s %-10s\n",
           "Lab ID", "Lab Name", "Equipment", "Technician", "Capacity");
    printf("-----------------------------------------------------------------------------------------\n");

    while (fread(&l, sizeof(Lab), 1, fp)) {
        printf("%-10d %-20s %-25s %-20s %-10d\n",
               l.lab_id, l.lab_name, l.equipment, l.technician, l.capacity);
    }
    fclose(fp);
}

// ------------------ SEARCH LAB ------------------
void searchLab() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Lab l;

    printf("\nEnter Lab ID to search: ");
    scanf("%d", &id);

    while (fread(&l, sizeof(Lab), 1, fp)) {
        if (l.lab_id == id) {
            printf("\nLab Found:\n");
            printf("Lab ID: %d\nName: %s\nEquipment: %s\nTechnician: %s\nCapacity: %d\n",
                   l.lab_id, l.lab_name, l.equipment, l.technician, l.capacity);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No lab found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE LAB ------------------
void updateLab() {
    Lab labs[100];
    int count = 0, id, found = 0;

    loadLabs(labs, &count);

    printf("\nEnter Lab ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (labs[i].lab_id == id) {
            found = 1;

            printf("Enter new equipment details: ");
            fgets(labs[i].equipment, sizeof(labs[i].equipment), stdin);
            labs[i].equipment[strcspn(labs[i].equipment, "\n")] = '\0';

            printf("Enter new technician name: ");
            fgets(labs[i].technician, sizeof(labs[i].technician), stdin);
            labs[i].technician[strcspn(labs[i].technician, "\n")] = '\0';

            printf("Enter new capacity: ");
            scanf("%d", &labs[i].capacity);

            break;
        }
    }

    if (found) {
        writeAllLabs(labs, count);
        printf("Lab updated successfully.\n");
    } else {
        printf("Lab ID not found.\n");
    }
}

// ------------------ DELETE LAB ------------------
void deleteLab() {
    Lab labs[100];
    int count = 0, id, found = 0;

    loadLabs(labs, &count);

    printf("\nEnter Lab ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (labs[i].lab_id == id) {
            found = 1;

            printf("Are you sure you want to delete '%s'? (y/n): ", labs[i].lab_name);
            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    labs[j] = labs[j + 1];

                count--;
                writeAllLabs(labs, count);

                printf("Lab deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Lab ID not found.\n");
}

// ------------------ LOAD & WRITE ALL LABS ------------------
void loadLabs(Lab labs[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;
    *count = 0;

    while (fread(&labs[*count], sizeof(Lab), 1, fp))
        (*count)++;

    fclose(fp);
}

void writeAllLabs(Lab labs[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(labs, sizeof(Lab), count, fp);
    fclose(fp);
}
