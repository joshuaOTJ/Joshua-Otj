#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book b;
    FILE *fp;

    // Input book details
    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);

    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);

    printf("Enter price: ");
    scanf("%f", &b.price);

    // Write book details to file
    fp = fopen("book.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "%s%s%.2f\n", b.title, b.author, b.price);
    fclose(fp);

    // Read and display book details from file
    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char title[100], author[100];
    float price;

    fgets(title, sizeof(title), fp);
    fgets(author, sizeof(author), fp);
    fscanf(fp, "%f", &price);

    printf("\nSaved Book Details:\n");
    printf("Title: %s", title);
    printf("Author: %s", author);
    printf("Price: %.2f\n", price);

    fclose(fp);
    return 0;
}

