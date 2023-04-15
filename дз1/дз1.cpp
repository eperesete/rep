#include <iostream>

using namespace std;

class Dog { // Объявляем класс Dog
public:
    friend class Human; // Делаем класс Dog дружественным классу Human
    Dog() {             // Прописываем конструктор по умолчанию
        cout << "Dog default Constructor\n";
    }
    ~Dog() {            // Прописываем деструктор
        cout << "Dog Destructor\n";
    }
private:
    void speak() {      // Прописываем приватный метод
        cout << "Woof!\n";
    }
};

class Human { // Объявляем класс Human
public:
    Human() { // Конструктор по умолчанию               
        age = 0;
        name = "default";
        population++;
        cout << "Human default Constructor\n";
    }
    Human(int age_, string name_) { // Конструктор от двух параметров
        age = age_;
        name = name_;
        population++;
        cout << "Human age and name Constructor\n";
    }
    Human(const Human& h) { // Конструктор копирования
        age = h.age;
        name = h.name;
        population++;
        cout << "Human copy Constructor\n";
    }
    ~Human() { // Деструктор
        cout << "Human " << name << " Destructor\n";
        population--;
    }
    void set_age(int age_) { // Сеттер для возраста
        if (age_ > 0) {
            age = age_;
        }
    }
    void set_name(string name_) { // Сеттер для имени
        name = name_;
    }
    int get_age() { // Геттер для возраста
        return age;
    }
    string get_name() { // Геттер для имени
        return name;
    }
    static int get_population() { // Статический метод доступа к статической переменной
        return population;
    }
    void birthday() { // Прописываем методы класса
        this->age++;
        cout << "Happy birthday, " << this->name << "!\n";
    }
    void dog_speak(Dog& d) {
        cout << "Speak!\n";
        d.speak();
        cout << "Good boy!\n";
    }
private:
    static int population; // Статическая переменная класса
    int age;
    string name;
};

int Human::population = 0; // Обязательное объявление статической переменной вне класса


int main()
{
    Human h1;               // Создаём объекты - экземпляры класса,
    Human h2(30, "Ivan");   // используя разные конструкторы
    Human h3 = h2;

    cout << "Total population is " << Human::get_population() << endl; // Вызываем статический метод

    h1.birthday();          // Вызываем методы для объектов
    h2.birthday();

    h1.set_age(35);
    h1.set_name("Alexey");

    h1.birthday();

    cout << h1.get_name() << " is " << h1.get_age() << " years old!\n";
    cout << h2.get_name() << " is " << h2.get_age() << " years old!\n";
    cout << h3.get_name() << " is " << h3.get_age() << " years old!\n";

    Dog d;                  // Создаём объект класса Dog
    h1.dog_speak(d);        // Вызываем метод, имеющий доступ к приватным полям класса Dog
}
