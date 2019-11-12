#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP
# include <string>
# include <typeinfo>
# include <exception>

class Convertor {

private:

	Convertor( void );
	Convertor( Convertor const & src );

	Convertor &	operator=(Convertor const & rhs);

	std::string const	_value;

public:

	Convertor( std::string value );
	~Convertor( void );

	std::string const	getValue( void ) const;

	char				charConvert( void );

};

std::ostream &	operator<<( std::ostream & o, Convertor const & rhs );

#endif // CONVERTOR_HPP