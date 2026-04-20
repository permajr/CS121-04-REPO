#include "q_array.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char charbo = 'a';

	cout << "Welcome to Quenzel's 'q' queue queueing questions & quantifications!\n";
	cout << "Queuing up some quickened queueable quotients!\n";
	cout << "-------------------------------------------------\n";
	Queue<char> queuebo;
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < 26; i++)
	{	
		queuebo.enQ(charbo); //enQ 'a' then increment later.
		if (queuebo.fullQ() < 1)
		{
			cout << static_cast<char>(queuebo.front() + i) << " has been queued." << endl; // display character queued
		}
		else
			cout << static_cast<char>(queuebo.front() + i) << " could not be queued because: \n"; // using fullQ, character couldn't be queued because it's full
		if (i < 25)
			charbo++;	//use ASCII numbers to increment char queued, up til z. 	
	}
	for (int j = 1; j < 6; j++)
	{
		queuebo.deQ(); //deQ 'a', then the rest in order. FIFO.
		cout << static_cast<char>(queuebo.front() - 1 ) << " has been dequeued.\n"; // ditto as cout in the last loop but corrected for deQ happening first.
	}

	cout << "Quentzel quashed this 'q' queue! Quick - qualm your quizzical quirk with qorrectly queued 'q' queues!\n";
	cout << "-------------------------------------------------\n";
	for (int k = 0; k < 10; k++)
		cout << static_cast<char>(queuebo.front() + k) << endl; // final q queue
	cout << "-------------------------------------------------\n";

}

/*********************************CONSOLE OUTPUT***********************************************************

Welcome to Quenzel's 'q' queue queueing questions & quantifications!
Queuing up some quickened queueable quotients!
-------------------------------------------------
q constr
-------------------------------------------------
a has been queued.
b has been queued.
c has been queued.
d has been queued.
e has been queued.
f has been queued.
g has been queued.
h has been queued.
i has been queued.
j could not be queued because:
 full q!
k could not be queued because:
 full q!
l could not be queued because:
 full q!
m could not be queued because:
 full q!
n could not be queued because:
 full q!
o could not be queued because:
 full q!
p could not be queued because:
 full q!
q could not be queued because:
 full q!
r could not be queued because:
 full q!
s could not be queued because:
 full q!
t could not be queued because:
 full q!
u could not be queued because:
 full q!
v could not be queued because:
 full q!
w could not be queued because:
 full q!
x could not be queued because:
 full q!
y could not be queued because:
 full q!
z could not be queued because:
a has been dequeued.
b has been dequeued.
c has been dequeued.
d has been dequeued.
e has been dequeued.
Quentzel quashed this 'q' queue! Quick - qualm your quizzical quirk with qorrectly queued 'q' queues!
-------------------------------------------------
f
g
h
i
j
k
l
m
n
o
-------------------------------------------------


**********************************************************************************************************/