#include <stdio.h>
#define MAX 20
int frames[MAX], ref[MAX], mem[MAX][MAX];
int faults = 0, sp = 0, m, n, count[MAX];
void accept()
{
 int i;
 printf("Enter no. of frames: ");
 scanf("%d", &n);
 printf("Enter no. of references: ");
 scanf("%d", &m);
 printf("Enter reference string:\n");
 for (i = 0; i < m; i++)
 {
 printf("[%d] = ", i);
 scanf("%d", &ref[i]);
 }
}
void disp()
{
 int i, j;
 printf("\nReference String:\n");
 for (i = 0; i < m; i++)
 printf("%3d", ref[i]);
 printf("\n\n");
 printf("Page Replacement Table:\n");
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < m; j++)
 {
 if (mem[i][j] != 0)
 printf("%3d", mem[i][j]);
 else
 printf(" ");
 }
 printf("\n");
 }
 printf("\nTotal Page Faults: %d\n", faults);
}
int search(int pno)
{
 for (int i = 0; i < n; i++)
 {
 if (frames[i] == pno)
 return i;
 }
 return -1;
}
int get_lfu()
{
    int min = 9999, min_i = 0;
 for (int i = 0; i < n; i++)
 {
 if (count[i] < min)
 {
 min = count[i];
 min_i = i;
 }
 }
 return min_i;
}
void lfu()
{
 int i, j, k;
 for (i = 0; i < n; i++)
 {
 frames[i] = 0;
 count[i] = 0;
 }
 for (i = 0; i < m; i++)
 {
 k = search(ref[i]);
 if (k == -1)
 {
 if (sp < n)
 {
 frames[sp] = ref[i];
 count[sp] = 1;
 sp++;
 }
 else
 {
 int rep = get_lfu();
 frames[rep] = ref[i];
 count[rep] = 1;
 }
 faults++;
 }
 else
 {
 count[k]++;
 }
 for (j = 0; j < n; j++)
 mem[j][i] = frames[j];
 }
}
int main()
{
 accept();
 lfu();
 disp();
}