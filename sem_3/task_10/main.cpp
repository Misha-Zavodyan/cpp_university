#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;


struct Point {
    double x, y;
};
bool isEqual(double a, double b) {
    return fabs(a - b) < 1e-9;
}

bool isPointOnSegment(const Point& p, const Point& p1, const Point& p2) {

    double crossProduct = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);


    return isEqual(crossProduct,0) && (p.x - p1.x) * (p.x - p2.x) <= 0 && (p.y - p1.y) * (p.y - p2.y) <= 0;
}

int orientation(Point a, Point b, Point c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (isEqual(val,0)) return 0;
    return (isEqual(val,0)) ? 1 : 2;
}




int pointLocation(const vector<Point>& points, Point p) {
    int n = points.size();
    if (n < 3) return 0;


    int count = 0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;


        if ((((points[i].y - p.y < 1e-9) && (points[next].y - p.y >= 1e-9)) || ((points[next].y - p.y < 1e-9) && (points[i].y - p.y >= 1e-9))) &&
            ((points[i].x - p.x <= 1e-9) || (points[next].x - p.x <= 1e-9)) &&
           ( (points[i].x + (p.y - points[i].y) / (points[next].y - points[i].y) * (points[next].x - points[i].x))- p.x)< 1e-9) {

            
            count++;
            std::cout << points[i].x << " " << points[i].y << " " << points[next].x << " " << points[next].y << std::endl;
        }
        if (isPointOnSegment(p,points[i],points[next])) return 1;
    }

    return (count % 2 == 1) ? 2 : 0;
}

int main() {

    vector<Point> polygon = {{1, 0}, {2, 0}, {2, 2}, {0, 2}, {0, 1}, {-2, 1}, {-2, 0}, {-1, 0}, {-1, -1}, {0, -1}, {0, -2}, {1, -2}};
    

    Point testPoint = {0, 0};

    int location = pointLocation(polygon, testPoint);

    if (location == 2) {
        cout << "Point inside a polygon" << endl;
    } else if (location == 1) {
        cout << "Point on the side of the polygon" << endl;
    } else {
        cout << "Pint outside the polygon" << endl;
    }
    
chrono::time_point<std::chrono::_V2::system_clock> start, end;
start = chrono::high_resolution_clock::now();
// 10000 итараций с 4 вершинами
for (int i = 0; i < 1000000; ++i)
{
  testPoint={double(rand()%1000), double(rand()%1000)};
  //location=pointLocation(polygon, testPoint);
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

for (int i = 0; i < 32; ++i) {
  polygon2.push_back({double(rand()%1000), double(rand()%1000)}) ;
}  
cout<<polygon2.size() ;

start = chrono::high_resolution_clock::now();
for (int i = 0; i < 1000000; ++i) {
    testPoint={double(rand()%1000), double(rand()%1000)};
  //location=pointLocation(polygon2, testPoint);
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
