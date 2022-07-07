
//setting values progmatically
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


// trgb >> 24 =/ (trgb >> 24) - the first one pushes everything down 8 bits
//ints are stored R -> L - need to bit shift each value according to the amount of bits backwards
//this function retrieves int values from an encoded TRGB int.
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF); //'>>' is an arithmatic signed shift // Bitwise AND'&' operator
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF); //sets the RED bits as the lower 8 - everything else to 0 - and the RED bits set to one stay
}
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF); //sets the GREEN bits as the lower 8 - everything else to 0 - and the GREEN bits set to one stay
}

int	get_b(int trgb)
{
	return (trgb & 0xFF); //sets the upper 24 bits to 0 - and only turn on the bits in the lower 8 which are set to 1 //BLUE
}


//function to create necessary colours
int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}