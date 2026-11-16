#define MAXIT 1000
#define MAXIT1 1000
#define MINX (-20)
#define STEP 0.5
#define SIGN(x) ((x) < 0 ? (1) : (-1))
double f3(double x, double u, double t);

double f2(double x, double u, double eps);

double f1(double x, double eps);

double f0(double x, double eps);

int task8(double (*op)(double, double, double), double xx, double uu, double a, double b, double ep, double *r);

int task8_1(double (*op)(double, double, double), double xx, double a, double b, double ep, double *r);

int task1(double (*op)(double, double), double a, double b, double ep, double *x);


