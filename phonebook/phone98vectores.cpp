#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;

    // Constructor de la clase Contact
    Contact(const std::string& _name, const std::string& _phoneNumber)
        : name(_name), phoneNumber(_phoneNumber) {}
};

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    // Añade un contacto al libro de teléfonos
    void addContact(const std::string& name, const std::string& phoneNumber) {
        if (contacts.size() < 8) {
            Contact newContact(name, phoneNumber);
            contacts.push_back(newContact);
            std::cout << "Contacto agregado correctamente.\n";
        } else {
            std::cout << "El libro de teléfonos está lleno. No se puede agregar más contactos.\n";
        }
    }

    // Muestra todos los contactos en el libro de teléfonos
    void displayContacts() {
        std::cout << "Libro de Teléfonos:\n";
        for (std::vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
            std::cout << "Nombre: " << it->name << "\t Teléfono: " << it->phoneNumber << "\n";
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
