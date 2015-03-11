void spiral2DArray()
{
	int R, C;
	int i, l, s, t, x, y;
	int start[22] = {0, };

	R = 7;
	C = 6;
	l = (min(R, C) + 1) / 2;
	for (i = 0; i < l; i++)
	{
		start[i + 1] = start[i] + R + R + C + C - i * 8 - 4;
	}

	l = R * C;
	for (i = 0; i < l; i++)
	{
		x = i % C;
		y = i / C;
		s = 100;
		s = min(s, x);
		s = min(s, C - x - 1);
		s = min(s, y);
		s = min(s, R - y - 1);

		if (y == s)
		{
			t = start[s] + x - s;
		}
		else if (y == R - s - 1)
		{
			t = start[s + 1] - (R - s - s - s - 1) - x;
		}
		else if (x == s)
		{
			t = start[s + 1] - y + s;
		}
		else
		{
			t = start[s] + (C - s - s - s) + y - 1;
		}
		printf("%3d ", t);
		if (x == C - 1) cout << "\n";
	}
}
