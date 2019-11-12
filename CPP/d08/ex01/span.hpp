#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <exception>
# include <list>
# include <vector>
# include <iterator>
# include <cstdlib>

class span {

private:

	std::list<int> *	_list;
	unsigned int const	_size;

	span( void );

	span &	operator=( span const & rhs );

public:

	span( unsigned int n );
	span( span const & src );
	~span( void );

	unsigned int	getSize( void ) const;
	void			addNumber( int n );
	void			addNumber(
						std::vector<int>::iterator first,
						std::vector<int>::iterator last
					);
	int				shortestSpan( void );
	int				longestSpan( void );

	class OutOfBoundException : public std::exception {
	public:
		OutOfBoundException( void );
		OutOfBoundException( OutOfBoundException const & src );
		~OutOfBoundException( void ) throw();
		OutOfBoundException &	operator=(OutOfBoundException const & rhs);
		virtual char const *	what() const throw();
	};

};

#endif