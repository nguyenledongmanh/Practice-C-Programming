#include <stdio.h>
#include <stdlib.h>

int checkIO(FILE*);
int check(int);
void solve(FILE*, FILE*);

// initialize file as global arguments


int main(int argc, char const *argv[])
{
	int t, n;
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

int check(int n) {
	return n % 2 == 0 ? 1 : 0;
}

void solve(FILE* in, FILE* out) {

	int n;

	fscanf(in, "%d", &n);

	if (check(n))
		fprintf(out, "%s\n", "Ban da nhap vao so chan");
	else
		fprintf(out, "%s\n", "Ban da nhap vao so le");
}