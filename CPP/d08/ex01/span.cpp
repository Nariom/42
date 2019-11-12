#include "span.hpp"

span::span( unsigned int n ) : _list(new std::list<int>()), _size(n) {}

span::~span( void ) { delete this->_list; }

unsigned int	span::getSize( void ) const { return this->_size; }

void			span::addNumber( int n ) {
	if (this->_list->size() + 1 > this->_size)
		throw span::OutOfBoundException();
	else
		this->_list->push_back(n);
}

void	span::addNumber(
			std::vector<int>::iterator first,
			std::vector<int>::iterator last
)
{
			for(std::vector<int>::iterator it = first; it != last; ++it)
				this->addNumber(*it);
}

int				span::shortestSpan( void ) {

	int							shortest, temp, abs1, abs2 = 0;
	std::list<int>::iterator	it, it2, ite;
	bool						first;

	ite = this->_list->end();
	if(this->_list->size() < 2)
		throw span::OutOfBoundException();
	else {
		for(it = this->_list->begin(); it != ite; ++it) {
			abs1 = abs(*it);
			it2 = it;
			std::advance(it2, 1);
			first = true;
			for(it2 = it2; it2 != ite; ++it2) {
				abs2 = abs(*it2);
				if (first) {
					shortest = (abs1 < abs2) ? abs2 - abs1 : abs1 - abs2;
					first = false;
				}
				else {
					temp = (abs1 < abs2) ? abs2 - abs1 : abs1 - abs2;
					shortest = (temp < shortest) ? temp : shortest;
				}
			}
		}
	}

	return shortest;

}

int				span::longestSpan( void ) {

	int							longest, temp, abs1, abs2 = 0;
	std::list<int>::iterator	it, it2, ite;

	ite = this->_list->end();
	if(this->_list->size() < 2)
		throw span::OutOfBoundException();
	else {
		for(it = this->_list->begin(); it != ite; ++it) {
			abs1 = abs(*it);
			it2 = it;
			std::advance(it2, 1);
			for(it2 = it2; it2 != ite; ++it2) {
				abs2 = abs(*it2);
				temp = (abs1 < abs2) ? abs2 - abs1 : abs1 - abs2;
				longest = (temp > longest) ? temp : longest;
			}
		}
	}

	return longest;

}

span::OutOfBoundException::OutOfBoundException( void ) {}

span::OutOfBoundException::~OutOfBoundException( void ) throw() {}

char const *	span::OutOfBoundException::what() const throw() {
	return "Out of Bound.";
}