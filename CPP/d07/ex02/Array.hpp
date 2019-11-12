#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template< typename T >
class Array {

private:

	T *					_array;
	unsigned int const	_size;

public:

	Array< T >( void ) : _array(new T[0]), _size(0) {}

	Array< T >( unsigned int n ) : _array(new T[n]), _size(n) {}

	Array< T >( Array< T > const & src ) :
		_array(new T[src.size()]),
		_size(src.size())
	{
		for (unsigned int i = 0; i < src.size(); ++i)
			this->_array[i] = src[i];
	}

	~Array< T >( void ) { delete [] this->_array; }

	Array< T > &	operator=( Array< T > const & rhs ){
		delete [] this->_array;
		this->_array = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); ++i)
			this->_array[i] = rhs[i];
		return *this;
	}

	T &				operator[]( unsigned int n ) const {
		if (n >= this->_size)
			throw Array< T >::OutOfBoundException();
		else
			return this->_array[n];
	}

	unsigned int	size( void ) const { return this->_size; }

	class OutOfBoundException : public std::exception {

	public:

		OutOfBoundException( void ) {}

		OutOfBoundException( OutOfBoundException const & src ) { *this = src; }

		~OutOfBoundException( void ) throw() {}

		OutOfBoundException &	operator=(OutOfBoundException const & rhs) {
			(void) rhs;
			return *this;
		}

		virtual const char*		what() const throw() {
			return "Out of Bound.";
		}

	};

};

template< typename T >
std::ostream &	operator<<( std::ostream & o, Array< T > const & rhs ) {
	for (unsigned int i = 0; i < rhs.size(); ++i)
		o << '[' << rhs[i] << ']';
	return o;
}

#endif