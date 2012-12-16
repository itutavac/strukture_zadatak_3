#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "red_pokazivac.h"
//#include "red_polje.h"

using  namespace	std;

int		n = 0;

bool	First(_queue	*queue)
{
	_tempList	temp;
	do
	{
		cout<<"Koliko nizova zelite generirati: \n";
		cin>>n;
		if (n<0 || n > MAX-1)
			cout<<"Ponovite ";
	}while(n<0 || n > MAX-1);
	for (int i = 0; i<n;i++)
	{
		temp.date = " ", temp.devizni = 0, temp.name = " ", temp.tekuci = 0;
		temp.a = rand()%401+100;
		temp.b = rand()%401+100;
		temp.c = rand()%6+1;
		do
		{
			temp.d = rand()%4+1;
		}while (temp.c == 6 && (temp.d == 2 || temp.d == 4));
		EnQueueQ(temp,queue);
	}
	return	true;
}

bool	Sort(_tempList	*Array,_queue	*queue,int limit)
{
	if (IsEmptyQ(queue))
		return	false;
	_tempList	temp;
	for (int i = 0; i < limit; i++)
	{
		Array[i] = FrontQ(queue);
		DeQueueQ(queue);
	}
	int	i,j,c;
	for (i = 1; i < limit; i++)
	{
		j = i;
		while (j>0 && Array[j-1].c > Array[j].c)
		{
			temp = Array[j];
			Array[j] = Array[j-1];
			Array[j-1] = temp;
			j--;
		}
	}
	for (int i = 0; i < limit; i++)
		EnQueueQ(Array[i],queue);
	return	true;
}

bool	PrintOne(_tempList	temp)
{	
	cout<<endl<<"Ime i prezime: "<<temp.name<<endl;
	cout<<"Datum rodjenja: "<<temp.date<<endl;
	cout<<"Stanje na deviznom: "<<temp.devizni<<" €"<<endl;
	cout<<"Stanje na tekucem: "<<temp.tekuci<<endl;
	cout<<"Vrijeme ulaza u red: "<<temp.a<<endl;
	cout<<"Vrijeme trajanja transakcije: "<<temp.b<<endl;
	switch (temp.c)
	{
	case	1:
		cout<<"Umirovljenici\n";
		break;
	case	2:
		cout<<"Invalidi\n";
		break;
	case	3:
		cout<<"Trudnice\n";
		break;
	case	4:
		cout<<"VIP klijenti banke\n";
		break;
	case	5:
		cout<<"Ostali klijenti banke\n";
		break;
	}
	switch (temp.d)
	{
	case	1:
		cout<<"Uplata\n";
		break;
	case	2:
		cout<<"Isplata\n";
		break;
	case	3:
		cout<<"Placanje racuna\n";
		break;
	case	4:
		cout<<"Krediti\n";
		break;
	}
	return	true;
}

bool	Print(_queue	*queue,int limit,int select)
{
	_tempList	temp;
	if (IsEmptyQ(queue))
		return	false;
	bool	ok = true;
	for (int i = 0; i < limit; i++)
	{
		ok = true;
		temp = FrontQ(queue);
		DeQueueQ(queue);
		if (select == 2)
		{
			temp = FrontQ(queue);
			DeQueueQ(queue);
		}
		if (select == 1 && temp.devizni <= 1332)
			ok = false;
		if (ok)
		{
			cout<<endl<<"Ime i prezime: "<<temp.name<<endl;
			cout<<"Datum rodjenja: "<<temp.date<<endl;
			cout<<"Stanje na deviznom: "<<temp.devizni<<" €"<<endl;
			cout<<"Stanje na tekucem: "<<temp.tekuci<<endl;
			cout<<"Vrijeme ulaza u red: "<<temp.a<<endl;
			cout<<"Vrijeme trajanja transakcije: "<<temp.b<<endl;
			switch (temp.c)
			{
			case	1:
				cout<<"Umirovljenici\n";
				break;
			case	2:
				cout<<"Invalidi\n";
				break;
			case	3:
				cout<<"Trudnice\n";
				break;
			case	4:
				cout<<"VIP klijenti banke\n";
				break;
			case	5:
				cout<<"Ostali klijenti banke\n";
				break;
			}
			switch (temp.d)
			{
			case	1:
				cout<<"Uplata\n";
				break;
			case	2:
				cout<<"Isplata\n";
				break;
			case	3:
				cout<<"Placanje racuna\n";
				break;
			case	4:
				cout<<"Krediti\n";
				break;
			}
		}
		EnQueueQ(temp,queue);
	}
	return	true;
}

bool	Second(_queue	*queue)
{
	if (IsEmptyQ(queue))
		return	false;
	_tempList	temp;
	for (int i = 0; i < n; i++)
	{
		temp = FrontQ(queue);
		DeQueueQ(queue);
		cout<<endl<<"Ime i prezime klijenta: ";
		cin.clear();
		cin.ignore();
		getline(cin,temp.name);
		cout<<"Datum rodjenja: ";
		cin>>temp.date;
		cout<<"Stanje na tekucem: ";
		cin>>temp.tekuci;
		cout<<"Stanje na deviznom: ";
		cin>>temp.devizni;
		EnQueueQ(temp,queue);
	}
	cout<<endl;
	_tempList	*Array = new _tempList[n];
	Sort(Array,queue,n);
	for (int i = 0; i < n; i++)
		cout<<Array[i].c<<endl;
	Print(queue,n,1);
	cout<<endl;
	delete	[]Array;
	return	true;
}

