# Moulitest: Test your 42 projects

This repository contains tests for several projects done at 42.

Feedbacks, github issues and pull requests are welcome. You can also raise issues on github directly.

Quick Start
---
Create the config file

	cp config.ini.template config.ini

Edit the config file

	vim config.ini # add your configs

Run tests
	
	make
	

Notes
---
GNL

* If the tests stop in the middle, it could mean that your get_next_line is waiting for an input from the file descriptor but nothing is coming.

Credits
---

The test framework and many libft tests are based on the work done by Maxime Bacoux (mbacoux)
Here is the original repository: https://github.com/Nax/libft-test
