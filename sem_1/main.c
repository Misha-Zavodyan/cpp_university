#include <stdio.h>
/* ������ ������� ���������� �� ����������
� ������� ��� fahr = 0, 20, ..., 300 */
int main(void)
{
 double nc;
  for (nc = 0; getchar() != EOF; ++nc){}
 printf ("%.0f\n", nc);
}