bool	Third(_queue	*queue)
{
	if (IsEmptyQ(queue))
		return	false;
	_tempList	temp;
	_queue	*fastQueue = new _queue;
	InitQ(fastQueue);
	int	k = 0,l=0;
	for (int i = 0; i < n; i++)
	{
		temp	=	FrontQ(queue);
		DeQueueQ(queue);
		if (temp.d == 3)
		{
			EnQueueQ(temp,fastQueue);
			k++;
		}
		else
		{
			EnQueueQ(temp,queue);
			l++;
		}
	}
	_tempList	*Array1 = new _tempList[k];
	_tempList	*Array2 = new _tempList[l];
	Sort(Array1,fastQueue,k);
	Sort(Array2,queue,l);
	cout<<"\nBrzi red\n";
	Print(fastQueue,k,0);
	cout<<"\nGlavni red\n";
	Print(queue,l,0);
	n = l;
	delete	[]Array1;
	delete  []Array2;
	return	true;
}

bool		Check(_tempList	a,int min, int max)
{
	time_t		rawTime;
	struct	tm	*timeInfo;
	time (&rawTime);
	timeInfo = localtime (&rawTime);
	string	buff,temp;
	// XX.XX.XXXX
	// 0123456789
	for (int i = 6; i<10; i++)
	{
		buff = a.date[i];
		temp += buff;
	}
	int		year	=	(timeInfo->tm_year + 1900) - atoi(temp.c_str());
	if ( year > min && year < max )
		return	true;
	temp.clear();
	buff.clear();
	for (int i = 3; i<5; i++)
	{
		buff = a.date[i];
		temp += buff;
	}
	int		month	=	(timeInfo->tm_mon  + 1);
	if (month > atoi(temp.c_str()) && year == min)
		return	true;
	if (month < atoi(temp.c_str()) && year == max)
		return	true;
	temp.clear();
	buff.clear();
	for (int i = 0; i<2; i++)
	{
		buff = a.date[i];
		temp += buff;
	}
	int		day		=	(timeInfo->tm_mday);
	if (day > atoi(temp.c_str()) && year == min)
		return	true;
	if (day < atoi(temp.c_str()) && year == max)
		return	true;
	return	false;
}

bool	Fourth(_queue	*queue)
{
	_tempList	temp;
	int	k = 0;
	for (int i = 0; i < n; i++)
	{
		temp = FrontQ(queue);
		DeQueueQ(queue);
		if ((Check(temp,0,30) && temp.c == 4 && temp.d == 1 && temp.tekuci < 100) ||  
			(temp.c == 1 && temp.d == 2 && temp.tekuci > 5000))
			k++;
		else
			EnQueueQ(temp,queue);
	}
	n-=k;
	Print(queue,n,0);
	return	true;
}

int	tempN = 0;

void	Fifth(_queue	*queue,_queue	*newQueue,int k)
{
	if (IsEmptyQ(queue))
		return;
	_tempList	temp1;
	if (k < (n*(7./10.)))
	{
		temp1 = FrontQ(queue);
		k++;
		DeQueueQ(queue);
		Fifth(queue,newQueue,k);
	}
	else
	{
		while (!IsEmptyQ(queue))
		{
			_tempList	temp2 = FrontQ(queue);
			PrintOne(temp2);
			EnQueueQ(temp2,newQueue);
			DeQueueQ(queue);
		}
	}
	EnQueueQ(temp1,queue);
	tempN++;
}


int	main()
{
	srand(time(0));
	_queue	*queue		=	new _queue;
	_queue	*newQueue	=	new _queue;
	InitQ(queue);
	InitQ(newQueue);
	int		choice = 0;
	do
	{
		cout<<"\nIzbornik\n\n";
		cout<<"1. Generiranje niza od N cetvorki\n";
		cout<<"2. Dodavanje zapisa te ispis klijenata s vise od 10000 kn\n";
		cout<<"3. Brze transakcije\n";
		cout<<"4. Ispis s brisanjem odredjenih clanova\n";
		cout<<"5. Rekurzija\n";
		cout<<"9. Izlaz\n";
		cin>>choice;
		switch (choice)
		{
		case	1:
			if(!First(queue))
				cout<<"Error\n";
			break;
		case	2:
			if(!Second(queue))
				cout<<"Error\n";
			break;
		case	3:
			if (!Third(queue))
				cout<<"Error\n";
			break;
		case	4:
			if (!Fourth(queue))
				cout<<"Error\n";
			break;
		case	5:
			cout<<"\nNovi red\n\n";
			Fifth(queue,newQueue,0);
			cout<<"\nGlavni red\n\n";
			Print(queue,tempN,2);
			n = tempN;
			break;
		}
	}while(choice != 9);
	return	0;
}
