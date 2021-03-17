# Schweizer Messer

Schweizer Messer is a grab bag of tools for programming mainly focussed on work
in robotics research requiring rapid prototyping.

That's it.

[![Build Status](https://jenkins.asl.ethz.ch/buildStatus/icon?job=schweizer_messer)](https://jenkins.asl.ethz.ch/job/schweizer_messer/)

## Recent BREAKING changes

* `numpy_eigen` moved into its [own package](https://github.com/ethz-asl/numpy_eigen/). The last revision of this repository still containing it is tagged as `with_numpy_eigen`.

## Dependencies

... can be found here [dependencies.rosinstall](dependencies.rosinstall)

## If you have trouble compiling

... make sure to:

* Use gcc 4.7 ([How to install on Ubuntu 12.04](http://charette.no-ip.com:81/programming/2011-12-24_GCCv47/))
* Use a boost version that is compatible with gcc 4.7 (>= 1.51)

On Ubuntu 12.04, if your ubuntu-installed ROS depends on the ubuntu-installed
boost you can simply download a later boost and install it from source - it
will install to "/usr/local" per default (verify this though), where the
Schweizer Messer build will look for it.

