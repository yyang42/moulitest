# Moulitest

This repository contains tests for several projects done at 42. Please use the tests with caution and check the tests source code.

Correction: A failed test doesn't necessarily mean that the tested code is wrong. The test suite doesn't correct for you, **you are the corrector**.

At the moment, the available tests are:

- libft (58 functions and 25+ other generic functions)
- get_next_line (with handling of multiples file descriptors)
- ft_ls comming soon ...

Feedbacks and pull requests are welcome. You can also raise issues on github directly.

![Sample](http://i.imgur.com/443xC3D.png)

Install
-------

	$ cp config.json.template config.json
	# ==> EDIT config.json and replace with your OWN VALUES <==

	# WARNING: Unnecessary trailing commas are not allowed in .json files.
	# e.g.      ["aaa", "bbb"]  GOOD
	#           ["aaa", "bbb",] BAD

Usage
-----

####Libft

	$ cd libft_tests
	$ ./test --help
	
####Get Next Line

	$ cd get_next_line_tests
	$ ./test --help

Do not use file descriptor 1 for debugging to avoid conflict with the tests. Use the file descriptor 2 instead. Example:

	write(2, "abc", 3);

**WARNING:** If the test stops in the middle, it certainly means that the test is waiting for an input from your get_next_line function but nothing is returned.

Credits
------

The test framework and many libft tests are based on the work done by Maxime Bacoux (mbacoux)
Here is the original repository: https://github.com/Nax/libft-test

Other interesting tests have also been included for convenience: Mouli-nator and Qperez test suite.
