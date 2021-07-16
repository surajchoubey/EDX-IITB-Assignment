/*

Graded Programming Assignment 2 (Inheritance and Polymorphism)
Rohan, a student of CS101.2x, wishes to implement the game of rock, paper and scissors on C++. However, he wants to modify the rules of the game slightly. He assigns each weapon (rock, paper or scissor) a numerical value of strength, which is decided by the user during runtime. Now, when facing each other, Rock's strength is doubled when fighting scissors, but halved when fighting paper. In the same way, paper has the advantage against rock, and scissors against paper.

For example, if the strengths of rock, paper and scissor are 5, 7, and 24 respectively, then:

(i) When rock fights against paper, the rock’s strength is halved and the paper’s strength is doubled. So, the rock’s strength becomes 2 and the paper’s strength becomes 14. Hence, paper wins the battle between the two in this case.

(ii) When paper fights against scissor, paper’s strength is halved and the scissor’s strength is doubled. So, the paper’s strength becomes 3 and scissor's strength becomes 48. Thus, scissor wins the battle between paper and scissor.

(iii) When scissor fights against rock, scissors’ strength is halved and rock’s strength is doubled. So, the scissor's strength becomes 12 and rock’s strength becomes 10.

Thus, scissor wins the battle between rock and scissor.

To implement this, he makes use of a class Weapon, which has an int field called strength, and a char field called type. The Weapon class also contains the function ‘void setPower(int), which sets the strength for the ‘Weapon’. Apart from this, there are two other functions ‘int return_strength()’ and ‘char return_type()’, which return the strength and type of the object. There is an additional int field called modified, whose usage will not be revealed for obvious reasons. (You are required to figure it out)

Further, he needs 3 more classes called Rock, Paper and Scissors, which inherit from Weapon. These classes will also need a public function bool battle(Weapon) that compares their strengths in the following way:

● Rock's strength is doubled (temporarily) when fighting scissors, but halved (temporarily) when fighting against paper
● In the same way, paper has the advantage against rock, and scissors against paper.

The strength field shouldn't change in the function, which returns true if the original class wins in strength and false otherwise.


Note:

You may use your own choice of visibility modes for the definition of the derived classes. The program outputs the results of the battles of rock with paper, paper with scissors and scissors with rock. Please note that the results of the battles are nothing but the return values of the function bool battle(Weapon). For example, if you want the result of the battle of rock with paper, you need to call the function as: r.battle(p) , where r is an object of class Rock and p is an object of class Paper

Here are some sample inputs along with their outputs for your reference. You may also use them to check the correctness of your program:

(i) Input:
5
7
24
Output: 001

(ii) Input:
3
4
5
Output: 000

*/

#include<iostream>
using namespace std;

class Weapon{

	private:
	int power;
	char type;
	int modified;
	
	public:
	void set_mod_power(int modified_){
		modified = modified_;
	}	
	int get_mod_power(){
		return modified;
	}
	void set_power(int power_){
		power = power_;
	}	
	int get_power(){
		return power;
	}
	void set_type(char type_){
		type = type_;
	}
	char get_type(){
		return type;
	}	
	
	void modifier(Weapon *one, Weapon *two){
		
		one->set_mod_power(one->get_power() * 2) ; two->set_mod_power(two->get_power() / 2);
		
	}
	
	bool battle(Weapon *opponent){
		
		if( opponent->get_type() == this->get_type() ) { 
		
			cout<< this->get_type() << " cannot fight with " << opponent->get_type() << "\n" ;
			return false;
			
		} else if ( opponent->get_type() + this->get_type() == 'r' + 's' ){
		
			if(this->get_type() == 'r') modifier( this, opponent );
			else modifier( opponent, this );
			
		} else if ( opponent->get_type() + this->get_type() == 'p' + 's' ){
			
			if(this->get_type() == 's') modifier( this, opponent );
			else modifier( opponent, this );
		
		
		} else if ( opponent->get_type() + this->get_type() == 'p' + 'r' ){
			
			if(this->get_type() == 'p') modifier( this, opponent );
			else modifier( opponent, this );
			
		} else {
			cout << "There is something fishy! \n" ;
			return false;
		}
		
		if( this->get_mod_power() >= opponent->get_mod_power() ) return true;
		else return false;
		
	}
};

class Rock: public Weapon{

	public: 	
	
	Rock(int S){
		Weapon::set_power(S);
		Weapon::set_type('r');
	}
	
	Rock(){
		Weapon::set_power(0);
		Weapon::set_type('s');
	}
};

class Paper: public Weapon{

	public: 

	Paper(int S){
		Weapon::set_power(S);
		Weapon::set_type('p');
	}	
	
	Paper(){
		Weapon::set_power(0);
		Weapon::set_type('p');
	}
};

class Scissor: public Weapon{
	
	public:

	Scissor(int S){
		Weapon::set_power(S);
		Weapon::set_type('s');
	}
	
	Scissor(){
		Weapon::set_power(0);
		Weapon::set_type('s');
	}
};


int main(){
	
	Rock r(5);
	Paper p(7);
	Scissor s(24);
	
	cout << "Rock and Paper = " << r.battle(&p)  << endl;
	cout << "Paper and Scissor = " << p.battle(&s)  << endl;
	cout << "Scissor and Rock = "<< s.battle(&r)  << endl;
	
	return 0;

}
