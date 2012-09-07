// Bring in gtest
#include <gtest/gtest.h>
#include <boost/cstdint.hpp>

#include <sm/random.hpp>

// Bring in the Matlab Interface
#include <sm/matlab/Engine.hpp>


int main(int argc, char **argv)
{
	// create a new engine
	sm::matlab::Engine engine;
	
	if (!engine.initialize())
	{
		std::cout<<"Could not start Matlab"<<endl;
		return -1;
	}
	
	if (!engine.good())
	{
		std::cout<<"Matlab interface not working properly"<<endl;
		return -1;
	}
	
	// create a few variables 
	double a = sm::random::rand();
	double b = sm::random::rand();
	Eigen::Matrix3d A = Eigen::Matrix2d::Random();
    Eigen::Matrix3d B = Eigen::Matrix3d::Random();
	
	// and send them to Matlab
	engine.put("a", a);
	engine.put("b", b);
	engine.putEigen("A", A);
	engine.putEigen("B", B);

	// do some operations
	engine.executeCommand("plot(A)");
	engine.executeCommand("C = A*B");
	engine.executeCommand("c = a*b");
	
	// create containers
	double c;
	Eigen::MatrixXd C;
	
	// retrieve data
	engine.getEigen("c", c);
	engine.getEigen("C", C);
	
	// go into command line mode
	engine.openCommandLine();
	
	return 0;
	// session is automatically terminated when engine goes out of scope
}
