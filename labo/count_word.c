int count_word(const char *sentence)
{
	int count = 0;
	const char *image = *sentence;

	while (!image)
	{
		if (*image =! " " && *image =! "\n" && *image =! "\t")
			if (*image =! "
