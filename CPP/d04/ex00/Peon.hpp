#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"

class Peon : public Victim {

public:

	Peon( Peon const & src );
	Peon( std::string name);
	virtual ~Peon( void );

	Peon &			operator=(Peon const & rhs);

	virtual void	getPolymorphed() const;

private:

	Peon( void );

};

#endif // PEON_HPP