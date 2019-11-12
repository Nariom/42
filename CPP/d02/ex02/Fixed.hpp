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
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;
	Fixed &	operator++( void );
	Fixed	operator++( int );
	Fixed &	operator--( void );
	Fixed	operator--( int );

	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);
	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);

private:

	int			_rawBits;
	int const	_fractionalBits;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif // FIXED_CLASS_HPP