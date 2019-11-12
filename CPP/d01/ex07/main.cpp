#include <iostream>
#include <fstream>
#include <string>

std::string replace_all( std::string line, std::string from, std::string to )
{
	for ( std::string::size_type i = 0; (i = line.find(from, i)) != std::string::npos; )
	{
		line.replace(i, from.length(), to);
		i += to.length() - from.length() + 1;
	}
	return line;
}

int	main( int ac, char *av[] )
{

	if ( ac != 4 ) {
		std::cout << "usage: " << av[0] << " filename s1 s2" << std::endl;
		return -1;
	}

	std::string		from = av[2];
	std::string		to = av[3];

	if ( from.empty() || to.empty() ) {
		std::cout << "You must provide non empty strings." << std::endl;
		return -1;
	}

	std::string		filename = av[1];
	std::ifstream	ifs(av[1]);

	if ( !ifs.is_open() ) {
		std::cout << filename << " : file not found." << std::endl;
		return -1;
	}
	filename.append(".replace");

	std::string		line;
	std::ofstream	ofs(filename.c_str());

	while ( std::getline(ifs, line) )
		ofs << replace_all(line, from, to) << std::endl;
	ifs.close();
	ofs.close();

}