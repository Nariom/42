#include <cstdlib>
#include <iostream>
#include "Data.hpp"

void *	serialize( void ) {

	std::string const	alphanum = "abcdefghijklmnopqrstuvwxyz0123456789";
	unsigned int const	len = 16 + sizeof(int);
	char *				randStuff = new char[len];
	int					randNum;
	unsigned int		i = 0;

	while (i < 8)
		randStuff[i++] = alphanum[rand() % 36];
	randNum = rand();
	char *				conv = reinterpret_cast<char *>(&randNum);
	for (unsigned int j = 0; j < sizeof(int); ++j)
		randStuff[i++] = conv[j];
	while (i < len)
		randStuff[i++] = alphanum[rand() % 36];
	return reinterpret_cast<void *>(randStuff);

}

Data *	deserialize( void * raw ) {

	char			*rawData = reinterpret_cast<char *>(raw);
	char			str[9];
	unsigned int	i = 0;
	Data *	data = new Data;

	while (i < 8) {
		str[i] = rawData[i];
		++i;
	}
	str[i] = 0;
	data->s1 = str;
	data->n = *(reinterpret_cast<int *>(rawData + 8));
	i += sizeof(int);
	while (i < 16 + sizeof(int)) {
		str[i - 8 - sizeof(int)] = rawData[i];
		++i;
	}
	str[i] = 0;
	data->s2 = str;

	return data;

}

int		main( void ) {
	void *	raw = serialize();
	Data *	data = deserialize(raw);
	std::cout << data->s1 << " " << data->n << " " << data->s2 << std::endl;
}