char		path[10000];
FILE		*file;
char		*line = NULL;
size_t		len = 0;
ssize_t		read;
int			static_files_count = 0;
regex_t		regex;
int			reti;

strcpy(path, RENDU_PATH);
strcat(path, "/get_next_line.c");
file = fopen(path, "r");

regcomp(&regex, "static .*;", 0);

while ((read = getline(&line, &len, file)) != -1) {
	reti = regexec(&regex, line, 0, NULL, 0);
	if (!reti) {
		static_files_count++;
	}
}

UT_ASSERT(static_files_count <= 1);
