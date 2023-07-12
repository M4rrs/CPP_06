#pragma once
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
	public:
		virtual ~Base( void );

		Base *generate( void );
		void identify( Base *p );
		void identify( Base &p );
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

#endif