#ifndef  _RED_POLJE_H_
#define	_RED_POLJE_H_

#define	MAX	200

struct	_tempList
{
	int	a,b,c,d;
	std::string	name;
	std::string	date;
	float tekuci,devizni;
};

struct	_queue
{
	_tempList	a[MAX];
	int	front,rear;
};

int	AddOne(int n)
{
	return	((n+1)%MAX);
}

_tempList	FrontQ(_queue	*temp)
{
	if (!(AddOne(temp->rear) == temp->front))
		return	temp->a[temp->front];
}

bool		EnQueueQ(_tempList	x,_queue *temp)
{
	if (AddOne(AddOne(temp->rear)) == temp->front)
		return	false;
	temp->rear = AddOne(temp->rear);
	temp->a[temp->rear].a = x.a;
	temp->a[temp->rear].b = x.b;
	temp->a[temp->rear].c = x.c;
	temp->a[temp->rear].d = x.d;
	temp->a[temp->rear].date = x.date;
	temp->a[temp->rear].devizni = x.devizni;
	temp->a[temp->rear].name = x.name;
	temp->a[temp->rear].tekuci = x.tekuci;
	return	true;
}

bool		DeQueueQ(_queue	*temp)
{
	if (AddOne(temp->rear) == temp->front)
		return	false;
	temp->front = AddOne(temp->front);
	return	true;
}

bool		InitQ(_queue	*temp)
{
	if (!temp)
		return	false;
	temp->front = 0;
	temp->rear = MAX-1;
	return	true;
}

bool		IsEmptyQ(_queue	*temp)
{
	if (AddOne(temp->rear) == temp->front)
		return	true;
	return	false;
}

#endif
