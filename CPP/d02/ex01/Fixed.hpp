#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( int const n );
	Fixed( float const f );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed &	operator=(Fixed const & rhs);

private:

	int			_rawBits;
	int const	_fractionalBits;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif // FIXED_CLASS_HPP