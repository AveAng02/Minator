
#include <cmath>

namespace jaggery
{
    class Vector3
    {
    public:

        Vector3()
        {
            x = 0.0;
            y = 0.0;
            z = 0.0;
        }

        // Default constructor
        Vector3(double x_, double y_, double z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        // Copy constructor
        Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

        // Copy assignment operator
        Vector3& operator=(const Vector3& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;

            return *this;
        }
        
        // Destructor
        ~Vector3() {}

        // move constructor
        Vector3(Vector3&& v) : x(0.0), y(0.0), z(0.0)
        {
            x = v.x;
            y = v.y;
            z = v.z;

            v.x = v.y = v.z = 0.0;
        }

        // move assignment operator
        Vector3& operator=(Vector3&& v)
        {
            if(this != &v)
            {
                x = v.x;
                y = v.y;
                z = v.z;

                v.x = v.y = v.z = 0.0;
            }

            return *this;
        }

        void operator+=(const Vector3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        void operator-=(const Vector3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        double operator*(const Vector3 v)
        {
            return (v.x * x) + (v.y * y) + (v.z * z);
        }

        Vector3 operator%(const Vector3 v)
        {
            return Vector3(((v.y * z) - (v.z * y)), ((v.z * x) - (v.x * z)), ((v.x * y) - (v.y * x)));
        }

        Vector3 operator*(const double num)
        {
            return Vector3((x * num), (y * num), (z * num));
        }

        Vector3 operator/(const double num)
        {
            return Vector3((x / num), (y / num), (z / num));
        }

        void scale(const double num)
        {
            x *= num;
            y *= num;
            z *= num;
        }

        double magSquare() const
        {
            return x*x + y*y + z*z;
        }

        double mag() const
        {
            return sqrt(magSquare());
        }


        double x;
        double y;
        double z;
    };


    double operator*(const Vector3 v, const Vector3 u)
    {
        return (v.x * u.x) + (v.y + u.y) + (v.z + u.z);
    }

    Vector3 operator*(const double num, const Vector3& v)
    {
        return Vector3((v.x * num), (v.y * num), (v.z * num));
    }

    Vector3 operator%(const Vector3 v, const Vector3 u)
    {
        return Vector3(((v.y * u.z) - (v.z * u.y)), ((v.z * u.x) - (v.x * u.z)), ((v.x * u.y) - (v.y * u.x)));
    }

    double operator^(const Vector3 v, const Vector3 u)
    {
        return acos(v*u / (v.mag() * u.mag()));
    }

    inline Vector3 compProd(const Vector3 v, const Vector3 u)
    {
        return Vector3((v.x * u.x), (v.y * u.y), (v.z * u.z));
    }


}


int main()
{
    jaggery::Vector3 a(1,2,3), b(7,8,9);

    a += b;

    return 0;
}






