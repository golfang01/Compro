#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    double salary;
    double annualTax;
};

void calculateTax(struct Employee* emp) {
    emp->annualTax = emp->salary * 12 * 0.07;
}

void printSum(const struct Employee* employees, int numEmp) {
    double totalSalary = 0.0;
    double totalTax = 0.0;
    double maxTax = 0.0;
    char maxTaxEmployee[50];

    for (int i = 0; i < numEmp; ++i) {
        totalSalary += employees[i].salary * 12;
        totalTax += employees[i].annualTax;

        if (employees[i].annualTax > maxTax) {
            maxTax = employees[i].annualTax;
            strcpy(maxTaxEmployee, employees[i].name);
        }
    }

    printf("All salary per month: %.2lf Bath\n", totalSalary / 12);
    printf("All salary per year: %.2lf Bath\n", totalSalary);
    printf("Tax (7%% per year): %.2lf Bath\n", totalTax);
    printf("Most tax in company: %s (%.2lf Bath per year)\n", maxTaxEmployee, maxTax);
}

int main() {
    const int maxEmployees = 10;
    struct Employee employees[maxEmployees];
    int numEmp = 0;

    while (numEmp < maxEmployees) {
        printf("Employee %d's Name :\n", numEmp + 1);
        fgets(employees[numEmp].name, sizeof(employees[numEmp].name), stdin);
        employees[numEmp].name[strcspn(employees[numEmp].name, "\n")] = '\0'; 

        if (strcmp(employees[numEmp].name, "-1") == 0) {
            break;
        }

        printf("Salary (Bath/Month) :\n");
        scanf("%lf", &employees[numEmp].salary);
        getchar(); 

        calculateTax(&employees[numEmp]);
        ++numEmp;
    }

    printSum(employees, numEmp);

    return 0;
}
