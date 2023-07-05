#include <ScalarConverter.hpp>

/* ================= CONSTRUCTOR ================== */
ScalarConverter::ScalarConverter( void ) : _literal(NULL) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	std::cout << "Default constructor should never be called, and shouldn't be accessible. Somethings wrong."
			<< std::endl;
}

ScalarConverter::ScalarConverter( std::string lit ) : _literal(lit) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
}

/* ================= DESTRUCTOR ================== */

ScalarConverter::~ScalarConverter( void ) { }

/* ================= COPY CONSTRUCTOR ================== */

ScalarConverter::ScalarConverter( const ScalarConverter &copy ) : _literal(copy._literal){
	*this = copy;
}

/* ================= OVERLOADED OPERATOR ================== */

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &assign ) {
	if (this == &assign)
		return *this;

	this->_char = assign._char;
	this->_int = assign._int;
	this->_float = assign._float;
	this->_double = assign._double;

	return *this;
}

/* ================= PUBLIC ================== */

char ScalarConverter::getChar( void ) const {
	return (this->_char);
}

int ScalarConverter::getInt( void ) const {
	return (this->_int);
}

float ScalarConverter::getFloat( void ) const {
	return (this->_float);
}

double ScalarConverter::getDouble( void ) const {
	return (this->_double);
}

void ScalarConverter::printResults( void ) const {
	std::cout << "Converted Values:\n"
			<< "Char"
}

void ScalarConverter::convertInput( std::string str ) {

}