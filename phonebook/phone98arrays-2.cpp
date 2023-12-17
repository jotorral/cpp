#include <iostream>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;

    // Constructor sin argumentos de la clase Contact
    Contact(void) {}

    // Destructor de la clase Contact
    ~Contact() {
        // Aquí puedes agregar lógica de limpieza si es necesario
    }
};

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    // Constructor por defecto de la clase PhoneBook
    PhoneBook() {}

    void addContact(const std::string& _name, const std::string& _phoneNumber) {
        if (contactCount < 8) {
            contacts[contactCount].name = _name;
            contacts[contactCount].phoneNumber = _phoneNumber;
            ++contactCount;
            std::cout << "Contacto agregado correctamente.\n";
        } else {
            std::cout << "El libro de teléfonos está lleno. No se puede agregar más contactos.\n";
        }
    }

    void displayContacts() {
        std::cout << "Libro de Teléfonos:\n";
        for (int i = 0; i < contactCount; ++i) {
            std::cout << "Nombre: " << contacts[i].name << "\t Teléfono: " << contacts[i].phoneNumber << "\n";
        }
    }
};

int main() {
    PhoneBook myPhoneBook;

    myPhoneBook.addContact("Persona1", "123-456-7890");
    myPhoneBook.addContact("Persona2", "987-654-3210");
    myPhoneBook.addContact("Persona3", "111-222-3333");

    myPhoneBook.displayContacts();

    return 0;
}
