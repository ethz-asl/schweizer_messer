#ifndef SM_KINEMATICS_PROPERTY_TREE_HPP
#define SM_KINEMATICS_PROPERTY_TREE_HPP

#include <sm/eigen/property_tree.hpp>
#include <sm/kinematics/Transformation.hpp>

namespace sm {
    namespace kinematics {
        
        inline sm::kinematics::Transformation transformationFromPropertyTree(const sm::ConstPropertyTree & config)
        {
            Eigen::Vector4d q = sm::eigen::quaternionFromPropertyTree( sm::ConstPropertyTree(config, "q_a_b") );
            q = q / q.norm();
            Eigen::Vector3d t = sm::eigen::vector3FromPropertyTree( sm::ConstPropertyTree(config, "t_a_b_a" ) );
            return sm::kinematics::Transformation(q,t);
        }

        
    } // namespace kinematics
} // namespace sm


#endif /* SM_KINEMATICS_PROPERTY_TREE_HPP */
