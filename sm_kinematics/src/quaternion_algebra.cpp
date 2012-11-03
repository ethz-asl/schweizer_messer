#include <sm/kinematics/quaternion_algebra.hpp>
#include <sm/kinematics/rotations.hpp>
#include <sm/assert_macros.hpp>
#include <Eigen/Geometry>
#include <limits>
#include <cmath>

namespace sm { namespace kinematics {

        // quaternion rotation.
        Eigen::Vector4d r2quat(Eigen::Matrix3d const & R){
      
            const double & c1 = R(0,0);
            const double & c2 = R(1,0);
            const double & c3 = R(2,0);
            const double & c4 = R(0,1);
            const double & c5 = R(1,1);
            const double & c6 = R(2,1);
            const double & c7 = R(0,2);
            const double & c8 = R(1,2);
            const double & c9 = R(2,2);

            Eigen::Vector4d dc(fabs(1.0+c1-c5-c9),
                               fabs(1.0-c1+c5-c9),
                               fabs(1.0-c1-c5+c9),
                               fabs(1.0+c1+c5+c9));

            unsigned maxq = 0;
            double maxqval = dc(0);

            for(unsigned i = 1; i < 4; i++) {
                if(dc(i) > maxqval) {
                    maxq = i;
                    maxqval = dc(i);
                }
            }

            double c;
            Eigen::Vector4d q;
            if(maxq == 0){
                q(0)=0.5*sqrt(dc(0));
                c = 0.25/q(0);
                q(1)=c*(c4+c2);
                q(2)=c*(c7+c3);
                q(3)=c*(c8-c6);
            } else if(maxq == 1){
                q(1)=0.5*sqrt(dc(1));
                c = 0.25/q(1);
                q(0)=c*(c4+c2);
                q(2)=c*(c6+c8);
                q(3)=c*(c3-c7);
            } else if(maxq == 2){
                q(2)=0.5*sqrt(dc(2));
                c = 0.25/q(2);
                q(0)=c*(c3+c7);
                q(1)=c*(c6+c8);
                q(3)=c*(c4-c2);
            } else {
                q(3)=0.5*sqrt(dc(3));
                c = 0.25/q(3);
                q(0)=c*(c8-c6);
                q(1)=c*(c3-c7);
                q(2)=c*(c4-c2);
            }

            if(q(3) < 0)
                q = -q;

            return q;
        }

        Eigen::Matrix3d quat2r(Eigen::Vector4d const & q){
    
            SM_ASSERT_NEAR_DBG(std::runtime_error,q.norm(),1.f,1e-4, "The quaternion must be a unit vector to represent a rotation");
            //double n = q(3);
            //Eigen::Vector3d e = makeV3(q(0),q(1),q(2));
            //R = (n^2 - e'*e) * eye(3) + 2 * e * e' + 2 * n * crossMx(e);
            //Eigen::Matrix3d R = (n*n - e.dot(e))*Eigen::Matrix3d::Identity() + 2 * e * e.transpose() + 2 * n * crossMx(e);
    
            Eigen::Matrix3d R;

            // [ q0^2 - q1^2 - q2^2 + q3^2,           2*q0*q1 + 2*q2*q3,           2*q0*q2 - 2*q1*q3]
            // [         2*q0*q1 - 2*q2*q3, - q0^2 + q1^2 - q2^2 + q3^2,           2*q0*q3 + 2*q1*q2]
            // [         2*q0*q2 + 2*q1*q3,           2*q1*q2 - 2*q0*q3, - q0^2 - q1^2 + q2^2 + q3^2]
            R(0,0) = q[0]*q[0]-q[1]*q[1]-q[2]*q[2]+q[3]*q[3];
            R(0,1) = q[0]*q[1]*2.0+q[2]*q[3]*2.0;
            R(0,2) = q[0]*q[2]*2.0-q[1]*q[3]*2.0;
            R(1,0) = q[0]*q[1]*2.0-q[2]*q[3]*2.0;
            R(1,1) = -q[0]*q[0]+q[1]*q[1]-q[2]*q[2]+q[3]*q[3];
            R(1,2) = q[0]*q[3]*2.0+q[1]*q[2]*2.0;
            R(2,0) = q[0]*q[2]*2.0+q[1]*q[3]*2.0;
            R(2,1) = q[0]*q[3]*(-2.0)+q[1]*q[2]*2.0;
            R(2,2) = -q[0]*q[0]-q[1]*q[1]+q[2]*q[2]+q[3]*q[3];

            return R;
        }


