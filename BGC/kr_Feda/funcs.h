#define MAXIT 1000

#define MAXIT1 1000

#define MINX (-10)

#define STEP 0.1

#define SIGN(x) ((x) < 0 ? (1) : (-1))

double f2(double x, double t);

double f1(double x, double eps);

double f0(double x, double eps);

int task8(double (*op)(double, double), double xx, double a, double b, double ep, double *r);

int task9(double (*op)(double, double), double xx, double a, double b, double ep, double *r);

int task1(double (*op)(double, double), double a, double b, double ep, double *x);

int task3(double (*op)(double, double), double a, double b, double ep, double *x);
