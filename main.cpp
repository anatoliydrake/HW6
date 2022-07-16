#include <iostream>

using namespace std;

/*1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то
 * кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз.*/

void getInt() {
    int a;
    cout << "Enter number:";
    cin >> a;
    while (!cin.good() || cin.peek() != '\n') {
        cout << "Incorrect input. Try again" << endl;
        cin.clear();
        cin.ignore(sizeof(streamsize), '\n');
        cin >> a;
    }
    return;
}

/*2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.*/

class Endll {
public:
    friend ostream &operator<<(ostream &out, const Endll &endll);
};

ostream &operator<<(ostream &out, const Endll &endll) {
    out << endl << endl;
    out.flush();
    return out;
}

/*3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
• virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли
  ему еще одна карта и возвращает ответ пользователя в виде true или false.
• void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
• void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
• void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
 Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты,
 а также общую сумму очков его карт.*/

//class Player : public GenericPlayer {
//public:
//    Player(string name) : GenericPlayer(name) {};
//
//    bool isHitting() const override {
//        cout << name << ", do you need one more card? (y/n):";
//        char answer;
//        cin >> answer;
//        return (answer == 'Y' || answer == 'y');
//    }
//
//    void win() {
//        cout << name << " won";
//    }
//
//    void lose() {
//        cout << name << " lost";
//    }
//
//    void push() {
//        cout << name << " has a draw";
//    }
//    friend ostream &operator<<(ostream &out, const Player &pl);
//};

//ostream &operator<<(ostream &out, const Player &pl) {
//    cout << pl.name << " cards: ";
//    for (vector<Card *>::const_iterator it = pl.m_Cards.begin(); it != pl.m_Cards.end(); ++it) {
//        out << *(*it) << " ";
//    }
//    out << "| Total score: " << pl.getTotal();
//    return out;
//}

/*4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
• void FlipFirstCard() - метод переворачивает первую карту дилера.*/

//class House : public GenericPlayer {
//public:
//    House() : GenericPlayer("House") {}
//
//    bool isHitting() const override {
//        return getTotal() <= 16;
//    }
//
//    void flipFirstCard() {
//        m_Cards[0]->flip();
//    }
//};

/*5. Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ,
 * если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода,
 * который должен отображать имя игрока и его карты, а также общую сумму очков его карт.*/

//ostream &operator<<(ostream &out, const Card &card) {
//    string Ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8",
//                        "9", "10", "J", "Q", "K"};
//    string Suits[4] = {"d", "h", "c", "s"};
//
//    if (card.face) {
//        out << Ranks[card.cardRank - 1] << Suits[card.cardSuite];
//    } else {
//        out << "XX";
//    }
//    return out;
//}

int main() {
    getInt();

    Endll e1;
    cout << "Hello" << e1 << "world!";

    return 0;
}