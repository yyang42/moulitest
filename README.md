# Moulitest

This repository contains tests for several projects done at 42.

Correction: A failed test doesn't necessarily mean that the tested code is wrong. The test suite doesn't correct for you, **you are the corrector**. As general rule, only use tests that you understand.

Feedbacks and pull requests are welcome. You can also raise issues on github directly.

![Sample](http://i.imgur.com/3p0Xg7Z.png)

Install
---

	$ cp config.ini.template config.ini
	# ==> EDIT config.ini and replace with your own config values <==

Usage
---
	
	make # yes that's it

#### Notes for get_next_line

Do not use file descriptor 1 for debugging to avoid conflict with the tests. Use the file descriptor 2 instead. Example:

	write(2, "abc", 3);

**WARNING:** If the tests stop in the middle, it could mean that your get_next_line is waiting for an input from the file descriptor but nothing is coming.

Credits
---

The test framework and many libft tests are based on the work done by Maxime Bacoux (mbacoux)
Here is the original repository: https://github.com/Nax/libft-test