        Eigen::Matrix4d quatPlus(Eigen::Vector4d const & q)
        {
            // [  q3,  q2, -q1, q0]
            // [ -q2,  q3,  q0, q1]
            // [  q1, -q0,  q3, q2]
            // [ -q0, -q1, -q2, q3]
            Eigen::Matrix4d Q;
            Q(0,0) =  q[3]; Q(0,1) =  q[2]; Q(0,2) = -q[1]; Q(0,3) =  q[0];
            Q(1,0) = -q[2]; Q(1,1) =  q[3]; Q(1,2) =  q[0]; Q(1,3) =  q[1];
            Q(2,0) =  q[1]; Q(2,1) = -q[0]; Q(2,2) =  q[3]; Q(2,3) =  q[2];
            Q(3,0) = -q[0]; Q(3,1) = -q[1]; Q(3,2) = -q[2]; Q(3,3) =  q[3];

            return Q;
        }

        Eigen::Matrix4d quatOPlus(Eigen::Vector4d const & q)
        {
            // [  q3, -q2,  q1, q0]
            // [  q2,  q3, -q0, q1]
            // [ -q1,  q0,  q3, q2]
            // [ -q0, -q1, -q2, q3]

            Eigen::Matrix4d Q;
            Q(0,0) =  q[3]; Q(0,1) = -q[2]; Q(0,2) =  q[1]; Q(0,3) =  q[0];
            Q(1,0) =  q[2]; Q(1,1) =  q[3]; Q(1,2) = -q[0]; Q(1,3) =  q[1];
            Q(2,0) = -q[1]; Q(2,1) =  q[0]; Q(2,2) =  q[3]; Q(2,3) =  q[2];
            Q(3,0) = -q[0]; Q(3,1) = -q[1]; Q(3,2) = -q[2]; Q(3,3) =  q[3];

            return Q;

        }

        Eigen::Vector4d qplus(Eigen::Vector4d const & q, Eigen::Vector4d const & p)
        {
            Eigen::Vector4d qplus_p;
            // p0*q3 + p1*q2 - p2*q1 + p3*q0
            qplus_p[0] = p[0]*q[3] + p[1]*q[2] - p[2]*q[1] + p[3]*q[0];
            // p2*q0 - p0*q2 + p1*q3 + p3*q1
            qplus_p[1] = p[2]*q[0] - p[0]*q[2] + p[1]*q[3] + p[3]*q[1];
            // p0*q1 - p1*q0 + p2*q3 + p3*q2
            qplus_p[2] = p[0]*q[1] - p[1]*q[0] + p[2]*q[3] + p[3]*q[2];
            // p3*q3 - p1*q1 - p2*q2 - p0*q0
            qplus_p[3] = p[3]*q[3] - p[1]*q[1] - p[2]*q[2] - p[0]*q[0];

            return qplus_p;
        }

        Eigen::Vector4d qoplus(Eigen::Vector4d const & q, Eigen::Vector4d const & p)
        {
            Eigen::Vector4d qoplus_p;
            // p0*q3 - p1*q2 + p2*q1 + p3*q0
            qoplus_p[0] = p[0]*q[3] - p[1]*q[2] + p[2]*q[1] + p[3]*q[0];
            // p0*q2 - p2*q0 + p1*q3 + p3*q1
            qoplus_p[1] = p[0]*q[2] - p[2]*q[0] + p[1]*q[3] + p[3]*q[1];
            // p1*q0 - p0*q1 + p2*q3 + p3*q2
            qoplus_p[2] = p[1]*q[0] - p[0]*q[1] + p[2]*q[3] + p[3]*q[2];
            // p3*q3 - p1*q1 - p2*q2 - p0*q0
            qoplus_p[3] = p[3]*q[3] - p[1]*q[1] - p[2]*q[2] - p[0]*q[0];

            return qoplus_p;
        }

        Eigen::Vector4d quatInv(Eigen::Vector4d const & q)
        {
            Eigen::Vector4d qret = q;
            invertQuat(qret);
            return qret;
        }

        void invertQuat(Eigen::Vector4d & q)
        {
            q.head<3>() = -q.head<3>();
        }


        Eigen::Vector3d qeps(Eigen::Vector4d const & q)
        {
            return q.head<3>();
        }
  
        double qeta(Eigen::Vector4d const & q)
        {
            return q[3];
        }



        Eigen::Vector4d axisAngle2quat(Eigen::Vector3d const & a)
        {
            // Method of implementing this function that is accurate to numerical precision from
            // Grassia, F. S. (1998). Practical parameterization of rotations using the exponential map. journal of graphics, gpu, and game tools, 3(3):29–48.
      
            // The threshold for an alternate computation is theta < the fourth root of epsilon
            static const double threshold = pow(std::numeric_limits<double>::epsilon(),1.0/4.0);
            double theta = a.norm();

            // na is 1/theta sin(theta/2)
            double na;
            if(theta < threshold)
            {
                static const double one_over_48 = 1.0/48.0;
                na = 0.5 + (theta * theta) * one_over_48;
            }
            else
            {
      
                na = sin(theta*0.5) / theta; 
            }
            Eigen::Vector3d axis = a*na;
            double ct = cos(theta*0.5);
            return Eigen::Vector4d(axis[0],axis[1],axis[2],ct);

        }

