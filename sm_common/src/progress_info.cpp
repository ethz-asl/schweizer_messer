/*
 * show_progress.cpp
 *
 *  Created on: Jan 29, 2014
 *      Author: mbuerki
 */

#include <sm/progress_info.hpp>

#include <sm/assert_macros.hpp>
#include <stdexcept>

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

namespace sm {

void showProgress(double progress)
{
	SM_ASSERT_GE_DBG(std::runtime_error, progress, 0.0, "negative progress! shame on you!");
	SM_ASSERT_LE_DBG(std::runtime_error, progress, 1.0, "progress out of bounds!");

	std::cout << std::fixed << std::setprecision(2) << std::showpoint;
	if(progress >= 1.0)
	{
		std::cout << "\r" << "Complete!             " << std::endl;
	} else
	{
		std::cout << "\r" << 100*progress << "% complete ";
		std::cout.flush();
	}
}

void showProgress(size_t done, double all){	showProgress(static_cast<double>(done), all);}
void showProgress(size_t done, size_t all){	showProgress(static_cast<double>(done), static_cast<double>(all));}
void showProgress(double done, double all){
	SM_ASSERT_GE_DBG(std::runtime_error, all, 0, "about to divide by zero! aborting!");
	showProgress(done / all);
}



} /* namespace sm */
