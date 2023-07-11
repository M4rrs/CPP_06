#include "ScalarConverter.hpp"
/* ================= CONSTRUCTOR ================== */
ScalarConverter::ScalarConverter( void ) : _literal(NULL) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	_dataType = setInputType(_literal);
	convert();
	std::cout << "Default constructor should never be called, and shouldn't be accessible. Somethings wrong."
			<< std::endl;
}

ScalarConverter::ScalarConverter( std::string lit ) : _literal(lit) {
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
	_dataType = setInputType(_literal);
	convert();
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

int ScalarConverter::setInputType( const std::string lit ) {
	if (!lit.compare("nan") || !lit.compare("+inf") || !lit.compare("-inf") ||
		!lit.compare("nanf") || !lit.compare("+inff") || !lit.compare("-inff"))
		return NAN_INF;
	if (lit.length() == 1 && !isdigit(lit[0]) && isprint(lit[0]))
		return CHAR;
	if (lit.find_first_of("+-") != lit.find_last_of("+-") || lit.find_first_not_of("-+0123456789.ef") != std::string::npos)
		return ERROR;
	if ((lit.find_first_of("-+") == 0 && lit.find_first_not_of("-+0123456789") == std::string::npos)
		||(lit.find_first_not_of("0123456789") == std::string::npos)) {
		long temp = std::stol(lit);
		if (temp >= INT_MAX || temp <= INT_MIN)
			return ERROR;
		return INT;
	}
	if (lit.find_first_of(".") != lit.find_last_of(".") || (lit.find_first_of(".") == lit.find_last_of(".") 
		&& !isdigit(lit[lit.find_first_of(".") + 1])))
		return ERROR;
	if (lit.find_first_of(".") == lit.find_last_of(".")) {
		if (!isdigit(lit[lit.find_first_of(".") + 1]))
			return ERROR;
		if (lit.find_first_of("f") == lit.find_last_of("f") && lit[lit.find_first_of("f") + 1] == '\0')
			return FLOAT;
		else
			return DOUBLE;
	}
	// if (lit.length() == 1 && isprint(lit[0]))
	// 	return CHAR;
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
	printResults();
}

void ScalarConverter::printResults( void ) const {
	if (this->_dataType != NAN_INF && this->_char >= 0) {
		std::cout << "char: " << (isprint(this->_char) ? "'" + std::string(1, this->_char) + "'" : "Non-displayable");
	}
	else
		std::cout << "char: impossible";
	std::cout << std::endl;

	if (this->_dataType != NAN_INF && this->_int <= INT_MAX && this->_int >= INT_MIN) {
		std::cout << "int: " << this->_int;
	}
	else
		std::cout << "int: impossible";
	std::cout << std::endl;

	if (this->_dataType != NAN_INF)
		std::cout << "float: " << _float << (this->_float - this->_int == 0 ? ".0f" : "f");
	else if (_literal == "nan" || _literal == "nanf")
		std::cout << "float: nanf";
	else
		std::cout << "float: " << (_literal[0] == '+' ? "+inff" : "-inff");
	std::cout << std::endl;

	if (this->_dataType != NAN_INF)
		std::cout << "double: " << _double << (this->_double - this->_int == 0 ? ".0" : "");
	else if (_literal == "nan" || _literal == "nanf")
		std::cout << "double: nan";
	else
		std::cout << "double: " << (_literal[0] == '+' ? "+inf" : "-inf");
	std::cout << std::endl;
}

const char *ScalarConverter::Exception::what( void ) const throw () {
	return ("Conversion Error.");
}