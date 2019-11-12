#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>
# include <iterator>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container > {

public:

	MutantStack( void ) : std::stack<T, Container >() {}
	MutantStack( MutantStack const & src );
	MutantStack( Container & c ) : std::stack<T, Container >(c) {}
	~MutantStack( void ) {}

	MutantStack &	operator=(MutantStack const & rhs);

	typedef typename Container::iterator		iterator;

	iterator		begin() { return this->c.begin(); }
	iterator		end() { return this->c.end(); }
	iterator		rbegin() { return this->c.rbegin(); }
	iterator		rend() { return this->c.rend(); }

};

#endif