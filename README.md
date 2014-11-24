# Moulitest

[![Issue Stats](http://issuestats.com/github/yyang42/moulitest/badge/pr)](http://issuestats.com/github/yyang42/moulitest)
[![Issue Stats](http://issuestats.com/github/yyang42/moulitest/badge/issue)](http://issuestats.com/github/yyang42/moulitest)

This repository contains tests for several projects done at 42. Please use the tests with caution and check the tests source code.

Correction: A failed test doesn't necessarily mean that the tested code is wrong. The test suite doesn't correct for you, **you are the corrector**.

At the moment, the available tests are:

- libft (58 functions and 25+ other generic functions)
- get_next_line (with handling of multiples file descriptors)
- ft_ls

Feedbacks and pull requests are welcome. You can also raise issues on github directly.

![Sample](http://i.imgur.com/3p0Xg7Z.png)

Install
---

	$ cp config.json.template config.json
	# ==> EDIT config.json and replace with your OWN VALUES <==

	# WARNING: Unnecessary trailing commas are not allowed in .json files.
	# e.g.      ["aaa", "bbb"]  GOOD
	#           ["aaa", "bbb",] BAD

Usage
---

####Libft

	$ cd libft_tests
	$ ./test --help

####Get Next Line

	$ cd get_next_line_tests
	$ ./test

Do not use file descriptor 1 for debugging to avoid conflict with the tests. Use the file descriptor 2 instead. Example:

	write(2, "abc", 3);

**WARNING:** If the tests stop in the middle, it could mean that your get_next_line is waiting for an input from the file descriptor but nothing is coming.

####Ft ls

	$ cd ft_ls_tests
	$ ./test

Credits
---

The test framework and many libft tests are based on the work done by Maxime Bacoux (mbacoux)
Here is the original repository: https://github.com/Nax/libft-test

Other interesting tests have also been included for convenience: Mouli-nator and Qperez test suite.
