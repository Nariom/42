#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <sstream>

class Brain {

public:

	Brain( void );
	Brain( int n );
	~Brain( void );

	int			getNeurons( void ) const;
	void		setNeurons( int n );
	std::string	identify( void ) const;

private:

	int			_neurons;

};

#endif // BRAIN_HPP