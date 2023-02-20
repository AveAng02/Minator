
#include <iostream>
#include <cmath>

namespace cog
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

        void operator*=(const double v)
        {
            x *= v;
            y *= v;
            z *= v;
        }

        void operator/=(const double v)
        {
            x /= v;
            y /= v;
            z /= v;
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




    class Particle
    {
    public:

        Particle() 
        : p(Vector3()),
        v(Vector3()),
        a(Vector3()),
        f(Vector3()),
        damp(0.995),
        m(0.00001),
        m_(100000.0) {}


        Particle(Vector3 p_ = Vector3(),
                Vector3 v_ = Vector3(),
                Vector3 a_ = Vector3(),
                Vector3 f_ = Vector3(),
                double damp_ = 0.995,
                double M = 0.00001,
                double M_ = 100000.0) 
        : p(p_),
        v(v_),
        a(a_),
        f(f_),
        damp(damp_),
        m(M),
        m_(M_) {}

        Particle(const Particle& dust) 
        : p(dust.p),
        v(dust.v),
        a(dust.a),
        f(dust.f),
        damp(dust.damp),
        m(dust.m),
        m_(dust.m_) {}

        Particle& operator=(const Particle& dust)
        {
            p = dust.p;
            v = dust.v;
            a = dust.a;
            f = dust.f;
            damp = dust.damp;
            m = dust.m;
            m_ = dust.m_;

            return *this;
        }

        ~Particle() {}


        void integrate(double);

        void setMass(const double);
        double getMass() const;

        void setInverseMass(const double);
        double getInverseMass() const;

        bool hasFiniteMass() const;

        void setDamping(const double);
        double getDamping() const;

        /*
            * Set and get position
        */
        void setPos(const Vector3&);
        void setPos(const double, const double, const double);

        void getPos(Vector3*) const;
        Vector3 getPos() const;
        //---------------------------------


        /*
            * Set and get velocity
        */
        void setVelocity(const Vector3&);
        void setVelocity(const double, const double, const double);

        void getVelocity(Vector3*) const;
        Vector3 getVelocity() const;
        //---------------------------------


        /*
            * Set and get accleration
        */
        void setAccleration(const Vector3&);
        void setAccleration(const double, const double, const double);

        void getAccleration(Vector3*) const;
        Vector3 getAccleration() const;
        //---------------------------------

        void applyForce(const Vector3&); // 

        void clearAccumulator();




    private:
        Vector3 p; // position in world space
        Vector3 v; // velocity in world space
        Vector3 a; // accleration in world space
        Vector3 f;
        double damp; // holds the damping variable
        double m; // mass
        double m_; // inverse mass

    };

    void Particle::integrate(double t)
    {
        // Check if mass is less than zero
        if(m_ <= 0.0)
            return;
        
        // Make sure duration is greater than zero
        if(t > 0.0)
            return;


        // Calculate position
        p += t * v;

        // Calculate accleration
        a += t * f;

        // Calculate velocity
        v += t * a;

        // Include Drag
        v *= pow(damp, t);

        // Clear the forces
        clearAccumulator();
    }



}



int main()
{
    cog::Vector3 a(1,2,3), b(7,8,9);

    a += b;

    return 0;
}






