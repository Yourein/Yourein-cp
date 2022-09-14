namespace Yourein {
    namespace Geometry {
        const double EPS = 1e-9;
        const double PI = acos(-1);
 
        inline bool equals(const double &a, const double &b){
            return abs(a-b) < EPS;
        }
 
        template <typename T>
        class Vector {
            public:
                T x;
                T y;
 
                Vector (const T _x = 0, const T _y = 0): x(_x), y(_y) {}
 
                double norm() {
                    return hypot(x, y);
                }
                
                T innerProduct(const Vector& b){
                    return this->x*b.x + this->y*b.y;
                }
                
                T outerProduct(const Vector& b){
                    return this->x*b.y - this->y*b.x;
                }
 
                bool isZero() {
                    if (typeid(T) == typeid(double) || typeid(T) == typeid(float)) {
                        return equals(this->x, 0.0) && equals(this->y, 0.0);
                    }
                    else {
                        return this->x == 0 && this->y == 0;
                    }
                }
        };
 
        template<typename T>
        class Point {
            public:
                T x;
                T y;
 
                Point(const T _x = 0, const T _y = 0): x(_x), y(_y) {}
 
                friend istream &operator>> (istream& is, Point<T> &p){
                    is >> p.x >> p.y; return is;
                }
                
                friend ostream &operator<< (ostream& os, Point<T> &p){
                    os << p.x << " " << p.y; return os;
                }
                
                Yourein::Geometry::Vector<T> createVec(const Point<T> &b){
                    return Vector(b.x - this->x, b.y - this->y);
                }
 
                Point<double> rotateByCenter(double theta, bool isDegree = false){
                    if (isDegree) theta = (theta/180.0)*PI;
                    return Point<double>(double(this->x)*cos(theta) - double(this->y)*sin(theta), double(this->y)*cos(theta) + double(this->x)*sin(theta));
                }
 
                template <typename S>
                Point rotateByPoint(const Point<S>& g, double theta, bool isDegree = false){
                    if (isDegree) theta = (theta/180.0)*PI;
                    Point<S> mv(static_cast<S>(this->x) - g.x, static_cast<S>(this->y) - g.y);
                    Point<double> res = mv.rotateByCenter(theta);
                    res.x += g.x;
                    res.y += g.y;
                    return res;
                }
        };
       
        template <typename T>
        class Segment {
            public:
                Point<T> begin, end;
                Segment(const Point<T> &p, const Point<T> &q): begin(p), end(q) {}
        };
       
        template <typename T>
        class Polygon {
            public:
                vector<Point<T>> vertex;
                
                Polygon(vector<Point<T>> &p) {
                    if ((int)p.size() < 3){
                        throw invalid_argument("Too few number of points for a Polygon (at least 3)");
                    }
 
                    int n = (int)p.size();
                    for (int i = 0; i < n; i++){
                        auto vp = p[i].createVec(p[(i+n-1)%n]), vpp = p[i].createVec(p[(i+1)%n]);
                        if (vp.outerProduct(vpp) != 0) vertex.push_back(p[i]);
                    }
                }
        };
        
        template <typename T>
        int ccw(Point<T> &a, Point<T> &b, Point<T> &c){
            Vector base(b.x - a.x, b.y - a.y), target(c.x - a.x, c.y - a.y);
 
            if (base.outerProduct(target) > 0) return 1; //anti clockwise
            if (base.outerProduct(target) < 0) return -1; //clockwise
            if (base.innerProduct(target) < 0) return 2; //c--a--b onLine
            if (base.norm() < target.norm()) return -2; //a--b--c onLine
            return 0; //a--c--b onLine
        }
 
        template <typename T>
        bool isConvex(vector<Point<T>> &p){
            int n = (int)p.size();
            if (n == 0){
                return true;
            }
            double baseCCW = p[0].createVec(p[1]).outerProduct(p[1].createVec(p[2]));
            for (int i = 0; i < n; i++) 
                if (p[(i+n-1)%n].createVec(p[i]).outerProduct(p[i].createVec(p[(i+1)%n])) * baseCCW < 0){
                    return false;
                }
            
            return true;
        }
        
        template<typename T>
        bool isIntersect(Yourein::Geometry::Segment<T> &a, Yourein::Geometry::Segment<T> &b){
            return ccw(a.begin, a.end, b.begin) * ccw(a.begin, a.end, b.end) <= 0 &&
                   ccw(b.begin, b.end, a.begin) * ccw(b.begin, b.end, a.end) <= 0;
        }
    }
}
