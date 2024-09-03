#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data	pepe = {1, "Pepe"};
	Data*	pepePoint = &pepe;
	uintptr_t pepe2 = Serializer::serialize(pepePoint);
	Data*	josePoint = Serializer::deserialize(pepe2);

	std::cout << "The pointer points to an object with this data:                         "<< pepePoint->_id << "    " << pepePoint->_name << std::endl;
	std::cout << "Once converted the object pointer to an uintptr_t and again to pointer: " << josePoint->_id << "    " << josePoint->_name << std::endl;
	return 0;
}
