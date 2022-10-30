#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

int checkIO(FILE*);
float* solveLinearEquation(float, float);
float* solveQuadraticEquation(float, float, float);
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

float* solveLinearEquation(float a, float b) {
	float* x = (float*) malloc(3 * sizeof(float));
	if (a != 0.0) {
		x[0] = -b / a;
		x[2] = 1;
	}
	else {
		if (b == 0.0) {
			x[2] = 0;
		}
		else
			x[2] = -1;
	}
	return x;

}

float* solveQuadraticEquation(float a, float b, float c) {
	float* x = (float*) malloc(3 * sizeof(float));
	if (a == 0) {
		return solveLinearEquation(b, c);
	}
	else {
		float delta = b * b - 4 * a * c;
		if (delta < 0) {
			x[2] = -1;
		}
		else if (delta == 0) {
			x[2] = 1;
			x[0] = x[1] = -b / (2 * a);
		}
		else {
			x[2] = 2;
			x[0] = (-b + sqrt(delta)) / (2 * a);
			x[1] = (-b - sqrt(delta)) / (2 * a);
		}
	}

	return x;
}

void solve(FILE* in, FILE* out) {
	float a, b, c, *x;

	fscanf(in, "%f %f %f", &a, &b, &c);
	x = solveQuadraticEquation(a, b, c);

	switch ((int)x[2]) {
	case -1:
		fprintf(out, "%s\n", "Vo nghiem");
		break;
	case 0:
		fprintf(out, "%s\n", "Vo so nghiem");
		break;
	case 1:
		fprintf(out, "%s %.2f\n", "Co mot nghiem hoac nghiem kep la:", x[0]);
		break;
	case 2:
		fprintf(out, "%s %s %.2f %s %.2f\n", "Co hai nghiem phan biet lan luot la:", "x1 =", x[0], "x2 =", x[1]);
		break;
	default:
		break;
	}


	free(x);

}
