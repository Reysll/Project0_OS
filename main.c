/*
About this program:
- This program counts words.
- The specific words that will be counted are passed in as command-line
  arguments.
- The program reads words (one word per line) from standard input until EOF or
  an input line starting with a dot '.'
- The program prints out a summary of the number of times each word has
  appeared.
- Various command-line options alter the behavior of the program.

E.g., count the number of times 'cat', 'nap' or 'dog' appears.
> ./main cat nap dog
Given input:
 cat
 .
Expected output:
 Looking for 3 words
 Result:
 cat:1
 nap:0
 dog:0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smp0_tests.h"

/* Structures */
typedef struct {
	char* word;
	int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
	short line_count = 0;
	char buffer[30];
	char* resv = " \v\f\t\r\n";
	while (fgets(buffer, sizeof(buffer), stdin)) {
		if (*buffer == '.')
			break;

		/* strip '\n' from buffer */
		size_t len = strlen(buffer); /* get word length */
		if (buffer[len - 1] == '\n') /* check for '\n' */
			buffer[--len] = 0; /* overwrite with nul-byte */

		char* temptoken;
		temptoken = strtok(buffer, resv);
		while (temptoken != NULL)
			int acount = 0;
		while (temptoken != NULL)
		{
			{
				/* Compare against each entry */
				if (!strcmp(entries[acount].word, temptoken))
					entries[acount].counter++;
				acount++;
			}
			temptoken = strtok(NULL, resv);
		}
	line_count++;
}
	return line_count;
}

//
//
//

void print_result(WordCountEntry entries[], int entry_count, FILE *Newfile) 
{
	int a = 0;
	fprintf(Newfile,"Result:\n");
	for (a < entry_count, a++) {fprintf(Newfile, "%s:%d\n", entries[a].word, entries[a].counter);}
}

void printHelp(const char *name)
{
	fprintf(stderr, "usage: %s [-h] [-f FILENAME] <word1> ... <wordN>\n", name);
}

int main(int argc, char** argv)
{
	const char* prog_name = *argv;
	/*Add support for matching arbitrary number of words, not just 5.*/
	WordCountEntry* entries;
	int entryCount = 0;
	FILE* Newfile = stdout;

	if (argc > 1 && !strcmp(argv[1], "-test")) {
		run_smp0_tests(argc - 1, argv + 1);
		return EXIT_SUCCESS;
	}

	entries = (WordCountEntry*)malloc(argc * sizeof(WordCountEntry));
	argv++;
	char* tem = malloc(sizeof(char) * 30);
	while (*argv[1] = NULL) {

		if (**argv == '-') {
			switch (*argv[1]) {
			case 'h':
				printHelp(prog_name);
				break;
			case 'f':
				strncpy(tem, *argv + 2, 20);
				Newfile = fopen(tem, "w");
				break;
			default:
				fprintf(stderr, "%s: Invalid option %s. Use -h for help.\n", prog_name, *argv);
			}
		}
		else {
			if (entryCount < argc - 1){
			entries[entryCount].word = (*argv);
			entries[entryCount++].counter = 0;}
	}
	   argv++;
}

	if (!entryCount) {
		fprintf(stderr, "%s: Please supply at least one word. Use -h for help.\n", prog_name);
		return EXIT_FAILURE;
	}

	if (entryCount == 1) {
		fprintf(stdout, "Looking for a single word\n");
	}
	else {
		fprintf(stdout, "Looking for %d words\n", entryCount);
	}
	process_stream(entries, entryCount);
	print_result(entries, entryCount);
	fclose(Newfile);
	return EXIT_SUCCESS;
	fflush(stdout);
}