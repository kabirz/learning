#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main()
{
	cpp_int result = pow(cpp_int(2), 2048);
	std::cout << result << std::endl;

	return 0;
}
