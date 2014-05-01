Schweizer Messer is a grab bag of tools for programming mainly focussed on work
in robotics research requiring rapid prototyping.

That's it.

[![Build Status](http://129.132.38.183:8080/job/suitesparse/badge/icon)](http://129.132.38.183:8080/job/suitesparse/)//"

Among others, Schweizer Messer depends on boost, and you need to make sure that
your boost version works well with your gcc version (typically, this might not
be the case if you have the package boost from Ubuntu 12.04 but gcc > 4.6). The
following combinations have proven to work:

**boost** | **gcc** | **note**
----------|---------|----------
1.46.1    | 4.6.4   | Ubuntu 12.04
1.55      | 4.7     | Jenkins

