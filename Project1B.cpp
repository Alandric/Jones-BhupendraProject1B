// Project1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <string>
#include <iostream>
#include<list>

using namespace std;
class Poly {
public:
	int exp;
	double coef;
	Poly* next;
	double getCoef() {

		return coef;
	}
	int getExp() {

		return exp;
	}
	Poly() {
		coef = 0;
		exp = 0;
		next = nullptr;
	}

	Poly(double coeff, int expn, Poly* next_ptr=NULL ) {
		coef = coeff;
		exp = expn;
		next = next_ptr;
	}
	Poly add_poly(Poly a, Poly b) {
		
		Poly temp;
		if (a.exp == b.exp) {
			temp.coef = a.coef + b.coef;
			temp.exp = a.exp;
		}

		return temp;
	}
	/*bool operator < (Poly a, Poly b) {

		return();
	}*/

	};
void insert_short(Poly term, Poly* & head);
void displayPoly(Poly* head);

	int main()
	{
		Poly * head=NULL;// = new Poly(3.0, 2, nullptr);
		//head = new Poly(-5.0, 4, head);
		insert_short( Poly(4.0, 4, nullptr), head);

		insert_short(Poly(4.0, 3, nullptr), head);
		insert_short(Poly(4.0, 5, nullptr), head);
		insert_short(Poly(4.0, 2, nullptr), head);
		insert_short(Poly(4.0, 5, nullptr), head);
		/*head = new Poly(3.0, 2, head);
		
		head = new Poly(3.0, 1, head);*/
		displayPoly(head);

		/*list Poly::iterator iter=l */

		int x; cin >> x;

		return 0;
	}

	
	void displayPoly(Poly* head)
	{
		Poly* current_node = head;


		while (current_node != NULL) {
			string sign = ((current_node->coef) > 0.0) ? " +" : " ";
			if (current_node == head)
				sign = " ";

			cout << sign << current_node->coef << "X^" << current_node->exp;
		 

			/*if (current_node->next != NULL)
			cout << "==>";*/

			current_node = current_node->next; //advance the current node

		}
	}
	void insert_short(Poly term, Poly* & head)
	{
		Poly* curPtr = head;
		
		if (head == NULL) {
			Poly* new_poly = new Poly(term.coef, term.exp, nullptr);
			head = new_poly;
		}
		else if(term.exp > head->exp)
			head = new Poly(term.coef, term.exp, head);

		else {
			{   Poly* prevPtr = curPtr;
				while (curPtr != NULL && term.exp < curPtr->exp) {
					prevPtr = curPtr;
					curPtr = curPtr->next;
				}
				if (term.exp == prevPtr->exp)
					prevPtr->coef += term.coef;
				else
				prevPtr->next = new Poly(term.coef, term.exp, curPtr);

			}
		}
	}

