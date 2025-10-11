template<typename T>
class Point {
public:
  T x,y;
  Point(T x = 0, T y = 0): x(x), y(y) {}

  Point<T> operator + (const Point<T>& other) {return {x + other.x, y + other.y};}
  Point<T> operator - (const Point<T>& other) {return {x - other.x, y - other.y};}
  T operator * (Point<T> b) {return x*b.x + y*b.y;}
  T operator ^ (Point<T> b) {return x*b.y - y*b.x;}

  bool operator < (const Point<T>& other) {return x < other.x || (x == other.x && y < other.y);}

  friend ostream& operator << (ostream & out, const Point& a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
  }

  friend istream & operator >> (istream & is, Point& a) {
    is >> a.x >> a.y;
    return is;
  }
};


template<typename T>
ll dir(Point<T>& A, Point<T>& B, Point<T>& C) {
  return ((B - A) ^ (C - B));
}

// CONVEX HULL (CLOCKWISE)
// Source: from VNOI Wiki with small modification
// for speed might change to vector<Point>& p if possible
template<typename T>
vector<Point<T>> convexHull(vector<Point<T>>& p) {
    int n = p.size();
    if (n < 3) {
        // cannot form convex hull
        return vector<Point<T>>();
    }

    // SORT POINTS
    sort(p.begin(), p.end());

    vector<Point<T>> hull;
    hull.push_back(p[0]);

    // UPPER HULL
    for (int i = 1; i < n; ++i) {
        while (hull.size() >= 2 && dir(hull[hull.size() - 2], hull.back(), p[i]) > 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    // LOWER HULL
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() >= 2 && dir(hull[hull.size() - 2], hull.back(), p[i]) > 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    // REMOVE 1 OVERLAPPING
    if (n > 1) hull.pop_back();
    return hull;
}

template<typename T>
ll area2(vector<Point<T>>& p) {
  // p must already be sorted counter-clockwise
  if (p.size() <= 2) return 0.0;
  ll area2 = 0;
  p.push_back(p[0]);
  for (int i = 0; i < p.size() - 1; i++) {
    //area += (p[i].x * p[i + 1].y) - (p[i + 1].x * p[i].y);
    area2 += (p[i].x - p[i + 1].x) * (p[i].y + p[i + 1].y);
  }
  // area = abs(area) / 2;
  p.pop_back();
  return area2;
}

template<typename T>
Point<T> find_center(vector<Point<T>>& p) {
  // T should be double when using this function
  T x = 0, y = 0;
  p.push_back(p[0]);
  for (int i = 0; i < p.size() - 1; i++) {
    T d = p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
    x += (p[i].x + p[i + 1].x) * d;
    y += (p[i].y + p[i + 1].y) * d;
  }
  p.pop_back();
  T A = area(p);
  x /= 6*A;
  y /= 6*A;
  return Point<T>(x,y);
}
