This repository contains tests of several projects done at 42. At the moment, the available tests are:

- libft (58 functions and 25+ other generic functions)
- get_next_line (with handling of multiples file descriptors)

Feedbacks and pull requests are welcome. You can also raise issues on github directly.

Install
-------

	$ cp config.json.template config.json
	# ==> EDIT config.json and replace with your OWN VALUES <==

	# WARNING: Trailing commas are not allowed in json files at the end of a list.
	# e.g
	#	["aaa", "bbb"] GOOD
	#	["aaa", "bbb",] BAD

Usage Libft
-----

	$ cd libft_tests
	$ ./test --help
	
Usage Get Next Line
-----

	$ cd get_next_line_tests
	$ ./test --help

Do not use file descriptor 1 for debugging to avoid conflict with the tests. Use the file descriptor 2 instead. Example:

	write(2, "abc", 3);

Credit
------

The test framework and many libft tests are based on the work done by Maxime Bacoux (mbacoux)
Here is the original repository: https://github.com/Nax/libft-test

Other interesting tests have also been included for convenience: Mouli-nator and Qperez test suite.
