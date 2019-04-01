#include <unistd.h>
void printHexedByte(unsigned char byte)
{
	char hexedByte;

	int first4bits = (byte >> 4);
	hexedByte = ((first4bits>= 0 && first4bits <= 9) ? first4bits + '0' : first4bits + 'a' - 10);	
	write(1, &hexedByte, 1); 

 	int last4bit = (byte & 0xf);
	hexedByte = ((last4bit>= 0 && last4bit <= 9) ? last4bit + '0' : last4bit + 'a' - 10);
	write(1, &hexedByte, 1);
}

void printDotforByte(unsigned char byte)
{
	char  c = (byte >= 32 && byte <= 126) ? byte : '.';
	write(1, &c, 1);
}

void putSpaces(int restBytes)
{
	int size;
	if (restBytes == 0)
		return ;
	if ((16 - restBytes) % 2 == 1)
		size = ((16 - restBytes) / 2 * 5) + 3;
	else 
		size = (16 - restBytes) / 2 * 5;
	while (size--)
		write(1, " ", 1);
}

void	print_memory(const void *addr, size_t size)
{
	if (size <=0 || !addr)
		return ;
	
	const unsigned char * addrforDots = addr;
	const unsigned char * addr1 = addr;
	size_t rows = size / 16;
	size_t restBytes = size % 16;
	int i;
	while (rows--)
	{
		i = 0;
		while (i < 16)
		{
			printHexedByte((*addr1));
			addr1++;
			i++;
			if (i % 2 == 0)
				write(1, " ", 1);
		}
		i = 0;
		while (i < 16)
		{
			printDotforByte(((*addrforDots)));
			addrforDots++;
			i++;
		}
		write(1, "\n", 1);
 	}
	i = 0;
	size_t restBytes2 = restBytes;
	while (restBytes--)
	{
		printHexedByte((*addr1));
		addr1++;
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	putSpaces(restBytes2);
	while (restBytes2--)
	{
		printDotforByte((*addrforDots));
		addrforDots++;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	char str[5] = "012	";
	// int		tab[15] = {37729000, 58597, 59111,
	// 	59625, 60139, 60653, 61167, 61681, 62195, 62709, 63223, 63737, 64251,
	// 64765, 65279};

	print_memory(str, 50);
	return (0);
}