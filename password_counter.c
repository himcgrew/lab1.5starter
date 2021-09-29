#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>

#define FILESZ 43838
#define TBLSZ FILESZ * 1.25
#define LINE_LEN 100
#define DATABASE "passwords.db"

/**
 * You may find this useful.
 *
 * Allocates storage for an integer. Kills the program
 * if it can't.
 */
int* allocInt() {
    int* intloc = malloc(sizeof(int));
    if (!intloc) {
        fprintf(stderr, "Allocation failure.\n");
        exit(1);
    }
    return intloc;
}

/**
 * Counts the occurrence of each password in a password
 * file.  Stores counts in an hsearch(3) hash table.
 *
 * This function assumes that you have already called
 * the hcreate function.
 *
 * Remember that each hash table entry has two parts:
 *  - a key
 *  - a data value
 *
 * You are going to store the password as a key, and
 * the password count as the data value.
 *
 * Keys are _always_ of type char*. Therefore the table
 * only stores a pointer to some memory YOU allocate.
 *
 * Data values are type void*, meaning that they are
 * "pointers to anything".  Again, they point at data
 * YOU allocate.  Since they are void*, you will also
 * need to cast the pointer to the appropriate type
 * on retrieval or C will do the wrong thing.
 *
 * Finally, hdestroy() only deallocates memory reserved
 * for keys; YOU need to deallocate memory reserved
 * for data values.  This is why the function takes
 * the `keys` parameter: this should be an array
 * containing pointers to all of the table's keys.
 *
 * Function returns the number of unique passwords.
 */
int tabulate(char* filename, char** keys) {
    char line[LINE_LEN];
    int keyindex = 0;

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Cannot read file '%s'!\n", filename);
        exit(1);
    }

    // read file, line by line
    while(fgets(line, LINE_LEN, fp)) {
	// split by comma
        char* u = strtok(line, ",");
	char* p = strtok(NULL, "\n");

	/* NOTE: strtok returns a pointer into the original string,
         *       replacing the delimiter with a null character.
         *   line, originally:
         * [u|s|e|r|n|a|m|e|,|p|a|s|s|w|o|r|d|\n|\0]
         *
         *   line, after running strtok above twice:
         * [u|s|e|r|n|a|m|e|\0|p|a|s|s|w|o|r|d|\0|\0]
         *  ^                  ^
         *  u                  p
         */
        // for debugging: uncomment to see username and password
	//printf("username: '%s', password: '%s'\n", u, p);
        
        /* TODO START: your code should go here */
        /* TODO END: your code should end here */
    }

    fclose(fp);

    return keyindex;
}

int main() {
    // array for hash table keys
    char* keys[FILESZ];

    // TODO: create hash table

    // TODO: call tabulate to count passwords

    // TODO: print counts

    // TODO: deallocate table, including every data value
}
