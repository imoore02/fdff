struct 
//totally forgot how to build this but do that thing

graph count_matricies(int filedes, graph matrix)
{
	char *string;
	int counter;

	counter = 0;
	string = get_next_line(filedes);
	matrix.x = ft_strlen(string);
	while(string)
	{
		string = get_next_line(filedes);
		counter++;
	}
	matrix.y = counter;
	return(matrix);
}

int	ft_strlen(const char *r)
{
	int		w;

	w = 0;
	while (r[w])
		w++;
	return (w);
}