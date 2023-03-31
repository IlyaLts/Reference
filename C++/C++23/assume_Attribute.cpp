void process(int x)
{
	// An optimization hint
    [[assume(x > 0)]];
    int y = 100 / x;
}