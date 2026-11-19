#include <stdio.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

/* 計算並印出所有書籍的總價 */
void total_price(book_t books[], int n) {
    int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + books[i].price;
    }
    printf("總共價錢: %d\n", sum);
}

/* 印出所有書籍資料 */
void list_books(book_t books[], int n) {
    int i;
    printf("Id\tPrice\tTitle\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n", books[i].id, books[i].price, books[i].title);
    }
}

int main() {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4,  550, "Killers of the Flower Moon"},
        {5,  870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };
    book_t books2[6];   /* 用來放從檔案讀回來的資料 */
    FILE *fp;

    /* 把書籍資料寫進 Book.bin */
    fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), 6, fp);
    fclose(fp);

    /* 再從 Book.bin 讀回來 */
    fp = fopen("Book.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }
    fread(books2, sizeof(book_t), 6, fp);
    fclose(fp);

    list_books(books2, 6);
    total_price(books2, 6);

    return 0;
}
