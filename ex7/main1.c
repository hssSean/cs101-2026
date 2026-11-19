#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, temp, same;
    int num[7];
    FILE *fp;
    time_t now;

    srand(time(NULL));   /* 用現在時間當亂數種子，每次結果才會不同 */

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    /* n 只能是 1 ~ 5 */
    while (n < 1 || n > 5) {
        printf("只能買 1 ~ 5 組，請重新輸入：");
        scanf("%d", &n);
    }

    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    /* 標題與日期 */
    time(&now);
    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "= %.24s =\n", ctime(&now));   /* ctime 前 24 個字就是日期時間 */

    /* 印出 5 列，買了的列印數字，沒買的印 -- */
    for (i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);

        if (i <= n) {
            /* 產生 7 個不重複的數字 (1 ~ 69) */
            k = 0;
            while (k < 7) {
                temp = rand() % 69 + 1;
                same = 0;
                for (j = 0; j < k; j++) {
                    if (num[j] == temp) {
                        same = 1;
                    }
                }
                if (same == 0) {
                    num[k] = temp;
                    k++;
                }
            }

            /* 號碼由小排到大 */
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 6 - j; k++) {
                    if (num[k] > num[k + 1]) {
                        temp = num[k];
                        num[k] = num[k + 1];
                        num[k + 1] = temp;
                    }
                }
            }

            for (j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", num[j]);
            }
        } else {
            for (j = 0; j < 7; j++) {
                fprintf(fp, "-- ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
