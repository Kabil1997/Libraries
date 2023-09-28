#pragma once
#include <iostream>

using namespace std;


template <class T> class clsDblLinkedList
{

protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};

	Node* Head = NULL;
	
	void InsertAtBeginning(Node* &Head , T Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->Prev = NULL;
		NewNode->Next = Head;
		if (Head != NULL)
		{
			NewNode->Next->Prev = NewNode;
		}
		Head = NewNode;
		_Size++;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAtBeginning(Head, Value);
	}

	void PrintList(Node* Head)
	{
		Node* Current = Head;
		while (Current !=NULL)
		{
			cout << Current->Value << " ";
			Current = Current->Next;
		}
		cout << "\n";
		delete Current;
	}

	void PrintList()
	{
		PrintList(Head);
	}

	Node *Find(Node* Head , T Value)
	{
		Node* Current = Head;
		if (Current ==NULL)
		{
			return NULL;
		}
		while (Current !=NULL)
		{
			if (Current->Value == Value)
			{
				return Current;
			}
			Current = Current->Next;
		}
		delete Current;
		return NULL;
	}

	Node *Find(T Value)
	{
		return Find(Head, Value);
	}

	void InsertAfter(Node* CurrentNode, T Value)
	{
		if (CurrentNode!=NULL)
		{
			Node* NewNode = new Node();
			NewNode->Value = Value;
			NewNode->Next = CurrentNode->Next;
			NewNode->Prev = CurrentNode;
			if (CurrentNode->Next != NULL)
			{
				CurrentNode->Next->Prev = NewNode;
			}
			CurrentNode->Next = NewNode;
			_Size++;
		}
		else
		{
			cout << "\nThere is not a Node to Insert After !\n";
		}
	}

	Node* FindLastNode(Node* Head)
	{
		Node* LastNode = Head;
		for (; LastNode != NULL;)
		{
			if (LastNode->Next == NULL)
			{
				return LastNode;
			}
			LastNode = LastNode->Next;
		}
		return NULL;
	}

	Node* FindLastNode()
	{
		return FindLastNode(Head);
	}

	void InsertAtEnd(Node*& Head, int Value)
	{
		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->Next = NULL;
		if (Head == NULL)
		{
			NewNode->Prev = NULL;
			Head = NewNode;
			_Size++;
			return;
		}
		Node* CurrentNode = FindLastNode(Head);
		NewNode->Prev = CurrentNode;
		CurrentNode->Next = NewNode;
		_Size++;
	}

	void InsertAtEnd(int Value)
	{
		InsertAtEnd(Head, Value);
	}

	void DeleteNode(Node*&Head, Node* &CurrentNode)
	{

		if (CurrentNode!=NULL)
		{
			if (CurrentNode==Head)
			{
				Head = CurrentNode->Next;
				if (CurrentNode->Next != NULL)
				{
					CurrentNode->Next->Prev = NULL;
				}
			}
			else
			{
				CurrentNode->Prev->Next = CurrentNode->Next;
				if (CurrentNode->Next!=NULL)
				{
					CurrentNode->Next->Prev = CurrentNode->Prev;
				}
			}
			delete CurrentNode;
		}
		else
		{
			cout << "\nThere is not a Node to Delete !\n";
		}

	}

	void DeleteNode(Node* CurrentNode)
	{
		DeleteNode(Head,CurrentNode);
	}

	void DeleteFirstNode(Node* &Head)
	{
		Node* CurrentNode = Head;
		if (Head != NULL)
		{
			Node* temp = Head;
			Head = Head->Next;
			if (Head != NULL) {
				Head->Prev = NULL;
			}
			delete temp;
			_Size--;
		}
		else
		{
			cout<<"\n\nThe List is Empty. \n";
		}
	}

	void DeleteFirstNode()
	{
		DeleteFirstNode(Head);
	}

	void DeleteLastNode(Node*&Head)
	{
		Node* LastNode = FindLastNode(Head);
		if (Head!=NULL&&LastNode!=NULL)
		{
			if (LastNode->Prev != NULL)
			{
				LastNode->Prev->Next = LastNode->Next;
			}
			else
			{
				Head = NULL;
			}
			delete LastNode;
			_Size--;
		}
		else
		{
			cout << "\n\nThe List is Empty. \n";
		}
	}

	void DeleteLastNode()
	{
		DeleteLastNode(Head);
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty(Node* Head)
	{
		return Head == NULL;
	}

	bool IsEmpty()
	{
		return IsEmpty(Head);
	}

	void Clear(Node*& Head)
	{
		while (_Size > 0)
		{
			DeleteFirstNode(Head);
		}
	}

	void Clear()
	{
		Clear(Head);
	}

	void Reverse(Node*& Head)
	{
		Node* Temp = NULL;
		Node* Current = Head;
		if (Current->Next!=NULL)
		{
			while (Current != NULL)
			{
				Temp = Current->Prev;
				Current->Prev = Current->Next;
				Current->Next = Temp;
				Current = Current->Prev;
			}
			Head = Temp->Prev;
		}
	}

	void Reverse()
	{
		Reverse(Head);
	}

	Node* GetNode(Node* Head , int Index)
	{
		if (Head==NULL || Index>(_Size-1)||Index<0)
		{
			return NULL;
		}
		Node* Current = Head;
		int Counter = 0;
		for (; Current!=NULL && (Current->Next!=NULL);)
		{
			if (Index==Counter)
			{
				break;
			}
			Counter++;
			Current = Current->Next;
		}
		return Current;
	}

	Node* GetNode(int Index)
	{
		return GetNode(Head, Index);
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);
		return ItemNode ==NULL? NULL : ItemNode->Value;
	}

	bool UpdateItem(int Index, T Value)
	{
		Node* CurrentNode = GetNode(Index);
		if (CurrentNode==NULL)
		{
			return false;
		}
		CurrentNode->Value = Value;
		return true;
	}

	bool InsertAfterIndex(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode!=NULL)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		return false;
	}

	T GetFirstItem()
	{
		return GetItem(0);
	}

	T GetLastItem()
	{
		return GetItem(_Size-1);
	}
};

