//int InputArray(const char *sf,int ***v,size_t *m,size_t **n);
int InputArray(const char *sf, int ***arr , size_t *m, size_t **n);
char *wfgets(char **str, size_t *l, FILE *f);// считывание строки неогр длины
void FindAverage(int **v, size_t m, size_t *column,size_t *n);
int Compare(int *v, size_t n,size_t num);                 
void Delete(int ***v, size_t **n,size_t column, size_t m);
void Print(const char *sf,int **v,size_t *n,size_t m);