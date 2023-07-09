#include <ScalarConverter.hpp>

/* ================= CONSTRUCTOR ================== */
ScalarConverter::ScalarConverter( void ) : _literal(NULL) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	_dataType = setInputType(_literal);
	std::cout << "Default constructor should never be called, and shouldn't be accessible. Somethings wrong."
			<< std::endl;
}

ScalarConverter::ScalarConverter( std::string lit ) : _literal(lit) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	_dataType = setInputType(_literal);

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

int ScalarConverter::setInputType( const std::string lit ) {
	if (!lit.compare("nan") || !lit.compare("+inf") || !lit.compare("-inf") ||
		!lit.compare("nanf") || !lit.compare("+inff") || !lit.compare("-inff"))
		return NAN_INF;
	if (lit.length() == 1 && isprint(lit[0]))
		return CHAR;
	if (lit.find_first_of("+-") != lit.find_last_of("+-"))
		return ERROR;
	if (lit.find_first_of("-+") == 0 && lit.find_first_not_of("-+0123456789") == std::string::npos)
		return INT;
	else if (lit.find_first_not_of("0123456789") == std::string::npos)
		return INT;
	if (lit.find_first_of(".") != lit.find_last_of(".") || (lit.find_first_of(".") == lit.find_last_of(".") 
		&& !isdigit(lit[lit.find_first_of(".") + 1])))
		return ERROR;
	if (lit.find_first_of(".") == lit.find_last_of(".")) {
		if (!isdigit(lit[lit.find_first_of(".") + 1]))
			return ERROR;
		if (lit.find_first_of("f") == lit.find_last_of("f") && lit[lit.find_first_of("f") + 1] == std::string::npos)
			return FLOAT;
		else
			return DOUBLE;
	}
	else
		return ERROR;
}

void ScalarConverter::typeC( void ) {
	_char = static_cast<unsigned char>(_literal[0]);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void ScalarConverter::typeI( void ) {
	_int = stoi(_literal);
	_char = static_cast<unsigned char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::typeF( void ) {
	_float = stof(_literal);
	_char = static_cast<unsigned char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::typeD( void ) {
	_double = stod(_literal);
	_char = static_cast<unsigned char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
}

void ScalarConverter::convert( void ) {
	switch (this->_dataType) {
		case CHAR:
			this->typeC();
			break;
		case INT:
			this->typeI();
			break;
		case FLOAT:
			this->typeF();
			break;
		case DOUBLE:
			this->typeD();
			break;
		case NAN_INF:
			break;
		default:
			throw ScalarConverter::Exception();
	}
}

void ScalarConverter::printResults( void ) const {
	if (this->_dataType != NAN_INF && this->_char <= UCHAR_MAX)
}