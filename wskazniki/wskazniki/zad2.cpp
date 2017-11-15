void zad_2()
{
	int t[10];
	int *w = t;

	for (int i = 0; i< 10; ++i)
	{
		*w = i;
		w++;
	}
}