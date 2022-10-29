#include <stdio.h>
#include <stdlib.h>

int checkIO(FILE*);
int checkTriangle(float, float, float);
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

int checkTriangle(float a, float b, float c) {
	return (a + b <= c || a + c <= b || b + c <= a) ? 0 : 1;
}

void solve(FILE* in, FILE* out) {
	float a, b, c;

	fscanf(in, "%f %f %f", &a, &b, &c);
	if (checkTriangle(a, b, c))
		fprintf(out, "%s\n", "Co la tam giac");
	else
		fprintf(out, "%s\n", "Khong la tam giac");
}