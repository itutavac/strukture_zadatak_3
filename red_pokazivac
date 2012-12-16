#ifndef  _RED_POKAZIVAC_H_
#define _RED_POKAZIVAC_H_

#define	MAX	200

struct	_tempList
{
	int	a,b,c,d;
	std::string	name;
	std::string	date;
	float tekuci,devizni;
};

struct	_list
{
	_tempList	a;
	_list		*next;
};

struct	_queue
{
	_list	*front,*rear;
};

_tempList	FrontQ(_queue	*temp)
{
	if (!(temp->front == temp->rear))
		return	temp->front->next->a;
}

bool		EnQueueQ(_tempList	temp,_queue	*queue)
{
	_list	*newElement = new _list;
	if (!newElement)
		return	false;
	newElement->a.a = temp.a;
	newElement->a.b = temp.b;
	newElement->a.c = temp.c;
	newElement->a.d = temp.d;
	newElement->a.date = temp.date;
	newElement->a.devizni = temp.devizni;
	newElement->a.name = temp.name;
	newElement->a.tekuci = temp.tekuci;
	newElement->next = NULL;
	queue->rear->next = newElement;
	queue->rear = newElement;
	return	true;
}

bool		DeQueueQ(_queue *temp)
{
	if (temp->front == temp->rear)
		return	false;
	_list	*deleteElement;
	deleteElement = temp->front;
	temp->front = temp->front->next;
	deleteElement->next = NULL;
	delete	deleteElement;
	return	true;
}

bool		IsEmptyQ(_queue	*temp)
{
	if (temp->front == temp->rear)
		return	true;
	return	false;
}

bool		InitQ(_queue *temp)
{
	if (!temp || !temp->front || !temp->rear)
		return	false;
	_list	*newElement = new	_list;
	if (!newElement)
		return	false;
	newElement->next = NULL;
	temp->front = newElement;
	temp->rear  = newElement;
	return	true;
}

#endif
