// It is extremely important to use this header
// if you are using the numpy_eigen interface
#include <numpy_eigen/boost_python_headers.hpp>

void export_Vertex();
void export_Edge();
void export_PoseGraph();

BOOST_PYTHON_MODULE(libsm_pose_graph_python)
{
  export_Vertex();
  export_Edge();
  export_PoseGraph();
}
