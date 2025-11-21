#include <stdio.h> #include <string.h> #define MAX 100

struct Student { char roll[20]; char name[50]; char department[20]; char section; char mobile[15]; };

int main() { struct Student s[MAX]; int choice, count = 0;

while (1) {
    printf("\n===== Student Record Management System =====\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 6) {
        printf("Exiting...\n");
        break;
    }
    switch (choice) {
    case 1: {
        if (count >= MAX) {
            printf("Cannot add more students! Array is full.\n");
            break;
        }
        printf("Enter roll number: ");
        scanf(" %s", s[count].roll);
        printf("Enter name: ");
        scanf(" %s", s[count].name);
        printf("Enter department (SET/FET/...): ");
        scanf(" %s", s[count].department);
        printf("Enter section (A/B/C/...): ");
        scanf(" %c", &s[count].section);
        printf("Enter mobile number: ");
        scanf(" %s", s[count].mobile);
        count++;
        printf("Student added successfully!\n");
        break;
    }
    case 2: {
        if (count == 0) {
            printf("No student records found.\n");
            break;
        }
        printf("\n--- Student Records ---\n");
        for (int i = 0; i < count; i++) {
            printf("\nStudent %d\n", i + 1);
            printf("Roll Number : %s\n", s[i].roll);
            printf("Name        : %s\n", s[i].name);
            printf("Department  : %s\n", s[i].department);
            printf("Section     : %c\n", s[i].section);
            printf("Mobile No.  : %s\n", s[i].mobile);
        }
        break;
    }
    case 3: {
        char r[20];
        int found = 0;
        printf("Enter roll number to search: ");
        scanf(" %s", r);
        for (int i = 0; i < count; i++) {
            if (strcmp(s[i].roll, r) == 0) {
                printf("\nRecord Found!\n");
                printf("Roll Number : %s\n", s[i].roll);
                printf("Name        : %s\n", s[i].name);
                printf("Department  : %s\n", s[i].department);
                printf("Section     : %c\n", s[i].section);
                printf("Mobile No.  : %s\n", s[i].mobile);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    case 4: {
        char r[20];
        int found = 0;
        printf("Enter roll number to update: ");
        scanf(" %s", r);
        for (int i = 0; i < count; i++) {
            if (strcmp(s[i].roll, r) == 0) {
                printf("Enter new name: ");
                scanf(" %s", s[i].name);
                printf("Enter new department: ");
                scanf(" %s", s[i].department);
                printf("Enter new section: ");
                scanf(" %c", &s[i].section);
                printf("Enter new mobile number: ");
                scanf(" %s", s[i].mobile);
                printf("Record updated successfully!\n");
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    case 5: {
        char r[20];
        int found = 0;
        printf("Enter roll number to delete: ");
        scanf(" %s", r);
        for (int i = 0; i < count; i++) {
            if (strcmp(s[i].roll, r) == 0) {
                for (int j = i; j < count - 1; j++) {
                    s[j] = s[j + 1];
                }
                count--;
                printf("Record deleted successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Student not found!\n");
        break;
    }
    default:
        printf("Invalid choice! Try again.\n");
    }
}
return 0;
}
