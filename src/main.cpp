
#include <iostream>
#include <cmath>

// Constants 

#define g 9.807

#define FPS 25


//-----------------------//

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


    using Position = Vector3;

    using Velocity = Vector3;

    using Accleration = Vector3;

    using Force = Vector3;






    class Particle
    {
    public:

        // Default Constructor
        /*
        Particle() 
        : p(Position()),
        v(Vector3()),
        a(Vector3()),
        f(Vector3()),
        damp(0.995),
        m(0.00001),
        m_(100000.0) {}
        */

        // Parameterized Constructor
        Particle(Position p_ = Position(),
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

        // Copy Constructor
        Particle(const Particle& dust) 
        : p(dust.p),
        v(dust.v),
        a(dust.a),
        f(dust.f),
        damp(dust.damp),
        m(dust.m),
        m_(dust.m_) {}

        // Copy Assignment Operator
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

        void print();


    private:
        Position p; // position in world space
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
        {
            // Calculate position
            p += t * v;

            // Calculate accleration
            a += t * f;

            // Calculate velocity
            v += t * a;

            // Include Drag
            // v *= pow(damp, t);

            // Clear the forces
            // clearAccumulator();
        }
    }

    void Particle::setMass(const double mass)
    {
        if(mass != 0)
        {
            m = mass;
            m = 1 / m_;
        }
    }

    double Particle::getMass() const
    {
        return m;
    }

    void Particle::setInverseMass(const double mass)
    {
        if(mass != 0)
        {
            m_ = mass;
            m_ = 1 / m;
        }
    }

    double Particle::getInverseMass() const
    {
        return m_;
    }

    bool Particle::hasFiniteMass() const
    {
        if(m_ == 0)
        {
            return false;
        }

        return true;
    }
    
    void Particle::setDamping(const double newDamp)
    {
        damp = newDamp;
    }

    double Particle::getDamping() const
    {
        return damp;
    }

    void Particle::setPos(const Vector3& v)
    {
        p = v;
    }

    void Particle::setPos(const double x, const double y, const double z)
    {
        p = Vector3(x,y,z);
    }

    void Particle::getPos(Vector3* v) const
    {
        v->x = p.x;
        v->y = p.y;
        v->z = p.z;
    }

    Vector3 Particle::getPos() const
    {
        return p;
    }

    //------------------------------

    void Particle::setVelocity(const Vector3& v_)
    {
        this->v = v_;
    }

    void Particle::setVelocity(const double x, const double y, const double z)
    {
        v = Vector3(x,y,z);
    }

    void Particle::getVelocity(Vector3* v) const
    {
        v->x = this->v.x;
        v->y = this->v.y;
        v->z = this->v.z;
    }

    Vector3 Particle::getVelocity() const
    {
        return v;
    }

    //-------------------------------------

    void Particle::setAccleration(const Vector3& v)
    {
        a = v;
    }

    void Particle::setAccleration(const double x, const double y, const double z)
    {
        a = Vector3(x,y,z);
    }

    void Particle::getAccleration(Vector3* v) const
    {
        v->x = a.x;
        v->y = a.y;
        v->z = a.z;
    }

    Vector3 Particle::getAccleration() const
    {
        return a;
    }

    void Particle::applyForce(const Vector3& v)
    {
        f += v;
    } 

    void Particle::print()
    {
        std::cout << " Position = (" << p.x << ", " << p.y << ", " << p.z << "); "
                << " Velocity = (" << v.x << ", " << v.y << ", " << v.z << "); "
                << " Accleration = (" << a.x << ", " << a.y << ", " << a.z << ")" << std::endl;
    }

    /* 
    void Particle::clearAccumulator();
    */

}



int main()
{
    cog::Position pos(0,0,0);

    cog::Velocity vel(1,1,0);

    vel *= 4;

    cog::Accleration acc(0,-1,0);

    acc *= g;

    cog::Particle sample;

    sample.setPos(pos);
    sample.setVelocity(vel);
    sample.setAccleration(acc);

    for(int i = 0; i < 25; i++)
    {
        sample.integrate(1.0/FPS);
        sample.print();
    }
}






