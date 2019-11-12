#include <iostream>

template< typename T, typename U, typename V >
void	iter( T * arr, U size, V & fct ) {
	for (U i = 0; i < size; ++i)
		fct((*arr)[i]);
}

template< typename T >
void	output( T t ) {
	std::cout << t << std::endl;
}

void	charOutput(char s) {
	std::cout << s << std::endl;
}

int	main( void ) {

	char			str[5] = {'b', 'l', 'a', 'a', 'h'};
	int 			nbs[5] = {1, 2, 3, 4, 5};
	std::string		str2 = "Blahblahblah";
	unsigned int	n = 12;
 
 	std::cout << "iter(&char[5], int, template_fct)" << std::endl;
 	iter(&str, 5, output<char>);
 	std::cout << "iter(&int[5], int, template_fct)" << std::endl;
	iter(&nbs, 5, output<int>);
	std::cout << "iter(&std::string, unsigned int, fct)" << std::endl;
	iter(&str2, n, charOutput);

}