#include <stdio.h>
#include <stdlib.h>

int checkIO(FILE *);
void solve(FILE *, FILE *);

// initialize file as global arguments

int main(int argc, char const *argv[])
{
	int t;
	FILE *in = fopen("in.txt", "r");
	FILE *out = fopen("out.txt", "w");
	FILE *err = fopen("errlog.txt", "w");

	if (!checkIO(in))
	{
		fprintf(err, "%s\n", "Input file not exist, create a new input file !");
		exit(0);
	}

	fscanf(in, "%d", &t);
	while (t--)
	{
		solve(in, out);
	}

	fclose(in);
	fclose(out);
	fclose(err);

	return 0;
}

int checkIO(FILE *in)
{
	return in == NULL ? 0 : 1;
}

void solve(FILE *in, FILE *out)
{
	int year, age = 0;

	fscanf(in, "%d", &year);

	if (year > 2022)
	{
		fprintf(out, "%s\n", "Vui long nhap lai nam sinh");
		return;
	}

	age = 2022 - year;
	if (age < 6)
		fprintf(out, "%s\n", "Tre em");
	else if (age < 11)
		fprintf(out, "%s\n", "HS Cap I");
	else if (age < 15)
		fprintf(out, "%s\n", "HS Cap II");
	else if (age < 18)
		fprintf(out, "%s\n", "HS Cap III");
	else if (age < 40)
		fprintf(out, "%s\n", "Thanh nien");
	else if (age < 60)
		fprintf(out, "%s\n", "Trung nien");
	else
		fprintf(out, "%s\n", "Nguoi gia");
}