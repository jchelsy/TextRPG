#pragma once

#include <iostream>
#include <exception>

struct InvalidInputException : public std::exception
{
	const char* name() const throw ()
	{
		return "INVALID_INPUT_EXCEPTION";
	}
	const char* messageTitle() const throw ()
	{
		return "INVALID INPUT";
	}
};