        Eigen::Vector3d quat2AxisAngle(Eigen::Vector4d const & q)
        {
            double theta = 2*acos( std::min(1.0, std::max(-1.0,qeta(q))) );
            Eigen::Vector3d a = qeps(q);
            double na = a.norm();
            if(fabs(theta) < 1e-12 || na < 1e-12)
                return Eigen::Vector3d::Zero();

            a /= na;
            a *= theta;
            return a;
        }

        Eigen::Matrix<double,4,3> quatJacobian(Eigen::Vector4d const & p)
        {
            Eigen::Matrix<double,4,3> J;
            // [  p3, -p2,  p1]
            // [  p2,  p3, -p0]
            // [ -p1,  p0,  p3]
            // [ -p0, -p1, -p2]
    
            J(0,0) =  p[3];
            J(0,1) = -p[2];
            J(0,2) =  p[1];
            J(1,0) =  p[2];
            J(1,1) =  p[3];
            J(1,2) = -p[0];
            J(2,0) = -p[1];
            J(2,1) =  p[0];
            J(2,2) =  p[3];
            J(3,0) = -p[0];
            J(3,1) = -p[1];
            J(3,2) = -p[2];

            return J*0.5;
        }

        Eigen::Vector4d updateQuat(Eigen::Vector4d const & q, Eigen::Vector3d const & dq)
        {
            // the following code is an optimized version of:
            // Eigen::Vector4d dq4 = axisAngle2quat(dq);
            // Eigen::Vector4d retq = quatPlus(dq4)*q;
            // return retq;

            Eigen::Vector4d dq3 = axisAngle2quat(dq);
            double ca = dq3[3];
            Eigen::Vector4d retq;
            retq[0] = q[0]*ca+dq3[0]*q[3]-dq3[1]*q[2]+dq3[2]*q[1];
            retq[1] = q[1]*ca+dq3[0]*q[2]+dq3[1]*q[3]-dq3[2]*q[0];
            retq[2] = q[2]*ca-dq3[0]*q[1]+dq3[1]*q[0]+dq3[2]*q[3];
            retq[3] = q[3]*ca-dq3[0]*q[0]-dq3[1]*q[1]-dq3[2]*q[2];

            return retq;
        }

        Eigen::Vector3d quatRotate(Eigen::Vector4d const & q_a_b, Eigen::Vector3d const & v_b)
        {
            return v_b + 2.0 * q_a_b.head<3>().cross(q_a_b.head<3>().cross(v_b) - q_a_b[3] * v_b);
        }

        Eigen::Vector4d quatRandom()
        {
            Eigen::Vector4d q_a_b;
            q_a_b.setRandom();
            q_a_b.array() -= 0.5;
            q_a_b /= q_a_b.norm();
            return q_a_b;
        }

        Eigen::Vector4d quatIdentity()
        {
            return Eigen::Vector4d(0,0,0,1);
        }

        Eigen::Matrix<double,3,4> quatS(Eigen::Vector4d q)
        {
            //   [  q3,  q2, -q1, -q0]
            // 2 [ -q2,  q3,  q0, -q1]
            //   [  q1, -q0,  q3, -q2]
            q *= 2.0;
      
            Eigen::Matrix<double,3,4> S;
            S <<
                q[3],  q[2], -q[1], -q[0],
                -q[2],  q[3],  q[0], -q[1],
                q[1], -q[0],  q[3], -q[2];

            return S;
        }

        Eigen::Matrix<double,4,3> quatInvS(Eigen::Vector4d q)
        {
            q *= 0.5;

            // 1 [  q3, -q2,  q1]
            // - [  q2,  q3, -q0]
            // 2 [ -q1,  q0,  q3]
            //   [ -q0, -q1, -q2]


            Eigen::Matrix<double,4,3> invS;
            invS <<
                q[3], -q[2],  q[1],
                q[2],  q[3], -q[0],
                -q[1],  q[0],  q[3],
                -q[0], -q[1], -q[2];
            return invS;
        }

        Eigen::Vector4d qslerp(const Eigen::Vector4d & q0, const Eigen::Vector4d & q1, double t)
        {
            if(t <= 0.0)
            {
                return q0;
            }
            else if(t >= 1.0)
            {
                return q1;
            }
            else
            {
                return qplus(q0, qexp(t * qlog( qplus(quatInv(q0),q1))));
            }
        }
        


    }} // namespace sm::kinematics

