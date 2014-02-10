/*
 * DatabaseConsistencyChecker.hpp
 *
 *  Created on: Jan 29, 2014
 *      Author: mbuerki
 */

#ifndef PROGRESS_INFO_HPP_
#define PROGRESS_INFO_HPP_

#include <cstddef>

namespace sm {

	void showProgress(double progress);
	void showProgress(size_t done, double all);
	void showProgress(size_t done, size_t all);
	void showProgress(double done, double all);

} /* namespace sm */

#endif /* PROGRESS_INFP_HPP_ */
