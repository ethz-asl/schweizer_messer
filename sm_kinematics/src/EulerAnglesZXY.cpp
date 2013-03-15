/******************************************************************************
 * Copyright (C) 2013 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "sm/kinematics/EulerAnglesZXY.h"

#include <sm/assert_macros.hpp>

namespace sm {
  namespace kinematics {

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

    EulerAnglesZXY::EulerAnglesZXY() {
    }

    EulerAnglesZXY::EulerAnglesZXY(const EulerAnglesZXY& other) :
        RotationalKinematics(other) {
    }

    EulerAnglesZXY& EulerAnglesZXY::operator = (const EulerAnglesZXY& other) {
      if (this != &other) {
        RotationalKinematics::operator=(other);
      }
      return *this;
    }

    EulerAnglesZXY::~EulerAnglesZXY() {
    }

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/


    Eigen::Matrix3d EulerAnglesZXY::parametersToRotationMatrix(
        const Eigen::Vector3d& parameters, Eigen::Matrix3d * S ) const {
      if (S != NULL)
        SM_THROW(Exception,"Not implemented")

      const double cx = cos(parameters(1));
      const double sx = sin(parameters(1));
      const double cy = cos(parameters(2));
      const double sy = sin(parameters(2));
      const double cz = cos(parameters(0));
      const double sz = sin(parameters(0));

      return (Eigen::Matrix3d() <<
        cz * cy - sz * sx * sy, -sz * cx, cz * sy + sz * sx * cy,
        sz * cy + cz * sx * sy, cz * cx, sz * sy - cz * sx * cy,
        -cx * sy, sx, cx * cy).finished();
    }

    Eigen::Vector3d EulerAnglesZXY::rotationMatrixToParameters(
        const Eigen::Matrix3d& rotationMatrix) const {
      const double sx = rotationMatrix(2, 1);
      const double r_x = asin(sx);
      const double ty = -rotationMatrix(2, 0) / rotationMatrix(2, 2);
      const double r_y = atan(ty);
      const double tz = -rotationMatrix(0, 1) / rotationMatrix(1, 1);
      const double r_z = atan(tz);
      return Eigen::Vector3d(r_z, r_x, r_y);
    }

    Eigen::Matrix3d EulerAnglesZXY::parametersToSMatrix(
        const Eigen::Vector3d& parameters) const {
      SM_THROW(Exception,"Not implemented")
      return Eigen::Matrix3d::Zero();
    }

    Eigen::Vector3d EulerAnglesZXY::angularVelocityAndJacobian(
        const Eigen::Vector3d& p, const Eigen::Vector3d& pdot,
        Eigen::Matrix<double, 3, 6>* Jacobian) const {
      SM_THROW(Exception,"Not implemented")
      return Eigen::Vector3d::Zero();
    }

  }
}
