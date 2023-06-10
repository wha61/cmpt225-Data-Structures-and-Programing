#include <iostream>
#include <string>

using namespace std;

//principal class
class Animal
{
private:
    int age;
public:
	//constructer
	Animal();
	Animal(const int&);

    //destructer
	virtual ~Animal();

	//assignment operator
	Animal& operator=(const Animal&);

    //needed member functions
    virtual string noise();
    int repeats();
    int ageInMonths();
    void print();
};
Animal::Animal()
{
    this->age = 0;
}
Animal::Animal(const int& ageOfAnimal)
{
    this->age = ageOfAnimal;
}
Animal::~Animal()
{}
Animal& Animal::operator=(const Animal& a)
{
	this->age = a.age;
    return *this;
}
string Animal::noise()
{
    string noiseOfAnimal = "grunt";
    return noiseOfAnimal;
}
int Animal::repeats()//as said in the assignment, "All animals grunt three times"
{
    int grunt = 3;
    return grunt;
}
int Animal::ageInMonths()
{
    return this->age;
}
void Animal::print()
{
    //print the age of animal 
    cout << this->ageInMonths() << " ";
    //find repeat time
    int repeatTime = this->repeats();
    //print repeat time's noise of the animal
    for(int i = 0; i < repeatTime; i++)
    {
        cout << this->noise() << " ";
    }
    cout << endl;
}

class Cow : public Animal
{
public:
	Cow();
	Cow(const int& cowAge);

	//destructer
	virtual ~Cow();

	//assignment operator
	Cow& operator=(const Cow& m);

    //needed functions
    virtual string noise();
    int repeats();
};
Cow::Cow() : Animal()
{}
Cow::Cow(const int& cowAge) : Animal(cowAge)
{}
Cow::~Cow()
{}
Cow& Cow::operator=(const Cow& m)
{
	this->Animal::operator=(m);
	return *this;
}
string Cow::noise()
{
    return "moo";
}
int Cow::repeats()
{
    int repeatsOfCow = 2;
    return repeatsOfCow;
}

class Sheep : public Animal
{
public:
	Sheep();
	Sheep(const int& sheepAge);

	//destructer
	virtual ~Sheep();

	//ass
	Sheep& operator=(const Sheep& m);

    virtual string noise();
    int repeats();
};
Sheep::Sheep() : Animal()
{}
Sheep::Sheep(const int& sheepAge) :  Animal(sheepAge)
{}
Sheep::~Sheep()
{}
Sheep& Sheep::operator=(const Sheep& m)
{
	this->Animal::operator=(m);
	return *this;
}
string Sheep::noise()
{
    return "baa";
}
int Sheep::repeats()
{
    int repeatsOfSheep = 6;
    return repeatsOfSheep;
}

class Dog : public Animal
{
public:
	Dog();
	Dog(const int& dogAge);

	//destructer
	virtual ~Dog();

	//ass
	Dog& operator=(const Dog& m);

    virtual string noise();
    int repeats();
};
Dog::Dog() : Animal()
{}
Dog::Dog(const int& dogAge) : Animal(dogAge)
{}
Dog::~Dog()
{}
Dog& Dog::operator=(const Dog& m)
{
	this->Animal::operator=(m);
	return *this;
}
string Dog::noise()
{
    return "woof";
}
int Dog::repeats()
{
    int repeatsOfDog = 2;
    return repeatsOfDog;
}

class Cat : public Animal
{
public:
	Cat();
	Cat(const int& age);

	//destructer
	virtual ~Cat();

	//ass
	Cat& operator=(const Cat& m);

    virtual string noise();
    int repeats();
};
Cat::Cat() : Animal()
{}
Cat::Cat(const int& age) : Animal(age)
{}
Cat::~Cat()
{}
Cat& Cat::operator=(const Cat& m)
{
	this->Animal::operator=(m);
	return *this;
}
string Cat::noise()
{
    return "meow";
}
int Cat::repeats()
{
    int repeatsOfCat = 1;
    return repeatsOfCat;
}

int main()
{
    //construnt five varibles(animal cow cat dog sheep) and print them
    Animal ani(8);
    ani.print();
    Cow cow(6);
    cow.print();
    Cat cat(2);
    cat.print();
    Dog dog(9);
    dog.print();
    Sheep sheep(5);
    sheep.print();

    cout << endl;

    //declare a 10 pointers array of animal and other different animals and intialize them
    Animal** animals = new Animal*[10];
    animals[0] = new Cat(5);
    animals[1] = new Cow(3);
    animals[2] = new Sheep(9);
    animals[3] = new Dog(2);
    animals[4] = new Dog(9);
    animals[5] = new Animal(20);
    animals[6] = new Cat(1);
    animals[7] = new Sheep(4);
    animals[8] = new Animal(50);
    animals[9] = new Cow(8);

    //print each elements of the array
    for (int i = 0; i < 10; i++)
    {
        animals[i]->print();
        cout << endl;
    }

    //delete array
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    delete[] animals;

    return 0;
}