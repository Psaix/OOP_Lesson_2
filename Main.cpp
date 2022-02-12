#include <iostream>


//______________________________________________________________________________________________________________________________________
//		Task 1
//______________________________________________________________________________________________________________________________________

class Person {
private:
	std::string m_name = "Adam";
	unsigned short m_age = 100;
	unsigned short m_weight = 84;
	std::string m_gender = "male";

public:
	void setName(std::string name) {
		m_name = name;
	}

	void setAge(unsigned short age) {
		m_age = age;
	}

	void setWeight(unsigned short weight) {
		m_weight = weight;
	}

	void setGender(std::string gender) {
		m_gender = gender;
	}


	std::string getName() {
		return m_name;
	}

	unsigned short getAge() {
		return m_age;
	}

	unsigned short getWeight() {
		return m_weight;
	}

	std::string getGender() {
		return m_gender;
	}
};


class Student : public Person {
private:
	unsigned short m_year_of_study = 1;
	static int count;
public:
	Student() { count++; }
	~Student() { count--; }
	void setYearOfStudy(unsigned short year_of_study)
	{
		m_year_of_study = year_of_study;
	}

	void raiseYearOfStudy() {
		m_year_of_study++;
	}

	unsigned short getYearOfStudy() {
		return m_year_of_study;
	}

	int countStud() {
		return count;
	}
};

int Student::count = 0;

void printInfo(Student & student)
{
	std::cout << "Name: " << student.getName() << std::endl
		<< "Age: " << student.getAge() << std::endl
		<< "Weight: " << student.getWeight() << std::endl
		<< "Gender: " << student.getGender() << std::endl
		<< "Year of study: " << student.getYearOfStudy() << std::endl;
	std::cout << std::endl;
}


//______________________________________________________________________________________________________________________________________
//		Task 2
//______________________________________________________________________________________________________________________________________

class Fruit {
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string color = "blue", std::string name = "fruit") :
		m_color(color), m_name(name) {}

	std::string getName() {
		return m_name;
	}

	std::string getColor() {
		return m_color;
	}
};

class Banana : public Fruit {
public:
	Banana(std::string color = "yellow", std::string name = "banana") :
		Fruit(color, name) {}
};

class Apple : public Fruit {
public:
	Apple(std::string color = "red", std::string name = "apple") :
		Fruit(color, name) {}
};

class GrannySmith : public Apple {
public:
	GrannySmith(std::string color = "green", std::string name = "Granny Smith apple") :
		Apple(color, name) {}
};


int main()
{

//__________________TASK1___________________

	Student student1;
	
	student1.setName("Roma");
	student1.setAge(18);
	student1.setWeight(97);
	student1.setGender("male");
	student1.raiseYearOfStudy();

	std::cout << "Student: " << student1.countStud() << std::endl;
	printInfo(student1);


	Student student2;

	student2.setName("Helena");
	student2.setAge(21);
	student2.setWeight(65);
	student2.setGender("female");
	student2.setYearOfStudy(3);

	std::cout << "Student: " << student2.countStud() << std::endl;
	printInfo(student2);


	Student student3;

	student3.setName("Damian");
	student3.setAge(24);
	student3.setWeight(82);
	student3.setGender("male");
	student3.setYearOfStudy(4);
	
	std::cout << "Student: " << student3.countStud() << std::endl;
	printInfo(student3);




//__________________TASK2___________________

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


	return 0;
}



/*_____________________________TASK3_______________________________________________
#define DECK 52


class Casino {
protected:
	int m_bank = 0;
	int m_cards = 0;

public:
	Casino(int bank) : m_bank(bank) {}

	int getCard(int card)
	{
		m_cards += card;
		return m_cards;
	}

	int playCards()
	{
		return m_cards;
	}

	int fold()
	{
		m_cards = 0;
		return m_cards;
	}

	void printCards()
	{
		std::cout << m_cards << std::endl;
	}

	void printBank()
	{
		std::cout << m_bank << std::endl;
	}

	int takePlayerBet(int bet)
	{
		m_bank += bet;
		return m_bank;
	}

	int giveReward(int reward)
	{
		if (m_bank > 0)
		{
			m_bank -= reward;
			return reward;
		}
	}
};


class Player : public Casino {
public:
	Player(int bank) : Casino(bank) {}

	int makeBet(int bet)
	{
		if (m_bank > 0)
		{
			m_bank -= bet;
			return m_bank;
		}
	}

	int takeReward(int reward)
	{
		m_bank += reward;
		return m_bank;
	}

};


class CardDeck {
private:
	unsigned short int m_deck[DECK] =
	{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
	2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
	2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
	2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, };
	unsigned short int capacity = 51;

public:
	void deckShuffle() {
		std::random_shuffle(std::begin(m_deck), std::end(m_deck));
	}
	unsigned short int takeCard() {
		return m_deck[capacity--];
	}

	void printDeck() {
		int count = 0;
		for (size_t i = 0; i < DECK; i++)
		{
			std::cout << m_deck[i] << ' ';
			count++;
			if (count % 13 == 0)
				std::cout << std::endl;
		}
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	Casino dealer(1000000);

	Player player1(500000);

	CardDeck deck;
	deck.printDeck();
	std::cout << std::endl;

	deck.deckShuffle();
	deck.printDeck();
	std::cout << std::endl;

	player1.getCard(deck.takeCard());
	player1.printCards();
	std::cout << std::endl;

	dealer.getCard(deck.takeCard());
	dealer.printCards();
	std::cout << std::endl;

	player1.getCard(deck.takeCard());
	player1.printCards();
	std::cout << std::endl;

	dealer.getCard(deck.takeCard());
	dealer.printCards();
	std::cout << std::endl;

	player1.fold();
	player1.printCards();
	std::cout << std::endl;

	dealer.fold();
	dealer.printCards();
	std::cout << std::endl;


	return 0;

}
*/