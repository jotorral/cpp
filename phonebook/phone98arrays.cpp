#include <iostream>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;

    // Constructor por defecto de la clase Contact
    Contact() : name(""), phoneNumber("") {}

    // Constructor de la clase Contact con parámetros
    Contact(const std::string& _name, const std::string& _phoneNumber)
        : name(_name), phoneNumber(_phoneNumber) {}
};

class PhoneBook {
private:
    Contact contacts[8];  // Array fijo para almacenar hasta 8 contactos
    int contactCount;     // Contador de contactos

public:
    // Constructor por defecto de la clase PhoneBook
    PhoneBook() : contactCount(0) {}

    // Añade un contacto al libro de teléfonos
    void addContact(const std::string& name, const std::string& phoneNumber) {
        if (contactCount < 8) {
            contacts[contactCount] = Contact(name, phoneNumber);
            ++contactCount;
            std::cout << "Contacto agregado correctamente.\n";
        } else {
            std::cout << "El libro de teléfonos está lleno. No se puede agregar más contactos.\n";
        }
    }

    // Muestra todos los contactos en el libro de teléfonos
    void displayContacts() {
        std::cout << "Libro de Teléfonos:\n";
        for (int i = 0; i < contactCount; ++i) {
            std::cout << "Nombre: " << contacts[i].name << "\t Teléfono: " << contacts[i].phoneNumber << "\n";
        }
    }
};

int main() {
    PhoneBook myPhoneBook;

    // Agregar algunos contactos
    myPhoneBook.addContact("Persona1", "123-456-7890");
    myPhoneBook.addContact("Persona2", "987-654-3210");
    myPhoneBook.addContact("Persona3", "111-222-3333");

    // Mostrar contactos
    myPhoneBook.displayContacts();

    return 0;
}
