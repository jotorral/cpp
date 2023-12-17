#include <iostream>
#include <string>

const int MAX_CONTACTS = 8;

class Contact {
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact() {} // Constructor predeterminado

    // Métodos para obtener y guardar información
    std::string get_first_name() const { return _first_name; }
    void save_first_name(const std::string& first_name) { _first_name = first_name; }

    std::string get_last_name() const { return _last_name; }
    void save_last_name(const std::string& last_name) { _last_name = last_name; }

    std::string get_nickname() const { return _nickname; }
    void save_nickname(const std::string& nickname) { _nickname = nickname; }

    std::string get_phone_number() const { return _phone_number; }
    void save_phone_number(const std::string& phone_number) { _phone_number = phone_number; }

    std::string get_darkest_secret() const { return _darkest_secret; }
    void save_darkest_secret(const std::string& darkest_secret) { _darkest_secret = darkest_secret; }
};

class PhoneBook {
private:
    Contact arr_contacts[MAX_CONTACTS];
    int contactCount = 0;

public:
    void add_contact(const Contact& new_contact) {
        if (contactCount < MAX_CONTACTS) {
            arr_contacts[contactCount] = new_contact;
            contactCount++;
        } else {
            std::cout << "El directorio está lleno. No se pueden agregar más contactos." << std::endl;
        }
    }

    void display_contacts() const {
        std::cout << "Lista de contactos: " << std::endl;
        for (int i = 0; i < contactCount; i++) {
            std::cout << "Contacto: " << i + 1 << ";" << std::endl;
            std::cout << "Nombre: " << arr_contacts[i].get_first_name() << std::endl;
            std::cout << "Apellido: " << arr_contacts[i].get_last_name() << std::endl;
            std::cout << "Apodo: " << arr_contacts[i].get_nickname() << std::endl;
            std::cout << "Teléfono: " << arr_contacts[i].get_phone_number() << std::endl;
            std::cout << "Secreto oscuro: " << arr_contacts[i].get_darkest_secret() << std::endl;
            std::cout << std::endl; // Separador entre contactos
        }
    }
};

void print_menu() {
    std::cout << "**************** The very best Phonebook ***************" << std::endl;
    std::cout << std::endl;
    std::cout << "************* Type in one of the next commands: ********" << std::endl;
    std::cout << std::endl;
    std::cout << "ADD" << std::endl;
    std::cout << "SEARCH" << std::endl;
    std::cout << "EXIT" << std::endl;
    std::cout << std::endl;
}

int main() {
    std::string menu_option;
    PhoneBook phoneBook;

    print_menu();

    while (true) {
        std::getline(std::cin, menu_option);

        if (menu_option == "ADD") {
            std::cout << "Has seleccionado: ADD" << std::endl;

            // Puedes agregar lógica aquí para capturar información del usuario y luego llamar a add_contact

        } else if (menu_option == "SEARCH") {
            for (int i = 0; i < 8; i++) {
                phoneBook.add_contact(Contact("0", "0", "0", "0", "0"));
            }
            std::cout << "Has seleccionado: SEARCH" << std::endl;

            // Puedes agregar lógica aquí para mostrar o buscar contactos

        } else if (menu_option == "EXIT") {
            break;
        } else {
            print_menu();
        }
    }

    return 0;
}

