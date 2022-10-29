#include <stdio.h>
#include <stdlib.h>

int checkIO(FILE*);
char* convertToString(int);
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

char* convertToString(int a) {
	char* out_num = "";
	switch (a) {
	case 1:
		out_num = "mot";
		break;
	case 2:
		out_num = "hai";
		break;
	case 3:
		out_num = "ba";
		break;
	case 4:
		out_num = "bon";
		break;
	case 5:
		out_num = "nam";
		break;
	case 6:
		out_num = "sau";
		break;
	case 7:
		out_num = "bay";
		break;
	case 8:
		out_num = "tam";
		break;
	case 9:
		out_num = "chin";
		break;
	default:
		out_num = "";
		break;
	}
	return out_num;
}

void solve(FILE* in, FILE* out) {
	int n, hundreds, tens, ones;
	fscanf(in, "%d", &n);
	hundreds = n / 100;
	if (n % 100 == 0)
		fprintf(out, "%d tram\n", hundreds);
	else {
		tens = (n - hundreds * 100) / 10;
		ones = n - (hundreds * 100) - (tens * 10);
		switch (tens) {
		case 0:
			fprintf(out, "%s tram linh %s\n", convertToString(hundreds), convertToString(ones));
			break;
		case 1:
			fprintf(out, "%s tram muoi %s\n", convertToString(hundreds), convertToString(ones));
			break;
		default:
			fprintf(out, "%s tram %s muoi %s\n", convertToString(hundreds), convertToString(tens), convertToString(ones));
			break;
		}		
	}
}