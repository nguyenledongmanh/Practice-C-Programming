#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int checkIO(FILE*);
int findMin(int, int);
void solve(FILE*, FILE*);

// initialize file as global arguments


int main(int argc, char const *argv[])
{
	int t;
	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w");
	FILE* err = fopen("errlog.txt", "w");


	if (!checkIO(in)) {
		fprintf(err, "%s\n", "Input file not exist, create a new input file !");
		exit(0);
	}

	fscanf(in, "%d", &t);
	while (t--) {
		solve(in, out);
	}


	fclose(in);
	fclose(out);
	fclose(err);

	return 0;
}

int checkIO(FILE* in) {
	return in == NULL ? 0 : 1;
}

int findMin(int a, int b) {
	return a < b ? a : b;
}

void solve(FILE* in, FILE* out) {
	int a, b, c;
	int min = INT_MIN;
	fscanf(in, "%d %d %d", &a, &b, &c);
	min = findMin(a, b);

	if (min > c)
		min = c;
	fprintf(out, "%d\n", min);
}