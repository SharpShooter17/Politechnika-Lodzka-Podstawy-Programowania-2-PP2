extern void dump(unsigned char *w, int size);

void zad_5()
{
	int t[] = { 16909060, 84281096, 151653132 };

	dump((unsigned char*)t, 3 * sizeof(int));
}