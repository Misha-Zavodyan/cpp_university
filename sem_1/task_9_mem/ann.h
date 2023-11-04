#pragma once
struct otr {
  int a;     // 4 байта
  int b;    // 4 байта
};
int InputArray1(const char *sf,struct otr **m,int *n);
int fun(struct otr *m, int n,int*len);
