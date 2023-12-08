#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;

// Структура для представления точки в 2D пространстве
struct Point {
    double x, y;
};
bool isPointOnSegment(const Point& p, const Point& p1, const Point& p2) {
    // Проверяем, что векторные произведения векторов p1p и p1p2 имеют одинаковый знак
    double crossProduct = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);

    // Если векторные произведения имеют одинаковый знак, то точка лежит на отрезке
    return crossProduct == 0 && (p.x - p1.x) * (p.x - p2.x) <= 0 && (p.y - p1.y) * (p.y - p2.y) <= 0;
}
// Функция для сравнения двух double с учетом допуска EPSILON
bool isEqual(double a, double b) {
    return fabs(a - b) < 1e-9;
}

// Функция для определения ориентации троеки точек (a, b, c)
// Возвращает:
// 0 - если точки коллинеарны
// 1 - по часовой стрелке
// 2 - против часовой стрелки
int orientation(Point a, Point b, Point c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (val == 0) return 0;  // Точки коллинеарны
    return (isEqual(val,0)) ? 1 : 2; // 1 - по часовой стрелке, 2 - против часовой стрелки
}



// Функция для определения, лежит ли точка p внутри многоугольника с вершинами points
// Возвращает:
// 0 - точка снаружи многоугольника
// 1 - точка на границе многоугольника
// 2 - точка внутри многоугольника
int pointLocation(const vector<Point>& points, Point p) {
    int n = points.size();
    if (n < 3) return 0;  // Многоугольник должен иметь хотя бы 3 вершины

    // Инициализируем счетчик пересечений и флаг для точек на границе
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;

        // Проверяем пересечение отрезка (points[i], points[next]) с лучом, исходящим из p
        if ((points[i].y - p.y < 1e-9 && points[next].y - p.y >= 1e-9 || points[next].y - p.y < 1e-9 && points[i].y - p.y >= 1e-9) &&
            (points[i].x - p.x <= 1e-9 || points[next].x - p.x <= 1e-9) &&
           ( (points[i].x + (p.y - points[i].y) / (points[next].y - points[i].y) * (points[next].x - points[i].x))- p.x)< 1e-9) {
            // Проверяем, если точка находится на горизонтальной грани многоугольника
            
            count++;
        }
        if (isPointOnSegment(p,points[i],points[next])) return 1;  // Точка находится на границе многоугольника
    }

    return (count % 2 == 1) ? 2 : 0;  // Четное количество пересечений: точка внутри многоугольника, нечетное: снаружи
}

int main() {
    // Пример использования программы
    vector<Point> polygon = {{0.0, 0.0}, {0.0, 4.0}, {4.0, 4.0}, {4.0, 0.0}};
    

    Point testPoint = {0.1, 3.6000000};

    int location = pointLocation(polygon, testPoint);

    if (location == 2) {
        cout << "inside" << endl;
    } else if (location == 1) {
        cout << "in" << endl;
    } else {
        cout << "out" << endl;
    }
    
chrono::time_point<std::chrono::_V2::system_clock> start, end;
start = chrono::high_resolution_clock::now();
// 10000 итараций с 4 вершинами
for (int i = 0; i < 10000000; ++i) 
{
  testPoint={double(rand()%1000), double(rand()%1000)};
  location=pointLocation(polygon, testPoint);
    // if (location == 2) {
    //     cout << "inside" ;
    // } else if (location == 1) {
    //     cout << "in" ;
    // } else {
    //     cout << "out" ;
    // }
}
cout << endl;

end = chrono::high_resolution_clock::now();
chrono::duration<float> duration = end -start;
cout << "Run time = " << duration.count() << " ms "<<"\n";
  



vector<Point> polygon2 = {{1,0},{0,1},{0,2},{1,3},{5,3},{6,2},{6,1},{5,0}}; 

for (int i = 0; i < 392; ++i) {
  polygon2.push_back({double(rand()%1000), double(rand()%1000)}) ;
}  
cout<<polygon2.size() ;

start = chrono::high_resolution_clock::now();
for (int i = 0; i < 10000000; ++i) {
    testPoint={double(rand()%1000), double(rand()%1000)};
  location=pointLocation(polygon2, testPoint);
//   if (location == 2) {
//         cout << "inside" ;
//     } else if (location == 1) {
//         cout << "in" ;
//     } else {
//         cout << "out" ;
//     }
}
cout << endl;

end = chrono::high_resolution_clock::now();
duration = end - start;
cout << "Run time = " << duration.count() << " ms "<<"\n";

    return 0;
}